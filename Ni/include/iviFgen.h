/******************************************************************************
 *                            I V I - F G E N
 *-----------------------------------------------------------------------------
 *    Copytight (c) 1998-2009 National Instruments.  All Rights Reserved.
 *-----------------------------------------------------------------------------
 *
 * Title:       ivifgen.h
 * Purpose:     IviFgen Class declarations for the Base and Extended
 *              IviFgen Capabilities.
 ******************************************************************************/
 
#ifndef IVIFGEN_HEADER
#define IVIFGEN_HEADER

#include <ivi.h>

#ifdef _CVI_
#pragma EnableLibraryRuntimeChecking
#endif

#if defined(__cplusplus) || defined(__cpluplus__)
extern "C" {
#endif

/******************************************************************************
 *------------------ Instrument Driver Revision Information ------------------*
 ******************************************************************************/

#define IVIFGEN_MAJOR_VERSION               (4L)
#define IVIFGEN_MINOR_VERSION               (0L)

#define IVIFGEN_CLASS_SPEC_MAJOR_VERSION    (3L)
#define IVIFGEN_CLASS_SPEC_MINOR_VERSION    (0L)

#define IVIFGEN_DRIVER_VENDOR               "National Instruments"
#ifdef	_IVI_mswin64_
#define IVIFGEN_DRIVER_DESCRIPTION          "IviFgen Class Driver [Compiled for 64-bit.]"
#else
#define IVIFGEN_DRIVER_DESCRIPTION          "IviFgen Class Driver"
#endif

/******************************************************************************
 *---------------------- IviFgen Class Attribute Defines ---------------------*
 ******************************************************************************/

    /*- IVI Inherent Attributes -*/
        /*- User Options -*/
#define IVIFGEN_ATTR_CACHE                     IVI_ATTR_CACHE                       /* ViBoolean */
#define IVIFGEN_ATTR_RANGE_CHECK               IVI_ATTR_RANGE_CHECK                 /* ViBoolean */
#define IVIFGEN_ATTR_QUERY_INSTRUMENT_STATUS   IVI_ATTR_QUERY_INSTRUMENT_STATUS		/* ViBoolean */
#define IVIFGEN_ATTR_RECORD_COERCIONS          IVI_ATTR_RECORD_COERCIONS            /* ViBoolean */
#define IVIFGEN_ATTR_SIMULATE                  IVI_ATTR_SIMULATE                    /* ViBoolean */
#define IVIFGEN_ATTR_INTERCHANGE_CHECK         IVI_ATTR_INTERCHANGE_CHECK           /* ViBoolean */
#define IVIFGEN_ATTR_SPY                       IVI_ATTR_SPY                         /* ViBoolean */
#define IVIFGEN_ATTR_USE_SPECIFIC_SIMULATION   IVI_ATTR_USE_SPECIFIC_SIMULATION     /* ViBoolean */

        /*- Instrument Capabilities -*/
#define IVIFGEN_ATTR_GROUP_CAPABILITIES        IVI_ATTR_GROUP_CAPABILITIES          /* ViString, read-only */
#define IVIFGEN_ATTR_FUNCTION_CAPABILITIES     IVI_ATTR_FUNCTION_CAPABILITIES       /* ViString, read-only */

        /*- Class Driver Information -*/
#define IVIFGEN_ATTR_CLASS_DRIVER_PREFIX                         IVI_ATTR_CLASS_DRIVER_PREFIX         /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_VENDOR                         IVI_ATTR_CLASS_DRIVER_VENDOR         /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_DESCRIPTION                    IVI_ATTR_CLASS_DRIVER_DESCRIPTION    /* ViString, read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIFGEN_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION       IVI_ATTR_CLASS_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Specific Driver Information -*/    
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_PREFIX                      IVI_ATTR_SPECIFIC_DRIVER_PREFIX      /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_LOCATOR                     IVI_ATTR_SPECIFIC_DRIVER_LOCATOR     /* ViString, read-only */
#define IVIFGEN_ATTR_IO_RESOURCE_DESCRIPTOR                      IVI_ATTR_IO_RESOURCE_DESCRIPTOR      /* ViString, read-only */
#define IVIFGEN_ATTR_LOGICAL_NAME                                IVI_ATTR_LOGICAL_NAME                /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_VENDOR                      IVI_ATTR_SPECIFIC_DRIVER_VENDOR      /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_DESCRIPTION                 IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION /* ViString, read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MAJOR_VERSION  /* ViInt32,  read-only */
#define IVIFGEN_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION    IVI_ATTR_SPECIFIC_DRIVER_CLASS_SPEC_MINOR_VERSION  /* ViInt32,  read-only */

        /*- Instrument Information -*/    
#define IVIFGEN_ATTR_INSTRUMENT_FIRMWARE_REVISION     IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION /* ViString, read-only */
#define IVIFGEN_ATTR_INSTRUMENT_MANUFACTURER          IVI_ATTR_INSTRUMENT_MANUFACTURER      /* ViString, read-only */
#define IVIFGEN_ATTR_INSTRUMENT_MODEL                 IVI_ATTR_INSTRUMENT_MODEL             /* ViString, read-only */
#define IVIFGEN_ATTR_SUPPORTED_INSTRUMENT_MODELS      IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS

        /*- Version Information -*/
#define IVIFGEN_ATTR_CLASS_DRIVER_REVISION            IVI_ATTR_CLASS_DRIVER_REVISION              /* ViString, read-only */

#define IVIFGEN_ATTR_SPECIFIC_DRIVER_REVISION         IVI_ATTR_SPECIFIC_DRIVER_REVISION             /* ViString, read-only */

        /*- Driver Setup Information -*/
#define IVIFGEN_ATTR_DRIVER_SETUP                     IVI_ATTR_DRIVER_SETUP                /* ViString */

    /*- IviFgen Fundamental Attributes -*/
#define IVIFGEN_ATTR_CHANNEL_COUNT              IVI_ATTR_CHANNEL_COUNT              /* (ViInt32), read-only */
#define IVIFGEN_ATTR_OUTPUT_MODE                (IVI_CLASS_PUBLIC_ATTR_BASE + 1L)   /* (ViInt32) */
#define IVIFGEN_ATTR_REF_CLOCK_SOURCE           (IVI_CLASS_PUBLIC_ATTR_BASE + 2L)   /* (ViInt32) */
#define IVIFGEN_ATTR_OUTPUT_ENABLED             (IVI_CLASS_PUBLIC_ATTR_BASE + 3L)   /* (ViBoolean,  Multi-Channel) */
#define IVIFGEN_ATTR_OUTPUT_IMPEDANCE           (IVI_CLASS_PUBLIC_ATTR_BASE + 4L)   /* (ViReal64,   Multi-Channel) */
#define IVIFGEN_ATTR_OPERATION_MODE             (IVI_CLASS_PUBLIC_ATTR_BASE + 5L)   /* (ViInt32,    Multi-Channel) */

    /*- IviFgenStdFunc Extended Attributes -*/
#define IVIFGEN_ATTR_FUNC_WAVEFORM              (IVI_CLASS_PUBLIC_ATTR_BASE + 101L)  /* (ViInt32,  Multi-Channel)   */
#define IVIFGEN_ATTR_FUNC_AMPLITUDE             (IVI_CLASS_PUBLIC_ATTR_BASE + 102L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_DC_OFFSET             (IVI_CLASS_PUBLIC_ATTR_BASE + 103L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_FREQUENCY             (IVI_CLASS_PUBLIC_ATTR_BASE + 104L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_START_PHASE           (IVI_CLASS_PUBLIC_ATTR_BASE + 105L)  /* (ViReal64,  Multi-Channel)  */
#define IVIFGEN_ATTR_FUNC_DUTY_CYCLE_HIGH       (IVI_CLASS_PUBLIC_ATTR_BASE + 106L)  /* (ViReal64,  Multi-Channel)  */

    /*- IviFgenArbWfm Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_WAVEFORM_HANDLE        (IVI_CLASS_PUBLIC_ATTR_BASE + 201L)  /* (ViInt32,  Multi-Channel)   */
#define IVIFGEN_ATTR_ARB_GAIN                   (IVI_CLASS_PUBLIC_ATTR_BASE + 202L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_ARB_OFFSET                 (IVI_CLASS_PUBLIC_ATTR_BASE + 203L)  /* (ViReal64, Multi-Channel)  */
#define IVIFGEN_ATTR_ARB_SAMPLE_RATE            (IVI_CLASS_PUBLIC_ATTR_BASE + 204L)  /* (ViReal64)  */

#define IVIFGEN_ATTR_MAX_NUM_WAVEFORMS          (IVI_CLASS_PUBLIC_ATTR_BASE + 205L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_WAVEFORM_QUANTUM           (IVI_CLASS_PUBLIC_ATTR_BASE + 206L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MIN_WAVEFORM_SIZE          (IVI_CLASS_PUBLIC_ATTR_BASE + 207L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_WAVEFORM_SIZE          (IVI_CLASS_PUBLIC_ATTR_BASE + 208L)  /* (ViInt32, Read-only)   */

    /*- IviFgenArbFrequency Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_FREQUENCY              (IVI_CLASS_PUBLIC_ATTR_BASE + 209L)  /* (ViReal64, Multi-Channel)  */    

    /*- IviFgenArbSeq Extended Attributes -*/
#define IVIFGEN_ATTR_ARB_SEQUENCE_HANDLE        (IVI_CLASS_PUBLIC_ATTR_BASE + 211L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_MAX_NUM_SEQUENCES          (IVI_CLASS_PUBLIC_ATTR_BASE + 212L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MIN_SEQUENCE_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE + 213L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_SEQUENCE_LENGTH        (IVI_CLASS_PUBLIC_ATTR_BASE + 214L)  /* (ViInt32, Read-only)   */
#define IVIFGEN_ATTR_MAX_LOOP_COUNT             (IVI_CLASS_PUBLIC_ATTR_BASE + 215L)  /* (ViInt32, Read-only)   */

    /*- IviFgenTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_TRIGGER_SOURCE             (IVI_CLASS_PUBLIC_ATTR_BASE + 302L)  /* (ViInt32, Multi-Channel)   */

    /*- IviFgenInternalTrigger Extended Attributes -*/
#define IVIFGEN_ATTR_INTERNAL_TRIGGER_RATE      (IVI_CLASS_PUBLIC_ATTR_BASE + 310L)  /* (ViReal64)   */  

    /*- IviFgenBurst Extended Attributes -*/
#define IVIFGEN_ATTR_BURST_COUNT                (IVI_CLASS_PUBLIC_ATTR_BASE + 350L)  /* (ViInt32, Multi-Channel)   */  

    /*- IviFgenModulateAM Extended Attributes -*/
#define IVIFGEN_ATTR_AM_ENABLED                 (IVI_CLASS_PUBLIC_ATTR_BASE + 401L)  /* (ViBoolean, Multi-Channel) */
#define IVIFGEN_ATTR_AM_SOURCE                  (IVI_CLASS_PUBLIC_ATTR_BASE + 402L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_AM_INTERNAL_DEPTH          (IVI_CLASS_PUBLIC_ATTR_BASE + 403L)  /* (ViReal64)  */
#define IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM       (IVI_CLASS_PUBLIC_ATTR_BASE + 404L)  /* (ViInt32)   */
#define IVIFGEN_ATTR_AM_INTERNAL_FREQUENCY      (IVI_CLASS_PUBLIC_ATTR_BASE + 405L)  /* (ViReal64)  */

    /*- IviFgenModulateFM Extended Attributes -*/
#define IVIFGEN_ATTR_FM_ENABLED                 (IVI_CLASS_PUBLIC_ATTR_BASE + 501L)  /* (ViBoolean, Multi-Channel) */
#define IVIFGEN_ATTR_FM_SOURCE                  (IVI_CLASS_PUBLIC_ATTR_BASE + 502L)  /* (ViInt32, Multi-Channel)   */
#define IVIFGEN_ATTR_FM_INTERNAL_DEVIATION      (IVI_CLASS_PUBLIC_ATTR_BASE + 503L)  /* (ViReal64)  */
#define IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM       (IVI_CLASS_PUBLIC_ATTR_BASE + 504L)  /* (ViInt32)   */
#define IVIFGEN_ATTR_FM_INTERNAL_FREQUENCY      (IVI_CLASS_PUBLIC_ATTR_BASE + 505L)  /* (ViReal64)  */
      
/******************************************************************************
 *------------------- IviFgen Class Attribute Value Defines ------------------*
 ******************************************************************************/

   /*- Defined valued for attribute IVIFGEN_ATTR_OUTPUT_MODE -*/
#define IVIFGEN_VAL_OUTPUT_FUNC                         (0L)
#define IVIFGEN_VAL_OUTPUT_ARB                          (1L)
#define IVIFGEN_VAL_OUTPUT_SEQ                          (2L)

#define IVIFGEN_VAL_OUT_MODE_CLASS_EXT_BASE             (500L)
#define IVIFGEN_VAL_OUT_MODE_SPECIFIC_EXT_BASE          (1000L)

   /*- Defined valued for attribute IVIFGEN_ATTR_OPERATION_MODE -*/
#define IVIFGEN_VAL_OPERATE_CONTINUOUS                  (0L)
#define IVIFGEN_VAL_OPERATE_BURST                       (1L)

#define IVIFGEN_VAL_OP_MODE_CLASS_EXT_BASE              (500L)
#define IVIFGEN_VAL_OP_MODE_SPECIFIC_EXT_BASE           (1000L)

   /*- Defined values for attribute IVIFGEN_ATTR_REF_CLOCK_SOURCE -*/
#define IVIFGEN_VAL_REF_CLOCK_INTERNAL                  (0L)
#define IVIFGEN_VAL_REF_CLOCK_EXTERNAL                  (1L)
#define IVIFGEN_VAL_REF_CLOCK_RTSI_CLOCK                (101L)

#define IVIFGEN_VAL_CLK_SRC_CLASS_EXT_BASE              (500L)
#define IVIFGEN_VAL_CLK_SRC_SPECIFIC_EXT_BASE           (1000L)

   /*- Defined values for attribute IVIFGEN_ATTR_FUNC_WAVEFORM -*/
#define IVIFGEN_VAL_WFM_SINE                            (1L)
#define IVIFGEN_VAL_WFM_SQUARE                          (2L)
#define IVIFGEN_VAL_WFM_TRIANGLE                        (3L)
#define IVIFGEN_VAL_WFM_RAMP_UP                         (4L)
#define IVIFGEN_VAL_WFM_RAMP_DOWN                       (5L)
#define IVIFGEN_VAL_WFM_DC                              (6L)

#define IVIFGEN_VAL_WFM_CLASS_EXT_BASE                  (500L)
#define IVIFGEN_VAL_WFM_SPECIFIC_EXT_BASE               (1000L)

    /*- Defined values for attribute IVIFGEN_ATTR_TRIGGER_SOURCE -*/
#define IVIFGEN_VAL_EXTERNAL                            (1L)
#define IVIFGEN_VAL_SOFTWARE_TRIG                       (2L)
#define IVIFGEN_VAL_INTERNAL_TRIGGER                    (3L) 
#define IVIFGEN_VAL_TTL0                                (111L)
#define IVIFGEN_VAL_TTL1                                (112L)
#define IVIFGEN_VAL_TTL2                                (113L)
#define IVIFGEN_VAL_TTL3                                (114L)
#define IVIFGEN_VAL_TTL4                                (115L)
#define IVIFGEN_VAL_TTL5                                (116L)
#define IVIFGEN_VAL_TTL6                                (117L)
#define IVIFGEN_VAL_TTL7                                (118L)
#define IVIFGEN_VAL_ECL0                                (119L)
#define IVIFGEN_VAL_ECL1                                (120L)
#define IVIFGEN_VAL_PXI_STAR                            (131L)
#define IVIFGEN_VAL_RTSI_0                              (141L)
#define IVIFGEN_VAL_RTSI_1                              (142L)
#define IVIFGEN_VAL_RTSI_2                              (143L)
#define IVIFGEN_VAL_RTSI_3                              (144L)
#define IVIFGEN_VAL_RTSI_4                              (145L)
#define IVIFGEN_VAL_RTSI_5                              (146L)
#define IVIFGEN_VAL_RTSI_6                              (147L)

#define IVIFGEN_VAL_TRIG_SRC_CLASS_EXT_BASE             (500L)
#define IVIFGEN_VAL_TRIG_SRC_SPECIFIC_EXT_BASE          (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_AM_SOURCE -*/
#define IVIFGEN_VAL_AM_INTERNAL                         (0L)
#define IVIFGEN_VAL_AM_EXTERNAL                         (1L)

#define IVIFGEN_VAL_AM_SOURCE_CLASS_EXT_BASE            (500L)
#define IVIFGEN_VAL_AM_SOURCE_SPECIFIC_EXT_BASE         (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_AM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_AM_INTERNAL_SINE                    (1L)
#define IVIFGEN_VAL_AM_INTERNAL_SQUARE                  (2L)
#define IVIFGEN_VAL_AM_INTERNAL_TRIANGLE                (3L)
#define IVIFGEN_VAL_AM_INTERNAL_RAMP_UP                 (4L)
#define IVIFGEN_VAL_AM_INTERNAL_RAMP_DOWN               (5L)

#define IVIFGEN_VAL_AM_INTERNAL_WFM_CLASS_EXT_BASE      (500L)
#define IVIFGEN_VAL_AM_INTERNAL_WFM_SPECIFIC_EXT_BASE   (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_FM_SOURCE -*/
#define IVIFGEN_VAL_FM_INTERNAL                         (0L)
#define IVIFGEN_VAL_FM_EXTERNAL                         (1L)

#define IVIFGEN_VAL_FM_SOURCE_CLASS_EXT_BASE            (500L)
#define IVIFGEN_VAL_FM_SOURCE_SPECIFIC_EXT_BASE         (1000L)

  /*- Defined values for attribute IVIFGEN_ATTR_FM_INTERNAL_WAVEFORM -*/
#define IVIFGEN_VAL_FM_INTERNAL_SINE                    (1L)
#define IVIFGEN_VAL_FM_INTERNAL_SQUARE                  (2L)
#define IVIFGEN_VAL_FM_INTERNAL_TRIANGLE                (3L)
#define IVIFGEN_VAL_FM_INTERNAL_RAMP_UP                 (4L)
#define IVIFGEN_VAL_FM_INTERNAL_RAMP_DOWN               (5L)

#define IVIFGEN_VAL_FM_INTERNAL_WFM_CLASS_EXT_BASE      (500L)
#define IVIFGEN_VAL_FM_INTERNAL_WFM_SPECIFIC_EXT_BASE   (1000L)

   /*- Defined values for waveformHandle parameter for function IviFgen_ClearArbWaveform -*/
#define IVIFGEN_VAL_ALL_WAVEFORMS                       (-1L)

   /*- Defined values for sequenceHandle parameter for function IviFgen_ClearArbSequence -*/
#define IVIFGEN_VAL_ALL_SEQUENCES                       (-1L)

/******************************************************************************
 *----------- IviFgen Class Instrument Driver Function Declarations ----------*
 ******************************************************************************/
   /*- Required VXIplug&play Functions -*/
ViStatus _VI_FUNC IviFgen_init (ViRsrc logicalName, 
                                ViBoolean IDQuery,
                                ViBoolean resetDevice, 
                                ViSession *vi);

ViStatus _VI_FUNC IviFgen_close (ViSession vi);

ViStatus _VI_FUNC IviFgen_reset (ViSession vi);

ViStatus _VI_FUNC IviFgen_self_test (ViSession vi, 
                                     ViInt16* selfTestResult,
                                     ViChar selfTestMessage[]);

ViStatus _VI_FUNC IviFgen_error_query (ViSession vi, 
                                       ViInt32 *errorCode, 
                                       ViChar errorMessage[]);

ViStatus _VI_FUNC IviFgen_error_message (ViSession vi, 
                                         ViStatus statusCode,
                                         ViChar message[]);

ViStatus _VI_FUNC IviFgen_revision_query (ViSession vi, 
                                          ViChar driverRev[],
                                          ViChar instrRev[]);
                                           
    /*- Utility Functions -*/
ViStatus _VI_FUNC IviFgen_InvalidateAllAttributes (ViSession vi);

ViStatus _VI_FUNC IviFgen_ResetWithDefaults (ViSession vi);

ViStatus _VI_FUNC IviFgen_Disable (ViSession vi);

   /*- Required IVI Functions -*/
ViStatus _VI_FUNC IviFgen_InitWithOptions (ViRsrc logicalName, 
                                           ViBoolean IDQuery,
                                           ViBoolean resetDevice, 
                                           ViConstString optionString, 
                                           ViSession *vi);

   /*- Set, Get, and Check Attribute Functions -*/
ViStatus _VI_FUNC IviFgen_GetAttributeViInt32 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId, 
                                               ViInt32 *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViInt32 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId,
                                               ViInt32 value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViInt32 (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attributeId,
                                                 ViInt32 value);

#ifdef _IVI_64BIT_ATTR_DEFINED_
ViStatus _VI_FUNC IviFgen_GetAttributeViInt64 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId, 
                                               ViInt64 *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViInt64 (ViSession vi, 
                                               ViConstString channelName,
                                               ViAttr attributeId,
                                               ViInt64 value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViInt64 (ViSession vi,
                                                 ViConstString channelName,
                                                 ViAttr attributeId,
                                                 ViInt64 value);
#endif

ViStatus _VI_FUNC IviFgen_GetAttributeViReal64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId, 
                                                ViReal64 *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViReal64 (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId,
                                                ViReal64 value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViReal64 (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId, 
                                                  ViReal64 value);

ViStatus _VI_FUNC IviFgen_GetAttributeViString (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId, 
                                                ViInt32 bufferSize,
                                                ViChar value[]);

ViStatus _VI_FUNC IviFgen_SetAttributeViString (ViSession vi, 
                                                ViConstString channelName,
                                                ViAttr attributeId, 
                                                ViConstString value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViString (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViAttr attributeId, 
                                                  ViConstString value);

ViStatus _VI_FUNC IviFgen_GetAttributeViBoolean (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViBoolean *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViBoolean (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViBoolean value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViBoolean (ViSession vi, 
                                                   ViConstString channelName,
                                                   ViAttr attributeId, 
                                                   ViBoolean value);

ViStatus _VI_FUNC IviFgen_GetAttributeViSession (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViSession *value);

ViStatus _VI_FUNC IviFgen_SetAttributeViSession (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViAttr attributeId, 
                                                 ViSession value);

ViStatus _VI_FUNC IviFgen_CheckAttributeViSession (ViSession vi, 
                                                   ViConstString channelName,
                                                   ViAttr attributeId, 
                                                   ViSession value);

   /*- Lock and Unlock Functions -*/
ViStatus _VI_FUNC IviFgen_LockSession (ViSession vi, 
                                       ViBoolean *callerHasLock);

ViStatus _VI_FUNC IviFgen_UnlockSession (ViSession vi, 
                                         ViBoolean *callerHasLock);

   /*- Error Information Functions -*/
ViStatus _VI_FUNC IviFgen_GetError (ViSession vi, 
                                    ViStatus *errorCode,
                                    ViInt32 bufferSize,
                                    ViChar description[]);

ViStatus _VI_FUNC IviFgen_ClearError (ViSession vi);

    /*- Interchangeability Checking Functions -*/
ViStatus _VI_FUNC IviFgen_GetNextInterchangeWarning (ViSession vi, 
                                                     ViInt32 bufferSize, 
                                                     ViChar warning[]);

ViStatus _VI_FUNC IviFgen_ClearInterchangeWarnings (ViSession vi);
ViStatus _VI_FUNC IviFgen_ResetInterchangeCheck (ViSession vi);

ViStatus _VI_FUNC IviFgen_GetNextCoercionRecord (ViSession vi, 
                                                 ViInt32 bufferSize, 
                                                 ViChar record[]);

ViStatus _VI_FUNC IviFgen_GetSpecificDriverCHandle (ViSession vi,
                                                    ViSession* specificDriverCHandle);
   
ViStatus _VI_FUNC IviFgen_GetSpecificDriverIUnknownPtr (ViSession vi,
                                                       void* specificDriverIUnknownPtr);
   /*- IviFgenBase Capability Group  -*/
ViStatus _VI_FUNC IviFgen_ConfigureOutputMode (ViSession vi, 
                                               ViInt32 outputMode);
ViStatus _VI_FUNC IviFgen_ConfigureOperationMode (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 operationMode);

ViStatus _VI_FUNC IviFgen_ConfigureRefClockSource (ViSession vi, 
                                                   ViInt32 refClockSource);

ViStatus _VI_FUNC IviFgen_ConfigureOutputImpedance (ViSession vi, 
                                                    ViConstString channelName,
                                                    ViReal64 outputImpedance);

ViStatus _VI_FUNC IviFgen_ConfigureOutputEnabled (ViSession vi, 
                                                  ViConstString channelName,
                                                  ViBoolean enabled);

ViStatus _VI_FUNC IviFgen_GetChannelName (ViSession vi,
                                          ViInt32 index,
                                          ViInt32 bufferSize,
                                          ViChar name[]);

ViStatus _VI_FUNC IviFgen_InitiateGeneration (ViSession vi);

ViStatus _VI_FUNC IviFgen_AbortGeneration    (ViSession vi);

   /*- IviFgenStdFunc Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureStandardWaveform (ViSession vi, 
                                                     ViConstString channelName,
                                                     ViInt32 waveform, 
                                                     ViReal64 amplitude,
                                                     ViReal64 dcOffset, 
                                                     ViReal64 frequency,
                                                     ViReal64 startPhase);

    /*- IviFgenArbWfm Extension Group -*/
ViStatus _VI_FUNC IviFgen_QueryArbWfmCapabilities (ViSession vi, 
                                                   ViInt32 *maxNumWfms,
                                                   ViInt32 *wfmQuantum,
                                                   ViInt32 *minWfmSize,
                                                   ViInt32 *maxWfmSize);

ViStatus _VI_FUNC IviFgen_CreateArbWaveform (ViSession vi,
                                             ViInt32 wfmSize,
                                             ViReal64 wfmData[], 
                                             ViInt32 *wfmHandle);

ViStatus _VI_FUNC IviFgen_ConfigureSampleRate (ViSession vi, 
                                               ViReal64 sampleRate);

ViStatus _VI_FUNC IviFgen_ConfigureArbWaveform (ViSession vi, 
                                                ViConstString channelName,
                                                ViInt32 wfmHandle,
                                                ViReal64 arbGain,
                                                ViReal64 arbOffset);

ViStatus _VI_FUNC IviFgen_ClearArbWaveform (ViSession vi, 
                                            ViInt32 wfmHandle);

    /*- IviFgenArbFrequency Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureArbFrequency (ViSession vi, 
                                                 ViConstString channelName,
                                                 ViReal64 frequency);

    /*- IviFgenArbSeq Extension Group -*/ 
ViStatus _VI_FUNC IviFgen_QueryArbSeqCapabilities (ViSession vi, 
                                                   ViInt32 *maxNumSeqs,
                                                   ViInt32 *minSeqLength, 
                                                   ViInt32 *maxSeqLength,
                                                   ViInt32 *maxLoopCount);

ViStatus _VI_FUNC IviFgen_CreateArbSequence (ViSession vi, 
                                             ViInt32 seqLength,
                                             ViInt32 wfmHandle[], 
                                             ViInt32 wfmLoopCount[],
                                             ViInt32 *seqHandle);

ViStatus _VI_FUNC IviFgen_ConfigureArbSequence (ViSession vi, 
                                                ViConstString channelName,
                                                ViInt32 seqHandle,
                                                ViReal64 arbGain,
                                                ViReal64 arbOffset);

ViStatus _VI_FUNC IviFgen_ClearArbSequence (ViSession vi, 
                                            ViInt32 seqHandle);

ViStatus _VI_FUNC IviFgen_ClearArbMemory (ViSession vi);

    /*- IviFgenTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureTriggerSource (ViSession vi,
                                                  ViConstString channelName,
                                                  ViInt32 trigSource);

    /*- IviFgenInternalTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureInternalTriggerRate (ViSession vi,
                                                        ViReal64 rate);

    /*- IviFgenSoftwareTrigger Extension Group -*/
ViStatus _VI_FUNC IviFgen_SendSoftwareTrigger (ViSession vi);

    /*- IviFgenBurst Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureBurstCount (ViSession vi,
                                               ViConstString channelName,
                                               ViInt32 count);

    /*- IviFgenModulateAM Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureAMEnabled (ViSession vi,
                                              ViConstString channelName,
                                              ViBoolean enabled);

ViStatus _VI_FUNC IviFgen_ConfigureAMSource (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 source);

ViStatus _VI_FUNC IviFgen_ConfigureAMInternal (ViSession vi, 
                                               ViReal64 amdepth,
                                               ViInt32 amWaveform,
                                               ViReal64 amFrequency);

    /*- IviFgenModulateFM Extension Group -*/
ViStatus _VI_FUNC IviFgen_ConfigureFMEnabled (ViSession vi,
                                              ViConstString channelName,
                                              ViBoolean enabled);

ViStatus _VI_FUNC IviFgen_ConfigureFMSource (ViSession vi,
                                             ViConstString channelName,
                                             ViInt32 source);

ViStatus _VI_FUNC IviFgen_ConfigureFMInternal (ViSession vi, 
                                               ViReal64 fmdeviation,
                                               ViInt32 fmWaveform,
                                               ViReal64 fmFrequency);
                                                     
/******************************************************************************
 *----------------- IviFgen Class Error And Completion Codes -----------------*
 ******************************************************************************/
#define IVIFGEN_ERROR_NO_WFMS_AVAILABLE       (IVI_CLASS_ERROR_BASE + 4L)
#define IVIFGEN_ERROR_WFM_IN_USE              (IVI_CLASS_ERROR_BASE + 8L)
#define IVIFGEN_ERROR_NO_SEQS_AVAILABLE       (IVI_CLASS_ERROR_BASE + 9L)
#define IVIFGEN_ERROR_SEQ_IN_USE              (IVI_CLASS_ERROR_BASE + 13L)
#define IVIFGEN_ERROR_TRIGGER_NOT_SOFTWARE    (IVI_CROSS_CLASS_ERROR_BASE + 1L)

#define IVIFGEN_ERRMSG_NO_WFMS_AVAILABLE      "The function generator's waveform memory is full."
#define IVIFGEN_ERRMSG_WFM_IN_USE             "The waveform is currently in use."
#define IVIFGEN_ERRMSG_NO_SEQS_AVAILABLE      "The function generator's sequence memory is full."
#define IVIFGEN_ERRMSG_SEQ_IN_USE             "The sequence is currently in use."
#define IVIFGEN_ERRMSG_TRIGGER_NOT_SOFTWARE   "The trigger source is not software trigger."

#define IVIFGEN_ERROR_CODES_AND_MSGS \
        { IVIFGEN_ERROR_NO_WFMS_AVAILABLE,    IVIFGEN_ERRMSG_NO_WFMS_AVAILABLE   }, \
        { IVIFGEN_ERROR_WFM_IN_USE,           IVIFGEN_ERRMSG_WFM_IN_USE          }, \
        { IVIFGEN_ERROR_NO_SEQS_AVAILABLE,    IVIFGEN_ERRMSG_NO_SEQS_AVAILABLE   }, \
        { IVIFGEN_ERROR_SEQ_IN_USE,           IVIFGEN_ERRMSG_SEQ_IN_USE          }, \
        { IVIFGEN_ERROR_TRIGGER_NOT_SOFTWARE, IVIFGEN_ERRMSG_TRIGGER_NOT_SOFTWARE}

/*- IviFgenObsolete.h included for backwards compatibility -*/
#include "IviFgenObsolete.h"

/******************************************************************************
 *----------------------------- End Include File -----------------------------*
 ******************************************************************************/
#if defined(__cplusplus) || defined(c__plusplus)
}
#endif

#endif /* IVIFGEN_HEADER */
