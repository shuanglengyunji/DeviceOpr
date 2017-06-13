#ifndef ___niScopeCal_h___
#define ___niScopeCal_h___

#ifndef ___niScope_h___
#include "niScope.h"
#endif

/* Pragma used in CVI to indicate that functions in this file have 
 * user protection associated with them */
#ifdef _CVI_
 #pragma EnableLibraryRuntimeChecking
#endif

#define NISCOPE_VAL_CAL_ACTION_STORE       0 // Possible Action for CloseSession
#define NISCOPE_VAL_CAL_ACTION_ABORT       1 // Possible Action for CloseSession
#define NISCOPE_VAL_CAL_ACTION_RESET       101 // Possible Action for CloseSession (internal use only)

#define NISCOPE_VAL_CAL_ABORT_ON_ERR       0 // option for error handling
#define NISCOPE_VAL_CAL_ABORT_ON_MAJOR_ERR 1 // option for error handling
#define NISCOPE_VAL_CAL_SKIP_BAD_SECTIONS  2 // option for error handling
#define NISCOPE_VAL_CAL_RESET_BAD_SECTIONS 3 // option for error handling

#define NISCOPE_VAL_CAL_SELF               1 // option for fetch date, count, temp
#define NISCOPE_VAL_CAL_EXTERNAL           0 // option for fetch date, count, temp
#define NISCOPE_VAL_CAL_MANUFACTURE        2 // option for fetch date

// Route internal reference options
#define NISCOPE_VAL_CAL_UNROUTE_SIGNAL     (ViUInt32)0xfffffff
#define NISCOPE_VAL_CAL_POSITIVE           (ViUInt32)0xffff
#define NISCOPE_VAL_CAL_NEGATIVE           0

// Calibration source for niScope_CalSetAccessorySource
#define NISCOPE_VAL_CAL_SOURCE_GROUND      0
#define NISCOPE_VAL_CAL_SOURCE_POSITIVEFS  1
#define NISCOPE_VAL_CAL_SOURCE_NEGATIVEFS  2

// Which reference parameter for routing, storing and fetching int. ref.
#define NISCOPE_VAL_CAL_10V_CH0            0

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

///////////////////////////////////////////////////////
//
//  OPEN / CLOSE / Change Password
//
///////////////////////////////////////////////////////

// Gives calibration session handle
ViStatus _VI_FUNC niScope_CalStart
(
   ViRsrc    resourceName,     // e.g. "DAQ:1"
   ViConstString   password,   // pointer to 4 bytes for password, 0 or "" by default
   ViSession *newSessionHandle // returns this session handle
);

// Either store constants in eeprom or abort.
ViStatus _VI_FUNC niScope_CalEnd
(
   ViSession sessionHandle,  // session handle from CalStart
   ViInt32   action          // see defined "action" constants above
);

// If the old password is correct, the new password is stored in eeprom
ViStatus _VI_FUNC niScope_CalChangePassword
(
   ViSession      sessionHandle, // session handle from CalStart or niScope_init
   ViConstString  oldPassword,   // previous password is verfied (pointer to 4 bytes)
   ViConstString  newPassword    // new password is written to eeprom (pointer to 4 bytes)
);

///////////////////////////////////////////////////////
//
//  FETCH
//
///////////////////////////////////////////////////////

ViStatus _VI_FUNC niScope_CalFetchCount
(
   ViSession    sessionHandle,    // session handle from CalStart or niScope_init
   ViInt32      whichOne,         // internal or external count: see defines
   ViInt32*     calibrationCount  // number of calibrations peformed
);

ViStatus _VI_FUNC niScope_CalFetchDate
(  
   ViSession    sessionHandle,   // session handle from CalStart or niScope_init
   ViInt32      whichOne,        // internal or external cal date, or manufacture date
   ViInt32*     year,            // year of last calibration from eeprom
   ViInt32*     month,           // month of last calibration from eeprom
   ViInt32*     day              // day of last calibration from eeprom
);


// Not supported yet, but will be for temperature sensing devices
ViStatus _VI_FUNC niScope_CalFetchTemperature
(
   ViSession    sessionHandle,  // session handle from CalStart or niScope_init
   ViInt32      whichOne,       // internal or external cal temperature
   ViReal64*    temperature     // temperature in degrees C
);

ViStatus _VI_FUNC niScope_CalFetchMiscInfo
(
   ViSession    sessionHandle, // session handle from CalStart or niScope_init
   ViChar*      miscInfo       // pointer to 5 bytes; returned from eeprom
);

// Return the last stored internal reference value.
// This value is not used during device operation.
ViStatus _VI_FUNC niScope_CalFetchInternalReference
(
   ViSession      sessionHandle,     // session handle from CalStart or niScope_init
   ViInt32        whichReference,    // see defines
   ViReal64*      internalRefValue   // last stored internal reference measurement
);

