/****************************************************************************
 *                                niScope                                   *
 *--------------------------------------------------------------------------*
 *      Copyright (c) National Instruments 2004.  All Rights Reserved.      *
 *--------------------------------------------------------------------------*
 *                                                                          *
 * Title:    niScope.h                                                      *
 * Purpose:  niScope                                                        *
 *           instrument driver declarations.                                *
 *                                                                          *
 ****************************************************************************/

#ifndef __NISCOPE_HEADER
#define __NISCOPE_HEADER

#include "ivi.h"
#include "IviScope.h"
#include <string.h>


#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif
/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NISCOPE_MAJOR_VERSION         3     /* Instrument driver major version */
#define NISCOPE_MINOR_VERSION         800   /* Instrument driver minor version */

/****************************************************************************
 *---------------------- Useful Macros and Defines -------------------------*
 ****************************************************************************/
/* Maximum length of a niscope function name */
#define MAX_FUNCTION_NAME_SIZE      55
/* Maximum size of an error message returned from niScope_errorHandler */
#define MAX_ERROR_DESCRIPTION       (IVI_MAX_MESSAGE_BUF_SIZE * 2 + MAX_FUNCTION_NAME_SIZE + 75)

/* This macro handles all errors and warnings returned from NI SCOPE.
   It requires two variables be declared:
      ViStatus error
      ViChar errorSource[MAX_FUNCTION_NAME_SIZE]
   and a line marked "Error:" that marks the beginning of cleanup code.
   If a function returns an error code, "error" is set to the error code
   and "errorSource" is set to the calling function's name, and execution
   skips to the "Error:" line.  Otherwise, "error" and "errorSource" store
   the location of warnings that occur, and execution proceeds normally.    */
#define handleErr(fCall) { int code = (fCall);                      \
        if (code < 0) {                                             \
           error = code;                                            \
           strncpy( errorSource, #fCall, MAX_FUNCTION_NAME_SIZE );  \
           errorSource[MAX_FUNCTION_NAME_SIZE - 1] = '\0';          \
           strcpy( errorSource, strtok( errorSource, " (") );       \
           goto Error; }                                            \
        else if ((error == 0) && (code > 0)) {                      \
           error = code;                                            \
           strncpy( errorSource, #fCall, MAX_FUNCTION_NAME_SIZE );  \
           errorSource[MAX_FUNCTION_NAME_SIZE - 1] = '\0';          \
           strcpy( errorSource, strtok( errorSource, " (") ); } }

/* Use this macro to set a customized error elaboration for a particular function
   call.  The overwrite parameter in Ivi_SetErrorInfo is set to VI_TRUE so this
   macro will overwrite the default error elaboration that is on the error queue. */
#define niScopeCheckParm(fCall, paramPosition, errorElaboration) \
        if (error = (fCall), (error = (error < 0) ? (error) : VI_SUCCESS)) \
           {Ivi_SetErrorInfo(vi, VI_TRUE, error, Ivi_ParamPositionError(paramPosition), \
           errorElaboration); goto Error;} else

/* Use this macro in the same manner as above but for cases where it is not a user
   set parameter that is in error
   Let errors over-ride warnings, but if there's no error or warning don't clear the
   previous warning!  If there are TWO warnings, then the new one will take precedence. */
#define niScopeCheckErrElab(fCall,elab)                              \
   {  int tempErrorForElab = (fCall);                                \
      if (tempErrorForElab < 0)                                      \
      {                                                              \
         Ivi_SetErrorInfo(vi, VI_TRUE, tempErrorForElab, 0, elab);   \
         error = tempErrorForElab;                                   \
         goto Error;                                                 \
      }                                                              \
      else if (tempErrorForElab > 0)                                 \
      {                                                              \
         Ivi_SetErrorInfo(vi, VI_TRUE, tempErrorForElab, 0, elab);   \
         error = tempErrorForElab;                                   \
      }                                                              \
   }

/* WARNING: These are overrides of some of the IVI macros to preserve warnings.
   These changes should ONLY affect the way warnings are dealt with.  However,
   there are other functions that may erase warning messages. */
#ifdef viCheckErrElab
#undef viCheckErrElab
#define viCheckErrElab(fCall, elab)                            \
   {                                                           \
      int code = (fCall);                                      \
      if (code < 0)                                            \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, elab);       \
         goto Error;                                           \
      }                                                        \
      if ((error == 0) && (code > 0))                          \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, elab);       \
      }                                                        \
   }
#endif


/* checkErr shouldn't ignore warning messages, so this is an override of the IVI version. */
#ifdef checkErr
#undef checkErr
#define checkErr(fCall)                                        \
   {  int code = (fCall);                                      \
      if (code < 0)                                            \
      {                                                        \
         error = code;                                         \
         goto Error;                                           \
      }                                                        \
      else if ((error == 0) && (code > 0))                     \
      {                                                        \
         error = code;                                         \
      }                                                        \
   }
#endif


#ifdef viCheckErr
#undef viCheckErr
#define viCheckErr(fCall)                                      \
   {                                                           \
      int code = (fCall);                                      \
      if (code < 0)                                            \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL);    \
         goto Error;                                           \
      }                                                        \
      if ((error == 0) && (code > 0))                          \
      {                                                        \
         error = code;                                         \
         Ivi_SetErrorInfo(vi, VI_FALSE, error, 0, VI_NULL);    \
      }                                                        \
   }
#endif


/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/
/*- NOTE: multi channel denotes an attribute specified on a per channel basis -*/

/*--- IVI Inherent Instrument Attributes --------------------------------------*/

      /* User Options ---------------------------------------------------------*/
#define NISCOPE_ATTR_CACHE                                        /* ViBoolean */   IVI_ATTR_CACHE
#define NISCOPE_ATTR_RANGE_CHECK                                  /* ViBoolean */   IVI_ATTR_RANGE_CHECK
#define NISCOPE_ATTR_QUERY_INSTRUMENT_STATUS                      /* ViBoolean */   IVI_ATTR_QUERY_INSTRUMENT_STATUS
#define NISCOPE_ATTR_RECORD_COERCIONS                             /* ViBoolean */   IVI_ATTR_RECORD_COERCIONS
#define NISCOPE_ATTR_SIMULATE                                     /* ViBoolean */   IVI_ATTR_SIMULATE
#define NISCOPE_ATTR_INTERCHANGE_CHECK                            /* ViBoolean */   IVI_ATTR_INTERCHANGE_CHECK

      /*- Instrument Capabilities, Read Only ----------------------------------*/
#define NISCOPE_ATTR_CHANNEL_COUNT                                /* ViInt32   */   IVI_ATTR_CHANNEL_COUNT
#define NISCOPE_ATTR_SUPPORTED_INSTRUMENT_MODELS                  /* ViString  */   IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS
#define NISCOPE_ATTR_GROUP_CAPABILITIES                           /* ViString  */   IVI_ATTR_GROUP_CAPABILITIES

      /*- Instrument Version and Identification, Read-only --------------------*/
#define NISCOPE_ATTR_SPECIFIC_DRIVER_DESCRIPTION                  /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION
#define NISCOPE_ATTR_SPECIFIC_DRIVER_PREFIX                       /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_PREFIX
#define NISCOPE_ATTR_SPECIFIC_DRIVER_VENDOR                       /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_VENDOR
#define NISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION     /* ViInt32   */   IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION
#define NISCOPE_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION     /* ViInt32   */   IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION
#define NISCOPE_ATTR_SPECIFIC_DRIVER_REVISION                     /* ViString  */   IVI_ATTR_SPECIFIC_DRIVER_REVISION
#define NISCOPE_ATTR_INSTRUMENT_MANUFACTURER                      /* ViString  */   IVI_ATTR_INSTRUMENT_MANUFACTURER
#define NISCOPE_ATTR_INSTRUMENT_MODEL                             /* ViString  */   IVI_ATTR_INSTRUMENT_MODEL
#define NISCOPE_ATTR_INSTRUMENT_FIRMWARE_REVISION                 /* ViString  */   IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION

      /*- Advanced Session Information, read-only -----------------------------*/
#define NISCOPE_ATTR_IO_RESOURCE_DESCRIPTOR                       /* ViString  */   IVI_ATTR_IO_RESOURCE_DESCRIPTOR
#define NISCOPE_ATTR_LOGICAL_NAME                                 /* ViString  */   IVI_ATTR_LOGICAL_NAME
#define NISCOPE_ATTR_DRIVER_SETUP                                 /* ViString  */   IVI_ATTR_DRIVER_SETUP


/*--- IVI Instrument-Specific Attributes --------------------------------*/

      /*- Acquisition Subsystem -*/
#define NISCOPE_ATTR_ACQUISITION_TYPE         IVISCOPE_ATTR_ACQUISITION_TYPE         /* ViInt32              */
#define NISCOPE_ATTR_SAMPLE_MODE              IVISCOPE_ATTR_SAMPLE_MODE              /* ViInt32,   read-only */

      /*- Vertical Subsystem -*/
#define NISCOPE_ATTR_CHANNEL_ENABLED          IVISCOPE_ATTR_CHANNEL_ENABLED          /* ViBoolean, multi channel        */
#define NISCOPE_ATTR_PROBE_ATTENUATION        IVISCOPE_ATTR_PROBE_ATTENUATION        /* ViReal64,  multi channel        */
#define NISCOPE_ATTR_VERTICAL_RANGE           IVISCOPE_ATTR_VERTICAL_RANGE           /* ViReal64,  multi channel, volts */
#define NISCOPE_ATTR_VERTICAL_OFFSET          IVISCOPE_ATTR_VERTICAL_OFFSET          /* ViReal64,  multi channel, volts */
#define NISCOPE_ATTR_VERTICAL_COUPLING        IVISCOPE_ATTR_VERTICAL_COUPLING        /* ViInt32,   multi channel        */
#define NISCOPE_ATTR_MAX_INPUT_FREQUENCY      IVISCOPE_ATTR_MAX_INPUT_FREQUENCY      /* ViReal64,  multi channel, hertz */
#define NISCOPE_ATTR_INPUT_IMPEDANCE          IVISCOPE_ATTR_INPUT_IMPEDANCE          /* ViReal64,  multi channel, ohms  */

      /*- Horizontal Subsystem -*/
#define NISCOPE_ATTR_HORZ_TIME_PER_RECORD     IVISCOPE_ATTR_HORZ_TIME_PER_RECORD     /* ViReal64,  seconds                         */
#define NISCOPE_ATTR_ACQUISITION_START_TIME   IVISCOPE_ATTR_ACQUISITION_START_TIME   /* ViReal64,  seconds                         */
#define NISCOPE_ATTR_HORZ_MIN_NUM_PTS         IVISCOPE_ATTR_HORZ_MIN_NUM_PTS         /* ViInt32                                    */
#define NISCOPE_ATTR_HORZ_RECORD_LENGTH       IVISCOPE_ATTR_HORZ_RECORD_LENGTH       /* ViInt32,   read-only, actual record length */
#define NISCOPE_ATTR_HORZ_RECORD_REF_POSITION (IVI_CLASS_PUBLIC_ATTR_BASE  + 11L)    /* ViReal64,  percentage of record length     */
#define NISCOPE_ATTR_HORZ_SAMPLE_RATE         IVISCOPE_ATTR_HORZ_SAMPLE_RATE         /* ViReal64,  read-only, actual sample rate   */

      /*- Trigger Subsystem -*/
