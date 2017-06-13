/****************************************************************************************************
 *                                             niHSDIO
 *--------------------------------------------------------------------------------------------------
 *   Copyright (c) National Instruments 2002 - 2008.  All Rights Reserved.
 *--------------------------------------------------------------------------------------------------
 *
 * Title:    niHSDIO.h
 * Purpose:  National Instruments High-Speed Digital I/O
 *           instrument driver declarations.
 *
 *****************************************************************************************************/

#ifndef __NIHSDIO_HEADER
#define __NIHSDIO_HEADER

#include <ivi.h>

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************************************
 *------------------------------- Instrument Driver Revision Information ---------------------------*
 ****************************************************************************************************/
#define NIHSDIO_MAJOR_VERSION                1     /* Instrument driver major version  */
#define NIHSDIO_MINOR_VERSION                700   /* Instrument driver minor version  */

#define NIHSDIO_SUPPORTED_INSTRUMENT_MODELS  "NI-PXI-6541, NI-PXI-6542, NI-PCI-6541, NI-PCI-6542, NI-PXIe-6544, NI-PXIe-6545, NI-PXIe-6547, NI-PXIe-6548, NI-PXI-6551, NI-PXI-6552, NI-PCI-6551, NI-PCI-6552, NI-PXI-6561, NI-PXI-6562, NI-PCI-6561, NI-PCI-6562"
#define NIHSDIO_DRIVER_VENDOR                "National Instruments"
#define NIHSDIO_DRIVER_DESCRIPTION           "NI-HSDIO instrument driver"

/***************************************************************************************************
 *------------------------------------------ Attribute Defines ------------------------------------*
 ***************************************************************************************************/

/* IVI Inherent Instrument Attributes */

/* Advanced Session Information */
#define NIHSDIO_ATTR_LOGICAL_NAME                            IVI_ATTR_LOGICAL_NAME                   /* ViString, read-only */


/********************************** Instrument-Specific Attributes *********************************/

/* Base attributes */
#define NIHSDIO_ATTR_DYNAMIC_CHANNELS                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 2L)    /* ViString */
#define NIHSDIO_ATTR_STATIC_CHANNELS                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 3L)    /* ViString */

/* Device attributes */
#define NIHSDIO_ATTR_TOTAL_ACQUISITION_MEMORY_SIZE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 73L)   /* ViInt32 */
#define NIHSDIO_ATTR_TOTAL_GENERATION_MEMORY_SIZE            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 74L)   /* ViInt32 */
#define NIHSDIO_ATTR_SERIAL_NUMBER                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 96L)   /* ViString */

/* Voltage attributes */
#define NIHSDIO_ATTR_DATA_VOLTAGE_LOW_LEVEL                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 6L)    /* ViReal64, channel-based */
#define NIHSDIO_ATTR_DATA_VOLTAGE_HIGH_LEVEL                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 7L)    /* ViReal64, channel-based */
#define NIHSDIO_ATTR_TRIGGER_VOLTAGE_LOW_LEVEL               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 8L)    /* ViReal64 */
#define NIHSDIO_ATTR_TRIGGER_VOLTAGE_HIGH_LEVEL              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 9L)    /* ViReal64 */
#define NIHSDIO_ATTR_EVENT_VOLTAGE_LOW_LEVEL                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 79L)   /* ViReal64 */
#define NIHSDIO_ATTR_EVENT_VOLTAGE_HIGH_LEVEL                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 80L)   /* ViReal64 */

/* Channel attributes */
#define NIHSDIO_ATTR_DATA_INTERPRETATION                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 10L)   /* ViInt32, channel-based */
#define NIHSDIO_ATTR_INPUT_IMPEDANCE                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 70L)   /* ViReal64, channel-based */
#define NIHSDIO_ATTR_DRIVE_TYPE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 139L)  /* ViInt32, channel-based */

/* Clocking attributes */
#define NIHSDIO_ATTR_REF_CLOCK_SOURCE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 11L)   /* ViString */
#define NIHSDIO_ATTR_REF_CLOCK_RATE                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 12L)   /* ViReal64 */
#define NIHSDIO_ATTR_REF_CLOCK_IMPEDANCE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 58L)   /* ViReal64 */
#define NIHSDIO_ATTR_EXPORTED_REF_CLOCK_OUTPUT_TERMINAL      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 59L)   /* ViString */
#define NIHSDIO_ATTR_SAMPLE_CLOCK_SOURCE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 13L)   /* ViString */
#define NIHSDIO_ATTR_SAMPLE_CLOCK_RATE                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 14L)   /* ViReal64 */
#define NIHSDIO_ATTR_SAMPLE_CLOCK_IMPEDANCE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 60L)   /* ViReal64 */
#define NIHSDIO_ATTR_EXPORTED_SAMPLE_CLOCK_MODE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 61L)   /* ViInt32 */
#define NIHSDIO_ATTR_EXPORTED_SAMPLE_CLOCK_DELAY             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 62L)   /* ViReal64 */
#define NIHSDIO_ATTR_EXPORTED_SAMPLE_CLOCK_OUTPUT_TERMINAL   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 63L)   /* ViString */
#define NIHSDIO_ATTR_EXPORTED_SAMPLE_CLOCK_OFFSET            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 83L)   /* ViReal64 */
#define NIHSDIO_ATTR_EXPORTED_ONBOARD_REF_CLOCK_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 85L)/* ViString */

/* Triggers attributes */
#define NIHSDIO_ATTR_START_TRIGGER_TYPE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 32L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_START_TRIGGER_SOURCE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 33L)   /* ViString */
#define NIHSDIO_ATTR_DIGITAL_EDGE_START_TRIGGER_EDGE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 34L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_START_TRIGGER_IMPEDANCE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)    /* ViReal64 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_START_TRIGGER_POSITION     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 75L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_START_TRIGGER_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 98L)    /* ViInt32 */
#define NIHSDIO_ATTR_PATTERN_MATCH_START_TRIGGER_PATTERN     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 35L)   /* ViString */
#define NIHSDIO_ATTR_PATTERN_MATCH_START_TRIGGER_WHEN        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 36L)   /* ViInt32 */
#define NIHSDIO_ATTR_EXPORTED_START_TRIGGER_OUTPUT_TERMINAL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 37L)   /* ViString */
#define NIHSDIO_ATTR_EXPORTED_START_TRIGGER_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 118L)    /* ViInt32 */

#define NIHSDIO_ATTR_REF_TRIGGER_TYPE                        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 38L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_REF_TRIGGER_SOURCE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 39L)   /* ViString */
#define NIHSDIO_ATTR_DIGITAL_EDGE_REF_TRIGGER_EDGE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 40L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_REF_TRIGGER_IMPEDANCE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)    /* ViReal64 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_REF_TRIGGER_POSITION       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_REF_TRIGGER_TERMINAL_CONFIGURATION      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 99L)    /* ViInt32 */
#define NIHSDIO_ATTR_PATTERN_MATCH_REF_TRIGGER_PATTERN       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 41L)   /* ViString */
#define NIHSDIO_ATTR_PATTERN_MATCH_REF_TRIGGER_WHEN          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 42L)   /* ViInt32 */
#define NIHSDIO_ATTR_EXPORTED_REF_TRIGGER_OUTPUT_TERMINAL    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 43L)   /* ViString */
#define NIHSDIO_ATTR_EXPORTED_REF_TRIGGER_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 119L)    /* ViInt32 */
#define NIHSDIO_ATTR_START_TO_REF_TRIGGER_HOLDOFF            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 86L)   /* ViReal64, seconds */
#define NIHSDIO_ATTR_REF_TO_REF_TRIGGER_HOLDOFF              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 129L)  /* ViReal64, seconds */

