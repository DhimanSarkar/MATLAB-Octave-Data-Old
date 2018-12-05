  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 28;
      section.data(28)  = dumData; %prealloc
      
	  ;% rtP.Ixx
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.Iyy
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtP.Kf
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtP.Kr
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtP.L
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtP.Mb
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtP.W
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtP.g
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtP.Z_IC
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtP.THETA_IC
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtP.PHI_IC
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtP.FromWs_Time0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtP.FromWs_Data0
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 2057;
	
	  ;% rtP.stiffness_Gain
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 6149;
	
	  ;% rtP.THETAdot_IC
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 6150;
	
	  ;% rtP.PHIdot_IC
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 6151;
	
	  ;% rtP.Zdot_IC
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 6152;
	
	  ;% rtP.damping_Gain
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 6153;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 6154;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 6155;
	
	  ;% rtP.stiffness_Gain_ejfmxf0ubt
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 6156;
	
	  ;% rtP.damping_Gain_jmhajh5utx
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 6157;
	
	  ;% rtP.stiffness_Gain_oi4325ilzi
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 6158;
	
	  ;% rtP.damping_Gain_kormbqmmae
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 6159;
	
	  ;% rtP.TransportDelay1_Delay
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 6160;
	
	  ;% rtP.TransportDelay1_InitOutput
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 6161;
	
	  ;% rtP.stiffness_Gain_dkutidbsbf
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 6162;
	
	  ;% rtP.damping_Gain_otuxh5svgn
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 6163;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% rtB.kf3x2lfbm2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.athg3b0cpi
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtB.iwrzxexy4o
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtB.m2js5kfkdp
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtB.k5fo1npzjc
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtB.nh0ippmp3i
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtB.mutpjnrc5z
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtB.ipdxefuu4f
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.npwmhg4hk3.modelTStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.hr4o3k3rqn.modelTStart
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.hu2pioagaa.SignalProbe
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.mvyeftsaxy.LoggedData
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.jql45x2viu.TimePtr
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.borxbvmdf3.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.jwb3e3k5si.TUbufferPtrs
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDW.e15wz5f0je
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.n4oo1gwbci
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1023;
	
	  ;% rtDW.g4xb0secad.PrevIndex
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 1024;
	
	  ;% rtDW.i0jyyo5z4h.Tail
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 1025;
	
	  ;% rtDW.e03x3yx1t1.Tail
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 1026;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2766936934;
  targMap.checksum1 = 2617085270;
  targMap.checksum2 = 296463808;
  targMap.checksum3 = 1505035899;