#define NISCOPE_ATTR_TRIGGER_TYPE             IVISCOPE_ATTR_TRIGGER_TYPE             /* ViInt32            */
#define NISCOPE_ATTR_TRIGGER_SOURCE           IVISCOPE_ATTR_TRIGGER_SOURCE           /* ViString           */
#define NISCOPE_ATTR_TRIGGER_LEVEL            IVISCOPE_ATTR_TRIGGER_LEVEL            /* ViReal64,  volts   */
#define NISCOPE_ATTR_TRIGGER_DELAY_TIME       (IVI_CLASS_PUBLIC_ATTR_BASE  + 15L)    /* ViReal64,  seconds */
#define NISCOPE_ATTR_TRIGGER_HOLDOFF          IVISCOPE_ATTR_TRIGGER_HOLDOFF          /* ViReal64,  seconds */
#define NISCOPE_ATTR_TRIGGER_COUPLING         IVISCOPE_ATTR_TRIGGER_COUPLING         /* ViInt32            */
#define NISCOPE_ATTR_TRIGGER_SLOPE            IVISCOPE_ATTR_TRIGGER_SLOPE            /* ViInt32            */

      /*- TVTrigger Extension -*/
#define NISCOPE_ATTR_TV_TRIGGER_EVENT         IVISCOPE_ATTR_TV_TRIGGER_EVENT         /* ViInt32            */
#define NISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER   IVISCOPE_ATTR_TV_TRIGGER_LINE_NUMBER   /* ViInt32            */
#define NISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT IVISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT /* ViInt32            */
#define NISCOPE_ATTR_TV_TRIGGER_POLARITY      IVISCOPE_ATTR_TV_TRIGGER_POLARITY      /* ViInt32            */

      /*- Measurement Functions -*/
#define NISCOPE_ATTR_MEAS_HIGH_REF            IVISCOPE_ATTR_MEAS_HIGH_REF            /* ViReal64           */
#define NISCOPE_ATTR_MEAS_LOW_REF             IVISCOPE_ATTR_MEAS_LOW_REF             /* ViReal64           */
#define NISCOPE_ATTR_MEAS_MID_REF             IVISCOPE_ATTR_MEAS_MID_REF             /* ViReal64           */

      /*--- Additional Instrument-Specific Attributes ----------------------------*/
#define NISCOPE_ATTR_HORZ_NUM_RECORDS          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)   /* ViInt32              */
#define NISCOPE_ATTR_INPUT_CLOCK_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)   /* ViString             */
#define NISCOPE_ATTR_OUTPUT_CLOCK_SOURCE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3L)   /* ViString             */
#define NISCOPE_ATTR_HORZ_ENFORCE_REALTIME     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)   /* ViBoolean            */
#define NISCOPE_ATTR_BINARY_SAMPLE_WIDTH       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)   /* ViInt32              */
#define NISCOPE_ATTR_TRIGGER_HYSTERESIS        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6L)   /* ViReal64,  volts     */
#define NISCOPE_ATTR_CLOCK_SYNC_PULSE_SOURCE   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)   /* ViString             */
#define NISCOPE_ATTR_MASTER_ENABLE             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)   /* ViBoolean            */
#define NISCOPE_ATTR_MIN_SAMPLE_RATE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)   /* ViReal64             */
#define NISCOPE_ATTR_TRIGGER_WINDOW_MODE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)  /* ViInt32              */
#define NISCOPE_ATTR_TRIGGER_WINDOW_LOW_LEVEL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)  /* ViReal64             */
#define NISCOPE_ATTR_TRIGGER_WINDOW_HIGH_LEVEL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)  /* ViReal64             */
#define NISCOPE_ATTR_MEAS_REF_LEVEL_UNITS      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)  /* ViInt32              */
#define NISCOPE_ATTR_MEAS_OTHER_CHANNEL        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 18L)  /* ViString             */
#define NISCOPE_ATTR_MEAS_HYSTERESIS_PERCENT   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)  /* ViReal64             */
#define NISCOPE_ATTR_MEAS_LAST_ACQ_HISTOGRAM_SIZE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)    /* ViInt32    */
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_SIZE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 21L)    /* ViInt32    */
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_LOW_VOLTS  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_VOLTAGE_HISTOGRAM_HIGH_VOLTS (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_SIZE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 24L)    /* ViInt32    */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_LOW_VOLTS     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 25L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_HIGH_VOLTS    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 26L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_LOW_TIME      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 27L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_TIME_HISTOGRAM_HIGH_TIME     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 28L)    /* ViReal64   */
#define NISCOPE_ATTR_MEAS_POLYNOMIAL_INTERPOLATION_ORDER (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)  /* ViInt32    */
#define NISCOPE_ATTR_MEAS_INTERPOLATION_SAMPLING_FACTOR  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_CUTOFF_FREQ             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 31L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_CENTER_FREQ             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_RIPPLE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)  /* ViReal64   */
#define NISCOPE_ATTR_MEAS_FILTER_TRANSIENT_WAVEFORM_PERCENT (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L) /* ViReal64 */
#define NISCOPE_ATTR_MEAS_FILTER_TYPE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_FILTER_ORDER         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_FILTER_TAPS          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_CHAN_LOW_REF_LEVEL   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_CHAN_MID_REF_LEVEL   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_CHAN_HIGH_REF_LEVEL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 40L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_FILTER_WIDTH         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_FIR_FILTER_WINDOW    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)  /* ViInt32  */
#define NISCOPE_ATTR_MEAS_ARRAY_GAIN           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 43L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_ARRAY_OFFSET         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 44L)  /* ViReal64 */
#define NISCOPE_ATTR_MEAS_PERCENTAGE_METHOD    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)  /* ViInt32  */

   /*- Advanced synchronization attributes -*/
#define NISCOPE_ATTR_SLAVE_TRIGGER_DELAY              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 46L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_TO_STAR_DELAY            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 47L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_TO_RTSI_DELAY            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 48L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_TO_PFI_DELAY             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 49L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_FROM_STAR_DELAY          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 50L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_FROM_RTSI_DELAY          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 51L) /* ViReal64 */
#define NISCOPE_ATTR_TRIGGER_FROM_PFI_DELAY           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 52L) /* ViReal64 */
#define NISCOPE_ATTR_ACQ_ARM_SOURCE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 53L) /* ViString */
#define NISCOPE_ATTR_RECORD_ARM_SOURCE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 65L) /* ViString */
#define NISCOPE_ATTR_IS_PROBE_COMP_ON                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 66L)  /* ViBoolean */
#define NISCOPE_ATTR_USE_SPEC_INITIAL_X               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 67L)  /* ViBoolean */
#define NISCOPE_ATTR_ALLOW_MORE_RECORDS_THAN_MEMORY   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 68L)  /* ViBoolean */
#define NISCOPE_ATTR_ONBOARD_MEMORY_SIZE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 69L)  /* ViInt32   */
#define NISCOPE_ATTR_RIS_NUM_AVERAGES                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 70L)  /* ViInt32   */
#define NISCOPE_ATTR_RIS_METHOD                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 71L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_INTERLEAVED_DATA           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 72L)  /* ViBoolean */
#define NISCOPE_ATTR_MAX_REAL_TIME_SAMPLING_RATE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 73L)  /* ViReal64  */
#define NISCOPE_ATTR_MAX_RIS_RATE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 74L)  /* ViReal64  */
#define NISCOPE_ATTR_TRIGGER_IMPEDANCE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 75L)  /* ViReal64  */
#define NISCOPE_ATTR_DEVICE_NUMBER                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 76L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_RELATIVE_TO                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_OFFSET                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 78L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_RECORD_NUMBER              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 79L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_NUM_RECORDS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 80L)  /* ViInt32   */
#define NISCOPE_ATTR_FETCH_MEAS_NUM_SAMPLES           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 81L)  /* ViInt32   */
#define NISCOPE_ATTR_POINTS_DONE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 82L)  /* ViReal64  */
#define NISCOPE_ATTR_RECORDS_DONE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 83L)  /* ViInt32   */
#define NISCOPE_ATTR_BACKLOG                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 84L)  /* ViReal64  */
#define NISCOPE_ATTR_5102_ADJUST_PRETRIGGER_SAMPLES   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 85L)  /* ViBoolean */
#define NISCOPE_ATTR_POLL_INTERVAL                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 100L) /* ViInt32   */

   /*- Attributes for the 5620 Digital Down Converter -*/
#define NISCOPE_ATTR_DDC_NCO_FREQUENCY                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1000)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_NCO_PHASE                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1001)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_ENABLE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1003)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_CIC_DECIMATION                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1010)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_CIC_SHIFT_GAIN                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1011)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_ENABLED           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1020)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_DECIMATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1021)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_SYMMETRY      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1022)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_SYMMETRY_TYPE (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1023)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_NUM_TAPS      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1024)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_DELAY             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1025)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_INPUT_SOURCE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1026)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DISCRIMINATOR_PHASE_MULTIPLIER  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1027)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_DECIMATION                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1030)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_SYMMETRY                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1031)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_SYMMETRY_TYPE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1032)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_NUM_TAPS                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1033)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_PFIR_REAL_OR_COMPLEX            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1034)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_UPPER_GAIN_LIMIT            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1040)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_AGC_LOWER_GAIN_LIMIT            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1041)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_0_EXPONENT        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1042)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_0_MANTISSA        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1043)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_1_EXPONENT        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1044)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_LOOP_GAIN_1_MANTISSA        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1045)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_THRESHOLD                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1046)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_AGC_AVERAGE_CONTROL             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1047)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_HALFBAND_BYPASSED               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1050)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_1_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1051)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_2_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1052)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_3_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1053)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_4_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1054)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_HALFBAND_5_ENABLED              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1055)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_AOUT_PARALLEL_OUTPUT_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1070) /* ViInt32   */
#define NISCOPE_ATTR_DDC_BOUT_PARALLEL_OUTPUT_SOURCE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1071) /* ViInt32   */
#define NISCOPE_ATTR_DDC_TEST_SINE_COSINE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1072) /* ViBoolean */
#define NISCOPE_ATTR_DDC_COORDINATE_CONVERTER_INPUT         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1073) /* ViInt32   */
#define NISCOPE_ATTR_DDC_Q_INPUT_TO_COORD_CONVERTER_INPUT   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1074) /* ViInt32   */
#define NISCOPE_ATTR_DDC_SYNCOUT_CLK_SELECT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1080)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_TIMING_NCO_PHASE_ACCUM_LOAD     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1120)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_TIMING_NCO_CLEAR_PHASE_ACCUM    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1121)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_TIMING_NCO_ENABLE_OFFSET_FREQ   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1122)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_TIMING_NCO_NUM_OFFSET_FREQ_BITS (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1123)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_TIMING_NCO_CENTER_FREQUENCY     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1124)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_TIMING_NCO_PHASE_OFFSET         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1125)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_RESAMPLER_FILTER_MODE_SELECT    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1126)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_RESAMPLER_BYPASS                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1127)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_RESAMPLER_OUTPUT_PULSE_DELAY    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1128)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_NCO_DIVIDE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1129)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_REFERENCE_DIVIDE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1130)    /* ViInt32   */
#define NISCOPE_ATTR_ENABLE_DITHER                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1300)    /* ViBoolean */
#define NISCOPE_ATTR_DDC_COMBINED_DECIMATION             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1301)    /* ViInt32   */
#define NISCOPE_ATTR_SERIAL_DAC_CAL_VOLTAGE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1302)    /* ViReal64  */
#define NISCOPE_ATTR_PLL_LOCK_STATUS                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1303)    /* ViBoolean */
#define NISCOPE_ATTR_DELAY_BEFORE_INITIATE               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1304)    /* ViReal64  */
#define NISCOPE_ATTR_DDC_DIRECT_REGISTER_ADDRESS         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1305)    /* ViInt32   */
#define NISCOPE_ATTR_DDC_DIRECT_REGISTER_DATA            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1306)    /* ViInt32   */

   /* New attributes for NI-SCOPE 2.5 */
