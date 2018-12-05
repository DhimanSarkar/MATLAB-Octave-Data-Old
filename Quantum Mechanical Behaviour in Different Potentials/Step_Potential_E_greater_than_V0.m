clear;
clc;

% Define Constants
eV=1.6E-19

% Define Variables
x=-10:.01:10;
V0=10E3 .* eV

% Defining Potential Function

Vx = [x<=0 0 ; x>=0 V0]

plot(Vx)
