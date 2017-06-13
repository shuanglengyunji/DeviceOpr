// ***************************************************************************************
//    NI-TClk 
// 
//    National Instruments library for TClk synchronization
//                             
//    Copyright (c) National Instruments 2003.  All Rights Reserved.         
// ****************************************************************************************

#ifndef ___niTClk_h___
#define ___niTClk_h___


#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#include "visatype.h"

// ****************************************************************************************
// ---------------------------- Attribute Definitions -------------------------------------
// ****************************************************************************************

#define NITCLK_ATTR_SYNC_PULSE_SOURCE                    1
#define NITCLK_ATTR_EXPORTED_SYNC_PULSE_OUTPUT_TERMINAL  2
#define NITCLK_ATTR_START_TRIGGER_MASTER_SESSION         3
#define NITCLK_ATTR_REF_TRIGGER_MASTER_SESSION           4
#define NITCLK_ATTR_SCRIPT_TRIGGER_MASTER_SESSION        5
#define NITCLK_ATTR_PAUSE_TRIGGER_MASTER_SESSION         6
#define NITCLK_ATTR_TCLK_ACTUAL_PERIOD                   8
#define NITCLK_ATTR_EXPORTED_TCLK_OUTPUT_TERMINAL        9
#define NITCLK_ATTR_SYNC_PULSE_CLOCK_SOURCE             10
#define NITCLK_ATTR_SAMPLE_CLOCK_DELAY                  11
#define NITCLK_ATTR_SYNC_PULSE_SENDER_SYNC_PULSE_SOURCE 13




// ****************************************************************************************
// -------------------------- Library Function Declarations -------------------------------
// ****************************************************************************************

ViStatus _VI_FUNC niTClk_ConfigureForHomogeneousTriggers(ViUInt32 sessionCount,
                                                                   ViSession sessions[]);

ViStatus _VI_FUNC niTClk_Synchronize(ViUInt32 sessionCount,
                                               ViSession sessions[],
                                               ViReal64 minTime);

ViStatus _VI_FUNC niTClk_Initiate(ViUInt32 sessionCount,
                                            ViSession sessions[]);

ViStatus _VI_FUNC niTClk_WaitUntilDone(ViUInt32 sessionCount,
                                                 ViSession sessions[],
                                                 ViReal64 timeout);

ViStatus _VI_FUNC niTClk_GetExtendedErrorInfo(ViChar errorString[], 
                                                        ViUInt32 errorStringSize);


// --- Advanced Functions

ViStatus _VI_FUNC niTClk_IsDone(ViUInt32 sessionCount,
                                          ViSession sessions[],
                                          ViBoolean *done);
										  
ViStatus _VI_FUNC niTClk_SetupForSyncPulseSenderSynchronize(ViUInt32 sessionCount,
                                                            ViSession sessions[],
                                                            ViReal64 minTime);
                                                 
ViStatus _VI_FUNC niTClk_FinishSyncPulseSenderSynchronize(ViUInt32 sessionCount,
                                                          ViSession sessions[],
                                                          ViReal64 minTime);

ViStatus _VI_FUNC niTClk_SynchronizeToSyncPulseSender(ViUInt32 sessionCount,
                                                      ViSession sessions[],
                                                      ViReal64 minTime);										  


// ------ Set Attribute

ViStatus _VI_FUNC niTClk_SetAttributeViString (ViSession session, 
                                                         ViConstString channelName, 
                                                         ViAttr attributeId, 
                                                         ViConstString value);

ViStatus _VI_FUNC niTClk_SetAttributeViSession(ViSession session, 
                                                         ViConstString channelName, 
                                                         ViAttr attributeId, 
                                                         ViSession value);

ViStatus _VI_FUNC niTClk_SetAttributeViReal64(ViSession session, 
                                                        ViConstString channelName, 
                                                        ViAttr attributeId, 
                                                        ViReal64 value);


// ------ Get Attribute

ViStatus _VI_FUNC niTClk_GetAttributeViString (ViSession session, 
                                                         ViConstString channelName, 
                                                         ViAttr attributeId, 
                                                         ViInt32 bufSize, 
                                                         ViChar value[]);

ViStatus _VI_FUNC niTClk_GetAttributeViSession(ViSession session, 
                                                         ViConstString channelName, 
                                                         ViAttr attributeId, 
                                                         ViSession *value);