#define NISCOPE_ATTR_DEVICE_TEMPERATURE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 86)   /* ViReal64   */
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_SRC               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 87)   /* ViString   */
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_RATE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 88)   /* ViReal64   */
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_DIV               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 89)   /* ViInt32    */
#define NISCOPE_ATTR_REF_CLK_RATE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 90)   /* ViReal64   */
#define NISCOPE_ATTR_EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 91)   /* ViString   */
#define NISCOPE_ATTR_DAQMX_TASK                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 92)   /* ViInt32    */
#define NISCOPE_ATTR_ENABLE_DC_RESTORE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 93)   /* ViBoolean  */
#define NISCOPE_ATTR_ADV_TRIG_SRC                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 94)   /* ViString   */
#define NISCOPE_ATTR_ARM_REF_TRIG_SRC                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 95)   /* ViString   */
#define NISCOPE_ATTR_REF_TRIG_TDC_ENABLE                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 96)   /* ViBoolean  */
#define NISCOPE_ATTR_RESOLUTION                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102)  /* ViInt32,   read-only */

   /* New attributes for NI-SCOPE 2.6 */
#define NISCOPE_ATTR_START_TO_REF_TRIGGER_HOLDOFF        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103)  /* ViReal64,  seconds */

   /* New attributes for NI-SCOPE 2.7 */
#define NISCOPE_ATTR_SERIAL_NUMBER                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104)  /* ViString   */
#define NISCOPE_ATTR_OSCILLATOR_PHASE_DAC_VALUE          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105)  /* ViInt32    */

   /* New attributes for NI-SCOPE 2.8 */
#define NISCOPE_ATTR_RIS_IN_AUTO_SETUP_ENABLE                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106)  /* ViBoolean  */
#define NISCOPE_ATTR_CHANNEL_TERMINAL_CONFIGURATION           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107)  /* ViInt32, multi channel */
#define NISCOPE_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 109)  /* ViString */
#define NISCOPE_ATTR_READY_FOR_START_EVENT_OUTPUT_TERMINAL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110)  /* ViString */
#define NISCOPE_ATTR_READY_FOR_REF_EVENT_OUTPUT_TERMINAL      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111)  /* ViString */
#define NISCOPE_ATTR_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112)  /* ViString */

   /* New attributes for NI-SCOPE 2.9.1 */
#define NISCOPE_ATTR_FLEX_FIR_ANTIALIAS_FILTER_TYPE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 271)  /* ViInt32, multi channel */

   /* New attributes for NI-SCOPE 3.0. Attributes for the NI 5142 & 5622 OSP functionality. */
#define NISCOPE_ATTR_DDC_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 300)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_ENABLED   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 302)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_DDC_CENTER_FREQUENCY                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 303)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DDC_DATA_PROCESSING_MODE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 304)  /* ViInt32 */
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_PHASE_I   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 305)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DDC_FREQUENCY_TRANSLATION_PHASE_Q   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 306)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DIGITAL_GAIN                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 307)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_DIGITAL_OFFSET                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 308)  /* ViReal64, multi channel */
#define NISCOPE_ATTR_OVERFLOW_ERROR_REPORTING            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 309)  /* ViInt32 */
#define NISCOPE_ATTR_DDC_Q_SOURCE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 310)  /* ViString, multi channel  */
#define NISCOPE_ATTR_FETCH_INTERLEAVED_IQ_DATA           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 311) // ViBoolean //

   /* New attributes for NI-SCOPE 3.1. */
#define NISCOPE_ATTR_EQUALIZATION_NUM_COEFFICIENTS       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 312)  /* ViInt32, multi channel */
#define NISCOPE_ATTR_EQUALIZATION_FILTER_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 313)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_REF_TRIGGER_DETECTOR_LOCATION       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 314)  /* ViInt32 */
#define NISCOPE_ATTR_REF_TRIGGER_MINIMUM_QUIET_TIME      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 315)  /* ViReal64 */

   /* New attributes for NI-SCOPE 3.2 */
#define NISCOPE_ATTR_ENABLE_TIME_INTERLEAVED_SAMPLING    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 128L)  // ViBoolean

   /* New attributes for NI-SCOPE 3.3 */
#define NISCOPE_ATTR_DATA_TRANSFER_BLOCK_SIZE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 316)  /* ViInt32 */

   /* New attributes for NI-SCOPE 3.4 */
#define NISCOPE_ATTR_TRIGGER_MODIFIER                          IVISCOPE_ATTR_TRIGGER_MODIFIER         /* ViInt32 */
#define NISCOPE_ATTR_TRIGGER_AUTO_TRIGGERED                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 278L) /* ViBoolean */
#define NISCOPE_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 97L)  /* ViString  */
#define NISCOPE_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 98L)  /* ViString  */
#define NISCOPE_ATTR_END_OF_RECORD_EVENT_OUTPUT_TERMINAL       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 99L)  /* ViString  */
#define NISCOPE_ATTR_END_OF_ACQUISITION_EVENT_OUTPUT_TERMINAL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L) /* ViString  */
#define NISCOPE_ATTR_5V_OUT_OUTPUT_TERMINAL                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 129L) /* ViString  */

   /* New attributes for NI-SCOPE 3.5 */
#define NISCOPE_ATTR_BANDPASS_FILTER_ENABLED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 318)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_DITHER_ENABLED                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 319)  /* ViBoolean, multi channel */
#define NISCOPE_ATTR_FRACTIONAL_RESAMPLE_ENABLED         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 320)  /* ViBoolean */
#define NISCOPE_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 321L)  /* ViReal64 */
#define NISCOPE_ATTR_DATA_TRANSFER_PREFERRED_PACKET_SIZE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 322L)  /* ViInt32 */

// NI-5900 specific definitions
#define NISCOPE_ATTR_SIGNAL_COND_GAIN                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 279L) // ViReal64 //
#define NISCOPE_ATTR_SIGNAL_COND_OFFSET                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 280L) // ViReal64 //

   /* New attributes for NI-SCOPE 3.6 */
//Peer-to-Peer
#define NISCOPE_ATTR_P2P_ENABLED                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 338L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_CHANNELS_TO_STREAM              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 339L) /* ViString  */
#define NISCOPE_ATTR_P2P_ENDPOINT_SIZE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 342L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_SAMPLES_AVAIL_IN_ENDPOINT       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 328L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_MOST_SAMPLES_AVAIL_IN_ENDPOINT  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 341L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_SAMPLES_TRANSFERRED             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 340L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_ENDPOINT_OVERFLOW               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 344L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_FIFO_ENDPOINT_COUNT             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 345L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_ONBOARD_MEMORY_ENABLED          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 354L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_MANUAL_CONFIGURATION_ENABLED    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 343L) /* ViBoolean */
#define NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 329L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR_TYPE (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 330L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 331L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR_TYPE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 332L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_DESTINATION_WINDOW_SIZE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 333L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_NOTIFY_PUSH_MESSAGE_ON          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 334L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 335L) /* ViInt64 */
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR_TYPE   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 336L) /* ViInt32 */
#define NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_VALUE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 337L) /* ViInt64 */

   /* New attributes for NI-SCOPE 3.8 */
#define NISCOPE_ATTR_SAMP_CLK_TIMEBASE_MULT              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 367)  /* ViInt32    */

/****************************************************************************
 *------------------ Attribute and Parameter Value Defines -----------------*
 ****************************************************************************/
/* RIS Methods */
#define NISCOPE_VAL_RIS_EXACT_NUM_AVERAGES 1
#define NISCOPE_VAL_RIS_MIN_NUM_AVERAGES   2
#define NISCOPE_VAL_RIS_INCOMPLETE         3
#define NISCOPE_VAL_RIS_LIMITED_BIN_WIDTH  5

/* Software Trigger Types */
#define NISCOPE_VAL_SOFTWARE_TRIGGER_START            0L
#define NISCOPE_VAL_SOFTWARE_TRIGGER_ARM_REFERENCE    1L
#define NISCOPE_VAL_SOFTWARE_TRIGGER_REFERENCE        2L
#define NISCOPE_VAL_SOFTWARE_TRIGGER_ADVANCE          3L

/*- NISCOPE_ATTR_VERTICAL_COUPLING Values -*/
#define NISCOPE_VAL_AC                           IVISCOPE_VAL_AC
#define NISCOPE_VAL_DC                           IVISCOPE_VAL_DC
#define NISCOPE_VAL_GND                          IVISCOPE_VAL_GND

/*- NISCOPE_ATTR_MAX_INPUT_FREQUENCY Values -*/
#define NISCOPE_VAL_BANDWIDTH_FULL               -1.0
#define NISCOPE_VAL_BANDWIDTH_DEVICE_DEFAULT     0.0
#define NISCOPE_VAL_20MHZ_BANDWIDTH              20000000.0
#define NISCOPE_VAL_100MHZ_BANDWIDTH             100000000.0
#define NISCOPE_VAL_20MHZ_MAX_INPUT_FREQUENCY    20000000.0
#define NISCOPE_VAL_100MHZ_MAX_INPUT_FREQUENCY   100000000.0

/*- NISCOPE_ATTR_INPUT_IMPEDANCE Values -*/
#define NISCOPE_VAL_50_OHMS                      50.0
#define NISCOPE_VAL_75_OHMS                      75.0
#define NISCOPE_VAL_1_MEG_OHM                    1000000.0

