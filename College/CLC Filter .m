clear; 
clc;

t=0:.1:10;
L = 150e-3
C1 = 220e-6
C2 = 220e-6
Rl = 1e3

Vm = 10

w = 2*pi*50





Xl = j .* w .* L

Xc1 = -j/(C1*w)

Xc2 = -1j/(C2*w)


Z = (Xc1.*Xc2+Xc2.*Rl+Xl.*C1+Xl.*Rl+Xc1.*Rl)/(Xc1+Rl)

modZ = abs(Z)

argZ = angle(Z)


Vl = (2.*Vm./(pi.*Rl) - 4.*Vm.*cos(2.*w.*t-argZ)./(3.*pi.*modZ)).*Rl;


plot(t,Vl);