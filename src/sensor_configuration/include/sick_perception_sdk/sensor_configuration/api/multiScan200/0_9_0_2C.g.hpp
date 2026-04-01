/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file 0_9_0_2C.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/checkCredentials.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/parameterbackup.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DeviceIdent.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LocationName.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SerialNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/FirmwareVersion.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SetPassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/getChallenge.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/changePassword.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EnableUserLevel.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/OrderNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DeviceStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DeviceName.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/WriteEeprom.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SoftReset.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/RebootDevice.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LoadFactoryDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LoadApplicationDefaults.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LastParaDate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LastParaTime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DoDiagnosisDump.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/GetDiagnosisDumpInfo.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPGateAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPMask.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherAuxEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherCoLaScanMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherAddressingMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherDHCPFallback.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EthernetUpdate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPGateAddressDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPMaskDHCP.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/httpsStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/certificateBundleInfo.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/removeCertificateBundle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/setCertificateBundle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SetWebserverEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/GetWebserverEnabled.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EnableLegacyUserLevel.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherMACAddress.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/PowerOnCnt.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DailyOpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/OpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DeviceType.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/RunFirmwareUpdate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/UpdateState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/CreateParameterBackup.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SCdevicestate.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ContaminationConfig.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ContaminationActiveSectors.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ContaminationData.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ContaminationResult.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/treatBlockedSectorsAsErrorSectors.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/dataOutputMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/compactScanDataTelegramType.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LFPintervalFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/horizontalAngleRangeFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/verticalAngleRangeFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/compactTelegramType6Content.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/compactSerializationContent.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SensorPosition.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/rosFrameId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/rosParentFrameId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/rosPointCloud2Content.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/rosNamespace.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/rosDomainId.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/mStartMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/mStopMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/AutoStartMeasure.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/InertialMeasurementUnit.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/PortConfiguration.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SetOutput.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/InputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/OutputState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/PortState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/mResetOutputCounter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LEDState.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LEDEnable.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/FindMe.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ScanConfig.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/PerformanceProfileNumber.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/horizontalFieldOfViewCenterAngle.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/bloomingFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/particleFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ambientPixelCountVertical.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SensitivityMode.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/FREchoFilter.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/temperatureAlarmConfiguration.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/temperatureAlarmStatus.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/CurrentTempDev.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCRole.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCTCSrvAddr.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCTCtimezone.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCTCupdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LSPdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LSPsetdatetime.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/setDateTimeUTC.g.hpp>