/*- NISCOPE_ATTR_TRIGGER_TYPE Values -*/
#define NISCOPE_VAL_EDGE_TRIGGER                 IVISCOPE_VAL_EDGE_TRIGGER
#define NISCOPE_VAL_HYSTERESIS_TRIGGER           (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 1L)
#define NISCOPE_VAL_DIGITAL_TRIGGER              (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 2L)
#define NISCOPE_VAL_WINDOW_TRIGGER               (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 3L)
#define NISCOPE_VAL_SOFTWARE_TRIGGER             (IVISCOPE_VAL_TRIGGER_TYPE_SPECIFIC_EXT_BASE + 4L)
#define NISCOPE_VAL_TV_TRIGGER                   IVISCOPE_VAL_TV_TRIGGER
#define NISCOPE_VAL_IMMEDIATE_TRIGGER            IVISCOPE_VAL_IMMEDIATE_TRIGGER

/*- NISCOPE_ATTR_TRIGGER_SOURCE Values -*/
#define NISCOPE_VAL_IMMEDIATE                    "VAL_IMMEDIATE"
#define NISCOPE_VAL_EXTERNAL                     IVISCOPE_VAL_EXTERNAL
#define NISCOPE_VAL_SW_TRIG_FUNC                 "VAL_SW_TRIG_FUNC"
#define NISCOPE_VAL_TTL0                         IVISCOPE_VAL_TTL0
#define NISCOPE_VAL_TTL1                         IVISCOPE_VAL_TTL1
#define NISCOPE_VAL_TTL2                         IVISCOPE_VAL_TTL2
#define NISCOPE_VAL_TTL3                         IVISCOPE_VAL_TTL3
#define NISCOPE_VAL_TTL4                         IVISCOPE_VAL_TTL4
#define NISCOPE_VAL_TTL5                         IVISCOPE_VAL_TTL5
#define NISCOPE_VAL_TTL6                         IVISCOPE_VAL_TTL6
#define NISCOPE_VAL_TTL7                         IVISCOPE_VAL_TTL7
#define NISCOPE_VAL_ECL0                         IVISCOPE_VAL_ECL0      /* Obsolete value */
#define NISCOPE_VAL_ECL1                         IVISCOPE_VAL_ECL1      /* Obsolete value */
#define NISCOPE_VAL_PXI_STAR                     IVISCOPE_VAL_PXI_STAR
#define NISCOPE_VAL_RTSI_0                       IVISCOPE_VAL_RTSI_0
#define NISCOPE_VAL_RTSI_1                       IVISCOPE_VAL_RTSI_1
#define NISCOPE_VAL_RTSI_2                       IVISCOPE_VAL_RTSI_2
#define NISCOPE_VAL_RTSI_3                       IVISCOPE_VAL_RTSI_3
#define NISCOPE_VAL_RTSI_4                       IVISCOPE_VAL_RTSI_4
#define NISCOPE_VAL_RTSI_5                       IVISCOPE_VAL_RTSI_5
#define NISCOPE_VAL_RTSI_6                       IVISCOPE_VAL_RTSI_6
#define NISCOPE_VAL_RTSI_7                       "VAL_RTSI_7"
#define NISCOPE_VAL_PFI_0                        "VAL_PFI_0"
#define NISCOPE_VAL_PFI_1                        "VAL_PFI_1"
#define NISCOPE_VAL_PFI_2                        "VAL_PFI_2"

/*-NISCOPE_ATTR_RELATIVE_TO Values -*/
#define NISCOPE_VAL_READ_POINTER                 388
#define NISCOPE_VAL_PRETRIGGER                   477
#define NISCOPE_VAL_NOW                          481
#define NISCOPE_VAL_START                        482
#define NISCOPE_VAL_TRIGGER                      483

/*- NISCOPE_ATTR_TRIGGER_MODIFIER Values -*/
#define NISCOPE_VAL_NO_TRIGGER_MOD               IVISCOPE_VAL_NO_TRIGGER_MOD /* default */
#define NISCOPE_VAL_AUTO                         IVISCOPE_VAL_AUTO
#define NISCOPE_VAL_AUTO_LEVEL                   IVISCOPE_VAL_AUTO_LEVEL

/*- NISCOPE_ATTR_TRIGGER_COUPLING Values -*/
/* #define NISCOPE_VAL_AC                        DEFINED ABOVE */
/* #define NISCOPE_VAL_DC                        DEFINED ABOVE */
#define NISCOPE_VAL_HF_REJECT                    IVISCOPE_VAL_HF_REJECT
#define NISCOPE_VAL_LF_REJECT                    IVISCOPE_VAL_LF_REJECT
#define NISCOPE_VAL_AC_PLUS_HF_REJECT            (IVISCOPE_VAL_TRIGGER_COUPLING_SPECIFIC_EXT_BASE + 1)

/*- NISCOPE_ATTR_TRIGGER_SLOPE Values -*/
#define NISCOPE_VAL_POSITIVE                     IVISCOPE_VAL_POSITIVE
#define NISCOPE_VAL_NEGATIVE                     IVISCOPE_VAL_NEGATIVE

/*- NISCOPE_ATTR_ACQUISITION_TYPE Values -*/
#define NISCOPE_VAL_NORMAL                       IVISCOPE_VAL_NORMAL     /* default */
#define NISCOPE_VAL_FLEXRES                      (IVISCOPE_VAL_ACQUISITION_TYPE_SPECIFIC_EXT_BASE + 1)
#define NISCOPE_VAL_DDC                          (IVISCOPE_VAL_ACQUISITION_TYPE_SPECIFIC_EXT_BASE + 2)

/*- NISCOPE_ATTR_INTERPOLATION Values -*/
#define NISCOPE_VAL_NO_INTERPOLATION             IVISCOPE_VAL_NO_INTERPOLATION
#define NISCOPE_VAL_SINE_X                       IVISCOPE_VAL_SINE_X          /* default */
#define NISCOPE_VAL_LINEAR                       IVISCOPE_VAL_LINEAR

/*- NISCOPE_ATTR_INTERPOLATION Values -*/
#define NISCOPE_VAL_NO_INTERPOLATION             IVISCOPE_VAL_NO_INTERPOLATION
#define NISCOPE_VAL_SINE_X                       IVISCOPE_VAL_SINE_X          /* default */
#define NISCOPE_VAL_LINEAR                       IVISCOPE_VAL_LINEAR

/*- Defined values for NISCOPE_ATTR_TV_TRIGGER_SIGNAL_FORMAT -*/
// SDTV/EDTV
#define NISCOPE_VAL_NTSC                         IVISCOPE_VAL_NTSC
#define NISCOPE_VAL_PAL                          IVISCOPE_VAL_PAL
#define NISCOPE_VAL_SECAM                        IVISCOPE_VAL_SECAM
#define NISCOPE_VAL_M_PAL                           (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 1)
#define NISCOPE_VAL_480I_59_94_FIELDS_PER_SECOND    (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 10)
#define NISCOPE_VAL_480I_60_FIELDS_PER_SECOND       (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 11)
#define NISCOPE_VAL_480P_59_94_FRAMES_PER_SECOND    (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 15)
#define NISCOPE_VAL_480P_60_FRAMES_PER_SECOND       (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 16)
#define NISCOPE_VAL_576I_50_FIELDS_PER_SECOND       (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 20)
#define NISCOPE_VAL_576P_50_FRAMES_PER_SECOND       (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 25)
// HDTV
#define NISCOPE_VAL_720P_50_FRAMES_PER_SECOND       (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 31)
#define NISCOPE_VAL_720P_59_94_FRAMES_PER_SECOND    (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 32)
#define NISCOPE_VAL_720P_60_FRAMES_PER_SECOND       (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 33)
#define NISCOPE_VAL_1080I_50_FIELDS_PER_SECOND      (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 40)
#define NISCOPE_VAL_1080I_59_94_FIELDS_PER_SECOND   (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 41)
#define NISCOPE_VAL_1080I_60_FIELDS_PER_SECOND      (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 42)
#define NISCOPE_VAL_1080P_24_FRAMES_PER_SECOND      (IVISCOPE_VAL_TV_SIGNAL_FORMAT_SPECIFIC_EXT_BASE + 45)


/*- Defined values for NISCOPE_ATTR_TV_TRIGGER_POLARITY -*/
#define NISCOPE_VAL_TV_POSITIVE                  IVISCOPE_VAL_TV_POSITIVE
#define NISCOPE_VAL_TV_NEGATIVE                  IVISCOPE_VAL_TV_NEGATIVE

/*- Defined values for NISCOPE_ATTR_TV_TRIGGER_EVENT -*/
#define NISCOPE_VAL_TV_EVENT_FIELD1              IVISCOPE_VAL_TV_EVENT_FIELD1
#define NISCOPE_VAL_TV_EVENT_FIELD2              IVISCOPE_VAL_TV_EVENT_FIELD2
#define NISCOPE_VAL_TV_EVENT_ANY_FIELD           IVISCOPE_VAL_TV_EVENT_ANY_FIELD
#define NISCOPE_VAL_TV_EVENT_ANY_LINE            IVISCOPE_VAL_TV_EVENT_ANY_LINE
#define NISCOPE_VAL_TV_EVENT_LINE_NUMBER         IVISCOPE_VAL_TV_EVENT_LINE_NUMBER

/*- NISCOPE_ATTR_SAMPLE_MODE Values -*/
#define NISCOPE_VAL_REAL_TIME                    IVISCOPE_VAL_REAL_TIME
#define NISCOPE_VAL_EQUIVALENT_TIME              IVISCOPE_VAL_EQUIVALENT_TIME

/*- NISCOPE_ATTR_CLOCK_SOURCE Values -*/
#define NISCOPE_VAL_NO_SOURCE                    "VAL_NO_SOURCE"
#define NISCOPE_VAL_RTSI_CLOCK                   "VAL_RTSI_CLOCK"
/* #define NISCOPE_VAL_EXTERNAL                  DEFINED ABOVE */
/* #define NISCOPE_VAL_PFI_0                     DEFINED ABOVE */
/* #define NISCOPE_VAL_PFI_1                     DEFINED ABOVE */
/* #define NISCOPE_VAL_PFI_2                     DEFINED ABOVE */
#define NISCOPE_VAL_CLK_IN                       "VAL_CLK_IN"
#define NISCOPE_VAL_CLK_OUT                      "VAL_CLK_OUT"
#define NISCOPE_VAL_INTERNAL10MHZ_OSC            "VAL_INTERNAL10MHZ_OSC"
#define NISCOPE_VAL_PXI_CLK                      "VAL_PXI_CLK"
#define NISCOPE_VAL_PXI_CLK10                    "VAL_PXI_CLK10"
#define NISCOPE_VAL_PXI_CLK100                   "VAL_PXI_CLK100"

/*- NISCOPE_ATTR_SAMP_CLK_TIMEBASE_SRC -*/
/* #define NISCOPE_VAL_CLK_IN                    DEFINED ABOVE */
/* #define NISCOPE_VAL_NO_SOURCE                 DEFINED ABOVE */
/* #define NISCOPE_VAL_PXI_STAR                  DEFINED ABOVE */

