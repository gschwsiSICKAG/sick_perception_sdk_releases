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

#include <sick_perception_sdk/sensor_configuration/api/LRS4000.g.hpp>
#include <nlohmann/json.hpp>

namespace sick::srt::LRS4000 {

inline void to_json(nlohmann::ordered_json& j, DeviceIdent::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Name", obj._Name},
      {"Version", obj._Version},
  };
}

inline void from_json(const nlohmann::json& j, DeviceIdent::Get::Response& obj)
{
  j.at("Name").get_to(obj._Name);
  j.at("Version").get_to(obj._Version);
}


inline void to_json(nlohmann::ordered_json& j, LocationName::Get::Response const& obj)
{
  j = obj._LocationName;
}

inline void from_json(const nlohmann::json& j, LocationName::Get::Response& obj)
{
  j.get_to(obj._LocationName);
}


inline void to_json(nlohmann::ordered_json& j, LocationName::Post::Request const& obj)
{
  j = obj._LocationName;
}

inline void from_json(const nlohmann::json& j, LocationName::Post::Request& obj)
{
  j.get_to(obj._LocationName);
}


inline void to_json(nlohmann::ordered_json& j, SerialNumber::Get::Response const& obj)
{
  j = obj._SerialNumber;
}

inline void from_json(const nlohmann::json& j, SerialNumber::Get::Response& obj)
{
  j.get_to(obj._SerialNumber);
}


inline void to_json(nlohmann::ordered_json& j, FirmwareVersion::Get::Response const& obj)
{
  j = obj._FirmwareVersion;
}

inline void from_json(const nlohmann::json& j, FirmwareVersion::Get::Response& obj)
{
  j.get_to(obj._FirmwareVersion);
}


inline void to_json(nlohmann::ordered_json& j, SetPassword::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"siUserLevel", obj._siUserLevel},
      {"udiNewPassword", obj._udiNewPassword},
  };
}

inline void from_json(const nlohmann::json& j, SetPassword::Post::Request& obj)
{
  j.at("siUserLevel").get_to(obj._siUserLevel);
  j.at("udiNewPassword").get_to(obj._udiNewPassword);
}


inline void to_json(nlohmann::ordered_json& j, SetPassword::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bSuccess", obj._bSuccess},
  };
}

inline void from_json(const nlohmann::json& j, SetPassword::Post::Response& obj)
{
  j.at("bSuccess").get_to(obj._bSuccess);
}


inline void to_json(nlohmann::ordered_json& j, getChallenge::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"user", obj._user},
  };
}

inline void from_json(const nlohmann::json& j, getChallenge::Post::Request& obj)
{
  j.at("user").get_to(obj._user);
}


inline void to_json(nlohmann::ordered_json& j, changePassword::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"encryptedMessage", obj._encryptedMessage},
      {"userLevel", obj._userLevel},
  };
}

inline void from_json(const nlohmann::json& j, changePassword::Post::Request& obj)
{
  j.at("encryptedMessage").get_to(obj._encryptedMessage);
  j.at("userLevel").get_to(obj._userLevel);
}


inline void to_json(nlohmann::ordered_json& j, changePassword::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
  };
}

inline void from_json(const nlohmann::json& j, changePassword::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
}


inline void to_json(nlohmann::ordered_json& j, FindMe::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"uiDuration", obj._uiDuration},
  };
}

inline void from_json(const nlohmann::json& j, FindMe::Post::Request& obj)
{
  j.at("uiDuration").get_to(obj._uiDuration);
}


inline void to_json(nlohmann::ordered_json& j, OrderNumber::Get::Response const& obj)
{
  j = obj._OrderNumber;
}

inline void from_json(const nlohmann::json& j, OrderNumber::Get::Response& obj)
{
  j.get_to(obj._OrderNumber);
}


inline void to_json(nlohmann::ordered_json& j, DeviceStatus::Get::Response const& obj)
{
  j = obj._DeviceStatus;
}

inline void from_json(const nlohmann::json& j, DeviceStatus::Get::Response& obj)
{
  j.get_to(obj._DeviceStatus);
}


inline void to_json(nlohmann::ordered_json& j, WriteEeprom::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, WriteEeprom::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, SCdevicestate::Get::Response const& obj)
{
  j = obj._SCdevicestate;
}

inline void from_json(const nlohmann::json& j, SCdevicestate::Get::Response& obj)
{
  j.get_to(obj._SCdevicestate);
}


inline void to_json(nlohmann::ordered_json& j, SoftReset::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"ProcessorNbr", obj._ProcessorNbr},
  };
}

inline void from_json(const nlohmann::json& j, SoftReset::Post::Request& obj)
{
  j.at("ProcessorNbr").get_to(obj._ProcessorNbr);
}


inline void to_json(nlohmann::ordered_json& j, LastParaDate::Get::Response const& obj)
{
  j = obj._LastParaDate;
}

inline void from_json(const nlohmann::json& j, LastParaDate::Get::Response& obj)
{
  j.get_to(obj._LastParaDate);
}


inline void to_json(nlohmann::ordered_json& j, LastParaTime::Get::Response const& obj)
{
  j = obj._LastParaTime;
}

inline void from_json(const nlohmann::json& j, LastParaTime::Get::Response& obj)
{
  j.get_to(obj._LastParaTime);
}


inline void to_json(nlohmann::ordered_json& j, DoDiagnosisDump::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"DoRunlevelLoop", obj._DoRunlevelLoop},
      {"Output", obj._Output},
  };
}

inline void from_json(const nlohmann::json& j, DoDiagnosisDump::Post::Request& obj)
{
  j.at("DoRunlevelLoop").get_to(obj._DoRunlevelLoop);
  j.at("Output").get_to(obj._Output);
}


inline void to_json(nlohmann::ordered_json& j, DoDiagnosisDump::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Successfull", obj._Successfull},
  };
}

inline void from_json(const nlohmann::json& j, DoDiagnosisDump::Post::Response& obj)
{
  j.at("Successfull").get_to(obj._Successfull);
}


inline void to_json(nlohmann::ordered_json& j, GetDiagnosisDumpInfo::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"DiagDumpExists", obj._DiagDumpExists},
      {"DiagDumpTimestamp", obj._DiagDumpTimestamp},
  };
}

inline void from_json(const nlohmann::json& j, GetDiagnosisDumpInfo::Post::Response& obj)
{
  j.at("DiagDumpExists").get_to(obj._DiagDumpExists);
  j.at("DiagDumpTimestamp").get_to(obj._DiagDumpTimestamp);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPAddress::Get::Response const& obj)
{
  j = obj._EtherIPAddress;
}

inline void from_json(const nlohmann::json& j, EtherIPAddress::Get::Response& obj)
{
  j.get_to(obj._EtherIPAddress);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPAddress::Post::Request const& obj)
{
  j = obj._EtherIPAddress;
}

inline void from_json(const nlohmann::json& j, EtherIPAddress::Post::Request& obj)
{
  j.get_to(obj._EtherIPAddress);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPGateAddress::Get::Response const& obj)
{
  j = obj._EtherIPGateAddress;
}

inline void from_json(const nlohmann::json& j, EtherIPGateAddress::Get::Response& obj)
{
  j.get_to(obj._EtherIPGateAddress);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPGateAddress::Post::Request const& obj)
{
  j = obj._EtherIPGateAddress;
}

