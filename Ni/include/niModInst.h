// ****************************************************************************
//    NI-ModInst 
// 
//    National Instruments utility library for Modular Instruments Drivers
//                             
//    Copyright (c) National Instruments 2004-.  All Rights Reserved.         
// ****************************************************************************

#ifndef ___niModInst_h___
#define ___niModInst_h___


#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#include "visatype.h"

#ifndef DllExport
   #define DllExport    __declspec( dllexport )
#endif


// ****************************************************************************
// --------------------------- Attribute Definitions --------------------------
// ****************************************************************************

// ViString Attributes
#define NIMODINST_ATTR_DEVICE_NAME                 0
#define NIMODINST_ATTR_DEVICE_MODEL                1
#define NIMODINST_ATTR_SERIAL_NUMBER               2

// ViInt32 Attributes
#define NIMODINST_ATTR_SLOT_NUMBER                 10
#define NIMODINST_ATTR_CHASSIS_NUMBER              11
#define NIMODINST_ATTR_BUS_NUMBER                  12
#define NIMODINST_ATTR_SOCKET_NUMBER               13
// 14-16 Reserved
#define NIMODINST_ATTR_PCIEXPRESS_LINK_WIDTH       17
#define NIMODINST_ATTR_MAX_PCIEXPRESS_LINK_WIDTH   18

// ****************************************************************************
// ------------------------- Library Function Declarations --------------------
// ****************************************************************************

// --- Session Based Functions

ViStatus DllExport _VI_FUNC 
niModInst_OpenInstalledDevicesSession (
   ViConstString driver,
   ViSession* handle, 
   ViInt32* deviceCount);

ViStatus DllExport _VI_FUNC 
niModInst_GetInstalledDeviceAttributeViString (
   ViSession handle,
   ViInt32 index,
   ViInt32 attributeID, 
   ViInt32 attributeValueBufferSize,
   ViChar attributeValue[]);

ViStatus DllExport _VI_FUNC 
niModInst_GetInstalledDeviceAttributeViInt32 (
   ViSession handle,
   ViInt32 index,
   ViInt32 attributeID, 
   ViInt32* attributeValue);

ViStatus DllExport _VI_FUNC 
niModInst_CloseInstalledDevicesSession (
   ViSession handle); 


// --- Utility Functions

ViStatus DllExport _VI_FUNC niModInst_GetExtendedErrorInfo (
   ViInt32 errorInfoBufferSize, 
   ViChar errorInfo[]);


// ****************************************************************************
// ----------------------- Error And Completion Codes -------------------------
// ****************************************************************************

#define NIMODINST_SUCCESS                                               0

#define NIMODINST_ERROR_INVALID_SESSION_HANDLE                          -250200
#define NIMODINST_ERROR_NULL_SESSION_HANDLE                             -250201
#define NIMODINST_ERROR_INVALID_DEVICE_INDEX                            -250202
#define NIMODINST_ERROR_INVALID_ATTRIBUTE_ID                            -250203
#define NIMODINST_ERROR_ATTRIBUTE_NOT_SUPPORTED_BY_DEVICE               -250204
#define NIMODINST_ERROR_NULL_OUTPUT_PARAMETER                           -250205
#define NIMODINST_ERROR_NULL_DRIVER                                     -250206


#if defined(__cplusplus) || defined(__cplusplus__)
}
#endif

#endif /* ___niModInst_h___ */



