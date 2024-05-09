//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: can_bus_test3.h
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
#ifndef RTW_HEADER_can_bus_test3_h_
#define RTW_HEADER_can_bus_test3_h_
#include <cmath>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef can_bus_test3_COMMON_INCLUDES_
# define can_bus_test3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 // can_bus_test3_COMMON_INCLUDES_

#include "can_bus_test3_types.h"

// Shared type includes
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

// Block signals (default storage)
typedef struct {
  real_T Gain;                         // '<Root>/Gain'
  real_T Gain1;                        // '<Root>/Gain1'
  real_T Gain2;                        // '<Root>/Gain2'
  real_T DataTypeConversion5[3];       // '<S3>/Data Type Conversion5'
  real_T DataTypeConversion6[3];       // '<S3>/Data Type Conversion6'
  real_T DataTypeConversion7[3];       // '<S3>/Data Type Conversion7'
  real_T SFunctionBuilder_o4;          // '<S2>/S-Function Builder'
  real32_T Gain3;                      // '<Root>/Gain3'
  real32_T Gain4;                      // '<Root>/Gain4'
  real32_T TmpSignalConversionAtSFunctionB[5];
  real32_T TmpSignalConversionAtSFunctio_h[5];
  real32_T TmpSignalConversionAtSFunctio_d[5];
  real32_T TmpSignalConversionAtSFunctio_e[5];
  real32_T SFunctionBuilder_o1[3];     // '<S3>/S-Function Builder'
  real32_T SFunctionBuilder_o2[3];     // '<S3>/S-Function Builder'
  real32_T SFunctionBuilder_o3[3];     // '<S3>/S-Function Builder'
  real32_T SFunctionBuilder_o4_p[3];   // '<S3>/S-Function Builder'
  int32_T SFunctionBuilder_o3_e;       // '<S2>/S-Function Builder'
  int32_T DataTypeConversion3;         // '<S2>/Data Type Conversion3'
  int16_T DataTypeConversion1;         // '<S2>/Data Type Conversion1'
  uint8_T DataTypeConversion4[4];      // '<S3>/Data Type Conversion4'
  uint8_T SFunctionBuilder_o1_c[2];    // '<S2>/S-Function Builder'
  uint8_T SFunctionBuilder_o2_i[2];    // '<S2>/S-Function Builder'
  uint8_T IntegertoBitConverter[8];    // '<S2>/Integer to Bit Converter'
  uint8_T IntegertoBitConverter1[8];   // '<S2>/Integer to Bit Converter1'
  uint8_T DataTypeConversion;          // '<S2>/Data Type Conversion'
} B_can_bus_test3_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  real_T UD_DSTATE;                    // '<S1>/UD'
  real_T SFunctionBuilder_DSTATE[5];   // '<S3>/S-Function Builder'
  real_T SFunctionBuilder_DSTATE_l[2]; // '<S2>/S-Function Builder'
  real_T lastSin;                      // '<Root>/Sine Wave'
  real_T lastCos;                      // '<Root>/Sine Wave'
  real_T lastSin_b;                    // '<Root>/Sine Wave1'
  real_T lastCos_h;                    // '<Root>/Sine Wave1'
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      // '<Root>/Scope2'

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      // '<Root>/Scope3'

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      // '<Root>/Scope5'

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      // '<Root>/Scope6'

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      // '<Root>/Scope8'

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      // '<Root>/Scope9'

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      // '<Root>/Scope1'

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      // '<Root>/Scope4'

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      // '<Root>/Scope7'

  void *SFunctionBuilder_PWORK;        // '<S3>/S-Function Builder'
  void *SFunctionBuilder_PWORK_d;      // '<S2>/S-Function Builder'
  int32_T systemEnable;                // '<Root>/Sine Wave'
  int32_T systemEnable_o;              // '<Root>/Sine Wave1'
} DW_can_bus_test3_T;

// Parameters (default storage)
struct P_can_bus_test3_T_ {
  real_T DiscreteDerivative_ICPrevScaled;// Mask Parameter: DiscreteDerivative_ICPrevScaled
                                         //  Referenced by: '<S1>/UD'

