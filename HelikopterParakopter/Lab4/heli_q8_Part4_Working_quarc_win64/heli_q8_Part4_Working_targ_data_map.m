  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
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
    ;% Auto data (heli_q8_Part4_Working_P)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.A_d
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_P.B_d
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 144;
	
	  ;% heli_q8_Part4_Working_P.C_d
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 168;
	
	  ;% heli_q8_Part4_Working_P.F
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 312;
	
	  ;% heli_q8_Part4_Working_P.Joystick_gain_x
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 316;
	
	  ;% heli_q8_Part4_Working_P.Joystick_gain_y
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 317;
	
	  ;% heli_q8_Part4_Working_P.K
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 318;
	
	  ;% heli_q8_Part4_Working_P.P_0
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 328;
	
	  ;% heli_q8_Part4_Working_P.Q_d
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 472;
	
	  ;% heli_q8_Part4_Working_P.R_d2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 616;
	
	  ;% heli_q8_Part4_Working_P.V_s0
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 760;
	
	  ;% heli_q8_Part4_Working_P.x_0
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 761;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.HILWriteAnalog_channels
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 68;
      section.data(68)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.HILInitialize_OOTerminate
	  section.data(1).logicalSrcIdx = 13;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_OOExit
	  section.data(2).logicalSrcIdx = 14;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_OOStart
	  section.data(3).logicalSrcIdx = 15;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_OOEnter
	  section.data(4).logicalSrcIdx = 16;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOFinal
	  section.data(5).logicalSrcIdx = 17;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POFinal
	  section.data(6).logicalSrcIdx = 18;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AIHigh
	  section.data(7).logicalSrcIdx = 19;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AILow
	  section.data(8).logicalSrcIdx = 20;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOHigh
	  section.data(9).logicalSrcIdx = 21;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOLow
	  section.data(10).logicalSrcIdx = 22;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOInitial
	  section.data(11).logicalSrcIdx = 23;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOWatchdog
	  section.data(12).logicalSrcIdx = 24;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POFrequency
	  section.data(13).logicalSrcIdx = 25;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POLeading
	  section.data(14).logicalSrcIdx = 26;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POTrailing
	  section.data(15).logicalSrcIdx = 27;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POInitial
	  section.data(16).logicalSrcIdx = 28;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POWatchdog
	  section.data(17).logicalSrcIdx = 29;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_Part4_Working_P.ElevationCounttorad_Gain
	  section.data(18).logicalSrcIdx = 30;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_Part4_Working_P.ElevationTransferFcn_A
	  section.data(19).logicalSrcIdx = 31;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_Part4_Working_P.ElevationTransferFcn_C
	  section.data(20).logicalSrcIdx = 32;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_Part4_Working_P.ElevationTransferFcn_D
	  section.data(21).logicalSrcIdx = 33;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_Part4_Working_P.Constant_Value
	  section.data(22).logicalSrcIdx = 34;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_Part4_Working_P.Constant1_Value
	  section.data(23).logicalSrcIdx = 35;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_Part4_Working_P.Memory_InitialCondition
	  section.data(24).logicalSrcIdx = 36;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_Part4_Working_P.Gain1_Gain
	  section.data(25).logicalSrcIdx = 37;
	  section.data(25).dtTransOffset = 33;
	
	  ;% heli_q8_Part4_Working_P.Gain2_Gain
	  section.data(26).logicalSrcIdx = 38;
	  section.data(26).dtTransOffset = 42;
	
	  ;% heli_q8_Part4_Working_P.Constant_Value_j
	  section.data(27).logicalSrcIdx = 39;
	  section.data(27).dtTransOffset = 51;
	
	  ;% heli_q8_Part4_Working_P.Integrator2_IC
	  section.data(28).logicalSrcIdx = 40;
	  section.data(28).dtTransOffset = 52;
	
	  ;% heli_q8_Part4_Working_P.Integrator1_IC
	  section.data(29).logicalSrcIdx = 41;
	  section.data(29).dtTransOffset = 53;
	
	  ;% heli_q8_Part4_Working_P.Integrator3_IC
	  section.data(30).logicalSrcIdx = 42;
	  section.data(30).dtTransOffset = 54;
	
	  ;% heli_q8_Part4_Working_P.UnitDelay2_InitialCondition
	  section.data(31).logicalSrcIdx = 43;
	  section.data(31).dtTransOffset = 55;
	
	  ;% heli_q8_Part4_Working_P.UnitDelay_InitialCondition
	  section.data(32).logicalSrcIdx = 44;
	  section.data(32).dtTransOffset = 56;
	
	  ;% heli_q8_Part4_Working_P.UnitDelay1_InitialCondition
	  section.data(33).logicalSrcIdx = 45;
	  section.data(33).dtTransOffset = 57;
	
	  ;% heli_q8_Part4_Working_P.UnitDelay_InitialCondition_p
	  section.data(34).logicalSrcIdx = 46;
	  section.data(34).dtTransOffset = 58;
	
	  ;% heli_q8_Part4_Working_P.Integrator_IC
	  section.data(35).logicalSrcIdx = 47;
	  section.data(35).dtTransOffset = 59;
	
	  ;% heli_q8_Part4_Working_P.UnitDelay1_InitialCondition_i
	  section.data(36).logicalSrcIdx = 48;
	  section.data(36).dtTransOffset = 60;
	
	  ;% heli_q8_Part4_Working_P.RateTransitionx_InitialConditio
	  section.data(37).logicalSrcIdx = 49;
	  section.data(37).dtTransOffset = 61;
	
	  ;% heli_q8_Part4_Working_P.DeadZonex_Start
	  section.data(38).logicalSrcIdx = 50;
	  section.data(38).dtTransOffset = 62;
	
	  ;% heli_q8_Part4_Working_P.DeadZonex_End
	  section.data(39).logicalSrcIdx = 51;
	  section.data(39).dtTransOffset = 63;
	
	  ;% heli_q8_Part4_Working_P.Gainx_Gain
	  section.data(40).logicalSrcIdx = 52;
	  section.data(40).dtTransOffset = 64;
	
	  ;% heli_q8_Part4_Working_P.RateTransitiony_InitialConditio
	  section.data(41).logicalSrcIdx = 53;
	  section.data(41).dtTransOffset = 65;
	
	  ;% heli_q8_Part4_Working_P.DeadZoney_Start
	  section.data(42).logicalSrcIdx = 54;
	  section.data(42).dtTransOffset = 66;
	
	  ;% heli_q8_Part4_Working_P.DeadZoney_End
	  section.data(43).logicalSrcIdx = 55;
	  section.data(43).dtTransOffset = 67;
	
	  ;% heli_q8_Part4_Working_P.Gainy_Gain
	  section.data(44).logicalSrcIdx = 56;
	  section.data(44).dtTransOffset = 68;
	
	  ;% heli_q8_Part4_Working_P.PitchCounttorad_Gain
	  section.data(45).logicalSrcIdx = 57;
	  section.data(45).dtTransOffset = 69;
	
	  ;% heli_q8_Part4_Working_P.PitchTransferFcn_A
	  section.data(46).logicalSrcIdx = 58;
	  section.data(46).dtTransOffset = 70;
	
	  ;% heli_q8_Part4_Working_P.PitchTransferFcn_C
	  section.data(47).logicalSrcIdx = 59;
	  section.data(47).dtTransOffset = 71;
	
	  ;% heli_q8_Part4_Working_P.PitchTransferFcn_D
	  section.data(48).logicalSrcIdx = 60;
	  section.data(48).dtTransOffset = 72;
	
	  ;% heli_q8_Part4_Working_P.Integrator1_IC_c
	  section.data(49).logicalSrcIdx = 61;
	  section.data(49).dtTransOffset = 73;
	
	  ;% heli_q8_Part4_Working_P.TravelCounttorad_Gain
	  section.data(50).logicalSrcIdx = 62;
	  section.data(50).dtTransOffset = 74;
	
	  ;% heli_q8_Part4_Working_P.TravelTransferFcn_A
	  section.data(51).logicalSrcIdx = 63;
	  section.data(51).dtTransOffset = 75;
	
	  ;% heli_q8_Part4_Working_P.TravelTransferFcn_C
	  section.data(52).logicalSrcIdx = 64;
	  section.data(52).dtTransOffset = 76;
	
	  ;% heli_q8_Part4_Working_P.TravelTransferFcn_D
	  section.data(53).logicalSrcIdx = 65;
	  section.data(53).dtTransOffset = 77;
	
	  ;% heli_q8_Part4_Working_P.Integrator2_IC_h
	  section.data(54).logicalSrcIdx = 66;
	  section.data(54).dtTransOffset = 78;
	
	  ;% heli_q8_Part4_Working_P.Integrator3_IC_o
	  section.data(55).logicalSrcIdx = 67;
	  section.data(55).dtTransOffset = 79;
	
	  ;% heli_q8_Part4_Working_P.Integrator4_IC
	  section.data(56).logicalSrcIdx = 68;
	  section.data(56).dtTransOffset = 80;
	
	  ;% heli_q8_Part4_Working_P.Backgain_Gain
	  section.data(57).logicalSrcIdx = 69;
	  section.data(57).dtTransOffset = 81;
	
	  ;% heli_q8_Part4_Working_P.Frontgain_Gain
	  section.data(58).logicalSrcIdx = 70;
	  section.data(58).dtTransOffset = 82;
	
	  ;% heli_q8_Part4_Working_P.FrontmotorSaturation_UpperSat
	  section.data(59).logicalSrcIdx = 71;
	  section.data(59).dtTransOffset = 83;
	
	  ;% heli_q8_Part4_Working_P.FrontmotorSaturation_LowerSat
	  section.data(60).logicalSrcIdx = 72;
	  section.data(60).dtTransOffset = 84;
	
	  ;% heli_q8_Part4_Working_P.BackmotorSaturation_UpperSat
	  section.data(61).logicalSrcIdx = 73;
	  section.data(61).dtTransOffset = 85;
	
	  ;% heli_q8_Part4_Working_P.BackmotorSaturation_LowerSat
	  section.data(62).logicalSrcIdx = 74;
	  section.data(62).dtTransOffset = 86;
	
	  ;% heli_q8_Part4_Working_P.gamma_IC
	  section.data(63).logicalSrcIdx = 75;
	  section.data(63).dtTransOffset = 87;
	
	  ;% heli_q8_Part4_Working_P.zeta_IC
	  section.data(64).logicalSrcIdx = 76;
	  section.data(64).dtTransOffset = 88;
	
	  ;% heli_q8_Part4_Working_P.Integrator_IC_k
	  section.data(65).logicalSrcIdx = 77;
	  section.data(65).dtTransOffset = 89;
	
	  ;% heli_q8_Part4_Working_P.Integrator_UpperSat
	  section.data(66).logicalSrcIdx = 78;
	  section.data(66).dtTransOffset = 90;
	
	  ;% heli_q8_Part4_Working_P.Integrator_LowerSat
	  section.data(67).logicalSrcIdx = 79;
	  section.data(67).dtTransOffset = 91;
	
	  ;% heli_q8_Part4_Working_P.K_ei_Gain
	  section.data(68).logicalSrcIdx = 80;
	  section.data(68).dtTransOffset = 92;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOWatchdog
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 4;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POModes
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 5;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POConfiguration
	  section.data(5).logicalSrcIdx = 85;
	  section.data(5).dtTransOffset = 6;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POAlignment
	  section.data(6).logicalSrcIdx = 86;
	  section.data(6).dtTransOffset = 7;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POPolarity
	  section.data(7).logicalSrcIdx = 87;
	  section.data(7).dtTransOffset = 8;
	
	  ;% heli_q8_Part4_Working_P.HILReadEncoderTimebase_Clock
	  section.data(8).logicalSrcIdx = 88;
	  section.data(8).dtTransOffset = 9;
	
	  ;% heli_q8_Part4_Working_P.StreamCall1_SendBufferSize
	  section.data(9).logicalSrcIdx = 89;
	  section.data(9).dtTransOffset = 10;
	
	  ;% heli_q8_Part4_Working_P.StreamCall1_ReceiveBufferSize
	  section.data(10).logicalSrcIdx = 90;
	  section.data(10).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 8;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_EIChannels
	  section.data(3).logicalSrcIdx = 93;
	  section.data(3).dtTransOffset = 16;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_EIQuadrature
	  section.data(4).logicalSrcIdx = 94;
	  section.data(4).dtTransOffset = 24;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POChannels
	  section.data(5).logicalSrcIdx = 95;
	  section.data(5).dtTransOffset = 25;
	
	  ;% heli_q8_Part4_Working_P.HILReadEncoderTimebase_Channels
	  section.data(6).logicalSrcIdx = 96;
	  section.data(6).dtTransOffset = 33;
	
	  ;% heli_q8_Part4_Working_P.HILReadEncoderTimebase_SamplesI
	  section.data(7).logicalSrcIdx = 97;
	  section.data(7).dtTransOffset = 36;
	
	  ;% heli_q8_Part4_Working_P.StreamFormattedWrite_MaxUnits
	  section.data(8).logicalSrcIdx = 98;
	  section.data(8).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.GameController_BufferSize
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 101;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 102;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 103;
	  section.data(4).dtTransOffset = 3;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 104;
	  section.data(5).dtTransOffset = 4;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 105;
	  section.data(6).dtTransOffset = 5;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 106;
	  section.data(7).dtTransOffset = 6;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 107;
	  section.data(8).dtTransOffset = 7;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 108;
	  section.data(9).dtTransOffset = 8;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 109;
	  section.data(10).dtTransOffset = 9;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 110;
	  section.data(11).dtTransOffset = 10;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 111;
	  section.data(12).dtTransOffset = 11;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 112;
	  section.data(13).dtTransOffset = 12;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 113;
	  section.data(14).dtTransOffset = 13;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 114;
	  section.data(15).dtTransOffset = 14;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 115;
	  section.data(16).dtTransOffset = 15;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 116;
	  section.data(17).dtTransOffset = 16;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 117;
	  section.data(18).dtTransOffset = 17;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 118;
	  section.data(19).dtTransOffset = 18;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 119;
	  section.data(20).dtTransOffset = 19;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 120;
	  section.data(21).dtTransOffset = 20;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 121;
	  section.data(22).dtTransOffset = 21;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 122;
	  section.data(23).dtTransOffset = 22;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 123;
	  section.data(24).dtTransOffset = 23;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 124;
	  section.data(25).dtTransOffset = 24;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 125;
	  section.data(26).dtTransOffset = 25;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 126;
	  section.data(27).dtTransOffset = 26;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 127;
	  section.data(28).dtTransOffset = 27;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 128;
	  section.data(29).dtTransOffset = 28;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 129;
	  section.data(30).dtTransOffset = 29;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 130;
	  section.data(31).dtTransOffset = 30;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 131;
	  section.data(32).dtTransOffset = 31;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 132;
	  section.data(33).dtTransOffset = 32;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 133;
	  section.data(34).dtTransOffset = 33;
	
	  ;% heli_q8_Part4_Working_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 134;
	  section.data(35).dtTransOffset = 34;
	
	  ;% heli_q8_Part4_Working_P.HILReadEncoderTimebase_Active
	  section.data(36).logicalSrcIdx = 135;
	  section.data(36).dtTransOffset = 35;
	
	  ;% heli_q8_Part4_Working_P.StreamCall1_NonBlocking
	  section.data(37).logicalSrcIdx = 136;
	  section.data(37).dtTransOffset = 36;
	
	  ;% heli_q8_Part4_Working_P.StreamCall1_Active
	  section.data(38).logicalSrcIdx = 137;
	  section.data(38).dtTransOffset = 37;
	
	  ;% heli_q8_Part4_Working_P.HILWriteAnalog_Active
	  section.data(39).logicalSrcIdx = 138;
	  section.data(39).dtTransOffset = 38;
	
	  ;% heli_q8_Part4_Working_P.GameController_AutoCenter
	  section.data(40).logicalSrcIdx = 139;
	  section.data(40).dtTransOffset = 39;
	
	  ;% heli_q8_Part4_Working_P.GameController_Enabled
	  section.data(41).logicalSrcIdx = 140;
	  section.data(41).dtTransOffset = 40;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_P.HILReadEncoderTimebase_Overflow
	  section.data(1).logicalSrcIdx = 141;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_P.StringConstant_Value
	  section.data(2).logicalSrcIdx = 142;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_Part4_Working_P.StreamCall1_URI
	  section.data(3).logicalSrcIdx = 143;
	  section.data(3).dtTransOffset = 256;
	
	  ;% heli_q8_Part4_Working_P.StreamCall1_Endian
	  section.data(4).logicalSrcIdx = 144;
	  section.data(4).dtTransOffset = 257;
	
	  ;% heli_q8_Part4_Working_P.GameController_ControllerNumber
	  section.data(5).logicalSrcIdx = 145;
	  section.data(5).dtTransOffset = 258;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
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
    nTotSects     = 2;
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
    ;% Auto data (heli_q8_Part4_Working_B)
    ;%
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_B.ElevationCounttorad
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_B.ElevationTransferFcn
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_Part4_Working_B.Switch
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_Part4_Working_B.Gain1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 12;
	
	  ;% heli_q8_Part4_Working_B.Gain2
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% heli_q8_Part4_Working_B.Sum
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 18;
	
	  ;% heli_q8_Part4_Working_B.p
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 19;
	
	  ;% heli_q8_Part4_Working_B.e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 20;
	
	  ;% heli_q8_Part4_Working_B.lambda
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 21;
	
	  ;% heli_q8_Part4_Working_B.V_s_tilde
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 22;
	
	  ;% heli_q8_Part4_Working_B.V_d
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 23;
	
	  ;% heli_q8_Part4_Working_B.Sum_n
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 24;
	
	  ;% heli_q8_Part4_Working_B.Gyro_e
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 25;
	
	  ;% heli_q8_Part4_Working_B.V_s
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 26;
	
	  ;% heli_q8_Part4_Working_B.RateTransitionx
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 27;
	
	  ;% heli_q8_Part4_Working_B.Joystick_gain_x
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 28;
	
	  ;% heli_q8_Part4_Working_B.RateTransitiony
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 29;
	
	  ;% heli_q8_Part4_Working_B.Joystick_gain_y
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 30;
	
	  ;% heli_q8_Part4_Working_B.PitchCounttorad
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 31;
	
	  ;% heli_q8_Part4_Working_B.PitchTransferFcn
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 32;
	
	  ;% heli_q8_Part4_Working_B.Gyro_p
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 33;
	
	  ;% heli_q8_Part4_Working_B.TravelCounttorad
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 34;
	
	  ;% heli_q8_Part4_Working_B.TravelTransferFcn
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 35;
	
	  ;% heli_q8_Part4_Working_B.Integrator2
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 36;
	
	  ;% heli_q8_Part4_Working_B.Integrator3
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 37;
	
	  ;% heli_q8_Part4_Working_B.Integrator4
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 38;
	
	  ;% heli_q8_Part4_Working_B.TmpSignalConversionAtToFileInpo
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 39;
	
	  ;% heli_q8_Part4_Working_B.gamma
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 73;
	
	  ;% heli_q8_Part4_Working_B.zeta
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 74;
	
	  ;% heli_q8_Part4_Working_B.F
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 75;
	
	  ;% heli_q8_Part4_Working_B.U
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 77;
	
	  ;% heli_q8_Part4_Working_B.Sum_f
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 79;
	
	  ;% heli_q8_Part4_Working_B.Sum2
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 80;
	
	  ;% heli_q8_Part4_Working_B.Sum3
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 81;
	
	  ;% heli_q8_Part4_Working_B.K_ei
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 82;
	
	  ;% heli_q8_Part4_Working_B.x_priori
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 83;
	
	  ;% heli_q8_Part4_Working_B.P_priori
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 95;
	
	  ;% heli_q8_Part4_Working_B.x_posteriori
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 239;
	
	  ;% heli_q8_Part4_Working_B.P_posteriori
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 251;
	
	  ;% heli_q8_Part4_Working_B.p_a
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 395;
	
	  ;% heli_q8_Part4_Working_B.euler_rates
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 396;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_B.StreamCall1_o2
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
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
    nTotSects     = 10;
    sectIdxOffset = 2;
    
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
    ;% Auto data (heli_q8_Part4_Working_DW)
    ;%
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.UnitDelay2_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_DW.UnitDelay_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% heli_q8_Part4_Working_DW.UnitDelay1_DSTATE
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% heli_q8_Part4_Working_DW.UnitDelay_DSTATE_m
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 14;
	
	  ;% heli_q8_Part4_Working_DW.UnitDelay1_DSTATE_c
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 158;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_AIMinimums
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 159;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_AIMaximums
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 167;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_AOMinimums
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 175;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_AOMaximums
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 183;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_AOVoltages
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 191;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_FilterFrequency
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 199;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_POSortedFreqs
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 207;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_POValues
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 215;
	
	  ;% heli_q8_Part4_Working_DW.Memory_PreviousInput
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 223;
	
	  ;% heli_q8_Part4_Working_DW.RateTransitionx_Buffer0
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 233;
	
	  ;% heli_q8_Part4_Working_DW.RateTransitiony_Buffer0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 234;
	
	  ;% heli_q8_Part4_Working_DW.HILWriteAnalog_Buffer
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 235;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.StreamCall1_Stream
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.GameController_Controller
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.HILReadEncoderTimebase_Task
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.ElevationRaterads_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_DW.Elevationrad_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_Part4_Working_DW.InputVoltageV_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 6;
	
	  ;% heli_q8_Part4_Working_DW.PitchRaterads_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 11;
	
	  ;% heli_q8_Part4_Working_DW.Pitchrad_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 14;
	
	  ;% heli_q8_Part4_Working_DW.Scope_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 17;
	
	  ;% heli_q8_Part4_Working_DW.ToFile_PWORK.FilePtr
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 23;
	
	  ;% heli_q8_Part4_Working_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 24;
	
	  ;% heli_q8_Part4_Working_DW.TravelRaterads_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 25;
	
	  ;% heli_q8_Part4_Working_DW.V_dV_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 30;
	
	  ;% heli_q8_Part4_Working_DW.V_sV_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 31;
	
	  ;% heli_q8_Part4_Working_DW.e_dotrads_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 32;
	
	  ;% heli_q8_Part4_Working_DW.lambda_dotrads_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 33;
	  section.data(13).dtTransOffset = 33;
	
	  ;% heli_q8_Part4_Working_DW.p_dotrads_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 34;
	  section.data(14).dtTransOffset = 34;
	
	  ;% heli_q8_Part4_Working_DW.Gyro_erad_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 35;
	  section.data(15).dtTransOffset = 35;
	
	  ;% heli_q8_Part4_Working_DW.Gyro_prad_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 36;
	  section.data(16).dtTransOffset = 36;
	
	  ;% heli_q8_Part4_Working_DW.a_xms2_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 37;
	  section.data(17).dtTransOffset = 37;
	
	  ;% heli_q8_Part4_Working_DW.a_yms2_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 38;
	  section.data(18).dtTransOffset = 38;
	
	  ;% heli_q8_Part4_Working_DW.a_zms2_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 39;
	  section.data(19).dtTransOffset = 39;
	
	  ;% heli_q8_Part4_Working_DW.omega_erads_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 40;
	  section.data(20).dtTransOffset = 40;
	
	  ;% heli_q8_Part4_Working_DW.omega_lambdarads_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 41;
	  section.data(21).dtTransOffset = 41;
	
	  ;% heli_q8_Part4_Working_DW.omega_prads_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 42;
	  section.data(22).dtTransOffset = 42;
	
	  ;% heli_q8_Part4_Working_DW.ElevationRate_Encrads_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 43;
	  section.data(23).dtTransOffset = 43;
	
	  ;% heli_q8_Part4_Working_DW.Elevation_Encrad_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 44;
	  section.data(24).dtTransOffset = 44;
	
	  ;% heli_q8_Part4_Working_DW.PitchRate_Encrads_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 45;
	  section.data(25).dtTransOffset = 45;
	
	  ;% heli_q8_Part4_Working_DW.Pitch_Encrad_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 46;
	  section.data(26).dtTransOffset = 46;
	
	  ;% heli_q8_Part4_Working_DW.TravelRate_Encrads_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 47;
	  section.data(27).dtTransOffset = 47;
	
	  ;% heli_q8_Part4_Working_DW.Travel_Encrad_PWORK.LoggedData
	  section.data(28).logicalSrcIdx = 48;
	  section.data(28).dtTransOffset = 48;
	
	  ;% heli_q8_Part4_Working_DW.HILWriteAnalog_PWORK
	  section.data(29).logicalSrcIdx = 49;
	  section.data(29).dtTransOffset = 49;
	
	  ;% heli_q8_Part4_Working_DW.Connected_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 50;
	  section.data(30).dtTransOffset = 50;
	
	  ;% heli_q8_Part4_Working_DW.XScope_PWORK.LoggedData
	  section.data(31).logicalSrcIdx = 51;
	  section.data(31).dtTransOffset = 51;
	
	  ;% heli_q8_Part4_Working_DW.YScope_PWORK.LoggedData
	  section.data(32).logicalSrcIdx = 52;
	  section.data(32).dtTransOffset = 52;
	
	  ;% heli_q8_Part4_Working_DW.x_hat_PWORK.LoggedData
	  section.data(33).logicalSrcIdx = 53;
	  section.data(33).dtTransOffset = 53;
	
	  ;% heli_q8_Part4_Working_DW.Joy_X_PWORK.LoggedData
	  section.data(34).logicalSrcIdx = 54;
	  section.data(34).dtTransOffset = 56;
	
	  ;% heli_q8_Part4_Working_DW.Joy_Y_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 55;
	  section.data(35).dtTransOffset = 57;
	
	  ;% heli_q8_Part4_Working_DW.gammascope_PWORK.LoggedData
	  section.data(36).logicalSrcIdx = 56;
	  section.data(36).dtTransOffset = 58;
	
	  ;% heli_q8_Part4_Working_DW.zetascope_PWORK.LoggedData
	  section.data(37).logicalSrcIdx = 57;
	  section.data(37).dtTransOffset = 59;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 3;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 11;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 19;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 62;
	  section.data(5).dtTransOffset = 27;
	
	  ;% heli_q8_Part4_Working_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 63;
	  section.data(6).dtTransOffset = 35;
	
	  ;% heli_q8_Part4_Working_DW.HILReadEncoderTimebase_Buffer
	  section.data(7).logicalSrcIdx = 64;
	  section.data(7).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% heli_q8_Part4_Working_DW.StreamCall1_State
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
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


  targMap.checksum0 = 3311556468;
  targMap.checksum1 = 721662016;
  targMap.checksum2 = 2328718924;
  targMap.checksum3 = 2479644021;

