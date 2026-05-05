// This program is written by Alistair clark
// This program solves a 3x3 linear system, compute area under a curve, and plots data from a csv file
// Date: 5/4/2026

clc;
clear;
close all;

% Run all functions
sys_3_lin_eq();
area_under_curve();
plot_csv_data();

%% ============================================================
% FUNCTION 1: Solve 3x3 system + plot equations
% ============================================================
function sys_3_lin_eq()

disp('--- Solving 3x3 Linear System ---');

A = zeros(3,3);
B = zeros(3,1);

for i = 1:3
    disp(['Equation ', num2str(i)]);

    A(i,1) = input('Enter x coefficient: ');
    A(i,2) = input('Enter y coefficient: ');
    A(i,3) = input('Enter z coefficient: ');
    B(i)   = input('Enter right side of function: ');
end

% Solve system Ax = B
X = A \ B;

disp('Solution:');
disp(['x = ', num2str(X(1))]);
disp(['y = ', num2str(X(2))]);
disp(['z = ', num2str(X(3))]);

%% ================== PLOTTING ==================

[x,y] = meshgrid(-5:1:5, -5:1:5);

figure;
hold on;

% ---- Equation 1 ----
if A(1,3) ~= 0
    z1 = (B(1) - A(1,1)*x - A(1,2)*y) / A(1,3);
    surf(x,y,z1);
end

% ---- Equation 2 ----
if A(2,3) ~= 0
    z2 = (B(2) - A(2,1)*x - A(2,2)*y) / A(2,3);
    surf(x,y,z2);
end

% ---- Equation 3 (special case) ----
% If no z term, plot as a line
if A(3,3) == 0
    x2 = -5:1:5;
    y2 = (B(3) - A(3,1)*x2) / A(3,2);
    z2 = zeros(size(x2));
    plot3(x2, y2, z2, 'k', 'LineWidth', 2);
else
    z3 = (B(3) - A(3,1)*x - A(3,2)*y) / A(3,3);
    surf(x,y,z3);
end

title('3x3 System of Equations');
xlabel('x'); ylabel('y'); zlabel('z');
grid on;

end

%% ============================================================
% FUNCTION 2: Area under curve
% ============================================================
function area_under_curve()

disp('--- Area Under Curve ---');

f = @(x) x.^2 .* log(x);

% avoid x = 0
x = linspace(0.01, 2, 500);
y = f(x);

% trapezoidal rule
area_trapz = trapz(x,y);

% built-in integral
area_int = integral(f, 0, 2);

disp(['Trapz area = ', num2str(area_trapz)]);
disp(['Integral area = ', num2str(area_int)]);

figure;
plot(x,y);
title('y = x^2 ln(x)');
xlabel('x');
ylabel('y');
grid on;

end

%% ============================================================
% FUNCTION 3: CSV data plot
% ============================================================
function plot_csv_data()

disp('--- Plotting CSV Data ---');

data = readtable('sample.csv');

x = data{:,1};
y = data{:,2};

figure;
plot(x,y,'o-');

title('CSV Data Plot');
xlabel('X');
ylabel('Y');
grid on;

end