#define NIHSDIO_ATTR_SCRIPT_TRIGGER_TYPE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 44L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_SOURCE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 45L)   /* ViString */
#define NIHSDIO_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_EDGE        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 46L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_IMPEDANCE   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)    /* ViReal64 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_SCRIPT_TRIGGER_TERMINAL_CONFIGURATION   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 100L)    /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_SOURCE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 47L)   /* ViString */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_WHEN       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 48L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_IMPEDANCE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 105L)  /* ViReal64 */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_SCRIPT_TRIGGER_TERMINAL_CONFIGURATION   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 106L)    /* ViInt32 */
#define NIHSDIO_ATTR_EXPORTED_SCRIPT_TRIGGER_OUTPUT_TERMINAL (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 49L)   /* ViString */
#define NIHSDIO_ATTR_EXPORTED_SCRIPT_TRIGGER_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 120L)    /* ViInt32 */

#define NIHSDIO_ATTR_PAUSE_TRIGGER_TYPE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 50L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_PAUSE_TRIGGER_SOURCE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 51L)   /* ViString */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_PAUSE_TRIGGER_WHEN        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 52L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_PAUSE_TRIGGER_IMPEDANCE   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 15L)   /* ViReal64 */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_PAUSE_TRIGGER_POSITION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 87L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_LEVEL_PAUSE_TRIGGER_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 101L)    /* ViInt32 */
#define NIHSDIO_ATTR_PATTERN_MATCH_PAUSE_TRIGGER_PATTERN     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 53L)   /* ViString */
#define NIHSDIO_ATTR_PATTERN_MATCH_PAUSE_TRIGGER_WHEN        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 54L)   /* ViInt32 */
#define NIHSDIO_ATTR_EXPORTED_PAUSE_TRIGGER_OUTPUT_TERMINAL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 55L)   /* ViString */
#define NIHSDIO_ATTR_EXPORTED_PAUSE_TRIGGER_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 121L)    /* ViInt32 */

#define NIHSDIO_ATTR_ADVANCE_TRIGGER_TYPE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 88L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_SOURCE       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 89L)   /* ViString */
#define NIHSDIO_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_EDGE         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 90L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_IMPEDANCE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 95L)   /* ViReal64 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_POSITION     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 93L)   /* ViInt32 */
#define NIHSDIO_ATTR_DIGITAL_EDGE_ADVANCE_TRIGGER_TERMINAL_CONFIGURATION      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 107L)    /* ViInt32 */
#define NIHSDIO_ATTR_PATTERN_MATCH_ADVANCE_TRIGGER_PATTERN     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 91L)   /* ViString */
#define NIHSDIO_ATTR_PATTERN_MATCH_ADVANCE_TRIGGER_WHEN        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 92L)   /* ViInt32 */
#define NIHSDIO_ATTR_EXPORTED_ADVANCE_TRIGGER_OUTPUT_TERMINAL  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 94L)   /* ViString */
#define NIHSDIO_ATTR_EXPORTED_ADVANCE_TRIGGER_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 122L)    /* ViInt32 */

#define NIHSDIO_ATTR_STOP_TRIGGER_TYPE                                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 152L)  /* ViInt32  */
#define NIHSDIO_ATTR_DIGITAL_EDGE_STOP_TRIGGER_SOURCE                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 153L)  /* ViString */
#define NIHSDIO_ATTR_DIGITAL_EDGE_STOP_TRIGGER_EDGE                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 154L)  /* ViInt32  */
#define NIHSDIO_ATTR_DIGITAL_EDGE_STOP_TRIGGER_TERMINAL_CONFIGURATION   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 155L)  /* ViInt32  */
#define NIHSDIO_ATTR_DIGITAL_EDGE_STOP_TRIGGER_IMPEDANCE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 156L)   /* ViReal64 */
#define NIHSDIO_ATTR_EXPORTED_STOP_TRIGGER_OUTPUT_TERMINAL              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 157L)  /* ViString */
#define NIHSDIO_ATTR_EXPORTED_STOP_TRIGGER_TERMINAL_CONFIGURATION       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 158L) /* ViInt32  */

/* Events attributes */
#define NIHSDIO_ATTR_READY_FOR_START_EVENT_OUTPUT_TERMINAL           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 16L)   /* ViString */
#define NIHSDIO_ATTR_READY_FOR_START_EVENT_LEVEL_ACTIVE_LEVEL        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 17L)   /* ViInt32 */
#define NIHSDIO_ATTR_READY_FOR_START_EVENT_TERMINAL_CONFIGURATION    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 102L)  /* ViInt32 */

#define NIHSDIO_ATTR_DATA_ACTIVE_EVENT_OUTPUT_TERMINAL        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 19L)   /* ViString */
#define NIHSDIO_ATTR_DATA_ACTIVE_EVENT_LEVEL_ACTIVE_LEVEL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 20L)   /* ViInt32 */
#define NIHSDIO_ATTR_DATA_ACTIVE_EVENT_POSITION               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 81L)   /* ViInt32 */
#define NIHSDIO_ATTR_DATA_ACTIVE_EVENT_TERMINAL_CONFIGURATION (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 103L)  /* ViInt32 */

#define NIHSDIO_ATTR_MARKER_EVENT_OUTPUT_TERMINAL              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 22L)   /* ViString */
#define NIHSDIO_ATTR_MARKER_EVENT_PULSE_POLARITY               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 23L)   /* ViInt32 */
#define NIHSDIO_ATTR_MARKER_EVENT_POSITION                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 82L)   /* ViInt32 */
#define NIHSDIO_ATTR_MARKER_EVENT_TERMINAL_CONFIGURATION       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 104L)  /* ViInt32 */

#define NIHSDIO_ATTR_READY_FOR_ADVANCE_EVENT_OUTPUT_TERMINAL        (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 109L)   /* ViString */
#define NIHSDIO_ATTR_READY_FOR_ADVANCE_EVENT_LEVEL_ACTIVE_LEVEL     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 110L)   /* ViInt32 */
#define NIHSDIO_ATTR_READY_FOR_ADVANCE_EVENT_TERMINAL_CONFIGURATION (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 111L)   /* ViInt32 */

#define NIHSDIO_ATTR_END_OF_RECORD_EVENT_OUTPUT_TERMINAL          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 112L)   /* ViString */
#define NIHSDIO_ATTR_END_OF_RECORD_EVENT_PULSE_POLARITY           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 113L)   /* ViInt32 */
#define NIHSDIO_ATTR_END_OF_RECORD_EVENT_TERMINAL_CONFIGURATION   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 114L)   /* ViInt32 */

#define NIHSDIO_ATTR_HWC_SAMPLE_ERROR_EVENT_OUTPUT_TERMINAL       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 136L) /* ViString */

/* Dynamic output attributes */
#define NIHSDIO_ATTR_GENERATION_MODE                         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 25L)   /* ViInt32 */
#define NIHSDIO_ATTR_REPEAT_MODE                             (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 26L)   /* ViInt32 */
#define NIHSDIO_ATTR_REPEAT_COUNT                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 71L)   /* ViInt32 */
#define NIHSDIO_ATTR_WAVEFORM_TO_GENERATE                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 27L)   /* ViString */
#define NIHSDIO_ATTR_SCRIPT_TO_GENERATE                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 28L)   /* ViString */
#define NIHSDIO_ATTR_INITIAL_STATE                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 64L)   /* ViInt32, channel-based */
#define NIHSDIO_ATTR_IDLE_STATE                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 65L)   /* ViInt32, channel-based */
#define NIHSDIO_ATTR_DATA_TRANSFER_BLOCK_SIZE                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 144L)  /* ViInt32, samples */

