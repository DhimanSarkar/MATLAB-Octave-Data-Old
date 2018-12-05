clear;
clc;

% constants
a=5;
w1=1/10;
w2=1/2;

% defining parameter time
t = -100:.1:100;

%defining waves
x1 = a.*sin(w1.*t);
x2 = a.*sin(w2.*t);

figure;
resultantX=x1 + x2;

% verification
Resultant = 2*a .* sin(w1+w2).*t./2 .* cos(w1-w2).*t./2;

figure;
hold on;
plot(t,x1,'DisplayName','Osc 1');
plot(t,x2,'DisplayName','Osc 2');
plot(t,resultantX,'displayname','Resultant');
legend show;
grid on;
box on;
figure;
hold on;
plot(t,x1,'DisplayName','Osc 1');
plot(t,x2,'DisplayName','Osc 2');
plot(t,Resultant,'displayname','Resultant');
legend show;
grid on;
box on;