/*****************************************************************************
 *                            N I - D M M                                   
 *----------------------------------------------------------------------------
 *    Copyright (c) National Instruments 2002.  All Rights Reserved.         
 *----------------------------------------------------------------------------
 *                                                                           
 * Title:       nidmmObsolete.h                                              
 * Purpose:     NiDmm Class value and attribute Id declarations for the     
 *              now obsolete IviDmm specification.                        
 *              These macros are defined to keep backward compatibility with 
 *              previous versions of this file.  Dmm specific drivers        
 *              should no longer use these macros. Instead, the drivers must 
 *              use definitions from the current nidmm.h header file.       
 *****************************************************************************/

#ifndef __NIDMM__HEADER_OBSOLETE
   #define __NIDMM__HEADER_OBSOLETE

   #if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
   #endif

   /*********************************************************************************
   * This section lists all attributes and values that became obsolete. Do not use  *
   * these attributes and values in your drivers and applications.                  *
   *********************************************************************************/

   #if (defined(_EXPORTING) && defined(_IVI_mswin32_))
      #define NIDMM_DECLSPEC    __declspec(dllexport)
   #else
      #define NIDMM_DECLSPEC
   #endif
   
   /*  Use NIDMM_ATTR_CHANNEL_COUNT instead */
   #define NIDMM_ATTR_NUM_CHANNELS             IVI_ATTR_NUM_CHANNELS              /* ViInt32, read only*/     
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_PREFIX instead */
   #define NIDMM_ATTR_SPECIFIC_PREFIX          IVI_ATTR_SPECIFIC_PREFIX           /* ViString, read only*/
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_REVISION instead */
   #define NIDMM_ATTR_DRIVER_REVISION          IVI_ATTR_DRIVER_REVISION           /* ViString, read only*/
   /*  Use NIDMM_ATTR_QUERY_INSTRUMENT_STATUS instead */
   #define NIDMM_ATTR_QUERY_INSTR_STATUS       IVI_ATTR_QUERY_INSTR_STATUS        /* ViBoolean */
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_MAJOR_VERSION instead */
   #define NIDMM_ATTR_DRIVER_MAJOR_VERSION     IVI_ATTR_DRIVER_MAJOR_VERSION      /* ViInt32, read only  */
   /*  Use NIDMM_ATTR_SPECIFIC_DRIVER_MINOR_VERSION instead */
   #define NIDMM_ATTR_DRIVER_MINOR_VERSION     IVI_ATTR_DRIVER_MINOR_VERSION      /* ViInt32, read only  */
   #define NIDMM_ATTR_PRIMARY_ERROR            IVI_ATTR_PRIMARY_ERROR             /* ViInt32   */
   #define NIDMM_ATTR_SECONDARY_ERROR          IVI_ATTR_SECONDARY_ERROR           /* ViInt32   */
   #define NIDMM_ATTR_ERROR_ELABORATION        IVI_ATTR_ERROR_ELABORATION         /* ViString  */
   #define NIDMM_ATTR_ENGINE_MAJOR_VERSION     IVI_ATTR_ENGINE_MAJOR_VERSION      /* ViInt32, read only  */
   #define NIDMM_ATTR_ENGINE_MINOR_VERSION     IVI_ATTR_ENGINE_MINOR_VERSION      /* ViInt32, read only  */
   #define NIDMM_ATTR_ENGINE_REVISION          IVI_ATTR_ENGINE_REVISION           /* ViString, read-only */
   #define NIDMM_ATTR_VISA_RM_SESSION          IVI_ATTR_VISA_RM_SESSION           /* ViSession, read only */
   #define NIDMM_ATTR_DEFER_UPDATE             IVI_ATTR_DEFER_UPDATE              /* ViBoolean */
   #define NIDMM_ATTR_RETURN_DEFERRED_VALUES   IVI_ATTR_RETURN_DEFERRED_VALUES    /* ViBoolean */
   /*  Use NIDMM_ATTR_IO_RESOURCE_DESCRIPTOR instead */
   #define NIDMM_ATTR_RESOURCE_DESCRIPTOR      IVI_ATTR_RESOURCE_DESCRIPTOR       /* ViString, read only */
   /*  Use NIDMM_ATTR_RESOLUTION_ABSOLUTE */
   #define NIDMM_ATTR_RESOLUTION               NIDMM_ATTR_RESOLUTION_DIGITS       /* ViReal64  */
   /*  Use NIDMM_ATTR_TRIGGER */
   #define NIDMM_ATTR_START_TRIGGER            (NIDMM_ATTR_BASE + 8L)             /* ViInt32   */
   #define NIDMM_ATTR_START_TRIG_SLOPE         (NIDMM_ATTR_BASE + 9L)             /* ViInt32   */
   #define NIDMM_ATTR_SAMPLE_TRIGGER_DELAY     (NIDMM_ATTR_BASE + 11L)            /* ViReal64  */
   #define NIDMM_ATTR_OLD_TRIGGER_MODEL        (NIDMM_ATTR_BASE + 12L)            /* ViBoolean */
   #define NIDMM_ATTR_CHAN_NAMES               (NIDMM_ATTR_BASE + 4L)             /* ViString, read only */
   #define NIDMM_ATTR_ID_QUERY_RESPONSE        (NIDMM_ATTR_BASE + 1L)             /* ViString, read only */
   #define NIDMM_ATTR_AI_NUM_CHANNELS          (NIDMM_ATTR_BASE + 5L)             /* ViInt32, read only  */
   #define NIDMM_ATTR_FILTER_NOTCH             (NIDMM_ATTR_BASE + 6L)             /* ViInt32, read only  */
   #define NIDMM_ATTR_CONVER_PER_SAMPLE        (NIDMM_ATTR_BASE + 7L)             /* ViInt32, read only  */
   #define NIDMM_ATTR_AI_BUFFER_SIZE           (NIDMM_ATTR_BASE + 13L)            /* ViInt32   */
   #define NIDMM_VAL_3_5_DIGITS                (3.5)
   #define NIDMM_VAL_4_5_DIGITS                (4.5)
   #define NIDMM_VAL_5_5_DIGITS                (5.5)
   #define NIDMM_VAL_6_5_DIGITS                (6.5)
   #define NIDMM_VAL_7_5_DIGITS                (7.5)
   /*  Use NIDMM_VAL_SOFTWARE_TRIG instead */
   #define NIDMM_VAL_SW_TRIG_FUNC              IVIDMM_VAL_SW_TRIG_FUNC
   /*  Use NIDMM_VAL_POSITIVE instead */
   #define NIDMM_VAL_POS                       IVIDMM_VAL_POSITIVE
   /*  Use NIDMM_VAL_NEGATIVE instead */
   #define NIDMM_VAL_NEG                       IVIDMM_VAL_NEGATIVE
   /*  Use NIDMM_VAL_MILLIAMP instead */
   #define NIDMM_VAL_1_MILIAMP         0.001
   #define NIDMM_WARN_FREQ_UNDERRANGE          (NIDMM_WARN_EXT_STATUS_BASE + 0x80) // 0x3FFA4F80 1073368960


   /*********************************************************************************
   * This section lists all driver functions that became obsolete. Do not use       *
   * these functions in your drivers and applications.                              *
   *********************************************************************************/
   ViStatus _VI_FUNC niDMM_error_message(
      ViSession   vi,
      ViStatus    errorCode,
      ViChar      errMessage[]);

   ViStatus _VI_FUNC niDMM_GetErrorInfo(
      ViSession   vi,
      ViStatus    *primaryError,
      ViStatus    *secondaryError,
      ViChar      errorElaboration[IVI_MAX_MESSAGE_BUF_SIZE]);

   ViStatus _VI_FUNC niDMM_ClearErrorInfo(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_error_query(
      ViSession   vi,
      ViStatus    *errorCode,
      ViChar      errMessage[]);

   ViStatus _VI_FUNC niDMM_Configure(
      ViSession   vi,
      ViInt32     measFunction,
      ViReal64    range,
      ViReal64    resolution,
      ViReal64    minFrequency,
      ViReal64    maxFrequency);

   ViStatus _VI_FUNC niDMM_ConfigureMeasurement(
      ViSession   vi,
      ViInt32     measFunction,
      ViReal64    range,
      ViReal64    resolution);

   ViStatus _VI_FUNC niDMM_ConfigureSampleDelayMode(
      ViSession   vi,
      ViInt32     sampleDelayMode);

   ViStatus _VI_FUNC niDMM_Measure(
      ViSession   vi,
      ViInt32     measFunction,
      ViInt32     maxTime,
      ViReal64    *reading);

   ViStatus _VI_FUNC niDMM_MeasureMultiPoint(
      ViSession   vi,
      ViInt32     function,
      ViInt32     maxTime,
      ViInt32     arraySize,
      ViReal64    readingArray[],
      ViInt32     *actualPts);

   ViStatus _VI_FUNC niDMM_ConfigureMeasurementComplete(
      ViSession   vi,
      ViInt32     destination,
      ViInt32     slope);

   ViStatus _VI_FUNC niDMM_SendSWTrigger(
      ViSession   vi);

   ViStatus _VI_FUNC niDMM_SetPowerlineFrequency(
      ViSession   vi,
      ViReal64    frequency);

   ViStatus _VI_FUNC niDMM_ConfigureStartTrigger(
      ViSession   vi,
      ViInt32     source,
      ViInt32     slope);

   ViStatus _VI_FUNC niDMM_SetAutoZero(
      ViSession   vi,
      ViInt32     enable);

   ViStatus _VI_FUNC niDMM_GetDigitsOfPrecision(
      ViSession   vi, 
      ViReal64    *digits);

   ViStatus _VI_FUNC niDMM_FormatMeas(
      ViInt32     function,
      ViReal64    range,
      ViReal64    resolution,
      ViReal64    reading,
      ViChar      modeString[],
      ViChar      rangeString[],
      ViChar      dataString[]);

   ViStatus _VI_FUNC niDMM_FormatMeasAbsolute(
      ViInt32     function,
      ViReal64    range,
      ViReal64    resolution,
      ViReal64    reading,
      ViChar      modeString[],
      ViChar      rangeString[],
      ViChar      dataString[]);

   ViStatus _VI_FUNC niDMM_CalculateAccuracy(
      ViSession   vi,
      ViReal64    frequency,
      ViReal64    *multiplier,
      ViReal64    *offset);

   ViStatus _VI_FUNC niDMM_GetViReal64Type(
      ViSession   vi,
      ViReal64    value,
      ViInt32*    type);

   /****************************************************************************
    *---------------------------- End Include File ----------------------------*
    ****************************************************************************/

   #if defined(__cplusplus) || defined(__cplusplus__)
}
   #endif

#endif // __NIDMM__HEADER_OBSOLETE
