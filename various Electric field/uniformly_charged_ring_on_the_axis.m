clear;
clc;


%defining constants
epsilon0 = 8.854187817817817817817E-12;
ringR = 50;
area = pi.*ringR.^2;
charge = 500;
chargeDensity = charge/area;

syms x;

dE = @(x) ringR.*chargeDensity.*x./(x.^2+ringR.^2).^3/2;

E = int (dE,x);
X=-500:500;
E = subs(E,x,X);
plot(E,X);