/* Dynamic input attributes */
#define NIHSDIO_ATTR_SAMPLES_PER_RECORD                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 29L)    /* ViInt32 */
#define NIHSDIO_ATTR_NUM_RECORDS                            (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 126L)   /* ViInt32 */
#define NIHSDIO_ATTR_REF_TRIGGER_PRETRIGGER_SAMPLES         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 30L)    /* ViInt32 */
#define NIHSDIO_ATTR_FETCH_BACKLOG                          (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 31L)    /* ViInt32, read-only */
#define NIHSDIO_ATTR_FETCH_RELATIVE_TO                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 67L)    /* ViInt32 */
#define NIHSDIO_ATTR_FETCH_OFFSET                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 68L)    /* ViInt32 */
#define NIHSDIO_ATTR_RECORDS_DONE                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 125L)   /* ViInt32 */
#define NIHSDIO_ATTR_DATA_ACTIVE_INTERNAL_ROUTE_DELAY       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 138L)   /* ViInt32 */
#define NIHSDIO_ATTR_SAMPLES_PER_RECORD_IS_FINITE           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 159L)   /* ViBoolean */

/* Data Position Delay */
#define NIHSDIO_ATTR_DATA_POSITION                           (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 56L)   /* ViInt32 */
#define NIHSDIO_ATTR_DATA_POSITION_DELAY                     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 57L)   /* ViReal64 */

/* Data Width */
#define NIHSDIO_ATTR_DATA_WIDTH                              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 108L)  /* ViInt32 */

/* Data Rate Multiplier */
#define NIHSDIO_ATTR_DATA_RATE_MULTIPLIER                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 128L)  /* ViInt32 */

/* Supported Data States */
#define NIHSDIO_ATTR_SUPPORTED_DATA_STATES                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 130L)  /* ViInt32 */

/* Synchronization attributes */
#define NIHSDIO_ATTR_OSCILLATOR_PHASE_DAC_VALUE              (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 72L)   /* ViInt32 */

/* Hardware compare */
#define NIHSDIO_ATTR_HWC_SAMPLE_ERROR_BACKLOG                (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 132L)  /* ViInt32 */
#define NIHSDIO_ATTR_HWC_NUM_SAMPLE_ERRORS                   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 133L)  /* ViInt32 */
#define NIHSDIO_ATTR_HWC_SAMPLES_COMPARED                    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 134L)  /* ViReal64 */
#define NIHSDIO_ATTR_HWC_FILTER_REPEATED_SAMPLE_ERRORS       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 140L)  /* ViBoolean */
#define NIHSDIO_ATTR_HWC_SAMPLE_ERROR_BUFFER_OVERFLOWED      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 135L)  /* ViBoolean */

/* Streaming attributes */
#define NIHSDIO_ATTR_SPACE_AVAILABLE_IN_STREAMING_WAVEFORM   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 141L)  /* ViInt32, read-only */
#define NIHSDIO_ATTR_STREAMING_WAVEFORM_NAME                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 142L)  /* ViString */
#define NIHSDIO_ATTR_STREAMING_ENABLED                       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 143L)  /* ViBoolean */

/* DirectDMA attributes */
#define NIHSDIO_ATTR_DIRECT_DMA_ENABLED                      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 146L)  /* ViBoolean */
#define NIHSDIO_ATTR_DIRECT_DMA_WINDOW_SIZE                  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 147L)  /* ViInt32 */
#define NIHSDIO_ATTR_DIRECT_DMA_WINDOW_ADDRESS               (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 148L)  /* ViInt32 */

/* Bandwidth Governing attributes */
#define NIHSDIO_ATTR_DATA_TRANSFER_MAXIMUM_BANDWIDTH         (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 149L)  /* ViReal64 */
#define NIHSDIO_ATTR_DATA_TRANSFER_PREFERRED_PACKET_SIZE     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 150L)  /* ViInt32 */
#define NIHSDIO_ATTR_DATA_TRANSFER_MAXIMUM_IN_FLIGHT_READS   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 151L)  /* ViInt32 */

/***************************************************************************************************
 *----------------------------------- Attribute Value Defines -------------------------------------*
 ***************************************************************************************************/

/************************** Instrument specific attribute value definitions ************************/

/* Data interpretation */
#define NIHSDIO_VAL_HIGH_OR_LOW                          3
#define NIHSDIO_VAL_VALID_OR_INVALID                     4

/* Drive type */
#define NIHSDIO_VAL_ACTIVE_DRIVE                         75
#define NIHSDIO_VAL_OPEN_COLLECTOR                       76

/* Logic family */
#define NIHSDIO_VAL_5_0V_LOGIC                           5
#define NIHSDIO_VAL_3_3V_LOGIC                           6
#define NIHSDIO_VAL_2_5V_LOGIC                           7
#define NIHSDIO_VAL_1_8V_LOGIC                           8
#define NIHSDIO_VAL_1_5V_LOGIC                           80
#define NIHSDIO_VAL_1_2V_LOGIC                           81

/* Digital edge */
#define NIHSDIO_VAL_RISING_EDGE                          12
#define NIHSDIO_VAL_FALLING_EDGE                         13

/* Pattern Match Values */
#define NIHSDIO_VAL_IGNORE                               33
#define NIHSDIO_VAL_MATCH_LOW                            0
#define NIHSDIO_VAL_MATCH_HIGH                           1

/* Trigger digital pattern trigger when */
#define NIHSDIO_VAL_PATTERN_MATCHES                      36
#define NIHSDIO_VAL_PATTERN_DOES_NOT_MATCH               37

/* Event polarity */
#define NIHSDIO_VAL_ACTIVE_HIGH                          10
#define NIHSDIO_VAL_ACTIVE_LOW                           11

/* Generation mode */
#define NIHSDIO_VAL_WAVEFORM                             14
#define NIHSDIO_VAL_SCRIPTED                             15

/* Repeat mode */
#define NIHSDIO_VAL_FINITE                               16
#define NIHSDIO_VAL_CONTINUOUS                           17

/* Data Position Delay */
#define NIHSDIO_VAL_SAMPLE_CLOCK_RISING_EDGE             18
#define NIHSDIO_VAL_SAMPLE_CLOCK_FALLING_EDGE            19
#define NIHSDIO_VAL_DELAY_FROM_SAMPLE_CLOCK_RISING_EDGE  20

/* Exported Sample Clock Inversion/Delay */
#define NIHSDIO_VAL_NONINVERTED                          21
#define NIHSDIO_VAL_INVERTED                             22
#define NIHSDIO_VAL_DELAYED                              23

/* Initial/Idle State */
#define NIHSDIO_VAL_TRISTATE                             24
#define NIHSDIO_VAL_LOGIC_HIGH                           1
#define NIHSDIO_VAL_LOGIC_LOW                            0
#define NIHSDIO_VAL_HOLD_LAST_VALUE                      27

/* Trigger Types */
#define NIHSDIO_VAL_NONE                                 28
#define NIHSDIO_VAL_DIGITAL_EDGE                         29
#define NIHSDIO_VAL_DIGITAL_LEVEL                        30
#define NIHSDIO_VAL_PATTERN_MATCH                        31
#define NIHSDIO_VAL_SOFTWARE                             32

/* Level Trigger Values */
#define NIHSDIO_VAL_HIGH                                 34
#define NIHSDIO_VAL_LOW                                  35

/* Write Position Value */
#define NIHSDIO_VAL_START_OF_WAVEFORM                    44
#define NIHSDIO_VAL_CURRENT_POSITION                     45

/* Fetch Position Value */
#define NIHSDIO_VAL_MOST_RECENT_SAMPLE                   46
#define NIHSDIO_VAL_FIRST_SAMPLE                         47
#define NIHSDIO_VAL_REFERENCE_TRIGGER                    48
#define NIHSDIO_VAL_FIRST_PRETRIGGER_SAMPLE              49
#define NIHSDIO_VAL_CURRENT_READ_POSITION                50

