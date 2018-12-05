function Result = BlackBody(Temperature, Wavelength)
%BlackBody - Several black body calculations based on temperature (in
%  Kelvin) and, optionally, wavelength (in microns).  If "nargout" is zero
%  print results in pretty format.
%
%Result = BlackBody('Demo')
%Result = BlackBody(TEMPERATURE)
%Result = BlackBody(Temperature, Wavelength)
%
%
%TEMPERATURE    Scalar|Vector        Kelvin
%       Black body Temperature
%
%Temperature    Scalar               Kelvin
%       Black body Temperature
%
%Wavelength     Scalar|Vector      micro-meters
%       If this is a scalar value, or a vector of length greater than two,
%       then the results for each of these input wavelengths are
%       calculated and returned.  If this value is a vector of length two,
%       then the function assumes that this is a wavelength range and that
%       the user wants the integrated values over this range.
%
%Result         Structure
%   Result.Temperature      Scalar|Vector     Kelvin
%           Temperature of black body, same as input value
%   Result.TotalRadiance    Scalar|Vector     Watt/meter^2
%           Total radiance of black body, at each input temperature
%   Result.PeakRadiance     Scalar|Vector     micro-meters
%           Peak radiance wavelength, at each input temperature
%      --- If Wavelength input is a Scalar or Vector of length > 2 ---
%   Result.Wavelength       Scalar|Vector     micro-meters
%           Wavelengths evaluated, same as input values
%   Result.SpectralRadiance Scalar|Vector     Watts / meter^2/micron
%           Spectral Radiance at each wavelength
%   Result.Photons          Scalar|Vector     photons/sec/meter^2/micron
%           Number of photons emitted by the black body at each wavelength
%      --- If Wavelength input is a Vector of length == 2 ---
%   Result.Wavelength       Vector            micro-meters
%           Wavelength range evaluated, same as input values
%   Result.SpectralRadiance Vector            Watts / meter^2
%           Total radiance integrated over the input wavelength range
%   Result.Photons          Vector            photons/sec/meter^2
%           Total number of photons integrated over input wavelength range
%
%
%  Author      - Ron Stahl
%  Last Update - 11Dec07
%  Copyright   - Aerius Photonics
%  Reference  - "Optical Radiation Detectors" by Dereniak and Crowe


if(strcmpi(Temperature, 'Demo'));
    Demo;
    
else,
    
    % Important constants
    Planck = 6.62606896e-34;
    Boltzmann = 1.380650424e-23;
    c = 299792458;

    if(any(Temperature < 0)),
        error('Input Temperature Less Than Zero');
    end;
    

    Result.Temperature = Temperature;

    Sigma = (2 * (pi^5) * (Boltzmann^4)) / (15 * (Planck^3) * (c^2));
    Result.TotalRadiance = Sigma * (Temperature.^4);

    Result.PeakRadiance = (2.8979e-3 ./ Temperature) * 1e6;

    if(nargin > 1),
        if(length(Temperature) > 1),
            error(['Limit to only one Temperature value when ', ...
                'doing Wavelength calculations']);
        end;
    
        C1 = 2 * pi * Planck * (c^2);       	% Should be 3.7415e-16
        C2 = (Planck * c) / Boltzmann;          % Should be 1.43879e-2
        SpecRad([-1, Temperature, C1, C2]);
        K1 = 2 * pi * c;
    	K2 = (Planck * c / Boltzmann);
        Photons([-1, Temperature, K1, K2]);
        WL = Wavelength * 1e-6;
        if(length(Wavelength) ~= 2),            % Wavelength(s) input
            Result.Wavelength = Wavelength;
       		Result.SpectralRadiance = SpecRad(WL) * 1e-6;
       		Result.Photons = Photons(WL) * 1e-6;

        else,                                   % Wavelength Range input
            Result.Wavelength = [min(Wavelength), max(Wavelength)];
            Result.SpectralRadiance = quadgk(@SpecRad, min(WL), max(WL));
    		Result.Photons = quadgk(@Photons, min(WL), max(WL));

        end;
    end;

    if(nargout == 0),           % Make a pretty display
        Pretty(Result);
        clear Result
    end;
end;
return;


function out = SpecRad(WL)
persistent Temperature C1 C2
if(WL(1) < 0),
    Temperature = WL(2);
    C1 = WL(3);
    C2 = WL(4);
else,
	WL5 = WL.^5;
	out = C1 ./ (WL5 .* (exp(C2 ./ (WL .* Temperature)) - 1));
end;
return;

function out = Photons(WL)
persistent Temperature K1 K2
if(WL(1) < 0),
    Temperature = WL(2);
    K1 = WL(3);
    K2 = WL(4);
