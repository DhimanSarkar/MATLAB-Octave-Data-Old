clear;
clc;

syms x y
Q=1;
l=10;
epsilon0=8.8419E-12;


yFucnction=(Q.*l./(2.*4.*pi.*epsilon0))./((x-l./2).^2+(y-l./2).^2+(l./2).^2).^2

intY=int(yFucnction,y)
definedY=subs(intY,y,l)-subs(intY,y,0)

xFunction = definedY

intX=int(xFunction,x)
definedX=subs(intX,x,l)-subs(intX,x,0)

ultimateIntegral = definedX