  real_T LINMOTCAN_PAR_ACCEL;          // Mask Parameter: LINMOTCAN_PAR_ACCEL
                                       //  Referenced by: '<S2>/S-Function Builder'

  real_T LINMOTCAN_PAR_DECEL;          // Mask Parameter: LINMOTCAN_PAR_DECEL
                                       //  Referenced by: '<S2>/S-Function Builder'

  real_T LINMOTCAN_PAR_MAX_VEL;        // Mask Parameter: LINMOTCAN_PAR_MAX_VEL
                                       //  Referenced by: '<S2>/S-Function Builder'

  real_T Constant7_Value;              // Expression: 1
                                       //  Referenced by: '<Root>/Constant7'

  real_T Constant8_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant8'

  real_T Constant_Value;               // Expression: 1
                                       //  Referenced by: '<Root>/Constant'

  real_T Constant6_Value;              // Expression: 0
                                       //  Referenced by: '<Root>/Constant6'

  real_T Constant16_Value;             // Expression: 1
                                       //  Referenced by: '<Root>/Constant16'

  real_T PAR_MASK_MODE_Value;          // Expression: 0
                                       //  Referenced by: '<S2>/PAR_MASK_MODE'

  real_T Gain_Gain;                    // Expression: 10
                                       //  Referenced by: '<S2>/Gain'

  real_T Gain1_Gain;                   // Expression: 1000
                                       //  Referenced by: '<S2>/Gain1'

  real_T PAR_MASK_MODE_Value_g[4];     // Expression: [0 0 0 0]
                                       //  Referenced by: '<S3>/PAR_MASK_MODE'

  real_T Constant10_Value;             // Expression: 0
                                       //  Referenced by: '<Root>/Constant10'

  real_T Constant12_Value;             // Expression: 0
                                       //  Referenced by: '<Root>/Constant12'

  real_T SineWave_Amp;                 // Expression: 2*pi
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Bias;                // Expression: 0
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Freq;                // Expression: 3*pi
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_Hsin;                // Computed Parameter: SineWave_Hsin
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_HCos;                // Computed Parameter: SineWave_HCos
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_PSin;                // Computed Parameter: SineWave_PSin
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave_PCos;                // Computed Parameter: SineWave_PCos
                                       //  Referenced by: '<Root>/Sine Wave'

  real_T SineWave1_Amp;                // Expression: 2*pi
                                       //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_Bias;               // Expression: 0
                                       //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_Freq;               // Expression: 1*pi
                                       //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_Hsin;               // Computed Parameter: SineWave1_Hsin
                                       //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_HCos;               // Computed Parameter: SineWave1_HCos
                                       //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_PSin;               // Computed Parameter: SineWave1_PSin
                                       //  Referenced by: '<Root>/Sine Wave1'

  real_T SineWave1_PCos;               // Computed Parameter: SineWave1_PCos
                                       //  Referenced by: '<Root>/Sine Wave1'

  real_T TSamp_WtEt;                   // Computed Parameter: TSamp_WtEt
                                       //  Referenced by: '<S1>/TSamp'

  real_T Gain_Gain_d;                  // Expression: 180/pi
                                       //  Referenced by: '<Root>/Gain'

  real_T Gain1_Gain_p;                 // Expression: 180/pi
                                       //  Referenced by: '<Root>/Gain1'

  real_T Gain2_Gain;                   // Expression: 180/pi
                                       //  Referenced by: '<Root>/Gain2'

  real_T Constant17_Value;             // Expression: 20
                                       //  Referenced by: '<Root>/Constant17'

  real_T Constant18_Value;             // Expression: .2
                                       //  Referenced by: '<Root>/Constant18'

  real32_T Constant9_Value;            // Computed Parameter: Constant9_Value
                                       //  Referenced by: '<Root>/Constant9'

  real32_T Constant15_Value;           // Computed Parameter: Constant15_Value
                                       //  Referenced by: '<Root>/Constant15'

  real32_T Constant5_Value;            // Computed Parameter: Constant5_Value
                                       //  Referenced by: '<Root>/Constant5'

  real32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                       //  Referenced by: '<Root>/Constant1'

