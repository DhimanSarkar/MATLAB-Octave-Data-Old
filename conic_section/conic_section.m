% Created by ShadyE
% Copyright (c) StanLab 2016

clear;
clc;

% defining directrix
prompt = 'Enter X coefficient -- ';
a = input (prompt);
prompt = 'Enter Y coefficient -- ';
b = input (prompt);
prompt = 'Enter Constant part -- ';
c = input (prompt);
m=-a./b;
syms directrixH directrixK;
solveDirectrixY = solve(a.*directrixH + b.*directrixK + c == 0, directrixK)
directrixX = -100:.1:100 ;
directrixY = subs(solveDirectrixY,directrixH,directrixX);
disp(['Equation of the directrix is,--> ',num2str(a),'x+',num2str(b),'y+',num2str(c),'=0']);

% defining parabola
prompt = 'Enter the Eccentricity of the conic section -- ';
Eccentricity = input(prompt);
prompt = 'Enter the X coordinate of focus -- ';
FocusX = input(prompt);
prompt = 'Enter the Y coordinate of focus -- ';
FocusY = input(prompt);
disp(['Focus is,--> (',num2str(FocusX),',',num2str(FocusY),')']);
syms x y;
FocusLocusSquare = ((x-FocusX).^2 + (y-FocusY).^2) ;
DirectrixLocusSquare = ((a.*x+b.*y+c).^2 ./ (a.^2+b.^2)) ;
ecentricitySquare = FocusLocusSquare ./ DirectrixLocusSquare ;
ConicSectionX = -100:.1:100 ;
solveConicSectionY = solve(ecentricitySquare == Eccentricity.^2, y);
ConicSectionY=subs(solveConicSectionY,x,ConicSectionX);

% Defining Axis
AxisC = FocusX.*b - FocusY.*a;
solveAxisY=solve(b.*x - a.*y+AxisC == 0,y);
AxisX=-100:.1:100;
AxisY=subs(solveAxisY,x,AxisX);


% Ploting Directrix
% Ploting Axis
% Ploting Conic Section
figure;
Plot = plot(ConicSectionX,ConicSectionY,AxisX,AxisY,directrixX,directrixY,FocusX,FocusY);
axis equal;
if (Eccentricity==1)
    title('Conic Section - Parabola');
elseif (Eccentricity>1)
    title('Conic Section - Hyparabola');
elseif (Eccentricity<1)
    title('Conic Section - Elipse');
end
xlabel = ('X');
ylabel = ('Y');

% End of Script