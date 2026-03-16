/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file 2_2_1.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan120' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/picoScan100/picoScan120/2_2_1.g.hpp>
#include <nlohmann/json.hpp>

namespace sick::picoScan120::v2_2_1::api::rest {

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


inline void to_json(nlohmann::ordered_json& j, EnableUserLevel::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"userLevel", obj._userLevel},
      {"isEnabled", obj._isEnabled},
  };
}

inline void from_json(const nlohmann::json& j, EnableUserLevel::Post::Request& obj)
{
  j.at("userLevel").get_to(obj._userLevel);
  j.at("isEnabled").get_to(obj._isEnabled);
}


inline void to_json(nlohmann::ordered_json& j, EnableUserLevel::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
  };
}

inline void from_json(const nlohmann::json& j, EnableUserLevel::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
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


inline void to_json(nlohmann::ordered_json& j, EtherCoLaScanMode::Get::Response const& obj)
{
  j = obj._EtherCoLaScanMode;
}

inline void from_json(const nlohmann::json& j, EtherCoLaScanMode::Get::Response& obj)
{
  j.get_to(obj._EtherCoLaScanMode);
}


inline void to_json(nlohmann::ordered_json& j, EtherCoLaScanMode::Post::Request const& obj)
{
  j = obj._EtherCoLaScanMode;
}

inline void from_json(const nlohmann::json& j, EtherCoLaScanMode::Post::Request& obj)
{
  j.get_to(obj._EtherCoLaScanMode);
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


inline void to_json(nlohmann::ordered_json& j, httpsStatus::Get::Response::errorCode const& obj)
{
  j = nlohmann::ordered_json{
      {"error", obj._error},
  };
}

inline void from_json(const nlohmann::json& j, httpsStatus::Get::Response::errorCode& obj)
{
  j.at("error").get_to(obj._error);
}

inline void to_json(nlohmann::ordered_json& j, httpsStatus::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"enabled", obj._enabled},
      {"errorCode", obj._errorCode},
  };
}

inline void from_json(const nlohmann::json& j, httpsStatus::Get::Response& obj)
{
  j.at("enabled").get_to(obj._enabled);
  j.at("errorCode").get_to(obj._errorCode);
}


inline void to_json(nlohmann::ordered_json& j, certificateBundleInfo::Get::Response::certificatesItem::namesItem const& obj)
{
  j = nlohmann::ordered_json{
      {"entry", obj._entry},
  };
}

inline void from_json(const nlohmann::json& j, certificateBundleInfo::Get::Response::certificatesItem::namesItem& obj)
{
  j.at("entry").get_to(obj._entry);
}

inline void to_json(nlohmann::ordered_json& j, certificateBundleInfo::Get::Response::certificatesItem const& obj)
{
  j = nlohmann::ordered_json{
      {"names", obj._names},
      {"issuer", obj._issuer},
      {"subject", obj._subject},
      {"serialNumber", obj._serialNumber},
      {"fingerprint", obj._fingerprint},
      {"validNotBefore", obj._validNotBefore},
      {"validNotAfter", obj._validNotAfter},
  };
}

inline void from_json(const nlohmann::json& j, certificateBundleInfo::Get::Response::certificatesItem& obj)
{
  j.at("names").get_to(obj._names);
  j.at("issuer").get_to(obj._issuer);
  j.at("subject").get_to(obj._subject);
  j.at("serialNumber").get_to(obj._serialNumber);
  j.at("fingerprint").get_to(obj._fingerprint);
  j.at("validNotBefore").get_to(obj._validNotBefore);
  j.at("validNotAfter").get_to(obj._validNotAfter);
}

inline void to_json(nlohmann::ordered_json& j, certificateBundleInfo::Get::Response::errorCode const& obj)
{
  j = nlohmann::ordered_json{
      {"error", obj._error},
  };
}

inline void from_json(const nlohmann::json& j, certificateBundleInfo::Get::Response::errorCode& obj)
{
  j.at("error").get_to(obj._error);
}