inline void from_json(const nlohmann::json& j, EtherIPGateAddress::Post::Request& obj)
{
  j.get_to(obj._EtherIPGateAddress);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPMask::Get::Response const& obj)
{
  j = obj._EtherIPMask;
}

inline void from_json(const nlohmann::json& j, EtherIPMask::Get::Response& obj)
{
  j.get_to(obj._EtherIPMask);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPMask::Post::Request const& obj)
{
  j = obj._EtherIPMask;
}

inline void from_json(const nlohmann::json& j, EtherIPMask::Post::Request& obj)
{
  j.get_to(obj._EtherIPMask);
}


inline void to_json(nlohmann::ordered_json& j, EtherAuxEnabled::Get::Response const& obj)
{
  j = obj._EtherAuxEnabled;
}

inline void from_json(const nlohmann::json& j, EtherAuxEnabled::Get::Response& obj)
{
  j.get_to(obj._EtherAuxEnabled);
}


inline void to_json(nlohmann::ordered_json& j, EtherAuxEnabled::Post::Request const& obj)
{
  j = obj._EtherAuxEnabled;
}

inline void from_json(const nlohmann::json& j, EtherAuxEnabled::Post::Request& obj)
{
  j.get_to(obj._EtherAuxEnabled);
}


inline void to_json(nlohmann::ordered_json& j, EtherAddressingMode::Get::Response const& obj)
{
  j = obj._EtherAddressingMode;
}

inline void from_json(const nlohmann::json& j, EtherAddressingMode::Get::Response& obj)
{
  j.get_to(obj._EtherAddressingMode);
}


inline void to_json(nlohmann::ordered_json& j, EtherAddressingMode::Post::Request const& obj)
{
  j = obj._EtherAddressingMode;
}

inline void from_json(const nlohmann::json& j, EtherAddressingMode::Post::Request& obj)
{
  j.get_to(obj._EtherAddressingMode);
}


inline void to_json(nlohmann::ordered_json& j, EtherDHCPFallback::Get::Response const& obj)
{
  j = obj._EtherDHCPFallback;
}

inline void from_json(const nlohmann::json& j, EtherDHCPFallback::Get::Response& obj)
{
  j.get_to(obj._EtherDHCPFallback);
}


inline void to_json(nlohmann::ordered_json& j, EtherDHCPFallback::Post::Request const& obj)
{
  j = obj._EtherDHCPFallback;
}

inline void from_json(const nlohmann::json& j, EtherDHCPFallback::Post::Request& obj)
{
  j.get_to(obj._EtherDHCPFallback);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPAddressDHCP::Get::Response const& obj)
{
  j = obj._EtherIPAddressDHCP;
}

inline void from_json(const nlohmann::json& j, EtherIPAddressDHCP::Get::Response& obj)
{
  j.get_to(obj._EtherIPAddressDHCP);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPGateAddressDHCP::Get::Response const& obj)
{
  j = obj._EtherIPGateAddressDHCP;
}

inline void from_json(const nlohmann::json& j, EtherIPGateAddressDHCP::Get::Response& obj)
{
  j.get_to(obj._EtherIPGateAddressDHCP);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPMaskDHCP::Get::Response const& obj)
{
  j = obj._EtherIPMaskDHCP;
}

inline void from_json(const nlohmann::json& j, EtherIPMaskDHCP::Get::Response& obj)
{
  j.get_to(obj._EtherIPMaskDHCP);
}


inline void to_json(nlohmann::ordered_json& j, ScanConfig::Get::Response::ScanRange::aRangeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"udiAngleRes", obj._udiAngleRes.value()},
      {"diStartAngle", obj._diStartAngle.value()},
      {"diStopAngle", obj._diStopAngle.value()},
  };
}

inline void from_json(const nlohmann::json& j, ScanConfig::Get::Response::ScanRange::aRangeItem& obj)
{
  j.at("udiAngleRes").get_to(obj._udiAngleRes);
  j.at("diStartAngle").get_to(obj._diStartAngle);
  j.at("diStopAngle").get_to(obj._diStopAngle);
}

inline void to_json(nlohmann::ordered_json& j, ScanConfig::Get::Response::ScanRange const& obj)
{
  j = nlohmann::ordered_json{
      {"uiLength", obj._uiLength.value()},
      {"aRange", obj._aRange},
  };
}

inline void from_json(const nlohmann::json& j, ScanConfig::Get::Response::ScanRange& obj)
{
  j.at("uiLength").get_to(obj._uiLength);
  j.at("aRange").get_to(obj._aRange);
}

inline void to_json(nlohmann::ordered_json& j, ScanConfig::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"udiScanFreq", obj._udiScanFreq.value()},
      {"ScanRange", obj._ScanRange},
  };
}

inline void from_json(const nlohmann::json& j, ScanConfig::Get::Response& obj)
{
  j.at("udiScanFreq").get_to(obj._udiScanFreq);
  j.at("ScanRange").get_to(obj._ScanRange);
}


inline void to_json(nlohmann::ordered_json& j, DataOutputRange::Get::Response::aRangeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"udiAngleRes", obj._udiAngleRes.value()},
      {"diStartAngle", obj._diStartAngle.value()},
      {"diStopAngle", obj._diStopAngle.value()},
  };
}

inline void from_json(const nlohmann::json& j, DataOutputRange::Get::Response::aRangeItem& obj)
{
  j.at("udiAngleRes").get_to(obj._udiAngleRes);
  j.at("diStartAngle").get_to(obj._diStartAngle);
  j.at("diStopAngle").get_to(obj._diStopAngle);
}

inline void to_json(nlohmann::ordered_json& j, DataOutputRange::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"uiLength", obj._uiLength.value()},
      {"aRange", obj._aRange},
  };
}

inline void from_json(const nlohmann::json& j, DataOutputRange::Get::Response& obj)
{
  j.at("uiLength").get_to(obj._uiLength);
  j.at("aRange").get_to(obj._aRange);
}


inline void to_json(nlohmann::ordered_json& j, DataOutputRange::Post::Request::aRangeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"udiAngleRes", obj._udiAngleRes.value()},
      {"diStartAngle", obj._diStartAngle.value()},
      {"diStopAngle", obj._diStopAngle.value()},
  };
}

inline void from_json(const nlohmann::json& j, DataOutputRange::Post::Request::aRangeItem& obj)
{
  j.at("udiAngleRes").get_to(obj._udiAngleRes);
  j.at("diStartAngle").get_to(obj._diStartAngle);
  j.at("diStopAngle").get_to(obj._diStopAngle);
}

inline void to_json(nlohmann::ordered_json& j, DataOutputRange::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"uiLength", obj._uiLength.value()},
      {"aRange", obj._aRange},
  };
}

inline void from_json(const nlohmann::json& j, DataOutputRange::Post::Request& obj)
{
  j.at("uiLength").get_to(obj._uiLength);
  j.at("aRange").get_to(obj._aRange);
}


inline void to_json(nlohmann::ordered_json& j, InputState::Get::Response::aDigitalInItem::IOState const& obj)
{
  j = nlohmann::ordered_json{
      {"eIOState", obj._eIOState},
  };
}

