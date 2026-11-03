/*
 * heli_q8_Part4_Working_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_Part4_Working".
 *
 * Model version              : 11.52
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Tue Nov  3 09:03:24 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_Part4_Working.h"
#include "heli_q8_Part4_Working_private.h"

/* Block parameters (default storage) */
P_heli_q8_Part4_Working_T heli_q8_Part4_Working_P = {
  /* Variable: A_d
   * Referenced by: '<S8>/Constant'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.2234780575259187E-6, 0.0012234780575259186, 0.002, 1.0,
    0.0, 0.0, 8.1565203835061226E-10, 1.2234780575259187E-6, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.002, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.002, 1.0 },

  /* Variable: B_d
   * Referenced by: '<S8>/Constant1'
   */
  { 0.0, 0.0, 1.7009102730819254E-7, 0.00017009102730819255, 0.0, 0.0,
    1.0569696969696975E-6, 0.0010569696969696975, 0.0, 0.0,
    2.1552987195204065E-13, 4.3105974390408139E-10 },

  /* Variable: C_d
   * Referenced by: '<S8>/Constant5'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Variable: F
   * Referenced by: '<S9>/F'
   */
  { -3.7688978935580833E-16, 2.0744401195744162, 7.1382185255378605,
    6.5724416277389985E-16 },

  /* Variable: Joystick_gain_x
   * Referenced by: '<S7>/Joystick_gain_x'
   */
  1.0,

  /* Variable: Joystick_gain_y
   * Referenced by: '<S7>/Joystick_gain_y'
   */
  -1.0,

  /* Variable: K
   * Referenced by: '<S9>/K'
   */
  { -3.7688978935580833E-16, 2.0744401195744162, -1.7739900636468366E-15,
    2.8607432835672304, 7.1382185255378605, 6.5724416277389985E-16,
    1.8241947810776389E-16, -0.5773502691896254, -2.08166599946613,
    -5.2619698282352369E-16 },

  /* Variable: P_0
   * Referenced by: '<S8>/Constant4'
   */
  { 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.01, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.01 },

  /* Variable: Q_d
   * Referenced by: '<S8>/Constant2'
   */
  { 3.0E-12, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    6.0E-8, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.5E-5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.5E-7 },

  /* Variable: R_d2
   * Referenced by: '<S8>/Constant6'
   */
  { 0.0053944419750402732, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0030686374405067885,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.14145120606042724, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.066054425619430077, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.000913654220575349, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0033909162304731006 },

  /* Variable: V_s0
   * Referenced by: '<S9>/Constant'
   */
  7.5,

  /* Variable: x_0
   * Referenced by: '<S8>/Constant3'
   */
  { 0.0, 0.0, -0.43, 0.0, 0.0, 0.0 },

  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<S5>/HIL Write Analog'
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

  /* Expression: -2 * pi /4096
   * Referenced by: '<S5>/Elevation: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: ElevationTransferFcn_A
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: ElevationTransferFcn_C
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: ElevationTransferFcn_D
   * Referenced by: '<S5>/Elevation: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Expression: 65
   * Referenced by: '<S6>/Constant1'
   */
  65.0,

  /* Expression: [0 0 0 0 0 0 0 0 0 0]
   * Referenced by: '<S6>/Memory'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S6>/Gain1'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: [ 0, 0, 1; 0, 1, 0; -1, 0, 0]
   * Referenced by: '<S6>/Gain2'
   */
  { 0.0, 0.0, -1.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: 0.4768
   * Referenced by: '<S4>/Constant'
   */
  0.4768,

  /* Expression: 0
   * Referenced by: '<S8>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Unit Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S7>/Rate Transition: x'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S7>/Dead Zone: x'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S7>/Dead Zone: x'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S7>/Gain: x'
   */
  1.1111111111111112,

  /* Expression: 0
   * Referenced by: '<S7>/Rate Transition: y'
   */
  0.0,

  /* Expression: -0.1
   * Referenced by: '<S7>/Dead Zone: y'
   */
  -0.1,

  /* Expression: 0.1
   * Referenced by: '<S7>/Dead Zone: y'
   */
  0.1,

  /* Expression: 10/9
   * Referenced by: '<S7>/Gain: y'
   */
  1.1111111111111112,

  /* Expression: -2*pi /4096
   * Referenced by: '<S5>/Pitch: Count to rad'
   */
  -0.0015339807878856412,

  /* Computed Parameter: PitchTransferFcn_A
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: PitchTransferFcn_C
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: PitchTransferFcn_D
   * Referenced by: '<S5>/Pitch: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 2*pi/8192
   * Referenced by: '<S5>/Travel: Count to rad'
   */
  0.00076699039394282058,

  /* Computed Parameter: TravelTransferFcn_A
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  -50.0,

  /* Computed Parameter: TravelTransferFcn_C
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  -2500.0,

  /* Computed Parameter: TravelTransferFcn_D
   * Referenced by: '<S5>/Travel: Transfer Fcn'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator4'
   */
  0.0,

  /* Expression: 0.49
   * Referenced by: '<S1>/Back gain'
   */
  0.49,

  /* Expression: 0.51
   * Referenced by: '<S1>/Front gain'
   */
  0.51,

  /* Expression: 5
   * Referenced by: '<S5>/Front motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S5>/Front motor: Saturation'
   */
  -5.0,

  /* Expression: 5
   * Referenced by: '<S5>/Back motor: Saturation'
   */
  5.0,

  /* Expression: -5
   * Referenced by: '<S5>/Back motor: Saturation'
   */
  -5.0,

  /* Expression: 0
   * Referenced by: '<S9>/gamma'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S9>/zeta'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S11>/Integrator'
   */
  0.0,

  /* Expression: inf
   * Referenced by: '<S11>/Integrator'
   */
  0.0,

  /* Expression: -inf
   * Referenced by: '<S11>/Integrator'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S11>/K_ei'
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
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  0,

  /* Computed Parameter: StreamCall1_SendBufferSize
   * Referenced by: '<S6>/Stream Call1'
   */
  8000,

  /* Computed Parameter: StreamCall1_ReceiveBufferSize
   * Referenced by: '<S6>/Stream Call1'
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
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  { 0U, 1U, 2U },

  /* Computed Parameter: HILReadEncoderTimebase_SamplesI
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  500U,

  /* Computed Parameter: StreamFormattedWrite_MaxUnits
   * Referenced by: '<S6>/Stream Formatted Write'
   */
  80U,

  /* Computed Parameter: GameController_BufferSize
   * Referenced by: '<S7>/Game Controller'
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
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  1,

  /* Computed Parameter: StreamCall1_NonBlocking
   * Referenced by: '<S6>/Stream Call1'
   */
  1,

  /* Computed Parameter: StreamCall1_Active
   * Referenced by: '<S6>/Stream Call1'
   */
  0,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<S5>/HIL Write Analog'
   */
  0,

  /* Computed Parameter: GameController_AutoCenter
   * Referenced by: '<S7>/Game Controller'
   */
  0,

  /* Computed Parameter: GameController_Enabled
   * Referenced by: '<S7>/Game Controller'
   */
  1,

  /* Computed Parameter: HILReadEncoderTimebase_Overflow
   * Referenced by: '<S5>/HIL Read Encoder Timebase'
   */
  1U,

  /* Expression: value
   * Referenced by: '<S6>/String Constant'
   */
  { 115U, 101U, 114U, 105U, 97U, 108U, 58U, 47U, 47U, 73U, 77U, 85U, 58U, 54U,
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
   * Referenced by: '<S6>/Stream Call1'
   */
  0U,

  /* Computed Parameter: StreamCall1_Endian
   * Referenced by: '<S6>/Stream Call1'
   */
  1U,

  /* Computed Parameter: GameController_ControllerNumber
   * Referenced by: '<S7>/Game Controller'
   */
  1U
};