inline void to_json(nlohmann::ordered_json& j, certificateBundleInfo::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"uuidBundle", obj._uuidBundle},
      {"certificates", obj._certificates},
      {"errorCode", obj._errorCode},
  };
}

inline void from_json(const nlohmann::json& j, certificateBundleInfo::Get::Response& obj)
{
  j.at("uuidBundle").get_to(obj._uuidBundle);
  j.at("certificates").get_to(obj._certificates);
  j.at("errorCode").get_to(obj._errorCode);
}


inline void to_json(nlohmann::ordered_json& j, removeCertificateBundle::Post::Response::errorCode const& obj)
{
  j = nlohmann::ordered_json{
      {"error", obj._error},
  };
}

inline void from_json(const nlohmann::json& j, removeCertificateBundle::Post::Response::errorCode& obj)
{
  j.at("error").get_to(obj._error);
}

inline void to_json(nlohmann::ordered_json& j, removeCertificateBundle::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"success", obj._success},
      {"errorCode", obj._errorCode},
  };
}

inline void from_json(const nlohmann::json& j, removeCertificateBundle::Post::Response& obj)
{
  j.at("success").get_to(obj._success);
  j.at("errorCode").get_to(obj._errorCode);
}


inline void to_json(nlohmann::ordered_json& j, setCertificateBundle::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"contentCertificateBundle", obj._contentCertificateBundle},
      {"contentPrivateKey", obj._contentPrivateKey},
  };
}

inline void from_json(const nlohmann::json& j, setCertificateBundle::Post::Request& obj)
{
  j.at("contentCertificateBundle").get_to(obj._contentCertificateBundle);
  j.at("contentPrivateKey").get_to(obj._contentPrivateKey);
}


inline void to_json(nlohmann::ordered_json& j, setCertificateBundle::Post::Response::errorCode const& obj)
{
  j = nlohmann::ordered_json{
      {"error", obj._error},
  };
}

inline void from_json(const nlohmann::json& j, setCertificateBundle::Post::Response::errorCode& obj)
{
  j.at("error").get_to(obj._error);
}

inline void to_json(nlohmann::ordered_json& j, setCertificateBundle::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"success", obj._success},
      {"errorCode", obj._errorCode},
  };
}

inline void from_json(const nlohmann::json& j, setCertificateBundle::Post::Response& obj)
{
  j.at("success").get_to(obj._success);
  j.at("errorCode").get_to(obj._errorCode);
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


inline void to_json(nlohmann::ordered_json& j, GetWebserverEnabled::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"IsEnabled", obj._IsEnabled},
  };
}

inline void from_json(const nlohmann::json& j, GetWebserverEnabled::Post::Response& obj)
{
  j.at("IsEnabled").get_to(obj._IsEnabled);
}


inline void to_json(nlohmann::ordered_json& j, EnableLegacyUserLevel::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"userLevel", obj._userLevel.value()},
      {"isEnabled", obj._isEnabled},
  };
}

inline void from_json(const nlohmann::json& j, EnableLegacyUserLevel::Post::Request& obj)
{
  j.at("userLevel").get_to(obj._userLevel);
  j.at("isEnabled").get_to(obj._isEnabled);
}


inline void to_json(nlohmann::ordered_json& j, EnableLegacyUserLevel::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
  };
}

inline void from_json(const nlohmann::json& j, EnableLegacyUserLevel::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
}


inline void to_json(nlohmann::ordered_json& j, EtherMACAddress::Get::Response const& obj)
{
  j = obj._EtherMACAddress;
}

inline void from_json(const nlohmann::json& j, EtherMACAddress::Get::Response& obj)
{
  j.get_to(obj._EtherMACAddress);
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


inline void to_json(nlohmann::ordered_json& j, DeviceType::Get::Response const& obj)
{
  j = obj._DeviceType;
}

inline void from_json(const nlohmann::json& j, DeviceType::Get::Response& obj)
{
  j.get_to(obj._DeviceType);
}


inline void to_json(nlohmann::ordered_json& j, UpdateState::Get::Response const& obj)
{
  j = obj._UpdateState;
}

inline void from_json(const nlohmann::json& j, UpdateState::Get::Response& obj)
{
  j.get_to(obj._UpdateState);
}


inline void to_json(nlohmann::ordered_json& j, CreateParameterBackup::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Passphrase", obj._Passphrase},
  };
}

