/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file multiScan200.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200/checkCredentials.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/parameterbackup.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/DeviceIdent.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LocationName.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SerialNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/FirmwareVersion.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SetPassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/getChallenge.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/changePassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EnableUserLevel.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/OrderNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/DeviceStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/DeviceName.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/WriteEeprom.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SoftReset.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/RebootDevice.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LoadFactoryDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LoadApplicationDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LastParaDate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LastParaTime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/DoDiagnosisDump.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/GetDiagnosisDumpInfo.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherIPAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherIPGateAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherIPMask.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherAuxEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherCoLaScanMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherAddressingMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherDHCPFallback.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EthernetUpdate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherIPAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherIPGateAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherIPMaskDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/httpsStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/certificateBundleInfo.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/removeCertificateBundle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/setCertificateBundle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SetWebserverEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/GetWebserverEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EnableLegacyUserLevel.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherMACAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/PowerOnCnt.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/DailyOpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/OpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/DeviceType.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/RunFirmwareUpdate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/UpdateState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/CreateParameterBackup.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SCdevicestate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/dataOutputMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LFPintervalFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/horizontalAngleRangeFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/verticalAngleRangeFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/compactSerializationContent.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SensorPosition.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/rosFrameId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/rosParentFrameId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/rosPointCloud2Content.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/rosNamespace.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/mStartMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/mStopMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/AutoStartMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/InertialMeasurementUnit.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/PortConfiguration.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SetOutput.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/InputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/OutputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/PortState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/mResetOutputCounter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LEDState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LEDEnable.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/FindMe.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/ScanConfig.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/PerformanceProfileNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/horizontalFieldOfViewStartAngle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/bloomingFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/particleFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/ambientPixelCountVertical.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/SensitivityMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/FREchoFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/temperatureAlarmConfiguration.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/temperatureAlarmStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/CurrentTempDev.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/TSCRole.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/TSCTCSrvAddr.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/TSCTCtimezone.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/TSCTCupdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LSPdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/LSPsetdatetime.g.hpp>

