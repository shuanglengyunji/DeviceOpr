/****************************************************************************
 *                                niTuner                                   *
 *--------------------------------------------------------------------------*
 *      Copyright (c) National Instruments 2001.  All Rights Reserved.      *
 *--------------------------------------------------------------------------*
 *                                                                          *
 * Title:    niTuner.h                                                      *
 * Purpose:  NI-TUNER                                                       *
 *           instrument driver declarations.                                *
 *                                                                          *
 ****************************************************************************/

#ifndef __NITUNER_HEADER
#define __NITUNER_HEADER

#include <string.h>

#ifdef _CVI_
   #include <cvidef.h>
   #pragma EnableLibraryRuntimeChecking
#else
   #define CVIFUNC __stdcall
#endif

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

/****************************************************************************
 *----------------- Instrument Driver Revision Information -----------------*
 ****************************************************************************/
#define NITUNER_MAJOR_VERSION         1     /* Instrument driver major version */
#define NITUNER_MINOR_VERSION         5     /* Instrument driver minor version */

/****************************************************************************
 *---------------------- Useful Macros and Defines -------------------------*
 ****************************************************************************/

/* Maximum length of a NI-TUNER function name, including the NULL terminator */
#define NITUNER_MAX_FUNCTION_NAME_SIZE      55

/* Maximum size of an error message returned from niTuner_errorHandler or 
   GetDAQErrorString, including the NULL terminator */
#define NITUNER_MAX_ERROR_DESCRIPTION       1024

/* This macro handles all errors and warnings returned from NI-TUNER.
   It requires one variable be declared:                                   
      int errorTuner
   and a line marked "ErrorTuner:" that marks the beginning of cleanup code.     
   If a function returns an error code, "errorTuner" is set to the error code,
   and execution skips to the "ErrorTuner:" line.  Otherwise, "errorTuner"
   stores the location of warnings that occur, and execution proceeds normally. */
#define handleErrTuner(fCall) {                                     \
        int code = (fCall);                                         \
        if (code != 0) errorTuner = code;                                          \
        if (code < 0) goto ErrorTuner;                              \
}

/* General Constants */
#define NITUNER_MAX_FREQUENCY                            2700000000
#define NITUNER_CENTER_IF_FREQUENCY                      15000000
#define NITUNER_DEFAULT_SPAN                             20000000

/****************************************************************************
 *------------------ Attribute and Parameter Value Defines -----------------*
 ****************************************************************************/

/*- Clock Reference Source Options -*/
#define NITUNER_REF_DRIVE_PXI_BACKPLANE_CLOCK            0
#define NITUNER_REF_INTERNAL                             1
#define NITUNER_REF_LOCK_TO_PXI_BACKPLANE_CLOCK          2
#define NITUNER_REF_EXTERNAL                             3
#define NITUNER_REF_DRIVE_PXI_BACKPLANE_CLOCK_EXTERNAL   4

/*- Signal Path Options -*/
#define NITUNER_SIGNAL_SOFTWARE                          0
#define NITUNER_SIGNAL_NO_DESTINATION                    0
#define NITUNER_SIGNAL_RTSI0                             1
#define NITUNER_SIGNAL_RTSI1                             2
#define NITUNER_SIGNAL_RTSI2                             3
#define NITUNER_SIGNAL_RTSI3                             4
#define NITUNER_SIGNAL_RTSI4                             5
#define NITUNER_SIGNAL_RTSI5                             6
#define NITUNER_SIGNAL_RTSI6                             7

/*- Signal Type Options -*/
#define NITUNER_SIGNAL_PULSE                             0
#define NITUNER_SIGNAL_LEVEL                             1

/*- Signal Polarity Options -*/
#define NITUNER_SIGNAL_ACTIVE_LOW                        0
#define NITUNER_SIGNAL_ACTIVE_HIGH                       1

/*- Attenuation Option -*/
#define NITUNER_ATTN_AUTOMODE                            1001

/*- Boolean Defines -*/
#define NITUNER_VAL_FALSE                                0
#define NITUNER_VAL_TRUE                                 1

/****************************************************************************
 *---------------- Instrument Driver Function Declarations -----------------*
 ****************************************************************************/

/*--- Basic Functions ------------------------------------------------------*/
int CVIFUNC niTuner_init (int device, int *taskID);

int CVIFUNC niTuner_initWithResetOption (int device, int *taskID, unsigned int reset);

int CVIFUNC niTuner_setFreq (int taskID, double desiredRFFrequency,
                             double span, double *actualIFFrequency,
                             double *actualRFTunedFrequency, double *freqShift);

int CVIFUNC niTuner_close (int taskID);

/*--- General Configuration ------------------------------------------------*/
int CVIFUNC niTuner_setAttenuation (int taskID, int refLevel, int mixerLevel,
                                    double *attenuation, double *scaleFactor);