inline void from_json(const nlohmann::json& j, CreateParameterBackup::Post::Request& obj)
{
  j.at("Passphrase").get_to(obj._Passphrase);
}


inline void to_json(nlohmann::ordered_json& j, CreateParameterBackup::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, CreateParameterBackup::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, RestoreParameterBackup::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Passphrase", obj._Passphrase},
  };
}

inline void from_json(const nlohmann::json& j, RestoreParameterBackup::Post::Request& obj)
{
  j.at("Passphrase").get_to(obj._Passphrase);
}


inline void to_json(nlohmann::ordered_json& j, RestoreParameterBackup::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, RestoreParameterBackup::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataEthSettings::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Protocol", obj._Protocol},
      {"IPAddress", obj._IPAddress},
      {"Port", obj._Port},
  };
}

inline void from_json(const nlohmann::json& j, ScanDataEthSettings::Get::Response& obj)
{
  j.at("Protocol").get_to(obj._Protocol);
  j.at("IPAddress").get_to(obj._IPAddress);
  j.at("Port").get_to(obj._Port);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataEthSettings::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Protocol", obj._Protocol},
      {"IPAddress", obj._IPAddress},
      {"Port", obj._Port},
  };
}

inline void from_json(const nlohmann::json& j, ScanDataEthSettings::Post::Request& obj)
{
  j.at("Protocol").get_to(obj._Protocol);
  j.at("IPAddress").get_to(obj._IPAddress);
  j.at("Port").get_to(obj._Port);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataEnable::Get::Response const& obj)
{
  j = obj._ScanDataEnable;
}

inline void from_json(const nlohmann::json& j, ScanDataEnable::Get::Response& obj)
{
  j.get_to(obj._ScanDataEnable);
}


inline void to_json(nlohmann::ordered_json& j, ScanDataEnable::Post::Request const& obj)
{
  j = obj._ScanDataEnable;
}

inline void from_json(const nlohmann::json& j, ScanDataEnable::Post::Request& obj)
{
  j.get_to(obj._ScanDataEnable);
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


inline void to_json(nlohmann::ordered_json& j, rosFrameId::Get::Response const& obj)
{
  j = obj._rosFrameId;
}

inline void from_json(const nlohmann::json& j, rosFrameId::Get::Response& obj)
{
  j.get_to(obj._rosFrameId);
}


inline void to_json(nlohmann::ordered_json& j, rosFrameId::Post::Request const& obj)
{
  j = obj._rosFrameId;
}

inline void from_json(const nlohmann::json& j, rosFrameId::Post::Request& obj)
{
  j.get_to(obj._rosFrameId);
}


inline void to_json(nlohmann::ordered_json& j, rosParentFrameId::Get::Response const& obj)
{
  j = obj._rosParentFrameId;
}

inline void from_json(const nlohmann::json& j, rosParentFrameId::Get::Response& obj)
{
  j.get_to(obj._rosParentFrameId);
}


inline void to_json(nlohmann::ordered_json& j, rosParentFrameId::Post::Request const& obj)
{
  j = obj._rosParentFrameId;
}

inline void from_json(const nlohmann::json& j, rosParentFrameId::Post::Request& obj)
{
  j.get_to(obj._rosParentFrameId);
}


inline void to_json(nlohmann::ordered_json& j, rosNamespace::Get::Response const& obj)
{
  j = obj._rosNamespace;
}

inline void from_json(const nlohmann::json& j, rosNamespace::Get::Response& obj)
{
  j.get_to(obj._rosNamespace);
}


inline void to_json(nlohmann::ordered_json& j, rosNamespace::Post::Request const& obj)
{
  j = obj._rosNamespace;
}

inline void from_json(const nlohmann::json& j, rosNamespace::Post::Request& obj)
{
  j.get_to(obj._rosNamespace);
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
      {"EncoderPortType", obj._EncoderPortType},
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
  j.at("EncoderPortType").get_to(obj._EncoderPortType);
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
      {"EncoderPortType", obj._EncoderPortType},
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
  j.at("EncoderPortType").get_to(obj._EncoderPortType);
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


inline void to_json(nlohmann::ordered_json& j, LEDState::Get::Response::LEDStateItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Color", obj._Color},
      {"Function", obj._Function},
      {"Id", obj._Id},
  };
}

inline void from_json(const nlohmann::json& j, LEDState::Get::Response::LEDStateItem& obj)
{
  j.at("Color").get_to(obj._Color);
  j.at("Function").get_to(obj._Function);
  j.at("Id").get_to(obj._Id);
}

inline void to_json(nlohmann::ordered_json& j, LEDState::Get::Response const& obj)
{
  j = obj._LEDState;
}

inline void from_json(const nlohmann::json& j, LEDState::Get::Response& obj)
{
  j.get_to(obj._LEDState);
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


inline void to_json(nlohmann::ordered_json& j, LFTchecksum::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"MD5SumOK", obj._MD5SumOK},
      {"MD5LinuxRoot", obj._MD5LinuxRoot},
      {"MD5App", obj._MD5App},
      {"MD5Calibration", obj._MD5Calibration},
      {"MD5Parameters", obj._MD5Parameters},
  };
}

