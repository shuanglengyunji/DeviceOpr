#ifndef ___niRFSA_niRFSAErrors_h___
#define ___niRFSA_niRFSAErrors_h___

/*******************************/
/*********** Errors ************/
/*******************************/

/* hex:0xBFFA4130 */
/* Relay count operations are not supported on this device */
#define NIRFSA_ERROR_RELAY_COUNT_NOT_SUPPORTED -1074118352

/* hex:0xBFFA412F */
/* Calibration Tone Frequency was found to exceed maximum deviation. Make sure the PXI chassis backplane clock and the LO Reference Clock are both locked to the same source. */
#define NIRFSA_ERROR_CAL_TONE_FREQUENCY_MAX_DEVIATION_EXCEEDED -1074118353

/* hex:0xBFFA412E */
/* The specified calibration gain adjustment is invalid, verify calibration setup is correct. Contact National Instruments support for further information */
#define NIRFSA_ERROR_EXTCAL_INVALID_GAIN_ADJUSTED -1074118354

/* hex:0xBFFA412D */
/* Adjacent Channel Power Ratio (ACPR) measurements are not supported in the current IF Filter path. Choose a narrower IF Filter by decreasing Span or Device Instantaneous Bandwidth. */
#define NIRFSA_ERROR_ACPR_NOT_SUPPORTED_IN_FILTER_PATH -1074118355

/* hex:0xBFFA412C */
/* Adjacent Channel Power Ratio (ACPR) measurement calibration is not supported with the selected IF filter path, Choose a different table type or a narrower filter. */
#define NIRFSA_ERROR_ACPR_CALIBRATION_NOT_SUPPORTED_IN_FILTER_PATH -1074118356

/* hex:0xBFFA412B */
/* NI-RFSA cannot achieve the specified calibration tone frequency. To solve this issue, try changing the requested resolution. */
#define NIRFSA_ERROR_CALIBRATION_TONE_INVALID -1074118357

/* hex:0xBFFA412A */
/* The number of frequencies and LO attenuation settings being passed to the function are not the same. Ensure the arrays you pass to the function have the same number of elements. */
#define NIRFSA_ERROR_NUMBER_OF_FREQUENCIES_LO_ATTENUATION_MISMATCH -1074118358

/* hex:0xBFFA4129 */
/* NI-RFSA cannot initialize a calibration session because another calibration session for the specified device is already open. Close the open session by calling niRFSA Close Ext Cal or by exiting the application with the open session. */
#define NIRFSA_ERROR_CAL_SESSION_ALREADY_EXISTS -1074118359

/* hex:0xBFFA4128 */
/* Calibration is not supported on simulated devices. */
#define NIRFSA_ERROR_CALIBRATION_SESSION_NOT_SUPPORTED_IN_SIMULATION -1074118360

/* hex:0xBFFA4127 */
/* You have exceeded the EEPROM memory space allocated for Self Cal. Run Self Cal again for all invalid steps, or contatct National Instruments technical support. */
#define NIRFSA_ERROR_EEPROM_SPACE_EXCEEDED_FOR_SELF_CAL -1074118361

/* hex:0xBFFA4126 */
/* The gain associated with the specified index is not valid for the specified frequency. */
#define NIRFSA_ERROR_INVALID_IF_GAIN_FOR_FREQUENCY -1074118362

/* hex:0xBFFA4125 */
/* The parameter value specified is not supported when using an external digitizer. */
#define NIRFSA_ERROR_INVALID_PARAMETER_VALUE_FOR_EXTERNAL_DIGITIZER -1074118363

/* hex:0xBFFA4124 */
/* This property or attribute is supported only during a calibration session. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_NON_CALIBRATION_SESSION -1074118364

/* hex:0xBFFA4123 */
/* LO2 and LO3 calibration adjustment supports adjusting only a single LO frequency (4 GHz  and 800 MHz, respectively). */
#define NIRFSA_ERROR_INVALID_LO_EXPORT_CALIBRATION_NUMBER_OF_FREQUENCIES -1074118365

/* hex:0xBFFA4122 */
/* The device temperature deviation during calibration exceeded the maximum allowed amount. To correct the issue, ensure good ventilation and a stable room temperature, and set the fan speed to its maximum. */
#define NIRFSA_ERROR_CALIBRATION_TEMPERATURE_DEVIATION_EXCEEDED -1074118366

/* hex:0xBFFA4121 */
/* A configuration property or attribute that is required for calibration is missing. Commit these properties and attributes prior to calling calibration adjustment VIs and functions. */
#define NIRFSA_ERROR_REQUIRED_CALIBRATION_PARAMETER_MISSING -1074118367

