//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: can_bus_test3_private.h
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
#ifndef RTW_HEADER_can_bus_test3_private_h_
#define RTW_HEADER_can_bus_test3_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern void LINMOT_CAN_TEST_Start_wrapper(real_T *xD,
  void **pW,
  const uint8_T *can_port, const int_T p_width0,
  const real_T *max_vel, const int_T p_width1,
  const real_T *accel, const int_T p_width2,
  const real_T *decel, const int_T p_width3,
  const uint8_T *safe_mode, const int_T p_width4);
extern void LINMOT_CAN_TEST_Outputs_wrapper(uint8_T *status_word,
  uint8_T *state_var,
  int32_T *position,
  real_T *err_no,
  const real_T *xD,
  void **pW,
  const uint8_T *can_port, const int_T p_width0,
  const real_T *max_vel, const int_T p_width1,
  const real_T *accel, const int_T p_width2,
  const real_T *decel, const int_T p_width3,
  const uint8_T *safe_mode, const int_T p_width4);
extern void LINMOT_CAN_TEST_Update_wrapper(const uint8_T *mode,
  const int16_T *pos_cmd,
  const int32_T *current_cmd,
  uint8_T *status_word,
  uint8_T *state_var,
  int32_T *position,
  real_T *err_no,
  real_T *xD,
  void **pW,
  const uint8_T *can_port, const int_T p_width0,
  const real_T *max_vel, const int_T p_width1,
  const real_T *accel, const int_T p_width2,
  const real_T *decel, const int_T p_width3,
  const uint8_T *safe_mode, const int_T p_width4);
extern void LINMOT_CAN_TEST_Terminate_wrapper(real_T *xD,
  void **pW,
  const uint8_T *can_port, const int_T p_width0,
  const real_T *max_vel, const int_T p_width1,
  const real_T *accel, const int_T p_width2,
  const real_T *decel, const int_T p_width3,
  const uint8_T *safe_mode, const int_T p_width4);
extern void CAN_BUS_MULTISTATE_SF_Start_wrapper(real_T *xD,
  void **pW,
  const uint8_T *device_num, const int_T p_width0,
  const uint8_T *can_port, const int_T p_width1,
  const uint8_T *safe_mode, const int_T p_width2);
extern void CAN_BUS_MULTISTATE_SF_Outputs_wrapper(real32_T *m1_out,
  real32_T *m2_out,
  real32_T *m3_out,
  real32_T *m4_out,
  const real_T *xD,
  void **pW,
  const uint8_T *device_num, const int_T p_width0,
  const uint8_T *can_port, const int_T p_width1,
  const uint8_T *safe_mode, const int_T p_width2);
extern void CAN_BUS_MULTISTATE_SF_Update_wrapper(const uint8_T *mode,
  const real32_T *m1_cmd,
  const real32_T *m2_cmd,
  const real32_T *m3_cmd,
  const real32_T *m4_cmd,
  real32_T *m1_out,
  real32_T *m2_out,
  real32_T *m3_out,
  real32_T *m4_out,
  real_T *xD,
  void **pW,
  const uint8_T *device_num, const int_T p_width0,
  const uint8_T *can_port, const int_T p_width1,
  const uint8_T *safe_mode, const int_T p_width2);
extern void CAN_BUS_MULTISTATE_SF_Terminate_wrapper(real_T *xD,
  void **pW,
  const uint8_T *device_num, const int_T p_width0,
  const uint8_T *can_port, const int_T p_width1,
  const uint8_T *safe_mode, const int_T p_width2);

#endif                                 // RTW_HEADER_can_bus_test3_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
