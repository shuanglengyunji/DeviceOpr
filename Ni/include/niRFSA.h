/****************************************************************************
 *                National Instruments RF Signal Analyzer
 *---------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2006.  All Rights Reserved.
 *---------------------------------------------------------------------------
 *
 * Title:    niRFSA.h
 * Purpose:  National Instruments RF Signal Analyzer
 *           Instrument Driver declarations.
 *
 ****************************************************************************/
#ifndef ___niRFSA_niRFSA_h___
#define ___niRFSA_niRFSA_h___

#include <ivi.h>
#include "niRFSAErrors.h"

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/* Pragma used in CVI to indicate that functions in this file have
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

/****************************************************************************
 *---------------------------- Attribute Defines ---------------------------*
 ****************************************************************************/

/*- IVI Inherent Attributes --------------------------------------------*/

/*- User Options */
#define NIRFSA_ATTR_CACHE                                  /* ViBoolean */  IVI_ATTR_CACHE
#define NIRFSA_ATTR_RANGE_CHECK                            /* ViBoolean */  IVI_ATTR_RANGE_CHECK
#define NIRFSA_ATTR_QUERY_INSTRUMENT_STATUS                /* ViBoolean */  IVI_ATTR_QUERY_INSTRUMENT_STATUS
#define NIRFSA_ATTR_RECORD_COERCIONS                       /* ViBoolean */  IVI_ATTR_RECORD_COERCIONS
#define NIRFSA_ATTR_SIMULATE                               /* ViBoolean */  IVI_ATTR_SIMULATE
#define NIRFSA_ATTR_INTERCHANGE_CHECK                      /* ViBoolean */  IVI_ATTR_INTERCHANGE_CHECK

/*- Instrument Capabilities --------------------------------------------*/

/*- Specific Driver Information, Read-only -----------------------------*/
#define NIRFSA_ATTR_SPECIFIC_DRIVER_DESCRIPTION               /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_DESCRIPTION
#define NIRFSA_ATTR_SPECIFIC_DRIVER_PREFIX                    /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_PREFIX
#define NIRFSA_ATTR_SPECIFIC_DRIVER_VENDOR                    /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_VENDOR
#define NIRFSA_ATTR_SPECIFIC_DRIVER_REVISION                  /* ViString */  IVI_ATTR_SPECIFIC_DRIVER_REVISION
#define NIRFSA_ATTR_SUPPORTED_INSTRUMENT_MODELS               /* ViString */  IVI_ATTR_SUPPORTED_INSTRUMENT_MODELS
#define NIRFSA_ATTR_CHANNEL_COUNT                             /* ViInt32  */  IVI_ATTR_CHANNEL_COUNT
#define NIRFSA_ATTR_INSTRUMENT_MANUFACTURER                   /* ViString */  IVI_ATTR_INSTRUMENT_MANUFACTURER
#define NIRFSA_ATTR_INSTRUMENT_MODEL                          /* ViString */  IVI_ATTR_INSTRUMENT_MODEL
#define NIRFSA_ATTR_INSTRUMENT_FIRMWARE_REVISION              /* ViString */  IVI_ATTR_INSTRUMENT_FIRMWARE_REVISION

/*- Instrument Information -*/
#define NIRFSA_ATTR_MEMORY_SIZE                               /* ViInt64  */  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 85L)

/*- Advanced Session Information, read-only ----------------------------*/
#define NIRFSA_ATTR_IO_RESOURCE_DESCRIPTOR                 /* ViString */  IVI_ATTR_RESOURCE_DESCRIPTOR
#define NIRFSA_ATTR_LOGICAL_NAME                           /* ViString */  IVI_ATTR_LOGICAL_NAME
#define NIRFSA_ATTR_DRIVER_SETUP                           /* ViString */  IVI_ATTR_DRIVER_SETUP

/*- Instrument-Specific Attributes -------------------------------------*/

/*- Acquisition Type ---------------------------------------------------*/
#define NIRFSA_ATTR_ACQUISITION_TYPE                       /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)

/*- Vertical -----------------------------------------------------------*/
#define NIRFSA_ATTR_REFERENCE_LEVEL                        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)
#define NIRFSA_ATTR_ATTENUATION                            /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)
#define NIRFSA_ATTR_MIXER_LEVEL                            /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6L)
#define NIRFSA_ATTR_MIXER_LEVEL_OFFSET                     /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 127L)
#define NIRFSA_ATTR_MECHANICAL_ATTENUATION                 /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 128L)
#define NIRFSA_ATTR_RF_PREAMP_ENABLED                      /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 129L)
#define NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL                  /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 130L)
#define NIRFSA_ATTR_IF_OUTPUT_POWER_LEVEL_OFFSET           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 131L)

#define NIRFSA_ATTR_IF_ATTENUATION                         /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 74L)
#define NIRFSA_ATTR_RF_ATTENUATION_INDEX                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 76L)
#define NIRFSA_ATTR_RF_ATTENUATION_TABLE                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)
#define NIRFSA_ATTR_IF1_ATTEN_VALUE                        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 78L)
#define NIRFSA_ATTR_IF2_ATTEN_VALUE                        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 79L)
#define NIRFSA_ATTR_MINIMUM_ACPR                           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 142L)

/*- Sigal Path Control (Advanced) --------------------------------------*/
#define NIRFSA_ATTR_CHANNEL_COUPLING                       /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 149L)

/*- IQ Acquisition -----------------------------------------------------*/
#define NIRFSA_ATTR_IQ_CARRIER_FREQUENCY                   /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 59L)
#define NIRFSA_ATTR_IQ_RATE                                /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)
#define NIRFSA_ATTR_NUMBER_OF_SAMPLES_IS_FINITE            /* ViBoolean   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)
#define NIRFSA_ATTR_NUMBER_OF_SAMPLES                      /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)
#define NIRFSA_ATTR_NUMBER_OF_RECORDS_IS_FINITE            /* ViBoolean   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 10L)
#define NIRFSA_ATTR_NUMBER_OF_RECORDS                      /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 11L)