inline void from_json(const nlohmann::json& j, InputState::Get::Response::aDigitalInItem::IOState& obj)
{
  j.at("eIOState").get_to(obj._eIOState);
}

inline void to_json(nlohmann::ordered_json& j, InputState::Get::Response::aDigitalInItem const& obj)
{
  j = nlohmann::ordered_json{
      {"IOState", obj._IOState},
  };
}

inline void from_json(const nlohmann::json& j, InputState::Get::Response::aDigitalInItem& obj)
{
  j.at("IOState").get_to(obj._IOState);
}

inline void to_json(nlohmann::ordered_json& j, InputState::Get::Response::aTimeBlockItem const& obj)
{
  j = nlohmann::ordered_json{
      {"uiYear", obj._uiYear.value()},
      {"usiMonth", obj._usiMonth.value()},
      {"usiDay", obj._usiDay.value()},
      {"usiHour", obj._usiHour.value()},
      {"usiMinute", obj._usiMinute.value()},
      {"usiSec", obj._usiSec.value()},
      {"udiUSec", obj._udiUSec.value()},
  };
}

inline void from_json(const nlohmann::json& j, InputState::Get::Response::aTimeBlockItem& obj)
{
  j.at("uiYear").get_to(obj._uiYear);
  j.at("usiMonth").get_to(obj._usiMonth);
  j.at("usiDay").get_to(obj._usiDay);
  j.at("usiHour").get_to(obj._usiHour);
  j.at("usiMinute").get_to(obj._usiMinute);
  j.at("usiSec").get_to(obj._usiSec);
  j.at("udiUSec").get_to(obj._udiUSec);
}

inline void to_json(nlohmann::ordered_json& j, InputState::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"uiVersionNumber", obj._uiVersionNumber},
      {"udiSystCount", obj._udiSystCount},
      {"aDigitalIn", obj._aDigitalIn},
      {"aTimeBlock", obj._aTimeBlock},
  };
}

inline void from_json(const nlohmann::json& j, InputState::Get::Response& obj)
{
  j.at("uiVersionNumber").get_to(obj._uiVersionNumber);
  j.at("udiSystCount").get_to(obj._udiSystCount);
  j.at("aDigitalIn").get_to(obj._aDigitalIn);
  j.at("aTimeBlock").get_to(obj._aTimeBlock);
}


inline void to_json(nlohmann::ordered_json& j, OutputState::Get::Response::aDigitalOutItem::IOState const& obj)
{
  j = nlohmann::ordered_json{
      {"eIOState", obj._eIOState},
  };
}

inline void from_json(const nlohmann::json& j, OutputState::Get::Response::aDigitalOutItem::IOState& obj)
{
  j.at("eIOState").get_to(obj._eIOState);
}

inline void to_json(nlohmann::ordered_json& j, OutputState::Get::Response::aDigitalOutItem const& obj)
{
  j = nlohmann::ordered_json{
      {"IOState", obj._IOState},
      {"udiCounter", obj._udiCounter},
  };
}

inline void from_json(const nlohmann::json& j, OutputState::Get::Response::aDigitalOutItem& obj)
{
  j.at("IOState").get_to(obj._IOState);
  j.at("udiCounter").get_to(obj._udiCounter);
}

inline void to_json(nlohmann::ordered_json& j, OutputState::Get::Response::aTimeBlockItem const& obj)
{
  j = nlohmann::ordered_json{
      {"uiYear", obj._uiYear.value()},
      {"usiMonth", obj._usiMonth.value()},
      {"usiDay", obj._usiDay.value()},
      {"usiHour", obj._usiHour.value()},
      {"usiMinute", obj._usiMinute.value()},
      {"usiSec", obj._usiSec.value()},
      {"udiUSec", obj._udiUSec.value()},
  };
}

inline void from_json(const nlohmann::json& j, OutputState::Get::Response::aTimeBlockItem& obj)
{
  j.at("uiYear").get_to(obj._uiYear);
  j.at("usiMonth").get_to(obj._usiMonth);
  j.at("usiDay").get_to(obj._usiDay);
  j.at("usiHour").get_to(obj._usiHour);
  j.at("usiMinute").get_to(obj._usiMinute);
  j.at("usiSec").get_to(obj._usiSec);
  j.at("udiUSec").get_to(obj._udiUSec);
}

inline void to_json(nlohmann::ordered_json& j, OutputState::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"uiVersionNumber", obj._uiVersionNumber},
      {"udiSystCount", obj._udiSystCount},
      {"aDigitalOut", obj._aDigitalOut},
      {"aTimeBlock", obj._aTimeBlock},
  };
}

inline void from_json(const nlohmann::json& j, OutputState::Get::Response& obj)
{
  j.at("uiVersionNumber").get_to(obj._uiVersionNumber);
  j.at("udiSystCount").get_to(obj._udiSystCount);
  j.at("aDigitalOut").get_to(obj._aDigitalOut);
  j.at("aTimeBlock").get_to(obj._aTimeBlock);
}


inline void to_json(nlohmann::ordered_json& j, PortState::Get::Response::aInternalPortsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"ePortState", obj._ePortState},
      {"PortCounter", obj._PortCounter},
  };
}

inline void from_json(const nlohmann::json& j, PortState::Get::Response::aInternalPortsItem& obj)
{
  j.at("ePortState").get_to(obj._ePortState);
  j.at("PortCounter").get_to(obj._PortCounter);
}

inline void to_json(nlohmann::ordered_json& j, PortState::Get::Response::aExternalPortsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"ePortState", obj._ePortState},
      {"PortCounter", obj._PortCounter},
  };
}

inline void from_json(const nlohmann::json& j, PortState::Get::Response::aExternalPortsItem& obj)
{
  j.at("ePortState").get_to(obj._ePortState);
  j.at("PortCounter").get_to(obj._PortCounter);
}

inline void to_json(nlohmann::ordered_json& j, PortState::Get::Response::aTimeBlockItem const& obj)
{
  j = nlohmann::ordered_json{
      {"uiYear", obj._uiYear.value()},
      {"usiMonth", obj._usiMonth.value()},
      {"usiDay", obj._usiDay.value()},
      {"usiHour", obj._usiHour.value()},
      {"usiMinute", obj._usiMinute.value()},
      {"usiSec", obj._usiSec.value()},
      {"udiUSec", obj._udiUSec.value()},
  };
}

inline void from_json(const nlohmann::json& j, PortState::Get::Response::aTimeBlockItem& obj)
{
  j.at("uiYear").get_to(obj._uiYear);
  j.at("usiMonth").get_to(obj._usiMonth);
  j.at("usiDay").get_to(obj._usiDay);
  j.at("usiHour").get_to(obj._usiHour);
  j.at("usiMinute").get_to(obj._usiMinute);
  j.at("usiSec").get_to(obj._usiSec);
  j.at("udiUSec").get_to(obj._udiUSec);
}

inline void to_json(nlohmann::ordered_json& j, PortState::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"uiVersionNumber", obj._uiVersionNumber},
      {"udiSystCount", obj._udiSystCount},
      {"aInternalPorts", obj._aInternalPorts},
      {"aExternalPorts", obj._aExternalPorts},
      {"aTimeBlock", obj._aTimeBlock},
  };
}