/* hex:0xBFFA4120 */
/* An invalid LO export number was provided to the niRFSA Cal Adjust LO Export Calibration function. */
#define NIRFSA_ERROR_INVALID_LO_EXPORT_NUMBER -1074118368

/* hex:0xBFFA411F */
/* The LO Export attenuation was adjusted to a value outside the supported range. */
#define NIRFSA_ERROR_LO_EXPORT_ATTENUATION_OUT_OF_RANGE -1074118369

/* hex:0xBFFA411E */
/* The maximum supported mixer level was exceeded. This problem is usually caused by forcing low RF attenuation. To correct the issue, increase the RF attenuation so that the mixer level is equal to the reference level minus the RF attenuation plus RF gain. */
#define NIRFSA_ERROR_MAXIMUM_MIXER_LEVEL_EXCEEDED -1074118370

/* hex:0xBFFA411D */
/* NI-RFSA failed to align the YIG tunable filter (YTF). */
#define NIRFSA_ERROR_YTF_ALIGNMENT_DOES_NOT_COVER_RANGE -1074118371

/* hex:0xBFFA411C */
/* NI-RFSA failed to detect a signal while calibrating the YTF module. Ensure that your LO and digitizer are properly connected by running the test panel in MAX. */
#define NIRFSA_ERROR_YTF_ALIGNMENT_SIGNAL_DETECTION_FAILED -1074118372

/* hex:0xBFFA411B */
/* Creation of the simulated device failed. Connection to the MXS database is taking too long. Restart your system, and if this process does not solve the problem, contact National Instruments technical support. */
#define NIRFSA_ERROR_SIMULATED_DEVICE_CREATION_FAILED -1074118373

/* hex:0xBFFA411A */
/* NI-RFSA does not support the specified LO. */
#define NIRFSA_ERROR_LO_NOT_SUPPORTED -1074118374

/* hex:0xBFFA4119 */
/* The specified keyword is not supported in this session. Real sessions support Digitizer and LO Driver Setup keywords, while simulated sessions support DigitizerModel and LOModel Driver Setup keywords. Refer to the documentation for more information about Driver Setup keywords. */
#define NIRFSA_ERROR_KEYWORD_NOT_SUPPORTED_IN_SESSION -1074118375

/* hex:0xBFFA4116 */
/* The Reference clock is not a valid value for this operation. */
#define NIRFSA_ERROR_REF_CLOCK_INVALID_SIGNAL_TYPE -1074118378

/* hex:0xBFFA4111 */
/* You have exceeded the maximum number of configuration list steps supported for your device. */
#define NIRFSA_ERROR_MAX_STEP_COUNT_EXCEEDED -1074118383

/* hex:0xBFFA4110 */
/* NI-RFSA cannot get the frequency response. Calibration data is not available for this device configuration. */
#define NIRFA_ERROR_CANNOT_GET_FREQUENCY_RESPONSE -1074118384

/* hex:0xBFFA410F */
/* The currently installed version of NI-RFSA is not compatible with the currently installed version of NI-RFSG. Downgrade your NI-RFSA installation, or upgrade your NI-RFSG installation. */
#define NIRFSA_ERROR_NIRFSG_DRIVER_VERSION_TOO_OLD -1074118385

/* hex:0xBFFA410E */
/* The currently installed version of NI-RFSA is not compatible with the currently installed version of NI-RFSG. Upgrade your NI-RFSA installation, or downgrade your NI-RFSG installation. */
#define NIRFSA_ERROR_NIRFSG_DRIVER_VERSION_TOO_NEW -1074118386

/* hex:0xBFFA40EC */
/* This function is only supported when using NI-RFSA in external digitizer mode. Specify the digitizer resource name as <external> in Measurement & Automation Explorer or in the Option String. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_DOWNCONVERTER_DIGITIZER_MODE -1074118420

/* hex:0xBFFA40EB */
/* This attribute is only supported when using NI-RFSA in external digitizer mode. Specify the digitizer resource name as <external> in Measurement & Automation Explorer or in the Option String. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_DOWNCONVERTER_DIGITIZER_MODE -1074118421

/* hex:0xBFFA40DA */
/* The temperature sensor on the device returned a bad reading. The sensor may be failing and need replacement. Contact National Instruments Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_BAD_TEMPERATURE_READING -1074118438

/* hex:0xBFFA40CA */
/* You must specify the reference level, attenuation, and mixer level attributes such that attenuation = reference level - mixer level. If you do not set either mixer level or attenuation, the driver selects the appropriate value for the attribute. */
#define NIRFSA_ERROR_ATTENUATION_RELATIONSHIP_INVALID -1074118454

