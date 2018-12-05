clear;
clc;

a=2;
b=3;
c=4;
alpha=20;
beta=40;
syms x y;
y=solve(b.^2 .* x.^2 + 2.* (c.*a+alpha).*x-2.*(b.*c+beta).*y - 2.*a.*b.*x.*y + alpha.^2 + beta.^2==0,y)