/*- Spectrum Acquisition -----------------------------------------------*/
#define NIRFSA_ATTR_SPECTRUM_CENTER_FREQUENCY              /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)
#define NIRFSA_ATTR_SPECTRUM_SPAN                          /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3L)
#define NIRFSA_ATTR_IF_OUTPUT_FREQUENCY                    /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 86L)
#define NIRFSA_ATTR_POWER_SPECTRUM_UNITS                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)
#define NIRFSA_ATTR_RESOLUTION_BANDWIDTH                   /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)
#define NIRFSA_ATTR_RESOLUTION_BANDWIDTH_TYPE              /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)
#define NIRFSA_ATTR_SPECTRUM_NUMBER_OF_AVERAGES            /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 15L)
#define NIRFSA_ATTR_SPECTRUM_AVERAGING_MODE                /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)
#define NIRFSA_ATTR_FFT_WINDOW_TYPE                        /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 17L)
#define NIRFSA_ATTR_NUMBER_OF_SPECTRAL_LINES               /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 18L)

/*- Clocking -----------------------------------------------------------*/
#define NIRFSA_ATTR_REF_CLOCK_SOURCE                       /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)
#define NIRFSA_ATTR_REF_CLOCK_RATE                         /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)
#define NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 21L)
#define NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_RATE   /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)
#define NIRFSA_ATTR_PXI_CHASSIS_CLK10_SOURCE               /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)
#define NIRFSA_ATTR_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL     /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 72L)

/*- Start Trigger ------------------------------------------------------*/
#define NIRFSA_ATTR_START_TRIGGER_TYPE                     /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 24L)
#define NIRFSA_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE      /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 25L)
#define NIRFSA_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE        /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 26L)
#define NIRFSA_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 27L)
#define NIRFSA_ATTR_START_TRIGGER_TERMINAL_NAME            /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 122L)

/*- Reference Trigger --------------------------------------------------*/
#define NIRFSA_ATTR_REF_TRIGGER_TYPE                       /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 28L)
#define NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_SOURCE        /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)
#define NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_EDGE          /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)
#define NIRFSA_ATTR_REF_TRIGGER_MINIMUM_QUIET_TIME         /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 58L)
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_SOURCE       /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 55L)
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_LEVEL        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 56L)
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_SLOPE        /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 57L)
#define NIRFSA_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL   /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)
#define NIRFSA_ATTR_REF_TRIGGER_TERMINAL_NAME              /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 123L)
#define NIRFSA_ATTR_REF_TRIGGER_DELAY                      /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 60L)
#define NIRFSA_ATTR_START_TO_REF_TRIGGER_HOLDOFF           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)
#define NIRFSA_ATTR_REF_TO_REF_TRIGGER_HOLDOFF             /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L)
#define NIRFSA_ATTR_REF_TRIGGER_PRETRIGGER_SAMPLES         /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)

/*- Advance Trigger ---------------------------------------------------*/
#define NIRFSA_ATTR_ADVANCE_TRIGGER_TYPE                     /* ViInt32   */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)
#define NIRFSA_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE      /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)
#define NIRFSA_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)
#define NIRFSA_ATTR_ADVANCE_TRIGGER_TERMINAL_NAME            /* ViString  */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 124L)

/*- Arm Reference Trigger ---------------------------------------------*/
#define NIRFSA_ATTR_ARM_REF_TRIGGER_TYPE                   /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)
#define NIRFSA_ATTR_DIGITAL_EDGE_ARM_REF_TRIGGER_SOURCE    /* ViString    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 40L)

/*- Events -------------------------------------------------------------*/
#define NIRFSA_ATTR_EXPORTED_READY_FOR_START_EVENT_OUTPUT_TERMINAL   /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)
#define NIRFSA_ATTR_EXPORTED_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)
#define NIRFSA_ATTR_EXPORTED_READY_FOR_REF_EVENT_OUTPUT_TERMINAL     /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 43L)
#define NIRFSA_ATTR_EXPORTED_END_OF_RECORD_EVENT_OUTPUT_TERMINAL     /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 44L)
#define NIRFSA_ATTR_EXPORTED_DONE_EVENT_OUTPUT_TERMINAL              /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 54L)

#define NIRFSA_ATTR_READY_FOR_START_EVENT_TERMINAL_NAME    /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 117L)
#define NIRFSA_ATTR_READY_FOR_ADVANCE_EVENT_TERMINAL_NAME  /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 118L)
#define NIRFSA_ATTR_READY_FOR_REF_EVENT_TERMINAL_NAME      /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 119L)
#define NIRFSA_ATTR_END_OF_RECORD_EVENT_TERMINAL_NAME      /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 120L)
#define NIRFSA_ATTR_DONE_EVENT_TERMINAL_NAME               /* ViString  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 121L)

/*- Fetching ------------------------------------------------------------*/
#define NIRFSA_ATTR_FETCH_RELATIVE_TO                      /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)
#define NIRFSA_ATTR_FETCH_OFFSET                           /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 46L)
#define NIRFSA_ATTR_RECORDS_DONE                           /* ViInt64     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 47L)
#define NIRFSA_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH        /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104L)
#define NIRFSA_ATTR_DATA_TRANSFER_BLOCK_SIZE               /* ViInt32     */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105L)
#define NIRFSA_ATTR_PHASE_OFFSET                           /* ViReal64    */   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106L)

/*- Advanced ------------------------------------------------------------*/
#define NIRFSA_ATTR_DIGITAL_IF_EQUALIZATION_ENABLED        /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 48L)
#define NIRFSA_ATTR_FFT_WINDOW_SIZE                        /* ViInt32, read-only  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 49L)
#define NIRFSA_ATTR_FFT_SIZE                               /* ViInt32, read-only  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 50L)
#define NIRFSA_ATTR_DEVICE_TEMPERATURE                     /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 51L)
#define NIRFSA_ATTR_TEMPERATURE_READ_INTERVAL              /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 61L)
#define NIRFSA_ATTR_DOWNCONVERTER_GAIN                     /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 65L)
#define NIRFSA_ATTR_NISCOPE_SESSION                        /* ViSession           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 52L)
#define NIRFSA_ATTR_DIGITIZER_VERTICAL_RANGE               /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 70L)
#define NIRFSA_ATTR_ENABLE_FRACTIONAL_RESAMPLING           /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 71L)
#define NIRFSA_ATTR_IF_FILTER                              /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 75L)
#define NIRFSA_ATTR_LO_TEMPERATURE                         /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 89L)
#define NIRFSA_ATTR_DIGITIZER_TEMPERATURE                  /* ViReal64, read-only */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 90L)

#define NIRFSA_ATTR_DIGITIZER_DITHER_ENABLED               /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 80L)
#define NIRFSA_ATTR_MECHANICAL_ATTENUATOR_ENABLED          /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 81L)
#define NIRFSA_ATTR_EXTERNAL_GAIN                          /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 94L)

