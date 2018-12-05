function [radiance] = planck_wv(T,wv);
%
%        function [radiance] = planck_wv(T,wv);
%
%    ....planck_wv.m
%
%        This is a MATLAB script that calculates the Planck radiance
%        given 1-by-N vectors of temperature (T) in Kelvin and 
%        wavelengths (wv) in um.  The radiance (radiance) is in 
%        W m-2 sr-1 um-1.
%
%        Written by: Von Walden
%                    13 January 1998
%

[r_T ,c_T]  = size(T);
[r_wv,c_wv] = size(wv);

if(r_T~=1 | r_wv~=1)
   disp('One of the input vectors is NOT a column vector.')
   disp('Try again!')
   return;
end

h = 6.626e-34;
c = 3.0e+8;
k = 1.381e-23;

wv = wv*1e-6;
radiance = (2*h*c*c) ./ ( ones(size(T'))*(wv.^5)  .* (exp(h*c./(k*(T')*wv)) - 1.)) / 1e6;


