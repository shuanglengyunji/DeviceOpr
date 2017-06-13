/****************************************************************************
*          National Instruments High Speed Sources Signal Generator                          
*---------------------------------------------------------------------------
*   Copyright (c) National Instruments 1998-2003.  All Rights Reserved.         
*---------------------------------------------------------------------------
*                                                                          
* Title:    niHSDIOObsolete.h                                        
* Purpose:  National Instruments High-Speed Digital I/O                                    
*           Instrument Driver declarations : Obsolete functions and attributes.                              
*                                                                          
****************************************************************************/

#ifndef __NIHSDIOOBSOLETE_HEADER
#define __NIHSDIOOBSOLETE_HEADER

#include <ivi.h>

/*  Compatibility with older versions ------*/

/*-  Deprecated Attributes  --------*/
#define NIHSDIO_ATTR_DEVICE_SERIAL_NUMBER       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 84L)   /* ViInt32 */
#define NIHSDIO_ATTR_START_TRIGGER_IMPEDANCE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 1L)    /* ViReal64 */
#define NIHSDIO_ATTR_REF_TRIGGER_IMPEDANCE      (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 4L)    /* ViReal64 */
#define NIHSDIO_ATTR_SCRIPT_TRIGGER_IMPEDANCE   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 5L)    /* ViReal64 */
#define NIHSDIO_ATTR_PAUSE_TRIGGER_IMPEDANCE    (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 15L)   /* ViReal64 */
#define NIHSDIO_ATTR_ADVANCE_TRIGGER_IMPEDANCE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 95L)   /* ViReal64 */
#define NIHSDIO_ATTR_START_TRIGGER_POSITION     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 75L)   /* ViInt32 */
#define NIHSDIO_ATTR_REF_TRIGGER_POSITION       (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 77L)   /* ViInt32 */
#define NIHSDIO_ATTR_PAUSE_TRIGGER_POSITION     (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 87L)   /* ViInt32 */
#define NIHSDIO_ATTR_ADVANCE_TRIGGER_POSITION   (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 93L)   /* ViInt32 */
#define NIHSDIO_ATTR_HWC_HARDWARE_COMPARE_MODE  (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 130L)  /* ViInt32 */
#define NIHSDIO_ATTR_DAQMX_TASK                 (IVI_SPECIFIC_PUBLIC_ATTR_BASE + 69L)   /* ViInt32 */

/*-  Deprecated Values  --------*/
#define NIHSDIO_VAL_PXI_CLK10_STR                        "PXI_CLK10"
#define NIHSDIO_VAL_PXI_CLK100_STR                       "PXI_CLK100"

/* Hardware Compare Mode Values - Use Supported Data States instead */
#define NIHSDIO_VAL_HWC_DISABLED                         77
#define NIHSDIO_VAL_HWC_STIMULUS_AND_EXPECTED_RESPONSE   78
#define NIHSDIO_VAL_HWC_EXPECTED_RESPONSE_ONLY           79

#endif /* __NIHSDIOOBSOLETE_HEADER */