/*- Inband Retuning -----------------------------------------------------*/
#define NIRFSA_ATTR_DOWNCONVERTER_CENTER_FREQUENCY         /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 82L)

/*- LO control attributes ----------------------------------------------*/
#define NIRFSA_ATTR_NIRFSG_SESSION                         /* ViSession           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 73L)
#define NIRFSA_ATTR_LO_FREQUENCY                           /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 68L)
#define NIRFSA_ATTR_LO_INJECTION_SIDE                      /* ViInt32,            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 69L)
#define NIRFSA_ATTR_DOWNCONVERTER_LOOP_BANDWIDTH           /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 67L)
#define NIRFSA_ATTR_FREQUENCY_SETTLING_UNITS               /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 87L)
#define NIRFSA_ATTR_FREQUENCY_SETTLING                     /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 88L)
#define NIRFSA_ATTR_LO_EXPORT_ENABLED                      /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 134L)
#define NIRFSA_ATTR_LO_YIG_MAIN_COIL_DRIVE                 /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 135L)

/*- Calibration ---------------------------------------------------------*/
#define NIRFSA_ATTR_CAL_RF_PATH_SELECTION                  /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 83L)
#define NIRFSA_ATTR_CAL_IF_FILTER_SELECTION                /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112L)
#define NIRFSA_ATTR_CAL_LO_PATH_SELECTION                  /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 113L)
#define NIRFSA_ATTR_CAL_IF_ATTENUATION_TABLE_SELECTION     /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 141L)
#define NIRFSA_ATTR_CAL_LO1_ATTENUATION                    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 114L)
#define NIRFSA_ATTR_CAL_LO2_ATTENUATION                    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 115L)
#define NIRFSA_ATTR_CAL_LO3_ATTENUATION                    /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 116L)
#define NIRFSA_ATTR_CAL_IF_ATTENUATION_INDEX               /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 109L)
#define NIRFSA_ATTR_CAL_RF_ELECTRONIC_ATTENUATION_INDEX    /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110L)
#define NIRFSA_ATTR_CAL_RF_MECHANICAL_ATTENUATION_INDEX    /* ViInt32             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_THROUGH_FILTER  /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 146L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_300_KHZ_FILTER   /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 147L)
#define NIRFSA_ATTR_CALIBRATION_CORRECTION_5_MHZ_FILTER     /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 148L)


/*- Device Attributes ---------------------------------------------------*/
#define NIRFSA_ATTR_SERIAL_NUMBER                          /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 53L)
#define NIRFSA_ATTR_MODULE_REVISION                        /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 91L)
#define NIRFSA_ATTR_DEVICE_INSTANTANEOUS_BANDWIDTH         /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 125L)
#define NIRFSA_ATTR_RF_PREAMP_PRESENT                      /* ViBoolean           */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 137L)

/*- List mode attributes ------------------------------------------------*/
#define NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST              /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 92L)
#define NIRFSA_ATTR_ACTIVE_CONFIGURATION_LIST_STEP         /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 93L)
#define NIRFSA_ATTR_RECONFIGURATION_TRIGGER_SOURCE         /* ViString            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 95L)
#define NIRFSA_ATTR_CONFIGURATION_LIST_STEP_IN_PROGRESS    /* ViInt64             */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 126L)

/* Timer Event configuration attributes */
#define NIRFSA_ATTR_TIMER_EVENT_INTERVAL                   /* ViReal64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 96L)

/*- P2P Attributes ---------------------------------------------------*/
#define NIRFSA_ATTR_P2P_ENABLED                            /* ViBoolean          */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 97L)
#define NIRFSA_ATTR_P2P_FIFO_ENDPOINT_COUNT                /* ViInt64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 98L)
#define NIRFSA_ATTR_P2P_SAMPLES_TRANSFERRED                /* ViInt64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 99L)
#define NIRFSA_ATTR_P2P_SAMPLES_AVAILABLE_IN_ENDPOINT      /* ViInt64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 100L)
#define NIRFSA_ATTR_P2P_MOST_SAMPLES_AVAILABLE_IN_ENDPOINT /* ViInt64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L)
#define NIRFSA_ATTR_P2P_ENDPOINT_SIZE                      /* ViInt64            */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102L)
#define NIRFSA_ATTR_P2P_ENDPOINT_OVERFLOW                  /* ViBoolean          */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103L)
#define NIRFSA_ATTR_P2P_ONBOARD_MEMORY_ENABLED             /* ViBoolean          */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107L)

/*- Cal Tone Controls ---------------------------------------*/
#define NIRFSA_ATTR_CAL_TONE_MODE               /* ViInt32   */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 139L)
#define NIRFSA_CAL_TONE_FREQUENCY               /* ViReal64  */ (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 140L)

/****************************************************************************
 *------------------------ Attribute Value Defines -------------------------*
 ****************************************************************************/

/*- NIRFSA_ATTR_ACQUISITION_TYPE Values -*/
#define NIRFSA_VAL_IQ                                   100
#define NIRFSA_VAL_SPECTRUM                             101

/*- NIRFSA_ATTR_POWER_SPECTRUM_UNITS Values -*/
#define NIRFSA_VAL_DBM                                  200
#define NIRFSA_VAL_VOLTS_SQUARED                        201
#define NIRFSA_VAL_DBMV                                 202
#define NIRFSA_VAL_DBUV                                 203
#define NIRFSA_VAL_VOLTS                                204
#define NIRFSA_VAL_WATTS                                205

/*- NIRFSA_ATTR_RESOLUTION_BANDWIDTH_TYPE Values -*/
#define NIRFSA_VAL_RBW_3DB                              300
#define NIRFSA_VAL_RBW_6DB                              301
#define NIRFSA_VAL_RBW_BIN_WIDTH                        302
#define NIRFSA_VAL_RBW_ENBW                             303

/*- NIRFSA_ATTR_AVERAGING_MODE Values -*/
#define NIRFSA_VAL_NO_AVERAGING                         400
#define NIRFSA_VAL_RMS_AVERAGING                        401
#define NIRFSA_VAL_VECTOR_AVERAGING                     402
#define NIRFSA_VAL_PEAK_HOLD_AVERAGING                  403