/* hex:0xBFFA401E */
/* The configured trigger level value is too high. The maximum value for the trigger level is determined by the configured reference level. */
#define NIRFSA_ERROR_TRIGGER_LEVEL_HIGHER_THAN_REF_LEVEL -1074118626

/* hex:0xBFFA401D */
/* Additional calibration information is necessary to enable this feature. */
#define NIRFSA_ERROR_ADDITIONAL_CALIBRATION_NEEDED_FOR_THIS_FEATURE -1074118627

/* hex:0xBFFA401C */
/* This function is not supported when using NI-RFSA with an external LO module. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_EXTERNAL_LO_MODE -1074118628

/* hex:0xBFFA401B */
/* This attribute is not supported when using NI-RFSA with the external LO module. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_EXTERNAL_LO_MODE -1074118629

/* hex:0xBFFA401A */
/* The LO returned the following error: */
#define NIRFSA_ERROR_NIRFSG_ERROR -1074118630

/* hex:0xBFFA4019 */
/* LO resource name is invalid. The resource name can be invalid because you either associated an invalid LO resource name in MAX with the downconverter or because you tried to use niRFSA Init With Options with a DriverSetup string that included an invalid LO resource name. */
#define NIRFSA_ERROR_INVALID_LO_RESOURCE_NAME -1074118631

/* hex:0xBFFA4018 */
/* Session could not be opened because the LO resource name was not specified. Specify the LO resource name in Measurement & Automation Explorer or in the Option String. */
#define NIRFSA_ERROR_LO_RESOURCE_NAME_NOT_FOUND -1074118632

/* hex:0xBFFA4017 */
/* The currently installed version of NI-RFSA is not compatible with the currently installed version of NI-SCOPE. Upgrade your NI-RFSA installation, or downgrade your NI-SCOPE installation. */
#define NIRFSA_ERROR_INCOMPATIBLE_NISCOPE_DRIVER_VERSION -1074118633

/* hex:0xBFFA4016 */
/* The attenuator relays are not settled. Repair or reinstall the NI-RFSA instrument driver. Contact National Instruments Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_ATTENUATORS_NOT_SETTLED -1074118634

/* hex:0xBFFA4015 */
/* The frequency tuning PLL is not locked. */
#define NIRFSA_ERROR_FREQUENCY_TUNING_PLL_NOT_LOCKED -1074118635

/* hex:0xBFFA4014 */
/* The Reference clock PLL is not locked. */
#define NIRFSA_ERROR_REF_CLK_PLL_NOT_LOCKED -1074118636

/* hex:0xBFFA4013 */
/* This attribute is not supported when using NI-RFSA with an external digitizer module. */
#define NIRFSA_ERROR_ATTR_NOT_SUPPORTED_IN_DOWNCONVERTER_ONLY_MODE -1074118637

/* hex:0xBFFA4012 */
/* This function is not supported when using NI-RFSA with an external digitizer module. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_DOWNCONVERTER_ONLY_MODE -1074118638

/* hex:0xBFFA4011 */
/* This function is not supported when the acquistion type is set to IQ. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_IQ_ACQUISITION -1074118639

/* hex:0xBFFA4010 */
/* This function is not supported when the acquistion type is set to Spectrum. */
#define NIRFSA_ERROR_FUNCTION_NOT_SUPPORTED_IN_SPECTRUM_ACQUISITION -1074118640

/* hex:0xBFFA400F */
/* You can only get the specified property while the session is committed or while the session is running.Commit or initiate the session prior to getting the property. */
#define NIRFSA_ERROR_GET_WHEN_SESSION_NOT_RUNNING -1074118641

/* hex:0xBFFA400E */
/* Unable to initialize because a session for the specified device is already open from another process. Close the open session by calling niRFSA Close or by exiting the application with the open session. */
#define NIRFSA_ERROR_INSTRUMENT_ALREADY_IN_USE -1074118642

/* hex:0xBFFA400D */
/* Device not available in NI-RFSA. The device may be being used by NI-Tuner or NI-5660, or the device is being reset. After using a device in NI-Tuner, you must reset the device using the Traditional DAQ Device Reset before using it in NI-RFSA. */
#define NIRFSA_ERROR_DEVICE_ABSENT_OR_UNAVAILABLE -1074118643

/* hex:0xBFFA400C */
/* The device's calibration revision is unsupported by this version of the driver. Upgrade the driver. Contact National Instruments Technical Support if you need additional information or the problem persists. */
#define NIRFSA_ERROR_UNSUPPORTED_CALIBRATION_REVISION -1074118644

/* hex:0xBFFA400B */
/* The specified operation cannot be performed because a session has been aborted or a device has been removed from the system. */
#define NIRFSA_ERROR_RUNTIME_ABORTED -1074118645