/* Signal Values */
#define NIHSDIO_VAL_SAMPLE_CLOCK                         51
#define NIHSDIO_VAL_REF_CLOCK                            52
#define NIHSDIO_VAL_START_TRIGGER                        53
#define NIHSDIO_VAL_REF_TRIGGER                          54
#define NIHSDIO_VAL_DATA_ACTIVE_EVENT                    55
#define NIHSDIO_VAL_READY_FOR_START_EVENT                56
#define NIHSDIO_VAL_READY_FOR_ADVANCE_EVENT              66
#define NIHSDIO_VAL_END_OF_RECORD_EVENT                  68
#define NIHSDIO_VAL_PAUSE_TRIGGER                        57
#define NIHSDIO_VAL_SCRIPT_TRIGGER                       58
#define NIHSDIO_VAL_MARKER_EVENT                         59
#define NIHSDIO_VAL_ONBOARD_REF_CLOCK                    60
#define NIHSDIO_VAL_ADVANCE_TRIGGER                      61
#define NIHSDIO_VAL_STOP_TRIGGER                         82

/* Timestamp Type Values */
#define NIHSDIO_VAL_TIMESTAMP_ABSOLUTE                   69
#define NIHSDIO_VAL_TIMESTAMP_RELATIVE                   70

/* Calibration values */
#define NIHSDIO_VAL_EXT_CAL_COMMIT                       62
#define NIHSDIO_VAL_EXT_CAL_CANCEL                       63

/* Terminal Configuration Values */
#define NIHSDIO_VAL_LVDS                                 64
#define NIHSDIO_VAL_SINGLE_ENDED                         65

/* Data Rate Mode Values */
#define NIHSDIO_VAL_SINGLE_DATA_RATE                     1
#define NIHSDIO_VAL_DOUBLE_DATA_RATE                     2

/* Data Layout Values for WDT */
#define NIHSDIO_VAL_GROUP_BY_SAMPLE                      71
#define NIHSDIO_VAL_GROUP_BY_CHANNEL                     72

/* Supported Data States Values */
#define NIHSDIO_VAL_STATES_0_1                         77
#define NIHSDIO_VAL_STATES_0_1_Z                       83
#define NIHSDIO_VAL_STATES_0_1_Z_L_H_X                 78
#define NIHSDIO_VAL_STATES_L_H_X                       79

/****** String enum values for terminal names (used for CVI Get/Set Attribute functions only) *******/
#define NIHSDIO_VAL_DO_NOT_EXPORT_STR                    ""
#define NIHSDIO_VAL_PFI0_STR                             "PFI0"
#define NIHSDIO_VAL_PFI1_STR                             "PFI1"
#define NIHSDIO_VAL_PFI2_STR                             "PFI2"
#define NIHSDIO_VAL_PFI3_STR                             "PFI3"
#define NIHSDIO_VAL_PXI_TRIG0_STR                        "PXI_Trig0"
#define NIHSDIO_VAL_PXI_TRIG1_STR                        "PXI_Trig1"
#define NIHSDIO_VAL_PXI_TRIG2_STR                        "PXI_Trig2"
#define NIHSDIO_VAL_PXI_TRIG3_STR                        "PXI_Trig3"
#define NIHSDIO_VAL_PXI_TRIG4_STR                        "PXI_Trig4"
#define NIHSDIO_VAL_PXI_TRIG5_STR                        "PXI_Trig5"
#define NIHSDIO_VAL_PXI_TRIG6_STR                        "PXI_Trig6"
#define NIHSDIO_VAL_PXI_TRIG7_STR                        "PXI_Trig7"
#define NIHSDIO_VAL_PXI_STAR_STR                         "PXI_STAR"
#define NIHSDIO_VAL_CLK_OUT_STR                          "ClkOut"
#define NIHSDIO_VAL_DDC_CLK_OUT_STR                      "DDC_ClkOut"
#define NIHSDIO_VAL_ON_BOARD_CLOCK_STR                   "OnBoardClock"
#define NIHSDIO_VAL_CLK_IN_STR                           "ClkIn"
#define NIHSDIO_VAL_PXI_CLK_STR                          "PXI_CLK"
#define NIHSDIO_VAL_STROBE_STR                           "STROBE"
#define NIHSDIO_VAL_NONE_STR                             "None"
#define NIHSDIO_VAL_RTSI0_STR                            "RTSI0"
#define NIHSDIO_VAL_RTSI1_STR                            "RTSI1"
#define NIHSDIO_VAL_RTSI2_STR                            "RTSI2"
#define NIHSDIO_VAL_RTSI3_STR                            "RTSI3"
#define NIHSDIO_VAL_RTSI4_STR                            "RTSI4"
#define NIHSDIO_VAL_RTSI5_STR                            "RTSI5"
#define NIHSDIO_VAL_RTSI6_STR                            "RTSI6"
#define NIHSDIO_VAL_RTSI7_STR                            "RTSI7"

/****** String enum values for signal names *******/
#define NIHSDIO_VAL_SCRIPT_TRIGGER0                      "scriptTrigger0"
#define NIHSDIO_VAL_SCRIPT_TRIGGER1                      "scriptTrigger1"
#define NIHSDIO_VAL_SCRIPT_TRIGGER2                      "scriptTrigger2"
#define NIHSDIO_VAL_SCRIPT_TRIGGER3                      "scriptTrigger3"
#define NIHSDIO_VAL_MARKER_EVENT0                        "marker0"
#define NIHSDIO_VAL_MARKER_EVENT1                        "marker1"
#define NIHSDIO_VAL_MARKER_EVENT2                        "marker2"
#define NIHSDIO_VAL_MARKER_EVENT3                        "marker3"

/************************************* Digital Channel States **************************************/

#define NI_DIO_0  0
#define NI_DIO_1  1
#define NI_DIO_Z  2
#define NI_DIO_L  3
#define NI_DIO_H  4
#define NI_DIO_X  5
#define NI_DIO_T  6
#define NI_DIO_V  7

/***************************************************************************************************
 *---------------------------- Instrument Driver Function Declarations ----------------------------*
 ***************************************************************************************************/

/* Init and Close Functions */
ViStatus _VI_FUNC niHSDIO_InitAcquisitionSession (
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession *vi);
ViStatus _VI_FUNC niHSDIO_InitGenerationSession (
   ViRsrc resourceName,
   ViBoolean IDQuery,
   ViBoolean resetDevice,
   ViConstString optionString,
   ViSession *vi);
ViStatus _VI_FUNC niHSDIO_close (
   ViSession vi);

/* Locking Functions */
ViStatus _VI_FUNC niHSDIO_LockSession (
   ViSession vi,
   ViBoolean *callerHasLock);
ViStatus _VI_FUNC niHSDIO_UnlockSession (
   ViSession vi,
   ViBoolean *callerHasLock);