/*- NIRFSA_ATTR_FFT_WINDOW_TYPE Values -*/
#define NIRFSA_VAL_UNIFORM                              500
#define NIRFSA_VAL_HANNING                              501
#define NIRFSA_VAL_HAMMING                              502
#define NIRFSA_VAL_BLACKMAN_HARRIS                      503
#define NIRFSA_VAL_EXACT_BLACKMAN                       504
#define NIRFSA_VAL_BLACKMAN                             505
#define NIRFSA_VAL_FLAT_TOP                             506
#define NIRFSA_VAL_4_TERM_BLACKMAN_HARRIS               507
#define NIRFSA_VAL_7_TERM_BLACKMAN_HARRIS               508
#define NIRFSA_VAL_LOW_SIDE_LOBE                        509

/*- Values For Trigger Type Attributes -*/
#define NIRFSA_VAL_NONE                                 600
#define NIRFSA_VAL_DIGITAL_EDGE                         601
#define NIRFSA_VAL_DIGITAL_LEVEL                        602
#define NIRFSA_VAL_IQ_POWER_EDGE                        603
#define NIRFSA_VAL_SOFTWARE_EDGE                        604

/*- NIRFSA_ATTR_FETCH_RELATIVE_TO Values -*/
#define NIRFSA_VAL_MOST_RECENT_SAMPLE                   700
#define NIRFSA_VAL_FIRST_SAMPLE                         701
#define NIRFSA_VAL_REF_TRIGGER                          702
#define NIRFSA_VAL_FIRST_PRETRIGGER_SAMPLE              703
#define NIRFSA_VAL_CURRENT_READ_POSITION                704

/*- NIRFSA_ATTR_DOWNCONVERTER_LOOP_BANDWIDTH Values -*/
#define NIRFSA_VAL_NARROW                               800
#define NIRFSA_VAL_MEDIUM                               801
#define NIRFSA_VAL_WIDE                                 802

/*- Values For Digital Edge Attributes -*/
#define NIRFSA_VAL_RISING_EDGE                          900
#define NIRFSA_VAL_FALLING_EDGE                         901

/*- Values For Slope Attributes -*/
#define NIRFSA_VAL_RISING_SLOPE                        1000
#define NIRFSA_VAL_FALLING_SLOPE                       1001

/*- Values For Send Software Edge Trigger -*/
#define NIRFSA_VAL_START_TRIGGER                       1100
/* #define NIRFSA_VAL_REF_TRIGGER                       702  (Defined Above) */
#define NIRFSA_VAL_ADVANCE_TRIGGER                     1102
#define NIRFSA_VAL_ARM_REF_TRIGGER                     1103

/*- Values for Export Signals -*/
#define NIRFSA_VAL_READY_FOR_START_EVENT               1200
#define NIRFSA_VAL_READY_FOR_REF_EVENT                 1201
#define NIRFSA_VAL_READY_FOR_ADVANCE_EVENT             1202
#define NIRFSA_VAL_END_OF_RECORD_EVENT                 1203
#define NIRFSA_VAL_DONE_EVENT                          1204
#define NIRFSA_VAL_REF_CLOCK                           1205

/*- Values for LO Injection attribute-*/
#define NIRFSA_VAL_LO_INJECTION_HIGH_SIDE              1300
#define NIRFSA_VAL_LO_INJECTION_LOW_SIDE               1301

/*- Values for NIRFSA_ATTR_REF_CLOCK_SOURCE and NIRFSA_ATTR_PXI_CHASSIS_CLK10_SOURCE -*/
#define NIRFSA_VAL_NONE_STR                            "None"
#define NIRFSA_VAL_ONBOARD_CLOCK_STR                   "OnboardClock"
#define NIRFSA_VAL_REF_IN_STR                          "RefIn"
#define NIRFSA_VAL_PXI_CLK_STR                         "PXI_Clk"

/*- Values for NIRFSA_ATTR_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL -*/
#define NIRFSA_VAL_CLK_OUT_STR                         "ClkOut"
#define NIRFSA_VAL_REF_OUT_STR                         "RefOut"
#define NIRFSA_VAL_REF_OUT2_STR                        "RefOut2"

/*- Values for NIRFSA_ATTR_DIGITIZER_SAMPLE_CLOCK_TIMEBASE_SOURCE -*/
#define NIRFSA_VAL_CLK_IN_STR                          "ClkIn"
/* #define NIRFSA_VAL_ONBOARD_CLOCK_STR                "OnboardClock" (Defined Above) */
/* #define NIRFSA_VAL_PXI_STAR_STR                     "PXI_STAR"     (Defined Below) */
#define NIRFSA_VAL_LO_REF_CLK_STR                      "LORefClk"

/*- Values for digital source and export terminal attributes:
    NIRFSA_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE
    NIRFSA_ATTR_DIGITAL_EDGE_REF_TRIGGER_SOURCE
    NIRFSA_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE
    NIRFSA_ATTR_DIGITAL_EDGE_ARM_REF_TRIGGER_SOURCE
    NIRFSA_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_READY_FOR_START_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_READY_FOR_REF_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_END_OF_RECORD_EVENT_OUTPUT_TERMINAL
    NIRFSA_ATTR_EXPORTED_DONE_EVENT_OUTPUT_TERMINAL
-*/

#define NIRFSA_VAL_DO_NOT_EXPORT_STR                   ""
#define NIRFSA_VAL_PFI0_STR                            "PFI0"
#define NIRFSA_VAL_PFI1_STR                            "PFI1"
#define NIRFSA_VAL_PXI_TRIG0_STR                       "PXI_Trig0"
#define NIRFSA_VAL_PXI_TRIG1_STR                       "PXI_Trig1"
#define NIRFSA_VAL_PXI_TRIG2_STR                       "PXI_Trig2"
#define NIRFSA_VAL_PXI_TRIG3_STR                       "PXI_Trig3"
#define NIRFSA_VAL_PXI_TRIG4_STR                       "PXI_Trig4"
#define NIRFSA_VAL_PXI_TRIG5_STR                       "PXI_Trig5"
#define NIRFSA_VAL_PXI_TRIG6_STR                       "PXI_Trig6"
#define NIRFSA_VAL_PXI_TRIG7_STR                       "PXI_Trig7"
#define NIRFSA_VAL_PXI_STAR_STR                        "PXI_STAR"
#define NIRFSA_VAL_RTSI0_STR                           NIRFSA_VAL_PXI_TRIG0_STR
#define NIRFSA_VAL_RTSI1_STR                           NIRFSA_VAL_PXI_TRIG1_STR
#define NIRFSA_VAL_RTSI2_STR                           NIRFSA_VAL_PXI_TRIG2_STR
#define NIRFSA_VAL_RTSI3_STR                           NIRFSA_VAL_PXI_TRIG3_STR
#define NIRFSA_VAL_RTSI4_STR                           NIRFSA_VAL_PXI_TRIG4_STR
#define NIRFSA_VAL_RTSI5_STR                           NIRFSA_VAL_PXI_TRIG5_STR
#define NIRFSA_VAL_RTSI6_STR                           NIRFSA_VAL_PXI_TRIG6_STR
#define NIRFSA_VAL_RTSI7_STR                           NIRFSA_VAL_PXI_TRIG7_STR
#define NIRFSA_VAL_TIMER_EVENT_STR                     "TimerEvent"

