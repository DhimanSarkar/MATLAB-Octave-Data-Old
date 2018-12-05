clear;
clc;


LinearChargeDensity = .01;


syms L;
Q = L .* LinearChargeDensity;
dQ = diff(Q)

dE = (1/(4.*pi.*epsilon0)) .* dQ 