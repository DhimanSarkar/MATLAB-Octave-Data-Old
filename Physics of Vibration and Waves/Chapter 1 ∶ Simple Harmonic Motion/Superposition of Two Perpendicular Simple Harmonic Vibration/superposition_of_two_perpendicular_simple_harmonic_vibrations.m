clear;
clc;

% constants
a1=5;
a2=10;
fi1=pi/6;
fi2=pi/3;
w=1/10;

% defining time parameter
t=-100:.1:100;

% defining wave
x = a1 .* sin(w.*t + fi1);
y = a2 .* sin(w.*t + fi2);

z= x + y;

plot(x,z,y,z,t,z,x,t,t,y)