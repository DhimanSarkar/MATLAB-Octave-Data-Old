clear;
clc;

% constants
a1=5;
a2=10;
w1=1/10;
w2=1/2;
fi1 = pi/4 + pi/6;
fi2 = pi/4 - pi/3;
delta = fi1-fi2;

% defining parameter time
t = -100:.1:100;

% defining waves
x1 = a1 .* cos(w1.*t + fi1);
x2 = a2 .* cos(w2.*t + fi2);

resultantX = x1 + x2;

figure;
hold on;
plot(t,x1,'DisplayName','Osc 1');
plot (t,x2,'DisplayName','Osc 2');
plot (t,resultantX,'DisplayName','Resultant');
legend show;
box on;
grid on;