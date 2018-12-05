% Two particles of equal mass have velocities v1=ai and v2=aj. The
% acclerationof the second particle is zero, the centre of mass of the two
% particles moves along a , a> straight line

clear;
clc;


% Time interval
t=0:.1:100;

% Particle 1 velovity, accleration
v1x=5;
v1y=0;
a1x=10;
a1y=10;

% Particle 2 velocity, accleration
v2x=0;
v2y=5;
a2x=0;
a2y=0;

% Particle 1 Path
S1x = v1x .* t + 1/2 .* a1x .*t .^2;
S1y = v1y .* t + 1/2 .* a1y .*t .^2;

% Particle 2 Path
S2x = v2x .* t + a2x .* t .^2;
S2y = v2y .* t + a2y .* t .^2;

%Centre of Mass path
CMx=(S1x+S2y)./2;
CMy=(S1x+S2y)./2;

% Plot
hold on;
xlim([-30,563.4323369267164]);
ylim([-.2842170943E-13,500]);
box on;
grid on;
plot(CMx,CMy,'DisplayName','Center of Mass','LineWidth',2,'Color',[0 0 1]);
plot(S1x,S1y,'DisplayName','Particle 1','LineWidth',1,'Color',[1 0 0]);
plot(S2x,S2y,'DisplayName','Particle 2','LineWidth',1,'Color',[0 1 0]);
legend show;