inline void from_json(const nlohmann::json& j, PortState::Get::Response& obj)
{
  j.at("uiVersionNumber").get_to(obj._uiVersionNumber);
  j.at("udiSystCount").get_to(obj._udiSystCount);
  j.at("aInternalPorts").get_to(obj._aInternalPorts);
  j.at("aExternalPorts").get_to(obj._aExternalPorts);
  j.at("aTimeBlock").get_to(obj._aTimeBlock);
}


inline void to_json(nlohmann::ordered_json& j, mResetOutputCounter::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, mResetOutputCounter::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


inline void to_json(nlohmann::ordered_json& j, DeviceTime::Get::Response const& obj)
{
  j = obj._DeviceTime;
}

inline void from_json(const nlohmann::json& j, DeviceTime::Get::Response& obj)
{
  j.get_to(obj._DeviceTime);
}


inline void to_json(nlohmann::ordered_json& j, FREchoFilter::Get::Response const& obj)
{
  j = obj._FREchoFilter;
}

inline void from_json(const nlohmann::json& j, FREchoFilter::Get::Response& obj)
{
  j.get_to(obj._FREchoFilter);
}


inline void to_json(nlohmann::ordered_json& j, FREchoFilter::Post::Request const& obj)
{
  j = obj._FREchoFilter;
}

inline void from_json(const nlohmann::json& j, FREchoFilter::Post::Request& obj)
{
  j.get_to(obj._FREchoFilter);
}


inline void to_json(nlohmann::ordered_json& j, ParticleFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiThreshold", obj._uiThreshold.value()},
  };
}

inline void from_json(const nlohmann::json& j, ParticleFilter::Get::Response& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiThreshold").get_to(obj._uiThreshold);
}


inline void to_json(nlohmann::ordered_json& j, ParticleFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiThreshold", obj._uiThreshold.value()},
  };
}

inline void from_json(const nlohmann::json& j, ParticleFilter::Post::Request& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiThreshold").get_to(obj._uiThreshold);
}


inline void to_json(nlohmann::ordered_json& j, EtherMACAddress::Get::Response const& obj)
{
  j = obj._EtherMACAddress;
}

inline void from_json(const nlohmann::json& j, EtherMACAddress::Get::Response& obj)
{
  j.get_to(obj._EtherMACAddress);
}


inline void to_json(nlohmann::ordered_json& j, EnableColaScan::Get::Response const& obj)
{
  j = obj._EnableColaScan;
}

inline void from_json(const nlohmann::json& j, EnableColaScan::Get::Response& obj)
{
  j.get_to(obj._EnableColaScan);
}


inline void to_json(nlohmann::ordered_json& j, EnableColaScan::Post::Request const& obj)
{
  j = obj._EnableColaScan;
}

inline void from_json(const nlohmann::json& j, EnableColaScan::Post::Request& obj)
{
  j.get_to(obj._EnableColaScan);
}


inline void to_json(nlohmann::ordered_json& j, EtherCoLaAEventsEnable::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EtherCoLaAEventsEnable", obj._EtherCoLaAEventsEnable},
  };
}

inline void from_json(const nlohmann::json& j, EtherCoLaAEventsEnable::Post::Request& obj)
{
  j.at("EtherCoLaAEventsEnable").get_to(obj._EtherCoLaAEventsEnable);
}


inline void to_json(nlohmann::ordered_json& j, EtherColaTransmitTimeout::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EtherColaTransmitTimeout", obj._EtherColaTransmitTimeout.value()},
  };
}

inline void from_json(const nlohmann::json& j, EtherColaTransmitTimeout::Post::Request& obj)
{
  j.at("EtherColaTransmitTimeout").get_to(obj._EtherColaTransmitTimeout);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataScaleFactor::Get::Response const& obj)
{
  j = obj._ScanDataScaleFactor;
}

inline void from_json(const nlohmann::json& j, ScanDataScaleFactor::Get::Response& obj)
{
  j.get_to(obj._ScanDataScaleFactor);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataScaleFactor::Post::Request const& obj)
{
  j = obj._ScanDataScaleFactor;
}

inline void from_json(const nlohmann::json& j, ScanDataScaleFactor::Post::Request& obj)
{
  j.get_to(obj._ScanDataScaleFactor);
}


inline void to_json(nlohmann::ordered_json& j, SensitivityMode::Get::Response const& obj)
{
  j = obj._SensitivityMode;
}

inline void from_json(const nlohmann::json& j, SensitivityMode::Get::Response& obj)
{
  j.get_to(obj._SensitivityMode);
}


inline void to_json(nlohmann::ordered_json& j, SensitivityMode::Post::Request const& obj)
{
  j = obj._SensitivityMode;
}

inline void from_json(const nlohmann::json& j, SensitivityMode::Post::Request& obj)
{
  j.get_to(obj._SensitivityMode);
}


inline void to_json(nlohmann::ordered_json& j, SetScanConfigList::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"ScanConfigList", obj._ScanConfigList},
  };
}

inline void from_json(const nlohmann::json& j, SetScanConfigList::Post::Request& obj)
{
  j.at("ScanConfigList").get_to(obj._ScanConfigList);
}


inline void to_json(nlohmann::ordered_json& j, SetScanConfigList::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"eScanConfigError", obj._eScanConfigError},
  };
}

inline void from_json(const nlohmann::json& j, SetScanConfigList::Post::Response& obj)
{
  j.at("eScanConfigError").get_to(obj._eScanConfigError);
}


inline void to_json(nlohmann::ordered_json& j, EncSetting::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EncSetting", obj._EncSetting},
  };
}

inline void from_json(const nlohmann::json& j, EncSetting::Post::Request& obj)
{
  j.at("EncSetting").get_to(obj._EncSetting);
}


inline void to_json(nlohmann::ordered_json& j, EncResolution::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EncResolution", obj._EncResolution},
  };
}

inline void from_json(const nlohmann::json& j, EncResolution::Post::Request& obj)
{
  j.at("EncResolution").get_to(obj._EncResolution);
}


inline void to_json(nlohmann::ordered_json& j, ActualEncSpeed::Get::Response const& obj)
{
  j = obj._ActualEncSpeed;
}

inline void from_json(const nlohmann::json& j, ActualEncSpeed::Get::Response& obj)
{
  j.get_to(obj._ActualEncSpeed);
}


inline void to_json(nlohmann::ordered_json& j, LEDEnable::Get::Response const& obj)
{
  j = obj._LEDEnable;
}

inline void from_json(const nlohmann::json& j, LEDEnable::Get::Response& obj)
{
  j.get_to(obj._LEDEnable);
}


inline void to_json(nlohmann::ordered_json& j, LEDEnable::Post::Request const& obj)
{
  j = obj._LEDEnable;
}

inline void from_json(const nlohmann::json& j, LEDEnable::Post::Request& obj)
{
  j.get_to(obj._LEDEnable);
}


inline void to_json(nlohmann::ordered_json& j, PowerOnCnt::Get::Response const& obj)
{
  j = obj._PowerOnCnt;
}

inline void from_json(const nlohmann::json& j, PowerOnCnt::Get::Response& obj)
{
  j.get_to(obj._PowerOnCnt);
}


inline void to_json(nlohmann::ordered_json& j, DailyOpHours::Get::Response const& obj)
{
  j = obj._DailyOpHours;
}

inline void from_json(const nlohmann::json& j, DailyOpHours::Get::Response& obj)
{
  j.get_to(obj._DailyOpHours);
}


