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

PORT = 6;

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

q_1 = 3; % Pitch-vekting
q_2 = 1; % Pitch-rate-vekting
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

Ts = 0.002;

sys = ss(A_K,B_K,C_K,D_K);
sysd = c2d(sys, Ts, 'zoh');

A_d = sysd.A;
B_d = sysd.B;
C_d = sysd.C;

x_0 = [0;0;0;0;0;0]; %-0.523333333333333
P_0 = zeros(6);

q = 1;
Q_d = q*eye(6);

%% Estimering av støy

% Gyro_p = simout.signals.values(:,17);
% Gyro_p_dot = simout.signals.values(:,18);
% Gyro_e = simout.signals.values(:,19);
% Gyro_e_dot = simout.signals.values(:,20);
% Gyro_l = simout.signals.values(:,21);
% Gyro_l_dot = simout.signals.values(:,22);
% 
% Gyro = simout.signals.values(2500:5000,17:22);
% 
% R_d = cov(Gyro);


% R_d from the helicopter lying still
R_d1 = [4.65653328279899e-07,3.49834077169025e-08,1.30597186346466e-08,2.56802213150077e-07,-1.74647211463784e-06,-9.82778674936143e-07;3.49834077169025e-08,7.03644267856449e-07,8.05499160151576e-08,-1.61141032368164e-08,1.12780821505476e-07,6.31147880952989e-08;1.30597186346466e-08,8.05499160151576e-08,5.47618551870970e-07,2.46906006681541e-07,-1.70404109693680e-06,-9.64536589444343e-07;2.56802213150077e-07,-1.61141032368164e-08,2.46906006681541e-07,1.68557957202342e-05,-0.000114872043212648,-6.47863088634731e-05;-1.74647211463784e-06,1.12780821505476e-07,-1.70404109693680e-06,-0.000114872043212648,0.000783460784200803,0.000441904818834722;-9.82778674936143e-07,6.31147880952989e-08,-9.64536589444343e-07,-6.47863088634731e-05,0.000441904818834722,0.000249263385610476];
R_d2 = [0.00306863744050679,0.00597898155272382,0.00292964415525621,4.38149043481465e-05,4.15450305267450e-05,0.000115689192015894;0.00597898155272382,0.0660544256194300,0.00894879886876270,5.18858244272164e-06,-4.85973444756856e-05,2.72329175898819e-05;0.00292964415525621,0.00894879886876270,0.00339091623047310,-4.52253473117218e-05,-1.27627393089588e-05,-3.74321106219478e-05;4.38149043481465e-05,5.18858244272164e-06,-4.52253473117218e-05,0.000201720907872831,0.000134760684249710,0.000373145380848365;4.15450305267450e-05,-4.85973444756856e-05,-1.27627393089588e-05,0.000134760684249710,0.000118374148641113,0.000325639980324475;0.000115689192015894,2.72329175898819e-05,-3.74321106219478e-05,0.000373145380848365,0.000325639980324475,0.000913654220575349];

R_d2/R_d1

%% Van Loan Metode


n = size(A_K,1);

G = eye(n);
Q_c = q*eye(n);

M = [-A_K G*Q_c*G
    zeros(n) A_K']*Ts;

Mx = expm(M);
A_d = Mx(n+1:end, n+1:end)';
Q_d = A_d * Mx(1:n, n+1:end);

%% Bias Korreksjon

A_K = [A_K zeros(6)
    zeros(6) zeros(6)];

B_K = [B_K
    zeros(6,2)];

C_K = eye(12);

D_K = zeros(12,2);

sys = ss(A_K,B_K,C_K,D_K);
sysd = c2d(sys, Ts, 'zoh');

A_d = sysd.A;
B_d = sysd.B;
C_d = sysd.C;

x_0 = [0;0;0;0;0;0 %-0.523333333333333
    zeros(6,1)];
P_0 = zeros(12);

R_d2 = [R_d2 zeros(6)
    zeros(6) zeros(6)];

%% Van Loan 2

q = 10000;

n = size(A_K,1);

G = eye(n);
Q_c = q*eye(n);

M = [-A_K G*Q_c*G
    zeros(n) A_K']*Ts;

Mx = expm(M);
Ad = Mx(n+1:end, n+1:end)';
Q_d = Ad * Mx(1:n, n+1:end);

%%

% Ts = 0.002;
% t = (0:size(simout,1)-1)' * Ts;
% Fs = 1/Ts;

% plot(t, elevationData)
% legend('elevation')
% grid on
% 
% t = simData.Time;

% % % % % % % % % % % % travel = simout.signals.values(:,1);
% % % % % % % % % % % % travel_rate = simout.signals.values(:,2);
% % % % % % % % % % % % pitch = simout.signals.values(:,3);
% % % % % % % % % % % % pitch_rate = simout.signals.values(:,4);
% % % % % % % % % % % % elevation = simout.signals.values(:,5);
% % % % % % % % % % % % elevation_rate = simout.signals.values(:,6);
% % % % % % % % % % % % p_c = simout.signals.values(:,7);
% % % % % % % % % % % % e_dot_c = simout.signals.values(:,8);

% plot(simout.time, simout.signals.values)
% legend('Travel', 'Travel rate', 'Pitch', 'Pitch rate', 'Elevation', 'Elevation rate', 'Joystick X', 'Joystick Y', 'accelerometer x-direction', 'accelerometer y-direction', 'accelerometer z-direction', 'gyroscope p-direction', 'gyroscope e-direction', 'gyroscope lambda-direction')
% grid on

%% Saving data
% save('2_4_1_LyingStill.mat', 'simout')







