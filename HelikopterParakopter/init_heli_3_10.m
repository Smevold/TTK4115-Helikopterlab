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
%% 
A = [0 1 0 
    0 0 0 
    0 0 0];

B = [0 0
    0 K_1
    K_2 0];

q_1 = 5; % Pitch-vekting
q_2 = 0.1; % Pitch-rate-vekting
q_3 = 8; % Elevation-rate-vekting

Q_lqr = [q_1 0 0
        0 q_2 0
        0 0 q_3];
    
r_1 = 0.1; % V_s-vekting
r_2 = 0.1; % V_d-vekting
    
R_lqr = [r_1 0
        0 r_2];

K = lqr(A,B,Q_lqr,R_lqr);

F = [K(1,1) K(1,3)
    K(2,1) K(2,3)];

%%

% Ts = 0.002;
% t = (0:size(simout,1)-1)' * Ts;
% Fs = 1/Ts;

% plot(t, elevationData)
% legend('elevation')
% grid on
% 
% t = simData.Time;

travel = simout.signals.values(:,1);
travel_rate = simout.signals.values(:,2);
pitch = simout.signals.values(:,3);
pitch_rate = simout.signals.values(:,4);
elevation = simout.signals.values(:,5);
elevation_rate = simout.signals.values(:,6);

plot(simout.time, simout.signals.values)
legend('Travel', 'Travel rate', 'Pitch', 'Pitch rate', 'Elevation', 'Elevation rate')
grid on

%% Saving data

save('q_1_5-q_3_8-x_0.5.mat', 'simout')







