/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file 0_9_0.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/checkCredentials.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/parameterbackup.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/DeviceIdent.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LocationName.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SerialNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/FirmwareVersion.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SetPassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/getChallenge.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/changePassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EnableUserLevel.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/OrderNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/DeviceStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/DeviceName.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/WriteEeprom.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SoftReset.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/RebootDevice.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LoadFactoryDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LoadApplicationDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LastParaDate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LastParaTime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/DoDiagnosisDump.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/GetDiagnosisDumpInfo.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherIPAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherIPGateAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherIPMask.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherAuxEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherCoLaScanMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherAddressingMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherDHCPFallback.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EthernetUpdate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherIPAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherIPGateAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherIPMaskDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/httpsStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/certificateBundleInfo.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/removeCertificateBundle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/setCertificateBundle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SetWebserverEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/GetWebserverEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EnableLegacyUserLevel.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/EtherMACAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/PowerOnCnt.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/DailyOpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/OpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/DeviceType.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/RunFirmwareUpdate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/UpdateState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/CreateParameterBackup.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SCdevicestate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/ContaminationConfig.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/ContaminationActiveSectors.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/ContaminationData.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/ContaminationResult.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/dataOutputMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/compactScanDataTelegramType.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LFPintervalFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/horizontalAngleRangeFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/verticalAngleRangeFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/compactTelegramType6Content.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/compactSerializationContent.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SensorPosition.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/rosFrameId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/rosParentFrameId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/rosPointCloud2Content.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/rosNamespace.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/rosDomainId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/mStartMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/mStopMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/AutoStartMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/InertialMeasurementUnit.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/PortConfiguration.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SetOutput.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/InputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/OutputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/PortState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/mResetOutputCounter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LEDState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LEDEnable.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/FindMe.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/ScanConfig.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/PerformanceProfileNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/horizontalFieldOfViewCenterAngle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/bloomingFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/particleFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/ambientPixelCountVertical.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/SensitivityMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/FREchoFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/temperatureAlarmConfiguration.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/temperatureAlarmStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/CurrentTempDev.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/TSCRole.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/TSCTCSrvAddr.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/TSCTCtimezone.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/TSCTCupdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LSPdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/LSPsetdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0/setDateTimeUTC.g.hpp>

