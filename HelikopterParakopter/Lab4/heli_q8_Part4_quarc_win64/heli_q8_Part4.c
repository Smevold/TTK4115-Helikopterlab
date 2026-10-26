/*
 * heli_q8_Part4.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "heli_q8_Part4".
 *
 * Model version              : 11.49
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Mon Oct 26 17:58:26 2026
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "heli_q8_Part4.h"
#include "heli_q8_Part4_private.h"
#include "heli_q8_Part4_dt.h"

t_stream heli_q8_Part4_rtZt_stream = NULL;

/* Block signals (default storage) */
B_heli_q8_Part4_T heli_q8_Part4_B;

/* Continuous states */
X_heli_q8_Part4_T heli_q8_Part4_X;

/* Block states (default storage) */
DW_heli_q8_Part4_T heli_q8_Part4_DW;

/* Real-time model */
static RT_MODEL_heli_q8_Part4_T heli_q8_Part4_M_;
RT_MODEL_heli_q8_Part4_T *const heli_q8_Part4_M = &heli_q8_Part4_M_;

/* Forward declaration for local functions */
static void heli_q8_Part4_mpower(const real_T a[144], real_T c[144]);
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(heli_q8_Part4_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(heli_q8_Part4_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (heli_q8_Part4_M->Timing.TaskCounters.TID[1] == 0) {
    heli_q8_Part4_M->Timing.RateInteraction.TID1_2 =
      (heli_q8_Part4_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    heli_q8_Part4_M->Timing.perTaskSampleHits[5] =
      heli_q8_Part4_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (heli_q8_Part4_M->Timing.TaskCounters.TID[2])++;
  if ((heli_q8_Part4_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    heli_q8_Part4_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 14;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  heli_q8_Part4_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Function for MATLAB Function: '<S8>/Correction' */
static void heli_q8_Part4_mpower(const real_T a[144], real_T c[144])
{
  real_T A[144];
  real_T smax;
  real_T y;
  int32_T c_ix;
  int32_T c_j;
  int32_T d;
  int32_T d_k;
  int32_T ijA;
  int32_T ix;
  int32_T iy;
  int32_T pipk;
  int8_T ipiv[12];
  int8_T p[12];
  int8_T ipiv_0;
  for (d_k = 0; d_k < 144; d_k++) {
    c[d_k] = 0.0;
    A[d_k] = a[d_k];
  }

  for (d_k = 0; d_k < 12; d_k++) {
    ipiv[d_k] = (int8_T)(d_k + 1);
  }

  for (c_j = 0; c_j < 11; c_j++) {
    pipk = c_j * 13;
    iy = 0;
    ix = pipk;
    smax = fabs(A[pipk]);
    for (d_k = 2; d_k <= 12 - c_j; d_k++) {
      ix++;
      y = fabs(A[ix]);
      if (y > smax) {
        iy = d_k - 1;
        smax = y;
      }
    }

    if (A[pipk + iy] != 0.0) {
      if (iy != 0) {
        iy += c_j;
        ipiv[c_j] = (int8_T)(iy + 1);
        ix = c_j;
        for (d_k = 0; d_k < 12; d_k++) {
          smax = A[ix];
          A[ix] = A[iy];
          A[iy] = smax;
          ix += 12;
          iy += 12;
        }
      }

      iy = (pipk - c_j) + 12;
      for (ix = pipk + 1; ix < iy; ix++) {
        A[ix] /= A[pipk];
      }
    }

    iy = pipk;
    ix = pipk + 12;
    for (d_k = 0; d_k <= 10 - c_j; d_k++) {
      if (A[ix] != 0.0) {
        smax = -A[ix];
        c_ix = pipk + 1;
        d = (iy - c_j) + 24;
        for (ijA = iy + 13; ijA < d; ijA++) {
          A[ijA] += A[c_ix] * smax;
          c_ix++;
        }
      }

      ix += 12;
      iy += 12;
    }
  }

  for (d_k = 0; d_k < 12; d_k++) {
    p[d_k] = (int8_T)(d_k + 1);
  }

  for (c_j = 0; c_j < 11; c_j++) {
    ipiv_0 = ipiv[c_j];
    if (ipiv_0 > c_j + 1) {
      pipk = p[ipiv_0 - 1];
      p[ipiv_0 - 1] = p[c_j];
      p[c_j] = (int8_T)pipk;
    }
  }

  for (c_j = 0; c_j < 12; c_j++) {
    pipk = p[c_j] - 1;
    c[c_j + 12 * pipk] = 1.0;
    for (iy = c_j; iy + 1 < 13; iy++) {
      d_k = 12 * pipk + iy;
      if (c[d_k] != 0.0) {
        for (ix = iy + 1; ix + 1 < 13; ix++) {
          c_ix = 12 * pipk + ix;
          c[c_ix] -= c[d_k] * A[12 * iy + ix];
        }
      }
    }
  }

  for (c_j = 0; c_j < 12; c_j++) {
    pipk = 12 * c_j;
    for (iy = 11; iy >= 0; iy--) {
      ix = 12 * iy;
      d_k = iy + pipk;
      smax = c[d_k];
      if (smax != 0.0) {
        c[d_k] = smax / A[iy + ix];
        for (d_k = 0; d_k < iy; d_k++) {
          c_ix = d_k + pipk;
          c[c_ix] -= c[iy + pipk] * A[d_k + ix];
        }
      }
    }
  }
}

/* Model output function for TID0 */
void heli_q8_Part4_output0(void)       /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  t_stream_ptr rtb_StreamCall1_o1;
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_FrontmotorSaturation;
  real_T rtb_Sum;
  real32_T rtb_StreamRead1_o2[10];
  int32_T rtb_StreamFormattedWrite_o2;
  int32_T rtb_StreamCall1_o3;
  boolean_T rtb_StreamRead1_o3;
  real_T L[144];
  real_T L_0[144];
  real_T L_tmp[144];
  real_T L_tmp_0[144];
  real_T P_posteriori_tmp[144];
  real_T b_0[144];
  real_T b_1[144];
  real_T tmp[12];
  real_T tmp_0[12];
  real_T x_posteriori[12];
  real_T tmp_1[9];
  real_T tmp_2[5];
  real_T N;
  real_T euler_rates_tmp;
  real_T euler_rates_tmp_0;
  real_T euler_rates_tmp_1;
  int32_T L_tmp_tmp;
  int32_T P_priori_tmp;
  int32_T b_tmp;
  int32_T b_tmp_0;
  int32_T i;
  int_T iy;
  int8_T b[144];
  boolean_T exitg1;
  boolean_T y;
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* set solver stop time */
    if (!(heli_q8_Part4_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&heli_q8_Part4_M->solverInfo,
                            ((heli_q8_Part4_M->Timing.clockTickH0 + 1) *
        heli_q8_Part4_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&heli_q8_Part4_M->solverInfo,
                            ((heli_q8_Part4_M->Timing.clockTick0 + 1) *
        heli_q8_Part4_M->Timing.stepSize0 + heli_q8_Part4_M->Timing.clockTickH0 *
        heli_q8_Part4_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(heli_q8_Part4_M)) {
    heli_q8_Part4_M->Timing.t[0] = rtsiGetT(&heli_q8_Part4_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

    /* S-Function Block: heli_q8_Part4/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (heli_q8_Part4_DW.HILReadEncoderTimebase_Task, 1,
         &heli_q8_Part4_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          heli_q8_Part4_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_FrontmotorSaturation =
          heli_q8_Part4_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_Sum = heli_q8_Part4_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S5>/Elevation: Count to rad' */
    heli_q8_Part4_B.ElevationCounttorad =
      heli_q8_Part4_P.ElevationCounttorad_Gain * rtb_Sum;
  }

  /* TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  heli_q8_Part4_B.ElevationTransferFcn = 0.0;
  heli_q8_Part4_B.ElevationTransferFcn += heli_q8_Part4_P.ElevationTransferFcn_C
    * heli_q8_Part4_X.ElevationTransferFcn_CSTATE;
  heli_q8_Part4_B.ElevationTransferFcn += heli_q8_Part4_P.ElevationTransferFcn_D
    * heli_q8_Part4_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* S-Function (stream_call_block): '<S6>/Stream Call1' incorporates:
     *  Constant: '<S6>/Constant'
     *  S-Function (string_constant_block): '<S6>/String Constant'
     */

    /* S-Function Block: heli_q8_Part4/IMU/Stream Call1 (stream_call_block) */
    {
      t_error result = 0;
      t_boolean close_flag = (heli_q8_Part4_P.Constant_Value != 0);
      rtb_StreamCall1_o1 = NULL;
      switch (heli_q8_Part4_DW.StreamCall1_State) {
       case STREAM_CALL_STATE_NOT_CONNECTED:
        {
          if (!close_flag) {
            /* Make sure URI is null-terminated */
            if (string_length((char *) heli_q8_Part4_P.StringConstant_Value, 255)
                == 255) {
              rtmSetErrorStatus(heli_q8_Part4_M,
                                "URI passed to Stream Call block is not null-terminated!");
              result = -QERR_STRING_NOT_TERMINATED;
            } else {
              result = stream_connect((char *)
                heli_q8_Part4_P.StringConstant_Value,
                heli_q8_Part4_P.StreamCall1_NonBlocking != 0,
                heli_q8_Part4_P.StreamCall1_SendBufferSize,
                heli_q8_Part4_P.StreamCall1_ReceiveBufferSize,
                &heli_q8_Part4_DW.StreamCall1_Stream);
              if (result == 0) {
                heli_q8_Part4_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
                stream_set_byte_order(heli_q8_Part4_DW.StreamCall1_Stream,
                                      (t_stream_byte_order)
                                      heli_q8_Part4_P.StreamCall1_Endian);
                rtb_StreamCall1_o1 = &heli_q8_Part4_DW.StreamCall1_Stream;
              } else if (result == -QERR_WOULD_BLOCK) {
                heli_q8_Part4_DW.StreamCall1_State =
                  STREAM_CALL_STATE_CONNECTING;
                result = 0;
              }
            }
          }
          break;
        }

       case STREAM_CALL_STATE_CONNECTING:
        {
          if (!close_flag) {
            const t_timeout timeout = { 0, 0, false };/* zero seconds */

            result = stream_poll(heli_q8_Part4_DW.StreamCall1_Stream, &timeout,
                                 STREAM_POLL_CONNECT);
            if (result > 0) {
              heli_q8_Part4_DW.StreamCall1_State = STREAM_CALL_STATE_CONNECTED;
              stream_set_byte_order(heli_q8_Part4_DW.StreamCall1_Stream,
                                    (t_stream_byte_order)
                                    heli_q8_Part4_P.StreamCall1_Endian);
              rtb_StreamCall1_o1 = &heli_q8_Part4_DW.StreamCall1_Stream;
              result = 0;
              break;
            } else if (result == 0) {
              break;
            }
          }

          /* Fall through deliberately */
        }

       case STREAM_CALL_STATE_CONNECTED:
        {
          rtb_StreamCall1_o1 = &heli_q8_Part4_DW.StreamCall1_Stream;
          if (!close_flag) {
            break;
          }

          /* Fall through deliberately */
        }

       default:
        {
          t_error close_result = stream_close
            (heli_q8_Part4_DW.StreamCall1_Stream);
          if (close_result == 0) {
            heli_q8_Part4_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
            heli_q8_Part4_DW.StreamCall1_Stream = NULL;
            rtb_StreamCall1_o1 = NULL;
          } else if (result == 0) {
            result = close_result;
          }
          break;
        }
      }

      heli_q8_Part4_B.StreamCall1_o2 = heli_q8_Part4_DW.StreamCall1_State;
      rtb_StreamCall1_o3 = (int32_T) result;
    }

    /* S-Function (stream_formatted_write_block): '<S6>/Stream Formatted Write' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    {
      t_error result;
      if (rtb_StreamCall1_o1 != NULL) {
        result = stream_print_utf8_char_array(*rtb_StreamCall1_o1,
          heli_q8_Part4_P.StreamFormattedWrite_MaxUnits,
          &rtb_StreamFormattedWrite_o2, "%c\n"
          , (char) heli_q8_Part4_P.Constant1_Value
          );
        if (result > 0) {
          result = stream_flush(*rtb_StreamCall1_o1);
        }

        if (result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      }
    }

    /* S-Function (stream_read_block): '<S6>/Stream Read1' incorporates:
     *  Constant: '<S6>/Constant1'
     *  S-Function (stream_call_block): '<S6>/Stream Call1'
     *  S-Function (stream_formatted_write_block): '<S6>/Stream Formatted Write'
     */

    /* S-Function Block: heli_q8_Part4/IMU/Stream Read1 (stream_read_block) */
    {
      t_error result;
      memset(&rtb_StreamRead1_o2[0], 0, 10 * sizeof(real32_T));
      if (((t_stream_ptr)rtb_StreamCall1_o1) != NULL) {
        result = stream_receive_unit_array(*((t_stream_ptr)rtb_StreamCall1_o1),
          &rtb_StreamRead1_o2[0], sizeof(real32_T), 10);
        rtb_StreamRead1_o3 = (result > 0);
        if (result > 0 || result == -QERR_WOULD_BLOCK) {
          result = 0;
        }
      } else {
        rtb_StreamRead1_o3 = false;
        result = 0;
      }
    }

    for (i = 0; i < 10; i++) {
      /* Switch: '<S6>/Switch' */
      if (rtb_StreamRead1_o3) {
        /* Switch: '<S6>/Switch' incorporates:
         *  DataTypeConversion: '<S6>/Data Type Conversion'
         */
        heli_q8_Part4_B.Switch[i] = rtb_StreamRead1_o2[i];
      } else {
        /* Switch: '<S6>/Switch' incorporates:
         *  Memory: '<S6>/Memory'
         */
        heli_q8_Part4_B.Switch[i] = heli_q8_Part4_DW.Memory_PreviousInput[i];
      }

      /* End of Switch: '<S6>/Switch' */
    }

    for (i = 0; i < 3; i++) {
      /* Gain: '<S6>/Gain1' */
      heli_q8_Part4_B.Gain1[i] = 0.0;

      /* Gain: '<S6>/Gain2' */
      heli_q8_Part4_B.Gain2[i] = 0.0;

      /* Gain: '<S6>/Gain1' */
      heli_q8_Part4_B.Gain1[i] += heli_q8_Part4_P.Gain1_Gain[i] *
        heli_q8_Part4_B.Switch[3];

      /* Gain: '<S6>/Gain2' */
      heli_q8_Part4_B.Gain2[i] += heli_q8_Part4_P.Gain2_Gain[i] *
        heli_q8_Part4_B.Switch[0];

      /* Gain: '<S6>/Gain1' */
      heli_q8_Part4_B.Gain1[i] += heli_q8_Part4_P.Gain1_Gain[i + 3] *
        heli_q8_Part4_B.Switch[4];

      /* Gain: '<S6>/Gain2' */
      heli_q8_Part4_B.Gain2[i] += heli_q8_Part4_P.Gain2_Gain[i + 3] *
        heli_q8_Part4_B.Switch[1];

      /* Gain: '<S6>/Gain1' */
      heli_q8_Part4_B.Gain1[i] += heli_q8_Part4_P.Gain1_Gain[i + 6] *
        heli_q8_Part4_B.Switch[5];

      /* Gain: '<S6>/Gain2' */
      heli_q8_Part4_B.Gain2[i] += heli_q8_Part4_P.Gain2_Gain[i + 6] *
        heli_q8_Part4_B.Switch[2];
    }

    /* MATLAB Function: '<S4>/Pitch_Transformation' */
    /* MATLAB Function 'Gyro_Math/Pitch_Transformation': '<S13>:1' */
    if (heli_q8_Part4_B.Gain2[2] == 0.0) {
      /* '<S13>:1:3' */
      /* '<S13>:1:4' */
      heli_q8_Part4_B.p_a = 1.5707963267948966;
    } else {
      /* '<S13>:1:6' */
      heli_q8_Part4_B.p_a = heli_q8_Part4_B.Gain2[1] / heli_q8_Part4_B.Gain2[2];
      heli_q8_Part4_B.p_a = atan(heli_q8_Part4_B.p_a);
    }

    /* End of MATLAB Function: '<S4>/Pitch_Transformation' */

    /* MATLAB Function: '<S4>/Elevation_Transformation' */
    /* MATLAB Function 'Gyro_Math/Elevation_Transformation': '<S12>:1' */
    /* '<S12>:1:3' */
    N = sqrt(heli_q8_Part4_B.Gain2[1] * heli_q8_Part4_B.Gain2[1] +
             heli_q8_Part4_B.Gain2[2] * heli_q8_Part4_B.Gain2[2]);
    if (N == 0.0) {
      /* '<S12>:1:5' */
      /* '<S12>:1:6' */
      N = 1.5707963267948966;
    } else {
      /* '<S12>:1:8' */
      N = atan(heli_q8_Part4_B.Gain2[0] / N);
    }

    /* End of MATLAB Function: '<S4>/Elevation_Transformation' */

    /* Sum: '<S4>/Sum' incorporates:
     *  Constant: '<S4>/Constant'
     */
    heli_q8_Part4_B.Sum = N + heli_q8_Part4_P.Constant_Value_j;

    /* MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travel rate]' incorporates:
     *  SignalConversion generated from: '<S3>/ SFunction '
     */
    /* MATLAB Function 'Gyro vector to [pitch rate, elevation rate, travel rate]': '<S3>:1' */
    /* '<S3>:1:3' */
    /* '<S3>:1:4' */
    /* '<S3>:1:7' */
    /* '<S3>:1:10' */
    N = tan(heli_q8_Part4_B.Sum);
    euler_rates_tmp = sin(heli_q8_Part4_B.p_a);
    euler_rates_tmp_0 = cos(heli_q8_Part4_B.p_a);
    euler_rates_tmp_1 = cos(heli_q8_Part4_B.Sum);
    tmp_1[0] = 1.0;
    tmp_1[3] = euler_rates_tmp * N;
    tmp_1[6] = euler_rates_tmp_0 * N;
    tmp_1[1] = 0.0;
    tmp_1[4] = euler_rates_tmp_0;
    tmp_1[7] = -euler_rates_tmp;
    tmp_1[2] = 0.0;
    tmp_1[5] = euler_rates_tmp / euler_rates_tmp_1;
    tmp_1[8] = euler_rates_tmp_0 / euler_rates_tmp_1;
    for (i = 0; i < 3; i++) {
      heli_q8_Part4_B.euler_rates[i] = 0.0;
      heli_q8_Part4_B.euler_rates[i] += tmp_1[i] * heli_q8_Part4_B.Gain1[0];
      heli_q8_Part4_B.euler_rates[i] += tmp_1[i + 3] * heli_q8_Part4_B.Gain1[1];
      heli_q8_Part4_B.euler_rates[i] += tmp_1[i + 6] * heli_q8_Part4_B.Gain1[2];
    }

    /* End of MATLAB Function: '<Root>/Gyro vector to [pitch rate, elevation rate, travel rate]' */

    /* UnitDelay: '<S9>/Unit Delay2' */
    heli_q8_Part4_B.V_s_tilde = heli_q8_Part4_DW.UnitDelay2_DSTATE;

    /* UnitDelay: '<S9>/Unit Delay' */
    heli_q8_Part4_B.V_d = heli_q8_Part4_DW.UnitDelay_DSTATE;

    /* MATLAB Function: '<S8>/Prediction' incorporates:
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant2'
     *  Constant: '<S8>/Constant3'
     *  Constant: '<S8>/Constant4'
     *  SignalConversion generated from: '<S15>/ SFunction '
     *  UnitDelay: '<S8>/Unit Delay'
     *  UnitDelay: '<S8>/Unit Delay1'
     */
    memcpy(&x_posteriori[0], &heli_q8_Part4_DW.UnitDelay1_DSTATE[0], 12U *
           sizeof(real_T));
    memcpy(&L[0], &heli_q8_Part4_DW.UnitDelay_DSTATE_m[0], 144U * sizeof(real_T));

    /* MATLAB Function 'Kalman Filter + Luenberger/Prediction': '<S15>:1' */
    y = true;
    iy = 0;
    exitg1 = false;
    while ((!exitg1) && (iy < 12)) {
      if (!(heli_q8_Part4_DW.UnitDelay1_DSTATE[iy] == 0.0)) {
        y = false;
        exitg1 = true;
      } else {
        iy++;
      }
    }

    if (y) {
      /* '<S15>:1:4' */
      memcpy(&x_posteriori[0], &heli_q8_Part4_P.x_0[0], 12U * sizeof(real_T));
    }

    y = true;
    iy = 0;
    exitg1 = false;
    while ((!exitg1) && (iy < 144)) {
      if (!(heli_q8_Part4_DW.UnitDelay_DSTATE_m[iy] == 0.0)) {
        y = false;
        exitg1 = true;
      } else {
        iy++;
      }
    }

    if (y) {
      /* '<S15>:1:8' */
      memcpy(&L[0], &heli_q8_Part4_P.P_0[0], 144U * sizeof(real_T));
    }

    /* '<S15>:1:11' */
    /* '<S15>:1:12' */
    for (i = 0; i < 12; i++) {
      tmp_0[i] = 0.0;
      for (iy = 0; iy < 12; iy++) {
        P_priori_tmp = 12 * iy + i;
        b_0[P_priori_tmp] = 0.0;
        for (L_tmp_tmp = 0; L_tmp_tmp < 12; L_tmp_tmp++) {
          b_0[P_priori_tmp] += heli_q8_Part4_P.A_d[12 * L_tmp_tmp + i] * L[12 *
            iy + L_tmp_tmp];
        }

        tmp_0[i] += heli_q8_Part4_P.A_d[P_priori_tmp] * x_posteriori[iy];
      }

      heli_q8_Part4_B.x_priori[i] = tmp_0[i] + (heli_q8_Part4_P.B_d[i + 12] *
        heli_q8_Part4_B.V_d + heli_q8_Part4_P.B_d[i] * heli_q8_Part4_B.V_s_tilde);
      for (iy = 0; iy < 12; iy++) {
        N = 0.0;
        for (P_priori_tmp = 0; P_priori_tmp < 12; P_priori_tmp++) {
          N += b_0[12 * P_priori_tmp + i] * heli_q8_Part4_P.A_d[12 *
            P_priori_tmp + iy];
        }

        P_priori_tmp = 12 * iy + i;
        heli_q8_Part4_B.P_priori[P_priori_tmp] =
          heli_q8_Part4_P.Q_d[P_priori_tmp] + N;
      }
    }

    /* End of MATLAB Function: '<S8>/Prediction' */
  }

  /* Integrator: '<S8>/Integrator2' */
  heli_q8_Part4_B.p = heli_q8_Part4_X.Integrator2_CSTATE;

  /* Integrator: '<S8>/Integrator1' */
  heli_q8_Part4_B.e = heli_q8_Part4_X.Integrator1_CSTATE;

  /* Integrator: '<S8>/Integrator3' */
  heli_q8_Part4_B.lambda = heli_q8_Part4_X.Integrator3_CSTATE;

  /* MATLAB Function: '<S8>/Correction' incorporates:
   *  Constant: '<S8>/Constant5'
   *  Constant: '<S8>/Constant6'
   */
  /* MATLAB Function 'Kalman Filter + Luenberger/Correction': '<S14>:1' */
  /* '<S14>:1:3' */
  for (i = 0; i < 12; i++) {
    for (iy = 0; iy < 12; iy++) {
      L_tmp_tmp = 12 * iy + i;
      L_tmp[iy + 12 * i] = heli_q8_Part4_P.C_d[L_tmp_tmp];
      b_0[L_tmp_tmp] = 0.0;
      for (P_priori_tmp = 0; P_priori_tmp < 12; P_priori_tmp++) {
        b_0[L_tmp_tmp] += heli_q8_Part4_P.C_d[12 * P_priori_tmp + i] *
          heli_q8_Part4_B.P_priori[12 * iy + P_priori_tmp];
      }
    }
  }

  for (i = 0; i < 12; i++) {
    for (iy = 0; iy < 12; iy++) {
      N = 0.0;
      for (P_priori_tmp = 0; P_priori_tmp < 12; P_priori_tmp++) {
        N += b_0[12 * P_priori_tmp + i] * L_tmp[12 * iy + P_priori_tmp];
      }

      P_priori_tmp = 12 * iy + i;
      b_1[P_priori_tmp] = heli_q8_Part4_P.R_d2[P_priori_tmp] + N;
    }
  }

  heli_q8_Part4_mpower(b_1, b_0);
  for (i = 0; i < 12; i++) {
    for (iy = 0; iy < 12; iy++) {
      P_priori_tmp = i + 12 * iy;
      b_1[P_priori_tmp] = 0.0;
      for (L_tmp_tmp = 0; L_tmp_tmp < 12; L_tmp_tmp++) {
        b_1[P_priori_tmp] += heli_q8_Part4_B.P_priori[12 * L_tmp_tmp + i] *
          L_tmp[12 * iy + L_tmp_tmp];
      }
    }

    for (iy = 0; iy < 12; iy++) {
      L_tmp_tmp = i + 12 * iy;
      L[L_tmp_tmp] = 0.0;
      for (P_priori_tmp = 0; P_priori_tmp < 12; P_priori_tmp++) {
        L[L_tmp_tmp] += b_1[12 * P_priori_tmp + i] * b_0[12 * iy + P_priori_tmp];
      }
    }
  }

  /* '<S14>:1:7' */
  for (i = 0; i < 144; i++) {
    L_tmp[i] = 0.0;
  }

  for (iy = 0; iy < 12; iy++) {
    L_tmp[iy + 12 * iy] = 1.0;
  }

  /* '<S14>:1:9' */
  memset(&b[0], 0, 144U * sizeof(int8_T));

  /* SignalConversion generated from: '<S14>/ SFunction ' incorporates:
   *  MATLAB Function: '<S8>/Correction'
   */
  tmp_0[0] = heli_q8_Part4_B.p;
  tmp_0[1] = heli_q8_Part4_B.euler_rates[0];
  tmp_0[2] = heli_q8_Part4_B.e;
  tmp_0[3] = heli_q8_Part4_B.euler_rates[1];
  tmp_0[4] = heli_q8_Part4_B.lambda;
  tmp_0[5] = heli_q8_Part4_B.euler_rates[2];
  tmp_0[6] = 0.0;
  tmp_0[7] = 0.0;
  tmp_0[8] = 0.0;
  tmp_0[9] = 0.0;
  tmp_0[10] = 0.0;
  tmp_0[11] = 0.0;

  /* MATLAB Function: '<S8>/Correction' incorporates:
   *  Constant: '<S8>/Constant5'
   *  Constant: '<S8>/Constant6'
   */
  for (iy = 0; iy < 12; iy++) {
    b[iy + 12 * iy] = 1;
    x_posteriori[iy] = 0.0;
    for (i = 0; i < 12; i++) {
      x_posteriori[iy] += heli_q8_Part4_P.C_d[12 * i + iy] *
        heli_q8_Part4_B.x_priori[i];
    }

    tmp[iy] = tmp_0[iy] - x_posteriori[iy];
  }

  for (i = 0; i < 12; i++) {
    N = 0.0;
    for (iy = 0; iy < 12; iy++) {
      P_priori_tmp = 12 * iy + i;
      N += L[P_priori_tmp] * tmp[iy];
      P_posteriori_tmp[P_priori_tmp] = 0.0;
      for (L_tmp_tmp = 0; L_tmp_tmp < 12; L_tmp_tmp++) {
        P_posteriori_tmp[P_priori_tmp] += L[12 * L_tmp_tmp + i] *
          heli_q8_Part4_P.C_d[12 * iy + L_tmp_tmp];
      }
    }

    heli_q8_Part4_B.x_posteriori[i] = heli_q8_Part4_B.x_priori[i] + N;
  }

  for (i = 0; i < 144; i++) {
    b_0[i] = (real_T)b[i] - P_posteriori_tmp[i];
  }

  for (i = 0; i < 12; i++) {
    for (iy = 0; iy < 12; iy++) {
      L_tmp_tmp = i + 12 * iy;
      b_1[L_tmp_tmp] = 0.0;
      L_tmp_0[iy + 12 * i] = L_tmp[L_tmp_tmp] - P_posteriori_tmp[L_tmp_tmp];
      L_0[L_tmp_tmp] = 0.0;
      for (P_priori_tmp = 0; P_priori_tmp < 12; P_priori_tmp++) {
        b_tmp = 12 * P_priori_tmp + i;
        b_tmp_0 = 12 * iy + P_priori_tmp;
        b_1[L_tmp_tmp] += b_0[b_tmp] * heli_q8_Part4_B.P_priori[b_tmp_0];
        L_0[L_tmp_tmp] += L[b_tmp] * heli_q8_Part4_P.R_d2[b_tmp_0];
      }
    }
  }

  for (i = 0; i < 12; i++) {
    for (iy = 0; iy < 12; iy++) {
      L_tmp_tmp = i + 12 * iy;
      b_0[L_tmp_tmp] = 0.0;
      L_tmp[L_tmp_tmp] = 0.0;
      for (P_priori_tmp = 0; P_priori_tmp < 12; P_priori_tmp++) {
        b_tmp = 12 * P_priori_tmp + i;
        b_0[L_tmp_tmp] += b_1[b_tmp] * L_tmp_0[12 * iy + P_priori_tmp];
        L_tmp[L_tmp_tmp] += L_0[b_tmp] * L[12 * P_priori_tmp + iy];
      }
    }
  }

  for (i = 0; i < 144; i++) {
    heli_q8_Part4_B.P_posteriori[i] = b_0[i] + L_tmp[i];
  }

  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* Sum: '<S5>/Sum' */
    heli_q8_Part4_B.Sum_n = heli_q8_Part4_B.ElevationCounttorad;
  }

  /* Integrator: '<Root>/Integrator' */
  heli_q8_Part4_B.Gyro_e = heli_q8_Part4_X.Integrator_CSTATE;
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* UnitDelay: '<S9>/Unit Delay1' */
    heli_q8_Part4_B.V_s = heli_q8_Part4_DW.UnitDelay1_DSTATE_c;

    /* Gain: '<S5>/Pitch: Count to rad' */
    heli_q8_Part4_B.PitchCounttorad = heli_q8_Part4_P.PitchCounttorad_Gain *
      rtb_FrontmotorSaturation;
  }

  /* TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  heli_q8_Part4_B.PitchTransferFcn = 0.0;
  heli_q8_Part4_B.PitchTransferFcn += heli_q8_Part4_P.PitchTransferFcn_C *
    heli_q8_Part4_X.PitchTransferFcn_CSTATE;
  heli_q8_Part4_B.PitchTransferFcn += heli_q8_Part4_P.PitchTransferFcn_D *
    heli_q8_Part4_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
  }

  /* Integrator: '<Root>/Integrator1' */
  heli_q8_Part4_B.Gyro_p = heli_q8_Part4_X.Integrator1_CSTATE_p;

  /* RateTransition: '<S7>/Rate Transition: x' */
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* Gain: '<S5>/Travel: Count to rad' */
    heli_q8_Part4_B.TravelCounttorad = heli_q8_Part4_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
    if (heli_q8_Part4_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S7>/Rate Transition: x' */
      heli_q8_Part4_B.RateTransitionx = heli_q8_Part4_DW.RateTransitionx_Buffer0;
    }

    /* DeadZone: '<S7>/Dead Zone: x' */
    if (heli_q8_Part4_B.RateTransitionx > heli_q8_Part4_P.DeadZonex_End) {
      /* Sum: '<S2>/Sum' */
      rtb_Sum = heli_q8_Part4_B.RateTransitionx - heli_q8_Part4_P.DeadZonex_End;
    } else if (heli_q8_Part4_B.RateTransitionx >=
               heli_q8_Part4_P.DeadZonex_Start) {
      /* Sum: '<S2>/Sum' */
      rtb_Sum = 0.0;
    } else {
      /* Sum: '<S2>/Sum' */
      rtb_Sum = heli_q8_Part4_B.RateTransitionx -
        heli_q8_Part4_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S7>/Dead Zone: x' */

    /* Gain: '<S7>/Joystick_gain_x' incorporates:
     *  Gain: '<S7>/Gain: x'
     */
    heli_q8_Part4_B.Joystick_gain_x = heli_q8_Part4_P.Gainx_Gain * rtb_Sum *
      heli_q8_Part4_P.Joystick_gain_x;

    /* RateTransition: '<S7>/Rate Transition: y' */
    if (heli_q8_Part4_M->Timing.RateInteraction.TID1_2) {
      /* RateTransition: '<S7>/Rate Transition: y' */
      heli_q8_Part4_B.RateTransitiony = heli_q8_Part4_DW.RateTransitiony_Buffer0;
    }

    /* End of RateTransition: '<S7>/Rate Transition: y' */

    /* DeadZone: '<S7>/Dead Zone: y' */
    if (heli_q8_Part4_B.RateTransitiony > heli_q8_Part4_P.DeadZoney_End) {
      /* Sum: '<S2>/Sum' */
      rtb_Sum = heli_q8_Part4_B.RateTransitiony - heli_q8_Part4_P.DeadZoney_End;
    } else if (heli_q8_Part4_B.RateTransitiony >=
               heli_q8_Part4_P.DeadZoney_Start) {
      /* Sum: '<S2>/Sum' */
      rtb_Sum = 0.0;
    } else {
      /* Sum: '<S2>/Sum' */
      rtb_Sum = heli_q8_Part4_B.RateTransitiony -
        heli_q8_Part4_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S7>/Dead Zone: y' */

    /* Gain: '<S7>/Joystick_gain_y' incorporates:
     *  Gain: '<S7>/Gain: y'
     */
    heli_q8_Part4_B.Joystick_gain_y = heli_q8_Part4_P.Gainy_Gain * rtb_Sum *
      heli_q8_Part4_P.Joystick_gain_y;
  }

  /* End of RateTransition: '<S7>/Rate Transition: x' */

  /* TransferFcn: '<S5>/Travel: Transfer Fcn' */
  heli_q8_Part4_B.TravelTransferFcn = 0.0;
  heli_q8_Part4_B.TravelTransferFcn += heli_q8_Part4_P.TravelTransferFcn_C *
    heli_q8_Part4_X.TravelTransferFcn_CSTATE;
  heli_q8_Part4_B.TravelTransferFcn += heli_q8_Part4_P.TravelTransferFcn_D *
    heli_q8_Part4_B.TravelCounttorad;

  /* Integrator: '<Root>/Integrator2' */
  heli_q8_Part4_B.Integrator2 = heli_q8_Part4_X.Integrator2_CSTATE_j;

  /* Integrator: '<Root>/Integrator3' */
  heli_q8_Part4_B.Integrator3 = heli_q8_Part4_X.Integrator3_CSTATE_b;

  /* Integrator: '<Root>/Integrator4' */
  heli_q8_Part4_B.Integrator4 = heli_q8_Part4_X.Integrator4_CSTATE;
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* SignalConversion generated from: '<Root>/To File' */
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[0] =
      heli_q8_Part4_B.TravelCounttorad;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[1] =
      heli_q8_Part4_B.TravelTransferFcn;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[2] =
      heli_q8_Part4_B.PitchCounttorad;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[3] =
      heli_q8_Part4_B.PitchTransferFcn;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[4] = heli_q8_Part4_B.Sum_n;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[5] =
      heli_q8_Part4_B.ElevationTransferFcn;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[6] =
      heli_q8_Part4_B.Joystick_gain_x;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[7] =
      heli_q8_Part4_B.Joystick_gain_y;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[14] = heli_q8_Part4_B.p_a;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[15] = heli_q8_Part4_B.Sum;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[8] = heli_q8_Part4_B.Gain2[0];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[11] = heli_q8_Part4_B.Gain1
      [0];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[16] =
      heli_q8_Part4_B.euler_rates[0];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[9] = heli_q8_Part4_B.Gain2[1];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[12] = heli_q8_Part4_B.Gain1
      [1];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[17] =
      heli_q8_Part4_B.euler_rates[1];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[10] = heli_q8_Part4_B.Gain2
      [2];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[13] = heli_q8_Part4_B.Gain1
      [2];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[18] =
      heli_q8_Part4_B.euler_rates[2];
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[19] =
      heli_q8_Part4_B.Integrator2;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[20] =
      heli_q8_Part4_B.Integrator3;
    heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[21] =
      heli_q8_Part4_B.Integrator4;
    memcpy(&heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[22],
           &heli_q8_Part4_B.x_posteriori[0], 12U * sizeof(real_T));

    /* ToFile: '<Root>/To File' */
    if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
      if (rtmIsMajorTimeStep(heli_q8_Part4_M) ) {
        {
          if (!(++heli_q8_Part4_DW.ToFile_IWORK.Decimation % 1) &&
              (heli_q8_Part4_DW.ToFile_IWORK.Count * (34 + 1)) + 1 < 100000000 )
          {
            FILE *fp = (FILE *) heli_q8_Part4_DW.ToFile_PWORK.FilePtr;
            if (fp != (NULL)) {
              real_T u[34 + 1];
              heli_q8_Part4_DW.ToFile_IWORK.Decimation = 0;
              u[0] = heli_q8_Part4_M->Timing.t[1];
              u[1] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[0];
              u[2] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[1];
              u[3] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[2];
              u[4] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[3];
              u[5] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[4];
              u[6] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[5];
              u[7] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[6];
              u[8] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[7];
              u[9] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[8];
              u[10] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[9];
              u[11] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[10];
              u[12] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[11];
              u[13] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[12];
              u[14] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[13];
              u[15] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[14];
              u[16] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[15];
              u[17] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[16];
              u[18] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[17];
              u[19] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[18];
              u[20] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[19];
              u[21] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[20];
              u[22] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[21];
              u[23] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[22];
              u[24] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[23];
              u[25] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[24];
              u[26] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[25];
              u[27] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[26];
              u[28] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[27];
              u[29] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[28];
              u[30] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[29];
              u[31] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[30];
              u[32] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[31];
              u[33] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[32];
              u[34] = heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[33];
              if (fwrite(u, sizeof(real_T), 34 + 1, fp) != 34 + 1) {
                rtmSetErrorStatus(heli_q8_Part4_M,
                                  "Error writing to MAT-file simout2.mat");
                return;
              }

              if (((++heli_q8_Part4_DW.ToFile_IWORK.Count) * (34 + 1))+1 >=
                  100000000) {
                (void)fprintf(stdout,
                              "*** The ToFile block will stop logging data before\n"
                              "    the simulation has ended, because it has reached\n"
                              "    the maximum number of elements (100000000)\n"
                              "    allowed in MAT-file simout2.mat.\n");
              }
            }
          }
        }
      }
    }

    /* Sum: '<S2>/Sum' incorporates:
     *  Gain: '<S1>/Back gain'
     *  Sum: '<S1>/Subtract'
     */
    rtb_Sum = (heli_q8_Part4_B.V_s + heli_q8_Part4_B.V_d) *
      heli_q8_Part4_P.Backgain_Gain;

    /* Saturate: '<S5>/Front motor: Saturation' incorporates:
     *  Gain: '<S1>/Front gain'
     *  Sum: '<S1>/Add'
     */
    rtb_FrontmotorSaturation = (heli_q8_Part4_B.V_s - heli_q8_Part4_B.V_d) *
      heli_q8_Part4_P.Frontgain_Gain;

    /* Saturate: '<S5>/Front motor: Saturation' */
    if (rtb_FrontmotorSaturation > heli_q8_Part4_P.FrontmotorSaturation_UpperSat)
    {
      /* Saturate: '<S5>/Front motor: Saturation' */
      rtb_FrontmotorSaturation = heli_q8_Part4_P.FrontmotorSaturation_UpperSat;
    } else {
      if (rtb_FrontmotorSaturation <
          heli_q8_Part4_P.FrontmotorSaturation_LowerSat) {
        /* Saturate: '<S5>/Front motor: Saturation' */
        rtb_FrontmotorSaturation = heli_q8_Part4_P.FrontmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S5>/Front motor: Saturation' */

    /* Saturate: '<S5>/Back motor: Saturation' */
    if (rtb_Sum > heli_q8_Part4_P.BackmotorSaturation_UpperSat) {
      /* Sum: '<S2>/Sum' */
      rtb_Sum = heli_q8_Part4_P.BackmotorSaturation_UpperSat;
    } else {
      if (rtb_Sum < heli_q8_Part4_P.BackmotorSaturation_LowerSat) {
        /* Sum: '<S2>/Sum' */
        rtb_Sum = heli_q8_Part4_P.BackmotorSaturation_LowerSat;
      }
    }

    /* End of Saturate: '<S5>/Back motor: Saturation' */

    /* S-Function (hil_write_analog_block): '<S5>/HIL Write Analog' */

    /* S-Function Block: heli_q8_Part4/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      heli_q8_Part4_DW.HILWriteAnalog_Buffer[0] = rtb_FrontmotorSaturation;
      heli_q8_Part4_DW.HILWriteAnalog_Buffer[1] = rtb_Sum;
      result = hil_write_analog(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILWriteAnalog_channels, 2,
        &heli_q8_Part4_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
      }
    }

    /* S-Function (stop_with_error_block): '<S6>/Stop with Call Error' */

    /* S-Function Block: heli_q8_Part4/IMU/Stop with Call Error (stop_with_error_block) */
    {
      if (rtb_StreamCall1_o3 < 0) {
        msg_get_error_messageA(NULL, rtb_StreamCall1_o3, _rt_error_message,
          sizeof(_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }
  }

  /* Integrator: '<S9>/gamma' */
  heli_q8_Part4_B.gamma = heli_q8_Part4_X.gamma_CSTATE;
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
  }

  /* Integrator: '<S9>/zeta' */
  heli_q8_Part4_B.zeta = heli_q8_Part4_X.zeta_CSTATE;
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* Gain: '<S9>/F' incorporates:
     *  SignalConversion generated from: '<S9>/F'
     */
    heli_q8_Part4_B.F[0] = 0.0;
    heli_q8_Part4_B.F[0] += heli_q8_Part4_P.F[0] *
      heli_q8_Part4_B.Joystick_gain_x;
    heli_q8_Part4_B.F[0] += heli_q8_Part4_P.F[2] *
      heli_q8_Part4_B.Joystick_gain_y;
    heli_q8_Part4_B.F[1] = 0.0;
    heli_q8_Part4_B.F[1] += heli_q8_Part4_P.F[1] *
      heli_q8_Part4_B.Joystick_gain_x;
    heli_q8_Part4_B.F[1] += heli_q8_Part4_P.F[3] *
      heli_q8_Part4_B.Joystick_gain_y;
  }

  /* SignalConversion generated from: '<S9>/K' */
  tmp_2[0] = heli_q8_Part4_B.x_posteriori[0];
  tmp_2[1] = heli_q8_Part4_B.x_posteriori[1];
  tmp_2[2] = heli_q8_Part4_B.x_posteriori[3];
  tmp_2[3] = heli_q8_Part4_B.gamma;
  tmp_2[4] = heli_q8_Part4_B.zeta;
  for (i = 0; i < 2; i++) {
    /* Sum: '<S9>/Sum1' incorporates:
     *  Gain: '<S9>/K'
     */
    N = 0.0;
    for (iy = 0; iy < 5; iy++) {
      N += heli_q8_Part4_P.K[(iy << 1) + i] * tmp_2[iy];
    }

    heli_q8_Part4_B.U[i] = heli_q8_Part4_B.F[i] - N;

    /* End of Sum: '<S9>/Sum1' */
  }

  /* Sum: '<S9>/Sum' incorporates:
   *  Constant: '<S9>/Constant'
   */
  heli_q8_Part4_B.Sum_f = heli_q8_Part4_B.U[0] + heli_q8_Part4_P.V_s0;

  /* Sum: '<S9>/Sum2' */
  heli_q8_Part4_B.Sum2 = heli_q8_Part4_B.Joystick_gain_x -
    heli_q8_Part4_B.x_posteriori[0];

  /* Sum: '<S9>/Sum3' */
  heli_q8_Part4_B.Sum3 = heli_q8_Part4_B.Joystick_gain_y -
    heli_q8_Part4_B.x_posteriori[3];

  /* Integrator: '<S11>/Integrator' */
  /* Limited  Integrator  */
  if (heli_q8_Part4_X.Integrator_CSTATE_n >= heli_q8_Part4_P.Integrator_UpperSat)
  {
    heli_q8_Part4_X.Integrator_CSTATE_n = heli_q8_Part4_P.Integrator_UpperSat;
  } else {
    if (heli_q8_Part4_X.Integrator_CSTATE_n <=
        heli_q8_Part4_P.Integrator_LowerSat) {
      heli_q8_Part4_X.Integrator_CSTATE_n = heli_q8_Part4_P.Integrator_LowerSat;
    }
  }

  /* End of Integrator: '<S11>/Integrator' */
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* Sum: '<S2>/Sum' */
    rtb_Sum = 0.0;

    /* Gain: '<S11>/K_ei' */
    heli_q8_Part4_B.K_ei = heli_q8_Part4_P.K_ei_Gain * rtb_Sum;
  }
}

/* Model update function for TID0 */
void heli_q8_Part4_update0(void)       /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    /* Update for Memory: '<S6>/Memory' */
    memcpy(&heli_q8_Part4_DW.Memory_PreviousInput[0], &heli_q8_Part4_B.Switch[0],
           10U * sizeof(real_T));

    /* Update for UnitDelay: '<S9>/Unit Delay2' */
    heli_q8_Part4_DW.UnitDelay2_DSTATE = heli_q8_Part4_B.U[0];

    /* Update for UnitDelay: '<S9>/Unit Delay' */
    heli_q8_Part4_DW.UnitDelay_DSTATE = heli_q8_Part4_B.U[1];

    /* Update for UnitDelay: '<S8>/Unit Delay1' */
    memcpy(&heli_q8_Part4_DW.UnitDelay1_DSTATE[0],
           &heli_q8_Part4_B.x_posteriori[0], 12U * sizeof(real_T));

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    memcpy(&heli_q8_Part4_DW.UnitDelay_DSTATE_m[0],
           &heli_q8_Part4_B.P_posteriori[0], 144U * sizeof(real_T));

    /* Update for UnitDelay: '<S9>/Unit Delay1' */
    heli_q8_Part4_DW.UnitDelay1_DSTATE_c = heli_q8_Part4_B.Sum_f;
  }

  if (rtmIsMajorTimeStep(heli_q8_Part4_M)) {
    rt_ertODEUpdateContinuousStates(&heli_q8_Part4_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_Part4_M->Timing.clockTick0)) {
    ++heli_q8_Part4_M->Timing.clockTickH0;
  }

  heli_q8_Part4_M->Timing.t[0] = rtsiGetSolverStopTime
    (&heli_q8_Part4_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_Part4_M->Timing.clockTick1)) {
    ++heli_q8_Part4_M->Timing.clockTickH1;
  }

  heli_q8_Part4_M->Timing.t[1] = heli_q8_Part4_M->Timing.clockTick1 *
    heli_q8_Part4_M->Timing.stepSize1 + heli_q8_Part4_M->Timing.clockTickH1 *
    heli_q8_Part4_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void heli_q8_Part4_derivatives(void)
{
  XDot_heli_q8_Part4_T *_rtXdot;
  boolean_T lsat;
  boolean_T usat;
  _rtXdot = ((XDot_heli_q8_Part4_T *) heli_q8_Part4_M->derivs);

  /* Derivatives for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_Part4_P.ElevationTransferFcn_A
    * heli_q8_Part4_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += heli_q8_Part4_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S8>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = heli_q8_Part4_B.euler_rates[0];

  /* Derivatives for Integrator: '<S8>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = heli_q8_Part4_B.euler_rates[1];

  /* Derivatives for Integrator: '<S8>/Integrator3' */
  _rtXdot->Integrator3_CSTATE = heli_q8_Part4_B.euler_rates[2];

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = heli_q8_Part4_B.euler_rates[1];

  /* Derivatives for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_Part4_P.PitchTransferFcn_A *
    heli_q8_Part4_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += heli_q8_Part4_B.PitchCounttorad;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE_p = heli_q8_Part4_B.euler_rates[0];

  /* Derivatives for TransferFcn: '<S5>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_Part4_P.TravelTransferFcn_A *
    heli_q8_Part4_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += heli_q8_Part4_B.TravelCounttorad;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  _rtXdot->Integrator2_CSTATE_j = heli_q8_Part4_B.euler_rates[0];

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  _rtXdot->Integrator3_CSTATE_b = heli_q8_Part4_B.euler_rates[1];

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = heli_q8_Part4_B.euler_rates[2];

  /* Derivatives for Integrator: '<S9>/gamma' */
  _rtXdot->gamma_CSTATE = heli_q8_Part4_B.Sum2;

  /* Derivatives for Integrator: '<S9>/zeta' */
  _rtXdot->zeta_CSTATE = heli_q8_Part4_B.Sum3;

  /* Derivatives for Integrator: '<S11>/Integrator' */
  lsat = (heli_q8_Part4_X.Integrator_CSTATE_n <=
          heli_q8_Part4_P.Integrator_LowerSat);
  usat = (heli_q8_Part4_X.Integrator_CSTATE_n >=
          heli_q8_Part4_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (heli_q8_Part4_B.K_ei > 0.0)) || (usat &&
       (heli_q8_Part4_B.K_ei < 0.0))) {
    _rtXdot->Integrator_CSTATE_n = heli_q8_Part4_B.K_ei;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE_n = 0.0;
  }

  /* End of Derivatives for Integrator: '<S11>/Integrator' */
}

/* Model output function for TID2 */
void heli_q8_Part4_output2(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_GameController_o4;
  real_T rtb_GameController_o5;

  /* S-Function (game_controller_block): '<S7>/Game Controller' */

  /* S-Function Block: heli_q8_Part4/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_Part4_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(heli_q8_Part4_DW.GameController_Controller,
        &state, &new_data);
      if (result < 0) {
        new_data = false;
      }

      rtb_GameController_o4 = state.x;
      rtb_GameController_o5 = state.y;
    } else {
      rtb_GameController_o4 = 0;
      rtb_GameController_o5 = 0;
    }
  }

  /* RateTransition: '<S7>/Rate Transition: x' */
  heli_q8_Part4_DW.RateTransitionx_Buffer0 = rtb_GameController_o4;

  /* RateTransition: '<S7>/Rate Transition: y' */
  heli_q8_Part4_DW.RateTransitiony_Buffer0 = rtb_GameController_o5;
}

/* Model update function for TID2 */
void heli_q8_Part4_update2(void)       /* Sample time: [0.01s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++heli_q8_Part4_M->Timing.clockTick2)) {
    ++heli_q8_Part4_M->Timing.clockTickH2;
  }

  heli_q8_Part4_M->Timing.t[2] = heli_q8_Part4_M->Timing.clockTick2 *
    heli_q8_Part4_M->Timing.stepSize2 + heli_q8_Part4_M->Timing.clockTickH2 *
    heli_q8_Part4_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void heli_q8_Part4_output(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_Part4_output0();
    break;

   case 2 :
    heli_q8_Part4_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void heli_q8_Part4_update(int_T tid)
{
  switch (tid) {
   case 0 :
    heli_q8_Part4_update0();
    break;

   case 2 :
    heli_q8_Part4_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void heli_q8_Part4_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_Part4/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &heli_q8_Part4_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(heli_q8_Part4_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(heli_q8_Part4_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
      return;
    }

    if ((heli_q8_Part4_P.HILInitialize_AIPStart && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &heli_q8_Part4_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = (heli_q8_Part4_P.HILInitialize_AILow);
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &heli_q8_Part4_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = heli_q8_Part4_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_AIChannels, 8U,
        &heli_q8_Part4_DW.HILInitialize_AIMinimums[0],
        &heli_q8_Part4_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_Part4_P.HILInitialize_AOPStart && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &heli_q8_Part4_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = (heli_q8_Part4_P.HILInitialize_AOLow);
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &heli_q8_Part4_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = heli_q8_Part4_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_AOChannels, 8U,
        &heli_q8_Part4_DW.HILInitialize_AOMinimums[0],
        &heli_q8_Part4_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_Part4_P.HILInitialize_AOStart && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_Part4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_Part4_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_AOChannels, 8U,
        &heli_q8_Part4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_Part4_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_Part4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_Part4_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (heli_q8_Part4_DW.HILInitialize_Card,
         heli_q8_Part4_P.HILInitialize_AOChannels, 8U,
         &heli_q8_Part4_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_Part4_P.HILInitialize_EIPStart && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &heli_q8_Part4_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = heli_q8_Part4_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (heli_q8_Part4_DW.HILInitialize_Card,
         heli_q8_Part4_P.HILInitialize_EIChannels, 8U,
         (t_encoder_quadrature_mode *)
         &heli_q8_Part4_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_Part4_P.HILInitialize_EIStart && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &heli_q8_Part4_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = heli_q8_Part4_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_EIChannels, 8U,
        &heli_q8_Part4_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_Part4_P.HILInitialize_POPStart && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_Part4_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_Part4_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_POChannels, 8U, (t_pwm_mode *)
        &heli_q8_Part4_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          heli_q8_Part4_P.HILInitialize_POChannels;
        int32_T *dw_POModeValues = &heli_q8_Part4_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE ||
              dw_POModeValues[i1] == PWM_RAW_MODE) {
            heli_q8_Part4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              (p_HILInitialize_POChannels[i1]);
            heli_q8_Part4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              heli_q8_Part4_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            heli_q8_Part4_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            heli_q8_Part4_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = heli_q8_Part4_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(heli_q8_Part4_DW.HILInitialize_Card,
          &heli_q8_Part4_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &heli_q8_Part4_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(heli_q8_Part4_DW.HILInitialize_Card,
          &heli_q8_Part4_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &heli_q8_Part4_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &heli_q8_Part4_DW.HILInitialize_POModeValues
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = heli_q8_Part4_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &heli_q8_Part4_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = heli_q8_Part4_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &heli_q8_Part4_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = heli_q8_Part4_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_POChannels, 8U,
        (t_pwm_configuration *) &heli_q8_Part4_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &heli_q8_Part4_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &heli_q8_Part4_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &heli_q8_Part4_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = heli_q8_Part4_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_Part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_Part4_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_POChannels, 8U,
        &heli_q8_Part4_DW.HILInitialize_POSortedFreqs[0],
        &heli_q8_Part4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if ((heli_q8_Part4_P.HILInitialize_POStart && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_Part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_Part4_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(heli_q8_Part4_DW.HILInitialize_Card,
        heli_q8_Part4_P.HILInitialize_POChannels, 8U,
        &heli_q8_Part4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }

    if (heli_q8_Part4_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_Part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_Part4_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (heli_q8_Part4_DW.HILInitialize_Card,
         heli_q8_Part4_P.HILInitialize_POChannels, 8U,
         &heli_q8_Part4_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S5>/HIL Read Encoder Timebase' */

  /* S-Function Block: heli_q8_Part4/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(heli_q8_Part4_DW.HILInitialize_Card,
      heli_q8_Part4_P.HILReadEncoderTimebase_SamplesI,
      heli_q8_Part4_P.HILReadEncoderTimebase_Channels, 3,
      &heli_q8_Part4_DW.HILReadEncoderTimebase_Task);
    if (result >= 0) {
      result = hil_task_set_buffer_overflow_mode
        (heli_q8_Part4_DW.HILReadEncoderTimebase_Task, (t_buffer_overflow_mode)
         (heli_q8_Part4_P.HILReadEncoderTimebase_Overflow - 1));
    }

    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
    }
  }

  /* Start for S-Function (stream_call_block): '<S6>/Stream Call1' incorporates:
   *  Constant: '<S6>/Constant'
   *  S-Function (string_constant_block): '<S6>/String Constant'
   */

  /* S-Function Block: heli_q8_Part4/IMU/Stream Call1 (stream_call_block) */
  {
    heli_q8_Part4_DW.StreamCall1_State = STREAM_CALL_STATE_NOT_CONNECTED;
    heli_q8_Part4_DW.StreamCall1_Stream = NULL;
  }

  /* Start for RateTransition: '<S7>/Rate Transition: x' */
  heli_q8_Part4_B.RateTransitionx =
    heli_q8_Part4_P.RateTransitionx_InitialConditio;

  /* Start for RateTransition: '<S7>/Rate Transition: y' */
  heli_q8_Part4_B.RateTransitiony =
    heli_q8_Part4_P.RateTransitiony_InitialConditio;

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "simout2.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(heli_q8_Part4_M, "Error creating .mat file simout2.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp, 34 + 1, 0, "ans")) {
      rtmSetErrorStatus(heli_q8_Part4_M,
                        "Error writing mat file header to file simout2.mat");
      return;
    }

    heli_q8_Part4_DW.ToFile_IWORK.Count = 0;
    heli_q8_Part4_DW.ToFile_IWORK.Decimation = -1;
    heli_q8_Part4_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for S-Function (game_controller_block): '<S7>/Game Controller' */

  /* S-Function Block: heli_q8_Part4/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_Part4_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open
        (heli_q8_Part4_P.GameController_ControllerNumber,
         heli_q8_Part4_P.GameController_BufferSize, deadzone, saturation,
         heli_q8_Part4_P.GameController_AutoCenter, 0, 1.0,
         &heli_q8_Part4_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
      }
    }
  }

  {
    int32_T i;

    /* InitializeConditions for TransferFcn: '<S5>/Elevation: Transfer Fcn' */
    heli_q8_Part4_X.ElevationTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Memory: '<S6>/Memory' */
    memcpy(&heli_q8_Part4_DW.Memory_PreviousInput[0],
           &heli_q8_Part4_P.Memory_InitialCondition[0], 10U * sizeof(real_T));

    /* InitializeConditions for Integrator: '<S8>/Integrator2' */
    heli_q8_Part4_X.Integrator2_CSTATE = heli_q8_Part4_P.Integrator2_IC;

    /* InitializeConditions for Integrator: '<S8>/Integrator1' */
    heli_q8_Part4_X.Integrator1_CSTATE = heli_q8_Part4_P.Integrator1_IC;

    /* InitializeConditions for Integrator: '<S8>/Integrator3' */
    heli_q8_Part4_X.Integrator3_CSTATE = heli_q8_Part4_P.Integrator3_IC;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay2' */
    heli_q8_Part4_DW.UnitDelay2_DSTATE =
      heli_q8_Part4_P.UnitDelay2_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
    heli_q8_Part4_DW.UnitDelay_DSTATE =
      heli_q8_Part4_P.UnitDelay_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */
    for (i = 0; i < 12; i++) {
      heli_q8_Part4_DW.UnitDelay1_DSTATE[i] =
        heli_q8_Part4_P.UnitDelay1_InitialCondition;
    }

    /* End of InitializeConditions for UnitDelay: '<S8>/Unit Delay1' */

    /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
    for (i = 0; i < 144; i++) {
      heli_q8_Part4_DW.UnitDelay_DSTATE_m[i] =
        heli_q8_Part4_P.UnitDelay_InitialCondition_p;
    }

    /* End of InitializeConditions for UnitDelay: '<S8>/Unit Delay' */

    /* InitializeConditions for Integrator: '<Root>/Integrator' */
    heli_q8_Part4_X.Integrator_CSTATE = heli_q8_Part4_P.Integrator_IC;

    /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
    heli_q8_Part4_DW.UnitDelay1_DSTATE_c =
      heli_q8_Part4_P.UnitDelay1_InitialCondition_i;

    /* InitializeConditions for TransferFcn: '<S5>/Pitch: Transfer Fcn' */
    heli_q8_Part4_X.PitchTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for Integrator: '<Root>/Integrator1' */
    heli_q8_Part4_X.Integrator1_CSTATE_p = heli_q8_Part4_P.Integrator1_IC_c;

    /* InitializeConditions for TransferFcn: '<S5>/Travel: Transfer Fcn' */
    heli_q8_Part4_X.TravelTransferFcn_CSTATE = 0.0;

    /* InitializeConditions for RateTransition: '<S7>/Rate Transition: x' */
    heli_q8_Part4_DW.RateTransitionx_Buffer0 =
      heli_q8_Part4_P.RateTransitionx_InitialConditio;

    /* InitializeConditions for RateTransition: '<S7>/Rate Transition: y' */
    heli_q8_Part4_DW.RateTransitiony_Buffer0 =
      heli_q8_Part4_P.RateTransitiony_InitialConditio;

    /* InitializeConditions for Integrator: '<Root>/Integrator2' */
    heli_q8_Part4_X.Integrator2_CSTATE_j = heli_q8_Part4_P.Integrator2_IC_h;

    /* InitializeConditions for Integrator: '<Root>/Integrator3' */
    heli_q8_Part4_X.Integrator3_CSTATE_b = heli_q8_Part4_P.Integrator3_IC_o;

    /* InitializeConditions for Integrator: '<Root>/Integrator4' */
    heli_q8_Part4_X.Integrator4_CSTATE = heli_q8_Part4_P.Integrator4_IC;

    /* InitializeConditions for Integrator: '<S9>/gamma' */
    heli_q8_Part4_X.gamma_CSTATE = heli_q8_Part4_P.gamma_IC;

    /* InitializeConditions for Integrator: '<S9>/zeta' */
    heli_q8_Part4_X.zeta_CSTATE = heli_q8_Part4_P.zeta_IC;

    /* InitializeConditions for Integrator: '<S11>/Integrator' */
    heli_q8_Part4_X.Integrator_CSTATE_n = heli_q8_Part4_P.Integrator_IC_k;
  }
}