int CVIFUNC niTuner_getAttenuation (int taskID, unsigned long listSize, 
                                    double * attenuation, double * scaleFactor);

/*--- Synchronization ------------------------------------------------------*/
int CVIFUNC niTuner_configAdvanceTrigger (int taskID, unsigned int signalSource,
                                          unsigned int signalType, unsigned int signalPolarity);


int CVIFUNC niTuner_configReadySignal (int taskID, unsigned int signalDestination,
                                       unsigned int signalType, unsigned int signalPolarity,
                                       double pulseLength);

int CVIFUNC niTuner_configReferenceClock (int taskID,
                                          unsigned int referenceConfiguration);

int CVIFUNC niTuner_initiateScan (int taskID);

int CVIFUNC niTuner_sendSoftwareTrigger (int taskID);

/*--- Scan List Configuration ----------------------------------------------*/
int CVIFUNC niTuner_setFreqScanList (int taskID, unsigned long numFreq,
                                     double desiredRFFrequencies[],
                                     double spans[],
                                     double actualIFFrequencies[],
                                     double actualRFTunedFrequencies[],
                                     double freqShifts[]);

int CVIFUNC niTuner_getCal (int taskID, 
                            unsigned long listSize, 
                            double RFArrays[],
                            double IFArrays[],
                            double attenuationArray[]);

/*--- Utility --------------------------------------------------------------*/
int CVIFUNC niTuner_getTemperature (int taskID, double *temperature,
                                    double *correctionFactor);

int CVIFUNC niTuner_getTemperatureWithRefreshInterval (int taskID, double *temperature,
                                    double *correctionFactor, double refreshInterval);

int CVIFUNC niTuner_ready (int taskID, double timeout, unsigned long *ready);

int CVIFUNC niTuner_errorHandler (int taskID, int errorCode, char errorSource[],
                                  char errorDescription[]);

/****************************************************************************
 *------------------- Error, Warning, and Completion Codes -----------------*
 ****************************************************************************/
#define NITUNER_ERROR_SUCCESS                    0
 
#define NITUNER_ERROR_OFFSET                     -27000
#define NITUNER_MIN_ERROR                        (  -1 + NITUNER_ERROR_OFFSET )
#define NITUNER_MAX_ERROR                        ( -31 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALIDSERIALCHAINSIZE     (  -1 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_ALLOCATEMEMORY             (  -2 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_FREQCOUNTERTIMEOUT         (  -3 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_DOWNCONVERTERBUSY          (  -4 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_RELAYBUSY                  (  -5 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INFINITELOOP               (  -6 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_DEVICEPOINTER              (  -7 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_EEPROMWRITEFAIL            (  -8 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALIDARRAYSIZE           ( -10 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_BADSPAN                    ( -11 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_RANGEERROR                 ( -12 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_RESETNOTCALLED             ( -13 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INITNOTCALLED              ( -14 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALIDRTSIVALUE           ( -15 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_UNKNOWNPLL                 ( -16 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_CLOCKCONFLICT              ( -17 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_NULLPOINTER                ( -18 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_CPLDREJECT                 ( -19 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_FPGADOWNLOADFAILED         ( -20 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALIDATTRIBUTE           ( -21 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALID_SIGNAL_PATH        ( -23 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALID_SIGNAL_TYPE        ( -24 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALID_SIGNAL_POLARITY    ( -25 + NITUNER_ERROR_OFFSET )
#define NITUNER_ERROR_INVALID_PULSE_LENGTH       ( -26 + NITUNER_ERROR_OFFSET )

#define NITUNER_WARN_OFFSET                      27000
#define NITUNER_MIN_WARN                         (   1 + NITUNER_WARN_OFFSET )
#define NITUNER_MAX_WARN                         (  31 + NITUNER_WARN_OFFSET )
#define NITUNER_WARN_CALIBRATIONLOADFAIL         (   9 + NITUNER_WARN_OFFSET )
#define NITUNER_WARN_ATTENUATIONCOERCED          (  22 + NITUNER_WARN_OFFSET )
#define NITUNER_WARN_BAD_MIXER_RANGE             (  27 + NITUNER_WARN_OFFSET )
#define NITUNER_WARN_BAD_REFERENCE_RANGE         (  28 + NITUNER_WARN_OFFSET )
#define NITUNER_WARN_MAX_SPEC                    (  29 + NITUNER_WARN_OFFSET )
#define NITUNER_WARN_MIXER_ABOVE_ZERO            (  30 + NITUNER_WARN_OFFSET )
#define NITUNER_WARN_BAD_IF_RANGE                (  31 + NITUNER_WARN_OFFSET )



/****************************************************************************
 *---------------------------- End Include File ----------------------------*
 ****************************************************************************/
#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif
#endif /* __NITUNER_HEADER */