/*- Values for IF Filter attribute-*/
#define NIRFSA_VAL_187_5_MHZ_WIDE                                 1400
#define NIRFSA_VAL_187_5_MHZ_NARROW                               1401
#define NIRFSA_VAL_53_MHZ                                         1402
#define NIRFSA_VAL_BYPASS                                         1403

/////////////////////////////////////////////////////////////////////////
// Values for External Calibration
/*- Defined values for action in niRFSA_CloseExtCal()  ---------------*/
#define NIRFSA_VAL_EXT_CAL_ABORT                                  1500
#define NIRFSA_VAL_EXT_CAL_COMMIT                                 1501

/*- Defined values for calibration step in niRFSA_InitializeCalibrationStep()  ---------------*/
#define NIRFSA_VAL_EXT_CAL_IF_ATTENUATION_CALIBRATION             1600
#define NIRFSA_VAL_EXT_CAL_IF_RESPONSE_CALIBRATION                1601
#define NIRFSA_VAL_EXT_CAL_REF_LEVEL_CALIBRATION                  1602
#define NIRFSA_VAL_EXT_CAL_LO_EXPORT_CALIBRATION                  1603

/*- Defined values for NIRFSA_ATTR_CAL_RF_PATH_SELECTION  ---------------*/
#define NIRFSA_VAL_EXT_CAL_RF_BAND_1                              1700
#define NIRFSA_VAL_EXT_CAL_RF_BAND_2                              1701
#define NIRFSA_VAL_EXT_CAL_RF_BAND_3                              1702
#define NIRFSA_VAL_EXT_CAL_RF_BAND_4                              1703

/*- Defined values for refLevelCalDataType in niRFSA_CalAdjustRefLevelCalibration()  ---------------*/
#define NIRFSA_VAL_EXT_CAL_DEFAULT                                1800
#define NIRFSA_VAL_EXT_CAL_MECHANICAL_ATTENUATOR_DISABLED         1801

/*- Values for NIRFSA_ATTR_MECHANICAL_ATTENUATOR_ENABLED and NIRFSA_ATTR_DIGITIZER_DITHER_ENABLED  -*/
#define NIRFSA_VAL_DISABLED                                       1900
#define NIRFSA_VAL_ENABLED                                        1901

/*- Values for Frequency Settling units attribute */
#define NIRFSA_VAL_FSU_PPM                                        2000
#define NIRFSA_VAL_FSU_SECONDS_AFTER_LOCK                         2001
#define NIRFSA_VAL_FSU_SECONDS_AFTER_IO                           2002

/*- Values for NIRFSA_ATTR_CAL_IF_FILTER_SELECTION attribute-*/
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_1                       2100 // 5Mhz Bandpass IF Filter
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_2                       2101 // 300Khz BandPass IF Filter
#define NIRFSA_VAL_EXT_CAL_IF_FILTER_PATH_3                       2102 // Bypass Path (no IF Filter)

/*-Values For niRFSA_CalAdjustLOExportCalibration:LONumber-*/
#define NIRFSA_VAL_EXT_CAL_LO1                                    2200 // Variable LO
#define NIRFSA_VAL_EXT_CAL_LO2                                    2201 // 4Ghz LO
#define NIRFSA_VAL_EXT_CAL_LO3                                    2202 // 800Mhz LO

/*- Values for NIRFSA_ATTR_CAL_LO_PATH_SELECTION attribute-*/
#define NIRFSA_VAL_EXT_CAL_LO_PATH_1                              2300 // LO Doubler Disabled
#define NIRFSA_VAL_EXT_CAL_LO_PATH_2                              2301 // LO Doubler Enabled

/*- Values for NIRFSA_ATTR_LO_YIG_MAIN_COIL_DRIVE attribute-*/
#define NIRFSA_VAL_LO_YIG_MAIN_COIL_DRIVE_NORMAL                  2400
#define NIRFSA_VAL_LO_YIG_MAIN_COIL_DRIVE_FAST                    2401

/*- Values for NIRFSA_ATTR_RF_PREAMP_ENABLED attribute-*/
#define NIRFSA_VAL_RF_PREAMP_DISABLED                             2500 // Preamp Disabled
#define NIRFSA_VAL_RF_PREAMP_ENABLED_WHEN_IN_SIGNAL_PATH          2501 // The RF preamp will be automatically enabled when it is in the signal path and will be automatically disabled when it is out of the signal path
#define NIRFSA_VAL_RF_PREAMP_ENABLED                              2502 // Preamp Enabled

/*- Values for SELF CAL steps -*/
#define NIRFSA_VAL_SELF_CAL_YTF_ALIGNMENT                         0x0000000000000001
#define NIRFSA_VAL_SELF_CAL_GAIN_REFERENCE                        0x0000000000000002
#define NIRFSA_VAL_SELF_CAL_IF_FLATNESS                           0x0000000000000004
#define NIRFSA_VAL_SELF_CAL_DIGITIZER_SELF_CAL                    0x0000000000000008
#define NIRFSA_VAL_SELF_CAL_LO_SELF_CAL                           0x0000000000000010

/*- Values for Cal Tone Mode -*/
#define NIRFSA_VAL_CAL_TONE_DISABLED                              2700
#define NIRFSA_VAL_CAL_TONE_LOWBAND_RF                            2701
#define NIRFSA_VAL_CAL_TONE_HIGHBAND_RF                           2702
#define NIRFSA_VAL_CAL_TONE_HIGHBAND_IF                           2703

/* Values for niRFSA_GetDeviceResponse response type */
#define NIRFSA_VAL_DOWNCONVERTER_IF_RESPONSE                      2800
#define NIRFSA_VAL_DOWNCONVERTER_RF_RESPONSE                      2801
#define NIRFSA_VAL_DOWNCONVERTER_COMBINED_RESPONSE                2802
#define NIRFSA_VAL_VSA_IF_RESPONSE                                2803
#define NIRFSA_VAL_VSA_COMBINED_RESPONSE                          2804