else,
	out = K1 ./ ((WL.^4) .* (exp(K2 ./ (WL .* Temperature)) - 1));
end;
return;

function Pretty(Result)
disp(['Calculation Results for a Black Body at ', ...
    num2str(Result.Temperature), 'K']);
temp = Result.TotalRadiance;
    disp('      Total Radiance');
    disp(['         ', num2str(temp), ' Watts / m^2']);
    disp(['         ', num2str(temp * 1e-2 * 1e-2), ' Watts / cm^2']);
temp = Result.PeakRadiance;
    disp('      Peak Radiance');
    disp(['         ', num2str(temp), ' microns wavelength']);
if(isfield(Result, 'SpectralRadiance')),
    Wavelength = Result.Wavelength;
    if(length(Wavelength) ~= 2),
        temp = Result.SpectralRadiance;
            disp(['      Spectral Radiance for Wavelength(s) ', ...
                num2str(Wavelength), ' microns']);
            disp(['         ', num2str(temp), ' Watts / meter^2/micron']);
            disp(['         ', num2str(temp * 1e-2 * 1e-2), ' Watts / cm^2/micron']);
        temp = Result.Photons;
            disp(['      Photons Emitted for Wavelength(s) ', ...
                num2str(Wavelength), ' microns']);
            disp(['         ', num2str(temp), ' Photons / second/meter^2/micron']);
            disp(['         ', num2str(temp * 1e-2 * 1e-2), ' Photons / second/cm^2/micron']);
    else,
        temp = Result.SpectralRadiance;
            disp(['      Spectral Radiance Integrated over Wavelength Range ', ...
                num2str(Wavelength(1)), ' microns to ', num2str(Wavelength(2)), ...
                ' microns']);
            disp(['         ', num2str(temp), ' Watts / meter^2']);
            disp(['         ', num2str(temp * 1e-2 * 1e-2), ' Watts / cm^2']);            
        temp = Result.Photons;
            disp(['      Photons Emitted Integrated over Wavelength Range ', ...
                num2str(Wavelength(1)), ' microns to ', num2str(Wavelength(2)), ...
                ' microns']);
            disp(['         ', num2str(temp), ' Photons / second/meter^2']);
            disp(['         ', num2str(temp * 1e-2 * 1e-2), ' Photons / second/cm^2']);
    end;
end;
return;

function Demo
disp('Making Plots of the black body radiance over different wavelength ranges');
disp('Peak Radiance is indicated in red');
Temp = [(4:4:1000),(1020 : 20 : 3000)];
Out = BlackBody(max(Temp));
Out = BlackBody(max(Temp), Out.PeakRadiance);
Top1 = Out.SpectralRadiance / 1000;
Out = BlackBody(max(Temp), min(Out.PeakRadiance, 5));
Top2 = Out.SpectralRadiance / 1000;
Out = BlackBody(max(Temp), 0.8);
Top3 = Out.SpectralRadiance;
Waves = [(0.01 : 0.01 : 0.8),(0.9 : 0.1 : 20)];
figure('doublebuffer', 'on', ...
    'units', 'normalized', ...
    'position', [0.1,0.1,0.8,0.8]);
for index = 1 : length(Temp),
    Out = BlackBody(Temp(index), Waves);
    SR = Out.SpectralRadiance;
    PR = Out.PeakRadiance;
    if(max(SR) > Top1),
        Top1 = Top1 * 10;
        Top2 = Top2 * 10;
        disp('Adjusting Vertical Scale');
        pause(2);
    end;
    subplot(2,2,1);
        plot(Waves, SR, 'k', [PR,PR], [0, max(SR)], '*-r');
        axis([0,max(Waves),0,Top1]);
        title(['Black Body Spectral Radiance out to Far-Wave IR at ', ...
            num2str(Temp(index)), ' Kelvin']);
        xlabel('Wavelength (microns)');
        ylabel('Radiance (watts / m^2)');
    subplot(2,2,2);
        plot(Waves, SR, 'k', [PR,PR], [0, max(SR)], '*-r');
        axis([0,5,0,Top2]);
        title(['Black Body Spectral Radiance out to Mid-Wave IR at ', ...
            num2str(Temp(index)), ' Kelvin']);
        xlabel('Wavelength (microns)');
        ylabel('Radiance (watts / m^2)');
    subplot(2,1,2);
        plot((1e3*Waves), SR, 'k', [PR,PR], [0, max(SR)], '*-r');
        axis([400,800,0,Top3]);
        title(['Black Body Spectral Radiance in Visible Light at ', ...
            num2str(Temp(index)), ' Kelvin']);
        xlabel('Wavelength (nano-meters)');
        ylabel('Radiance (watts / m^2)');
    drawnow;
end;
return;