/* Control Functions */
ViStatus _VI_FUNC niHSDIO_Initiate (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_Abort (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_CommitStatic (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_CommitDynamic (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_WaitUntilDone (
   ViSession vi,
   ViInt32 maxTime);
ViStatus _VI_FUNC niHSDIO_IsDone (
   ViSession vi,
   ViBoolean* done);
ViStatus _VI_FUNC niHSDIO_TristateChannels (
   ViSession vi,
   ViConstString channelList,
   ViBoolean tristate);

/* Static I/O Functions */
ViStatus _VI_FUNC niHSDIO_AssignStaticChannels (
   ViSession vi,
   ViConstString channelList);
ViStatus _VI_FUNC niHSDIO_WriteStaticU32 (
   ViSession vi, ViUInt32 writeData,
   ViUInt32 channelMask);
ViStatus _VI_FUNC niHSDIO_ReadStaticU32 (
   ViSession vi,
   ViUInt32* data);

/* Voltage Configuration Functions */
ViStatus _VI_FUNC niHSDIO_ConfigureDataVoltageLogicFamily (
   ViSession vi,
   ViConstString channelList,
   ViInt32 logicFamily);
ViStatus _VI_FUNC niHSDIO_ConfigureDataVoltageCustomLevels (
   ViSession vi,
   ViConstString channelList,
   ViReal64 lowLevel,
   ViReal64 highLevel);
ViStatus _VI_FUNC niHSDIO_ConfigureTriggerVoltageLogicFamily (
   ViSession vi,
   ViInt32 logicFamily);
ViStatus _VI_FUNC niHSDIO_ConfigureTriggerVoltageCustomLevels (
   ViSession vi,
   ViReal64 lowLevel,
   ViReal64 highLevel);
ViStatus _VI_FUNC niHSDIO_ConfigureEventVoltageLogicFamily (
   ViSession vi,
   ViInt32 logicFamily);
ViStatus _VI_FUNC niHSDIO_ConfigureEventVoltageCustomLevels(
   ViSession vi,
   ViReal64 lowLevel,
   ViReal64 highLevel);

/* Timing Configuration Functions */
ViStatus _VI_FUNC niHSDIO_ConfigureRefClock (
   ViSession vi,
   ViConstString clockSource,
   ViReal64 clockRate);
ViStatus _VI_FUNC niHSDIO_ConfigureSampleClock (
   ViSession vi,
   ViConstString clockSource,
   ViReal64 clockRate);
ViStatus _VI_FUNC niHSDIO_ConfigureDataPosition (
   ViSession vi,
   ViConstString channelList,
   ViInt32 position);
ViStatus _VI_FUNC niHSDIO_ConfigureDataPositionDelay (
   ViSession vi,
   ViConstString channelList,
   ViReal64 delay);
ViStatus _VI_FUNC niHSDIO_AdjustSampleClockRelativeDelay (
   ViSession vi,
   ViReal64 adjustmentTime);

/* Triggers Functions */
ViStatus _VI_FUNC niHSDIO_SendSoftwareEdgeTrigger (
   ViSession vi,
   ViInt32 triggerName,
   ViConstString triggerIdentifier);

ViStatus _VI_FUNC niHSDIO_ConfigureDigitalLevelPauseTrigger (
   ViSession vi,
   ViConstString source,
   ViInt32 level);
ViStatus _VI_FUNC niHSDIO_DisablePauseTrigger (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchPauseTrigger (
   ViSession vi,
   ViConstString channelList,
   ViConstString pattern,
   ViInt32 triggerWhen);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchPauseTriggerU32 (
   ViSession vi,
   ViConstString channelList,
   ViUInt32 pattern,
   ViInt32 triggerWhen);

ViStatus _VI_FUNC niHSDIO_ConfigureDigitalEdgeScriptTrigger (
   ViSession vi,
   ViConstString triggerID,
   ViConstString source,
   ViInt32 edge);
ViStatus _VI_FUNC niHSDIO_ConfigureDigitalLevelScriptTrigger (
   ViSession vi,
   ViConstString triggerID,
   ViConstString source,
   ViInt32 level);
ViStatus _VI_FUNC niHSDIO_DisableScriptTrigger (
   ViSession vi,
   ViConstString triggerID);
ViStatus _VI_FUNC niHSDIO_ConfigureSoftwareScriptTrigger (
   ViSession vi,
   ViConstString triggerID);

ViStatus _VI_FUNC niHSDIO_ConfigureDigitalEdgeStartTrigger (
   ViSession vi,
   ViConstString source,
   ViInt32 edge);
ViStatus _VI_FUNC niHSDIO_DisableStartTrigger (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ConfigureSoftwareStartTrigger (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchStartTrigger (
   ViSession vi,
   ViConstString channelList,
   ViConstString pattern,
   ViInt32 triggerWhen);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchStartTriggerU32 (
   ViSession vi,
   ViConstString channelList,
   ViUInt32 pattern,
   ViInt32 triggerWhen);

ViStatus _VI_FUNC niHSDIO_ConfigureDigitalEdgeAdvanceTrigger (
   ViSession vi,
   ViConstString source,
   ViInt32 edge);
ViStatus _VI_FUNC niHSDIO_DisableAdvanceTrigger (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ConfigureSoftwareAdvanceTrigger (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchAdvanceTrigger (
   ViSession vi,
   ViConstString channelList,
   ViConstString pattern,
   ViInt32 triggerWhen);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchAdvanceTriggerU32 (
   ViSession vi,
   ViConstString channelList,
   ViUInt32 pattern,
   ViInt32 triggerWhen);

ViStatus _VI_FUNC niHSDIO_ConfigureDigitalEdgeRefTrigger (
   ViSession vi,
   ViConstString source,
   ViInt32 edge,
   ViInt32 pretriggerSamples);
ViStatus _VI_FUNC niHSDIO_DisableRefTrigger (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ConfigureSoftwareRefTrigger (
   ViSession vi,
   ViInt32 pretriggerSamples);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchRefTrigger (
   ViSession vi,
   ViConstString channelList,
   ViConstString pattern,
   ViInt32 triggerWhen,
   ViInt32 pretrigSamples);
ViStatus _VI_FUNC niHSDIO_ConfigurePatternMatchRefTriggerU32 (
   ViSession vi,
   ViConstString channelList,
   ViUInt32 pattern,
   ViInt32 triggerWhen,
   ViInt32 pretrigSamples);

ViStatus _VI_FUNC niHSDIO_ConfigureDigitalEdgeStopTrigger (
   ViSession vi,
   ViConstString source,
   ViInt32 edge);
ViStatus _VI_FUNC niHSDIO_DisableStopTrigger (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ConfigureSoftwareStopTrigger (
   ViSession vi);

/* Events Functions */
ViStatus _VI_FUNC niHSDIO_ExportSignal (
   ViSession vi,
   ViInt32 signal,
   ViConstString signalIdentifier,
   ViConstString outputTerminal);

/* Dynamic Generation Functions */
ViStatus _VI_FUNC niHSDIO_AssignDynamicChannels (
   ViSession vi,
   ViConstString channelList);
ViStatus _VI_FUNC niHSDIO_AllocateNamedWaveform (
   ViSession vi,
   ViConstString waveformName,
   ViInt32 sizeInSamples);
ViStatus _VI_FUNC niHSDIO_DeleteNamedWaveform (
   ViSession vi,
   ViConstString waveformName);
ViStatus _VI_FUNC niHSDIO_WriteNamedWaveformU32 (
   ViSession vi,
   ViConstString waveformName,
   ViInt32 samplesToWrite,
   ViUInt32 data[]);
ViStatus _VI_FUNC niHSDIO_WriteNamedWaveformU16 (
   ViSession vi,
   ViConstString waveformName,
   ViInt32 samplesToWrite,
   ViUInt16 data[]);
ViStatus _VI_FUNC niHSDIO_WriteNamedWaveformU8 (
   ViSession vi,
   ViConstString waveformName,
   ViInt32 samplesToWrite,
   ViUInt8 data[]);
ViStatus _VI_FUNC niHSDIO_WriteNamedWaveformWDT(
   ViSession vi,
   ViConstString waveformName,
   ViInt32 samplesPerChannel,
   ViInt32 dataLayout,
   ViUInt8 data[]);
ViStatus _VI_FUNC niHSDIO_WriteNamedWaveformFromFileHWS(
   ViSession vi,
   ViConstString waveformName,
   ViConstString filePath,
   ViBoolean useRateFromWaveform,
   ViInt32* waveformSizeInSamples);
ViStatus _VI_FUNC niHSDIO_ConfigureGenerationMode (
   ViSession vi,
   ViInt32 generationMode);
ViStatus _VI_FUNC niHSDIO_ConfigureGenerationRepeat (
   ViSession vi,
   ViInt32 repeatMode,
   ViInt32 repeatCount);
ViStatus _VI_FUNC niHSDIO_WriteScript (
   ViSession vi,
   ViConstString script);
ViStatus _VI_FUNC niHSDIO_ConfigureWaveformToGenerate (
   ViSession vi,
   ViConstString waveformName);
ViStatus _VI_FUNC niHSDIO_ConfigureScriptToGenerate (
   ViSession vi,
   ViConstString scriptName);
ViStatus _VI_FUNC niHSDIO_ConfigureInitialState (
   ViSession vi,
   ViConstString channelList,
   ViConstString initialState);
ViStatus _VI_FUNC niHSDIO_ConfigureInitialStateU32 (
   ViSession vi,
   ViUInt32 initialState);
ViStatus _VI_FUNC niHSDIO_ConfigureIdleState (
   ViSession vi,
   ViConstString channelList,
   ViConstString idleState);
ViStatus _VI_FUNC niHSDIO_ConfigureIdleStateU32 (
   ViSession vi,
   ViUInt32 idleState);
ViStatus _VI_FUNC niHSDIO_SetNamedWaveformNextWritePosition (
   ViSession vi,
   ViConstString waveformName,
   ViInt32 relativeTo,
   ViInt32 offset);

/* Dynamic Acquisition Functions */

#if defined(_WIN64)
   #pragma pack(push,8)
#else
   #pragma pack(push,4)
#endif
struct niHSDIO_wfmInfo
{
   ViReal64 absoluteTimestamp;
   ViReal64 relativeTimestamp;
   ViReal64 dt;
   ViInt32 actualSamplesRead;
   ViReal64 reserved1;
   ViReal64 reserved2;
};
#pragma pack(pop)

ViStatus _VI_FUNC niHSDIO_ConfigureAcquisitionSize (
   ViSession vi,
   ViInt32 samplesPerRecord,
   ViInt32 numberOfRecords);
ViStatus _VI_FUNC niHSDIO_ConfigureDataInterpretation (
   ViSession vi,
   ViConstString channelList,
   ViInt32 dataInterpretation);
ViStatus _VI_FUNC niHSDIO_GetFetchBacklog(
   ViSession vi,
   ViInt32 recordNumber,
   ViInt32* backlog);
ViStatus _VI_FUNC niHSDIO_FetchMultiRecordU32 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32 startingRecord,
   ViInt32 numberOfRecords,
   ViUInt32 data[],
   struct niHSDIO_wfmInfo wfmInfo[]);
ViStatus _VI_FUNC niHSDIO_FetchMultiRecordU16 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32 startingRecord,
   ViInt32 numberOfRecords,
   ViUInt16 data[],
   struct niHSDIO_wfmInfo wfmInfo[]);
ViStatus _VI_FUNC niHSDIO_FetchMultiRecordU8 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32 startingRecord,
   ViInt32 numberOfRecords,
   ViUInt8 data[],
   struct niHSDIO_wfmInfo wfmInfo[]);
ViStatus _VI_FUNC niHSDIO_FetchWaveformU32 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32* numberOfSamplesRead,
   ViUInt32 data[]);
ViStatus _VI_FUNC niHSDIO_FetchWaveformU16 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32* numberOfSamplesRead,
   ViUInt16 data[]);
ViStatus _VI_FUNC niHSDIO_FetchWaveformU8 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32* numberOfSamplesRead,
   ViUInt8 data[]);
ViStatus _VI_FUNC niHSDIO_FetchWaveformDirectDMA (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViUInt32 bufferSize,
   void* bufferAddress,
   struct niHSDIO_wfmInfo* wfmInfo,
   ViUInt32* offsetToFirstSample);
ViStatus _VI_FUNC niHSDIO_ReadWaveformU32 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32* numberOfSamplesRead,
   ViUInt32 data[]);
ViStatus _VI_FUNC niHSDIO_ReadWaveformU16 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32* numberOfSamplesRead,
   ViUInt16 data[]);
ViStatus _VI_FUNC niHSDIO_ReadWaveformU8 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32* numberOfSamplesRead,
   ViUInt8 data[]);
ViStatus _VI_FUNC niHSDIO_ReadMultiRecordU32 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32 startingRecord,
   ViInt32 numberOfRecords,
   ViUInt32 data[],
   struct niHSDIO_wfmInfo wfmInfo[]);
ViStatus _VI_FUNC niHSDIO_ReadMultiRecordU16 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32 startingRecord,
   ViInt32 numberOfRecords,
   ViUInt16 data[],
   struct niHSDIO_wfmInfo wfmInfo[]);
