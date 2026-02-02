/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LRS4000.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DeviceIdent.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LocationName.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SerialNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/FirmwareVersion.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SetPassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/getChallenge.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/changePassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/FindMe.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/OrderNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DeviceStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/WriteEeprom.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SCdevicestate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SoftReset.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/RebootDevice.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LoadFactoryDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LoadApplicationDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LastParaDate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LastParaTime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DoDiagnosisDump.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/GetDiagnosisDumpInfo.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherIPAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherIPGateAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherIPMask.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherAuxEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherAddressingMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherDHCPFallback.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EthernetUpdate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherIPAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherIPGateAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherIPMaskDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ScanConfig.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DataOutputRange.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/InputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/OutputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/PortState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/mResetOutputCounter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DeviceTime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/FREchoFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ParticleFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherMACAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EnableColaScan.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherCoLaAEventsEnable.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EtherColaTransmitTimeout.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ScanDataScaleFactor.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SensitivityMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SetScanConfigList.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EncSetting.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EncResolution.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ActualEncSpeed.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LEDEnable.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/PowerOnCnt.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DailyOpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/OpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/CurrentTempDev.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DeviceType.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ContaminationConfig.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ContaminationData.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ContaminationActiveSectors.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ContaminationResult.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EnableInertialMeasurementUnit.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/InertialMeasurementUnit.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SyncMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SyncPhase.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/MotorSyncStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ScanDataFormat.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/PortConfiguration.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SetOutput.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/mStartMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/mStandby.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/MeanFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LFPmedianfilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LFPradialDistanceRangeFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SetWebserverEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/FieldEvaluationResult.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ActivateEvaluationGroup.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/SetFieldEvaluationContour.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/GetFieldEvaluationContour.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/FieldEvaluationGroupState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/FieldEvaluationApplicationState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EnableDetectionHistory.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ResetDetectionHistory.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/StartTeachIn.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/StopTeachIn.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ScanMergerEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ScanMergerSource.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/ScanMergeTrigger.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/RotationOffset.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EncoderTransformationType.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EncoderRotation.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/EncoderTranslation.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/StartScanMerge.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/StopScanMerge.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/TSCRole.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/TSCTCSrvAddr.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/TSCTCtimezone.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/TSCTCupdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/DateTime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/mSetDateTime.g.hpp>

