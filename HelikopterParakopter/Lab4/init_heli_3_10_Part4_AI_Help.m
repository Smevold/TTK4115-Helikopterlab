% FOR HELICOPTER NR 3-10
% This file contains the initialization for the helicopter assignment in
% the course TTK4115. Run this file before you execute QuaRC_ -> Build 
% to build the file heli_q8.mdl.

% Oppdatert høsten 2006 av Jostein Bakkeheim
% Oppdatert høsten 2008 av Arnfinn Aas Eielsen
% Oppdatert høsten 2009 av Jonathan Ronen
% Updated fall 2010, Dominik Breu
% Updated fall 2013, Mark Haring
% Updated spring 2015, Mark Haring


%%%%%%%%%%% Calibration of the encoder and the hardware for the specific
%%%%%%%%%%% helicopter
Joystick_gain_x = 1;
Joystick_gain_y = -1;


%%%%%%%%%%% Physical constants
g = 9.81; % gravitational constant [m/s^2]
l_c = 0.46; % distance elevation axis to counterweight [m]
l_h = 0.66; % distance elevation axis to helicopter head [m]
l_p = 0.175; % distance pitch axis to motor [m]
m_c = 1.92; % Counterweight mass [kg]
m_p = 0.72; % Motor mass [kg]

% Results from Lab Prep

V_s0 = 7.5;

K_f = (2*m_p*l_h - m_c*l_c)*g/(l_h*V_s0);

L_1 = l_p*K_f;
L_2 = (m_c*l_c - 2*m_p*l_h)*g;
L_3 = l_h*K_f;
L_4 = L_3;


J_p = 2*m_p*l_p^2;
J_e = m_c*l_c^2 + 2*m_p*l_h^2;
J_l = m_c*l_c^2 + 2*m_p*(l_h^2 + l_p^2);

K_1 = L_1/J_p;
K_2 = L_3/J_e;
K_3 = (2*m_p*l_h - m_c*l_c)*g/J_l;

lambda_1 = -2;
lambda_2 = -2;

K_pp = - (lambda_1 + lambda_2)/K_1;
K_pd = lambda_1*lambda_2/K_1;

PORT = 7;

%% Luenberger
A = [0 1 0 0 0 
    0 0 0 0 0 
    0 0 0 1 0
    0 0 0 0 0
    K_3 0 0 0 0];

B = [0 0
    0 K_1
    0 0
    K_2 0
    0 0];

C = [0 0 1 0 0
     0 0 0 0 1];

% C = eye(5);

% Define poles-placement
p = -8;
P = [p p+1 p+2 p-2 p-1];

sys = ss(A,B,C,0);

Ob = obsv(sys);
rank(obsv(A, C))
Cb = ctrb(sys);
rank(ctrb(A, B))
rank(C')
L = place(A', C', P).';

eig(A-L*C)

%% LQR:

A_lqr = [0 1 0 0 0 
    0 0 0 0 0 
    0 0 0 0 0
    -1 0 0 0 0
    0 0 -1 0 0];

B_lqr = [0 0
    0 K_1
    K_2 0
    0 0
    0 0];

q_1 = 6; % Pitch-vekting
q_2 = 2; % Pitch-rate-vekting
q_3 = 6; % Elevation-rate-vekting
q_4 = 2; % Akkumulert pitch-error
q_5 = 13; % Akkumulert elevation-rate-error

Q_lqr = [q_1 0 0 0 0
        0 q_2 0 0 0
        0 0 q_3 0 0
        0 0 0 q_4 0
        0 0 0 0 q_5];
    
r_1 = 3; % V_s-vekting
r_2 = 6; % V_d-vekting
    
R_lqr = [r_1 0
        0 r_2];

K = lqr(A_lqr,B_lqr,Q_lqr,R_lqr);

F = [K(1,1) K(1,3)
    K(2,1) K(2,3)];

%% Kalman

% Tilstand: x = [p; p_dot; e; e_dot; lambda; lambda_dot]
% Måling:   y = [Acc_p; Gyro_p_dot; Acc_e; Gyro_e_dot; Guro_lambda; Gyro_lambda_dot]

Ts = 0.002;

A_K = [0 1 0 0 0 0
    0 0 0 0 0 0
    0 0 0 1 0 0
    0 0 0 0 0 0
    0 0 0 0 0 1
    K_3 0 0 0 0 0];

B_K = [0 0
    0 K_1
    0 0
    K_2 0
    0 0
    0 0];

C_K = eye(6);

D_K = zeros(6,2);

bruk_van_loan = true;
bruk_bias = true;

%% Målestøy R_d

Stoyfil   = '2_4_3_AI_Help_wVanLoan_BiasEst.mat';
Stoytid = 5000:20000; % Fjerne lift-off
y_kolonner  = [15 17 16 18 22 19]; % Samme rekkefølge som y

H = load(Stoyfil);
if isfield(H, 'simout')
    V = H.simout.signals.values;
else
    V = H.ans(2:end, :)';
end
Y_Stoy = V(Stoytid, y_kolonner);

R_full = cov(Y_Stoy); % Full matrise
R_d2   = diag(diag(R_full)); % Bare diagonalen brukes i filteret

%% Prosesstøy Q_d

% Tunet av Claude mot encoder, deretter ganget med 3 for å passe til R_d fra cov.
q_diag = [3e-12 3e-5 6e-8 1.5e-5 0.6 1.5e-7];

% Q_d6 = diag(q_diag);
Q_d6 = 1e-2*eye(6);

if bruk_van_loan
    Q_c = Q_d6/Ts;
    
    M = [-A_K, Q_c
        zeros(6), A_K']*Ts;
    
    Mx = expm(M);
    
    Q_d6 = Mx(7:12, 7:12)' * Mx(1:6, 7:12);
end

%% Diskretisering og startverdier

e_offset = -pi/6; % Elevation starter på -pi/6

if ~bruk_bias % IKKE bruk_bias
    
    sysd = c2d(ss(A_K, B_K, C_K, D_K), Ts, 'zoh');
    
    A_d = sysd.A;  
    B_d = sysd.B;  
    C_d = sysd.C;
    
    Q_d = Q_d6;
    
    x_0 = [0
        0
        e_offset
        0
        0
        0];
    
    P_0 = zeros(6);
    
else
    % Bonus 2: bias på pdot-, edot- og lambdadot-gyroen: y_rate = rate + b
    
    S = zeros(6,3);  
    S(2,1) = 1; 
    S(4,2) = 1;  
    S(6,3) = 1;
    
    A_b = blkdiag(A_K, zeros(3));
    
    B_b = [B_K; zeros(3,2)];
    
    sysb = c2d(ss(A_b, B_b, [eye(6) S], zeros(6,2)), Ts, 'zoh');
    
    A_d = sysb.A;  
    B_d = sysb.B;  
    C_d = sysb.C;
    
    Q_d = blkdiag(Q_d6, diag([3e-12 6e-9 3e-12]));
    
    x_0 = [0
        0
        e_offset
        0
        0
        0
        0
        0
        0];
    
    P_0 = zeros(9);
    
end

n_x = size(A_d, 1);

fprintf('Kalman: %d tilstander, rank(obsv(A_d, C_d)) = %d\n\n', n_x, rank(obsv(A_d, C_d)));








