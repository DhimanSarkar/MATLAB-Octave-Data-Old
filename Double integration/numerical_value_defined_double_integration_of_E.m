clear;
clc;

syms x y
Q=1;
l=10;
epsilon0=8.8419E-12;


yFucnction=(Q.*l./(2.*4.*pi.*epsilon0))./((x-l./2).^2+(y-l./2).^2+(l./2).^2).^2

definedintY = int(yFucnction,y,0,l)

xFunction = definedintY

definedintX = int(xFunction,x,0,l)

ultimateIntegral = definedintX