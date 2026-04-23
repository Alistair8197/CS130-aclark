//  This Program is written by Alistair Clark
// This program calculates a projectile’s height vs distance and also graphs it
// Date: 4/19/26



>> clc;
clear;

%% INPUTS
alpha = input('Enter launch angle (degrees between 0 and 90): ');
velocity = input('Enter muzzle velocity (m/s): ');

%% CONSTANT
g = 9.81;

%% CONVERT ANGLE TO RADIANS
theta = alpha * pi / 180;

%% VELOCITY COMPONENTS
Vx = velocity * cos(theta);
Vy = velocity * sin(theta);

%% FLIGHT TIME
flight_time = (2 * Vy) / g;

%% MAX HEIGHT
max_height = (Vy^2) / (2 * g);

%% DISTANCE
distance_m = Vx * flight_time;
distance_ft = distance_m * 3.28084;

%% DISPLAY RESULTS
disp(' ');
disp(['Flight time (s): ', num2str(round(flight_time,2))]);
disp(['Max height (m): ', num2str(max_height)]);
disp(['Distance (m): ', num2str(distance_m)]);
disp(['Distance (ft): ', num2str(distance_ft)]);

%% HEIGHT VS DISTANCE PLOT
t = linspace(0, flight_time, 100);

x = Vx * t;
y = Vy * t - 0.5 * g * t.^2;

figure;
plot(x, y);
title('Projectile Motion: Height vs Distance');
xlabel('Distance (m)');
ylabel('Height (m)');

%% TABLE OF DISTANCES (10x10)
velocities = linspace(0, 50, 10);
angles = linspace(5, 85, 10);

distance_table = zeros(10,10);

for i = 1:10
    for j = 1:10
        
        theta = angles(j) * pi / 180;
        
        Vx = velocities(i) * cos(theta);
        Vy = velocities(i) * sin(theta);
        
        time = (2 * Vy) / g;
        dist = Vx * time;
        
        distance_table(i,j) = dist;
        
    end
end

disp(' ');
disp('Distance Table (meters):');
disp(distance_table);

%% SOLVE FOR VELOCITY GIVEN DISTANCE = 30m
distance_target = 30;

angles_plot = linspace(5, 85, 100);
velocity_required = zeros(size(angles_plot));

for i = 1:length(angles_plot)
    
    theta = angles_plot(i) * pi / 180;
    
    % Range equation solved for velocity
    velocity_required(i) = sqrt((distance_target * g) / sin(2 * theta));
    
end

%% PLOT VELOCITY VS ANGLE
figure;
plot(angles_plot, velocity_required);
title('Required Velocity vs Angle (Range = 30m)');
xlabel('Angle (degrees)');
ylabel('Velocity (m/s)');