inline void from_json(const nlohmann::json& j, LFTchecksum::Get::Response& obj)
{
  j.at("MD5SumOK").get_to(obj._MD5SumOK);
  j.at("MD5LinuxRoot").get_to(obj._MD5LinuxRoot);
  j.at("MD5App").get_to(obj._MD5App);
  j.at("MD5Calibration").get_to(obj._MD5Calibration);
  j.at("MD5Parameters").get_to(obj._MD5Parameters);
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


inline void to_json(nlohmann::ordered_json& j, mStopMeasure::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, mStopMeasure::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


inline void to_json(nlohmann::ordered_json& j, AutoStartMeasure::Get::Response const& obj)
{
  j = obj._AutoStartMeasure;
}

inline void from_json(const nlohmann::json& j, AutoStartMeasure::Get::Response& obj)
{
  j.get_to(obj._AutoStartMeasure);
}


inline void to_json(nlohmann::ordered_json& j, AutoStartMeasure::Post::Request const& obj)
{
  j = obj._AutoStartMeasure;
}

inline void from_json(const nlohmann::json& j, AutoStartMeasure::Post::Request& obj)
{
  j.get_to(obj._AutoStartMeasure);
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


inline void to_json(nlohmann::ordered_json& j, temperatureAlarmConfiguration::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"upperThreshold", obj._upperThreshold},
      {"lowerThreshold", obj._lowerThreshold},
  };
}

inline void from_json(const nlohmann::json& j, temperatureAlarmConfiguration::Get::Response& obj)
{
  j.at("upperThreshold").get_to(obj._upperThreshold);
  j.at("lowerThreshold").get_to(obj._lowerThreshold);
}


inline void to_json(nlohmann::ordered_json& j, temperatureAlarmConfiguration::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"upperThreshold", obj._upperThreshold},
      {"lowerThreshold", obj._lowerThreshold},
  };
}

inline void from_json(const nlohmann::json& j, temperatureAlarmConfiguration::Post::Request& obj)
{
  j.at("upperThreshold").get_to(obj._upperThreshold);
  j.at("lowerThreshold").get_to(obj._lowerThreshold);
}


inline void to_json(nlohmann::ordered_json& j, temperatureAlarmStatus::Get::Response const& obj)
{
  j = obj._temperatureAlarmStatus;
}

inline void from_json(const nlohmann::json& j, temperatureAlarmStatus::Get::Response& obj)
{
  j.get_to(obj._temperatureAlarmStatus);
}