/* Model terminate function */
void heli_q8_Part4_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: heli_q8_Part4/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(heli_q8_Part4_DW.HILInitialize_Card);
    hil_monitor_stop_all(heli_q8_Part4_DW.HILInitialize_Card);
    is_switching = false;
    if ((heli_q8_Part4_P.HILInitialize_AOTerminate && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &heli_q8_Part4_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = heli_q8_Part4_P.HILInitialize_AOFinal;
        }
      }

      num_final_analog_outputs = 8U;
    } else {
      num_final_analog_outputs = 0;
    }

    if ((heli_q8_Part4_P.HILInitialize_POTerminate && !is_switching) ||
        (heli_q8_Part4_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &heli_q8_Part4_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = heli_q8_Part4_P.HILInitialize_POFinal;
        }
      }

      num_final_pwm_outputs = 8U;
    } else {
      num_final_pwm_outputs = 0;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(heli_q8_Part4_DW.HILInitialize_Card
                         , heli_q8_Part4_P.HILInitialize_AOChannels,
                         num_final_analog_outputs
                         , heli_q8_Part4_P.HILInitialize_POChannels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &heli_q8_Part4_DW.HILInitialize_AOVoltages[0]
                         , &heli_q8_Part4_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(heli_q8_Part4_DW.HILInitialize_Card,
            heli_q8_Part4_P.HILInitialize_AOChannels, num_final_analog_outputs,
            &heli_q8_Part4_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(heli_q8_Part4_DW.HILInitialize_Card,
            heli_q8_Part4_P.HILInitialize_POChannels, num_final_pwm_outputs,
            &heli_q8_Part4_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(heli_q8_Part4_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(heli_q8_Part4_DW.HILInitialize_Card);
    hil_monitor_delete_all(heli_q8_Part4_DW.HILInitialize_Card);
    hil_close(heli_q8_Part4_DW.HILInitialize_Card);
    heli_q8_Part4_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (stream_call_block): '<S6>/Stream Call1' incorporates:
   *  Constant: '<S6>/Constant'
   *  S-Function (string_constant_block): '<S6>/String Constant'
   */

  /* S-Function Block: heli_q8_Part4/IMU/Stream Call1 (stream_call_block) */
  {
    if (heli_q8_Part4_DW.StreamCall1_Stream != NULL) {
      stream_close(heli_q8_Part4_DW.StreamCall1_Stream);
      heli_q8_Part4_DW.StreamCall1_Stream = NULL;
    }
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) heli_q8_Part4_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "simout2.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_Part4_M, "Error closing MAT-file simout2.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(heli_q8_Part4_M,
                          "Error reopening MAT-file simout2.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 34 + 1, heli_q8_Part4_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(heli_q8_Part4_M,
                          "Error writing header for ans to MAT-file simout2.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(heli_q8_Part4_M, "Error closing MAT-file simout2.mat");
        return;
      }

      heli_q8_Part4_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S7>/Game Controller' */

  /* S-Function Block: heli_q8_Part4/Joystick/Game Controller (game_controller_block) */
  {
    if (heli_q8_Part4_P.GameController_Enabled) {
      game_controller_close(heli_q8_Part4_DW.GameController_Controller);
      heli_q8_Part4_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_Part4_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  heli_q8_Part4_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  heli_q8_Part4_initialize();
}

void MdlTerminate(void)
{
  heli_q8_Part4_terminate();
}

/* Registration function */
RT_MODEL_heli_q8_Part4_T *heli_q8_Part4(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  heli_q8_Part4_P.Integrator_UpperSat = rtInf;
  heli_q8_Part4_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)heli_q8_Part4_M, 0,
                sizeof(RT_MODEL_heli_q8_Part4_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&heli_q8_Part4_M->solverInfo,
                          &heli_q8_Part4_M->Timing.simTimeStep);
    rtsiSetTPtr(&heli_q8_Part4_M->solverInfo, &rtmGetTPtr(heli_q8_Part4_M));
    rtsiSetStepSizePtr(&heli_q8_Part4_M->solverInfo,
                       &heli_q8_Part4_M->Timing.stepSize0);
    rtsiSetdXPtr(&heli_q8_Part4_M->solverInfo, &heli_q8_Part4_M->derivs);
    rtsiSetContStatesPtr(&heli_q8_Part4_M->solverInfo, (real_T **)
                         &heli_q8_Part4_M->contStates);
    rtsiSetNumContStatesPtr(&heli_q8_Part4_M->solverInfo,
      &heli_q8_Part4_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&heli_q8_Part4_M->solverInfo,
      &heli_q8_Part4_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&heli_q8_Part4_M->solverInfo,
      &heli_q8_Part4_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&heli_q8_Part4_M->solverInfo,
      &heli_q8_Part4_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&heli_q8_Part4_M->solverInfo, (&rtmGetErrorStatus
      (heli_q8_Part4_M)));
    rtsiSetRTModelPtr(&heli_q8_Part4_M->solverInfo, heli_q8_Part4_M);
  }

  rtsiSetSimTimeStep(&heli_q8_Part4_M->solverInfo, MAJOR_TIME_STEP);
  heli_q8_Part4_M->intgData.f[0] = heli_q8_Part4_M->odeF[0];
  heli_q8_Part4_M->contStates = ((real_T *) &heli_q8_Part4_X);
  rtsiSetSolverData(&heli_q8_Part4_M->solverInfo, (void *)
                    &heli_q8_Part4_M->intgData);
  rtsiSetSolverName(&heli_q8_Part4_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = heli_q8_Part4_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    heli_q8_Part4_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    heli_q8_Part4_M->Timing.sampleTimes =
      (&heli_q8_Part4_M->Timing.sampleTimesArray[0]);
    heli_q8_Part4_M->Timing.offsetTimes =
      (&heli_q8_Part4_M->Timing.offsetTimesArray[0]);

    /* task periods */
    heli_q8_Part4_M->Timing.sampleTimes[0] = (0.0);
    heli_q8_Part4_M->Timing.sampleTimes[1] = (0.002);
    heli_q8_Part4_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    heli_q8_Part4_M->Timing.offsetTimes[0] = (0.0);
    heli_q8_Part4_M->Timing.offsetTimes[1] = (0.0);
    heli_q8_Part4_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(heli_q8_Part4_M, &heli_q8_Part4_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = heli_q8_Part4_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = heli_q8_Part4_M->Timing.perTaskSampleHitsArray;
    heli_q8_Part4_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    heli_q8_Part4_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(heli_q8_Part4_M, 100.0);
  heli_q8_Part4_M->Timing.stepSize0 = 0.002;
  heli_q8_Part4_M->Timing.stepSize1 = 0.002;
  heli_q8_Part4_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  heli_q8_Part4_M->Sizes.checksums[0] = (194335875U);
  heli_q8_Part4_M->Sizes.checksums[1] = (3640651357U);
  heli_q8_Part4_M->Sizes.checksums[2] = (3350765161U);
  heli_q8_Part4_M->Sizes.checksums[3] = (3669214109U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    heli_q8_Part4_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(heli_q8_Part4_M->extModeInfo,
      &heli_q8_Part4_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(heli_q8_Part4_M->extModeInfo,
                        heli_q8_Part4_M->Sizes.checksums);
    rteiSetTPtr(heli_q8_Part4_M->extModeInfo, rtmGetTPtr(heli_q8_Part4_M));
  }

  heli_q8_Part4_M->solverInfoPtr = (&heli_q8_Part4_M->solverInfo);
  heli_q8_Part4_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&heli_q8_Part4_M->solverInfo, 0.002);
  rtsiSetSolverMode(&heli_q8_Part4_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  heli_q8_Part4_M->blockIO = ((void *) &heli_q8_Part4_B);
  (void) memset(((void *) &heli_q8_Part4_B), 0,
                sizeof(B_heli_q8_Part4_T));

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_Part4_B.Switch[i] = 0.0;
    }

    for (i = 0; i < 34; i++) {
      heli_q8_Part4_B.TmpSignalConversionAtToFileInpo[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      heli_q8_Part4_B.x_priori[i] = 0.0;
    }

    for (i = 0; i < 144; i++) {
      heli_q8_Part4_B.P_priori[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      heli_q8_Part4_B.x_posteriori[i] = 0.0;
    }

    for (i = 0; i < 144; i++) {
      heli_q8_Part4_B.P_posteriori[i] = 0.0;
    }

    heli_q8_Part4_B.ElevationCounttorad = 0.0;
    heli_q8_Part4_B.ElevationTransferFcn = 0.0;
    heli_q8_Part4_B.Gain1[0] = 0.0;
    heli_q8_Part4_B.Gain1[1] = 0.0;
    heli_q8_Part4_B.Gain1[2] = 0.0;
    heli_q8_Part4_B.Gain2[0] = 0.0;
    heli_q8_Part4_B.Gain2[1] = 0.0;
    heli_q8_Part4_B.Gain2[2] = 0.0;
    heli_q8_Part4_B.Sum = 0.0;
    heli_q8_Part4_B.p = 0.0;
    heli_q8_Part4_B.e = 0.0;
    heli_q8_Part4_B.lambda = 0.0;
    heli_q8_Part4_B.V_s_tilde = 0.0;
    heli_q8_Part4_B.V_d = 0.0;
    heli_q8_Part4_B.Sum_n = 0.0;
    heli_q8_Part4_B.Gyro_e = 0.0;
    heli_q8_Part4_B.V_s = 0.0;
    heli_q8_Part4_B.PitchCounttorad = 0.0;
    heli_q8_Part4_B.PitchTransferFcn = 0.0;
    heli_q8_Part4_B.Gyro_p = 0.0;
    heli_q8_Part4_B.TravelCounttorad = 0.0;
    heli_q8_Part4_B.TravelTransferFcn = 0.0;
    heli_q8_Part4_B.RateTransitionx = 0.0;
    heli_q8_Part4_B.Joystick_gain_x = 0.0;
    heli_q8_Part4_B.RateTransitiony = 0.0;
    heli_q8_Part4_B.Joystick_gain_y = 0.0;
    heli_q8_Part4_B.Integrator2 = 0.0;
    heli_q8_Part4_B.Integrator3 = 0.0;
    heli_q8_Part4_B.Integrator4 = 0.0;
    heli_q8_Part4_B.gamma = 0.0;
    heli_q8_Part4_B.zeta = 0.0;
    heli_q8_Part4_B.F[0] = 0.0;
    heli_q8_Part4_B.F[1] = 0.0;
    heli_q8_Part4_B.U[0] = 0.0;
    heli_q8_Part4_B.U[1] = 0.0;
    heli_q8_Part4_B.Sum_f = 0.0;
    heli_q8_Part4_B.Sum2 = 0.0;
    heli_q8_Part4_B.Sum3 = 0.0;
    heli_q8_Part4_B.K_ei = 0.0;
    heli_q8_Part4_B.p_a = 0.0;
    heli_q8_Part4_B.euler_rates[0] = 0.0;
    heli_q8_Part4_B.euler_rates[1] = 0.0;
    heli_q8_Part4_B.euler_rates[2] = 0.0;
  }

  /* parameters */
  heli_q8_Part4_M->defaultParam = ((real_T *)&heli_q8_Part4_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &heli_q8_Part4_X;
    heli_q8_Part4_M->contStates = (x);
    (void) memset((void *)&heli_q8_Part4_X, 0,
                  sizeof(X_heli_q8_Part4_T));
  }

  /* states (dwork) */
  heli_q8_Part4_M->dwork = ((void *) &heli_q8_Part4_DW);
  (void) memset((void *)&heli_q8_Part4_DW, 0,
                sizeof(DW_heli_q8_Part4_T));
  heli_q8_Part4_DW.UnitDelay2_DSTATE = 0.0;
  heli_q8_Part4_DW.UnitDelay_DSTATE = 0.0;

  {
    int32_T i;
    for (i = 0; i < 12; i++) {
      heli_q8_Part4_DW.UnitDelay1_DSTATE[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 144; i++) {
      heli_q8_Part4_DW.UnitDelay_DSTATE_m[i] = 0.0;
    }
  }

  heli_q8_Part4_DW.UnitDelay1_DSTATE_c = 0.0;

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      heli_q8_Part4_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      heli_q8_Part4_DW.Memory_PreviousInput[i] = 0.0;
    }
  }

  heli_q8_Part4_DW.RateTransitionx_Buffer0 = 0.0;
  heli_q8_Part4_DW.RateTransitiony_Buffer0 = 0.0;
  heli_q8_Part4_DW.HILWriteAnalog_Buffer[0] = 0.0;
  heli_q8_Part4_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    heli_q8_Part4_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 25;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  heli_q8_Part4_M->Sizes.numContStates = (14);/* Number of continuous states */
  heli_q8_Part4_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  heli_q8_Part4_M->Sizes.numY = (0);   /* Number of model outputs */
  heli_q8_Part4_M->Sizes.numU = (0);   /* Number of model inputs */
  heli_q8_Part4_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  heli_q8_Part4_M->Sizes.numSampTimes = (3);/* Number of sample times */
  heli_q8_Part4_M->Sizes.numBlocks = (123);/* Number of blocks */
  heli_q8_Part4_M->Sizes.numBlockIO = (42);/* Number of block outputs */
  heli_q8_Part4_M->Sizes.numBlockPrms = (1219);/* Sum of parameter "widths" */
  return heli_q8_Part4_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