/* hex:0xBFFA400A */
/* Specified property cannot be set while the session is running.Set the property prior to initiating the session, or abort the session prior to setting the property. */
#define NIRFSA_ERROR_SET_WHEN_SESSION_RUNNING -1074118646

/* hex:0xBFFA4009 */
/* Specified operation is only supported while the session is running.Initiate the session before requesting the operation and ensure that the session has not been aborted. */
#define NIRFSA_ERROR_SESSION_NOT_IN_RUNNING_STATE -1074118647

/* hex:0xBFFA4008 */
/* You cannot perform this action while the session is running. */
#define NIRFSA_ERROR_SESSION_IN_RUNNING_STATE -1074118648

/* hex:0xBFFA4007 */
/* Session could not be opened because the digitizer resource name was not specified. Specify the digitizer resource name in Measurement & Automation Explorer by right-clicking on the downconverter and selecting Properties. */
#define NIRFSA_ERROR_DIGITIZER_RESOURCE_NAME_NOT_FOUND_IN_INIT -1074118649

/* hex:0xBFFA4006 */
/* Session could not be opened because the digitizer resource name was not specified. Specify the digitizer resource name in Measurement & Automation Explorer by right-clicking on the downconverter and selecting Properties.  If you are specifying the digitizer via the Option String, ensure the digitizer Resource Name is valid. */
#define NIRFSA_ERROR_DIGITIZER_RESOURCE_NAME_NOT_FOUND -1074118650

/* hex:0xBFFA4005 */
/* Digitizer resource name is invalid. The resource name can be invalid because you either associated an invalid digitizer resource name in MAX with the downconverter or because you tried to use niRFSA Init With Options with a DriverSetup string that included an invalid digitizer resource name. */
#define NIRFSA_ERROR_INVALID_DIGITIZER_RESOURCE_NAME -1074118651

/* hex:0xBFFA4004 */
/* The specified digitizer is not supported by NI-RFSA. */
#define NIRFSA_ERROR_DIGITIZER_NOT_SUPPORTED -1074118652

/* hex:0xBFFA4003 */
/* The device specified is not supported by this driver. */
#define NIRFSA_ERROR_DEVICE_NOT_SUPPORTED -1074118653

/* hex:0xBFFA4002 */
/* Maximum time exceeded before the operation completed. */
#define NIRFSA_ERROR_MAX_TIME_EXCEEDED -1074118654

/* hex:0xBFFA4001 */
/* The digitizer returned the following error: */
#define NIRFSA_ERROR_NISCOPE_ERROR -1074118655

/*********************************/
/*********** Warnings ************/
/*********************************/

/* hex:0x3FFA4001 */
/* The digitizer returned the following warning: */
#define NIRFSA_WARN_NISCOPE_WARN 1073364993

/* hex:0x3FFA4002 */
/* The reference clock PLL is not locked. */
#define NIRFSA_WARN_REF_CLK_PLL_NOT_LOCKED 1073364994

/* hex:0x3FFA4003 */
/* The LO returned the following warning: */
#define NIRFSA_WARN_NIRFSG_WARN 1073364995

/* hex:0x3FFA4004 */
/* The digitizer returned the following PLL warning: */
#define NIRFSA_WARN_NISCOPE_PLL_WARN 1073364996

/* hex:0x3FFA4005 */
/* The current channel coupling configuration is not calibrated, accuracy levels are not guaranteed */
#define NIRFSA_WARN_DCBLOCK_NOT_CALIBRATED 1073364997

/* hex:0x3FFA4006 */
/* The Speficied IF state is not present in the calibration data, try a different IF filter path, IF Attenuation table type, or IF Index. */
#define NIRFSA_WARN_IF_INDEX_NOT_CALIBRATED 1073364998

/* hex:0x3FFA4007 */
/* The specified Attenuation constraints are not calibrated, Reference level accuracy not guaranteed. */
#define NIRFSA_WARN_ATTENUATION_CONSTRAINT_NOT_CALIBRATED 1073364999

/* hex:0x3FFA4008 */
/* Calibration data not present or invalid, Reference level accuracy not guaranteed */
#define NIRFSA_WARN_CALIBRATION_DATA_NOT_PRESENT 1073365000

/* hex:0x3FFA4009 */
/* The current RF configuration is not calibrated. Try changing the Channel Coupling attribute, Preamp Enabled attribute, or RF attenuation configuration with either Mixer Level or RF Attenuation Attributes */
#define NIRFSA_WARN_RF_CONFIGURATION_NOT_CALIBRATED 1073365001

#endif /* ___niRFSA_niRFSAErrors_h___ */
