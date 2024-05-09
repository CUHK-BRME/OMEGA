//
//  can_bus_test3_dt.h
//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Code generation for model "can_bus_test3".
//
//  Model version              : 1.3643
//  Simulink Coder version : 9.0 (R2018b) 24-May-2018
//  C++ source code generated on : Mon Apr 19 17:28:36 2021
//
//  Target selection: ert.tlc
//  Embedded hardware selection: ARM Compatible->ARM Cortex
//  Code generation objectives: Unspecified
//  Validation result: Not run


#include "ext_types.h"

// data type size table
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64m_T),
  sizeof(int64m_T),
  sizeof(uint64m_T),
  sizeof(int96m_T),
  sizeof(uint96m_T),
  sizeof(int128m_T),
  sizeof(uint128m_T),
  sizeof(int160m_T),
  sizeof(uint160m_T),
  sizeof(int192m_T),
  sizeof(uint192m_T),
  sizeof(int224m_T),
  sizeof(uint224m_T),
  sizeof(int256m_T),
  sizeof(uint256m_T)
};

// data type name table
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "int32_T",
  "int64m_T",
  "int64m_T",
  "uint64m_T",
  "int96m_T",
  "uint96m_T",
  "int128m_T",
  "uint128m_T",
  "int160m_T",
  "uint160m_T",
  "int192m_T",
  "uint192m_T",
  "int224m_T",
  "uint224m_T",
  "int256m_T",
  "uint256m_T"
};

// data type transitions for block I/O structure
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&can_bus_test3_B.Gain), 0, 0, 13 },

  { (char_T *)(&can_bus_test3_B.Gain3), 1, 0, 34 },

  { (char_T *)(&can_bus_test3_B.SFunctionBuilder_o3_e), 6, 0, 2 },

  { (char_T *)(&can_bus_test3_B.DataTypeConversion1), 4, 0, 1 },

  { (char_T *)(&can_bus_test3_B.DataTypeConversion4[0]), 3, 0, 25 }
  ,

  { (char_T *)(&can_bus_test3_DW.UD_DSTATE), 0, 0, 12 },

  { (char_T *)(&can_bus_test3_DW.Scope2_PWORK.LoggedData), 11, 0, 13 },

  { (char_T *)(&can_bus_test3_DW.systemEnable), 6, 0, 2 }
};

// data type transition table for block I/O structure
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

// data type transitions for Parameters structure
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&can_bus_test3_P.DiscreteDerivative_ICPrevScaled), 0, 0, 38 },

  { (char_T *)(&can_bus_test3_P.Constant9_Value), 1, 0, 12 },

  { (char_T *)(&can_bus_test3_P.SFunctionBuilder_P1), 3, 0, 10 }
};

// data type transition table for Parameters structure
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

// [EOF] can_bus_test3_dt.h
