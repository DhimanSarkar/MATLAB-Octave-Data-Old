function [radiance] = planck_wn(T,wn);
%
%        function [radiance] = planck_wn(T,wn);
%
%    ....planck_wn.m
%
%        This is a MATLAB script that calculates the Planck radiance
%        given 1-by-N vectors of temperature (T) in Kelvin and 
%        wavenumbers (wn) in cm-1.  The radiance (radiance) is in 
%        mW m-2 sr-1 (cm-1)-1.
%
%        Written by: Von Walden
%                    25 January 1998
%

[r_T ,c_T]  = size(T);
[r_wn,c_wn] = size(wn);

if(r_T~=1 | r_wn~=1)
   disp('One of the input vectors is NOT a column vector.')
   disp('Try again!')
   return;
end

h = 6.626e-34;
c = 3.0e+8;
k = 1.381e-23;

wv = 1./(wn*100.);

radiance = (2.e+5*h*c*c) ./ ( ones(size(T'))* (wv.^3) ) ./ (exp(h*c./(k*(T')*wv)) - 1.);