ViStatus _VI_FUNC niTClk_GetAttributeViReal64(ViSession session, 
                                                        ViConstString channelName, 
                                                        ViAttr attributeId, 
                                                        ViReal64 *value);



// ****************************************************************************************
// ------------------------ Error And Completion Codes ------------------------------------
// ****************************************************************************************

#define NITCLK_SUCCESS                                                           0


#define NITCLK_ERROR_START_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                     -250001
#define NITCLK_ERROR_REF_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                       -250002
#define NITCLK_ERROR_SCRIPT_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                    -250003
#define NITCLK_ERROR_PAUSE_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK                     -250004
#define NITCLK_ERROR_START_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW         -250005 
#define NITCLK_ERROR_REF_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW           -250006
#define NITCLK_ERROR_SCRIPT_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW        -250007   
#define NITCLK_ERROR_PAUSE_TRIG_MASTER_DOES_NOT_SUPPORT_TCLK_FOR_LABVIEW         -250008 
#define NITCLK_ERROR_CHAN_NAME_NOT_EMPTY                                         -250009
#define NITCLK_ERROR_REF_CLK_RATE_ZERO                                           -250010
#define NITCLK_ERROR_REF_CLK_RATE_NEGATIVE                                       -250011
#define NITCLK_ERROR_UNEQUAL_REF_CLK_RATES                                       -250012
#define NITCLK_ERROR_MIN_TCLK_PERIOD_NOT_SUPPORTED                               -250013
#define NITCLK_ERROR_REF_CLK_SRC_NONE                                            -250014
#define NITCLK_ERROR_EXT_SAMP_CLK_RATE_NOT_ALSO_INT                              -250015
#define NITCLK_ERROR_CANNOT_FIND_COMMON_TCLK_PERIOD                              -250016
#define NITCLK_ERROR_INCONSISTENT_SYNC_PULSE_CLK_SRC                             -250017
#define NITCLK_ERROR_INCONSISTENT_REF_CLK_SRC                                    -250018
#define NITCLK_ERROR_NO_START_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS               -250019
#define NITCLK_ERROR_NO_REF_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS                 -250020
#define NITCLK_ERROR_NO_PAUSE_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS               -250021
#define NITCLK_ERROR_NO_SCRIPT_TRIGS_CONFIGURED_ONE_OR_MORE_MASTERS              -250022
#define NITCLK_ERROR_MULTIPLE_START_TRIG_MASTERS                                 -250023
#define NITCLK_ERROR_TIMEOUT_NOT_SUPPORTED                                       -250024
#define NITCLK_ERROR_OP_NOT_DONE_WITHIN_TIMEOUT                                  -250025
#define NITCLK_ERROR_MULTIPLE_SESSIONS_EXPORT_SYNC_PULSE                         -250026
#define NITCLK_ERROR_SESSION_NOT_SUPPORTED                                       -250027
#define NITCLK_ERROR_ZERO_SESSIONS                                               -250028
#define NITCLK_ERROR_SESSIONS_ARRAY_NULL                                         -250029
#define NITCLK_ERROR_SESSION_SPECIFIED_TWICE                                     -250030
#define NITCLK_ERROR_TWO_SESSIONS_FOR_ONE_DEVICE                                 -250031
#define NITCLK_ERROR_SESSION_NOT_VALID                                           -250032
#define NITCLK_ERROR_COMMIT_FAILED                                               -250033
#define NITCLK_ERROR_INITIATE_FAILED                                             -250034
#define NITCLK_ERROR_IS_DONE_FAILED                                              -250035
#define NITCLK_ERROR_NULL_ERROR_STRING                                           -250036 
#define NITCLK_ERROR_ZERO_START_TRIG_MASTERS                                     -250037 
#define NITCLK_ERROR_ATTRIBUTE_ID_NOT_SUPPORTED                                  -250038 
#define NITCLK_ERROR_GET_ATTRIBUTE_FUNCTION_NOT_SUPPORTED_DUE_TO_DATA_TYPE       -250039 
#define NITCLK_ERROR_SET_ATTRIBUTE_FUNCTION_NOT_SUPPORTED_DUE_TO_DATA_TYPE       -250040 
#define NITCLK_ERROR_GET_ATTRIBUTE_NOT_SUPPORTED                                 -250041 
#define NITCLK_ERROR_SET_ATTRIBUTE_NOT_SUPPORTED                                 -250042 
#define NITCLK_ERROR_INSTRUMENT_DRIVER_CALL_FAILED                               -250043 
#define NITCLK_ERROR_EXT_SAMP_CLK_RATE_NOT_ABOVE_ZERO                            -250044 
#define NITCLK_ERROR_EXT_SAMP_CLK_RATES_UNEQUAL                                  -250045 
#define NITCLK_ERROR_TRIG_MASTER_SESSION_NO_LONGER_VALID                         -250046 
#define NITCLK_ERROR_MULTIPLE_SESSIONS_EXPORT_ONBOARD_REF_CLK                    -250047
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED                                -250048
#define NITCLK_ERROR_ONE_START_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS               -250049
#define NITCLK_ERROR_ONE_REF_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS                 -250050
#define NITCLK_ERROR_ONE_PAUSE_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS               -250051
#define NITCLK_ERROR_ONE_SCRIPT_TRIG_CONFIGURED_ONE_OR_MORE_MASTERS              -250052
#define NITCLK_ERROR_ALL_BUT_ONE_START_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER  -250053
#define NITCLK_ERROR_ALL_BUT_ONE_REF_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER    -250054
#define NITCLK_ERROR_ALL_BUT_ONE_PAUSE_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER  -250055
#define NITCLK_ERROR_ALL_BUT_ONE_SCRIPT_TRIG_CONFIGURED_AND_NONE_TRIG_NOT_MASTER -250056
#define NITCLK_ERROR_NUM_SESSIONS_START_TRIG_CONFIGURED                          -250057
#define NITCLK_ERROR_NUM_SESSIONS_REF_TRIG_CONFIGURED                            -250058
#define NITCLK_ERROR_NUM_SESSIONS_PAUSE_TRIG_CONFIGURED                          -250059
#define NITCLK_ERROR_NUM_SESSIONS_SCRIPT_TRIG_CONFIGURED                         -250060
#define NITCLK_ERROR_SAMP_CLK_RATE_TOO_LOW                                       -250061
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED_FOR_ACQ_SESSIONS               -250062
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED_FOR_EXT_SAMP_CLK               -250063
#define NITCLK_ERROR_SAMP_CLK_DELAY_NOT_SUPPORTED_FOR_EXT_SAMP_CLK_TIMEBASE      -250064
#define NITCLK_ERROR_MORE_THAN_ONE_REF_TRIG_MASTER                               -250065
#define NITCLK_ERROR_ACTIVE_CHANNELS_NOT_SUPPORTED_FOR_LABVIEW                   -250066
#define NITCLK_ERROR_ACTIVE_CHANNELS_FOR_SCRIPT_TRIGGER_MASTER_FOR_LABVIEW       -250067
#define NITCLK_ERROR_VALUE_IS_NULL                                               -250068
#define NITCLK_ERROR_CHANNEL_NAME_FOR_SCRIPT_TRIGGER_MASTER                      -250069
#define NITCLK_ERROR_INCOMPATIBLE_VERSIONS_OF_NITCLK_AND_INSTRUMENT_DRIVER       -250070
#define NITCLK_ERROR_INCOMPATIBLE_VERSIONS_OF_NITCLK_AND_2_INSTRUMENT_DRIVERS    -250071
#define NITCLK_ERROR_EXT_SAMP_CLK_AND_OR_SAMP_CLK_TIMEBASE_RATE_UNMATCHED        -250072
#define NITCLK_ERROR_INVALID_ORDERING_OF_DEVICES_LIST                            -250073
#define NITCLK_ERROR_SESSIONS_CANNOT_BE_SYNC_DUE_TO_CONFIGURATION                -250074
#define NITCLK_ERROR_DRIVER_VERSION_DOES_NOT_SUPPORT_ATTRIBUTE                   -250075
#define NITCLK_ERROR_SESSIONS_CANNOT_CONFIGURED_DUE_TO_CONFIGURATION             -250076

#define NITCLK_WARNING_COMMIT_RETURNED_WARNING                                    250000
#define NITCLK_WARNING_INITIATE_RETURNED_WARNING                                  250001 
#define NITCLK_WARNING_IS_DONE_RETURNED_WARNING                                   250002 
#define NITCLK_WARNING_STRING_TRUNCATED_TO_FIT_BUFFER                             250003 
#define NITCLK_WARNING_INSTRUMENT_DRIVER_CALL_RETURNED_WARNING                    250004  


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* ___niTClk_h___ */