inline void to_json(nlohmann::ordered_json& j, CurrentTempDev::Get::Response const& obj)
{
  j = obj._CurrentTempDev;
}

inline void from_json(const nlohmann::json& j, CurrentTempDev::Get::Response& obj)
{
  j.get_to(obj._CurrentTempDev);
}


inline void to_json(nlohmann::ordered_json& j, operatingMode::Get::Response const& obj)
{
  j = obj._operatingMode;
}

inline void from_json(const nlohmann::json& j, operatingMode::Get::Response& obj)
{
  j.get_to(obj._operatingMode);
}


inline void to_json(nlohmann::ordered_json& j, operatingMode::Post::Request const& obj)
{
  j = obj._operatingMode;
}

inline void from_json(const nlohmann::json& j, operatingMode::Post::Request& obj)
{
  j.get_to(obj._operatingMode);
}


inline void to_json(nlohmann::ordered_json& j, LFPparticle::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiThreshold", obj._uiThreshold.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPparticle::Get::Response& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiThreshold").get_to(obj._uiThreshold);
}


inline void to_json(nlohmann::ordered_json& j, LFPparticle::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiThreshold", obj._uiThreshold.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPparticle::Post::Request& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiThreshold").get_to(obj._uiThreshold);
}


inline void to_json(nlohmann::ordered_json& j, SensorPosition::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x.value()},
      {"y", obj._y.value()},
      {"z", obj._z.value()},
      {"yaw", obj._yaw.value()},
      {"pitch", obj._pitch.value()},
      {"roll", obj._roll.value()},
  };
}

inline void from_json(const nlohmann::json& j, SensorPosition::Get::Response& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
  j.at("z").get_to(obj._z);
  j.at("yaw").get_to(obj._yaw);
  j.at("pitch").get_to(obj._pitch);
  j.at("roll").get_to(obj._roll);
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


inline void to_json(nlohmann::ordered_json& j, LSPdatetime::Get::Response::LSPdatetime const& obj)
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

inline void from_json(const nlohmann::json& j, LSPdatetime::Get::Response::LSPdatetime& obj)
{
  j.at("uiYear").get_to(obj._uiYear);
  j.at("usiMonth").get_to(obj._usiMonth);
  j.at("usiDay").get_to(obj._usiDay);
  j.at("usiHour").get_to(obj._usiHour);
  j.at("usiMinute").get_to(obj._usiMinute);
  j.at("usiSec").get_to(obj._usiSec);
  j.at("udiUSec").get_to(obj._udiUSec);
}

inline void to_json(nlohmann::ordered_json& j, LSPdatetime::Get::Response const& obj)
{
  j = obj._LSPdatetime;
}

inline void from_json(const nlohmann::json& j, LSPdatetime::Get::Response& obj)
{
  j.get_to(obj._LSPdatetime);
}


inline void to_json(nlohmann::ordered_json& j, LSPsetdatetime::Post::Request::DateTime const& obj)
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

inline void from_json(const nlohmann::json& j, LSPsetdatetime::Post::Request::DateTime& obj)
{
  j.at("uiYear").get_to(obj._uiYear);
  j.at("usiMonth").get_to(obj._usiMonth);
  j.at("usiDay").get_to(obj._usiDay);
  j.at("usiHour").get_to(obj._usiHour);
  j.at("usiMinute").get_to(obj._usiMinute);
  j.at("usiSec").get_to(obj._usiSec);
  j.at("udiUSec").get_to(obj._udiUSec);
}

inline void to_json(nlohmann::ordered_json& j, LSPsetdatetime::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"DateTime", obj._DateTime},
  };
}

inline void from_json(const nlohmann::json& j, LSPsetdatetime::Post::Request& obj)
{
  j.at("DateTime").get_to(obj._DateTime);
}


inline void to_json(nlohmann::ordered_json& j, LSPsetdatetime::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, LSPsetdatetime::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


} // namespace sick::picoScan120::v2_2_1::api::rest