inline void to_json(nlohmann::ordered_json& j, OpHours::Get::Response const& obj)
{
  j = obj._OpHours;
}

inline void from_json(const nlohmann::json& j, OpHours::Get::Response& obj)
{
  j.get_to(obj._OpHours);
}


inline void to_json(nlohmann::ordered_json& j, CurrentTempDev::Get::Response const& obj)
{
  j = obj._CurrentTempDev;
}

inline void from_json(const nlohmann::json& j, CurrentTempDev::Get::Response& obj)
{
  j.get_to(obj._CurrentTempDev);
}


inline void to_json(nlohmann::ordered_json& j, DeviceType::Get::Response const& obj)
{
  j = obj._DeviceType;
}

inline void from_json(const nlohmann::json& j, DeviceType::Get::Response& obj)
{
  j.get_to(obj._DeviceType);
}


inline void to_json(nlohmann::ordered_json& j, ContaminationConfig::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"eStrategy", obj._eStrategy},
      {"usiResponseTime", obj._usiResponseTime.value()},
      {"eThreshold", obj._eThreshold},
      {"eCover", obj._eCover},
      {"CustomSectors", obj._CustomSectors},
      {"bEnableWarning", obj._bEnableWarning},
      {"bEnableError", obj._bEnableError},
  };
}

inline void from_json(const nlohmann::json& j, ContaminationConfig::Get::Response& obj)
{
  j.at("eStrategy").get_to(obj._eStrategy);
  j.at("usiResponseTime").get_to(obj._usiResponseTime);
  j.at("eThreshold").get_to(obj._eThreshold);
  j.at("eCover").get_to(obj._eCover);
  j.at("CustomSectors").get_to(obj._CustomSectors);
  j.at("bEnableWarning").get_to(obj._bEnableWarning);
  j.at("bEnableError").get_to(obj._bEnableError);
}


inline void to_json(nlohmann::ordered_json& j, ContaminationConfig::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"eStrategy", obj._eStrategy},
      {"usiResponseTime", obj._usiResponseTime.value()},
      {"eThreshold", obj._eThreshold},
      {"eCover", obj._eCover},
      {"CustomSectors", obj._CustomSectors},
      {"bEnableWarning", obj._bEnableWarning},
      {"bEnableError", obj._bEnableError},
  };
}

inline void from_json(const nlohmann::json& j, ContaminationConfig::Post::Request& obj)
{
  j.at("eStrategy").get_to(obj._eStrategy);
  j.at("usiResponseTime").get_to(obj._usiResponseTime);
  j.at("eThreshold").get_to(obj._eThreshold);
  j.at("eCover").get_to(obj._eCover);
  j.at("CustomSectors").get_to(obj._CustomSectors);
  j.at("bEnableWarning").get_to(obj._bEnableWarning);
  j.at("bEnableError").get_to(obj._bEnableError);
}


inline void to_json(nlohmann::ordered_json& j, ContaminationData::Get::Response const& obj)
{
  j = obj._ContaminationData;
}

inline void from_json(const nlohmann::json& j, ContaminationData::Get::Response& obj)
{
  j.get_to(obj._ContaminationData);
}


inline void to_json(nlohmann::ordered_json& j, ContaminationActiveSectors::Get::Response const& obj)
{
  j = obj._ContaminationActiveSectors;
}

inline void from_json(const nlohmann::json& j, ContaminationActiveSectors::Get::Response& obj)
{
  j.get_to(obj._ContaminationActiveSectors);
}


inline void to_json(nlohmann::ordered_json& j, ContaminationResult::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"warningActive", obj._warningActive},
      {"errorActive", obj._errorActive},
  };
}

inline void from_json(const nlohmann::json& j, ContaminationResult::Get::Response& obj)
{
  j.at("warningActive").get_to(obj._warningActive);
  j.at("errorActive").get_to(obj._errorActive);
}


inline void to_json(nlohmann::ordered_json& j, EnableInertialMeasurementUnit::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EnableInertialMeasurementUnit", obj._EnableInertialMeasurementUnit},
  };
}

inline void from_json(const nlohmann::json& j, EnableInertialMeasurementUnit::Post::Request& obj)
{
  j.at("EnableInertialMeasurementUnit").get_to(obj._EnableInertialMeasurementUnit);
}


inline void to_json(nlohmann::ordered_json& j, InertialMeasurementUnit::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Acceleration", obj._Acceleration},
      {"AngularVelocity", obj._AngularVelocity},
      {"MagneticField", obj._MagneticField},
      {"Orientation", obj._Orientation},
      {"TimeStamp", obj._TimeStamp},
  };
}

inline void from_json(const nlohmann::json& j, InertialMeasurementUnit::Get::Response& obj)
{
  j.at("Acceleration").get_to(obj._Acceleration);
  j.at("AngularVelocity").get_to(obj._AngularVelocity);
  j.at("MagneticField").get_to(obj._MagneticField);
  j.at("Orientation").get_to(obj._Orientation);
  j.at("TimeStamp").get_to(obj._TimeStamp);
}


inline void to_json(nlohmann::ordered_json& j, SyncMode::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"SyncMode", obj._SyncMode},
  };
}

inline void from_json(const nlohmann::json& j, SyncMode::Post::Request& obj)
{
  j.at("SyncMode").get_to(obj._SyncMode);
}


inline void to_json(nlohmann::ordered_json& j, SyncPhase::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"SyncPhase", obj._SyncPhase.value()},
  };
}

inline void from_json(const nlohmann::json& j, SyncPhase::Post::Request& obj)
{
  j.at("SyncPhase").get_to(obj._SyncPhase);
}


inline void to_json(nlohmann::ordered_json& j, MotorSyncStatus::Get::Response const& obj)
{
  j = obj._MotorSyncStatus;
}

inline void from_json(const nlohmann::json& j, MotorSyncStatus::Get::Response& obj)
{
  j.get_to(obj._MotorSyncStatus);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataFormat::Get::Response const& obj)
{
  j = obj._ScanDataFormat;
}

inline void from_json(const nlohmann::json& j, ScanDataFormat::Get::Response& obj)
{
  j.get_to(obj._ScanDataFormat);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataFormat::Post::Request const& obj)
{
  j = obj._ScanDataFormat;
}

inline void from_json(const nlohmann::json& j, ScanDataFormat::Post::Request& obj)
{
  j.get_to(obj._ScanDataFormat);
}


inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Get::Response::PortConfigurationItem::InputSettings const& obj)
{
  j = nlohmann::ordered_json{
      {"Logic", obj._Logic},
      {"Debounce", obj._Debounce.value()},
      {"Sensitivity", obj._Sensitivity},
      {"Reserved1", obj._Reserved1},
      {"Reserved2", obj._Reserved2},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Get::Response::PortConfigurationItem::InputSettings& obj)
{
  j.at("Logic").get_to(obj._Logic);
  j.at("Debounce").get_to(obj._Debounce);
  j.at("Sensitivity").get_to(obj._Sensitivity);
  j.at("Reserved1").get_to(obj._Reserved1);
  j.at("Reserved2").get_to(obj._Reserved2);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Get::Response::PortConfigurationItem::OutputSettings::SourcesItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Name", obj._Name},
      {"Invert", obj._Invert},
      {"Reserved5", obj._Reserved5},
      {"Reserved6", obj._Reserved6},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Get::Response::PortConfigurationItem::OutputSettings::SourcesItem& obj)
{
  j.at("Name").get_to(obj._Name);
  j.at("Invert").get_to(obj._Invert);
  j.at("Reserved5").get_to(obj._Reserved5);
  j.at("Reserved6").get_to(obj._Reserved6);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Get::Response::PortConfigurationItem::OutputSettings const& obj)
{
  j = nlohmann::ordered_json{
      {"Logic", obj._Logic},
      {"OutputMode", obj._OutputMode},
      {"RestartType", obj._RestartType},
      {"RestartTime", obj._RestartTime.value()},
      {"RestartInput", obj._RestartInput.value()},
      {"Combination", obj._Combination},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
      {"Sources", obj._Sources},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Get::Response::PortConfigurationItem::OutputSettings& obj)
{
  j.at("Logic").get_to(obj._Logic);
  j.at("OutputMode").get_to(obj._OutputMode);
  j.at("RestartType").get_to(obj._RestartType);
  j.at("RestartTime").get_to(obj._RestartTime);
  j.at("RestartInput").get_to(obj._RestartInput);
  j.at("Combination").get_to(obj._Combination);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
  j.at("Sources").get_to(obj._Sources);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Get::Response::PortConfigurationItem const& obj)
{
  j = nlohmann::ordered_json{
      {"PortType", obj._PortType},
      {"Name", obj._Name},
      {"InputSettings", obj._InputSettings},
      {"OutputSettings", obj._OutputSettings},
      {"Reserved7", obj._Reserved7},
      {"Reserved8", obj._Reserved8},
      {"Reserved9", obj._Reserved9},
      {"Reserved10", obj._Reserved10},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Get::Response::PortConfigurationItem& obj)
{
  j.at("PortType").get_to(obj._PortType);
  j.at("Name").get_to(obj._Name);
  j.at("InputSettings").get_to(obj._InputSettings);
  j.at("OutputSettings").get_to(obj._OutputSettings);
  j.at("Reserved7").get_to(obj._Reserved7);
  j.at("Reserved8").get_to(obj._Reserved8);
  j.at("Reserved9").get_to(obj._Reserved9);
  j.at("Reserved10").get_to(obj._Reserved10);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Get::Response const& obj)
{
  j = obj._PortConfiguration;
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Get::Response& obj)
{
  j.get_to(obj._PortConfiguration);
}


inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Post::Request::PortConfigurationItem::InputSettings const& obj)
{
  j = nlohmann::ordered_json{
      {"Logic", obj._Logic},
      {"Debounce", obj._Debounce.value()},
      {"Sensitivity", obj._Sensitivity},
      {"Reserved1", obj._Reserved1},
      {"Reserved2", obj._Reserved2},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Post::Request::PortConfigurationItem::InputSettings& obj)
{
  j.at("Logic").get_to(obj._Logic);
  j.at("Debounce").get_to(obj._Debounce);
  j.at("Sensitivity").get_to(obj._Sensitivity);
  j.at("Reserved1").get_to(obj._Reserved1);
  j.at("Reserved2").get_to(obj._Reserved2);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Post::Request::PortConfigurationItem::OutputSettings::SourcesItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Name", obj._Name},
      {"Invert", obj._Invert},
      {"Reserved5", obj._Reserved5},
      {"Reserved6", obj._Reserved6},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Post::Request::PortConfigurationItem::OutputSettings::SourcesItem& obj)
{
  j.at("Name").get_to(obj._Name);
  j.at("Invert").get_to(obj._Invert);
  j.at("Reserved5").get_to(obj._Reserved5);
  j.at("Reserved6").get_to(obj._Reserved6);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Post::Request::PortConfigurationItem::OutputSettings const& obj)
{
  j = nlohmann::ordered_json{
      {"Logic", obj._Logic},
      {"OutputMode", obj._OutputMode},
      {"RestartType", obj._RestartType},
      {"RestartTime", obj._RestartTime.value()},
      {"RestartInput", obj._RestartInput.value()},
      {"Combination", obj._Combination},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
      {"Sources", obj._Sources},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Post::Request::PortConfigurationItem::OutputSettings& obj)
{
  j.at("Logic").get_to(obj._Logic);
  j.at("OutputMode").get_to(obj._OutputMode);
  j.at("RestartType").get_to(obj._RestartType);
  j.at("RestartTime").get_to(obj._RestartTime);
  j.at("RestartInput").get_to(obj._RestartInput);
  j.at("Combination").get_to(obj._Combination);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
  j.at("Sources").get_to(obj._Sources);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Post::Request::PortConfigurationItem const& obj)
{
  j = nlohmann::ordered_json{
      {"PortType", obj._PortType},
      {"Name", obj._Name},
      {"InputSettings", obj._InputSettings},
      {"OutputSettings", obj._OutputSettings},
      {"Reserved7", obj._Reserved7},
      {"Reserved8", obj._Reserved8},
      {"Reserved9", obj._Reserved9},
      {"Reserved10", obj._Reserved10},
  };
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Post::Request::PortConfigurationItem& obj)
{
  j.at("PortType").get_to(obj._PortType);
  j.at("Name").get_to(obj._Name);
  j.at("InputSettings").get_to(obj._InputSettings);
  j.at("OutputSettings").get_to(obj._OutputSettings);
  j.at("Reserved7").get_to(obj._Reserved7);
  j.at("Reserved8").get_to(obj._Reserved8);
  j.at("Reserved9").get_to(obj._Reserved9);
  j.at("Reserved10").get_to(obj._Reserved10);
}

inline void to_json(nlohmann::ordered_json& j, PortConfiguration::Post::Request const& obj)
{
  j = obj._PortConfiguration;
}

inline void from_json(const nlohmann::json& j, PortConfiguration::Post::Request& obj)
{
  j.get_to(obj._PortConfiguration);
}


inline void to_json(nlohmann::ordered_json& j, SetOutput::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Output", obj._Output},
      {"Value", obj._Value},
  };
}

inline void from_json(const nlohmann::json& j, SetOutput::Post::Request& obj)
{
  j.at("Output").get_to(obj._Output);
  j.at("Value").get_to(obj._Value);
}


inline void to_json(nlohmann::ordered_json& j, SetOutput::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, SetOutput::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, mStartMeasure::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, mStartMeasure::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


inline void to_json(nlohmann::ordered_json& j, mStandby::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, mStandby::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


inline void to_json(nlohmann::ordered_json& j, MeanFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiScanNumber", obj._uiScanNumber.value()},
      {"eFilterMethod", obj._eFilterMethod},
  };
}

inline void from_json(const nlohmann::json& j, MeanFilter::Get::Response& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiScanNumber").get_to(obj._uiScanNumber);
  j.at("eFilterMethod").get_to(obj._eFilterMethod);
}


inline void to_json(nlohmann::ordered_json& j, MeanFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiScanNumber", obj._uiScanNumber.value()},
      {"eFilterMethod", obj._eFilterMethod},
  };
}

inline void from_json(const nlohmann::json& j, MeanFilter::Post::Request& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiScanNumber").get_to(obj._uiScanNumber);
  j.at("eFilterMethod").get_to(obj._eFilterMethod);
}


inline void to_json(nlohmann::ordered_json& j, LFPmedianfilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiMedianWidth", obj._uiMedianWidth.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPmedianfilter::Get::Response& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiMedianWidth").get_to(obj._uiMedianWidth);
}


inline void to_json(nlohmann::ordered_json& j, LFPmedianfilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiMedianWidth", obj._uiMedianWidth.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPmedianfilter::Post::Request& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiMedianWidth").get_to(obj._uiMedianWidth);
}


inline void to_json(nlohmann::ordered_json& j, LFPradialDistanceRangeFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"ulDistMin", obj._ulDistMin.value()},
      {"ulDistMax", obj._ulDistMax.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPradialDistanceRangeFilter::Get::Response& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("ulDistMin").get_to(obj._ulDistMin);
  j.at("ulDistMax").get_to(obj._ulDistMax);
}


inline void to_json(nlohmann::ordered_json& j, LFPradialDistanceRangeFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"ulDistMin", obj._ulDistMin.value()},
      {"ulDistMax", obj._ulDistMax.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPradialDistanceRangeFilter::Post::Request& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("ulDistMin").get_to(obj._ulDistMin);
  j.at("ulDistMax").get_to(obj._ulDistMax);
}


inline void to_json(nlohmann::ordered_json& j, SetWebserverEnabled::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Enable", obj._Enable},
  };
}

