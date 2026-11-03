/*
 * heli_q8_Part4_AI_Help2_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_Part4_AI_Help2".
 *
 * Model version              : 11.60
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Nov  3 13:14:03 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_Part4_AI_Help2.h"
#include "heli_q8_Part4_AI_Help2_private.h"

/* Block parameters (default storage) */
P_heli_q8_Part4_AI_Help2_T heli_q8_Part4_AI_Help2_P = {
  /* Variable: A_d
   * Referenced by: '<S9>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.2234780575259187E-6, 0.0012234780575259186, 0.0, 0.0,
    0.0, 0.002, 1.0, 0.0, 0.0, 8.1565203835061226E-10, 1.2234780575259187E-6,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.002,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.002, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: B_d
   * Referenced by: '<S9>/Constant1'
   */
  { 0.0, 0.0, 1.7009102730819254E-7, 0.00017009102730819255, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0569696969696975E-6, 0.0010569696969696975, 0.0, 0.0,
    2.1552987195204065E-13, 4.3105974390408139E-10, 0.0, 0.0, 0.0 },

  /* Variable: C_d
   * Referenced by: '<S9>/Constant5'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: F
   * Referenced by: '<S10>/F'
   */
  { -3.7688978935580833E-16, 2.0744401195744162, 7.1382185255378605,
    6.5724416277389985E-16 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S8>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S8>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K
   * Referenced by: '<S10>/K'
   */
  { -3.7688978935580833E-16, 2.0744401195744162, -1.7739900636468366E-15,
    2.8607432835672304, 7.1382185255378605, 6.5724416277389985E-16,
    1.8241947810776389E-16, -0.5773502691896254, -2.08166599946613,
    -5.2619698282352369E-16 },

  /* Variable: P_0
   * Referenced by: '<S9>/Constant4'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Variable: Q_d
   * Referenced by: '<S9>/Constant2'
   */
  { 0.010000013333333333, 9.9999999999999991E-6, 0.0, 0.0, 4.0782634543612178E-9,
    6.11739640501988E-6, 0.0, 0.0, 0.0, 1.0000000000000003E-5, 0.01, 0.0, 0.0,
    2.039130095876531E-12, 4.0782601917530643E-9, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.010000013333333333, 9.9999999999999991E-6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0000000000000003E-5, 0.01, 0.0, 0.0, 0.0, 0.0, 0.0,
    4.0782634543612161E-9, 2.0391300958765298E-12, 0.0, 0.0,
    0.010000013333336328, 1.0000003742248059E-5, 0.0, 0.0, 0.0,
    6.11739640501988E-6, 4.0782601917530618E-9, 0.0, 0.0, 1.0000003742248059E-5,
    0.010000004989664853, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-12,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 6.0E-9, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 3.0E-12 },

  /* Variable: R_d2
   * Referenced by: '<S9>/Constant6'
   */
  { 0.0044515557676786284, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0012094581005361962,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.064248961134913352, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.014916073632920484, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.013271124665431112, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0014436052028649847 },

  /* Variable: V_s0
   * Referenced by: '<S10>/Constant'
   */
  7.5,

  /* Variable: x_0
   * Referenced by: '<S9>/Constant3'
   */
  { 0.0, 0.0, -0.52359877559829882, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S6>/HIL Write Analog'
   */
  { 0U, 1U },

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize'
   */
  24305.934065934067,

  /* Expression: pwm_leading_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: pwm_trailing_deadband
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize'
   */
  0.0,

  /* Expression: 2*pi/8192
   * Referenced by: '<S6>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S6>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S6>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S6>/Travel: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S7>/Constant'
   */
  0.0,

  /* Expression: 65
   * Referenced by: '<S7>/Constant1'
   */
  65.0,

  /* Expression: [0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S7>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S7>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S7>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S9>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Unit Delay'
   */
  0.0,

  /* Expression: -2*pi /4096
   * Referenced by: '<S6>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S6>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S6>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S6>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Expression: -2 * pi /4096
   * Referenced by: '<S6>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Expression: pi/6
   * Referenced by: '<S6>/Constant'
   */
  0.52359877559829882,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S6>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S6>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S6>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S10>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S8>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S8>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S8>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S8>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S8>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S8>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S8>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S12>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S12>/Integrator4'
   */
  0.0,

  /* Expression: 0.47
   * Referenced by: '<S2>/Back gain'
   */
  0.47,

  /* Expression: 0.53
   * Referenced by: '<S2>/Front gain'
   */
  0.53,

  /* Expression: 5
   * Referenced by: '<S6>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S6>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S6>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S6>/Back motor: Saturation'
   */
  -5.0,

  /* Expression: 0
   * Referenced by: '<S10>/gamma'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/zeta'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S13>/Integrator'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S13>/Integrator'
   */
  0.0,

  /* Expression: -inf
   * Referenced by: '<S13>/Integrator'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S13>/K_ei'
   */
  5.0,

  /* Computed Parameter: HILInitialize_CKChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },

  /* Computed Parameter: HILInitialize_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POModes
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POConfiguration
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POAlignment
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPolarity
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Clock
   * Referenced by: '<S6>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: StreamCall1_SendBufferSize
   * Referenced by: '<S7>/Stream Call1'
   */
  8000,

  /* Computed Parameter: StreamCall1_ReceiveBufferSize
   * Referenced by: '<S7>/Stream Call1'
   */
  8000,

  /* Computed Parameter: HILInitialize_AIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_AOChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILInitialize_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize'
   */
  4U,

  /* Computed Parameter: HILInitialize_POChannels
   * Referenced by: '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /* Computed Parameter: HILReadEncoderTimebase_Channels
   * Referenced by: '<S6>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S6>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: StreamFormattedWrite_MaxUnits
   * Referenced by: '<S7>/Stream Formatted Write'
   */
  80U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S8>/Game Controller'
   */
  12U,

  /* Computed Parameter: HILInitialize_Active
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POTerminate
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POExit
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_CKEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_AOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_AOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_EIStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_EIEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POPStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POPEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POStart
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_POEnter
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_POReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_OOReset
   * Referenced by: '<Root>/HIL Initialize'
   */
  0,

  /* Computed Parameter: HILInitialize_DOFinal
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILInitialize_DOInitial
   * Referenced by: '<Root>/HIL Initialize'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Active
   * Referenced by: '<S6>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: StreamCall1_NonBlocking
   * Referenced by: '<S7>/Stream Call1'
   */
  1,

  /* Computed Parameter: StreamCall1_Active
   * Referenced by: '<S7>/Stream Call1'
   */
  0,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S6>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S8>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S8>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S6>/HIL Read Encoder Timebase'
   */
  1U,

  /* Expression: value
   * Referenced by: '<S7>/String Constant'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 55U,
    63U, 98U, 97U, 117U, 100U, 61U, 49U, 49U, 53U, 50U, 48U, 48U, 44U, 119U,
    111U, 114U, 100U, 61U, 56U, 44U, 112U, 97U, 114U, 105U, 116U, 121U, 61U,
    110U, 111U, 110U, 101U, 44U, 115U, 116U, 111U, 112U, 61U, 49U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
    0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Expression: uri_argument
   * Referenced by: '<S7>/Stream Call1'
   */
  0U,

  /* Computed Parameter: StreamCall1_Endian
   * Referenced by: '<S7>/Stream Call1'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S8>/Game Controller'
   */
  1U
};