///////////////////////////////////////////////////////
//
//  Store
//
///////////////////////////////////////////////////////
ViStatus _VI_FUNC niScope_CalStoreMiscInfo
( 
   ViSession     sessionHandle,        // session handle from CalStart  
   ViConstString miscInfo   // pointer to 4 characters to store in eeprom (operator id?)
);

// For verification, store the internal reference. This value is not
// used during device operation.
ViStatus _VI_FUNC niScope_CalStoreInternalReference
(
   ViSession      sessionHandle,     // session handle from CalStart
   ViInt32        whichReference,    // see defines
   ViReal64       internalRefValue   // last stored internal reference measurement
);


///////////////////////////////////////////////////////
//
//  Adjustment 
//
///////////////////////////////////////////////////////

ViStatus _VI_FUNC niScope_CalAdjustRange
(  
   ViSession      sessionHandle,    // session handle from CalStart
   ViConstString  channelName,      // e.g. "0" or "1"
   ViReal64       range,            // see niscope calibration document
   ViReal64       stimulus          // peak voltage of applied signal
);

ViStatus _VI_FUNC niScope_CalAdjustVCXO
(  
   ViSession      sessionHandle,    // session handle from CalStart
   ViReal64       stimulusFreq      // frequency of applied signal
);

ViStatus _VI_FUNC niScope_CalAdjustDCM
(  
   ViSession      sessionHandle,    // session handle from CalStart
   ViConstString  channelName,      // e.g. "0" or "1"
   ViReal64       stimulusFreq      // frequency of applied signal
);

ViStatus _VI_FUNC niScope_CalAdjustOffset 
(  
   ViSession      sessionHandle,    // session handle from CalStart
   ViConstString  channelName,      // e.g. "0" or "1"
   ViReal64       range             // see niscope calibration document
);

ViStatus _VI_FUNC niScope_CalAdjustOffsetRange 
(  
   ViSession      sessionHandle,    // session handle from CalStart
   ViConstString  channelName,      // e.g. "0" or "1"
   ViReal64       range,            // see niscope calibration document
   ViReal64       stimulus          // peak voltage of applied signal
);

ViStatus _VI_FUNC niScope_CalAdjustCompensationAttenuator
(  
   ViSession      sessionHandle,    // session handle from CalStart
   ViConstString  channelName,      // e.g. "0" or "1"
   ViReal64       range             // see niscope calibration document
);

ViStatus _VI_FUNC niScope_CalAdjustFrequencyResponse
(  
   ViSession      sessionHandle,    // session handle from CalStart
   ViConstString  channelName,      // e.g. "0" or "1"
   ViReal64       range,            // see niscope calibration document
   ViReal64       stimulusFreq,     // frequency of applied signal
   ViReal64       stimulusAmp       // peak voltage of applied signal
);

// For the 5911 external calibration with a single DC external voltage source
ViStatus _VI_FUNC niScope_CalAdjustInternalReference
(
   ViSession      sessionHandle,   // session handle from CalStart
   ViInt32        option,          // use VI_NULL
   ViReal64       stimulus         // voltage of applied signal
);


// For 5112 verification, this routes the internal reference out the
// front BNC connector for measurement.
ViStatus _VI_FUNC niScope_CalRouteInternalReference
(
   ViSession      sessionHandle, // session handle from CalStart
   ViInt32        option ,       // see defines
   ViInt32        whichReference // see constants
);

// For the 5900 external calibration
ViStatus _VI_FUNC niScope_CalAdjustAccessoryGainAndOffset
(
   ViSession      sessionHandle, // session handle from CalStart
   ViConstString  channelName,   // e.g. "0" or "1"
   ViReal64       posFS,
   ViReal64       gnd,
   ViReal64       negFS
);

ViStatus _VI_FUNC niScope_CalSetAccessorySource
(
   ViSession      sessionHandle,
   ViConstString  channelName,
   ViInt32        calSource
);

///////////////////////////////////////////////////////
//
//  Verification
//
///////////////////////////////////////////////////////
ViStatus _VI_FUNC niScope_CalMeasureRISDistribution
(
   ViSession       sessionHandle,     // session handle from CalStart or niScope_init
   ViConstString   channelName,       // e.g. "0" or "1"
   ViInt32         maxTime,           // max time in ms for each acquisition
   ViReal64*       minBinPercent,     // percent (0-1) of trigers in the least full bin
   ViInt32         distributionSize,  // number of bins for distribution
   ViInt32*        distribution       // array for distribution, NULL for "don't return it"
);

#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif
