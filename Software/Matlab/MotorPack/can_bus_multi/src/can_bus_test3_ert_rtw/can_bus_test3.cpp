//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: can_bus_test3.cpp
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
#include "can_bus_test3_dt.h"

// Block signals (default storage)
B_can_bus_test3_T can_bus_test3_B;

// Block states (default storage)
DW_can_bus_test3_T can_bus_test3_DW;

// Real-time model
RT_MODEL_can_bus_test3_T can_bus_test3_M_;
RT_MODEL_can_bus_test3_T *const can_bus_test3_M = &can_bus_test3_M_;

// Model step function
void can_bus_test3_step(void)
{
  int32_T j;
  int32_T u;
  int32_T bitIdx;
  int32_T u_0;
  real_T rtb_SineWave1;
  real32_T rtb_DataTypeConversion;
  real_T rtb_Gain1;
  int32_T i;
  real_T tmp;

  // Sin: '<Root>/Sine Wave'
  if (can_bus_test3_DW.systemEnable != 0) {
    rtb_SineWave1 = can_bus_test3_P.SineWave_Freq *
      can_bus_test3_M->Timing.taskTime0;
    can_bus_test3_DW.lastSin = std::sin(rtb_SineWave1);
    can_bus_test3_DW.lastCos = std::cos(rtb_SineWave1);
    can_bus_test3_DW.systemEnable = 0;
  }

  // ManualSwitch: '<Root>/Manual Switch'
  if (can_bus_test3_P.ManualSwitch_CurrentSetting == 1) {
    // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
    //   Sin: '<Root>/Sine Wave'

    rtb_DataTypeConversion = (real32_T)(((can_bus_test3_DW.lastSin *
      can_bus_test3_P.SineWave_PCos + can_bus_test3_DW.lastCos *
      can_bus_test3_P.SineWave_PSin) * can_bus_test3_P.SineWave_HCos +
      (can_bus_test3_DW.lastCos * can_bus_test3_P.SineWave_PCos -
       can_bus_test3_DW.lastSin * can_bus_test3_P.SineWave_PSin) *
      can_bus_test3_P.SineWave_Hsin) * can_bus_test3_P.SineWave_Amp +
      can_bus_test3_P.SineWave_Bias);
  } else {
    // DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
    //   Constant: '<Root>/Constant5'

    rtb_DataTypeConversion = can_bus_test3_P.Constant5_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch'

  // Sin: '<Root>/Sine Wave1'
  if (can_bus_test3_DW.systemEnable_o != 0) {
    rtb_SineWave1 = can_bus_test3_P.SineWave1_Freq *
      can_bus_test3_M->Timing.taskTime0;
    can_bus_test3_DW.lastSin_b = std::sin(rtb_SineWave1);
    can_bus_test3_DW.lastCos_h = std::cos(rtb_SineWave1);
    can_bus_test3_DW.systemEnable_o = 0;
  }

  rtb_SineWave1 = ((can_bus_test3_DW.lastSin_b * can_bus_test3_P.SineWave1_PCos
                    + can_bus_test3_DW.lastCos_h *
                    can_bus_test3_P.SineWave1_PSin) *
                   can_bus_test3_P.SineWave1_HCos + (can_bus_test3_DW.lastCos_h *
    can_bus_test3_P.SineWave1_PCos - can_bus_test3_DW.lastSin_b *
    can_bus_test3_P.SineWave1_PSin) * can_bus_test3_P.SineWave1_Hsin) *
    can_bus_test3_P.SineWave1_Amp + can_bus_test3_P.SineWave1_Bias;

  // End of Sin: '<Root>/Sine Wave1'

  // ManualSwitch: '<Root>/Manual Switch1' incorporates:
  //   Constant: '<Root>/Constant15'

  if (can_bus_test3_P.ManualSwitch1_CurrentSetting == 1) {
    rtb_Gain1 = rtb_SineWave1;
  } else {
    rtb_Gain1 = can_bus_test3_P.Constant15_Value;
  }

  // End of ManualSwitch: '<Root>/Manual Switch1'

  // SampleTimeMath: '<S1>/TSamp'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_SineWave1 *= can_bus_test3_P.TSamp_WtEt;

  // Outputs for Atomic SubSystem: '<Root>/MINI CHEETAH CAN'
  // SignalConversion: '<S3>/TmpSignal ConversionAtS-Function BuilderInport2' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Constant: '<Root>/Constant2'
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant4'

  can_bus_test3_B.TmpSignalConversionAtSFunctionB[0] = rtb_DataTypeConversion;
  can_bus_test3_B.TmpSignalConversionAtSFunctionB[1] =
    can_bus_test3_P.Constant1_Value;
  can_bus_test3_B.TmpSignalConversionAtSFunctionB[2] =
    can_bus_test3_P.Constant2_Value;
  can_bus_test3_B.TmpSignalConversionAtSFunctionB[3] =
    can_bus_test3_P.Constant3_Value;
  can_bus_test3_B.TmpSignalConversionAtSFunctionB[4] =
    can_bus_test3_P.Constant4_Value;

  // SignalConversion: '<S3>/TmpSignal ConversionAtS-Function BuilderInport3' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  can_bus_test3_B.TmpSignalConversionAtSFunctio_h[0] = (real32_T)rtb_Gain1;

  // End of Outputs for SubSystem: '<Root>/MINI CHEETAH CAN'

  // ManualSwitch: '<Root>/Manual Switch4'
  if (can_bus_test3_P.ManualSwitch4_CurrentSetting == 1) {
    // Outputs for Atomic SubSystem: '<Root>/MINI CHEETAH CAN'
    // SignalConversion: '<S3>/TmpSignal ConversionAtS-Function BuilderInport3' incorporates:
    //   Sum: '<S1>/Diff'
    //   UnitDelay: '<S1>/UD'
    //
    //  Block description for '<S1>/Diff':
    //
    //   Add in CPU
    //
    //  Block description for '<S1>/UD':
    //
    //   Store in Global RAM

    can_bus_test3_B.TmpSignalConversionAtSFunctio_h[1] = (real32_T)
      (rtb_SineWave1 - can_bus_test3_DW.UD_DSTATE);

    // End of Outputs for SubSystem: '<Root>/MINI CHEETAH CAN'
  } else {
    // Outputs for Atomic SubSystem: '<Root>/MINI CHEETAH CAN'
    // SignalConversion: '<S3>/TmpSignal ConversionAtS-Function BuilderInport3' incorporates:
    //   Constant: '<Root>/Constant9'

    can_bus_test3_B.TmpSignalConversionAtSFunctio_h[1] =
      can_bus_test3_P.Constant9_Value;

    // End of Outputs for SubSystem: '<Root>/MINI CHEETAH CAN'
  }

  // End of ManualSwitch: '<Root>/Manual Switch4'

  // Outputs for Atomic SubSystem: '<Root>/MINI CHEETAH CAN'
  // SignalConversion: '<S3>/TmpSignal ConversionAtS-Function BuilderInport3' incorporates:
  //   Constant: '<Root>/Constant11'
  //   Constant: '<Root>/Constant13'
  //   Constant: '<Root>/Constant14'

  can_bus_test3_B.TmpSignalConversionAtSFunctio_h[2] =
    can_bus_test3_P.Constant11_Value;
  can_bus_test3_B.TmpSignalConversionAtSFunctio_h[3] =
    can_bus_test3_P.Constant13_Value;
  can_bus_test3_B.TmpSignalConversionAtSFunctio_h[4] =
    can_bus_test3_P.Constant14_Value;
  for (i = 0; i < 5; i++) {
    // SignalConversion: '<S3>/TmpSignal ConversionAtS-Function BuilderInport4'
    can_bus_test3_B.TmpSignalConversionAtSFunctio_d[i] = 0.0F;

    // SignalConversion: '<S3>/TmpSignal ConversionAtS-Function BuilderInport5'
    can_bus_test3_B.TmpSignalConversionAtSFunctio_e[i] = 0.0F;
  }

  // Switch: '<S3>/Switch' incorporates:
  //   Constant: '<S3>/PAR_MASK_MODE'
  //   ManualSwitch: '<Root>/Manual Switch2'
  //   ManualSwitch: '<Root>/Manual Switch3'

  if (can_bus_test3_P.PAR_MASK_MODE_Value_g[0] != 0.0) {
    // DataTypeConversion: '<S3>/Data Type Conversion4'
    tmp = std::floor(can_bus_test3_P.PAR_MASK_MODE_Value_g[0]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[0] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  } else if (can_bus_test3_P.ManualSwitch2_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch2' incorporates:
    //   Constant: '<Root>/Constant6'
    //   DataTypeConversion: '<S3>/Data Type Conversion4'

    tmp = std::floor(can_bus_test3_P.Constant6_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[0] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  } else {
    // DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
    //   Constant: '<Root>/Constant'

    tmp = std::floor(can_bus_test3_P.Constant_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[0] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  }

  if (can_bus_test3_P.PAR_MASK_MODE_Value_g[1] != 0.0) {
    // DataTypeConversion: '<S3>/Data Type Conversion4'
    tmp = std::floor(can_bus_test3_P.PAR_MASK_MODE_Value_g[1]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[1] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  } else if (can_bus_test3_P.ManualSwitch3_CurrentSetting == 1) {
    // ManualSwitch: '<Root>/Manual Switch3' incorporates:
    //   Constant: '<Root>/Constant8'
    //   DataTypeConversion: '<S3>/Data Type Conversion4'

    tmp = std::floor(can_bus_test3_P.Constant8_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[1] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  } else {
    // DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
    //   Constant: '<Root>/Constant7'

    tmp = std::floor(can_bus_test3_P.Constant7_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[1] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  }

  if (can_bus_test3_P.PAR_MASK_MODE_Value_g[2] != 0.0) {
    // DataTypeConversion: '<S3>/Data Type Conversion4'
    tmp = std::floor(can_bus_test3_P.PAR_MASK_MODE_Value_g[2]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[2] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  } else {
    // DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
    //   Constant: '<Root>/Constant10'

    tmp = std::floor(can_bus_test3_P.Constant10_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[2] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  }

  if (can_bus_test3_P.PAR_MASK_MODE_Value_g[3] != 0.0) {
    // DataTypeConversion: '<S3>/Data Type Conversion4'
    tmp = std::floor(can_bus_test3_P.PAR_MASK_MODE_Value_g[3]);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[3] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  } else {
    // DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
    //   Constant: '<Root>/Constant12'

    tmp = std::floor(can_bus_test3_P.Constant12_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion4[3] = (uint8_T)(tmp < 0.0 ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  }

  // End of Switch: '<S3>/Switch'

  // S-Function (CAN_BUS_MULTISTATE_SF): '<S3>/S-Function Builder'
  CAN_BUS_MULTISTATE_SF_Outputs_wrapper(&can_bus_test3_B.SFunctionBuilder_o1[0],
    &can_bus_test3_B.SFunctionBuilder_o2[0],
    &can_bus_test3_B.SFunctionBuilder_o3[0],
    &can_bus_test3_B.SFunctionBuilder_o4_p[0],
    &can_bus_test3_DW.SFunctionBuilder_DSTATE[0],
    &can_bus_test3_DW.SFunctionBuilder_PWORK,
    &can_bus_test3_P.SFunctionBuilder_P1_k, 1,
    &can_bus_test3_P.SFunctionBuilder_P2, 1,
    &can_bus_test3_P.SFunctionBuilder_P3, 1);

  // DataTypeConversion: '<S3>/Data Type Conversion5'
  can_bus_test3_B.DataTypeConversion5[0] = can_bus_test3_B.SFunctionBuilder_o1[0];

  // DataTypeConversion: '<S3>/Data Type Conversion6'
  can_bus_test3_B.DataTypeConversion6[0] = can_bus_test3_B.SFunctionBuilder_o2[0];

  // DataTypeConversion: '<S3>/Data Type Conversion7'
  can_bus_test3_B.DataTypeConversion7[0] = can_bus_test3_B.SFunctionBuilder_o3[0];

  // DataTypeConversion: '<S3>/Data Type Conversion5'
  can_bus_test3_B.DataTypeConversion5[1] = can_bus_test3_B.SFunctionBuilder_o1[1];

  // DataTypeConversion: '<S3>/Data Type Conversion6'
  can_bus_test3_B.DataTypeConversion6[1] = can_bus_test3_B.SFunctionBuilder_o2[1];

  // DataTypeConversion: '<S3>/Data Type Conversion7'
  can_bus_test3_B.DataTypeConversion7[1] = can_bus_test3_B.SFunctionBuilder_o3[1];

  // DataTypeConversion: '<S3>/Data Type Conversion5'
  can_bus_test3_B.DataTypeConversion5[2] = can_bus_test3_B.SFunctionBuilder_o1[2];

  // DataTypeConversion: '<S3>/Data Type Conversion6'
  can_bus_test3_B.DataTypeConversion6[2] = can_bus_test3_B.SFunctionBuilder_o2[2];

  // DataTypeConversion: '<S3>/Data Type Conversion7'
  can_bus_test3_B.DataTypeConversion7[2] = can_bus_test3_B.SFunctionBuilder_o3[2];

  // Update for S-Function (CAN_BUS_MULTISTATE_SF): '<S3>/S-Function Builder'

  // S-Function "CAN_BUS_MULTISTATE_SF_wrapper" Block: <S3>/S-Function Builder
  CAN_BUS_MULTISTATE_SF_Update_wrapper(&can_bus_test3_B.DataTypeConversion4[0],
    &can_bus_test3_B.TmpSignalConversionAtSFunctionB[0],
    &can_bus_test3_B.TmpSignalConversionAtSFunctio_h[0],
    &can_bus_test3_B.TmpSignalConversionAtSFunctio_d[0],
    &can_bus_test3_B.TmpSignalConversionAtSFunctio_e[0],
    &can_bus_test3_B.SFunctionBuilder_o1[0],
    &can_bus_test3_B.SFunctionBuilder_o2[0],
    &can_bus_test3_B.SFunctionBuilder_o3[0],
    &can_bus_test3_B.SFunctionBuilder_o4_p[0],
    &can_bus_test3_DW.SFunctionBuilder_DSTATE[0],
    &can_bus_test3_DW.SFunctionBuilder_PWORK,
    &can_bus_test3_P.SFunctionBuilder_P1_k, 1,
    &can_bus_test3_P.SFunctionBuilder_P2, 1,
    &can_bus_test3_P.SFunctionBuilder_P3, 1);

  // End of Outputs for SubSystem: '<Root>/MINI CHEETAH CAN'
  // Gain: '<Root>/Gain'
  can_bus_test3_B.Gain = can_bus_test3_P.Gain_Gain_d *
    can_bus_test3_B.DataTypeConversion5[0];

  // Gain: '<Root>/Gain3'
  can_bus_test3_B.Gain3 = can_bus_test3_P.Gain3_Gain * rtb_DataTypeConversion;

  // Gain: '<Root>/Gain1'
  can_bus_test3_B.Gain1 = can_bus_test3_P.Gain1_Gain_p *
    can_bus_test3_B.DataTypeConversion6[0];

  // Gain: '<Root>/Gain4' incorporates:
  //   DataTypeConversion: '<Root>/Data Type Conversion1'

  can_bus_test3_B.Gain4 = can_bus_test3_P.Gain4_Gain * (real32_T)rtb_Gain1;

  // Gain: '<Root>/Gain2'
  can_bus_test3_B.Gain2 = can_bus_test3_P.Gain2_Gain *
    can_bus_test3_B.DataTypeConversion7[0];

  // Outputs for Atomic SubSystem: '<Root>/LINMOT CAN'
  // S-Function (LINMOT_CAN_TEST): '<S2>/S-Function Builder'
  LINMOT_CAN_TEST_Outputs_wrapper(&can_bus_test3_B.SFunctionBuilder_o1_c[0],
    &can_bus_test3_B.SFunctionBuilder_o2_i[0],
    &can_bus_test3_B.SFunctionBuilder_o3_e, &can_bus_test3_B.SFunctionBuilder_o4,
    &can_bus_test3_DW.SFunctionBuilder_DSTATE_l[0],
    &can_bus_test3_DW.SFunctionBuilder_PWORK_d,
    &can_bus_test3_P.SFunctionBuilder_P1, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_MAX_VEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_ACCEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_DECEL, 1,
    &can_bus_test3_P.SFunctionBuilder_P5, 1);

  // S-Function (scominttobit): '<S2>/Integer to Bit Converter'
  // Integer to Bit Conversion
  i = 0;
  u = can_bus_test3_B.SFunctionBuilder_o1_c[0];

  // S-Function (scominttobit): '<S2>/Integer to Bit Converter1'
  // Integer to Bit Conversion
  bitIdx = 0;
  u_0 = can_bus_test3_B.SFunctionBuilder_o1_c[1];
  for (j = 0; j < 8; j++) {
    // S-Function (scominttobit): '<S2>/Integer to Bit Converter'
    can_bus_test3_B.IntegertoBitConverter[i] = (uint8_T)(u & 1U);
    u = (int32_T)((uint32_T)u >> 1);
    i++;

    // S-Function (scominttobit): '<S2>/Integer to Bit Converter1'
    can_bus_test3_B.IntegertoBitConverter1[bitIdx] = (uint8_T)(u_0 & 1U);
    u_0 = (int32_T)((uint32_T)u_0 >> 1);
    bitIdx++;
  }

  // Switch: '<S2>/Switch' incorporates:
  //   Constant: '<S2>/PAR_MASK_MODE'

  if (can_bus_test3_P.PAR_MASK_MODE_Value != 0.0) {
    // DataTypeConversion: '<S2>/Data Type Conversion'
    tmp = std::floor(can_bus_test3_P.PAR_MASK_MODE_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  } else {
    // DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
    //   Constant: '<Root>/Constant16'

    tmp = std::floor(can_bus_test3_P.Constant16_Value);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = std::fmod(tmp, 256.0);
    }

    can_bus_test3_B.DataTypeConversion = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
      -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  }

  // End of Switch: '<S2>/Switch'

  // DataTypeConversion: '<S2>/Data Type Conversion1' incorporates:
  //   Constant: '<Root>/Constant17'
  //   Gain: '<S2>/Gain'

  tmp = std::floor(can_bus_test3_P.Gain_Gain * can_bus_test3_P.Constant17_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = std::fmod(tmp, 65536.0);
  }

  can_bus_test3_B.DataTypeConversion1 = (int16_T)(tmp < 0.0 ? (int32_T)(int16_T)
    -(int16_T)(uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);

  // End of DataTypeConversion: '<S2>/Data Type Conversion1'

  // DataTypeConversion: '<S2>/Data Type Conversion3' incorporates:
  //   Constant: '<Root>/Constant18'
  //   Gain: '<S2>/Gain1'

  tmp = std::floor(can_bus_test3_P.Gain1_Gain * can_bus_test3_P.Constant18_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = std::fmod(tmp, 4.294967296E+9);
  }

  can_bus_test3_B.DataTypeConversion3 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  // End of DataTypeConversion: '<S2>/Data Type Conversion3'

  // Update for Atomic SubSystem: '<Root>/LINMOT CAN'
  // Update for S-Function (LINMOT_CAN_TEST): '<S2>/S-Function Builder'

  // S-Function "LINMOT_CAN_TEST_wrapper" Block: <S2>/S-Function Builder
  LINMOT_CAN_TEST_Update_wrapper(&can_bus_test3_B.DataTypeConversion,
    &can_bus_test3_B.DataTypeConversion1, &can_bus_test3_B.DataTypeConversion3,
    &can_bus_test3_B.SFunctionBuilder_o1_c[0],
    &can_bus_test3_B.SFunctionBuilder_o2_i[0],
    &can_bus_test3_B.SFunctionBuilder_o3_e, &can_bus_test3_B.SFunctionBuilder_o4,
    &can_bus_test3_DW.SFunctionBuilder_DSTATE_l[0],
    &can_bus_test3_DW.SFunctionBuilder_PWORK_d,
    &can_bus_test3_P.SFunctionBuilder_P1, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_MAX_VEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_ACCEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_DECEL, 1,
    &can_bus_test3_P.SFunctionBuilder_P5, 1);

  // End of Update for SubSystem: '<Root>/LINMOT CAN'
  // End of Outputs for SubSystem: '<Root>/LINMOT CAN'

  // Update for Sin: '<Root>/Sine Wave'
  rtb_Gain1 = can_bus_test3_DW.lastSin;
  can_bus_test3_DW.lastSin = can_bus_test3_DW.lastSin *
    can_bus_test3_P.SineWave_HCos + can_bus_test3_DW.lastCos *
    can_bus_test3_P.SineWave_Hsin;
  can_bus_test3_DW.lastCos = can_bus_test3_DW.lastCos *
    can_bus_test3_P.SineWave_HCos - rtb_Gain1 * can_bus_test3_P.SineWave_Hsin;

  // Update for Sin: '<Root>/Sine Wave1'
  rtb_Gain1 = can_bus_test3_DW.lastSin_b;
  can_bus_test3_DW.lastSin_b = can_bus_test3_DW.lastSin_b *
    can_bus_test3_P.SineWave1_HCos + can_bus_test3_DW.lastCos_h *
    can_bus_test3_P.SineWave1_Hsin;
  can_bus_test3_DW.lastCos_h = can_bus_test3_DW.lastCos_h *
    can_bus_test3_P.SineWave1_HCos - rtb_Gain1 * can_bus_test3_P.SineWave1_Hsin;

  // Update for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  can_bus_test3_DW.UD_DSTATE = rtb_SineWave1;

  // External mode
  rtExtModeUploadCheckTrigger(1);

  {                                    // Sample time: [0.001s, 0.0s]
    rtExtModeUpload(0, (real_T)can_bus_test3_M->Timing.taskTime0);
  }

  // signal main to stop simulation
  {                                    // Sample time: [0.001s, 0.0s]
    if ((rtmGetTFinal(can_bus_test3_M)!=-1) &&
        !((rtmGetTFinal(can_bus_test3_M)-can_bus_test3_M->Timing.taskTime0) >
          can_bus_test3_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(can_bus_test3_M, "Simulation finished");
    }

    if (rtmGetStopRequested(can_bus_test3_M)) {
      rtmSetErrorStatus(can_bus_test3_M, "Simulation finished");
    }
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  can_bus_test3_M->Timing.taskTime0 =
    (++can_bus_test3_M->Timing.clockTick0) * can_bus_test3_M->Timing.stepSize0;
}

// Model initialize function
void can_bus_test3_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // initialize real-time model
  (void) memset((void *)can_bus_test3_M, 0,
                sizeof(RT_MODEL_can_bus_test3_T));
  rtmSetTFinal(can_bus_test3_M, -1);
  can_bus_test3_M->Timing.stepSize0 = 0.001;

  // External mode info
  can_bus_test3_M->Sizes.checksums[0] = (3350778234U);
  can_bus_test3_M->Sizes.checksums[1] = (1432855611U);
  can_bus_test3_M->Sizes.checksums[2] = (522118496U);
  can_bus_test3_M->Sizes.checksums[3] = (130281107U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[12];
    can_bus_test3_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(can_bus_test3_M->extModeInfo,
      &can_bus_test3_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(can_bus_test3_M->extModeInfo,
                        can_bus_test3_M->Sizes.checksums);
    rteiSetTPtr(can_bus_test3_M->extModeInfo, rtmGetTPtr(can_bus_test3_M));
  }

  // block I/O
  (void) memset(((void *) &can_bus_test3_B), 0,
                sizeof(B_can_bus_test3_T));

  // states (dwork)
  (void) memset((void *)&can_bus_test3_DW, 0,
                sizeof(DW_can_bus_test3_T));

  // data type transition information
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    can_bus_test3_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 30;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    // Block I/O transition table
    dtInfo.BTransTable = &rtBTransTable;

    // Parameters transition table
    dtInfo.PTransTable = &rtPTransTable;
  }

  // Start for Atomic SubSystem: '<Root>/MINI CHEETAH CAN'
  // Start for S-Function (CAN_BUS_MULTISTATE_SF): '<S3>/S-Function Builder'

  // S-Function Block: <S3>/S-Function Builder
  CAN_BUS_MULTISTATE_SF_Start_wrapper(&can_bus_test3_DW.SFunctionBuilder_DSTATE
    [0], &can_bus_test3_DW.SFunctionBuilder_PWORK,
    &can_bus_test3_P.SFunctionBuilder_P1_k, 1,
    &can_bus_test3_P.SFunctionBuilder_P2, 1,
    &can_bus_test3_P.SFunctionBuilder_P3, 1);

  // End of Start for SubSystem: '<Root>/MINI CHEETAH CAN'
  // Start for Atomic SubSystem: '<Root>/LINMOT CAN'
  // Start for S-Function (LINMOT_CAN_TEST): '<S2>/S-Function Builder'

  // S-Function Block: <S2>/S-Function Builder
  LINMOT_CAN_TEST_Start_wrapper(&can_bus_test3_DW.SFunctionBuilder_DSTATE_l[0],
    &can_bus_test3_DW.SFunctionBuilder_PWORK_d,
    &can_bus_test3_P.SFunctionBuilder_P1, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_MAX_VEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_ACCEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_DECEL, 1,
    &can_bus_test3_P.SFunctionBuilder_P5, 1);

  // End of Start for SubSystem: '<Root>/LINMOT CAN'

  // InitializeConditions for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  can_bus_test3_DW.UD_DSTATE = can_bus_test3_P.DiscreteDerivative_ICPrevScaled;

  // SystemInitialize for Atomic SubSystem: '<Root>/MINI CHEETAH CAN'
  // InitializeConditions for S-Function (CAN_BUS_MULTISTATE_SF): '<S3>/S-Function Builder' 

  // S-Function Block: <S3>/S-Function Builder
  {
    real_T initVector[5] = { 0, 0, 0, 0, 0 };

    {
      int_T i1;
      real_T *dw_DSTATE = &can_bus_test3_DW.SFunctionBuilder_DSTATE[0];
      for (i1=0; i1 < 5; i1++) {
        dw_DSTATE[i1] = initVector[i1];
      }
    }
  }

  // End of SystemInitialize for SubSystem: '<Root>/MINI CHEETAH CAN'

  // SystemInitialize for Atomic SubSystem: '<Root>/LINMOT CAN'
  // InitializeConditions for Atomic SubSystem: '<Root>/LINMOT CAN'
  // InitializeConditions for S-Function (LINMOT_CAN_TEST): '<S2>/S-Function Builder' 

  // S-Function Block: <S2>/S-Function Builder
  {
    real_T initVector[2] = { 0, 0 };

    {
      int_T i1;
      real_T *dw_DSTATE = &can_bus_test3_DW.SFunctionBuilder_DSTATE_l[0];
      for (i1=0; i1 < 2; i1++) {
        dw_DSTATE[i1] = initVector[i1];
      }
    }
  }

  // End of InitializeConditions for SubSystem: '<Root>/LINMOT CAN'
  // End of SystemInitialize for SubSystem: '<Root>/LINMOT CAN'

  // Enable for Sin: '<Root>/Sine Wave'
  can_bus_test3_DW.systemEnable = 1;

  // Enable for Sin: '<Root>/Sine Wave1'
  can_bus_test3_DW.systemEnable_o = 1;
}

// Model terminate function
void can_bus_test3_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/MINI CHEETAH CAN'

  // Terminate for S-Function (CAN_BUS_MULTISTATE_SF): '<S3>/S-Function Builder' 

  // S-Function Block: <S3>/S-Function Builder
  CAN_BUS_MULTISTATE_SF_Terminate_wrapper
    (&can_bus_test3_DW.SFunctionBuilder_DSTATE[0],
     &can_bus_test3_DW.SFunctionBuilder_PWORK,
     &can_bus_test3_P.SFunctionBuilder_P1_k, 1,
     &can_bus_test3_P.SFunctionBuilder_P2, 1,
     &can_bus_test3_P.SFunctionBuilder_P3, 1);

  // End of Terminate for SubSystem: '<Root>/MINI CHEETAH CAN'

  // Terminate for Atomic SubSystem: '<Root>/LINMOT CAN'

  // Terminate for S-Function (LINMOT_CAN_TEST): '<S2>/S-Function Builder'

  // S-Function Block: <S2>/S-Function Builder
  LINMOT_CAN_TEST_Terminate_wrapper(&can_bus_test3_DW.SFunctionBuilder_DSTATE_l
    [0], &can_bus_test3_DW.SFunctionBuilder_PWORK_d,
    &can_bus_test3_P.SFunctionBuilder_P1, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_MAX_VEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_ACCEL, 1,
    &can_bus_test3_P.LINMOTCAN_PAR_DECEL, 1,
    &can_bus_test3_P.SFunctionBuilder_P5, 1);

  // End of Terminate for SubSystem: '<Root>/LINMOT CAN'
}

//
// File trailer for generated code.
//
// [EOF]
//
