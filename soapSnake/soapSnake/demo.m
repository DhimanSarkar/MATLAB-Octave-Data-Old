close all; 
%% The complex function  (-1)^x
N = 200;    FOV = 6; 
x = (-N/2:N/2-1)/N*FOV ;
z = (-1).^x;
figure; soapSnake(x, z, 1);


%% The complex function  exp(1i*2*pi*x), with Gaussian decaying magnitude:
xMin = -2.2; 
xMax = +2.2; 
N = 201; 

x = linspace(xMin,xMax,N); 
z = exp(1i*2*pi*x).*exp(-1/2*x.^2);
figure; soapSnake(x, z, 1);

%% A normal parabola x.^2;
N = 200;    FOV = 6; 
x = (-N/2:N/2-1)/N*FOV ;
z = x.^2;
figure; soapSnake(x, z, 1);

%% Some weird function with leave like pattern
xMin = -2.2; 
xMax = +2.2; 
N = 201; 
z = exp(1i*2*pi*x).*(sin(4*pi*x/(1/2+1/2*sqrt(5))).^4);
figure; soapSnake(x, z, 0);

%% Complex logarithmic function
N = 200;    FOV = 6;
x = (-N/2:N/2-1)/N*FOV ;
z = log(x);
figure; soapSnake(x, z, 1);

%% Complex sinus function
N = 200;    FOV = 6;
x = (-N/2:N/2-1)/N*FOV ;
z = sin(x + 1i);
figure; soapSnake(x, z, 1);