/*- Values for NIRFSA_ATTR_CAL_IF_ATTENUATION_TABLE_SELECTION attribute-*/
#define NIRFSA_VAL_EXT_CAL_IF_ATTENUATION_TABLE_STANDARD          2900
#define NIRFSA_VAL_EXT_CAL_IF_ATTENUATION_TABLE_ACPR              2901

/*- Values for NIRFSA_ATTR_CHANNEL_COUPLING attribute -*/
#define NIRFSA_VAL_AC                                             3001
#define NIRFSA_VAL_DC                                             3002

/*- SMT Structures -----------------------------------------------*/
#ifndef _WIN64
   #pragma pack(push, 1)
#endif

#ifndef __SmtSpectrumInfo__
#define __SmtSpectrumInfo__
typedef struct {
   unsigned short spectrumType;
   unsigned short linearDB;
   unsigned short window;
   int windowSize;
   int FFTSize;
} SmtSpectrumInfo;
#endif

#ifndef __SmtZoomSettings__
#define __SmtZoomSettings__
typedef struct {
   double centerFrequency;
   double zoom;
   unsigned short window;
   int windowSize;
   int FFTSize;
   double overlap;
   double frequencyShift;
   unsigned short dataFormat;
   double trim;
} SmtZoomSettings;
#endif

#ifndef __SmtSpectrumSettings__
#define __SmtSpectrumSettings__
typedef struct {
   double centerFrequency;
   double span;
   double resolutionBandwidth;
   unsigned short window;
   int spectralLines;
} SmtSpectrumSettings;
#endif

#ifndef _WIN64
   #pragma pack(pop)
#endif

/*--------------------------------------------------------------------------*/


/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*- Init and Close Functions -----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_init (
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean reset,
   ViSession* vi);

ViStatus _VI_FUNC niRFSA_InitWithOptions(
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean reset,
   ViConstString optionString,
   ViSession* newVi);

ViStatus _VI_FUNC niRFSA_close(
   ViSession vi);

/*- Peer-to-Peer utility -----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_GetStreamEndpointHandle(
   ViSession vi,
   ViConstString streamEndpoint,
   ViUInt32* writerHandle);

/*- Calibration -----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_InitExtCal(
   ViRsrc resourceName,
   ViConstString password,
   ViConstString optionString,
   ViSession* vi);

ViStatus _VI_FUNC niRFSA_InitializeCalibrationStep(
   ViSession vi,
   ViInt32 calibrationStep);

ViStatus _VI_FUNC niRFSA_CloseCalibrationStep(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_CloseExtCal(
   ViSession vi,
   ViInt32 action);

ViStatus _VI_FUNC niRFSA_SelfCal(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_SelfCalibrate(
   ViSession vi,
   ViInt64 stepsToOmit);

ViStatus _VI_FUNC niRFSA_IsSelfCalValid(
   ViSession vi,
   ViBoolean* selfCalValid,
   ViInt64* validSteps);

/* Calibration Utility Functions */
ViStatus _VI_FUNC niRFSA_GetExtCalLastDateAndTime(
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niRFSA_GetExtCalLastTemp(
   ViSession vi,
   ViReal64* temperature);

ViStatus _VI_FUNC niRFSA_GetExtCalRecommendedInterval(
   ViSession vi,
   ViInt32* months);

ViStatus _VI_FUNC niRFSA_ChangeExtCalPassword(
   ViSession vi,
   ViConstString oldPassword,
   ViConstString newPassword);

ViStatus _VI_FUNC niRFSA_SetCalUserDefinedInfo(
   ViSession vi,
   ViConstString info);

ViStatus _VI_FUNC niRFSA_GetCalUserDefinedInfo(
   ViSession vi,
   ViChar info[]);

ViStatus _VI_FUNC niRFSA_GetCalUserDefinedInfoMaxSize(
   ViSession vi,
   ViInt32* infoSize);

ViStatus _VI_FUNC niRFSA_ExtCalStoreBaselineForSelfCalibration(
   ViSession vi,
   ViString password,
   ViInt64 selfCalibrationStep);

ViStatus _VI_FUNC niRFSA_GetSelfCalLastDateAndTime(
   ViSession vi,
   ViInt64 selfCalibrationStep,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);

ViStatus _VI_FUNC niRFSA_GetSelfCalLastTemp(
   ViSession vi,
   ViInt64 selfCalibrationStep,
   ViReal64* temp);

ViStatus _VI_FUNC niRFSA_GetGainReferenceCalBaseline(
   ViSession vi,
   ViInt32  bufferSize,
   ViReal64 gainReferenceCalConstants[],
   ViInt32* numberOfGainReferenceCalConstants);

/*- Calibration Adjust Functions-------------------------------------*/
ViStatus _VI_FUNC niRFSA_CalAdjustIFAttenuationCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32 IFFilter,
   ViInt32 numberOfAttenuators,
   ViReal64* attenuatorSettings,
   ViReal64 measurement);

ViStatus _VI_FUNC niRFSA_CalAdjustIFResponseCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32  IFFilter,
   ViReal64 RFFrequency,
   ViReal64 bandWidth,
   ViInt32  numberOfMeasurements,
   ViReal64* measurements);

ViStatus _VI_FUNC niRFSA_CalAdjustRefLevelCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32 referenceLevelDataType,
   ViInt32 rfBand,
   ViInt32 attenuatorTableNumber,
   ViReal64 frequency,
   ViReal64 measurement);

ViStatus _VI_FUNC niRFSA_CalAdjustLOExportCalibration(
   ViSession vi,
   ViConstString channelList,
   ViInt32   loNumber,
   ViInt32   numberOfFrequencyPoints,
   ViReal64* frequencyPoints,
   ViReal64* loAttenuation);

ViStatus _VI_FUNC niRFSA_CalAdjustDownconverterGain(
   ViSession vi,
   ViConstString channelList,
   ViReal64 frequency,
   ViReal64 gain);

ViStatus _VI_FUNC niRFSA_CalSetTemperature(
   ViSession vi,
   ViConstString channelList,
   ViReal64 temperature);

