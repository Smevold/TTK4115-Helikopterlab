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

%% Kalman: akselerometervinkler + gyro-rater
% Endret 2026-11-02, se Lab4_Kalman_analyse.md i Obsidian (TTK4115_Linsys/Lab).
% Tilstand: x = [p; pdot; e; edot; lambda; lambdadot]
% Måling:   y = [p_acc; pdot_gyro; e_acc; edot_gyro; int(lambdadot_gyro); lambdadot_gyro]
%           Samme rekkefølge som Mux3 i Kalman-subsystemet.

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

bruk_bias     = false;   % true: bonus 2, gyro-bias som tilstander (9 tilstander, se Simulink-punkt 4 nederst)
bruk_van_loan = false;   % true: bonus 1, Q_d regnes ut med Van Loan (gir samme Q_d)

%% Målestøy R_d fra hover-logg (oppgave 2.4.1)
% Kolonner i loggen (Mux-en til To File / To Workspace):
%   15 p_acc, 16 e_acc, 17 pdot, 18 edot, 19 lambdadot, 22 int(lambdadot)
% Ta en ny hover-logg etter at 0.4768-offseten er fjernet, og bytt filnavn under.
hover_fil   = '2_4_1_LyingStill.mat';
hover_rader = 2500:5000;               % rolig hover-vindu (sample-nummer)
y_kolonner  = [15 17 16 18 22 19];     % samme rekkefølge som y

H = load(hover_fil);
if isfield(H, 'simout')
    V = H.simout.signals.values;       % To Workspace (Structure With Time)
else
    V = H.ans(2:end, :)';              % To File: første rad er tid
end
Y_hover = V(hover_rader, y_kolonner);

R_full = cov(Y_hover);                 % hele matrisen, til rapporten
R_d2   = diag(diag(R_full));           % bare diagonalen brukes i filteret
% Korrelasjonene i R_full (p_acc-e_acc ca. 0.8, pdot-lambdadot ca. 0.9) er vibrasjon og
% ekte bevegelse, ikke uavhengig målestøy. Med hele matrisen fikk edot en bias på ca. -0.04 rad/s.

% Gamle verdier (kolonne 17:22 = [pdot edot lambdadot int(pdot) int(edot) int(lambdadot)],
% feil rekkefølge i forhold til y). Brukes ikke, bare til sammenligning i rapporten.
R_d1_gammel = [4.65653328279899e-07,3.49834077169025e-08,1.30597186346466e-08,2.56802213150077e-07,-1.74647211463784e-06,-9.82778674936143e-07;3.49834077169025e-08,7.03644267856449e-07,8.05499160151576e-08,-1.61141032368164e-08,1.12780821505476e-07,6.31147880952989e-08;1.30597186346466e-08,8.05499160151576e-08,5.47618551870970e-07,2.46906006681541e-07,-1.70404109693680e-06,-9.64536589444343e-07;2.56802213150077e-07,-1.61141032368164e-08,2.46906006681541e-07,1.68557957202342e-05,-0.000114872043212648,-6.47863088634731e-05;-1.74647211463784e-06,1.12780821505476e-07,-1.70404109693680e-06,-0.000114872043212648,0.000783460784200803,0.000441904818834722;-9.82778674936143e-07,6.31147880952989e-08,-9.64536589444343e-07,-6.47863088634731e-05,0.000441904818834722,0.000249263385610476];
R_d2_gammel = cov(V(hover_rader, 17:22));

%% Prosesstøy Q_d
% Tunet offline mot encoder, deretter ganget med 3 for å passe til R_d fra cov.
q_diag = [3e-12 3e-5 6e-8 1.5e-5 0.6 1.5e-7];   % [p pdot e edot lambda lambdadot]
Q_d6   = diag(q_diag);
% Enkel variant som også fungerer: Q_d6 = 1e-5*eye(6);

if bruk_van_loan
    % Van Loan (bonus 1): Q_c = Q_d/Ts gir tilnærmet samme Q_d
    Q_c = Q_d6/Ts;
    M   = [-A_K, Q_c; zeros(6), A_K']*Ts;
    Mx  = expm(M);
    Q_d6 = Mx(7:12, 7:12)' * Mx(1:6, 7:12);
end

%% Diskretisering og startverdier
if ~bruk_bias
    sysd = c2d(ss(A_K, B_K, eye(6), zeros(6,2)), Ts, 'zoh');
    A_d = sysd.A;  B_d = sysd.B;  C_d = sysd.C;
    Q_d = Q_d6;
    x_0 = [0; 0; -0.43; 0; 0; 0];      % e fra akselerometeret i hvile (absolutt vinkel)
    P_0 = 0.01*eye(6);
else
    % Bonus 2: bias på pdot-, edot- og lambdadot-gyroen: y_rate = rate + b
    S = zeros(6,3);  S(2,1) = 1;  S(4,2) = 1;  S(6,3) = 1;
    A_b = blkdiag(A_K, zeros(3));
    B_b = [B_K; zeros(3,2)];
    sysb = c2d(ss(A_b, B_b, [eye(6) S], zeros(6,2)), Ts, 'zoh');
    A_d = sysb.A;  B_d = sysb.B;  C_d = sysb.C;    % C_d er 6x9
    Q_d = blkdiag(Q_d6, diag([3e-12 6e-9 3e-12]));
    x_0 = [0; 0; -0.43; 0; 0; 0; 0; 0; 0];
    P_0 = blkdiag(0.01*eye(6), 0.02^2*eye(3));
    % R_d2 er fortsatt 6x6. Biasene måles ikke direkte.
end
n_x = size(A_d, 1);
fprintf('Kalman: %d tilstander, rang(obsv(A_d, C_d)) = %d\n', n_x, rank(obsv(A_d, C_d)));

%% Endringer i Simulink (heli_q8_Part4_AI_Help.slx)
% - 0.4768 fjernet i Gyro_Math, euler_angles inn i Kalman-subsystemet, Mux3 = 6 innganger,
%   Demux-ene som deler x_hat = 6 utganger.
% - Correction: x_posteriori og P_posteriori har arvet størrelse (-1), og korreksjonen
%   kjøres bare når new_data er 1 (ellers x_hat = x_bar, P_hat = P_bar).
% - IMU "New data" -> Data Type Conversion (double) -> Manual Switch "New data av/paa"
%   -> Kalman-subsystemet (inngang 5). Andre posisjon på bryteren er konstant 0
%   (ingen nye data), til oppgave 2.4.3.
% - gyro_vec_to_euler_rates: theta begrenset til +-1.2 rad.
% Med bruk_bias = true må Demux-ene som deler x_hat (toppnivå og i LQR) ha 9 utganger.
% LQR-en skal fortsatt bare bruke p, pdot og edot.

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