  real32_T Constant2_Value;            // Computed Parameter: Constant2_Value
                                       //  Referenced by: '<Root>/Constant2'

  real32_T Constant3_Value;            // Computed Parameter: Constant3_Value
                                       //  Referenced by: '<Root>/Constant3'

  real32_T Constant4_Value;            // Computed Parameter: Constant4_Value
                                       //  Referenced by: '<Root>/Constant4'

  real32_T Constant11_Value;           // Computed Parameter: Constant11_Value
                                       //  Referenced by: '<Root>/Constant11'

  real32_T Constant13_Value;           // Computed Parameter: Constant13_Value
                                       //  Referenced by: '<Root>/Constant13'

  real32_T Constant14_Value;           // Computed Parameter: Constant14_Value
                                       //  Referenced by: '<Root>/Constant14'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                       //  Referenced by: '<Root>/Gain3'

  real32_T Gain4_Gain;                 // Computed Parameter: Gain4_Gain
                                       //  Referenced by: '<Root>/Gain4'

  uint8_T SFunctionBuilder_P1;         // Expression: uint8(PAR_PORT_NUM)
                                       //  Referenced by: '<S2>/S-Function Builder'

  uint8_T SFunctionBuilder_P5;         // Expression: uint8(PAR_SAFE)
                                       //  Referenced by: '<S2>/S-Function Builder'

  uint8_T SFunctionBuilder_P1_k;       // Expression: uint8(PAR_DEV_NUM)
                                       //  Referenced by: '<S3>/S-Function Builder'

  uint8_T SFunctionBuilder_P2;         // Expression: uint8(PAR_PORT_NUM)
                                       //  Referenced by: '<S3>/S-Function Builder'

  uint8_T SFunctionBuilder_P3;         // Expression: uint8(PAR_SAFE)
                                       //  Referenced by: '<S3>/S-Function Builder'

  uint8_T ManualSwitch2_CurrentSetting;// Computed Parameter: ManualSwitch2_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch2'

  uint8_T ManualSwitch3_CurrentSetting;// Computed Parameter: ManualSwitch3_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch3'

  uint8_T ManualSwitch_CurrentSetting; // Computed Parameter: ManualSwitch_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch'

  uint8_T ManualSwitch1_CurrentSetting;// Computed Parameter: ManualSwitch1_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch1'

  uint8_T ManualSwitch4_CurrentSetting;// Computed Parameter: ManualSwitch4_CurrentSetting
                                       //  Referenced by: '<Root>/Manual Switch4'

};

// Real-time Model Data Structure
struct tag_RTM_can_bus_test3_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  //
  //  Sizes:
  //  The following substructure contains sizes information
  //  for many of the model attributes such as inputs, outputs,
  //  dwork, sample times, etc.

  struct {
    uint32_T checksums[4];
  } Sizes;

  //
  //  SpecialInfo:
  //  The following substructure contains special information
  //  related to other components that are dependent on RTW.

  struct {
    const void *mappingInfo;
  } SpecialInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_can_bus_test3_T can_bus_test3_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
extern B_can_bus_test3_T can_bus_test3_B;

// Block states (default storage)
extern DW_can_bus_test3_T can_bus_test3_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void can_bus_test3_initialize(void);
  extern void can_bus_test3_step(void);
  extern void can_bus_test3_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_can_bus_test3_T *const can_bus_test3_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S1>/Data Type Duplicate' : Unused code path elimination
//  Block '<S2>/Data Type Conversion2' : Unused code path elimination
//  Block '<S2>/Gain2' : Unused code path elimination
//  Block '<S3>/Data Type Conversion8' : Unused code path elimination
//  Block '<S3>/Data Type Conversion' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion1' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
//  Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'can_bus_test3'
//  '<S1>'   : 'can_bus_test3/Discrete Derivative'
//  '<S2>'   : 'can_bus_test3/LINMOT CAN'
//  '<S3>'   : 'can_bus_test3/MINI CHEETAH CAN'
//  '<S4>'   : 'can_bus_test3/VESC USB'

#endif                                 // RTW_HEADER_can_bus_test3_h_

//
// File trailer for generated code.
//
// [EOF]
//