/*- Required VXIplug&play Functions ----------------------------------------*/
ViStatus _VI_FUNC niRFSA_reset(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ResetDevice(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_self_test(
   ViSession vi,
   ViInt16 *testResult,/*Output*/
   ViChar testMessage[]);

ViStatus _VI_FUNC niRFSA_error_query(
   ViSession vi,
   ViInt32 *errorCode,
   ViChar errorMessage[]);

ViStatus _VI_FUNC niRFSA_error_message(
   ViSession vi,
   ViStatus statusCode,
   ViChar message[]);

ViStatus _VI_FUNC niRFSA_revision_query(
   ViSession vi,
   ViChar driverRev[],
   ViChar instrRev[]);

/*- Error Functions --------------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_GetError(
   ViSession vi,
   ViStatus *errorCode,
   ViInt32 errorDescriptionBufferSize,
   ViChar errorDescription[]);

ViStatus _VI_FUNC niRFSA_ClearError(
   ViSession vi);

/*- Required IVI Functions ---------------------------------------------*/
ViStatus _VI_FUNC niRFSA_LockSession(
   ViSession vi,
   ViBoolean *callerHasLock);

ViStatus _VI_FUNC niRFSA_UnlockSession(
   ViSession vi,
   ViBoolean *callerHasLock);

/*- Acquisition Type Configuration -------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureAcquisitionType(
   ViSession vi,
   ViInt32 acquisitionType);

/*- Reference Level Configuration --------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureReferenceLevel(
   ViSession vi,
   ViConstString channelList,
   ViReal64 referenceLevel);

/*- IQ Acquisition Configuration ---------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureIQCarrierFrequency(
   ViSession vi,
   ViConstString channelList,
   ViReal64 carrierFrequency);

ViStatus _VI_FUNC niRFSA_ConfigureIQRate(
   ViSession vi,
   ViConstString channelList,
   ViReal64 iqRate);

ViStatus _VI_FUNC niRFSA_ConfigureNumberOfSamples(
   ViSession vi,
   ViConstString channelList,
   ViBoolean numberOfSamplesIsFinite,
   ViInt64 samplesPerRecord);

ViStatus _VI_FUNC niRFSA_ConfigureNumberOfRecords(
   ViSession vi,
   ViConstString channelList,
   ViBoolean numberOfRecordsIsFinite,
   ViInt64 numberOfRecords);

/*- Spectrum Acquisition Configuration ---------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureSpectrumFrequencyCenterSpan(
   ViSession vi,
   ViConstString channelList,
   ViReal64 centerFrequency,
   ViReal64 span);

ViStatus _VI_FUNC niRFSA_ConfigureSpectrumFrequencyStartStop(
   ViSession vi,
   ViConstString channelList,
   ViReal64 startFrequency,
   ViReal64 stopFrequency);

ViStatus _VI_FUNC niRFSA_ConfigureResolutionBandwidth(
   ViSession vi,
   ViConstString channelList,
   ViReal64 resolutionBandwidth);

/*- Clock Configuration ------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureRefClock(
   ViSession vi,
   ViConstString clockSource,
   ViReal64 refClockRate);

ViStatus _VI_FUNC niRFSA_ConfigurePXIChassisClk10(
   ViSession vi,
   ViConstString pxiClk10Source);

/*- Trigger Configuration ----------------------------------------------*/
ViStatus _VI_FUNC niRFSA_ConfigureDigitalEdgeStartTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niRFSA_ConfigureSoftwareEdgeStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_DisableStartTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ConfigureDigitalEdgeRefTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge,
   ViInt64 pretriggerSamples);

ViStatus _VI_FUNC niRFSA_ConfigureIQPowerEdgeRefTrigger(
   ViSession vi,
   ViConstString source,
   ViReal64 level,
   ViInt32 slope,
   ViInt64 pretriggerSamples);

ViStatus _VI_FUNC niRFSA_ConfigureSoftwareEdgeRefTrigger(
   ViSession vi,
   ViInt64 pretriggerSamples);

ViStatus _VI_FUNC niRFSA_DisableRefTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ConfigureDigitalEdgeAdvanceTrigger(
   ViSession vi,
   ViConstString source,
   ViInt32 edge);

ViStatus _VI_FUNC niRFSA_ConfigureSoftwareEdgeAdvanceTrigger(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_DisableAdvanceTrigger(
   ViSession vi);

/*- Reading / Fetching IQ Data ------------------------------------------*/
#if !defined(_NIComplexNumber)
#define _NIComplexNumber

#pragma pack(push, 8)
typedef struct NIComplexNumber_struct {
   ViReal64 real;
   ViReal64 imaginary;
} NIComplexNumber;
#pragma pack(pop)

#endif


#if !defined(_niRFSA_wfmInfo)
#define _niRFSA_wfmInfo

#pragma pack(push,8)
typedef struct niRFSA_wfmInfo_struct
{
   ViReal64 absoluteInitialX;
   ViReal64 relativeInitialX;
   ViReal64 xIncrement;
   ViInt64 actualSamples;
   ViReal64 offset;
   ViReal64 gain;
   ViReal64 reserved1;
   ViReal64 reserved2;
} niRFSA_wfmInfo;
#pragma pack(pop)

#endif

#pragma pack(push,8)
typedef struct niRFSA_coefficientInfo_struct
{
   ViReal64 offset;
   ViReal64 gain;
   ViReal64 reserved1;
   ViReal64 reserved2;
} niRFSA_coefficientInfo;
#pragma pack(pop)

#ifndef _WIN64
   #pragma pack(push, 2)
#endif

#if !defined(_NIComplexI16)
#define _NIComplexI16
typedef struct NIComplexI16_struct {
   ViInt16 real;
   ViInt16 imaginary;
} NIComplexI16;
#endif

#ifndef _WIN64
   #pragma pack(pop)
#endif



ViStatus _VI_FUNC niRFSA_ReadIQSingleRecordComplexF64(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   NIComplexNumber* data,
   ViInt64 dataArraySize,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQSingleRecordComplexF64(
   ViSession vi,
   ViConstString channelList,
   ViInt64 recordNumber,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexNumber* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQMultiRecordComplexF64(
   ViSession vi,
   ViConstString channelList,
   ViInt64 startingRecord,
   ViInt64 numberOfRecords,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexNumber* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQSingleRecordComplexI16(
   ViSession vi,
   ViConstString channelList,
   ViInt64 recordNumber,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexI16* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_FetchIQMultiRecordComplexI16
(
   ViSession vi,
   ViConstString channelList,
   ViInt64 startingRecord,
   ViInt64 numberOfRecords,
   ViInt64 numberOfSamples,
   ViReal64 timeout,
   NIComplexI16* data,
   niRFSA_wfmInfo* wfmInfo);

ViStatus _VI_FUNC niRFSA_GetFetchBacklog(
   ViSession vi,
   ViConstString channelList,
   ViInt64 recordNumber,
   ViInt64* backlog);

ViStatus _VI_FUNC niRFSA_GetScalingCoefficients(
   ViSession vi,
   ViConstString channelList,
   ViInt32 arraySize,
   niRFSA_coefficientInfo coefficientInfo[],
   ViInt32* numberOfCoefficientSets);

ViStatus _VI_FUNC niRFSA_GetNormalizationCoefficients(
   ViSession vi,
   ViConstString channelList,
   ViInt32 arraySize,
   niRFSA_coefficientInfo coefficientInfo[],
   ViInt32* numberOfCoefficientSets);

/*- Reading Spectrum Data ----------------------------------------------*/
#if !defined(_niRFSA_spectrumInfo)
#define _niRFSA_spectrumInfo

#pragma pack(push,8)
typedef struct niRFSA_spectrumInfo_struct
{
   ViReal64 initialFrequency;
   ViReal64 frequencyIncrement;
   ViInt32 numberOfSpectralLines;
   ViReal64 reserved1;
   ViReal64 reserved2;
   ViReal64 reserved3;
   ViReal64 reserved4;
   ViReal64 reserved5;
} niRFSA_spectrumInfo;
#pragma pack(pop)

#endif

ViStatus _VI_FUNC niRFSA_ReadPowerSpectrumF64(
   ViSession vi,
   ViConstString channelList,
   ViReal64 timeout,
   ViReal64 powerSpectrumData[],
   ViInt32 dataArraySize,
   niRFSA_spectrumInfo* spectrumInfo);

ViStatus _VI_FUNC niRFSA_GetNumberOfSpectralLines(
   ViSession vi,
   ViConstString channelList,
   ViInt32* numberOfSpectralLines);

/*- Control Functions --------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_Initiate(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_Abort(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_Commit(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_CheckAcquisitionStatus(
   ViSession vi,
   ViBoolean* isDone);

/*- Utility Functions --------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_PerformThermalCorrection(
   ViSession vi);

ViStatus _VI_FUNC niRFSA_ExportSignal(
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViConstString outputTerminal);

ViStatus _VI_FUNC niRFSA_GetTerminalName
(
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViInt32 bufferSize,
   ViChar terminalName[]);

ViStatus _VI_FUNC niRFSA_SendSoftwareEdgeTrigger(
   ViSession vi,
   ViInt32 trigger,
   ViConstString triggerIdentifier);

ViStatus _VI_FUNC niRFSA_GetSpectralInfoForSMT(
   ViSession vi,
   SmtSpectrumInfo* spectrumInfo);

ViStatus _VI_FUNC niRFSA_GetFrequencyResponse(
   ViSession vi,
   ViConstString channelList,
   ViInt32 bufferSize,
   ViReal64 frequencies[],
   ViReal64 magnitudeResponse[],
   ViReal64 phaseResponse[],
   ViInt32* numberOfFrequencies);

ViStatus _VI_FUNC niRFSA_GetDeviceResponse(
   ViSession vi,
   ViConstString channelList,
   ViInt32 responseType,
   ViInt32 bufferSize,
   ViReal64 frequencies[],
   ViReal64 magnitudeResponse[],
   ViReal64 phaseResponse[],
   ViInt32* numberOfFrequencies);

ViStatus _VI_FUNC niRFSA_GetRelayOperationsCount(
   ViSession vi,
   ViConstString channelList,
   ViInt32 operationsCount[],
   ViInt32* bufferSize);

ViStatus _VI_FUNC niRFSA_GetRelayName(
   ViSession vi,
   ViConstString channelList,
   ViInt32 index,
   ViChar name[],
   ViInt32* bufferSize);

/*-------------------------------- List Mode API ----------------------------------------*/
ViStatus _VI_FUNC niRFSA_CreateConfigurationList(
   ViSession vi,
   ViConstString listName,
   ViInt32 numberOfListAttributes,
   const ViAttr* listAttributeIDs,
   ViBoolean setAsActiveList);

ViStatus _VI_FUNC niRFSA_CreateConfigurationListStep(
   ViSession vi,
   ViBoolean setAsActiveStep);

ViStatus _VI_FUNC niRFSA_DeleteConfigurationList(
   ViSession vi,
   ViConstString listName);

/*- Attributes ---------------------------------------------------------*/
ViStatus _VI_FUNC niRFSA_SetAttributeViInt32    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 value);
ViStatus _VI_FUNC niRFSA_SetAttributeViInt64    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 value);
ViStatus _VI_FUNC niRFSA_SetAttributeViReal64   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 value);
ViStatus _VI_FUNC niRFSA_SetAttributeViString   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViConstString value);
ViStatus _VI_FUNC niRFSA_SetAttributeViBoolean  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean value);
ViStatus _VI_FUNC niRFSA_SetAttributeViSession  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession value);