ViStatus _VI_FUNC niHSDIO_ReadMultiRecordU8 (
   ViSession vi,
   ViInt32 samplesToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32 startingRecord,
   ViInt32 numberOfRecords,
   ViUInt8 data[],
   struct niHSDIO_wfmInfo wfmInfo[]);
ViStatus _VI_FUNC niHSDIO_HWC_FetchSampleErrors(
   ViSession vi,
   ViInt32 numSampleErrorsToRead,
   ViInt32 maxTimeMilliseconds,
   ViInt32* numSampleErrorsRead,
   ViReal64 sampleNumber[],
   ViUInt32 errorBits[],
   ViInt32 errorRepeatCount[],
   ViUInt32* reserved1,
   ViUInt32* reserved2);

/* Error Functions */
ViStatus _VI_FUNC niHSDIO_error_message (
   ViSession vi,
   ViStatus errorCode,
   ViChar errorMessage[256]);
ViStatus _VI_FUNC niHSDIO_GetError (
   ViSession vi,
   ViStatus* errorCode,
   ViInt32 errorDescriptionBufferSize,
   ViChar errorDescription[]);
ViStatus _VI_FUNC niHSDIO_ClearError (
   ViSession vi);

/* Utility Functions */
ViStatus _VI_FUNC niHSDIO_reset (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_self_test (
   ViSession vi,
   ViInt16 *selfTestResult,
   ViChar selfTestMessage[]);
ViStatus _VI_FUNC niHSDIO_SelfCal (
   ViSession vi);
ViStatus _VI_FUNC niHSDIO_ResetDevice (
   ViSession vi);


/* Set and Get Attribute Functions */
ViStatus _VI_FUNC niHSDIO_GetAttributeViInt32 (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt32 *value);
ViStatus _VI_FUNC niHSDIO_GetAttributeViReal64 (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViReal64 *value);
ViStatus _VI_FUNC niHSDIO_GetAttributeViString (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt32 bufSize,
   ViChar value[]);
ViStatus _VI_FUNC niHSDIO_GetAttributeViSession (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViSession *value);
ViStatus _VI_FUNC niHSDIO_GetAttributeViBoolean (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViBoolean *value);

ViStatus _VI_FUNC niHSDIO_SetAttributeViInt32 (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViInt32 value);
ViStatus _VI_FUNC niHSDIO_SetAttributeViReal64 (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViReal64 value);
ViStatus _VI_FUNC niHSDIO_SetAttributeViString (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViConstString value);
ViStatus _VI_FUNC niHSDIO_SetAttributeViSession (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViSession value);
ViStatus _VI_FUNC niHSDIO_SetAttributeViBoolean (
   ViSession vi,
   ViConstString channelName,
   ViAttr attribute,
   ViBoolean value);

/* Reset Attribute */
ViStatus _VI_FUNC niHSDIO_ResetAttribute (
   ViSession vi,
   ViConstString channelName,
   ViAttr attributeId);

/* Calibration Functions */
ViStatus _VI_FUNC niHSDIO_InitExtCal (
   ViRsrc resourceName,
   ViConstString password,
   ViSession *vi);
ViStatus _VI_FUNC niHSDIO_CalAdjustChannelVoltage (
   ViSession vi,
   ViConstString channel);
ViStatus _VI_FUNC niHSDIO_CalAdjustChannelSkew (
   ViSession vi,
   ViConstString channel);
ViStatus _VI_FUNC niHSDIO_CalAdjustTerminalSkew (
   ViSession vi,
   ViConstString channel);
ViStatus _VI_FUNC niHSDIO_GetSelfCalSupported (
   ViSession vi,
   ViBoolean* selfCalSupported);
ViStatus _VI_FUNC niHSDIO_GetSelfCalLastDateAndTime (
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);
ViStatus _VI_FUNC niHSDIO_GetExtCalLastDateAndTime (
   ViSession vi,
   ViInt32* year,
   ViInt32* month,
   ViInt32* day,
   ViInt32* hour,
   ViInt32* minute);
ViStatus _VI_FUNC niHSDIO_GetSelfCalLastTemp (
   ViSession vi,
   ViReal64* temp);
ViStatus _VI_FUNC niHSDIO_GetExtCalLastTemp (
   ViSession vi,
   ViReal64* temp);
ViStatus _VI_FUNC niHSDIO_GetExtCalRecommendedInterval (
   ViSession vi,
   ViInt32* interval);
ViStatus _VI_FUNC niHSDIO_ChangeExtCalPassword (
   ViSession vi,
   ViConstString oldPassword,
   ViConstString newPassword);
ViStatus _VI_FUNC niHSDIO_SetCalUserDefinedInfo (
   ViSession vi,
   ViConstString info);
ViStatus _VI_FUNC niHSDIO_GetCalUserDefinedInfo (
   ViSession vi,
   ViString info);
ViStatus _VI_FUNC niHSDIO_GetCalUserDefinedInfoMaxSize (
   ViSession vi,
   ViInt32* infoSize);
ViStatus _VI_FUNC niHSDIO_CloseExtCal(
   ViSession vi,
   ViInt32 action);
ViStatus _VI_FUNC niHSDIO_RecordExtCalVerification(
   ViSession vi,
   ViConstString password);

/***************************************************************************************************
 *------------------------------------------ Status Codes -----------------------------------------*
 ***************************************************************************************************/

/* Error codes */
#define NIHSDIO_ERROR_INVALID_RESOURCE_DESCRIPTOR                  (IVI_SPECIFIC_ERROR_BASE + 44L)
#define NIHSDIO_ERROR_INVALID_CHANNEL_STRING_SYNTAX                (IVI_SPECIFIC_ERROR_BASE + 2L)
#define NIHSDIO_ERROR_NO_DYNAMIC_LINES_ENABLED                     (IVI_SPECIFIC_ERROR_BASE + 4L)
#define NIHSDIO_ERROR_SESSION_IN_RUNNING_STATE                     (IVI_SPECIFIC_ERROR_BASE + 5L)
#define NIHSDIO_ERROR_ONLY_ONE_IDENTIFIER_ALLOWED                  (IVI_SPECIFIC_ERROR_BASE + 6L)
#define NIHSDIO_ERROR_INVALID_LINE_STATE                           (IVI_SPECIFIC_ERROR_BASE + 7L)
#define NIHSDIO_ERROR_MAX_TIME_EXCEEDED                            (IVI_SPECIFIC_ERROR_BASE + 8L)
#define NIHSDIO_ERROR_INCORRECT_DIGITAL_PATTERN                    (IVI_SPECIFIC_ERROR_BASE + 9L)
#define NIHSDIO_ERROR_WAVEFORM_NOT_IN_MEMORY                       (IVI_SPECIFIC_ERROR_BASE + 12L)
#define NIHSDIO_ERROR_WAVEFORM_EMPTY                               (IVI_SPECIFIC_ERROR_BASE + 62L)
#define NIHSDIO_ERROR_SCRIPT_NOT_IN_MEMORY                         (IVI_SPECIFIC_ERROR_BASE + 3L)
#define NIHSDIO_ERROR_DIGITAL_WAVEFORM_EXPECTED                    (IVI_SPECIFIC_ERROR_BASE + 13L)
#define NIHSDIO_ERROR_SCALED_DATA_WIDTH_FAILED                     (IVI_SPECIFIC_ERROR_BASE + 14L)
#define NIHSDIO_ERROR_INVALID_REPEAT_COUNT                         (IVI_SPECIFIC_ERROR_BASE + 16L)
#define NIHSDIO_ERROR_SET_WHEN_SESSION_RUNNING                     (IVI_SPECIFIC_ERROR_BASE + 39L)
#define NIHSDIO_ERROR_GET_WHEN_SESSION_NOT_RUNNING                 (IVI_SPECIFIC_ERROR_BASE + 45L)
#define NIHSDIO_ERROR_SESSION_NOT_IN_RUNNING_STATE                 (IVI_SPECIFIC_ERROR_BASE + 17L)
#define NIHSDIO_ERROR_NO_WFMS_IN_MEM                               (IVI_SPECIFIC_ERROR_BASE + 18L)
#define NIHSDIO_ERROR_ACTIVE_WFM_NOT_SPECIFIED                     (IVI_SPECIFIC_ERROR_BASE + 19L)
#define NIHSDIO_ERROR_RESOURCE_ALREADY_RESERVED                    (IVI_SPECIFIC_ERROR_BASE + 20L)
#define NIHSDIO_ERROR_ROUTING_HARDWARE_BUSY                        (IVI_SPECIFIC_ERROR_BASE + 21L)
#define NIHSDIO_ERROR_SAMPS_PER_REC_TOO_BIG                        (IVI_SPECIFIC_ERROR_BASE + 22L)
#define NIHSDIO_ERROR_NO_SCRIPTS_IN_MEMORY                         (IVI_SPECIFIC_ERROR_BASE + 23L)
#define NIHSDIO_ERROR_ACTIVE_SCRIPT_NOT_SPECIFIED                  (IVI_SPECIFIC_ERROR_BASE + 24L)
#define NIHSDIO_ERROR_INSTRUMENT_NOT_SUPPORTED                     (IVI_SPECIFIC_ERROR_BASE + 25L)
#define NIHSDIO_ERROR_DUPLICATE_CHANNEL_NAME                       (IVI_SPECIFIC_ERROR_BASE + 26L)
#define NIHSDIO_ERROR_ACQUISITION_SESSION_ALREADY_OPEN             (IVI_SPECIFIC_ERROR_BASE + 27L)
#define NIHSDIO_ERROR_GENERATION_SESSION_ALREADY_OPEN              (IVI_SPECIFIC_ERROR_BASE + 28L)
#define NIHSDIO_ERROR_CHANNEL_NOT_PREV_TRISTATED                   (IVI_SPECIFIC_ERROR_BASE + 29L)
#define NIHSDIO_ERROR_CHANNEL_RESERVED_FOR_GENERATION              (IVI_SPECIFIC_ERROR_BASE + 31L)
#define NIHSDIO_ERROR_SAMPLES_NOT_YET_AVAILABLE                    (IVI_SPECIFIC_ERROR_BASE + 32L)
#define NIHSDIO_ERROR_WAVEFORM_PREVIOUSLY_ALLOCATED                (IVI_SPECIFIC_ERROR_BASE + 35L)
#define NIHSDIO_ERROR_ROUTE_RESOURCES_IN_USE_IN_SESSION            (IVI_SPECIFIC_ERROR_BASE + 36L)
#define NIHSDIO_ERROR_INVALID_GENERATION_CLOCK_SOURCE              (IVI_SPECIFIC_ERROR_BASE + 41L)
#define NIHSDIO_ERROR_RUNTIME_ABORTED                              (IVI_SPECIFIC_ERROR_BASE + 47L)
#define NIHSDIO_ERROR_DEVICE_ABSENT_OR_UNAVAILABLE                 (IVI_SPECIFIC_ERROR_BASE + 50L)
#define NIHSDIO_ERROR_INVALID_SIGNAL_IDENTIFIER                    (IVI_SPECIFIC_ERROR_BASE + 52L)
#define NIHSDIO_ERROR_UNSUPPORTED_SOFTWARE_TRIGGER_TYPE            (IVI_SPECIFIC_ERROR_BASE + 53L)
#define NIHSDIO_ERROR_UNSUPPORTED_EXPORT_SIGNAL_TYPE               (IVI_SPECIFIC_ERROR_BASE + 54L)
#define NIHSDIO_ERROR_UNKNOWN_CHANNEL_NAME                         (IVI_SPECIFIC_ERROR_BASE + 15L)
#define NIHSDIO_ERROR_ATTRIBUTE_NOT_SUPPORTED                      (IVI_SPECIFIC_ERROR_BASE + 30L)
#define NIHSDIO_ERROR_INTERNAL_SOFTWARE_ERROR                      (IVI_SPECIFIC_ERROR_BASE + 1L)
#define NIHSDIO_ERROR_REFERENCE_PAUSE_TRIGGER_CONFLICT             (IVI_SPECIFIC_ERROR_BASE + 37L)
#define NIHSDIO_ERROR_CALIBRATION_SESSION_ALREADY_OPEN             (IVI_SPECIFIC_ERROR_BASE + 58L)
#define NIHSDIO_ERROR_FILE_SIGNAL_AND_CHANNEL_MISMATCH             (IVI_SPECIFIC_ERROR_BASE + 59L)
#define NIHSDIO_ERROR_VOLTAGE_CALIBRATION_FAILED                   (IVI_SPECIFIC_ERROR_BASE + 60L)
#define NIHSDIO_ERROR_CALIBRATION_FUNCTION_NOT_SUPPORTED           (IVI_SPECIFIC_ERROR_BASE + 61L)
#define NIHSDIO_ERROR_DELAY_VALUE_INVALID_FOR_FREQUENCY            (IVI_SPECIFIC_ERROR_BASE + 63L)
#define NIHSDIO_ERROR_READ_WRITE_FUNCTION_NOT_SUPPORTED            (IVI_SPECIFIC_ERROR_BASE + 64L)
#define NIHSDIO_ERROR_INVALID_DATA_WIDTH                           (IVI_SPECIFIC_ERROR_BASE + 65L)
#define NIHSDIO_ERROR_INVALID_CHANNEL_FOR_DATA_WIDTH               (IVI_SPECIFIC_ERROR_BASE + 66L)
#define NIHSDIO_ERROR_INVALID_CHANNEL_FOR_DATA_RATE_MULTIPLIER     (IVI_SPECIFIC_ERROR_BASE + 67L)
#define NIHSDIO_ERROR_SESSION_NOT_IN_COMMITED_STATE                (IVI_SPECIFIC_ERROR_BASE + 68L)
#define NIHSDIO_ERROR_WAVEFORM_DATA_WIDTH_MISMATCH                 (IVI_SPECIFIC_ERROR_BASE + 70L)
#define NIHSDIO_ERROR_DIGITAL_STATE_NOT_SUPPORTED                  (IVI_SPECIFIC_ERROR_BASE + 71L)
#define NIHSDIO_ERROR_TRISTATE_MEMORY_FULL                         (IVI_SPECIFIC_ERROR_BASE + 72L)
#define NIHSDIO_ERROR_FAILED_TO_START_HARDWARE_COMPARE             (IVI_SPECIFIC_ERROR_BASE + 73L)
#define NIHSDIO_ERROR_SAMPLE_ERRORS_NOT_AVAILABLE                  (IVI_SPECIFIC_ERROR_BASE + 74L)
#define NIHSDIO_ERROR_EXPECTED_DATA_FIFO_OVERFLOW                  (IVI_SPECIFIC_ERROR_BASE + 77L)
#define NIHSDIO_ERROR_EXPECTED_DATA_GENERATION_ERROR               (IVI_SPECIFIC_ERROR_BASE + 78L)
#define NIHSDIO_ERROR_WAVEFORM_HARDWARE_COMPARE_MISMATCH           (IVI_SPECIFIC_ERROR_BASE + 79L)
#define NIHSDIO_ERROR_INVALID_FUNCTION_FOR_HARDWARE_COMPARE        (IVI_SPECIFIC_ERROR_BASE + 80L)
#define NIHSDIO_ERROR_DATATYPE_OF_WFM_NOT_SUPPORTED                (IVI_SPECIFIC_ERROR_BASE + 81L)
#define NIHSDIO_ERROR_EXPECTED_DATA_READY_TIMEOUT                  (IVI_SPECIFIC_ERROR_BASE + 82L)
#define NIHSDIO_ERROR_SAMPLE_ERROR_BUFFER_OVERFLOW                 (IVI_SPECIFIC_ERROR_BASE + 83L)
#define NIHSDIO_ERROR_INVALID_TRIGGER_TYPE_FOR_HARDWARE_COMPARE    (IVI_SPECIFIC_ERROR_BASE + 84L)
#define NIHSDIO_ERROR_FILE_CONTAINS_MULTIPLE_WAVEFORMS             (IVI_SPECIFIC_ERROR_BASE + 85L)
#define NIHSDIO_ERROR_STREAMING_WAVEFORM_NOT_SPECIFIED             (IVI_SPECIFIC_ERROR_BASE + 86L)
#define NIHSDIO_ERROR_STREAMING_DATA_OVERFLOW                      (IVI_SPECIFIC_ERROR_BASE + 87L)
#define NIHSDIO_ERROR_STREAMING_DATA_UNDERFLOW                     (IVI_SPECIFIC_ERROR_BASE + 88L)
#define NIHSDIO_ERROR_STREAMING_WAVEFORM_TOO_SMALL                 (IVI_SPECIFIC_ERROR_BASE + 89L)
#define NIHSDIO_ERROR_INVALID_DIRECT_DMA_WINDOW_SIZE               (IVI_SPECIFIC_ERROR_BASE + 90L)
#define NIHSDIO_ERROR_INVALID_DIRECT_DMA_WINDOW_ADDRESS            (IVI_SPECIFIC_ERROR_BASE + 91L)
#define NIHSDIO_ERROR_CANNOT_SET_WAVEFORM_WRITE_POSITION           (IVI_SPECIFIC_ERROR_BASE + 92L)
#define NIHSDIO_ERROR_INVALID_CONTINUOUS_CONFIGURATION             (IVI_SPECIFIC_ERROR_BASE + 93L)
#define NIHSDIO_ERROR_INVALID_COMBINATION_DDR_CLOCK_VOLTAGE        (IVI_SPECIFIC_ERROR_BASE + 94L)
#define NIHSDIO_ERROR_OSP_FIFO_OVERFLOW                            (IVI_SPECIFIC_ERROR_BASE + 95L)
#define NIHSDIO_ERROR_OSP_FIFO_UNDERFLOW                           (IVI_SPECIFIC_ERROR_BASE + 96L)
#define NIHSDIO_ERROR_FUNCTION_NOT_SUPPORTED_WIN64U                (IVI_SPECIFIC_ERROR_BASE + 97L)
#define NIHSDIO_ERROR_MB_DATA_DELAY_VALUE_INCONSISTENT_ACROSS_BANK (IVI_SPECIFIC_ERROR_BASE + 98L)
#define NIHSDIO_ERROR_WAVEFORM_TYPE_CONFLICT                       (IVI_SPECIFIC_ERROR_BASE + 99L)
#define NIHSDIO_ERROR_INVALID_CHANNEL_FOR_CCT_AND_HWC              (IVI_SPECIFIC_ERROR_BASE + 100L)
#define NIHSDIO_ERROR_CANNOT_STREAM_WITH_HWC_ENABLED               (IVI_SPECIFIC_ERROR_BASE + 101L)
#define NIHSDIO_ERROR_FUNCTION_NOT_SUPPORTED_ON_NON_HWC_CCT_DEVICE (IVI_SPECIFIC_ERROR_BASE + 102L)
#define NIHSDIO_ERROR_INVALID_DATA_WIDTH_FOR_SUPPORTED_DATA_STATES (IVI_SPECIFIC_ERROR_BASE + 103L)



/* Warning codes */
#define NIHSDIO_WARN_NSUP_ID_QUERY                     (IVI_SPECIFIC_WARN_BASE + 1L)
#define NIHSDIO_WARN_PLL_BECAME_UNLOCKED               (IVI_SPECIFIC_WARN_BASE + 2L)

/****************************************************************************************************
 *----------------------------------------- End Include File ---------------------------------------*
 ****************************************************************************************************/
#include "niHSDIOObsolete.h"

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NIHSDIO_HEADER */