/*- niScope_ExportSignal Values -*/
#define NISCOPE_VAL_REF_TRIGGER                       1
#define NISCOPE_VAL_START_TRIGGER                     2
#define NISCOPE_VAL_END_OF_ACQUISITION_EVENT          3
#define NISCOPE_VAL_END_OF_RECORD_EVENT               4
#define NISCOPE_VAL_ADVANCE_TRIGGER                   5
#define NISCOPE_VAL_READY_FOR_ADVANCE_EVENT           6
#define NISCOPE_VAL_READY_FOR_START_EVENT             7
#define NISCOPE_VAL_READY_FOR_REF_EVENT               10
#define NISCOPE_VAL_5V_OUT                            13
#define NISCOPE_VAL_REF_CLOCK                         100
#define NISCOPE_VAL_SAMPLE_CLOCK                      101

/*- NISCOPE_ATTR_TRIGGER_WINDOW_MODE Values -*/
#define NISCOPE_VAL_ENTERING_WINDOW              0
#define NISCOPE_VAL_LEAVING_WINDOW               1

/*- General defined values -*/
#define NISCOPE_VAL_INPUT                        0
#define NISCOPE_VAL_OUTPUT                       1
#define NISCOPE_VAL_NONE                         0
#define NISCOPE_VAL_TRUE                         (VI_TRUE)
#define NISCOPE_VAL_FALSE                        (VI_FALSE)

/*- Defined values for calibrationOperation of niScope_Calibrate -*/
/*- The niScope_Calibrate function is obsolete, see niScopeCal.h
    for calibration defines and functions.  */
#define NISCOPE_VAL_SELF_CALIBRATION             0
#define NISCOPE_VAL_EXTERNAL_CALIBRATION         1
#define NISCOPE_VAL_RESTORE_FACTORY_CALIBRATION  2
#define NISCOPE_VAL_CLEAR_EEPROM                 101  // internal use only

/* Self calibrate options */
#define NISCOPE_VAL_CAL_RESTORE_EXTERNAL_CALIBRATION \
        NISCOPE_VAL_RESTORE_FACTORY_CALIBRATION


/*- Defined values for maxTime parameter of niScope_ReadWaveform -*/
#define NISCOPE_VAL_MAX_TIME_INFINITE            IVISCOPE_VAL_MAX_TIME_INFINITE
#define NISCOPE_VAL_MAX_TIME_IMMEDIATE           IVISCOPE_VAL_MAX_TIME_IMMEDIATE
/*- Keep NISCOPE_VAL_MAX_TIME_NONE for compatibility - use NISCOPE_VAL_MAX_TIME_IMMEDIATE
    for new programs -*/
#define NISCOPE_VAL_MAX_TIME_NONE                IVISCOPE_VAL_MAX_TIME_IMMEDIATE

/*- Defined values for the status parameter of the niScope_AcquisitionStatus -*/
#define NISCOPE_VAL_ACQ_COMPLETE                 IVISCOPE_VAL_ACQ_COMPLETE
#define NISCOPE_VAL_ACQ_IN_PROGRESS              IVISCOPE_VAL_ACQ_IN_PROGRESS
#define NISCOPE_VAL_ACQ_STATUS_UNKNOWN           IVISCOPE_VAL_ACQ_STATUS_UNKNOWN

/*- Defined values for the waveform measurement functions -*/
#define NISCOPE_VAL_ALL_MEASUREMENTS             10000L /* for ClearingStats */

#define NISCOPE_VAL_MEAS_LOWPASS                 0   /* ATTR_MEAS_FILTER_TYPE */
#define NISCOPE_VAL_MEAS_HIGHPASS                1
#define NISCOPE_VAL_MEAS_BANDPASS                2
#define NISCOPE_VAL_MEAS_BANDSTOP                3

#define NISCOPE_VAL_MEAS_LOW_HIGH                0    /* ATTR_MEAS_PERCENTAGE_METHOD */
#define NISCOPE_VAL_MEAS_MIN_MAX                 1
#define NISCOPE_VAL_MEAS_BASE_TOP                2

#define NISCOPE_VAL_MEAS_VOLTAGE                 0    /* ATTR_MEAS_REF_LEVEL_UNITS */
#define NISCOPE_VAL_MEAS_PERCENTAGE              1

#define NISCOPE_VAL_RISE_TIME                    IVISCOPE_VAL_RISE_TIME
#define NISCOPE_VAL_FALL_TIME                    IVISCOPE_VAL_FALL_TIME
#define NISCOPE_VAL_FREQUENCY                    IVISCOPE_VAL_FREQUENCY
#define NISCOPE_VAL_PERIOD                       IVISCOPE_VAL_PERIOD
#define NISCOPE_VAL_VOLTAGE_RMS                  IVISCOPE_VAL_VOLTAGE_RMS
#define NISCOPE_VAL_VOLTAGE_PEAK_TO_PEAK         IVISCOPE_VAL_VOLTAGE_PEAK_TO_PEAK
#define NISCOPE_VAL_VOLTAGE_MAX                  IVISCOPE_VAL_VOLTAGE_MAX
#define NISCOPE_VAL_VOLTAGE_MIN                  IVISCOPE_VAL_VOLTAGE_MIN
#define NISCOPE_VAL_VOLTAGE_HIGH                 IVISCOPE_VAL_VOLTAGE_HIGH
#define NISCOPE_VAL_VOLTAGE_LOW                  IVISCOPE_VAL_VOLTAGE_LOW
#define NISCOPE_VAL_VOLTAGE_AVERAGE              IVISCOPE_VAL_VOLTAGE_AVERAGE
#define NISCOPE_VAL_WIDTH_NEG                    IVISCOPE_VAL_WIDTH_NEG
#define NISCOPE_VAL_WIDTH_POS                    IVISCOPE_VAL_WIDTH_POS
#define NISCOPE_VAL_DUTY_CYCLE_NEG               IVISCOPE_VAL_DUTY_CYCLE_NEG
#define NISCOPE_VAL_DUTY_CYCLE_POS               IVISCOPE_VAL_DUTY_CYCLE_POS
#define NISCOPE_VAL_AMPLITUDE                    IVISCOPE_VAL_AMPLITUDE
#define NISCOPE_VAL_VOLTAGE_CYCLE_RMS            IVISCOPE_VAL_VOLTAGE_CYCLE_RMS
#define NISCOPE_VAL_VOLTAGE_CYCLE_AVERAGE        IVISCOPE_VAL_VOLTAGE_CYCLE_AVERAGE
#define NISCOPE_VAL_OVERSHOOT                    IVISCOPE_VAL_OVERSHOOT
#define NISCOPE_VAL_PRESHOOT                     IVISCOPE_VAL_PRESHOOT
#define NISCOPE_VAL_LOW_REF_VOLTS                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 0L)
#define NISCOPE_VAL_MID_REF_VOLTS                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1L)
#define NISCOPE_VAL_HIGH_REF_VOLTS               (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2L)
#define NISCOPE_VAL_AREA                         (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 3L)
#define NISCOPE_VAL_CYCLE_AREA                   (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 4L)
#define NISCOPE_VAL_INTEGRAL                     (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 5L)
#define NISCOPE_VAL_VOLTAGE_BASE                 (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 6L)
#define NISCOPE_VAL_VOLTAGE_TOP                  (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 7L)
#define NISCOPE_VAL_FFT_FREQUENCY                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 8L)
#define NISCOPE_VAL_FFT_AMPLITUDE                (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 9L)
#define NISCOPE_VAL_RISE_SLEW_RATE               (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 10L)
#define NISCOPE_VAL_FALL_SLEW_RATE               (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 11L)
#define NISCOPE_VAL_AC_ESTIMATE                  (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 12L)
#define NISCOPE_VAL_DC_ESTIMATE                  (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 13L)
#define NISCOPE_VAL_TIME_DELAY                   (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 14L)
#define NISCOPE_VAL_AVERAGE_PERIOD               (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 15L)
#define NISCOPE_VAL_AVERAGE_FREQUENCY            (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 16L)
#define NISCOPE_VAL_VOLTAGE_BASE_TO_TOP          (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 17L)
#define NISCOPE_VAL_PHASE_DELAY                  (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 18L)

