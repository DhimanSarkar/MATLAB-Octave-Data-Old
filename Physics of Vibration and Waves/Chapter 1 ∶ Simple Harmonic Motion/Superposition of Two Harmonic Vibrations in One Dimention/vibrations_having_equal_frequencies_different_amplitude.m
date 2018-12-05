clear;
clc;

% constants
a1 = 5;
a2 = 10;
w = 1/10;
fi1 = pi/6;
fi2 = pi/3;
delta = fi1-fi2;

% defining parameter time
t = -100:.1:100;

% defining waves
x1 = a1 .* cos(w.*t + fi1);
x2 = a2 .* cos(w.*t + fi2);

resultantX = x1 + x2;

% Plot
figure;
hold on;
plot(t,x1,'displayname','Osc 1=a1 sin(wt+fi1)');
plot(t,x2,'displayname','Osc 2=a2 sin(wt+fi2)');
plot(t,resultantX,'displayname','Resultant');
legend show;
grid on;
box on;

% varification
ResultantAmplitude = ((a1 + a2.*cos(delta)).^2 + (a2.*sin(delta)).^2).^1/2;
theta = atan(a1.*sin(fi1) + a2.*sin(fi2))./(a1.*cos(fi1) + a2.*cos(fi2));
ResultantWave = ResultantAmplitude .* cos(w.*t + theta);

figure;
hold on;
plot(t,x1,'displayname','Osc 1=a1 sin(wt+fi1)');
plot(t,x2,'displayname','Osc 2=a2 sin(wt+fi2)');
plot(resultantX,ResultantWave,'displayname','Resultant');
legend show;
grid on;
box on;
