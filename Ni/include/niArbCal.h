/* 
   This is the public header file for calibration functions 
   for the National Instruments 54xx series.  This interface
   provides access to the niarbcal.dll and can be used to
   write calibration procedures for any NI PXI and PCI
   54xx board (5411, 5401, 5431, and 5404).  
   
   Please refer to the full documentation that 
   ships with this code.

   © Copyright 2000-2002
   National Instruments Corporation.
   All rights reserved.
*/


#ifndef  ___niArbCal_h___
#define  ___niArbCal_h___



/*-------------------------------------------------------------------
Constants
-------------------------------------------------------------------*/

/*
These are status contants which can be returned by the 
functions below.
*/

#if defined(__cplusplus) || defined(__cplusplus__)
extern "C" {
#endif

#define  NI54XX_STATUS_SUCCESS                            0
#define  NI54XX_STATUS_FUNCTION_NOT_SUPPORTED            -1
#define  NI54XX_STATUS_DEVICE_NOT_FOUND                  -2
#define  NI54XX_STATUS_DEVICE_NOT_SUPPORTED              -3
#define  NI54XX_STATUS_BAD_HANDLE                        -4
#define  NI54XX_STATUS_INCORRECT_PASSWORD                -5
#define  NI54XX_STATUS_INVALID_ACTION                    -6
#define  NI54XX_STATUS_INVALID_WAVE_TYPE                 -7
#define  NI54XX_STATUS_INVALID_AMPLITUDE                 -8
#define  NI54XX_STATUS_INVALID_FREQUENCY                 -9
#define  NI54XX_STATUS_INVALID_VIDEO_MODE                -10
#define  NI54XX_STATUS_INVALID_DUTY_CYCLE                -11
#define  NI54XX_STATUS_INVALID_OFFSET                    -12
#define  NI54XX_STATUS_INVALID_ATTENUATION               -13
#define  NI54XX_STATUS_INVALID_TERMINATION_STATE         -14
#define  NI54XX_STATUS_INVALID_DAC_VALUE                 -15
#define  NI54XX_STATUS_INVALID_FILTER_STATE              -16
#define  NI54XX_STATUS_INVALID_OUTPUT_IMPEDANCE          -17
#define  NI54XX_STATUS_INVALID_MUX_SETTING               -18
#define  NI54XX_STATUS_INVALID_CALIBRATION_AREA          -19
#define  NI54XX_STATUS_INVALID_OUTPUT_STATE              -20
#define  NI54XX_STATUS_BAD_PARAMETER_1                   -21
#define  NI54XX_STATUS_BAD_PARAMETER_2                   -22
#define  NI54XX_STATUS_BAD_PARAMETER_3                   -23
#define  NI54XX_STATUS_BAD_PARAMETER_4                   -24
#define  NI54XX_STATUS_BAD_PARAMETER_5                   -25
#define  NI54XX_STATUS_BAD_PARAMETER_6                   -26
#define  NI54XX_STATUS_UNKNOWN_ERROR                     -27
#define  NI54XX_STATUS_INVALID_MEASUREMENT_MODE          -28
#define  NI54XX_STATUS_INVALID_FREQUENCY_BAND            -29
#define  NI54XX_STATUS_INVALID_NUMBER_OF_MEASUREMENTS    -30
#define  NI54XX_STATUS_INTERNAL_DRIVER_ERROR             -31
#define  NI54XX_STATUS_TEMPERATURE_OUT_OF_RANGE_ERROR    -32
#define  NI54XX_STATUS_MEMORY_ALLOCATION_ERROR           -33

/*
These constants are option parameters for the
ni54xx_CalEnd function.
*/

#define  NI54XX_ABORT            0
#define  NI54XX_COMMIT_CONSTANTS 1


/*
These constants are used as parameters in the various
functions that control the board.
*/

#define  NI54XX_50_OHMS          0
#define  NI54XX_75_OHMS          1
#define  NI54XX_DISABLE          0
#define  NI54XX_ENABLE           1
#define  NI54XX_UNTERMINATED     0
#define  NI54XX_TERMINATED       1
#define  NI54XX_DC               0
#define  NI54XX_SINE             1
#define  NI54XX_PAL_M            0
#define  NI54XX_NTSC_M           1

#define  NI54XX_GND_VS_GND       0
#define  NI54XX_REF_VS_REF       1
#define  NI54XX_OUT_VS_GND       2
#define  NI54XX_OUT_VS_REF       3

#define  NI54XX_INTERNAL         0
#define  NI54XX_EXTERNAL         1


/*
These constants are parameters for measurementMode in the
ni54xx_CalAdjust function.  They specify which calibration constant
is currently being adjusted.
*/

#define  NI54XX_SET_A1                                0
#define  NI54XX_SET_A2                                1
#define  NI54XX_SET_A3                                2
#define  NI54XX_SET_A4                                3
#define  NI54XX_SET_A7                                4
#define  NI54XX_SET_A8                                5
#define  NI54XX_SET_A0                                6
#define  NI54XX_SET_A5                                7
#define  NI54XX_SET_A6                                8
#define  NI54XX_SET_A9_UNTERMINATED                   9
#define  NI54XX_SET_INTERNAL_REFERENCE                10
#define  NI54XX_SET_A9_TERMINATED                     11
#define  NI54XX_SET_A9TA                              12
#define  NI54XX_SET_FREQUENCY_RESPONSE_UNTERMINATED   13
#define  NI54XX_SET_FREQUENCY_RESPONSE_TERMINATED     14
#define  NI54XX_SET_D0                                15
#define  NI54XX_SET_D1_25                             16
#define  NI54XX_SET_D1_75                             17
#define  NI54XX_SET_D1                                18
#define  NI54XX_SET_VCXO                              19
#define  NI54XX_SET_VCXO_PAL_M                        20
#define  NI54XX_SET_VCXO_NTSC_M                       21
#define  NI54XX_SET_AMPLITUDE                         22
#define  NI54XX_SET_DUTY_CYCLE                        23


/*-------------------------------------------------------------------
Functions

  notes: All functions return signed, 32-bit integers 
         corresponding to the status of the operation.

         Not all functions are used for all devices.  
         See the "Supported Devices" comments below for 
         a list of models for which each function is 
         supported.  Also, see the calibration documentation 
         that ships with each device for a detailed 
         description of the calibration procedures.

-------------------------------------------------------------------*/


/*-------------------Main Calibration Functions--------------------*/

/*
ni54xx_CalStart

  Purpose: Initiates a calibration session for the specified device.

  Inputs:
      device:        a number corresponding to the DAQ device
                     number of the board to be calibrated

      password:      the external calibration password
                     this must point to a buffer of characters
                        at least 4 characters long

      sessionHandle: a pointer to the handle of the calibration session
                     used in most other calibration functions

  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_CalStart( unsigned long   device,
                 char            *password,
                 unsigned long   *sessionHandle);



/*
ni54xx_CalAdjust

  Purpose:  Makes an adjustment to the specified calibration constant
            based on the values of the measured and actual data.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      measurementMode:  the calibration constant(s) being adjusted
                        one of the NI54XX_SET_ constants above
                        see documentation for further information

      actualData:    an array of doubles, a pointer to one double, or NULL,
                     depending on the measurementMode parameter
                     (see documentation)

      measuredData:  an array of doubles, a pointer to one double, or NULL,
                     depending on the measurementMode parameter
                     (see documentation)

  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_CalAdjust( unsigned long  sessionHandle,
                  unsigned long  measurementMode,
                  double         *actualData,
                  double         *measuredData );



/*
ni54xx_CalEnd

  Purpose:  Closes the calibration session and either commits or discards 
            the new constants that have been calculated.

  Inputs:
      sessionHandle: a pointer to the handle of the calibration session
                     for the device, created with a call to ni54xx_CalStart

      action:        NI54XX_ABORT or NI54XX_COMMIT_CONSTANTS
                     using abort avoids storing the newly calculated
                        calibration constants in an on-board EEPROM
                     
  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_CalEnd(unsigned long   *sessionHandle,
              unsigned long   action);



/*
ni54xx_CalSelfCalibrate

  Purpose:  Performs an internal calibration of the device and stores the
            new calibration constants that it calculcates.  The self-
            calibration can only determine constants A0 through A8.
            CalStart and CalEnd do not need to be called with this function.

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_CalSelfCalibrate(unsigned long  device);



/*---------------Miscellaneous Utility Functions------------------*/


/*
ni54xx_CalFetchDate

  Purpose:  Retrieves the date of the last calibration, either from the  
            internal (self-calibration) or external (manual calibration)
            area.

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

      area:       the area (internal or external) from where to get the date
                  NI54XX_INTERNAL or NI54XX_EXTERNAL

      month:      a pointer to a long integer which will receive the month value

      day:        a pointer to a long integer which will receive the date value

      year:       a pointer to a long integer which will receive the year value

  Supported Devices: 5411, 5401, 5431, 5404                     

*/
__declspec(dllexport) long __stdcall
ni54xx_CalFetchDate(unsigned long   device,
                    long            area,
                    long            *month,
                    long            *day,
                    long            *year);



/*
ni54xx_CalFetchCount

  Purpose:  Retrieves the number of times the device has been calibrated,
            either internally (self-calibration) or externally
            (manual calibration).

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

      area:       the area (internal or external) from where to get the count
                  NI54XX_INTERNAL or NI54XX_EXTERNAL

      count:      a pointer to a long integer which will receive the count value

  Supported Devices: 5411, 5401, 5431, 5404
                     
*/
__declspec(dllexport) long __stdcall
ni54xx_CalFetchCount(unsigned long  device,
                     long           area,
                     long           *count);



/*
ni54xx_CalFetchMiscInfo

  Purpose:  Retrieves four bytes of data from the external calibration 
            miscellaneous data area.

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

      miscInfo:   this should be a char pointer which points to a buffer
                     which is at least 4 bytes long
                  this buffer should be allocated by the user
                     
  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall
ni54xx_CalFetchMiscInfo(unsigned long  device,
                        char           *miscInfo);



/*
ni54xx_CalStoreMiscInfo

  Purpose:  Stores four bytes of data in the external calibration 
            miscellaneous data area.

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

      miscInfo:   this should be a char pointer which points to a buffer
                     which is at least 4 bytes long
                  this buffer and its contents should be allocated and
                     specified by the user

  Supported Devices: 5411, 5401, 5431, 5404
                     
*/
__declspec(dllexport) long __stdcall
ni54xx_CalStoreMiscInfo(unsigned long  device,
                        char           *miscInfo);



/*
ni54xx_CalChangePassword

  Purpose:  Changes the password which is needed to do a full external
            calibration.

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

      oldPassword:   the currently existing password

      newPassword:   the new password (will replace the currently existing
                        password)

  Supported Devices: 5411, 5401, 5431, 5404
                     
*/
__declspec(dllexport) long __stdcall
ni54xx_CalChangePassword(unsigned long    device,
                         char             *oldPassword,
                         char             *newPassword);



/*
ni54xx_CalRestoreExternalConstants

  Purpose:  Copies the constants from the last external calibration into
            the internal calibration area, thereby restoring the state of the
            device to that of the last external calibration.  For use if 
            an internal calibration goes awry or produces unacceptable
            results.

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

  Supported Devices: 5411, 5401, 5431

                     
*/
__declspec(dllexport) long __stdcall
ni54xx_CalRestoreExternalConstants(unsigned long   device);



/*
ni54xx_CalGetLastCalibrationTemperature

  Purpose:  Retrieves the temperature at which the board was last 
            calibrated.

  Inputs:
      device:     a number corresponding to the DAQ device number of the
                  board to be calibrated

      area:       specifies whether to retrieve the temperature at the 
                  last internal (self-) calibration or external calibration
                  NI54XX_INTERNAL or NI54XX_EXTERNAL

      temperature:   a pointer to a double which will receive the temperature
                     value

  Supported Devices: 5404
                     
*/
__declspec(dllexport) long __stdcall 
ni54xx_CalGetLastCalibrationTemperature(unsigned long device, 
                                        int           area, 
                                        double*       temperature);




/*----------------------Device Control Functions-------------------------

  These functions allow the user to configure the device and initiate
  waveform generations.  They will be used extensively during an external
  calibration.  Refer to the documentation and  the external calibration
  example for detailed instructions on their use.

  -----------------------------------------------------------------------*/



/*
ni54xx_DeviceReset

  Purpose:  Resets the 54xx board and puts it in a default reset state.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

  Supported Devices: 5411, 5401, 5431, 5404
                     
*/
__declspec(dllexport) long __stdcall 
ni54xx_DeviceReset(unsigned long    sessionHandle );



/*
ni54xx_SetArbOutput

  Purpose:  Enables or disables the output of the device.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      outputState:   indicates whether to enable or disable the output
                     NI54XX_ENABLE or NI54XX_DISABLE

  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetArbOutput(unsigned long   sessionHandle,
                    unsigned long   outputState );



/*
ni54xx_SetAnalogFilter

  Purpose:  Enables or disables the analog filter of the device.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      filterState:   indicates whether to enable or disable the filter
                     NI54XX_ENABLE or NI54XX_DISABLE

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetAnalogFilter(unsigned long   sessionHandle,
                       unsigned long   filterState );



/*
ni54xx_SetDigitalFilter

  Purpose:  Enables or disables the digital filter of the device.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      filterState:   indicates whether to enable or disable the filter
                     NI54XX_ENABLE or NI54XX_DISABLE
                     this should normally be enabled

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetDigitalFilter(unsigned long  sessionHandle,
                        unsigned long  filterState );



/*
ni54xx_SetOutputImpedance

  Purpose:  Sets the output impedance of the device (50 or 75 ohms).
            During calibration, however, the impedance should never 
            really be set to 75 ohms.  The terminated case assumes
            a 50 ohm load.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      impedance:     the output impedance value to set
                     NI54XX_50_OHMS or NI54XX_75_OHMS

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetOutputImpedance(unsigned long   sessionHandle,
                          unsigned long   impedance );



/*
ni54xx_GenerateWaveform

  Purpose:  Causes the device to output a DC voltage or a sine wave
            with a specified amplitude and frequency.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      waveType:      the type of waveform to generate
                     NI54XX_DC or NI54XX_SINE

      amplitudeInVolts: the amplitude of the waveform (in volts)

                        For the 5411, 5431, and 5401: this is the 
                           peak amplitude into an unterminated
                           (high impedance) load

                        For the 5404: this is the peak to peak 
                           amplitude into a 50 Ohm load

      frequencyInHz: the frequency of the waveform (in hertz)
                     ignored for the DC case, of course

  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_GenerateWaveform(unsigned long  sessionHandle,
                        unsigned long  waveType,
                        double         amplitudeInVolts,
                        double         frequencyInHz );



/*
ni54xx_GenerateVideoWaveform

  Purpose:  Causes the device to output a DC voltage or a sine wave
            with a specified amplitude and frequency.  This function is
            ONLY used when creating a PAL or NTSC video signal for
            calibrating the VCXO of the 5431.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      waveType:      the type of waveform to generate
                     NI54XX_DC or NI54XX_SINE

      amplitudeInVolts:    the amplitude of the waveform (in volts)
                           this is the amplitude into an unterminated
                              (high impedance) load

      frequencyInHz: the frequency of the waveform (in hertz)
                     ignored for the DC case, of course

      videoMode:     the video mode (different clocking schemes are used)
                     NI54XX_PAL_M or NI54XX_NTSC_M

  Supported Devices: 5431

*/
__declspec(dllexport) long __stdcall
ni54xx_GenerateVideoWaveform(unsigned long   sessionHandle ,
                             unsigned long   waveType, 
                             double          amplitudeInVolts,
                             double          frequencyInHz,
                             unsigned long   videoMode);



/*
ni54xx_SetDutyCycle

  Purpose:  Sets the duty cycle of the board's SYNC output.  Note:
            this will only work correctly when the board is generating
            a sine wave at full scale (10 V into an unterminated load).

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      dutyCycle:     the duty cycle of the SYNC output, in percentage
                     (e.g. for 50% duty cycle, dutyCycle = 50.0)

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetDutyCycle( unsigned long  sessionHandle,
                     double         dutyCycle );



/*
ni54xx_SetAdjustedGainAndOffset

  Purpose:  This function configures the board to output with a certain
            level of attenuation and a certain offset.  It uses the calibration
            constants for the session (including those that have been changed
            during the session) to calculate the appropriate settings for the 
            calibration DACs.  The user must also provide the termination state
            (whether the board is unterminated [high-impedance load] or 
            terminated [50-ohm load]).

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      offsetInVolts: the DC offset of the waveform 
                     can be from -2.5 to 2.5 volts

      attenuationInDb:  the amount of post-amplifier attenuation applied
                           to the signal
                        from 0 to 73 dB in 1dB increments

      terminationState: NI54XX_UNTERMINATED (high-impedance load)
                        NI54XX_TERMINATED   (50-ohm load)

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetAdjustedGainAndOffset(unsigned long   sessionHandle,
                                double          offsetInVolts,
                                unsigned long   attenuationInDb,
                                unsigned long   terminatedState );



/*
ni54xx_SetGainDAC

  Purpose:  Sets the gain calibration DAC to the specified value.
            This affects the pre-attenuation gain of the signal.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      DACValue:      the integer value to write to the gain DAC
                     ranges from -8192 to 8191

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetGainDAC(unsigned long  sessionHandle,
                  long           DACValue );



/*
ni54xx_SetOffsetDAC

  Purpose:  Sets the offset calibration DAC to the specified value.
            This affects the pre-attenuation offset of the signal.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      DACValue:      the integer value to write to the offset DAC
                     ranges from -8192 to 8191

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetOffsetDAC(unsigned long   sessionHandle,
                    long            DACValue );



/*
ni54xx_SetAttenuation

  Purpose:  Sets the attenuation of the signal in dB.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      attenuation:   amount of attenuation to apply to the signal in dB
                     the user should use one of the following values:
                        (0,1,2,4,8,10,16,32)

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetAttenuation(unsigned long    sessionHandle,
                      unsigned long    attenuation );



/*
ni54xx_SetCalibrationMux

  Purpose:  Determines what value is read by a call to ReadCalibrationADC,
            the ground vs. the ground, the reference vs. the reference,
            the ouput vs. the ground, or the output vs. the reference.
            This should only be set to output vs. reference by the user.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      muxSetting:    the multiplexer setting
                     NI54XX_GND_VS_GND, NI54XX_REF_VS_REF,
                     NI54XX_OUT_VS_GND, or NI54XX_OUT_VS_REF

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetCalibrationMux(unsigned long    sessionHandle,
                         unsigned long    muxSetting );



/*
ni54xx_ReadCalibrationADC

  Purpose:  Reads the value of the calibration analog to digital converter,
            which holds the difference of the two inputs to the calibration 
            multiplexer.  For example, the current output can be compared to 
            the internal reference of the board.  This function returns the 
            average of many readings of the ADC.


  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      calADCValue:   a pointer to the value returned by the function

  Supported Devices: 5411, 5401, 5431

*/
__declspec(dllexport) long __stdcall 
ni54xx_ReadCalibrationADC(unsigned long   sessionHandle,
                          double          *calADCValue );



/*
ni54xx_InitializeVCXOCalibration

  Purpose:  The VCXO is calibrated in an iterative method.  This call 
            must be made before calibrating the VCXO.  It sets many 
            internal variables to appropriate values for the calibration.


  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      type:          the type of VCXO calibration to be done
                     NI54XX_SET_VCXO or
                     NI54XX_SET_PAL_M  (for the 5431 ONLY) or
                     NI54XX_SET_NTSC_M (for the 5431 ONLY)

  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall
ni54xx_InitializeVCXOCalibration(unsigned long  sessionHandle,
                                 unsigned long  type);



/*
ni54xx_CalibrateVCXO

  Purpose:  Re-tunes the VCXO with the current test value.
            This is used during calibration to iteratively converge on 
            the best value.  A new value is calculated, then this function 
            is called to set the VCXO, then the output is measured, and
            then a new value is calculated, and so on.


  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      type:          the type of VCXO calibration to be done
                     NI54XX_SET_VCXO or
                     NI54XX_SET_PAL_M  (for the 5431 ONLY) or
                     NI54XX_SET_NTSC_M (for the 5431 ONLY)

  Supported Devices: 5411, 5401, 5431, 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_CalibrateVCXO(unsigned long  sessionHandle,
                     unsigned long  type);



/*
ni54xx_InitializeAmplitudeCalibration

  Purpose:  The sine out amplitude of the 5404 is calibrated in an 
            iterative method.  This call must be made before calibrating 
            the sine amplitude.  It sets many internal variables to 
            appropriate values for the calibration.


  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      frequencyBand: an integer representing the index of the frequency 
                     band under which this calibration is being performed
                     (see documentation)

  Supported Devices: 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_InitializeAmplitudeCalibration(unsigned long sessionHandle, 
                                      unsigned long frequencyBand);



/*
ni54xx_CalibrateAmplitude

  Purpose:  Re-tunes the sine amplitude with the current test value.
            This is used during calibration to iteratively converge on 
            the best value.  A new value is calculated, then this function 
            is called to tune the amplitude, then the output is measured, 
            and then a new value is calculated, and so on.


  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

  Supported Devices: 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_CalibrateAmplitude(unsigned long  sessionHandle);



/*
ni54xx_InitializeDutyCycleCalibration

  Purpose:  This call must be made before calibrating the duty cycle 
            of the clock out terminal.  It sets many internal variables 
            to appropriate values for the calibration.


  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      frequencyBand: an integer representing the index of the frequency 
                     band under which this calibration is being performed
                     (see documentation)

      numberOfMeasurements:   the number of duty cycle measurements the 
                              user will take and pass into the 
                              _CalAdjust() function

  Supported Devices: 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_InitializeDutyCycleCalibration(unsigned long sessionHandle, 
                                      unsigned long frequencyBand, 
                                      unsigned long numberOfMeasurements);



/*
ni54xx_SetSYNCDAC

  Purpose:  Sets the SYNC calibration DAC to the specified value.
            This affects the duty cycle of the signal at the 
            clock out terminal and is used during a duty cycle 
            calibration.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

      DACValue:      the integer value to write to the SYNC DAC
                     ranges from 0 to 255

  Supported Devices: 5404

*/
__declspec(dllexport) long __stdcall 
ni54xx_SetSYNCDAC(unsigned long  sessionHandle, 
                  unsigned long  DACValue );




/*
ni54xx_ApplySessionConstants

  Purpose:  During calibration, the session holds an internal set of 
            calibration constants.  These constants may have been updated 
            based on calibration steps performed during the session.  
            This function commits the session constants to the underlying 
            driver so that the device will be calibrated according to the 
            newly updated constants for the remainder of the session.  
            This function does not store the updated constants in the 
            on-board EEPROM.

  Inputs:
      sessionHandle: a handle to the calibration session for the device,
                     created with a call to ni54xx_CalStart

  Supported Devices: 5404


*/
__declspec(dllexport) long __stdcall 
ni54xx_ApplySessionConstants(unsigned long  sessionHandle);




#if defined(__cplusplus) || defined(__cplusplus__)
} //extern "C"
#endif


#endif //___niArbCal_h___