inline void from_json(const nlohmann::json& j, SetWebserverEnabled::Post::Request& obj)
{
  j.at("Enable").get_to(obj._Enable);
}


inline void to_json(nlohmann::ordered_json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem::PositionsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem::PositionsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
      {"Positions", obj._Positions},
  };
}

inline void from_json(const nlohmann::json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem& obj)
{
  j.at("State").get_to(obj._State);
  j.at("Positions").get_to(obj._Positions);
}

inline void to_json(nlohmann::ordered_json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Timestamp", obj._Timestamp},
      {"EvaluationResultList", obj._EvaluationResultList},
  };
}

inline void from_json(const nlohmann::json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Timestamp").get_to(obj._Timestamp);
  j.at("EvaluationResultList").get_to(obj._EvaluationResultList);
}

inline void to_json(nlohmann::ordered_json& j, FieldEvaluationResult::Get::Response const& obj)
{
  j = obj._FieldEvaluationResult;
}

inline void from_json(const nlohmann::json& j, FieldEvaluationResult::Get::Response& obj)
{
  j.get_to(obj._FieldEvaluationResult);
}


inline void to_json(nlohmann::ordered_json& j, ActivateEvaluationGroup::Post::Request::ListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"GroupId", obj._GroupId.value()},
      {"Activate", obj._Activate},
  };
}

inline void from_json(const nlohmann::json& j, ActivateEvaluationGroup::Post::Request::ListItem& obj)
{
  j.at("GroupId").get_to(obj._GroupId);
  j.at("Activate").get_to(obj._Activate);
}

inline void to_json(nlohmann::ordered_json& j, ActivateEvaluationGroup::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"List", obj._List},
  };
}

inline void from_json(const nlohmann::json& j, ActivateEvaluationGroup::Post::Request& obj)
{
  j.at("List").get_to(obj._List);
}


inline void to_json(nlohmann::ordered_json& j, ActivateEvaluationGroup::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, ActivateEvaluationGroup::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, SetFieldEvaluationContour::Post::Request::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, SetFieldEvaluationContour::Post::Request::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, SetFieldEvaluationContour::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EvaluationId", obj._EvaluationId},
      {"Points", obj._Points},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
  };
}

inline void from_json(const nlohmann::json& j, SetFieldEvaluationContour::Post::Request& obj)
{
  j.at("EvaluationId").get_to(obj._EvaluationId);
  j.at("Points").get_to(obj._Points);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
}


inline void to_json(nlohmann::ordered_json& j, SetFieldEvaluationContour::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, SetFieldEvaluationContour::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


inline void to_json(nlohmann::ordered_json& j, GetFieldEvaluationContour::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EvaluationId", obj._EvaluationId},
  };
}

inline void from_json(const nlohmann::json& j, GetFieldEvaluationContour::Post::Request& obj)
{
  j.at("EvaluationId").get_to(obj._EvaluationId);
}


inline void to_json(nlohmann::ordered_json& j, GetFieldEvaluationContour::Post::Response::ContourItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, GetFieldEvaluationContour::Post::Response::ContourItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, GetFieldEvaluationContour::Post::Response::ContourItem const& obj)
{
  j = nlohmann::ordered_json{
      {"EvaluationId", obj._EvaluationId},
      {"Points", obj._Points},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
  };
}

inline void from_json(const nlohmann::json& j, GetFieldEvaluationContour::Post::Response::ContourItem& obj)
{
  j.at("EvaluationId").get_to(obj._EvaluationId);
  j.at("Points").get_to(obj._Points);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
}

inline void to_json(nlohmann::ordered_json& j, GetFieldEvaluationContour::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Contour", obj._Contour},
  };
}

inline void from_json(const nlohmann::json& j, GetFieldEvaluationContour::Post::Response& obj)
{
  j.at("Contour").get_to(obj._Contour);
}


inline void to_json(nlohmann::ordered_json& j, FieldEvaluationGroupState::Get::Response const& obj)
{
  j = obj._FieldEvaluationGroupState;
}

inline void from_json(const nlohmann::json& j, FieldEvaluationGroupState::Get::Response& obj)
{
  j.get_to(obj._FieldEvaluationGroupState);
}


inline void to_json(nlohmann::ordered_json& j, FieldEvaluationApplicationState::Get::Response const& obj)
{
  j = obj._FieldEvaluationApplicationState;
}

inline void from_json(const nlohmann::json& j, FieldEvaluationApplicationState::Get::Response& obj)
{
  j.get_to(obj._FieldEvaluationApplicationState);
}


inline void to_json(nlohmann::ordered_json& j, EnableDetectionHistory::Get::Response const& obj)
{
  j = obj._EnableDetectionHistory;
}

inline void from_json(const nlohmann::json& j, EnableDetectionHistory::Get::Response& obj)
{
  j.get_to(obj._EnableDetectionHistory);
}


inline void to_json(nlohmann::ordered_json& j, EnableDetectionHistory::Post::Request const& obj)
{
  j = obj._EnableDetectionHistory;
}

inline void from_json(const nlohmann::json& j, EnableDetectionHistory::Post::Request& obj)
{
  j.get_to(obj._EnableDetectionHistory);
}


inline void to_json(nlohmann::ordered_json& j, ScanMergerEnabled::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"ScanMergerEnabled", obj._ScanMergerEnabled},
  };
}

inline void from_json(const nlohmann::json& j, ScanMergerEnabled::Post::Request& obj)
{
  j.at("ScanMergerEnabled").get_to(obj._ScanMergerEnabled);
}


inline void to_json(nlohmann::ordered_json& j, ScanMergerSource::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"ScanMergerSource", obj._ScanMergerSource},
  };
}

inline void from_json(const nlohmann::json& j, ScanMergerSource::Post::Request& obj)
{
  j.at("ScanMergerSource").get_to(obj._ScanMergerSource);
}


inline void to_json(nlohmann::ordered_json& j, ScanMergeTrigger::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"ScanMergeTrigger", obj._ScanMergeTrigger},
  };
}

