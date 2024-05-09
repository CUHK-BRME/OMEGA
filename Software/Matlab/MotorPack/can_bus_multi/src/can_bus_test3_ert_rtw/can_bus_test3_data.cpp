//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: can_bus_test3_data.cpp
//
// Code generated for Simulink model 'can_bus_test3'.
//
// Model version                  : 1.3643
// Simulink Coder version         : 9.0 (R2018b) 24-May-2018
// C/C++ source code generated on : Mon Apr 19 17:28:36 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "can_bus_test3.h"
#include "can_bus_test3_private.h"

// Block parameters (default storage)
P_can_bus_test3_T can_bus_test3_P = {
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S1>/UD'

  0.0,

  // Mask Parameter: LINMOTCAN_PAR_ACCEL
  //  Referenced by: '<S2>/S-Function Builder'

  10.0,

  // Mask Parameter: LINMOTCAN_PAR_DECEL
  //  Referenced by: '<S2>/S-Function Builder'

  10.0,

  // Mask Parameter: LINMOTCAN_PAR_MAX_VEL
  //  Referenced by: '<S2>/S-Function Builder'

  1.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant7'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant8'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant'

  1.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant6'

  0.0,

  // Expression: 1
  //  Referenced by: '<Root>/Constant16'

  1.0,

  // Expression: 0
  //  Referenced by: '<S2>/PAR_MASK_MODE'

  0.0,

  // Expression: 10
  //  Referenced by: '<S2>/Gain'

  10.0,

  // Expression: 1000
  //  Referenced by: '<S2>/Gain1'

  1000.0,

  // Expression: [0 0 0 0]
  //  Referenced by: '<S3>/PAR_MASK_MODE'

  { 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<Root>/Constant10'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Constant12'

  0.0,

  // Expression: 2*pi
  //  Referenced by: '<Root>/Sine Wave'

  6.2831853071795862,

  // Expression: 0
  //  Referenced by: '<Root>/Sine Wave'

  0.0,

  // Expression: 3*pi
  //  Referenced by: '<Root>/Sine Wave'

  9.42477796076938,

  // Computed Parameter: SineWave_Hsin
  //  Referenced by: '<Root>/Sine Wave'

  0.0094246384331440058,

  // Computed Parameter: SineWave_HCos
  //  Referenced by: '<Root>/Sine Wave'

  0.99995558710894983,

  // Computed Parameter: SineWave_PSin
  //  Referenced by: '<Root>/Sine Wave'

  -0.0094246384331440058,

  // Computed Parameter: SineWave_PCos
  //  Referenced by: '<Root>/Sine Wave'

  0.99995558710894983,

  // Expression: 2*pi
  //  Referenced by: '<Root>/Sine Wave1'

  6.2831853071795862,

  // Expression: 0
  //  Referenced by: '<Root>/Sine Wave1'

  0.0,

  // Expression: 1*pi
  //  Referenced by: '<Root>/Sine Wave1'

  3.1415926535897931,

  // Computed Parameter: SineWave1_Hsin
  //  Referenced by: '<Root>/Sine Wave1'

  0.0031415874858795635,

  // Computed Parameter: SineWave1_HCos
  //  Referenced by: '<Root>/Sine Wave1'

  0.99999506520185821,

  // Computed Parameter: SineWave1_PSin
  //  Referenced by: '<Root>/Sine Wave1'

  -0.0031415874858795635,

  // Computed Parameter: SineWave1_PCos
  //  Referenced by: '<Root>/Sine Wave1'

  0.99999506520185821,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S1>/TSamp'

  1000.0,

  // Expression: 180/pi
  //  Referenced by: '<Root>/Gain'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<Root>/Gain1'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<Root>/Gain2'

  57.295779513082323,

  // Expression: 20
  //  Referenced by: '<Root>/Constant17'

  20.0,

  // Expression: .2
  //  Referenced by: '<Root>/Constant18'

  0.2,

  // Computed Parameter: Constant9_Value
  //  Referenced by: '<Root>/Constant9'

  0.0F,

  // Computed Parameter: Constant15_Value
  //  Referenced by: '<Root>/Constant15'

  0.0F,

  // Computed Parameter: Constant5_Value
  //  Referenced by: '<Root>/Constant5'

  0.0F,

  // Computed Parameter: Constant1_Value
  //  Referenced by: '<Root>/Constant1'

  0.0F,

  // Computed Parameter: Constant2_Value
  //  Referenced by: '<Root>/Constant2'

  0.0F,

  // Computed Parameter: Constant3_Value
  //  Referenced by: '<Root>/Constant3'

  0.0F,

  // Computed Parameter: Constant4_Value
  //  Referenced by: '<Root>/Constant4'

  0.5F,

  // Computed Parameter: Constant11_Value
  //  Referenced by: '<Root>/Constant11'

  20.0F,

  // Computed Parameter: Constant13_Value
  //  Referenced by: '<Root>/Constant13'

  2.0F,

  // Computed Parameter: Constant14_Value
  //  Referenced by: '<Root>/Constant14'

  0.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<Root>/Gain3'

  57.2957802F,

  // Computed Parameter: Gain4_Gain
  //  Referenced by: '<Root>/Gain4'

  57.2957802F,

  // Expression: uint8(PAR_PORT_NUM)
  //  Referenced by: '<S2>/S-Function Builder'

  2U,

  // Expression: uint8(PAR_SAFE)
  //  Referenced by: '<S2>/S-Function Builder'

  0U,

  // Expression: uint8(PAR_DEV_NUM)
  //  Referenced by: '<S3>/S-Function Builder'

  1U,

  // Expression: uint8(PAR_PORT_NUM)
  //  Referenced by: '<S3>/S-Function Builder'

  1U,

  // Expression: uint8(PAR_SAFE)
  //  Referenced by: '<S3>/S-Function Builder'

  1U,

  // Computed Parameter: ManualSwitch2_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch2'

  1U,

  // Computed Parameter: ManualSwitch3_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch3'

  1U,

  // Computed Parameter: ManualSwitch_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch'

  0U,

  // Computed Parameter: ManualSwitch1_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch1'

  1U,

  // Computed Parameter: ManualSwitch4_CurrentSetting
  //  Referenced by: '<Root>/Manual Switch4'

  0U
};

//
// File trailer for generated code.
//
// [EOF]
//
