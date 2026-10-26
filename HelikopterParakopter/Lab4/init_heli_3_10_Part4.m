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

Ad = sysd.A;
Bd = sysd.B;
Cd = sysd.C;

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

save('2_3_2_TransGyroCompare_WithEncoder.mat', 'simout')







