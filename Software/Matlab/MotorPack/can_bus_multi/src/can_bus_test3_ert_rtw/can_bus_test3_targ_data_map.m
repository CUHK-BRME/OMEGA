  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
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
    ;% Auto data (can_bus_test3_P)
    ;%
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% can_bus_test3_P.DiscreteDerivative_ICPrevScaled
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_P.LINMOTCAN_PAR_ACCEL
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% can_bus_test3_P.LINMOTCAN_PAR_DECEL
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% can_bus_test3_P.LINMOTCAN_PAR_MAX_VEL
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% can_bus_test3_P.Constant7_Value
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% can_bus_test3_P.Constant8_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% can_bus_test3_P.Constant_Value
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% can_bus_test3_P.Constant6_Value
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% can_bus_test3_P.Constant16_Value
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% can_bus_test3_P.PAR_MASK_MODE_Value
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% can_bus_test3_P.Gain_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% can_bus_test3_P.Gain1_Gain
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% can_bus_test3_P.PAR_MASK_MODE_Value_g
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% can_bus_test3_P.Constant10_Value
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 16;
	
	  ;% can_bus_test3_P.Constant12_Value
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 17;
	
	  ;% can_bus_test3_P.SineWave_Amp
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 18;
	
	  ;% can_bus_test3_P.SineWave_Bias
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 19;
	
	  ;% can_bus_test3_P.SineWave_Freq
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 20;
	
	  ;% can_bus_test3_P.SineWave_Hsin
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 21;
	
	  ;% can_bus_test3_P.SineWave_HCos
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 22;
	
	  ;% can_bus_test3_P.SineWave_PSin
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 23;
	
	  ;% can_bus_test3_P.SineWave_PCos
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 24;
	
	  ;% can_bus_test3_P.SineWave1_Amp
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 25;
	
	  ;% can_bus_test3_P.SineWave1_Bias
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 26;
	
	  ;% can_bus_test3_P.SineWave1_Freq
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 27;
	
	  ;% can_bus_test3_P.SineWave1_Hsin
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 28;
	
	  ;% can_bus_test3_P.SineWave1_HCos
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 29;
	
	  ;% can_bus_test3_P.SineWave1_PSin
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 30;
	
	  ;% can_bus_test3_P.SineWave1_PCos
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 31;
	
	  ;% can_bus_test3_P.TSamp_WtEt
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 32;
	
	  ;% can_bus_test3_P.Gain_Gain_d
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 33;
	
	  ;% can_bus_test3_P.Gain1_Gain_p
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 34;
	
	  ;% can_bus_test3_P.Gain2_Gain
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 35;
	
	  ;% can_bus_test3_P.Constant17_Value
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 36;
	
	  ;% can_bus_test3_P.Constant18_Value
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% can_bus_test3_P.Constant9_Value
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_P.Constant15_Value
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
	  ;% can_bus_test3_P.Constant5_Value
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 2;
	
	  ;% can_bus_test3_P.Constant1_Value
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 3;
	
	  ;% can_bus_test3_P.Constant2_Value
	  section.data(5).logicalSrcIdx = 39;
	  section.data(5).dtTransOffset = 4;
	
	  ;% can_bus_test3_P.Constant3_Value
	  section.data(6).logicalSrcIdx = 40;
	  section.data(6).dtTransOffset = 5;
	
	  ;% can_bus_test3_P.Constant4_Value
	  section.data(7).logicalSrcIdx = 41;
	  section.data(7).dtTransOffset = 6;
	
	  ;% can_bus_test3_P.Constant11_Value
	  section.data(8).logicalSrcIdx = 42;
	  section.data(8).dtTransOffset = 7;
	
	  ;% can_bus_test3_P.Constant13_Value
	  section.data(9).logicalSrcIdx = 43;
	  section.data(9).dtTransOffset = 8;
	
	  ;% can_bus_test3_P.Constant14_Value
	  section.data(10).logicalSrcIdx = 44;
	  section.data(10).dtTransOffset = 9;
	
	  ;% can_bus_test3_P.Gain3_Gain
	  section.data(11).logicalSrcIdx = 45;
	  section.data(11).dtTransOffset = 10;
	
	  ;% can_bus_test3_P.Gain4_Gain
	  section.data(12).logicalSrcIdx = 46;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% can_bus_test3_P.SFunctionBuilder_P1
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_P.SFunctionBuilder_P5
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
	  ;% can_bus_test3_P.SFunctionBuilder_P1_k
	  section.data(3).logicalSrcIdx = 49;
	  section.data(3).dtTransOffset = 2;
	
	  ;% can_bus_test3_P.SFunctionBuilder_P2
	  section.data(4).logicalSrcIdx = 50;
	  section.data(4).dtTransOffset = 3;
	
	  ;% can_bus_test3_P.SFunctionBuilder_P3
	  section.data(5).logicalSrcIdx = 51;
	  section.data(5).dtTransOffset = 4;
	
	  ;% can_bus_test3_P.ManualSwitch2_CurrentSetting
	  section.data(6).logicalSrcIdx = 52;
	  section.data(6).dtTransOffset = 5;
	
	  ;% can_bus_test3_P.ManualSwitch3_CurrentSetting
	  section.data(7).logicalSrcIdx = 53;
	  section.data(7).dtTransOffset = 6;
	
	  ;% can_bus_test3_P.ManualSwitch_CurrentSetting
	  section.data(8).logicalSrcIdx = 54;
	  section.data(8).dtTransOffset = 7;
	
	  ;% can_bus_test3_P.ManualSwitch1_CurrentSetting
	  section.data(9).logicalSrcIdx = 55;
	  section.data(9).dtTransOffset = 8;
	
	  ;% can_bus_test3_P.ManualSwitch4_CurrentSetting
	  section.data(10).logicalSrcIdx = 56;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    nTotSects     = 5;
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
    ;% Auto data (can_bus_test3_B)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% can_bus_test3_B.Gain
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_B.Gain1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% can_bus_test3_B.Gain2
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% can_bus_test3_B.DataTypeConversion5
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% can_bus_test3_B.DataTypeConversion6
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% can_bus_test3_B.DataTypeConversion7
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 9;
	
	  ;% can_bus_test3_B.SFunctionBuilder_o4
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% can_bus_test3_B.Gain3
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_B.Gain4
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% can_bus_test3_B.TmpSignalConversionAtSFunctionB
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% can_bus_test3_B.TmpSignalConversionAtSFunctio_h
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 7;
	
	  ;% can_bus_test3_B.TmpSignalConversionAtSFunctio_d
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 12;
	
	  ;% can_bus_test3_B.TmpSignalConversionAtSFunctio_e
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 17;
	
	  ;% can_bus_test3_B.SFunctionBuilder_o1
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 22;
	
	  ;% can_bus_test3_B.SFunctionBuilder_o2
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 25;
	
	  ;% can_bus_test3_B.SFunctionBuilder_o3
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 28;
	
	  ;% can_bus_test3_B.SFunctionBuilder_o4_p
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 31;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% can_bus_test3_B.SFunctionBuilder_o3_e
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_B.DataTypeConversion3
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% can_bus_test3_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% can_bus_test3_B.DataTypeConversion4
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_B.SFunctionBuilder_o1_c
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 4;
	
	  ;% can_bus_test3_B.SFunctionBuilder_o2_i
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 6;
	
	  ;% can_bus_test3_B.IntegertoBitConverter
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 8;
	
	  ;% can_bus_test3_B.IntegertoBitConverter1
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 16;
	
	  ;% can_bus_test3_B.DataTypeConversion
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
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
    sectIdxOffset = 5;
    
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
    ;% Auto data (can_bus_test3_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% can_bus_test3_DW.UD_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_DW.SFunctionBuilder_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% can_bus_test3_DW.SFunctionBuilder_DSTATE_l
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 6;
	
	  ;% can_bus_test3_DW.lastSin
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 8;
	
	  ;% can_bus_test3_DW.lastCos
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 9;
	
	  ;% can_bus_test3_DW.lastSin_b
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 10;
	
	  ;% can_bus_test3_DW.lastCos_h
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% can_bus_test3_DW.Scope2_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_DW.Scope3_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% can_bus_test3_DW.Scope5_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% can_bus_test3_DW.Scope6_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% can_bus_test3_DW.Scope8_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% can_bus_test3_DW.Scope9_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% can_bus_test3_DW.Scope1_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% can_bus_test3_DW.Scope4_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 8;
	
	  ;% can_bus_test3_DW.Scope7_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 10;
	
	  ;% can_bus_test3_DW.SFunctionBuilder_PWORK
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 11;
	
	  ;% can_bus_test3_DW.SFunctionBuilder_PWORK_d
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% can_bus_test3_DW.systemEnable
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% can_bus_test3_DW.systemEnable_o
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 1;
	
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


  targMap.checksum0 = 3350778234;
  targMap.checksum1 = 1432855611;
  targMap.checksum2 = 522118496;
  targMap.checksum3 = 130281107;

