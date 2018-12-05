% Releigh-Jean Curve
clear;
clc;

X1 = 0:.01:16;
Y1 = X1.^3 ./(exp(X1)-1);
X2=0:.5:16;
Y2 = X2.^3 ./(exp(X2)-1);
hold on;
bar(X2,Y2,'DisplayName','Plank''s Quantaisation','FaceColor',[0 0.600000023841858 0],'EdgeColor',[0 0.600000023841858 0]);
plot(X1,Y1,'DisplayName','Rayleigh - Jean Curve','LineWidth',2,'Color',[1 0 0]);
legend show;
box on;
grid on;