/* Voltage Histogram */
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1000L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_STDEV            (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1001L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_PEAK_TO_PEAK     (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1002L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEDIAN           (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1003L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_HITS             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1004L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MAX              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1005L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MIN              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1006L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_STDEV  (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1007L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_2_STDEV (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1008L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MEAN_PLUS_3_STDEV (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1009L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_MODE              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1010L)
#define NISCOPE_VAL_VOLTAGE_HISTOGRAM_NEW_HITS          (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 1011L)

/* Time Histogram */
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2000L)
#define NISCOPE_VAL_TIME_HISTOGRAM_STDEV            (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2001L)
#define NISCOPE_VAL_TIME_HISTOGRAM_PEAK_TO_PEAK     (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2002L)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEDIAN           (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2003L)
#define NISCOPE_VAL_TIME_HISTOGRAM_HITS             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2004L)
#define NISCOPE_VAL_TIME_HISTOGRAM_MAX              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2005L)
#define NISCOPE_VAL_TIME_HISTOGRAM_MIN              (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2006L)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_STDEV  (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2007L)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_2_STDEV (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2008L)
#define NISCOPE_VAL_TIME_HISTOGRAM_MEAN_PLUS_3_STDEV (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2009L)
#define NISCOPE_VAL_TIME_HISTOGRAM_MODE             (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2010L)
#define NISCOPE_VAL_TIME_HISTOGRAM_NEW_HITS         (IVISCOPE_VAL_MEASUREMENT_FUNCTION_SPECIFIC_EXT_BASE + 2011L)

/* Array Measurements */
#define NISCOPE_VAL_NO_MEASUREMENT                      4000L
#define NISCOPE_VAL_LAST_ACQ_HISTOGRAM                  4001L
#define NISCOPE_VAL_FFT_PHASE_SPECTRUM                  4002L
#define NISCOPE_VAL_FFT_AMP_SPECTRUM_VOLTS_RMS          4003L
#define NISCOPE_VAL_MULTI_ACQ_VOLTAGE_HISTOGRAM         4004L
#define NISCOPE_VAL_MULTI_ACQ_TIME_HISTOGRAM            4005L
#define NISCOPE_VAL_ARRAY_INTEGRAL                      4006L
#define NISCOPE_VAL_DERIVATIVE                          4007L
#define NISCOPE_VAL_INVERSE                             4008L
#define NISCOPE_VAL_HANNING_WINDOW                      4009L
#define NISCOPE_VAL_FLAT_TOP_WINDOW                     4010L
#define NISCOPE_VAL_POLYNOMIAL_INTERPOLATION            4011L
#define NISCOPE_VAL_MULTIPLY_CHANNELS                   4012L
#define NISCOPE_VAL_ADD_CHANNELS                        4013L
#define NISCOPE_VAL_SUBTRACT_CHANNELS                   4014L
#define NISCOPE_VAL_DIVIDE_CHANNELS                     4015L
#define NISCOPE_VAL_MULTI_ACQ_AVERAGE                   4016L
#define NISCOPE_VAL_BUTTERWORTH_FILTER                  4017L
#define NISCOPE_VAL_CHEBYSHEV_FILTER                    4018L
#define NISCOPE_VAL_FFT_AMP_SPECTRUM_DB                 4019L
#define NISCOPE_VAL_HAMMING_WINDOW                      4020L
#define NISCOPE_VAL_WINDOWED_FIR_FILTER                 4021L
#define NISCOPE_VAL_BESSEL_FILTER                       4022L
#define NISCOPE_VAL_TRIANGLE_WINDOW                     4023L
#define NISCOPE_VAL_BLACKMAN_WINDOW                     4024L
#define NISCOPE_VAL_ARRAY_OFFSET                        4025L
#define NISCOPE_VAL_ARRAY_GAIN                          4026L

/* NISCOPE_ATTR_DDC_PFIR_SYMMETRY_TYPE and NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_SYMMETRY_TYPE Values */
#define NISCOPE_VAL_EVEN  0
#define NISCOPE_VAL_ODD   1

/* NISCOPE_ATTR_DDC_PFIR_SYMMETRY and NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_SYMMETRY Values */
#define NISCOPE_VAL_SYMMETRIC   0
#define NISCOPE_VAL_ASYMMETRIC  1

/* NISCOPE_ATTR_DDC_DISCRIMINATOR_FIR_INPUT_SOURCE Values */
#define NISCOPE_VAL_PHASE       0
#define NISCOPE_VAL_MAGNITUDE   1
#define NISCOPE_VAL_RESAMPLER   2

/* Values for coefficientType parameter of niScope_SetDDCFilterCoefficients() */
#define NISCOPE_VAL_PFIR_COEFFICIENTS                    0
#define NISCOPE_VAL_DISCRIMINATOR_FIR_COEFFICIENTS       1

/* NISCOPE_ATTR_DDC_AOUT_PARALLEL_OUTPUT_SOURCE and NISCOPE_ATTR_DDC_BOUT_PARALLEL_OUTPUT_SOURCE Values */
#define NISCOPE_VAL_I_DATA             0  /* Valid for AOUT only           */
#define NISCOPE_VAL_MAGNITUDE_DATA     1  /* Valid for both AOUT and BOUT  */
#define NISCOPE_VAL_FREQ_DATA          2  /* Valid for AOUT only           */
#define NISCOPE_VAL_Q_DATA             3  /* Valid for BOUT only           */
#define NISCOPE_VAL_PHASE_DATA         4  /* Valid for BOUT only           */

/* NISCOPE_ATTR_DDC_PFIR_REAL_OR_COMPLEX Values */
#define NISCOPE_VAL_REAL         0
#define NISCOPE_VAL_COMPLEX      1

/* NISCOPE_ATTR_CHANNEL_TERMINAL_CONFIGURATION Values */
#define NISCOPE_VAL_SINGLE_ENDED                 0
#define NISCOPE_VAL_UNBALANCED_DIFFERENTIAL      1
#define NISCOPE_VAL_DIFFERENTIAL                 2

/* NISCOPE_ATTR_FLEX_FIR_ANTIALIAS_FILTER_TYPE Values */
#define NISCOPE_VAL_48_TAP_STANDARD       0
#define NISCOPE_VAL_48_TAP_HANNING        1
#define NISCOPE_VAL_16_TAP_HANNING        2
#define NISCOPE_VAL_8_TAP_HANNING         3

/* NISCOPE_ATTR_DDC_DATA_PROCESSING_MODE */
//#define NISCOPE_VAL_REAL      DEFINED ABOVE
//#define NISCOPE_VAL_COMPLEX   DEFINED ABOVE

/* NISCOPE_ATTR_OVERFLOW_ERROR_REPORTING */
#define NISCOPE_VAL_ERROR_REPORTING_ERROR    0
#define NISCOPE_VAL_ERROR_REPORTING_WARNING  1
#define NISCOPE_VAL_ERROR_REPORTING_DISABLED 2

/* NISCOPE_ATTR_REF_TRIGGER_DETECTOR_LOCATION */
#define NISCOPE_VAL_ANALOG_DETECTION_CIRCUIT   0
#define NISCOPE_VAL_DDC_OUTPUT                 1

/* Address types for NISCOPE_ATTR_P2P_DATA_TRANS_PERMISSION_ADDR_TYPE,
NISCOPE_ATTR_P2P_DESTINATION_WINDOW_ADDR_TYPE,
NISCOPE_ATTR_P2P_NOTIFY_MESSAGE_PUSH_ADDR_TYPE */
#define NISCOPE_VAL_ADDR_PHYSICAL               0
#define NISCOPE_VAL_ADDR_VIRTUAL                1

/* Notification events for NISCOPE_ATTR_P2P_NOTIFY_PUSH_MESSAGE_ON */
#define NISCOPE_VAL_NOTIFY_NEVER                0
#define NISCOPE_VAL_NOTIFY_DONE                 1

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*--- Init and Close Functions ---------------------------------------------*/
ViStatus _VI_FUNC niScope_init (ViRsrc resourceName,
                                ViBoolean IDQuery,
                                ViBoolean resetDevice,
                                ViSession* vi);

ViStatus _VI_FUNC niScope_InitWithOptions (ViRsrc resourceName,
                                           ViBoolean IDQuery,
                                           ViBoolean resetDevice,
                                           ViConstString optionString,
                                           ViSession* newVi);

ViStatus _VI_FUNC niScope_close (ViSession vi);

/*--- AutoSetup Functions ----------------------------------------------------*/
ViStatus _VI_FUNC niScope_AutoSetup (ViSession vi);

/*---- Vertical Subsystem Configuration ------------------------------------*/
ViStatus _VI_FUNC niScope_ConfigureVertical (ViSession vi,
                                             ViConstString channelList,
                                             ViReal64 range,
                                             ViReal64 offset,
                                             ViInt32 coupling,
                                             ViReal64 probeAttenuation,
                                             ViBoolean enabled);

ViStatus _VI_FUNC niScope_ConfigureChanCharacteristics (ViSession vi,
                                                        ViConstString channelList,
                                                        ViReal64 inputImpedance,
                                                        ViReal64 maxInputFrequency);

/*---- Horizontal Subsystem Configuration ----------------------------------*/
ViStatus _VI_FUNC niScope_ConfigureHorizontalTiming (ViSession vi,
                                                     ViReal64 minSampleRate,
                                                     ViInt32 minNumPts,
                                                     ViReal64 refPosition,
                                                     ViInt32 numRecords,
                                                     ViBoolean enforceRealtime);

/*--- Synchronization Configuration ----------------------------------------*/
ViStatus _VI_FUNC niScope_ConfigureClock (ViSession vi,
                                          ViConstString inputClockSource,
                                          ViConstString outputClockSource,
                                          ViConstString clockSyncPulseSource,
                                          ViBoolean masterEnabled);

ViStatus _VI_FUNC niScope_ExportSignal (ViSession vi,
                                        ViInt32 signal,
                                        ViConstString signalIdentifier,
                                        ViConstString outputTerminal);

ViStatus _VI_FUNC niScope_AdjustSampleClockRelativeDelay (ViSession vi,
                                                          ViReal64 delay);

/*--- Triggering Subsystem Configuration -----------------------------------*/
ViStatus _VI_FUNC niScope_ConfigureTriggerEdge (ViSession vi,
                                                ViConstString triggerSource,
                                                ViReal64 level,
                                                ViInt32 slope,
                                                ViInt32 triggerCoupling,
                                                ViReal64 holdoff,
                                                ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerHysteresis (ViSession vi,
                                                      ViConstString triggerSource,
                                                      ViReal64 level,
                                                      ViReal64 hysteresis,
                                                      ViInt32 slope,
                                                      ViInt32 triggerCoupling,
                                                      ViReal64 holdoff,
                                                      ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerWindow (ViSession vi,
                                                  ViConstString triggerSource,
                                                  ViReal64 lowLevel,
                                                  ViReal64 highLevel,
                                                  ViInt32 windowMode,
                                                  ViInt32 triggerCoupling,
                                                  ViReal64 holdoff,
                                                  ViReal64 delay);


ViStatus _VI_FUNC niScope_ConfigureTriggerSoftware (ViSession vi,
                                                    ViReal64 holdoff,
                                                    ViReal64 delay);

ViStatus _VI_FUNC niScope_SendSoftwareTriggerEdge (ViSession vi,
                                                   ViInt32 whichTrigger);

ViStatus _VI_FUNC niScope_ConfigureTriggerImmediate (ViSession vi);

ViStatus _VI_FUNC niScope_ConfigureTriggerDigital (ViSession vi,
                                                   ViConstString triggerSource,
                                                   ViInt32 slope,
                                                   ViReal64 holdoff,
                                                   ViReal64 delay);

ViStatus _VI_FUNC niScope_ConfigureTriggerVideo (ViSession vi,
                                                 ViConstString triggerSource,
                                                 ViBoolean enableDCRestore,
                                                 ViInt32 signalFormat,
                                                 ViInt32 event,
                                                 ViInt32 lineNumber, // ignored if not applicable
                                                 ViInt32 polarity,
                                                 ViInt32 triggerCoupling,
                                                 ViReal64 holdoff,
                                                 ViReal64 delay);

/*--- Onboard Signal Processing Subsystem Configuration --------------------*/
ViStatus _VI_FUNC niScope_ConfigureEqualizationFilterCoefficients (ViSession vi,
                                                                   ViConstString channel,
                                                                   ViInt32 numberOfCoefficients,
                                                                   ViReal64* coefficients);

ViStatus _VI_FUNC niScope_GetFrequencyResponse (ViSession vi,
                                                ViConstString channelName,
                                                ViInt32 bufferSize,
                                                ViReal64 frequencies[],
                                                ViReal64 amplitudes[],
                                                ViReal64 phases[],
                                                ViInt32* numberOfFrequencies);

/*--- Waveform Acquisition Subsystem ---------------------------------------*/
ViStatus _VI_FUNC niScope_ConfigureAcquisition (ViSession vi,
                                                ViInt32 acquisitionType);

ViStatus _VI_FUNC niScope_InitiateAcquisition (ViSession vi);

ViStatus _VI_FUNC niScope_Abort (ViSession vi);

ViStatus _VI_FUNC niScope_Commit (ViSession vi);

#pragma pack(push,8)

struct niScope_wfmInfo
{
   ViReal64 absoluteInitialX;
   ViReal64 relativeInitialX;
   ViReal64 xIncrement;
   ViInt32 actualSamples;
   ViReal64 offset;
   ViReal64 gain;
   ViReal64 reserved1;
   ViReal64 reserved2;
};

struct niScope_coefficientInfo
{
   ViReal64 offset;
   ViReal64 gain;
   ViReal64 reserved1;
   ViReal64 reserved2;
};

#if !defined(_NIComplexNumber)
#define _NIComplexNumber

typedef struct NIComplexNumber_struct {
   ViReal64 real;
   ViReal64 imaginary;
} NIComplexNumber;

#endif


#if !defined(_NIComplexI16)
#define _NIComplexI16

typedef struct NIComplexI16_struct {
   ViInt16 real;
   ViInt16 imaginary;
} NIComplexI16;

#endif

#pragma pack(pop)

ViStatus _VI_FUNC niScope_Read   (ViSession vi,
                                  ViConstString channelList,
                                  ViReal64 timeout,
                                  ViInt32 numSamples,
                                  ViReal64* wfm,
                                  struct niScope_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niScope_Fetch  (ViSession vi,
                                  ViConstString channelList,
                                  ViReal64 timeout,
                                  ViInt32 numSamples,
                                  ViReal64* wfm,
                                  struct niScope_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niScope_FetchBinary8 (ViSession vi,
                                        ViConstString channelList,
                                        ViReal64 timeout,
                                        ViInt32 numSamples,
                                        ViInt8* wfm,
                                        struct niScope_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niScope_FetchBinary16 (ViSession vi,
                                         ViConstString channelList,
                                         ViReal64 timeout,
                                         ViInt32 numSamples,
                                         ViInt16* wfm,
                                         struct niScope_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niScope_FetchBinary32 (ViSession vi,
                                         ViConstString channelList,
                                         ViReal64 timeout,
                                         ViInt32 numSamples,
                                         ViInt32* wfm,
                                         struct niScope_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niScope_FetchComplex ( ViSession vi,
                                         ViConstString channelList,
                                         ViReal64 timeout,
                                         ViInt32 numSamples,
                                         NIComplexNumber* wfm,
                                         struct niScope_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niScope_FetchComplexBinary16 ( ViSession vi,
                                                 ViConstString channelList,
                                                 ViReal64 timeout,
                                                 ViInt32 numSamples,
                                                 NIComplexI16* wfm,
                                                 struct niScope_wfmInfo* wfmInfo);

/*------ Status -----------------------------------------------------------*/
ViStatus _VI_FUNC niScope_AcquisitionStatus (ViSession vi, ViInt32* status);

/*------ Actual Values ----------------------------------------------------*/
ViStatus _VI_FUNC niScope_ActualNumWfms (ViSession vi,
                                         ViConstString channelList,
                                         ViInt32* numWfms);

ViStatus _VI_FUNC niScope_ActualMeasWfmSize (ViSession vi,
                                             ViInt32 arrayMeasFunction,
                                             ViInt32* measWfmSize);

ViStatus _VI_FUNC niScope_ActualRecordLength (ViSession vi,
                                              ViInt32* actualRecordLength);

ViStatus _VI_FUNC niScope_SampleRate (ViSession vi,
                                      ViReal64* sampleRate);

ViStatus _VI_FUNC niScope_SampleMode (ViSession vi, ViInt32* sampleMode);

/*--- Waveform Measurement Functions ----------------------------------------*/
ViStatus _VI_FUNC niScope_AddWaveformProcessing (ViSession vi,
                                                 ViConstString channelList,
                                                 ViInt32 measFunction);

ViStatus _VI_FUNC niScope_ClearWaveformProcessing (ViSession vi,
                                                   ViConstString channelList);


ViStatus _VI_FUNC niScope_ClearWaveformMeasurementStats (ViSession vi,
                                                         ViConstString channelList,
                                                         ViInt32 measFunction);

ViStatus _VI_FUNC niScope_ReadMeasurement (ViSession vi,
                                           ViConstString channelList,
                                           ViReal64 timeout,
                                           ViInt32 scalarMeasFunction,
                                           ViReal64* result);

ViStatus _VI_FUNC niScope_FetchMeasurement (ViSession vi,
                                            ViConstString channelList,
                                            ViReal64 timeout,
                                            ViInt32 scalarMeasFunction,
                                            ViReal64* result);

ViStatus _VI_FUNC niScope_FetchMeasurementStats (ViSession vi,
                                                 ViConstString channelList,
                                                 ViReal64 timeout,
                                                 ViInt32 scalarMeasFunction,
                                                 ViReal64* result,
                                                 ViReal64* mean,
                                                 ViReal64* stdev,
                                                 ViReal64* min,
                                                 ViReal64* max,
                                                 ViInt32* numInStats);

ViStatus _VI_FUNC niScope_FetchArrayMeasurement (ViSession vi,
                                                 ViConstString channelList,
                                                 ViReal64 timeout,
                                                 ViInt32 arrayMeasFunction,
                                                 ViInt32 measWfmSize,
                                                 ViReal64* measWfm,
                                                 struct niScope_wfmInfo* measWfmInfo);

/*--- Utility Functions ----------------------------------------------------*/
ViStatus _VI_FUNC niScope_reset (ViSession vi);

ViStatus _VI_FUNC niScope_self_test (ViSession vi,
                                     ViInt16* selfTestResult,
                                     ViChar testMessage[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niScope_Disable (ViSession vi);

ViStatus _VI_FUNC niScope_ResetDevice (ViSession vi);

ViStatus _VI_FUNC niScope_CalSelfCalibrate
(
   ViSession    sessionHandle,
   ViConstString channelNameList,  /* This parameter is currently ignored. */
   ViInt32      option
);

ViStatus _VI_FUNC niScope_revision_query (ViSession vi,
                                          ViChar driverRev[IVI_MAX_MESSAGE_BUF_SIZE],
                                          ViChar instrRev[IVI_MAX_MESSAGE_BUF_SIZE]);

ViStatus _VI_FUNC niScope_ProbeCompensationSignalStart (ViSession vi);

ViStatus _VI_FUNC niScope_ProbeCompensationSignalStop (ViSession vi);

ViStatus _VI_FUNC niScope_IsDeviceReady  (ViRsrc resourceName,
                                            ViConstString channelList,
                                            ViBoolean* deviceReady);


/*--- Error Functions ------------------------------------------------------*/
ViStatus _VI_FUNC niScope_errorHandler (ViSession vi,
                                        ViInt32 errorCode,
                                        ViChar errorSource[MAX_FUNCTION_NAME_SIZE],
                                        ViChar errorDescription[MAX_ERROR_DESCRIPTION]);

ViStatus _VI_FUNC niScope_GetError (ViSession vi,
                                    ViStatus* errorCode,
                                    ViInt32 bufferSize,
                                    ViChar description[]);

ViStatus _VI_FUNC niScope_GetErrorMessage (ViSession vi,
                                           ViStatus errorCode,
                                           ViInt32 bufferSize,
                                           ViChar errorMessage[]);

/*--- Session Locking Functions --------------------------------------------*/
ViStatus _VI_FUNC niScope_LockSession (ViSession vi, ViBoolean* callerHasLock);

ViStatus _VI_FUNC niScope_UnlockSession (ViSession vi, ViBoolean* callerHasLock);

/*--- Typesafe Get, Set, and Check Attribute Functions ---------------------*/
/* Note that the Get functions take a channelList but they return a single
   value.  Therefore, these functions return an error if the return value differs
   among the channels specified in the list. */
ViStatus  _VI_FUNC niScope_GetAttributeViInt32 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt32* value);
ViStatus  _VI_FUNC niScope_SetAttributeViInt32 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt32 value);
ViStatus  _VI_FUNC niScope_CheckAttributeViInt32 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt32 value);

ViStatus  _VI_FUNC niScope_GetAttributeViInt64 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt64* value);
ViStatus  _VI_FUNC niScope_SetAttributeViInt64 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt64 value);
ViStatus  _VI_FUNC niScope_CheckAttributeViInt64 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt64 value);

ViStatus  _VI_FUNC niScope_GetAttributeViReal64 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViReal64* value);
ViStatus  _VI_FUNC niScope_SetAttributeViReal64 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViReal64 value);
ViStatus  _VI_FUNC niScope_CheckAttributeViReal64 (ViSession vi, ViConstString channelList, ViAttr attributeId, ViReal64 value);

ViStatus  _VI_FUNC niScope_GetAttributeViString (ViSession vi, ViConstString channelList, ViAttr attributeId, ViInt32 bufSize, ViChar value[]);
ViStatus  _VI_FUNC niScope_SetAttributeViString (ViSession vi, ViConstString channelList, ViAttr attributeId, ViConstString value);
ViStatus  _VI_FUNC niScope_CheckAttributeViString (ViSession vi, ViConstString channelList, ViAttr attributeId, ViConstString value);

ViStatus  _VI_FUNC niScope_GetAttributeViSession (ViSession vi, ViConstString channelList, ViAttr attributeId, ViSession* value);
ViStatus  _VI_FUNC niScope_SetAttributeViSession (ViSession vi, ViConstString channelList, ViAttr attributeId, ViSession value);
ViStatus  _VI_FUNC niScope_CheckAttributeViSession (ViSession vi, ViConstString channelList, ViAttr attributeId, ViSession value);

ViStatus  _VI_FUNC niScope_GetAttributeViBoolean (ViSession vi, ViConstString channelList, ViAttr attributeId, ViBoolean* value);
ViStatus  _VI_FUNC niScope_SetAttributeViBoolean (ViSession vi, ViConstString channelList, ViAttr attributeId, ViBoolean value);
ViStatus  _VI_FUNC niScope_CheckAttributeViBoolean (ViSession vi, ViConstString channelList, ViAttr attributeId, ViBoolean value);

/*--- NI-5620 Specific Functions ----------------------------------------*/
ViStatus _VI_FUNC niScope_SetDDCFilterCoefficients(ViSession vi,
                                                   ViConstString channel,
                                                   ViInt32 coefficientType,
                                                   ViInt32 numCoefficients,
                                                   ViInt32* coefficients);

ViStatus _VI_FUNC niScope_CalSetSerialDACVoltageEeprom(ViSession vi,
                                          ViReal32 serialDACVolts);

ViStatus _VI_FUNC niScope_CalSetADCVoltageEeprom(ViSession vi,
                                     ViReal32 adcVoltageGain,
                                     ViReal32 adcVoltageOffset);

ViStatus _VI_FUNC niScope_CalSetFREeprom(ViSession vi,
                               ViInt32 numCoefficients,
                               ViReal32* polynomialFitCoefficients);

ViStatus _VI_FUNC niScope_CalGetSerialDACVoltageEeprom(ViSession vi,
                                          ViReal32* serialDACVolts);

ViStatus _VI_FUNC niScope_CalGetADCVoltageEeprom(ViSession vi,
                                     ViReal32* adcVoltageGain,
                                     ViReal32* adcVoltageOffset);

ViStatus _VI_FUNC niScope_CalGetFREeprom(ViSession vi,
                               ViInt32 numCoefficients,
                               ViReal32* polynomialFitCoefficients);


ViStatus _VI_FUNC niScope_AddAccessory(ViSession vi,
                                       ViRsrc resourceName);

ViStatus _VI_FUNC niScope_RemoveAccessory(ViSession vi);


/*--- Register Access Functions --------------------------------------------*/
ViStatus _VI_FUNC niScope_ReadRegister (ViSession vi,
                                        ViInt32 size,
                                        ViInt32 offset,
                                        ViUInt32* value);

ViStatus _VI_FUNC niScope_WriteRegister (ViSession vi,
                                         ViInt32 size,
                                         ViInt32 offset,
                                         ViUInt32 value);

/*--- Scaling and Normalization Functions -------------------------------------*/
ViStatus _VI_FUNC niScope_GetScalingCoefficients   (ViSession vi,
                                                   ViConstString channelList,
                                                   ViInt32 bufferSize,
                                                   struct niScope_coefficientInfo coefficientInfo[],
                                                   ViInt32* numberOfCoefficientSets);

ViStatus _VI_FUNC niScope_GetNormalizationCoefficients   (ViSession vi,
                                                         ViConstString channelList,
                                                         ViInt32 bufferSize,
                                                         struct niScope_coefficientInfo coefficientInfo[],
                                                         ViInt32* numberOfCoefficientSets);

/****************************************************************************
 *------------------------ Error And Completion Codes ----------------------*
 ****************************************************************************/
#define NISCOPE_WARN_INVALID_WFM_ELEMENT              IVISCOPE_WARN_INVALID_WFM_ELEMENT
#define NISCOPE_WARN_HEATER_CIRCUIT_TEMPERATURE       (IVI_SPECIFIC_WARN_BASE+0x001L)
#define NISCOPE_WARN_INVALID_DATA                     (IVI_SPECIFIC_WARN_BASE+0x002L)
#define NISCOPE_WARN_CHANNEL_OVERLOAD                 (IVI_SPECIFIC_WARN_BASE+0x003L)
#define NISCOPE_WARN_AUTOSETUP_NO_SIGNAL              (IVI_SPECIFIC_WARN_BASE+0x004L)
#define NISCOPE_WARN_PLL_UNLOCKED                     (IVI_SPECIFIC_WARN_BASE+0x005L)
#define NISCOPE_WARN_PLL_UNLOCKED_AND_ADC_OVERLOAD    (IVI_SPECIFIC_WARN_BASE+0x006L)
#define NISCOPE_WARN_TIMESTAMP_ROLLOVER               (IVI_SPECIFIC_WARN_BASE+0x007L)
#define NISCOPE_WARN_ADC_OVERLOAD                     (IVI_SPECIFIC_WARN_BASE+0x008L)
#define NISCOPE_WARN_P2P_OVERFLOW                     (IVI_SPECIFIC_WARN_BASE+0x009L)
#define NISCOPE_ERROR_CHANNEL_NOT_ENABLED             IVISCOPE_ERROR_CHANNEL_NOT_ENABLED
#define NISCOPE_ERROR_UNABLE_TO_PERFORM_MEASUREMENT   IVISCOPE_ERROR_UNABLE_TO_PERFORM_MEASUREMENT
#define NISCOPE_ERROR_MAX_TIME_EXCEEDED               IVISCOPE_ERROR_MAX_TIME_EXCEEDED
#define NISCOPE_ERROR_SOFTWARE_FAILURE                (IVI_SPECIFIC_ERROR_BASE+0x001L) /* 0xbffa4001 */
#define NISCOPE_ERROR_HARDWARE_FAILURE                (IVI_SPECIFIC_ERROR_BASE+0x002L)
#define NISCOPE_ERROR_INSUFFICIENT_MEMORY             (IVI_SPECIFIC_ERROR_BASE+0x003L)
#define NISCOPE_ERROR_INVALID_DATA                    (IVI_SPECIFIC_ERROR_BASE+0x004L)
#define NISCOPE_ERROR_GAIN_CAL_FAILURE                (IVI_SPECIFIC_ERROR_BASE+0x005L)
#define NISCOPE_ERROR_SINE_CAL_FAILURE                (IVI_SPECIFIC_ERROR_BASE+0x006L)
#define NISCOPE_ERROR_LIN_CAL_FAILURE                 (IVI_SPECIFIC_ERROR_BASE+0x007L)
#define NISCOPE_ERROR_ADC_CAL_FAILURE                 (IVI_SPECIFIC_ERROR_BASE+0x008L)
#define NISCOPE_ERROR_ACQ_IN_PROGRESS                 (IVI_SPECIFIC_ERROR_BASE+0x009L)
#define NISCOPE_ERROR_DATA_NOT_AVAILABLE              (IVI_SPECIFIC_ERROR_BASE+0x00AL)
#define NISCOPE_ERROR_HEATER_CIRCUIT_CAL_FAILURE      (IVI_SPECIFIC_ERROR_BASE+0x00BL)
#define NISCOPE_ERROR_FLEXRES_CONFIG_CORRUPT          (IVI_SPECIFIC_ERROR_BASE+0x00CL)
#define NISCOPE_ERROR_GAIN_OFFSET_CAL_FAILURE         (IVI_SPECIFIC_ERROR_BASE+0x00DL)
#define NISCOPE_ERROR_CREATE_THREAD                   (IVI_SPECIFIC_ERROR_BASE+0x00EL)
#define NISCOPE_ERROR_WRONG_PASSWORD                  (IVI_SPECIFIC_ERROR_BASE+0x00FL)
#define NISCOPE_ERROR_INVALID_GAIN                    (IVI_SPECIFIC_ERROR_BASE+0x010L)
#define NISCOPE_ERROR_INVALID_CAL_SESSION             (IVI_SPECIFIC_ERROR_BASE+0x013L)
#define NISCOPE_ERROR_BAD_MEASUREMENT                 (IVI_SPECIFIC_ERROR_BASE+0x014L)
#define NISCOPE_ERROR_BUFFER_NOT_ACQUIRED             (IVI_SPECIFIC_ERROR_BASE+0x015L)
#define NISCOPE_ERROR_TRIGGER_HAS_NOT_OCCURRED        (IVI_SPECIFIC_ERROR_BASE+0x016L)
#define NISCOPE_ERROR_ILLEGAL_RELATIVE_TO             (IVI_SPECIFIC_ERROR_BASE+0x017L)
#define NISCOPE_ERROR_DATA_OVERWRITTEN                (IVI_SPECIFIC_ERROR_BASE+0x018L)
#define NISCOPE_ERROR_INVALID_TIMESTAMP_EVENT_TAG     (IVI_SPECIFIC_ERROR_BASE+0x01AL)
#define NISCOPE_ERROR_TIMEOUT_TRANSFERRING_TIMESTAMPS (IVI_SPECIFIC_ERROR_BASE+0x01BL)
#define NISCOPE_ERROR_TIMEOUT_CHECKING_STATUS         (IVI_SPECIFIC_ERROR_BASE+0x01CL)
#define NISCOPE_ERROR_TIMEOUT_TRANSFERRING_DATA       (IVI_SPECIFIC_ERROR_BASE+0x01DL)
#define NISCOPE_ERROR_PLL_FAILURE                     (IVI_SPECIFIC_ERROR_BASE+0x01EL)
#define NISCOPE_ERROR_PAR_TO_SER_CONV_FAILURE         (IVI_SPECIFIC_ERROR_BASE+0x01FL)
#define NISCOPE_ERROR_DMA_CONFIG_ERROR                (IVI_SPECIFIC_ERROR_BASE+0x020L)
#define NISCOPE_ERROR_ILLEGAL_USER_OFFSET             (IVI_SPECIFIC_ERROR_BASE+0x021L)
#define NISCOPE_ERROR_NOT_A_SCOPE                     (IVI_SPECIFIC_ERROR_BASE+0x022L)
#define NISCOPE_ERROR_TIMEOUT_CLEARING_TIO            (IVI_SPECIFIC_ERROR_BASE+0x023L)
#define NISCOPE_ERROR_RIS_DID_NOT_COMPLETE            (IVI_SPECIFIC_ERROR_BASE+0x024L)
#define NISCOPE_ERROR_INVALID_RIS_METHOD              (IVI_SPECIFIC_ERROR_BASE+0x025L)
#define NISCOPE_ERROR_INVALID_RIS_NUM_AVERAGES        (IVI_SPECIFIC_ERROR_BASE+0x026L)
#define NISCOPE_ERROR_ILLEGAL_DATATYPE                (IVI_SPECIFIC_ERROR_BASE+0x027L)
#define NISCOPE_ERROR_ATTRIBUTES_DIFFER_BY_CHANNEL    (IVI_SPECIFIC_ERROR_BASE+0x028L)
#define NISCOPE_ERROR_TRIGGER_DELAY_INVALID_WITH_RIS  (IVI_SPECIFIC_ERROR_BASE+0x029L)
#define NISCOPE_ERROR_INITIATE_NOT_CALLED             (IVI_SPECIFIC_ERROR_BASE+0x02AL)
#define NISCOPE_ERROR_INVALID_FUNCTION_USE            (IVI_SPECIFIC_ERROR_BASE+0x02BL)
#define NISCOPE_ERROR_HOLDOFF_DELAY_NONZERO           (IVI_SPECIFIC_ERROR_BASE+0x02CL)
#define NISCOPE_ERROR_CHANNEL_NAME_TOO_LONG           (IVI_SPECIFIC_ERROR_BASE+0x02DL)
#define NISCOPE_ERROR_DIGITIZER_ALREADY_IN_USE        (IVI_SPECIFIC_ERROR_BASE+0x02EL)
#define NISCOPE_ERROR_SIM_MODEL_NOT_SUPPORTED         (IVI_SPECIFIC_ERROR_BASE+0X02FL)
#define NISCOPE_ERROR_SPECIFICDLL_LOAD_FAILURE        (IVI_SPECIFIC_ERROR_BASE+0X030L)
#define NISCOPE_ERROR_SPECIFICDLL_GET_ADDRESS_FAILURE (IVI_SPECIFIC_ERROR_BASE+0X031L)
#define NISCOPE_ERROR_TRIGGER_TYPE_INVALID            (IVI_SPECIFIC_ERROR_BASE+0X032L)
#define NISCOPE_ERROR_INVALID_FETCH_PARAMETERS        (IVI_SPECIFIC_ERROR_BASE+0X033L)
#define NISCOPE_ERROR_EXT_CAL_NOT_COMPLETE            (IVI_SPECIFIC_ERROR_BASE+0X034L)
#define NISCOPE_ERROR_EXT_CAL_CONSTS_INVALID          (IVI_SPECIFIC_ERROR_BASE+0X035L)
#define NISCOPE_ERROR_INVALID_NUM_WAVEFORMS           (IVI_SPECIFIC_ERROR_BASE+0X036L)
#define NISCOPE_ERROR_DIGITIZER_NOT_SUPPORTED_WITH_ACCESSORY  (IVI_SPECIFIC_ERROR_BASE+0X037L)
#define NISCOPE_ERROR_DIGITAL_TRIGGER_NOT_SUPPORTED_WITH_RIS  (IVI_SPECIFIC_ERROR_BASE+0X038L)
#define NISCOPE_ERROR_SELF_CAL_NOT_COMPLETE           (IVI_SPECIFIC_ERROR_BASE+0X039L)
#define NISCOPE_ERROR_INVALID_SESSION                 0xBFFA1190


/*- niScopeObsolete.h included for backwards compatibility -*/
#include "niScopeObsolete.h"

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NISCOPE_HEADER */
