% Clear previous data, figures, and command window
clear all;
close all;
clc;

% Time setup
t = linspace(0, 30, 100); 

% Acceleration setup
% Assuming force and mass vectors are defined elsewhere
force_l = 0.8514; % Example value for force for Design l
force_2 = 1.07239; % Example value for force for Design 2
force_3 = 0.878415; % Example value for force for Design 3
mass = 1; % Example value for mass (assuming it's constant)

% Calculate acceleration for each design
al = force_l / mass * ones(size(t));
a2 = force_2 / mass * ones(size(t));
a3 = force_3 / mass * ones(size(t));

% Plot acceleration
subplot(3,3,1);
plot(t, al);
grid on;
title('Acceleration for Design l');
xlabel('Time (seconds)');
ylabel('Acceleration (m/s^2)');

subplot(3,3,2);
plot(t, a2);
grid on;
title('Acceleration for Design 2');
xlabel('Time (seconds)');
ylabel('Acceleration (m/s^2)');

subplot(3,3,3);
plot(t, a3);
grid on;
title('Acceleration for Design 3');
xlabel('Time (seconds)');
ylabel('Acceleration (m/s^2)');

% Calculate velocity for each design
vl = al .* t;
v2 = a2 .* t;
v3 = a3 .* t;

% Plot velocity
subplot(3,3,4);
plot(t, vl);
grid on;
title('Velocity for Design l');
xlabel('Time (seconds)');
ylabel('Velocity (m/s)');

subplot(3,3,5);
plot(t, v2);
grid on;
title('Velocity for Design 2');
xlabel('Time (seconds)');
ylabel('Velocity (m/s)');

subplot(3,3,6);
plot(t, v3);
grid on;
title('Velocity for Design 3');
xlabel('Time (seconds)');
ylabel('Velocity (m/s)');

% Calculate linear displacement for each design
d1 = (vl / 2) .* t;
d2 = (v2 / 2) .* t;
d3 = (v3 / 2) .* t;

% Plot linear displacement
subplot(3,3,7);
plot(t, d1);
grid on;
title('Linear Displacement for Design l');
xlabel('Time (seconds)');
ylabel('Linear Displacement (m)');

subplot(3,3,8);
plot(t, d2);
grid on;
title('Linear Displacement for Design 2');
xlabel('Time (seconds)');
ylabel('Linear Displacement (m)');

subplot(3,3,9);
plot(t, d3);
grid on;
title('Linear Displacement for Design 3');
xlabel('Time (seconds)');
ylabel('Linear Displacement (m)');