ViStatus _VI_FUNC niRFSA_GetAttributeViInt32    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 *value);
ViStatus _VI_FUNC niRFSA_GetAttributeViInt64    (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt64 *value);
ViStatus _VI_FUNC niRFSA_GetAttributeViReal64   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViReal64 *value) ;
ViStatus _VI_FUNC niRFSA_GetAttributeViString   (ViSession vi, ViConstString channelName, ViAttr attributeId, ViInt32 bufSize, ViChar value[]);
ViStatus _VI_FUNC niRFSA_GetAttributeViBoolean  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViBoolean *value);
ViStatus _VI_FUNC niRFSA_GetAttributeViSession  (ViSession vi, ViConstString channelName, ViAttr attributeId, ViSession *value);

ViStatus _VI_FUNC niRFSA_ResetAttribute         (ViSession vi, ViConstString channelName, ViAttr attributeId);


/****************************************************************************
 *--------------------------------- obsolete -------------------------------*
 ****************************************************************************/
#define NIRFSA_ATTR_IQ_POWER_EDGE_REF_TRIGGER_MINIMUM_QUIET_TIME  /* ViReal64 */    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 58L)
#define NIRFSA_VAL_PXI_CLK10_STR                       "PXI_Clk10"
#define NIRFSA_VAL_LOW                                  NIRFSA_VAL_NARROW
#define NIRFSA_VAL_HIGH                                 NIRFSA_VAL_WIDE

/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* ___niRFSA_niRFSA_h___ */