inline void from_json(const nlohmann::json& j, ScanMergeTrigger::Post::Request& obj)
{
  j.at("ScanMergeTrigger").get_to(obj._ScanMergeTrigger);
}


inline void to_json(nlohmann::ordered_json& j, RotationOffset::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x.value()},
      {"y", obj._y.value()},
      {"z", obj._z.value()},
  };
}

inline void from_json(const nlohmann::json& j, RotationOffset::Get::Response& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
  j.at("z").get_to(obj._z);
}


inline void to_json(nlohmann::ordered_json& j, RotationOffset::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x.value()},
      {"y", obj._y.value()},
      {"z", obj._z.value()},
  };
}

inline void from_json(const nlohmann::json& j, RotationOffset::Post::Request& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
  j.at("z").get_to(obj._z);
}


inline void to_json(nlohmann::ordered_json& j, EncoderTransformationType::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"EncoderTransformationType", obj._EncoderTransformationType},
  };
}

inline void from_json(const nlohmann::json& j, EncoderTransformationType::Post::Request& obj)
{
  j.at("EncoderTransformationType").get_to(obj._EncoderTransformationType);
}


inline void to_json(nlohmann::ordered_json& j, EncoderRotation::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"yaw", obj._yaw.value()},
      {"pitch", obj._pitch.value()},
      {"roll", obj._roll.value()},
  };
}

inline void from_json(const nlohmann::json& j, EncoderRotation::Post::Request& obj)
{
  j.at("yaw").get_to(obj._yaw);
  j.at("pitch").get_to(obj._pitch);
  j.at("roll").get_to(obj._roll);
}


inline void to_json(nlohmann::ordered_json& j, EncoderTranslation::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x.value()},
      {"y", obj._y.value()},
      {"z", obj._z.value()},
  };
}

inline void from_json(const nlohmann::json& j, EncoderTranslation::Post::Request& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
  j.at("z").get_to(obj._z);
}


inline void to_json(nlohmann::ordered_json& j, TSCRole::Get::Response const& obj)
{
  j = obj._TSCRole;
}

inline void from_json(const nlohmann::json& j, TSCRole::Get::Response& obj)
{
  j.get_to(obj._TSCRole);
}


inline void to_json(nlohmann::ordered_json& j, TSCRole::Post::Request const& obj)
{
  j = obj._TSCRole;
}

inline void from_json(const nlohmann::json& j, TSCRole::Post::Request& obj)
{
  j.get_to(obj._TSCRole);
}


inline void to_json(nlohmann::ordered_json& j, TSCTCSrvAddr::Get::Response const& obj)
{
  j = obj._TSCTCSrvAddr;
}

inline void from_json(const nlohmann::json& j, TSCTCSrvAddr::Get::Response& obj)
{
  j.get_to(obj._TSCTCSrvAddr);
}


inline void to_json(nlohmann::ordered_json& j, TSCTCSrvAddr::Post::Request const& obj)
{
  j = obj._TSCTCSrvAddr;
}

inline void from_json(const nlohmann::json& j, TSCTCSrvAddr::Post::Request& obj)
{
  j.get_to(obj._TSCTCSrvAddr);
}


inline void to_json(nlohmann::ordered_json& j, TSCTCtimezone::Get::Response const& obj)
{
  j = obj._TSCTCtimezone;
}

inline void from_json(const nlohmann::json& j, TSCTCtimezone::Get::Response& obj)
{
  j.get_to(obj._TSCTCtimezone);
}


inline void to_json(nlohmann::ordered_json& j, TSCTCtimezone::Post::Request const& obj)
{
  j = obj._TSCTCtimezone;
}

inline void from_json(const nlohmann::json& j, TSCTCtimezone::Post::Request& obj)
{
  j.get_to(obj._TSCTCtimezone);
}


inline void to_json(nlohmann::ordered_json& j, TSCTCupdatetime::Get::Response const& obj)
{
  j = obj._TSCTCupdatetime.value();
}

inline void from_json(const nlohmann::json& j, TSCTCupdatetime::Get::Response& obj)
{
  j.get_to(obj._TSCTCupdatetime);
}


inline void to_json(nlohmann::ordered_json& j, TSCTCupdatetime::Post::Request const& obj)
{
  j = obj._TSCTCupdatetime.value();
}

inline void from_json(const nlohmann::json& j, TSCTCupdatetime::Post::Request& obj)
{
  j.get_to(obj._TSCTCupdatetime);
}


inline void to_json(nlohmann::ordered_json& j, DateTime::Get::Response::DateTime const& obj)
{
  j = nlohmann::ordered_json{
      {"uiYear", obj._uiYear.value()},
      {"usiMonth", obj._usiMonth.value()},
      {"usiDay", obj._usiDay.value()},
      {"usiHour", obj._usiHour.value()},
      {"usiMinute", obj._usiMinute.value()},
      {"usiSec", obj._usiSec.value()},
      {"udiUSec", obj._udiUSec.value()},
  };
}

inline void from_json(const nlohmann::json& j, DateTime::Get::Response::DateTime& obj)
{
  j.at("uiYear").get_to(obj._uiYear);
  j.at("usiMonth").get_to(obj._usiMonth);
  j.at("usiDay").get_to(obj._usiDay);
  j.at("usiHour").get_to(obj._usiHour);
  j.at("usiMinute").get_to(obj._usiMinute);
  j.at("usiSec").get_to(obj._usiSec);
  j.at("udiUSec").get_to(obj._udiUSec);
}

inline void to_json(nlohmann::ordered_json& j, DateTime::Get::Response const& obj)
{
  j = obj._DateTime;
}

inline void from_json(const nlohmann::json& j, DateTime::Get::Response& obj)
{
  j.get_to(obj._DateTime);
}


inline void to_json(nlohmann::ordered_json& j, mSetDateTime::Post::Request::DateTime const& obj)
{
  j = nlohmann::ordered_json{
      {"uiYear", obj._uiYear.value()},
      {"usiMonth", obj._usiMonth.value()},
      {"usiDay", obj._usiDay.value()},
      {"usiHour", obj._usiHour.value()},
      {"usiMinute", obj._usiMinute.value()},
      {"usiSec", obj._usiSec.value()},
      {"udiUSec", obj._udiUSec.value()},
  };
}

inline void from_json(const nlohmann::json& j, mSetDateTime::Post::Request::DateTime& obj)
{
  j.at("uiYear").get_to(obj._uiYear);
  j.at("usiMonth").get_to(obj._usiMonth);
  j.at("usiDay").get_to(obj._usiDay);
  j.at("usiHour").get_to(obj._usiHour);
  j.at("usiMinute").get_to(obj._usiMinute);
  j.at("usiSec").get_to(obj._usiSec);
  j.at("udiUSec").get_to(obj._udiUSec);
}

inline void to_json(nlohmann::ordered_json& j, mSetDateTime::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"DateTime", obj._DateTime},
  };
}

inline void from_json(const nlohmann::json& j, mSetDateTime::Post::Request& obj)
{
  j.at("DateTime").get_to(obj._DateTime);
}


inline void to_json(nlohmann::ordered_json& j, mSetDateTime::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, mSetDateTime::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


} // namespace sick::srt::LRS4000
