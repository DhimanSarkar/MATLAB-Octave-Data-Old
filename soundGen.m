close all; clear; clc;

f1 = 1000;
f2 = 500;
sF = 8000;
t = 5;

x=0:1/sF:t;

%y(1,1:80001)=sin(x.*2.*pi.*f1);
%y(2,1:80001)=sin(x.*2.*pi.*f2);
%y=y';
y=[sin(x.^4.*f1.*2.*pi).*(x.^-2+x.^3);cos(x.^3.*f2.*2.*pi).*(x.^-2+x.^3)];
sound(y,sF)