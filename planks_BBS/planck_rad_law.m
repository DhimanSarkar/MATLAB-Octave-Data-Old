
%defining the constants:
PlancksConstant=6.63e-34;
lightSpeed=2.998e8;
BoltzmanConstant=1.38e-23;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%calculation for first temperature
disp(' ')
T=input('Enter please first value of temperature in Kelvin:');
disp(' ')

gamma=300e-9:10e-9:1000e-8;
coeff1=(PlancksConstant.*lightSpeed)./(BoltzmanConstant.*T.*gamma);

%energy density function:
coeff2=(8.*pi.*PlancksConstant.*lightSpeed)./gamma.^5;
ED=coeff2.*(1./(exp(coeff1)-1));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%calculation for second temperature
disp(' ')
T1=input('Enter please second value of temperature in Kelvin:');
disp(' ')

coeff11=(PlancksConstant.*lightSpeed)./(BoltzmanConstant.*T1.*gamma);

%energy density function:
coeff21=(8.*pi.*PlancksConstant.*lightSpeed)./gamma.^5;
ED1=coeff21.*(1./(exp(coeff11)-1));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%calculation for second temperature
disp(' ')
T2=input('Enter please third value of temperature in Kelvin:');
disp(' ')

coeff12=(PlancksConstant.*lightSpeed)./(BoltzmanConstant.*T2.*gamma);

%energy density function:
coeff22=(8.*pi.*PlancksConstant.*lightSpeed)./gamma.^5;
ED2=coeff22.*(1./(exp(coeff12)-1));

plot(gamma,ED,'r',gamma,ED1,'g',gamma,ED2,'b')
ylabel('Energy density');
xlabel('Wavelength');
legend(num2str(T),num2str(T1),num2str(T2));

