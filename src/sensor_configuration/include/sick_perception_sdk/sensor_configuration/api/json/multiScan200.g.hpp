/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file multiScan200.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/sensor_configuration/api/multiScan200.g.hpp>
#include <nlohmann/json.hpp>

namespace sick::srt::multiScan200 {

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


inline void to_json(nlohmann::ordered_json& j, CidVersion::Get::Response::CidVersionStruct const& obj)
{
  j = nlohmann::ordered_json{
      {"MajorVersion", obj._MajorVersion},
      {"MinorVersion", obj._MinorVersion},
      {"PatchVersion", obj._PatchVersion},
      {"BuildNumber", obj._BuildNumber},
      {"VersionClassifier", obj._VersionClassifier},
  };
}

inline void from_json(const nlohmann::json& j, CidVersion::Get::Response::CidVersionStruct& obj)
{
  j.at("MajorVersion").get_to(obj._MajorVersion);
  j.at("MinorVersion").get_to(obj._MinorVersion);
  j.at("PatchVersion").get_to(obj._PatchVersion);
  j.at("BuildNumber").get_to(obj._BuildNumber);
  j.at("VersionClassifier").get_to(obj._VersionClassifier);
}

inline void to_json(nlohmann::ordered_json& j, CidVersion::Get::Response const& obj)
{
  j = obj._CidVersionStruct;
}

inline void from_json(const nlohmann::json& j, CidVersion::Get::Response& obj)
{
  j.get_to(obj._CidVersionStruct);
}


inline void to_json(nlohmann::ordered_json& j, SOPASVersion::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Release", obj._Release},
      {"Build", obj._Build},
  };
}

inline void from_json(const nlohmann::json& j, SOPASVersion::Get::Response& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Release").get_to(obj._Release);
  j.at("Build").get_to(obj._Build);
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


inline void to_json(nlohmann::ordered_json& j, SerialNumber::Post::Request const& obj)
{
  j = obj._SerialNumber;
}

inline void from_json(const nlohmann::json& j, SerialNumber::Post::Request& obj)
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


inline void to_json(nlohmann::ordered_json& j, SopasInfo::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"CIDUploadSupported", obj._CIDUploadSupported},
      {"ShortUDDUploadSupported", obj._ShortUDDUploadSupported},
      {"PMDUploadSupported", obj._PMDUploadSupported},
      {"LocationNameExists", obj._LocationNameExists},
      {"SegmentSize", obj._SegmentSize},
      {"SupportsEventPolling", obj._SupportsEventPolling},
      {"hasProcIndex", obj._hasProcIndex},
      {"CIDChecksumProvided", obj._CIDChecksumProvided},
      {"CheckPasswordProvided", obj._CheckPasswordProvided},
      {"hubFunctionality", obj._hubFunctionality},
      {"JarUploadSupported", obj._JarUploadSupported},
      {"hasFirmwareDownloadAlgorithm", obj._hasFirmwareDownloadAlgorithm},
      {"SimultaneousMethodsSupport", obj._SimultaneousMethodsSupport},
      {"HashValueSupport", obj._HashValueSupport},
      {"HasAdditionalTimeout", obj._HasAdditionalTimeout},
      {"BulkTransferSupported", obj._BulkTransferSupported},
      {"isSystemCapable", obj._isSystemCapable},
      {"SystemSDDUploadSupported", obj._SystemSDDUploadSupported},
  };
}

inline void from_json(const nlohmann::json& j, SopasInfo::Get::Response& obj)
{
  j.at("CIDUploadSupported").get_to(obj._CIDUploadSupported);
  j.at("ShortUDDUploadSupported").get_to(obj._ShortUDDUploadSupported);
  j.at("PMDUploadSupported").get_to(obj._PMDUploadSupported);
  j.at("LocationNameExists").get_to(obj._LocationNameExists);
  j.at("SegmentSize").get_to(obj._SegmentSize);
  j.at("SupportsEventPolling").get_to(obj._SupportsEventPolling);
  j.at("hasProcIndex").get_to(obj._hasProcIndex);
  j.at("CIDChecksumProvided").get_to(obj._CIDChecksumProvided);
  j.at("CheckPasswordProvided").get_to(obj._CheckPasswordProvided);
  j.at("hubFunctionality").get_to(obj._hubFunctionality);
  j.at("JarUploadSupported").get_to(obj._JarUploadSupported);
  j.at("hasFirmwareDownloadAlgorithm").get_to(obj._hasFirmwareDownloadAlgorithm);
  j.at("SimultaneousMethodsSupport").get_to(obj._SimultaneousMethodsSupport);
  j.at("HashValueSupport").get_to(obj._HashValueSupport);
  j.at("HasAdditionalTimeout").get_to(obj._HasAdditionalTimeout);
  j.at("BulkTransferSupported").get_to(obj._BulkTransferSupported);
  j.at("isSystemCapable").get_to(obj._isSystemCapable);
  j.at("SystemSDDUploadSupported").get_to(obj._SystemSDDUploadSupported);
}


inline void to_json(nlohmann::ordered_json& j, NotifyMode::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"NewMode", obj._NewMode},
  };
}

inline void from_json(const nlohmann::json& j, NotifyMode::Post::Request& obj)
{
  j.at("NewMode").get_to(obj._NewMode);
}


inline void to_json(nlohmann::ordered_json& j, GetAccessMode::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"opmode", obj._opmode},
  };
}

inline void from_json(const nlohmann::json& j, GetAccessMode::Post::Response& obj)
{
  j.at("opmode").get_to(obj._opmode);
}


inline void to_json(nlohmann::ordered_json& j, Run::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"success", obj._success},
  };
}

inline void from_json(const nlohmann::json& j, Run::Post::Response& obj)
{
  j.at("success").get_to(obj._success);
}


inline void to_json(nlohmann::ordered_json& j, GetDescription::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"eType", obj._eType},
      {"uiSegmentNumber", obj._uiSegmentNumber},
  };
}

inline void from_json(const nlohmann::json& j, GetDescription::Post::Request& obj)
{
  j.at("eType").get_to(obj._eType);
  j.at("uiSegmentNumber").get_to(obj._uiSegmentNumber);
}


inline void to_json(nlohmann::ordered_json& j, GetDescription::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"eState", obj._eState},
      {"uiSegmentNumber", obj._uiSegmentNumber},
      {"aByteStream", obj._aByteStream},
  };
}

inline void from_json(const nlohmann::json& j, GetDescription::Post::Response& obj)
{
  j.at("eState").get_to(obj._eState);
  j.at("uiSegmentNumber").get_to(obj._uiSegmentNumber);
  j.at("aByteStream").get_to(obj._aByteStream);
}


inline void to_json(nlohmann::ordered_json& j, SetAccessMode::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"NewMode", obj._NewMode},
      {"Password", obj._Password},
  };
}

inline void from_json(const nlohmann::json& j, SetAccessMode::Post::Request& obj)
{
  j.at("NewMode").get_to(obj._NewMode);
  j.at("Password").get_to(obj._Password);
}


inline void to_json(nlohmann::ordered_json& j, SetAccessMode::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"success", obj._success},
  };
}

inline void from_json(const nlohmann::json& j, SetAccessMode::Post::Response& obj)
{
  j.at("success").get_to(obj._success);
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


inline void to_json(nlohmann::ordered_json& j, CheckPassword::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"siUserLevel", obj._siUserLevel},
      {"udiPassword", obj._udiPassword},
  };
}

inline void from_json(const nlohmann::json& j, CheckPassword::Post::Request& obj)
{
  j.at("siUserLevel").get_to(obj._siUserLevel);
  j.at("udiPassword").get_to(obj._udiPassword);
}


inline void to_json(nlohmann::ordered_json& j, CheckPassword::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bSuccess", obj._bSuccess},
  };
}

inline void from_json(const nlohmann::json& j, CheckPassword::Post::Response& obj)
{
  j.at("bSuccess").get_to(obj._bSuccess);
}


inline void to_json(nlohmann::ordered_json& j, CIDChecksum::Get::Response const& obj)
{
  j = obj._CIDChecksum;
}

inline void from_json(const nlohmann::json& j, CIDChecksum::Get::Response& obj)
{
  j.get_to(obj._CIDChecksum);
}


inline void to_json(nlohmann::ordered_json& j, SubDevicesExt::Get::Response::AddressesItem::xProperties const& obj)
{
  j = nlohmann::ordered_json{
      {"bVisible", obj._bVisible},
      {"eProtocol", obj._eProtocol},
  };
}

inline void from_json(const nlohmann::json& j, SubDevicesExt::Get::Response::AddressesItem::xProperties& obj)
{
  j.at("bVisible").get_to(obj._bVisible);
  j.at("eProtocol").get_to(obj._eProtocol);
}

inline void to_json(nlohmann::ordered_json& j, SubDevicesExt::Get::Response::AddressesItem const& obj)
{
  j = nlohmann::ordered_json{
      {"usiSubAddress", obj._usiSubAddress},
      {"xProperties", obj._xProperties},
  };
}

inline void from_json(const nlohmann::json& j, SubDevicesExt::Get::Response::AddressesItem& obj)
{
  j.at("usiSubAddress").get_to(obj._usiSubAddress);
  j.at("xProperties").get_to(obj._xProperties);
}

inline void to_json(nlohmann::ordered_json& j, SubDevicesExt::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Addresses", obj._Addresses},
      {"reserved", obj._reserved},
  };
}

inline void from_json(const nlohmann::json& j, SubDevicesExt::Get::Response& obj)
{
  j.at("Addresses").get_to(obj._Addresses);
  j.at("reserved").get_to(obj._reserved);
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


inline void to_json(nlohmann::ordered_json& j, getChallenge::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"realm", obj._realm},
      {"nonce", obj._nonce},
      {"opaque", obj._opaque},
      {"salt", obj._salt},
  };
}

inline void from_json(const nlohmann::json& j, getChallenge::Post::Response& obj)
{
  j.at("realm").get_to(obj._realm);
  j.at("nonce").get_to(obj._nonce);
  j.at("opaque").get_to(obj._opaque);
  j.at("salt").get_to(obj._salt);
}


inline void to_json(nlohmann::ordered_json& j, SetUserLevel::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"challengeResponse", obj._challengeResponse},
      {"userLevel", obj._userLevel},
  };
}

inline void from_json(const nlohmann::json& j, SetUserLevel::Post::Request& obj)
{
  j.at("challengeResponse").get_to(obj._challengeResponse);
  j.at("userLevel").get_to(obj._userLevel);
}


inline void to_json(nlohmann::ordered_json& j, SetUserLevel::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
  };
}

inline void from_json(const nlohmann::json& j, SetUserLevel::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
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


inline void to_json(nlohmann::ordered_json& j, GetUserLevelPasswordState::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"userLevel", obj._userLevel},
  };
}

inline void from_json(const nlohmann::json& j, GetUserLevelPasswordState::Post::Request& obj)
{
  j.at("userLevel").get_to(obj._userLevel);
}


inline void to_json(nlohmann::ordered_json& j, GetUserLevelPasswordState::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"state", obj._state},
  };
}

inline void from_json(const nlohmann::json& j, GetUserLevelPasswordState::Post::Response& obj)
{
  j.at("state").get_to(obj._state);
}


inline void to_json(nlohmann::ordered_json& j, SwitchChangeDefaultPasswordDialogState::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"userLevel", obj._userLevel},
      {"enableChangePasswordDialog", obj._enableChangePasswordDialog},
  };
}

inline void from_json(const nlohmann::json& j, SwitchChangeDefaultPasswordDialogState::Post::Request& obj)
{
  j.at("userLevel").get_to(obj._userLevel);
  j.at("enableChangePasswordDialog").get_to(obj._enableChangePasswordDialog);
}


inline void to_json(nlohmann::ordered_json& j, SwitchChangeDefaultPasswordDialogState::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
  };
}

inline void from_json(const nlohmann::json& j, SwitchChangeDefaultPasswordDialogState::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
}


inline void to_json(nlohmann::ordered_json& j, SetPasswordRecoverySecret::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"secret", obj._secret},
  };
}

inline void from_json(const nlohmann::json& j, SetPasswordRecoverySecret::Post::Request& obj)
{
  j.at("secret").get_to(obj._secret);
}


inline void to_json(nlohmann::ordered_json& j, SetPasswordRecoverySecret::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
  };
}

inline void from_json(const nlohmann::json& j, SetPasswordRecoverySecret::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
}


inline void to_json(nlohmann::ordered_json& j, StartPasswordRecovery::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
      {"challenge", obj._challenge},
  };
}

inline void from_json(const nlohmann::json& j, StartPasswordRecovery::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
  j.at("challenge").get_to(obj._challenge);
}


inline void to_json(nlohmann::ordered_json& j, CompletePasswordRecovery::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"response", obj._response},
  };
}

inline void from_json(const nlohmann::json& j, CompletePasswordRecovery::Post::Request& obj)
{
  j.at("response").get_to(obj._response);
}


inline void to_json(nlohmann::ordered_json& j, CompletePasswordRecovery::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"result", obj._result},
  };
}

inline void from_json(const nlohmann::json& j, CompletePasswordRecovery::Post::Response& obj)
{
  j.at("result").get_to(obj._result);
}


inline void to_json(nlohmann::ordered_json& j, GetPasswordRecoveryStatus::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"status", obj._status},
      {"remainingLoginAttempts", obj._remainingLoginAttempts},
      {"challenge", obj._challenge},
  };
}

inline void from_json(const nlohmann::json& j, GetPasswordRecoveryStatus::Post::Response& obj)
{
  j.at("status").get_to(obj._status);
  j.at("remainingLoginAttempts").get_to(obj._remainingLoginAttempts);
  j.at("challenge").get_to(obj._challenge);
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


inline void to_json(nlohmann::ordered_json& j, GetUserLevelInformation::Post::Response::userLevelsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"isDefeatable", obj._isDefeatable},
      {"isEnabled", obj._isEnabled},
  };
}

inline void from_json(const nlohmann::json& j, GetUserLevelInformation::Post::Response::userLevelsItem& obj)
{
  j.at("isDefeatable").get_to(obj._isDefeatable);
  j.at("isEnabled").get_to(obj._isEnabled);
}

inline void to_json(nlohmann::ordered_json& j, GetUserLevelInformation::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"userLevels", obj._userLevels},
  };
}

inline void from_json(const nlohmann::json& j, GetUserLevelInformation::Post::Response& obj)
{
  j.at("userLevels").get_to(obj._userLevels);
}


inline void to_json(nlohmann::ordered_json& j, GenOpenFile::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Name", obj._Name},
      {"Mode", obj._Mode},
  };
}

inline void from_json(const nlohmann::json& j, GenOpenFile::Post::Request& obj)
{
  j.at("Name").get_to(obj._Name);
  j.at("Mode").get_to(obj._Mode);
}


inline void to_json(nlohmann::ordered_json& j, GenOpenFile::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
      {"FileHandle", obj._FileHandle},
  };
}

inline void from_json(const nlohmann::json& j, GenOpenFile::Post::Response& obj)
{
  j.at("State").get_to(obj._State);
  j.at("FileHandle").get_to(obj._FileHandle);
}


inline void to_json(nlohmann::ordered_json& j, GenCloseFile::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"FileHandle", obj._FileHandle},
  };
}

inline void from_json(const nlohmann::json& j, GenCloseFile::Post::Request& obj)
{
  j.at("FileHandle").get_to(obj._FileHandle);
}


inline void to_json(nlohmann::ordered_json& j, GenCloseFile::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
  };
}

inline void from_json(const nlohmann::json& j, GenCloseFile::Post::Response& obj)
{
  j.at("State").get_to(obj._State);
}


inline void to_json(nlohmann::ordered_json& j, GenReadFile::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"FileHandle", obj._FileHandle},
      {"SequenceNumber", obj._SequenceNumber},
  };
}

inline void from_json(const nlohmann::json& j, GenReadFile::Post::Request& obj)
{
  j.at("FileHandle").get_to(obj._FileHandle);
  j.at("SequenceNumber").get_to(obj._SequenceNumber);
}


inline void to_json(nlohmann::ordered_json& j, GenReadFile::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
      {"Data", obj._Data},
  };
}

inline void from_json(const nlohmann::json& j, GenReadFile::Post::Response& obj)
{
  j.at("State").get_to(obj._State);
  j.at("Data").get_to(obj._Data);
}


inline void to_json(nlohmann::ordered_json& j, GenWriteFile::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"FileHandle", obj._FileHandle},
      {"Data", obj._Data},
      {"SequenceNumber", obj._SequenceNumber},
  };
}

inline void from_json(const nlohmann::json& j, GenWriteFile::Post::Request& obj)
{
  j.at("FileHandle").get_to(obj._FileHandle);
  j.at("Data").get_to(obj._Data);
  j.at("SequenceNumber").get_to(obj._SequenceNumber);
}


inline void to_json(nlohmann::ordered_json& j, GenWriteFile::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
  };
}

inline void from_json(const nlohmann::json& j, GenWriteFile::Post::Response& obj)
{
  j.at("State").get_to(obj._State);
}


inline void to_json(nlohmann::ordered_json& j, GetFileSyncValue::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Name", obj._Name},
  };
}

inline void from_json(const nlohmann::json& j, GetFileSyncValue::Post::Request& obj)
{
  j.at("Name").get_to(obj._Name);
}


inline void to_json(nlohmann::ordered_json& j, GetFileSyncValue::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"HashValue", obj._HashValue},
  };
}

inline void from_json(const nlohmann::json& j, GetFileSyncValue::Post::Response& obj)
{
  j.at("HashValue").get_to(obj._HashValue);
}


inline void to_json(nlohmann::ordered_json& j, GetFileSize::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"FileHandle", obj._FileHandle},
  };
}

inline void from_json(const nlohmann::json& j, GetFileSize::Post::Request& obj)
{
  j.at("FileHandle").get_to(obj._FileHandle);
}


inline void to_json(nlohmann::ordered_json& j, GetFileSize::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
      {"FileSize", obj._FileSize},
  };
}

inline void from_json(const nlohmann::json& j, GetFileSize::Post::Response& obj)
{
  j.at("State").get_to(obj._State);
  j.at("FileSize").get_to(obj._FileSize);
}


inline void to_json(nlohmann::ordered_json& j, TypeCode::Get::Response const& obj)
{
  j = obj._TypeCode;
}

inline void from_json(const nlohmann::json& j, TypeCode::Get::Response& obj)
{
  j.get_to(obj._TypeCode);
}


inline void to_json(nlohmann::ordered_json& j, TypeCode::Post::Request const& obj)
{
  j = obj._TypeCode;
}

inline void from_json(const nlohmann::json& j, TypeCode::Post::Request& obj)
{
  j.get_to(obj._TypeCode);
}


inline void to_json(nlohmann::ordered_json& j, OrderNumber::Get::Response const& obj)
{
  j = obj._OrderNumber;
}

inline void from_json(const nlohmann::json& j, OrderNumber::Get::Response& obj)
{
  j.get_to(obj._OrderNumber);
}


inline void to_json(nlohmann::ordered_json& j, OrderNumber::Post::Request const& obj)
{
  j = obj._OrderNumber;
}

inline void from_json(const nlohmann::json& j, OrderNumber::Post::Request& obj)
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


inline void to_json(nlohmann::ordered_json& j, RequiredUserAction::Get::Response::RequiredUserAction const& obj)
{
  j = nlohmann::ordered_json{
      {"ConfirmConfiguration", obj._ConfirmConfiguration},
      {"CheckConfiguration", obj._CheckConfiguration},
      {"CheckEnvironment", obj._CheckEnvironment},
      {"CheckApplicationInterfaces", obj._CheckApplicationInterfaces},
      {"CheckDevice", obj._CheckDevice},
      {"RunSetupProcedure", obj._RunSetupProcedure},
      {"CheckFirmware", obj._CheckFirmware},
      {"Wait", obj._Wait},
      {"Reserved", obj._Reserved},
  };
}

inline void from_json(const nlohmann::json& j, RequiredUserAction::Get::Response::RequiredUserAction& obj)
{
  j.at("ConfirmConfiguration").get_to(obj._ConfirmConfiguration);
  j.at("CheckConfiguration").get_to(obj._CheckConfiguration);
  j.at("CheckEnvironment").get_to(obj._CheckEnvironment);
  j.at("CheckApplicationInterfaces").get_to(obj._CheckApplicationInterfaces);
  j.at("CheckDevice").get_to(obj._CheckDevice);
  j.at("RunSetupProcedure").get_to(obj._RunSetupProcedure);
  j.at("CheckFirmware").get_to(obj._CheckFirmware);
  j.at("Wait").get_to(obj._Wait);
  j.at("Reserved").get_to(obj._Reserved);
}

inline void to_json(nlohmann::ordered_json& j, RequiredUserAction::Get::Response const& obj)
{
  j = obj._RequiredUserAction;
}

inline void from_json(const nlohmann::json& j, RequiredUserAction::Get::Response& obj)
{
  j.get_to(obj._RequiredUserAction);
}


inline void to_json(nlohmann::ordered_json& j, DeviceName::Get::Response const& obj)
{
  j = obj._DeviceName;
}

inline void from_json(const nlohmann::json& j, DeviceName::Get::Response& obj)
{
  j.get_to(obj._DeviceName);
}


inline void to_json(nlohmann::ordered_json& j, DeviceName::Post::Request const& obj)
{
  j = obj._DeviceName;
}

inline void from_json(const nlohmann::json& j, DeviceName::Post::Request& obj)
{
  j.get_to(obj._DeviceName);
}


inline void to_json(nlohmann::ordered_json& j, ProjectName::Get::Response const& obj)
{
  j = obj._ProjectName;
}

inline void from_json(const nlohmann::json& j, ProjectName::Get::Response& obj)
{
  j.get_to(obj._ProjectName);
}


inline void to_json(nlohmann::ordered_json& j, ProjectName::Post::Request const& obj)
{
  j = obj._ProjectName;
}

inline void from_json(const nlohmann::json& j, ProjectName::Post::Request& obj)
{
  j.get_to(obj._ProjectName);
}


inline void to_json(nlohmann::ordered_json& j, ReadEeprom::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, ReadEeprom::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
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


inline void to_json(nlohmann::ordered_json& j, WriteCalibEeprom::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, WriteCalibEeprom::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, SCRebootNeedful::Get::Response const& obj)
{
  j = obj._SCRebootNeedful;
}

inline void from_json(const nlohmann::json& j, SCRebootNeedful::Get::Response& obj)
{
  j.get_to(obj._SCRebootNeedful);
}


inline void to_json(nlohmann::ordered_json& j, SCParamsChanged::Get::Response const& obj)
{
  j = obj._SCParamsChanged;
}

inline void from_json(const nlohmann::json& j, SCParamsChanged::Get::Response& obj)
{
  j.get_to(obj._SCParamsChanged);
}


inline void to_json(nlohmann::ordered_json& j, SCUserInterfaceVariant::Get::Response const& obj)
{
  j = obj._SCUserInterfaceVariant;
}

inline void from_json(const nlohmann::json& j, SCUserInterfaceVariant::Get::Response& obj)
{
  j.get_to(obj._SCUserInterfaceVariant);
}


inline void to_json(nlohmann::ordered_json& j, SCUserInterfaceVariant::Post::Request const& obj)
{
  j = obj._SCUserInterfaceVariant;
}

inline void from_json(const nlohmann::json& j, SCUserInterfaceVariant::Post::Request& obj)
{
  j.get_to(obj._SCUserInterfaceVariant);
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


inline void to_json(nlohmann::ordered_json& j, SetFilesImmutableFlag::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Immutable", obj._Immutable},
  };
}

inline void from_json(const nlohmann::json& j, SetFilesImmutableFlag::Post::Request& obj)
{
  j.at("Immutable").get_to(obj._Immutable);
}


inline void to_json(nlohmann::ordered_json& j, SetFilesImmutableFlag::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, SetFilesImmutableFlag::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, GetFilesImmutableFlag::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Immutable", obj._Immutable},
  };
}

inline void from_json(const nlohmann::json& j, GetFilesImmutableFlag::Post::Response& obj)
{
  j.at("Immutable").get_to(obj._Immutable);
}


inline void to_json(nlohmann::ordered_json& j, GetFilesProtectedByImmutableFlag::Post::Response::FileListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"FilePath", obj._FilePath},
      {"Immutable", obj._Immutable},
  };
}

inline void from_json(const nlohmann::json& j, GetFilesProtectedByImmutableFlag::Post::Response::FileListItem& obj)
{
  j.at("FilePath").get_to(obj._FilePath);
  j.at("Immutable").get_to(obj._Immutable);
}

inline void to_json(nlohmann::ordered_json& j, GetFilesProtectedByImmutableFlag::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"FileList", obj._FileList},
  };
}

inline void from_json(const nlohmann::json& j, GetFilesProtectedByImmutableFlag::Post::Response& obj)
{
  j.at("FileList").get_to(obj._FileList);
}


inline void to_json(nlohmann::ordered_json& j, FDSignature::Get::Response const& obj)
{
  j = obj._FDSignature;
}

inline void from_json(const nlohmann::json& j, FDSignature::Get::Response& obj)
{
  j.get_to(obj._FDSignature);
}


inline void to_json(nlohmann::ordered_json& j, Start2ndStageLoader::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Parameter", obj._Parameter},
  };
}

inline void from_json(const nlohmann::json& j, Start2ndStageLoader::Post::Request& obj)
{
  j.at("Parameter").get_to(obj._Parameter);
}


inline void to_json(nlohmann::ordered_json& j, Start2ndStageLoader::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
  };
}

inline void from_json(const nlohmann::json& j, Start2ndStageLoader::Post::Response& obj)
{
  j.at("Handle").get_to(obj._Handle);
}


inline void to_json(nlohmann::ordered_json& j, LogWrite::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"LogData", obj._LogData},
  };
}

inline void from_json(const nlohmann::json& j, LogWrite::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("LogData").get_to(obj._LogData);
}


inline void to_json(nlohmann::ordered_json& j, LogWrite::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, LogWrite::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, LogEnd::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
  };
}

inline void from_json(const nlohmann::json& j, LogEnd::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
}


inline void to_json(nlohmann::ordered_json& j, LogEnd::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, LogEnd::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, LogInfo::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Size", obj._Size},
  };
}

inline void from_json(const nlohmann::json& j, LogInfo::Post::Response& obj)
{
  j.at("Size").get_to(obj._Size);
}


inline void to_json(nlohmann::ordered_json& j, LogErase::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
  };
}

inline void from_json(const nlohmann::json& j, LogErase::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
}


inline void to_json(nlohmann::ordered_json& j, LogErase::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, LogErase::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, ETraceMsg::Get::Response const& obj)
{
  j = obj._ETraceMsg;
}

inline void from_json(const nlohmann::json& j, ETraceMsg::Get::Response& obj)
{
  j.get_to(obj._ETraceMsg);
}


inline void to_json(nlohmann::ordered_json& j, EMsgDebug::Get::Response::EMsgDebugItem::FirstTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgDebug::Get::Response::EMsgDebugItem::FirstTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgDebug::Get::Response::EMsgDebugItem::LastTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgDebug::Get::Response::EMsgDebugItem::LastTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgDebug::Get::Response::EMsgDebugItem const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorId", obj._ErrorId},
      {"ErrorState", obj._ErrorState},
      {"FirstTime", obj._FirstTime},
      {"LastTime", obj._LastTime},
      {"NumberOccurance", obj._NumberOccurance},
      {"ErrReserved", obj._ErrReserved},
      {"ExtInfo", obj._ExtInfo},
  };
}

inline void from_json(const nlohmann::json& j, EMsgDebug::Get::Response::EMsgDebugItem& obj)
{
  j.at("ErrorId").get_to(obj._ErrorId);
  j.at("ErrorState").get_to(obj._ErrorState);
  j.at("FirstTime").get_to(obj._FirstTime);
  j.at("LastTime").get_to(obj._LastTime);
  j.at("NumberOccurance").get_to(obj._NumberOccurance);
  j.at("ErrReserved").get_to(obj._ErrReserved);
  j.at("ExtInfo").get_to(obj._ExtInfo);
}

inline void to_json(nlohmann::ordered_json& j, EMsgDebug::Get::Response const& obj)
{
  j = obj._EMsgDebug;
}

inline void from_json(const nlohmann::json& j, EMsgDebug::Get::Response& obj)
{
  j.get_to(obj._EMsgDebug);
}


inline void to_json(nlohmann::ordered_json& j, EMsgInfo::Get::Response::EMsgInfoItem::FirstTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgInfo::Get::Response::EMsgInfoItem::FirstTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgInfo::Get::Response::EMsgInfoItem::LastTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgInfo::Get::Response::EMsgInfoItem::LastTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgInfo::Get::Response::EMsgInfoItem const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorId", obj._ErrorId},
      {"ErrorState", obj._ErrorState},
      {"FirstTime", obj._FirstTime},
      {"LastTime", obj._LastTime},
      {"NumberOccurance", obj._NumberOccurance},
      {"ErrReserved", obj._ErrReserved},
      {"ExtInfo", obj._ExtInfo},
  };
}

inline void from_json(const nlohmann::json& j, EMsgInfo::Get::Response::EMsgInfoItem& obj)
{
  j.at("ErrorId").get_to(obj._ErrorId);
  j.at("ErrorState").get_to(obj._ErrorState);
  j.at("FirstTime").get_to(obj._FirstTime);
  j.at("LastTime").get_to(obj._LastTime);
  j.at("NumberOccurance").get_to(obj._NumberOccurance);
  j.at("ErrReserved").get_to(obj._ErrReserved);
  j.at("ExtInfo").get_to(obj._ExtInfo);
}

inline void to_json(nlohmann::ordered_json& j, EMsgInfo::Get::Response const& obj)
{
  j = obj._EMsgInfo;
}

inline void from_json(const nlohmann::json& j, EMsgInfo::Get::Response& obj)
{
  j.get_to(obj._EMsgInfo);
}


inline void to_json(nlohmann::ordered_json& j, EMsgWarning::Get::Response::EMsgWarningItem::FirstTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgWarning::Get::Response::EMsgWarningItem::FirstTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgWarning::Get::Response::EMsgWarningItem::LastTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgWarning::Get::Response::EMsgWarningItem::LastTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgWarning::Get::Response::EMsgWarningItem const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorId", obj._ErrorId},
      {"ErrorState", obj._ErrorState},
      {"FirstTime", obj._FirstTime},
      {"LastTime", obj._LastTime},
      {"NumberOccurance", obj._NumberOccurance},
      {"ErrReserved", obj._ErrReserved},
      {"ExtInfo", obj._ExtInfo},
  };
}

inline void from_json(const nlohmann::json& j, EMsgWarning::Get::Response::EMsgWarningItem& obj)
{
  j.at("ErrorId").get_to(obj._ErrorId);
  j.at("ErrorState").get_to(obj._ErrorState);
  j.at("FirstTime").get_to(obj._FirstTime);
  j.at("LastTime").get_to(obj._LastTime);
  j.at("NumberOccurance").get_to(obj._NumberOccurance);
  j.at("ErrReserved").get_to(obj._ErrReserved);
  j.at("ExtInfo").get_to(obj._ExtInfo);
}

inline void to_json(nlohmann::ordered_json& j, EMsgWarning::Get::Response const& obj)
{
  j = obj._EMsgWarning;
}

inline void from_json(const nlohmann::json& j, EMsgWarning::Get::Response& obj)
{
  j.get_to(obj._EMsgWarning);
}


inline void to_json(nlohmann::ordered_json& j, EMsgError::Get::Response::EMsgErrorItem::FirstTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgError::Get::Response::EMsgErrorItem::FirstTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgError::Get::Response::EMsgErrorItem::LastTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgError::Get::Response::EMsgErrorItem::LastTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgError::Get::Response::EMsgErrorItem const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorId", obj._ErrorId},
      {"ErrorState", obj._ErrorState},
      {"FirstTime", obj._FirstTime},
      {"LastTime", obj._LastTime},
      {"NumberOccurance", obj._NumberOccurance},
      {"ErrReserved", obj._ErrReserved},
      {"ExtInfo", obj._ExtInfo},
  };
}

inline void from_json(const nlohmann::json& j, EMsgError::Get::Response::EMsgErrorItem& obj)
{
  j.at("ErrorId").get_to(obj._ErrorId);
  j.at("ErrorState").get_to(obj._ErrorState);
  j.at("FirstTime").get_to(obj._FirstTime);
  j.at("LastTime").get_to(obj._LastTime);
  j.at("NumberOccurance").get_to(obj._NumberOccurance);
  j.at("ErrReserved").get_to(obj._ErrReserved);
  j.at("ExtInfo").get_to(obj._ExtInfo);
}

inline void to_json(nlohmann::ordered_json& j, EMsgError::Get::Response const& obj)
{
  j = obj._EMsgError;
}

inline void from_json(const nlohmann::json& j, EMsgError::Get::Response& obj)
{
  j.get_to(obj._EMsgError);
}


inline void to_json(nlohmann::ordered_json& j, EMsgFatal::Get::Response::EMsgFatalItem::FirstTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgFatal::Get::Response::EMsgFatalItem::FirstTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgFatal::Get::Response::EMsgFatalItem::LastTime const& obj)
{
  j = nlohmann::ordered_json{
      {"PwrOnCnt", obj._PwrOnCnt},
      {"OpSecs", obj._OpSecs},
      {"TimeOccur", obj._TimeOccur},
  };
}

inline void from_json(const nlohmann::json& j, EMsgFatal::Get::Response::EMsgFatalItem::LastTime& obj)
{
  j.at("PwrOnCnt").get_to(obj._PwrOnCnt);
  j.at("OpSecs").get_to(obj._OpSecs);
  j.at("TimeOccur").get_to(obj._TimeOccur);
}

inline void to_json(nlohmann::ordered_json& j, EMsgFatal::Get::Response::EMsgFatalItem const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorId", obj._ErrorId},
      {"ErrorState", obj._ErrorState},
      {"FirstTime", obj._FirstTime},
      {"LastTime", obj._LastTime},
      {"NumberOccurance", obj._NumberOccurance},
      {"ErrReserved", obj._ErrReserved},
      {"ExtInfo", obj._ExtInfo},
  };
}

inline void from_json(const nlohmann::json& j, EMsgFatal::Get::Response::EMsgFatalItem& obj)
{
  j.at("ErrorId").get_to(obj._ErrorId);
  j.at("ErrorState").get_to(obj._ErrorState);
  j.at("FirstTime").get_to(obj._FirstTime);
  j.at("LastTime").get_to(obj._LastTime);
  j.at("NumberOccurance").get_to(obj._NumberOccurance);
  j.at("ErrReserved").get_to(obj._ErrReserved);
  j.at("ExtInfo").get_to(obj._ExtInfo);
}

inline void to_json(nlohmann::ordered_json& j, EMsgFatal::Get::Response const& obj)
{
  j = obj._EMsgFatal;
}

inline void from_json(const nlohmann::json& j, EMsgFatal::Get::Response& obj)
{
  j.get_to(obj._EMsgFatal);
}


inline void to_json(nlohmann::ordered_json& j, ClearErrorMessages::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ulError", obj._ulError},
  };
}

inline void from_json(const nlohmann::json& j, ClearErrorMessages::Post::Response& obj)
{
  j.at("ulError").get_to(obj._ulError);
}


inline void to_json(nlohmann::ordered_json& j, ClearErrorMessagesSickService::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ulError", obj._ulError},
  };
}

inline void from_json(const nlohmann::json& j, ClearErrorMessagesSickService::Post::Response& obj)
{
  j.at("ulError").get_to(obj._ulError);
}


inline void to_json(nlohmann::ordered_json& j, LastUsername::Get::Response const& obj)
{
  j = obj._LastUsername;
}

inline void from_json(const nlohmann::json& j, LastUsername::Get::Response& obj)
{
  j.get_to(obj._LastUsername);
}


inline void to_json(nlohmann::ordered_json& j, LastUsername::Post::Request const& obj)
{
  j = obj._LastUsername;
}

inline void from_json(const nlohmann::json& j, LastUsername::Post::Request& obj)
{
  j.get_to(obj._LastUsername);
}


inline void to_json(nlohmann::ordered_json& j, LastParaDate::Get::Response const& obj)
{
  j = obj._LastParaDate;
}

inline void from_json(const nlohmann::json& j, LastParaDate::Get::Response& obj)
{
  j.get_to(obj._LastParaDate);
}


inline void to_json(nlohmann::ordered_json& j, LastParaDate::Post::Request const& obj)
{
  j = obj._LastParaDate;
}

inline void from_json(const nlohmann::json& j, LastParaDate::Post::Request& obj)
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


inline void to_json(nlohmann::ordered_json& j, LastParaTime::Post::Request const& obj)
{
  j = obj._LastParaTime;
}

inline void from_json(const nlohmann::json& j, LastParaTime::Post::Request& obj)
{
  j.get_to(obj._LastParaTime);
}


inline void to_json(nlohmann::ordered_json& j, LastUsernameTemp::Get::Response const& obj)
{
  j = obj._LastUsernameTemp;
}

inline void from_json(const nlohmann::json& j, LastUsernameTemp::Get::Response& obj)
{
  j.get_to(obj._LastUsernameTemp);
}


inline void to_json(nlohmann::ordered_json& j, LastParaDateTemp::Get::Response const& obj)
{
  j = obj._LastParaDateTemp;
}

inline void from_json(const nlohmann::json& j, LastParaDateTemp::Get::Response& obj)
{
  j.get_to(obj._LastParaDateTemp);
}


inline void to_json(nlohmann::ordered_json& j, LastParaTimeTemp::Get::Response const& obj)
{
  j = obj._LastParaTimeTemp;
}

inline void from_json(const nlohmann::json& j, LastParaTimeTemp::Get::Response& obj)
{
  j.get_to(obj._LastParaTimeTemp);
}


inline void to_json(nlohmann::ordered_json& j, LastMaintenance::Get::Response const& obj)
{
  j = obj._LastMaintenance;
}

inline void from_json(const nlohmann::json& j, LastMaintenance::Get::Response& obj)
{
  j.get_to(obj._LastMaintenance);
}


inline void to_json(nlohmann::ordered_json& j, LastMaintenance::Post::Request const& obj)
{
  j = obj._LastMaintenance;
}

inline void from_json(const nlohmann::json& j, LastMaintenance::Post::Request& obj)
{
  j.get_to(obj._LastMaintenance);
}


inline void to_json(nlohmann::ordered_json& j, NextMaintenance::Get::Response const& obj)
{
  j = obj._NextMaintenance;
}

inline void from_json(const nlohmann::json& j, NextMaintenance::Get::Response& obj)
{
  j.get_to(obj._NextMaintenance);
}


inline void to_json(nlohmann::ordered_json& j, NextMaintenance::Post::Request const& obj)
{
  j = obj._NextMaintenance;
}

inline void from_json(const nlohmann::json& j, NextMaintenance::Post::Request& obj)
{
  j.get_to(obj._NextMaintenance);
}


inline void to_json(nlohmann::ordered_json& j, GoReadyCount::Get::Response const& obj)
{
  j = obj._GoReadyCount;
}

inline void from_json(const nlohmann::json& j, GoReadyCount::Get::Response& obj)
{
  j.get_to(obj._GoReadyCount);
}


inline void to_json(nlohmann::ordered_json& j, GoReadyCount::Post::Request const& obj)
{
  j = obj._GoReadyCount;
}

inline void from_json(const nlohmann::json& j, GoReadyCount::Post::Request& obj)
{
  j.get_to(obj._GoReadyCount);
}


inline void to_json(nlohmann::ordered_json& j, SetLastUser::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"LastUser", obj._LastUser},
      {"LastParaDate", obj._LastParaDate},
      {"LastParaTime", obj._LastParaTime},
  };
}

inline void from_json(const nlohmann::json& j, SetLastUser::Post::Request& obj)
{
  j.at("LastUser").get_to(obj._LastUser);
  j.at("LastParaDate").get_to(obj._LastParaDate);
  j.at("LastParaTime").get_to(obj._LastParaTime);
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


inline void to_json(nlohmann::ordered_json& j, GetDiagnosisDumpPath::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"DiagDumpPath", obj._DiagDumpPath},
  };
}

inline void from_json(const nlohmann::json& j, GetDiagnosisDumpPath::Post::Response& obj)
{
  j.at("DiagDumpPath").get_to(obj._DiagDumpPath);
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


inline void to_json(nlohmann::ordered_json& j, NotificationList::Get::Response::NotificationListItem::FirstOccurrence const& obj)
{
  j = nlohmann::ordered_json{
      {"PowerOnCount", obj._PowerOnCount},
      {"OpSeconds", obj._OpSeconds},
      {"Datetime", obj._Datetime},
  };
}

inline void from_json(const nlohmann::json& j, NotificationList::Get::Response::NotificationListItem::FirstOccurrence& obj)
{
  j.at("PowerOnCount").get_to(obj._PowerOnCount);
  j.at("OpSeconds").get_to(obj._OpSeconds);
  j.at("Datetime").get_to(obj._Datetime);
}

inline void to_json(nlohmann::ordered_json& j, NotificationList::Get::Response::NotificationListItem::LastOccurrence const& obj)
{
  j = nlohmann::ordered_json{
      {"PowerOnCount", obj._PowerOnCount},
      {"OpSeconds", obj._OpSeconds},
      {"Datetime", obj._Datetime},
  };
}

inline void from_json(const nlohmann::json& j, NotificationList::Get::Response::NotificationListItem::LastOccurrence& obj)
{
  j.at("PowerOnCount").get_to(obj._PowerOnCount);
  j.at("OpSeconds").get_to(obj._OpSeconds);
  j.at("Datetime").get_to(obj._Datetime);
}

inline void to_json(nlohmann::ordered_json& j, NotificationList::Get::Response::NotificationListItem::LastResolved const& obj)
{
  j = nlohmann::ordered_json{
      {"PowerOnCount", obj._PowerOnCount},
      {"OpSeconds", obj._OpSeconds},
      {"Datetime", obj._Datetime},
  };
}

inline void from_json(const nlohmann::json& j, NotificationList::Get::Response::NotificationListItem::LastResolved& obj)
{
  j.at("PowerOnCount").get_to(obj._PowerOnCount);
  j.at("OpSeconds").get_to(obj._OpSeconds);
  j.at("Datetime").get_to(obj._Datetime);
}

inline void to_json(nlohmann::ordered_json& j, NotificationList::Get::Response::NotificationListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Id", obj._Id},
      {"State", obj._State},
      {"NotificationGroup", obj._NotificationGroup},
      {"Severity", obj._Severity},
      {"FirstOccurrence", obj._FirstOccurrence},
      {"LastOccurrence", obj._LastOccurrence},
      {"LastResolved", obj._LastResolved},
      {"OccurrenceCount", obj._OccurrenceCount},
      {"AdditionalInfo", obj._AdditionalInfo},
  };
}

inline void from_json(const nlohmann::json& j, NotificationList::Get::Response::NotificationListItem& obj)
{
  j.at("Id").get_to(obj._Id);
  j.at("State").get_to(obj._State);
  j.at("NotificationGroup").get_to(obj._NotificationGroup);
  j.at("Severity").get_to(obj._Severity);
  j.at("FirstOccurrence").get_to(obj._FirstOccurrence);
  j.at("LastOccurrence").get_to(obj._LastOccurrence);
  j.at("LastResolved").get_to(obj._LastResolved);
  j.at("OccurrenceCount").get_to(obj._OccurrenceCount);
  j.at("AdditionalInfo").get_to(obj._AdditionalInfo);
}

inline void to_json(nlohmann::ordered_json& j, NotificationList::Get::Response const& obj)
{
  j = obj._NotificationList;
}

inline void from_json(const nlohmann::json& j, NotificationList::Get::Response& obj)
{
  j.get_to(obj._NotificationList);
}


inline void to_json(nlohmann::ordered_json& j, ClearNotifications::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bSuccess", obj._bSuccess},
  };
}

inline void from_json(const nlohmann::json& j, ClearNotifications::Post::Response& obj)
{
  j.at("bSuccess").get_to(obj._bSuccess);
}


inline void to_json(nlohmann::ordered_json& j, SystemConfigData::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"Identifier", obj._Identifier},
      {"Data", obj._Data},
  };
}

inline void from_json(const nlohmann::json& j, SystemConfigData::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("Identifier").get_to(obj._Identifier);
  j.at("Data").get_to(obj._Data);
}


inline void to_json(nlohmann::ordered_json& j, SystemConfigData::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, SystemConfigData::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, ProgramConfigData::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"Device", obj._Device},
      {"Identifier", obj._Identifier},
      {"Data", obj._Data},
  };
}

inline void from_json(const nlohmann::json& j, ProgramConfigData::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("Device").get_to(obj._Device);
  j.at("Identifier").get_to(obj._Identifier);
  j.at("Data").get_to(obj._Data);
}


inline void to_json(nlohmann::ordered_json& j, ProgramConfigData::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, ProgramConfigData::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, ProgramData::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"Device", obj._Device},
      {"BlockSize", obj._BlockSize},
      {"Data", obj._Data},
  };
}

inline void from_json(const nlohmann::json& j, ProgramData::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("Device").get_to(obj._Device);
  j.at("BlockSize").get_to(obj._BlockSize);
  j.at("Data").get_to(obj._Data);
}


inline void to_json(nlohmann::ordered_json& j, ProgramData::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, ProgramData::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, ProgramDataTransferSize::Get::Response const& obj)
{
  j = obj._ProgramDataTransferSize;
}

inline void from_json(const nlohmann::json& j, ProgramDataTransferSize::Get::Response& obj)
{
  j.get_to(obj._ProgramDataTransferSize);
}


inline void to_json(nlohmann::ordered_json& j, ExecuteDownload::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"Device", obj._Device},
  };
}

inline void from_json(const nlohmann::json& j, ExecuteDownload::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("Device").get_to(obj._Device);
}


inline void to_json(nlohmann::ordered_json& j, ExecuteDownload::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, ExecuteDownload::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, StatusDownload::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"Device", obj._Device},
  };
}

inline void from_json(const nlohmann::json& j, StatusDownload::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("Device").get_to(obj._Device);
}


inline void to_json(nlohmann::ordered_json& j, StatusDownload::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Status", obj._Status},
  };
}

inline void from_json(const nlohmann::json& j, StatusDownload::Post::Response& obj)
{
  j.at("Status").get_to(obj._Status);
}


inline void to_json(nlohmann::ordered_json& j, FinishDownload::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"Device", obj._Device},
  };
}

inline void from_json(const nlohmann::json& j, FinishDownload::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("Device").get_to(obj._Device);
}


inline void to_json(nlohmann::ordered_json& j, FinishDownload::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, FinishDownload::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, AbortDownload::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Handle", obj._Handle},
      {"Device", obj._Device},
  };
}

inline void from_json(const nlohmann::json& j, AbortDownload::Post::Request& obj)
{
  j.at("Handle").get_to(obj._Handle);
  j.at("Device").get_to(obj._Device);
}


inline void to_json(nlohmann::ordered_json& j, AbortDownload::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, AbortDownload::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
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


inline void to_json(nlohmann::ordered_json& j, EtherIPSpeedDuplex::Get::Response const& obj)
{
  j = obj._EtherIPSpeedDuplex;
}

inline void from_json(const nlohmann::json& j, EtherIPSpeedDuplex::Get::Response& obj)
{
  j.get_to(obj._EtherIPSpeedDuplex);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPSpeedDuplex::Post::Request const& obj)
{
  j = obj._EtherIPSpeedDuplex;
}

inline void from_json(const nlohmann::json& j, EtherIPSpeedDuplex::Post::Request& obj)
{
  j.get_to(obj._EtherIPSpeedDuplex);
}


inline void to_json(nlohmann::ordered_json& j, EtherHostIPPort::Get::Response const& obj)
{
  j = obj._EtherHostIPPort;
}

inline void from_json(const nlohmann::json& j, EtherHostIPPort::Get::Response& obj)
{
  j.get_to(obj._EtherHostIPPort);
}


inline void to_json(nlohmann::ordered_json& j, EtherHostCoLaDialect::Get::Response const& obj)
{
  j = obj._EtherHostCoLaDialect;
}

inline void from_json(const nlohmann::json& j, EtherHostCoLaDialect::Get::Response& obj)
{
  j.get_to(obj._EtherHostCoLaDialect);
}


inline void to_json(nlohmann::ordered_json& j, EtherAuxIPPort::Get::Response const& obj)
{
  j = obj._EtherAuxIPPort;
}

inline void from_json(const nlohmann::json& j, EtherAuxIPPort::Get::Response& obj)
{
  j.get_to(obj._EtherAuxIPPort);
}


inline void to_json(nlohmann::ordered_json& j, EtherAuxCoLaDialect::Get::Response const& obj)
{
  j = obj._EtherAuxCoLaDialect;
}

inline void from_json(const nlohmann::json& j, EtherAuxCoLaDialect::Get::Response& obj)
{
  j.get_to(obj._EtherAuxCoLaDialect);
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


inline void to_json(nlohmann::ordered_json& j, EtherCoLa2Enabled::Get::Response const& obj)
{
  j = obj._EtherCoLa2Enabled;
}

inline void from_json(const nlohmann::json& j, EtherCoLa2Enabled::Get::Response& obj)
{
  j.get_to(obj._EtherCoLa2Enabled);
}


inline void to_json(nlohmann::ordered_json& j, EtherCoLa2Enabled::Post::Request const& obj)
{
  j = obj._EtherCoLa2Enabled;
}

inline void from_json(const nlohmann::json& j, EtherCoLa2Enabled::Post::Request& obj)
{
  j.get_to(obj._EtherCoLa2Enabled);
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


inline void to_json(nlohmann::ordered_json& j, EtherUpdateNeeded::Get::Response const& obj)
{
  j = obj._EtherUpdateNeeded;
}

inline void from_json(const nlohmann::json& j, EtherUpdateNeeded::Get::Response& obj)
{
  j.get_to(obj._EtherUpdateNeeded);
}


inline void to_json(nlohmann::ordered_json& j, EtherUpdateNeeded::Post::Request const& obj)
{
  j = obj._EtherUpdateNeeded;
}

inline void from_json(const nlohmann::json& j, EtherUpdateNeeded::Post::Request& obj)
{
  j.get_to(obj._EtherUpdateNeeded);
}


inline void to_json(nlohmann::ordered_json& j, EthernetPing::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"IPAddress", obj._IPAddress},
      {"Timeout", obj._Timeout},
      {"InterfaceNumber", obj._InterfaceNumber},
  };
}

inline void from_json(const nlohmann::json& j, EthernetPing::Post::Request& obj)
{
  j.at("IPAddress").get_to(obj._IPAddress);
  j.at("Timeout").get_to(obj._Timeout);
  j.at("InterfaceNumber").get_to(obj._InterfaceNumber);
}


inline void to_json(nlohmann::ordered_json& j, EthernetPing::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, EthernetPing::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, EtherIPSpeedDuplexNegotiated::Get::Response const& obj)
{
  j = obj._EtherIPSpeedDuplexNegotiated;
}

inline void from_json(const nlohmann::json& j, EtherIPSpeedDuplexNegotiated::Get::Response& obj)
{
  j.get_to(obj._EtherIPSpeedDuplexNegotiated);
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


inline void to_json(nlohmann::ordered_json& j, EtherLinkState::Get::Response const& obj)
{
  j = obj._EtherLinkState;
}

inline void from_json(const nlohmann::json& j, EtherLinkState::Get::Response& obj)
{
  j.get_to(obj._EtherLinkState);
}


inline void to_json(nlohmann::ordered_json& j, FileSystemAccess::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"URL", obj._URL},
      {"Buffer", obj._Buffer},
      {"BufferCRC", obj._BufferCRC},
  };
}

inline void from_json(const nlohmann::json& j, FileSystemAccess::Post::Request& obj)
{
  j.at("URL").get_to(obj._URL);
  j.at("Buffer").get_to(obj._Buffer);
  j.at("BufferCRC").get_to(obj._BufferCRC);
}


inline void to_json(nlohmann::ordered_json& j, FileSystemAccess::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"URL", obj._URL},
      {"Buffer", obj._Buffer},
      {"BufferCRC", obj._BufferCRC},
  };
}

inline void from_json(const nlohmann::json& j, FileSystemAccess::Post::Response& obj)
{
  j.at("URL").get_to(obj._URL);
  j.at("Buffer").get_to(obj._Buffer);
  j.at("BufferCRC").get_to(obj._BufferCRC);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineVersion::Get::Response const& obj)
{
  j = obj._AppEngineVersion;
}

inline void from_json(const nlohmann::json& j, AppEngineVersion::Get::Response& obj)
{
  j.get_to(obj._AppEngineVersion);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineVersion::Post::Request const& obj)
{
  j = obj._AppEngineVersion;
}

inline void from_json(const nlohmann::json& j, AppEngineVersion::Post::Request& obj)
{
  j.get_to(obj._AppEngineVersion);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineLockAppDev::Get::Response const& obj)
{
  j = obj._AppEngineLockAppDev;
}

inline void from_json(const nlohmann::json& j, AppEngineLockAppDev::Get::Response& obj)
{
  j.get_to(obj._AppEngineLockAppDev);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineLockAppDev::Post::Request const& obj)
{
  j = obj._AppEngineLockAppDev;
}

inline void from_json(const nlohmann::json& j, AppEngineLockAppDev::Post::Request& obj)
{
  j.get_to(obj._AppEngineLockAppDev);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineDevSysApps::Get::Response const& obj)
{
  j = obj._AppEngineDevSysApps;
}

inline void from_json(const nlohmann::json& j, AppEngineDevSysApps::Get::Response& obj)
{
  j.get_to(obj._AppEngineDevSysApps);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineDevSysApps::Post::Request const& obj)
{
  j = obj._AppEngineDevSysApps;
}

inline void from_json(const nlohmann::json& j, AppEngineDevSysApps::Post::Request& obj)
{
  j.get_to(obj._AppEngineDevSysApps);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineDefaultWebpage::Get::Response const& obj)
{
  j = obj._AppEngineDefaultWebpage;
}

inline void from_json(const nlohmann::json& j, AppEngineDefaultWebpage::Get::Response& obj)
{
  j.get_to(obj._AppEngineDefaultWebpage);
}


inline void to_json(nlohmann::ordered_json& j, AppEngineDefaultWebpage::Post::Request const& obj)
{
  j = obj._AppEngineDefaultWebpage;
}

inline void from_json(const nlohmann::json& j, AppEngineDefaultWebpage::Post::Request& obj)
{
  j.get_to(obj._AppEngineDefaultWebpage);
}


inline void to_json(nlohmann::ordered_json& j, AppConsoleOutput::Get::Response const& obj)
{
  j = obj._AppConsoleOutput;
}

inline void from_json(const nlohmann::json& j, AppConsoleOutput::Get::Response& obj)
{
  j.get_to(obj._AppConsoleOutput);
}


inline void to_json(nlohmann::ordered_json& j, AppDebugEnvironment::Get::Response const& obj)
{
  j = obj._AppDebugEnvironment;
}

inline void from_json(const nlohmann::json& j, AppDebugEnvironment::Get::Response& obj)
{
  j.get_to(obj._AppDebugEnvironment);
}


inline void to_json(nlohmann::ordered_json& j, AppCommand::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"SLCmd", obj._SLCmd},
  };
}

inline void from_json(const nlohmann::json& j, AppCommand::Post::Request& obj)
{
  j.at("SLCmd").get_to(obj._SLCmd);
}


inline void to_json(nlohmann::ordered_json& j, AppCommand::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, AppCommand::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, PluginsFolder::Get::Response const& obj)
{
  j = obj._PluginsFolder;
}

inline void from_json(const nlohmann::json& j, PluginsFolder::Get::Response& obj)
{
  j.get_to(obj._PluginsFolder);
}


inline void to_json(nlohmann::ordered_json& j, PluginsFolder::Post::Request const& obj)
{
  j = obj._PluginsFolder;
}

inline void from_json(const nlohmann::json& j, PluginsFolder::Post::Request& obj)
{
  j.get_to(obj._PluginsFolder);
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


inline void to_json(nlohmann::ordered_json& j, EnableExtendedManifest::Get::Response const& obj)
{
  j = obj._EnableExtendedManifest;
}

inline void from_json(const nlohmann::json& j, EnableExtendedManifest::Get::Response& obj)
{
  j.get_to(obj._EnableExtendedManifest);
}


inline void to_json(nlohmann::ordered_json& j, EnableExtendedManifest::Post::Request const& obj)
{
  j = obj._EnableExtendedManifest;
}

inline void from_json(const nlohmann::json& j, EnableExtendedManifest::Post::Request& obj)
{
  j.get_to(obj._EnableExtendedManifest);
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


inline void to_json(nlohmann::ordered_json& j, SetSSHEnabled::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Enable", obj._Enable},
  };
}

inline void from_json(const nlohmann::json& j, SetSSHEnabled::Post::Request& obj)
{
  j.at("Enable").get_to(obj._Enable);
}


inline void to_json(nlohmann::ordered_json& j, isSshEnabled::Get::Response const& obj)
{
  j = obj._isSshEnabled;
}

inline void from_json(const nlohmann::json& j, isSshEnabled::Get::Response& obj)
{
  j.get_to(obj._isSshEnabled);
}


inline void to_json(nlohmann::ordered_json& j, ValidUserLevels::Get::Response const& obj)
{
  j = obj._ValidUserLevels;
}

inline void from_json(const nlohmann::json& j, ValidUserLevels::Get::Response& obj)
{
  j.get_to(obj._ValidUserLevels);
}


inline void to_json(nlohmann::ordered_json& j, ValidUserLevels::Post::Request const& obj)
{
  j = obj._ValidUserLevels;
}

inline void from_json(const nlohmann::json& j, ValidUserLevels::Post::Request& obj)
{
  j.get_to(obj._ValidUserLevels);
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


inline void to_json(nlohmann::ordered_json& j, acceptDevFirmware::Get::Response const& obj)
{
  j = obj._acceptDevFirmware;
}

inline void from_json(const nlohmann::json& j, acceptDevFirmware::Get::Response& obj)
{
  j.get_to(obj._acceptDevFirmware);
}


inline void to_json(nlohmann::ordered_json& j, acceptDevFirmware::Post::Request const& obj)
{
  j = obj._acceptDevFirmware;
}

inline void from_json(const nlohmann::json& j, acceptDevFirmware::Post::Request& obj)
{
  j.get_to(obj._acceptDevFirmware);
}


inline void to_json(nlohmann::ordered_json& j, DisableEyeSafety::Get::Response const& obj)
{
  j = obj._DisableEyeSafety;
}

inline void from_json(const nlohmann::json& j, DisableEyeSafety::Get::Response& obj)
{
  j.get_to(obj._DisableEyeSafety);
}


inline void to_json(nlohmann::ordered_json& j, DisableEyeSafety::Post::Request const& obj)
{
  j = obj._DisableEyeSafety;
}

inline void from_json(const nlohmann::json& j, DisableEyeSafety::Post::Request& obj)
{
  j.get_to(obj._DisableEyeSafety);
}


inline void to_json(nlohmann::ordered_json& j, DeviceTime::Get::Response const& obj)
{
  j = obj._DeviceTime;
}

inline void from_json(const nlohmann::json& j, DeviceTime::Get::Response& obj)
{
  j.get_to(obj._DeviceTime);
}


inline void to_json(nlohmann::ordered_json& j, DeviceTime::Post::Request const& obj)
{
  j = obj._DeviceTime;
}

inline void from_json(const nlohmann::json& j, DeviceTime::Post::Request& obj)
{
  j.get_to(obj._DeviceTime);
}


inline void to_json(nlohmann::ordered_json& j, EtherMACAddress::Get::Response const& obj)
{
  j = obj._EtherMACAddress;
}

inline void from_json(const nlohmann::json& j, EtherMACAddress::Get::Response& obj)
{
  j.get_to(obj._EtherMACAddress);
}


inline void to_json(nlohmann::ordered_json& j, EtherMACAddress::Post::Request const& obj)
{
  j = obj._EtherMACAddress;
}

inline void from_json(const nlohmann::json& j, EtherMACAddress::Post::Request& obj)
{
  j.get_to(obj._EtherMACAddress);
}


inline void to_json(nlohmann::ordered_json& j, LedBrightnessFactor::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Red", obj._Red},
      {"Green", obj._Green},
      {"Blue", obj._Blue},
  };
}

inline void from_json(const nlohmann::json& j, LedBrightnessFactor::Get::Response& obj)
{
  j.at("Red").get_to(obj._Red);
  j.at("Green").get_to(obj._Green);
  j.at("Blue").get_to(obj._Blue);
}


inline void to_json(nlohmann::ordered_json& j, LedBrightnessFactor::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Red", obj._Red},
      {"Green", obj._Green},
      {"Blue", obj._Blue},
  };
}

inline void from_json(const nlohmann::json& j, LedBrightnessFactor::Post::Request& obj)
{
  j.at("Red").get_to(obj._Red);
  j.at("Green").get_to(obj._Green);
  j.at("Blue").get_to(obj._Blue);
}


inline void to_json(nlohmann::ordered_json& j, LedGammaCorrectionTable::Get::Response const& obj)
{
  j = obj._LedGammaCorrectionTable;
}

inline void from_json(const nlohmann::json& j, LedGammaCorrectionTable::Get::Response& obj)
{
  j.get_to(obj._LedGammaCorrectionTable);
}


inline void to_json(nlohmann::ordered_json& j, LedGammaCorrectionTable::Post::Request const& obj)
{
  j = obj._LedGammaCorrectionTable;
}

inline void from_json(const nlohmann::json& j, LedGammaCorrectionTable::Post::Request& obj)
{
  j.get_to(obj._LedGammaCorrectionTable);
}


inline void to_json(nlohmann::ordered_json& j, StoreCustomerDefaultParameters::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, StoreCustomerDefaultParameters::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, RestoreUserCustomerParameters::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, RestoreUserCustomerParameters::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, StoreUserFactoryParameters::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, StoreUserFactoryParameters::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, RemoveUserFactoryParameters::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Success", obj._Success},
  };
}

inline void from_json(const nlohmann::json& j, RemoveUserFactoryParameters::Post::Response& obj)
{
  j.at("Success").get_to(obj._Success);
}


inline void to_json(nlohmann::ordered_json& j, PRODSetDeliveryState::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ulError", obj._ulError},
  };
}

inline void from_json(const nlohmann::json& j, PRODSetDeliveryState::Post::Response& obj)
{
  j.at("ulError").get_to(obj._ulError);
}


inline void to_json(nlohmann::ordered_json& j, PowerOnCnt::Get::Response const& obj)
{
  j = obj._PowerOnCnt;
}

inline void from_json(const nlohmann::json& j, PowerOnCnt::Get::Response& obj)
{
  j.get_to(obj._PowerOnCnt);
}


inline void to_json(nlohmann::ordered_json& j, PowerOnCnt::Post::Request const& obj)
{
  j = obj._PowerOnCnt;
}

inline void from_json(const nlohmann::json& j, PowerOnCnt::Post::Request& obj)
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


inline void to_json(nlohmann::ordered_json& j, DailyOpHours::Post::Request const& obj)
{
  j = obj._DailyOpHours;
}

inline void from_json(const nlohmann::json& j, DailyOpHours::Post::Request& obj)
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


inline void to_json(nlohmann::ordered_json& j, OpHours::Post::Request const& obj)
{
  j = obj._OpHours;
}

inline void from_json(const nlohmann::json& j, OpHours::Post::Request& obj)
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


inline void to_json(nlohmann::ordered_json& j, DeviceType::Post::Request const& obj)
{
  j = obj._DeviceType;
}

inline void from_json(const nlohmann::json& j, DeviceType::Post::Request& obj)
{
  j.get_to(obj._DeviceType);
}


inline void to_json(nlohmann::ordered_json& j, Manufacturer::Get::Response const& obj)
{
  j = obj._Manufacturer;
}

inline void from_json(const nlohmann::json& j, Manufacturer::Get::Response& obj)
{
  j.get_to(obj._Manufacturer);
}


inline void to_json(nlohmann::ordered_json& j, Manufacturer::Post::Request const& obj)
{
  j = obj._Manufacturer;
}

inline void from_json(const nlohmann::json& j, Manufacturer::Post::Request& obj)
{
  j.get_to(obj._Manufacturer);
}


inline void to_json(nlohmann::ordered_json& j, OrderNumberCompat::Get::Response const& obj)
{
  j = obj._OrderNumberCompat;
}

inline void from_json(const nlohmann::json& j, OrderNumberCompat::Get::Response& obj)
{
  j.get_to(obj._OrderNumberCompat);
}


inline void to_json(nlohmann::ordered_json& j, OrderNumberCompat::Post::Request const& obj)
{
  j = obj._OrderNumberCompat;
}

inline void from_json(const nlohmann::json& j, OrderNumberCompat::Post::Request& obj)
{
  j.get_to(obj._OrderNumberCompat);
}


inline void to_json(nlohmann::ordered_json& j, HasEthernet::Get::Response const& obj)
{
  j = obj._HasEthernet;
}

inline void from_json(const nlohmann::json& j, HasEthernet::Get::Response& obj)
{
  j.get_to(obj._HasEthernet);
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


inline void to_json(nlohmann::ordered_json& j, CreateParameterBackupDev::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Passphrase", obj._Passphrase},
  };
}

inline void from_json(const nlohmann::json& j, CreateParameterBackupDev::Post::Request& obj)
{
  j.at("Passphrase").get_to(obj._Passphrase);
}


inline void to_json(nlohmann::ordered_json& j, CreateParameterBackupDev::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Result", obj._Result},
  };
}

inline void from_json(const nlohmann::json& j, CreateParameterBackupDev::Post::Response& obj)
{
  j.at("Result").get_to(obj._Result);
}


inline void to_json(nlohmann::ordered_json& j, SCdevicestate::Get::Response const& obj)
{
  j = obj._SCdevicestate;
}

inline void from_json(const nlohmann::json& j, SCdevicestate::Get::Response& obj)
{
  j.get_to(obj._SCdevicestate);
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


inline void to_json(nlohmann::ordered_json& j, ContaminationActiveSectors::Get::Response const& obj)
{
  j = obj._ContaminationActiveSectors;
}

inline void from_json(const nlohmann::json& j, ContaminationActiveSectors::Get::Response& obj)
{
  j.get_to(obj._ContaminationActiveSectors);
}


inline void to_json(nlohmann::ordered_json& j, ContaminationData::Get::Response const& obj)
{
  j = obj._ContaminationData;
}

inline void from_json(const nlohmann::json& j, ContaminationData::Get::Response& obj)
{
  j.get_to(obj._ContaminationData);
}


inline void to_json(nlohmann::ordered_json& j, ContaminationResult::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bWarningActive", obj._bWarningActive},
      {"bErrorActive", obj._bErrorActive},
  };
}

inline void from_json(const nlohmann::json& j, ContaminationResult::Get::Response& obj)
{
  j.at("bWarningActive").get_to(obj._bWarningActive);
  j.at("bErrorActive").get_to(obj._bErrorActive);
}


inline void to_json(nlohmann::ordered_json& j, treatBlockedSectorsAsErrorSectors::Get::Response const& obj)
{
  j = obj._treatBlockedSectorsAsErrorSectors;
}

inline void from_json(const nlohmann::json& j, treatBlockedSectorsAsErrorSectors::Get::Response& obj)
{
  j.get_to(obj._treatBlockedSectorsAsErrorSectors);
}


inline void to_json(nlohmann::ordered_json& j, treatBlockedSectorsAsErrorSectors::Post::Request const& obj)
{
  j = obj._treatBlockedSectorsAsErrorSectors;
}

inline void from_json(const nlohmann::json& j, treatBlockedSectorsAsErrorSectors::Post::Request& obj)
{
  j.get_to(obj._treatBlockedSectorsAsErrorSectors);
}


inline void to_json(nlohmann::ordered_json& j, dataOutputMode::Get::Response const& obj)
{
  j = obj._dataOutputMode;
}

inline void from_json(const nlohmann::json& j, dataOutputMode::Get::Response& obj)
{
  j.get_to(obj._dataOutputMode);
}


inline void to_json(nlohmann::ordered_json& j, dataOutputMode::Post::Request const& obj)
{
  j = obj._dataOutputMode;
}

inline void from_json(const nlohmann::json& j, dataOutputMode::Post::Request& obj)
{
  j.get_to(obj._dataOutputMode);
}


inline void to_json(nlohmann::ordered_json& j, LFPintervalFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiReductionFactor", obj._uiReductionFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPintervalFilter::Get::Response& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiReductionFactor").get_to(obj._uiReductionFactor);
}


inline void to_json(nlohmann::ordered_json& j, LFPintervalFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"bEnable", obj._bEnable},
      {"uiReductionFactor", obj._uiReductionFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, LFPintervalFilter::Post::Request& obj)
{
  j.at("bEnable").get_to(obj._bEnable);
  j.at("uiReductionFactor").get_to(obj._uiReductionFactor);
}


inline void to_json(nlohmann::ordered_json& j, horizontalAngleRangeFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"thetaStart", obj._thetaStart.value()},
      {"thetaStop", obj._thetaStop.value()},
      {"thetaIndexIncrement", obj._thetaIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, horizontalAngleRangeFilter::Get::Response& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("thetaStart").get_to(obj._thetaStart);
  j.at("thetaStop").get_to(obj._thetaStop);
  j.at("thetaIndexIncrement").get_to(obj._thetaIndexIncrement);
}


inline void to_json(nlohmann::ordered_json& j, horizontalAngleRangeFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"thetaStart", obj._thetaStart.value()},
      {"thetaStop", obj._thetaStop.value()},
      {"thetaIndexIncrement", obj._thetaIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, horizontalAngleRangeFilter::Post::Request& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("thetaStart").get_to(obj._thetaStart);
  j.at("thetaStop").get_to(obj._thetaStop);
  j.at("thetaIndexIncrement").get_to(obj._thetaIndexIncrement);
}


inline void to_json(nlohmann::ordered_json& j, verticalAngleRangeFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"outerRoiStartAngle", obj._outerRoiStartAngle.value()},
      {"outerRoiStopAngle", obj._outerRoiStopAngle.value()},
      {"innerRoiStartAngle", obj._innerRoiStartAngle.value()},
      {"innerRoiStopAngle", obj._innerRoiStopAngle.value()},
      {"outerRoiIndexIncrement", obj._outerRoiIndexIncrement.value()},
      {"innerRoiIndexIncrement", obj._innerRoiIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, verticalAngleRangeFilter::Get::Response& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("outerRoiStartAngle").get_to(obj._outerRoiStartAngle);
  j.at("outerRoiStopAngle").get_to(obj._outerRoiStopAngle);
  j.at("innerRoiStartAngle").get_to(obj._innerRoiStartAngle);
  j.at("innerRoiStopAngle").get_to(obj._innerRoiStopAngle);
  j.at("outerRoiIndexIncrement").get_to(obj._outerRoiIndexIncrement);
  j.at("innerRoiIndexIncrement").get_to(obj._innerRoiIndexIncrement);
}


inline void to_json(nlohmann::ordered_json& j, verticalAngleRangeFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"outerRoiStartAngle", obj._outerRoiStartAngle.value()},
      {"outerRoiStopAngle", obj._outerRoiStopAngle.value()},
      {"innerRoiStartAngle", obj._innerRoiStartAngle.value()},
      {"innerRoiStopAngle", obj._innerRoiStopAngle.value()},
      {"outerRoiIndexIncrement", obj._outerRoiIndexIncrement.value()},
      {"innerRoiIndexIncrement", obj._innerRoiIndexIncrement.value()},
  };
}

inline void from_json(const nlohmann::json& j, verticalAngleRangeFilter::Post::Request& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("outerRoiStartAngle").get_to(obj._outerRoiStartAngle);
  j.at("outerRoiStopAngle").get_to(obj._outerRoiStopAngle);
  j.at("innerRoiStartAngle").get_to(obj._innerRoiStartAngle);
  j.at("innerRoiStopAngle").get_to(obj._innerRoiStopAngle);
  j.at("outerRoiIndexIncrement").get_to(obj._outerRoiIndexIncrement);
  j.at("innerRoiIndexIncrement").get_to(obj._innerRoiIndexIncrement);
}


inline void to_json(nlohmann::ordered_json& j, compactSerializationContent::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"serializeRssis", obj._serializeRssis},
      {"serializeProperties", obj._serializeProperties},
  };
}

inline void from_json(const nlohmann::json& j, compactSerializationContent::Get::Response& obj)
{
  j.at("serializeRssis").get_to(obj._serializeRssis);
  j.at("serializeProperties").get_to(obj._serializeProperties);
}


inline void to_json(nlohmann::ordered_json& j, compactSerializationContent::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"serializeRssis", obj._serializeRssis},
      {"serializeProperties", obj._serializeProperties},
  };
}

inline void from_json(const nlohmann::json& j, compactSerializationContent::Post::Request& obj)
{
  j.at("serializeRssis").get_to(obj._serializeRssis);
  j.at("serializeProperties").get_to(obj._serializeProperties);
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


inline void to_json(nlohmann::ordered_json& j, SensorPosition::Post::Request const& obj)
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

inline void from_json(const nlohmann::json& j, SensorPosition::Post::Request& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
  j.at("z").get_to(obj._z);
  j.at("yaw").get_to(obj._yaw);
  j.at("pitch").get_to(obj._pitch);
  j.at("roll").get_to(obj._roll);
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


inline void to_json(nlohmann::ordered_json& j, rosEndianness::Get::Response const& obj)
{
  j = obj._rosEndianness;
}

inline void from_json(const nlohmann::json& j, rosEndianness::Get::Response& obj)
{
  j.get_to(obj._rosEndianness);
}


inline void to_json(nlohmann::ordered_json& j, rosEndianness::Post::Request const& obj)
{
  j = obj._rosEndianness;
}

inline void from_json(const nlohmann::json& j, rosEndianness::Post::Request& obj)
{
  j.get_to(obj._rosEndianness);
}


inline void to_json(nlohmann::ordered_json& j, rosPointCloud2Content::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"includeRssi", obj._includeRssi},
      {"includeProperties", obj._includeProperties},
      {"includeTimeOffset", obj._includeTimeOffset},
      {"includeRing", obj._includeRing},
  };
}

inline void from_json(const nlohmann::json& j, rosPointCloud2Content::Get::Response& obj)
{
  j.at("includeRssi").get_to(obj._includeRssi);
  j.at("includeProperties").get_to(obj._includeProperties);
  j.at("includeTimeOffset").get_to(obj._includeTimeOffset);
  j.at("includeRing").get_to(obj._includeRing);
}


inline void to_json(nlohmann::ordered_json& j, rosPointCloud2Content::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"includeRssi", obj._includeRssi},
      {"includeProperties", obj._includeProperties},
      {"includeTimeOffset", obj._includeTimeOffset},
      {"includeRing", obj._includeRing},
  };
}

inline void from_json(const nlohmann::json& j, rosPointCloud2Content::Post::Request& obj)
{
  j.at("includeRssi").get_to(obj._includeRssi);
  j.at("includeProperties").get_to(obj._includeProperties);
  j.at("includeTimeOffset").get_to(obj._includeTimeOffset);
  j.at("includeRing").get_to(obj._includeRing);
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


inline void to_json(nlohmann::ordered_json& j, DistMeasState::Get::Response::DistMeasState const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
  };
}

inline void from_json(const nlohmann::json& j, DistMeasState::Get::Response::DistMeasState& obj)
{
  j.at("State").get_to(obj._State);
}

inline void to_json(nlohmann::ordered_json& j, DistMeasState::Get::Response const& obj)
{
  j = obj._DistMeasState;
}

inline void from_json(const nlohmann::json& j, DistMeasState::Get::Response& obj)
{
  j.get_to(obj._DistMeasState);
}


inline void to_json(nlohmann::ordered_json& j, InertialMeasurementUnit::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"Acceleration", obj._Acceleration},
      {"AngularVelocity", obj._AngularVelocity},
      {"Orientation", obj._Orientation},
      {"TimeStamp", obj._TimeStamp},
  };
}

inline void from_json(const nlohmann::json& j, InertialMeasurementUnit::Get::Response& obj)
{
  j.at("Acceleration").get_to(obj._Acceleration);
  j.at("AngularVelocity").get_to(obj._AngularVelocity);
  j.at("Orientation").get_to(obj._Orientation);
  j.at("TimeStamp").get_to(obj._TimeStamp);
}


inline void to_json(nlohmann::ordered_json& j, InertialMeasurementUnit::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Acceleration", obj._Acceleration},
      {"AngularVelocity", obj._AngularVelocity},
      {"Orientation", obj._Orientation},
      {"TimeStamp", obj._TimeStamp},
  };
}

inline void from_json(const nlohmann::json& j, InertialMeasurementUnit::Post::Request& obj)
{
  j.at("Acceleration").get_to(obj._Acceleration);
  j.at("AngularVelocity").get_to(obj._AngularVelocity);
  j.at("Orientation").get_to(obj._Orientation);
  j.at("TimeStamp").get_to(obj._TimeStamp);
}


inline void to_json(nlohmann::ordered_json& j, SourceList::Get::Response::SourceListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Id", obj._Id},
      {"Label", obj._Label},
      {"State", obj._State},
      {"DefaultState", obj._DefaultState},
  };
}

inline void from_json(const nlohmann::json& j, SourceList::Get::Response::SourceListItem& obj)
{
  j.at("Id").get_to(obj._Id);
  j.at("Label").get_to(obj._Label);
  j.at("State").get_to(obj._State);
  j.at("DefaultState").get_to(obj._DefaultState);
}

inline void to_json(nlohmann::ordered_json& j, SourceList::Get::Response const& obj)
{
  j = obj._SourceList;
}

inline void from_json(const nlohmann::json& j, SourceList::Get::Response& obj)
{
  j.get_to(obj._SourceList);
}


inline void to_json(nlohmann::ordered_json& j, PortToPinMapping::Get::Response const& obj)
{
  j = obj._PortToPinMapping;
}

inline void from_json(const nlohmann::json& j, PortToPinMapping::Get::Response& obj)
{
  j.get_to(obj._PortToPinMapping);
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


inline void to_json(nlohmann::ordered_json& j, OutputCommandState::Get::Response const& obj)
{
  j = obj._OutputCommandState;
}

inline void from_json(const nlohmann::json& j, OutputCommandState::Get::Response& obj)
{
  j.get_to(obj._OutputCommandState);
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


inline void to_json(nlohmann::ordered_json& j, setLedOverride::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
  };
}

inline void from_json(const nlohmann::json& j, setLedOverride::Post::Request& obj)
{
  j.at("enable").get_to(obj._enable);
}


inline void to_json(nlohmann::ordered_json& j, EvaluationList::Get::Response const& obj)
{
  j = obj._EvaluationList;
}

inline void from_json(const nlohmann::json& j, EvaluationList::Get::Response& obj)
{
  j.get_to(obj._EvaluationList);
}


inline void to_json(nlohmann::ordered_json& j, EvaluationList::Post::Request const& obj)
{
  j = obj._EvaluationList;
}

inline void from_json(const nlohmann::json& j, EvaluationList::Post::Request& obj)
{
  j.get_to(obj._EvaluationList);
}


inline void to_json(nlohmann::ordered_json& j, Eval001::Get::Response::Eval001::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Get::Response::Eval001::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Get::Response::Eval001::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Get::Response::Eval001::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Get::Response::Eval001::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Get::Response::Eval001::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Get::Response::Eval001::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Get::Response::Eval001::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Get::Response::Eval001 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Get::Response::Eval001& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Get::Response const& obj)
{
  j = obj._Eval001;
}

inline void from_json(const nlohmann::json& j, Eval001::Get::Response& obj)
{
  j.get_to(obj._Eval001);
}


inline void to_json(nlohmann::ordered_json& j, Eval001::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval001::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval001::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval002::Get::Response::Eval002::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Get::Response::Eval002::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Get::Response::Eval002::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Get::Response::Eval002::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Get::Response::Eval002::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Get::Response::Eval002::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Get::Response::Eval002::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Get::Response::Eval002::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Get::Response::Eval002 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Get::Response::Eval002& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Get::Response const& obj)
{
  j = obj._Eval002;
}

inline void from_json(const nlohmann::json& j, Eval002::Get::Response& obj)
{
  j.get_to(obj._Eval002);
}


inline void to_json(nlohmann::ordered_json& j, Eval002::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval002::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval002::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval003::Get::Response::Eval003::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Get::Response::Eval003::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Get::Response::Eval003::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Get::Response::Eval003::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Get::Response::Eval003::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Get::Response::Eval003::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Get::Response::Eval003::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Get::Response::Eval003::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Get::Response::Eval003 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Get::Response::Eval003& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Get::Response const& obj)
{
  j = obj._Eval003;
}

inline void from_json(const nlohmann::json& j, Eval003::Get::Response& obj)
{
  j.get_to(obj._Eval003);
}


inline void to_json(nlohmann::ordered_json& j, Eval003::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval003::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval003::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval004::Get::Response::Eval004::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Get::Response::Eval004::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Get::Response::Eval004::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Get::Response::Eval004::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Get::Response::Eval004::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Get::Response::Eval004::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Get::Response::Eval004::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Get::Response::Eval004::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Get::Response::Eval004 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Get::Response::Eval004& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Get::Response const& obj)
{
  j = obj._Eval004;
}

inline void from_json(const nlohmann::json& j, Eval004::Get::Response& obj)
{
  j.get_to(obj._Eval004);
}


inline void to_json(nlohmann::ordered_json& j, Eval004::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval004::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval004::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval005::Get::Response::Eval005::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Get::Response::Eval005::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Get::Response::Eval005::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Get::Response::Eval005::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Get::Response::Eval005::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Get::Response::Eval005::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Get::Response::Eval005::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Get::Response::Eval005::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Get::Response::Eval005 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Get::Response::Eval005& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Get::Response const& obj)
{
  j = obj._Eval005;
}

inline void from_json(const nlohmann::json& j, Eval005::Get::Response& obj)
{
  j.get_to(obj._Eval005);
}


inline void to_json(nlohmann::ordered_json& j, Eval005::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval005::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval005::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval006::Get::Response::Eval006::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Get::Response::Eval006::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Get::Response::Eval006::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Get::Response::Eval006::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Get::Response::Eval006::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Get::Response::Eval006::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Get::Response::Eval006::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Get::Response::Eval006::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Get::Response::Eval006 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Get::Response::Eval006& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Get::Response const& obj)
{
  j = obj._Eval006;
}

inline void from_json(const nlohmann::json& j, Eval006::Get::Response& obj)
{
  j.get_to(obj._Eval006);
}


inline void to_json(nlohmann::ordered_json& j, Eval006::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval006::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval006::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval007::Get::Response::Eval007::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Get::Response::Eval007::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Get::Response::Eval007::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Get::Response::Eval007::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Get::Response::Eval007::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Get::Response::Eval007::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Get::Response::Eval007::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Get::Response::Eval007::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Get::Response::Eval007 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Get::Response::Eval007& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Get::Response const& obj)
{
  j = obj._Eval007;
}

inline void from_json(const nlohmann::json& j, Eval007::Get::Response& obj)
{
  j.get_to(obj._Eval007);
}


inline void to_json(nlohmann::ordered_json& j, Eval007::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval007::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval007::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval008::Get::Response::Eval008::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Get::Response::Eval008::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Get::Response::Eval008::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Get::Response::Eval008::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Get::Response::Eval008::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Get::Response::Eval008::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Get::Response::Eval008::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Get::Response::Eval008::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Get::Response::Eval008 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Get::Response::Eval008& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Get::Response const& obj)
{
  j = obj._Eval008;
}

inline void from_json(const nlohmann::json& j, Eval008::Get::Response& obj)
{
  j.get_to(obj._Eval008);
}


inline void to_json(nlohmann::ordered_json& j, Eval008::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval008::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval008::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval009::Get::Response::Eval009::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Get::Response::Eval009::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Get::Response::Eval009::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Get::Response::Eval009::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Get::Response::Eval009::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Get::Response::Eval009::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Get::Response::Eval009::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Get::Response::Eval009::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Get::Response::Eval009 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Get::Response::Eval009& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Get::Response const& obj)
{
  j = obj._Eval009;
}

inline void from_json(const nlohmann::json& j, Eval009::Get::Response& obj)
{
  j.get_to(obj._Eval009);
}


inline void to_json(nlohmann::ordered_json& j, Eval009::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval009::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval009::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval010::Get::Response::Eval010::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Get::Response::Eval010::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Get::Response::Eval010::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Get::Response::Eval010::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Get::Response::Eval010::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Get::Response::Eval010::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Get::Response::Eval010::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Get::Response::Eval010::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Get::Response::Eval010 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Get::Response::Eval010& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Get::Response const& obj)
{
  j = obj._Eval010;
}

inline void from_json(const nlohmann::json& j, Eval010::Get::Response& obj)
{
  j.get_to(obj._Eval010);
}


inline void to_json(nlohmann::ordered_json& j, Eval010::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval010::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval010::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval011::Get::Response::Eval011::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Get::Response::Eval011::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Get::Response::Eval011::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Get::Response::Eval011::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Get::Response::Eval011::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Get::Response::Eval011::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Get::Response::Eval011::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Get::Response::Eval011::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Get::Response::Eval011 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Get::Response::Eval011& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Get::Response const& obj)
{
  j = obj._Eval011;
}

inline void from_json(const nlohmann::json& j, Eval011::Get::Response& obj)
{
  j.get_to(obj._Eval011);
}


inline void to_json(nlohmann::ordered_json& j, Eval011::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval011::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval011::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval012::Get::Response::Eval012::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Get::Response::Eval012::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Get::Response::Eval012::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Get::Response::Eval012::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Get::Response::Eval012::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Get::Response::Eval012::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Get::Response::Eval012::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Get::Response::Eval012::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Get::Response::Eval012 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Get::Response::Eval012& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Get::Response const& obj)
{
  j = obj._Eval012;
}

inline void from_json(const nlohmann::json& j, Eval012::Get::Response& obj)
{
  j.get_to(obj._Eval012);
}


inline void to_json(nlohmann::ordered_json& j, Eval012::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval012::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval012::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval013::Get::Response::Eval013::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Get::Response::Eval013::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Get::Response::Eval013::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Get::Response::Eval013::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Get::Response::Eval013::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Get::Response::Eval013::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Get::Response::Eval013::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Get::Response::Eval013::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Get::Response::Eval013 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Get::Response::Eval013& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Get::Response const& obj)
{
  j = obj._Eval013;
}

inline void from_json(const nlohmann::json& j, Eval013::Get::Response& obj)
{
  j.get_to(obj._Eval013);
}


inline void to_json(nlohmann::ordered_json& j, Eval013::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval013::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval013::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval014::Get::Response::Eval014::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Get::Response::Eval014::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Get::Response::Eval014::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Get::Response::Eval014::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Get::Response::Eval014::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Get::Response::Eval014::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Get::Response::Eval014::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Get::Response::Eval014::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Get::Response::Eval014 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Get::Response::Eval014& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Get::Response const& obj)
{
  j = obj._Eval014;
}

inline void from_json(const nlohmann::json& j, Eval014::Get::Response& obj)
{
  j.get_to(obj._Eval014);
}


inline void to_json(nlohmann::ordered_json& j, Eval014::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval014::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval014::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval015::Get::Response::Eval015::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Get::Response::Eval015::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Get::Response::Eval015::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Get::Response::Eval015::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Get::Response::Eval015::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Get::Response::Eval015::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Get::Response::Eval015::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Get::Response::Eval015::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Get::Response::Eval015 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Get::Response::Eval015& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Get::Response const& obj)
{
  j = obj._Eval015;
}

inline void from_json(const nlohmann::json& j, Eval015::Get::Response& obj)
{
  j.get_to(obj._Eval015);
}


inline void to_json(nlohmann::ordered_json& j, Eval015::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval015::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval015::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval016::Get::Response::Eval016::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Get::Response::Eval016::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Get::Response::Eval016::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Get::Response::Eval016::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Get::Response::Eval016::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Get::Response::Eval016::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Get::Response::Eval016::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Get::Response::Eval016::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Get::Response::Eval016 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Get::Response::Eval016& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Get::Response const& obj)
{
  j = obj._Eval016;
}

inline void from_json(const nlohmann::json& j, Eval016::Get::Response& obj)
{
  j.get_to(obj._Eval016);
}


inline void to_json(nlohmann::ordered_json& j, Eval016::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval016::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval016::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval017::Get::Response::Eval017::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Get::Response::Eval017::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Get::Response::Eval017::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Get::Response::Eval017::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Get::Response::Eval017::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Get::Response::Eval017::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Get::Response::Eval017::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Get::Response::Eval017::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Get::Response::Eval017 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Get::Response::Eval017& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Get::Response const& obj)
{
  j = obj._Eval017;
}

inline void from_json(const nlohmann::json& j, Eval017::Get::Response& obj)
{
  j.get_to(obj._Eval017);
}


inline void to_json(nlohmann::ordered_json& j, Eval017::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval017::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval017::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval018::Get::Response::Eval018::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Get::Response::Eval018::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Get::Response::Eval018::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Get::Response::Eval018::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Get::Response::Eval018::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Get::Response::Eval018::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Get::Response::Eval018::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Get::Response::Eval018::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Get::Response::Eval018 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Get::Response::Eval018& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Get::Response const& obj)
{
  j = obj._Eval018;
}

inline void from_json(const nlohmann::json& j, Eval018::Get::Response& obj)
{
  j.get_to(obj._Eval018);
}


inline void to_json(nlohmann::ordered_json& j, Eval018::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval018::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval018::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval019::Get::Response::Eval019::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Get::Response::Eval019::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Get::Response::Eval019::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Get::Response::Eval019::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Get::Response::Eval019::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Get::Response::Eval019::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Get::Response::Eval019::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Get::Response::Eval019::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Get::Response::Eval019 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Get::Response::Eval019& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Get::Response const& obj)
{
  j = obj._Eval019;
}

inline void from_json(const nlohmann::json& j, Eval019::Get::Response& obj)
{
  j.get_to(obj._Eval019);
}


inline void to_json(nlohmann::ordered_json& j, Eval019::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval019::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval019::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval020::Get::Response::Eval020::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Get::Response::Eval020::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Get::Response::Eval020::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Get::Response::Eval020::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Get::Response::Eval020::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Get::Response::Eval020::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Get::Response::Eval020::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Get::Response::Eval020::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Get::Response::Eval020 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Get::Response::Eval020& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Get::Response const& obj)
{
  j = obj._Eval020;
}

inline void from_json(const nlohmann::json& j, Eval020::Get::Response& obj)
{
  j.get_to(obj._Eval020);
}


inline void to_json(nlohmann::ordered_json& j, Eval020::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval020::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval020::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval021::Get::Response::Eval021::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Get::Response::Eval021::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Get::Response::Eval021::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Get::Response::Eval021::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Get::Response::Eval021::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Get::Response::Eval021::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Get::Response::Eval021::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Get::Response::Eval021::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Get::Response::Eval021 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Get::Response::Eval021& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Get::Response const& obj)
{
  j = obj._Eval021;
}

inline void from_json(const nlohmann::json& j, Eval021::Get::Response& obj)
{
  j.get_to(obj._Eval021);
}


inline void to_json(nlohmann::ordered_json& j, Eval021::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval021::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval021::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval022::Get::Response::Eval022::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Get::Response::Eval022::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Get::Response::Eval022::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Get::Response::Eval022::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Get::Response::Eval022::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Get::Response::Eval022::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Get::Response::Eval022::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Get::Response::Eval022::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Get::Response::Eval022 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Get::Response::Eval022& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Get::Response const& obj)
{
  j = obj._Eval022;
}

inline void from_json(const nlohmann::json& j, Eval022::Get::Response& obj)
{
  j.get_to(obj._Eval022);
}


inline void to_json(nlohmann::ordered_json& j, Eval022::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval022::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval022::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval023::Get::Response::Eval023::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Get::Response::Eval023::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Get::Response::Eval023::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Get::Response::Eval023::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Get::Response::Eval023::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Get::Response::Eval023::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Get::Response::Eval023::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Get::Response::Eval023::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Get::Response::Eval023 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Get::Response::Eval023& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Get::Response const& obj)
{
  j = obj._Eval023;
}

inline void from_json(const nlohmann::json& j, Eval023::Get::Response& obj)
{
  j.get_to(obj._Eval023);
}


inline void to_json(nlohmann::ordered_json& j, Eval023::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval023::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval023::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval024::Get::Response::Eval024::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Get::Response::Eval024::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Get::Response::Eval024::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Get::Response::Eval024::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Get::Response::Eval024::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Get::Response::Eval024::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Get::Response::Eval024::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Get::Response::Eval024::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Get::Response::Eval024 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Get::Response::Eval024& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Get::Response const& obj)
{
  j = obj._Eval024;
}

inline void from_json(const nlohmann::json& j, Eval024::Get::Response& obj)
{
  j.get_to(obj._Eval024);
}


inline void to_json(nlohmann::ordered_json& j, Eval024::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval024::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval024::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval025::Get::Response::Eval025::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Get::Response::Eval025::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Get::Response::Eval025::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Get::Response::Eval025::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Get::Response::Eval025::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Get::Response::Eval025::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Get::Response::Eval025::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Get::Response::Eval025::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Get::Response::Eval025 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Get::Response::Eval025& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Get::Response const& obj)
{
  j = obj._Eval025;
}

inline void from_json(const nlohmann::json& j, Eval025::Get::Response& obj)
{
  j.get_to(obj._Eval025);
}


inline void to_json(nlohmann::ordered_json& j, Eval025::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval025::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval025::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval026::Get::Response::Eval026::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Get::Response::Eval026::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Get::Response::Eval026::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Get::Response::Eval026::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Get::Response::Eval026::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Get::Response::Eval026::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Get::Response::Eval026::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Get::Response::Eval026::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Get::Response::Eval026 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Get::Response::Eval026& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Get::Response const& obj)
{
  j = obj._Eval026;
}

inline void from_json(const nlohmann::json& j, Eval026::Get::Response& obj)
{
  j.get_to(obj._Eval026);
}


inline void to_json(nlohmann::ordered_json& j, Eval026::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval026::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval026::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval027::Get::Response::Eval027::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Get::Response::Eval027::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Get::Response::Eval027::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Get::Response::Eval027::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Get::Response::Eval027::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Get::Response::Eval027::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Get::Response::Eval027::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Get::Response::Eval027::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Get::Response::Eval027 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Get::Response::Eval027& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Get::Response const& obj)
{
  j = obj._Eval027;
}

inline void from_json(const nlohmann::json& j, Eval027::Get::Response& obj)
{
  j.get_to(obj._Eval027);
}


inline void to_json(nlohmann::ordered_json& j, Eval027::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval027::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval027::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval028::Get::Response::Eval028::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Get::Response::Eval028::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Get::Response::Eval028::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Get::Response::Eval028::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Get::Response::Eval028::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Get::Response::Eval028::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Get::Response::Eval028::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Get::Response::Eval028::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Get::Response::Eval028 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Get::Response::Eval028& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Get::Response const& obj)
{
  j = obj._Eval028;
}

inline void from_json(const nlohmann::json& j, Eval028::Get::Response& obj)
{
  j.get_to(obj._Eval028);
}


inline void to_json(nlohmann::ordered_json& j, Eval028::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval028::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval028::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval029::Get::Response::Eval029::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Get::Response::Eval029::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Get::Response::Eval029::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Get::Response::Eval029::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Get::Response::Eval029::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Get::Response::Eval029::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Get::Response::Eval029::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Get::Response::Eval029::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Get::Response::Eval029 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Get::Response::Eval029& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Get::Response const& obj)
{
  j = obj._Eval029;
}

inline void from_json(const nlohmann::json& j, Eval029::Get::Response& obj)
{
  j.get_to(obj._Eval029);
}


inline void to_json(nlohmann::ordered_json& j, Eval029::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval029::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval029::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval030::Get::Response::Eval030::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Get::Response::Eval030::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Get::Response::Eval030::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Get::Response::Eval030::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Get::Response::Eval030::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Get::Response::Eval030::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Get::Response::Eval030::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Get::Response::Eval030::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Get::Response::Eval030 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Get::Response::Eval030& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Get::Response const& obj)
{
  j = obj._Eval030;
}

inline void from_json(const nlohmann::json& j, Eval030::Get::Response& obj)
{
  j.get_to(obj._Eval030);
}


inline void to_json(nlohmann::ordered_json& j, Eval030::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval030::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval030::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval031::Get::Response::Eval031::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Get::Response::Eval031::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Get::Response::Eval031::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Get::Response::Eval031::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Get::Response::Eval031::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Get::Response::Eval031::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Get::Response::Eval031::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Get::Response::Eval031::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Get::Response::Eval031 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Get::Response::Eval031& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Get::Response const& obj)
{
  j = obj._Eval031;
}

inline void from_json(const nlohmann::json& j, Eval031::Get::Response& obj)
{
  j.get_to(obj._Eval031);
}


inline void to_json(nlohmann::ordered_json& j, Eval031::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval031::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval031::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval032::Get::Response::Eval032::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Get::Response::Eval032::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Get::Response::Eval032::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Get::Response::Eval032::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Get::Response::Eval032::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Get::Response::Eval032::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Get::Response::Eval032::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Get::Response::Eval032::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Get::Response::Eval032 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Get::Response::Eval032& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Get::Response const& obj)
{
  j = obj._Eval032;
}

inline void from_json(const nlohmann::json& j, Eval032::Get::Response& obj)
{
  j.get_to(obj._Eval032);
}


inline void to_json(nlohmann::ordered_json& j, Eval032::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval032::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval032::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval033::Get::Response::Eval033::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Get::Response::Eval033::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Get::Response::Eval033::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Get::Response::Eval033::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Get::Response::Eval033::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Get::Response::Eval033::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Get::Response::Eval033::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Get::Response::Eval033::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Get::Response::Eval033 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Get::Response::Eval033& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Get::Response const& obj)
{
  j = obj._Eval033;
}

inline void from_json(const nlohmann::json& j, Eval033::Get::Response& obj)
{
  j.get_to(obj._Eval033);
}


inline void to_json(nlohmann::ordered_json& j, Eval033::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval033::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval033::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval034::Get::Response::Eval034::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Get::Response::Eval034::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Get::Response::Eval034::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Get::Response::Eval034::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Get::Response::Eval034::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Get::Response::Eval034::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Get::Response::Eval034::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Get::Response::Eval034::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Get::Response::Eval034 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Get::Response::Eval034& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Get::Response const& obj)
{
  j = obj._Eval034;
}

inline void from_json(const nlohmann::json& j, Eval034::Get::Response& obj)
{
  j.get_to(obj._Eval034);
}


inline void to_json(nlohmann::ordered_json& j, Eval034::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval034::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval034::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval035::Get::Response::Eval035::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Get::Response::Eval035::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Get::Response::Eval035::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Get::Response::Eval035::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Get::Response::Eval035::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Get::Response::Eval035::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Get::Response::Eval035::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Get::Response::Eval035::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Get::Response::Eval035 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Get::Response::Eval035& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Get::Response const& obj)
{
  j = obj._Eval035;
}

inline void from_json(const nlohmann::json& j, Eval035::Get::Response& obj)
{
  j.get_to(obj._Eval035);
}


inline void to_json(nlohmann::ordered_json& j, Eval035::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval035::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval035::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval036::Get::Response::Eval036::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Get::Response::Eval036::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Get::Response::Eval036::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Get::Response::Eval036::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Get::Response::Eval036::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Get::Response::Eval036::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Get::Response::Eval036::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Get::Response::Eval036::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Get::Response::Eval036 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Get::Response::Eval036& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Get::Response const& obj)
{
  j = obj._Eval036;
}

inline void from_json(const nlohmann::json& j, Eval036::Get::Response& obj)
{
  j.get_to(obj._Eval036);
}


inline void to_json(nlohmann::ordered_json& j, Eval036::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval036::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval036::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval037::Get::Response::Eval037::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Get::Response::Eval037::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Get::Response::Eval037::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Get::Response::Eval037::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Get::Response::Eval037::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Get::Response::Eval037::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Get::Response::Eval037::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Get::Response::Eval037::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Get::Response::Eval037 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Get::Response::Eval037& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Get::Response const& obj)
{
  j = obj._Eval037;
}

inline void from_json(const nlohmann::json& j, Eval037::Get::Response& obj)
{
  j.get_to(obj._Eval037);
}


inline void to_json(nlohmann::ordered_json& j, Eval037::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval037::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval037::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval038::Get::Response::Eval038::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Get::Response::Eval038::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Get::Response::Eval038::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Get::Response::Eval038::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Get::Response::Eval038::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Get::Response::Eval038::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Get::Response::Eval038::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Get::Response::Eval038::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Get::Response::Eval038 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Get::Response::Eval038& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Get::Response const& obj)
{
  j = obj._Eval038;
}

inline void from_json(const nlohmann::json& j, Eval038::Get::Response& obj)
{
  j.get_to(obj._Eval038);
}


inline void to_json(nlohmann::ordered_json& j, Eval038::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval038::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval038::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval039::Get::Response::Eval039::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Get::Response::Eval039::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Get::Response::Eval039::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Get::Response::Eval039::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Get::Response::Eval039::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Get::Response::Eval039::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Get::Response::Eval039::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Get::Response::Eval039::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Get::Response::Eval039 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Get::Response::Eval039& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Get::Response const& obj)
{
  j = obj._Eval039;
}

inline void from_json(const nlohmann::json& j, Eval039::Get::Response& obj)
{
  j.get_to(obj._Eval039);
}


inline void to_json(nlohmann::ordered_json& j, Eval039::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval039::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval039::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval040::Get::Response::Eval040::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Get::Response::Eval040::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Get::Response::Eval040::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Get::Response::Eval040::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Get::Response::Eval040::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Get::Response::Eval040::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Get::Response::Eval040::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Get::Response::Eval040::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Get::Response::Eval040 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Get::Response::Eval040& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Get::Response const& obj)
{
  j = obj._Eval040;
}

inline void from_json(const nlohmann::json& j, Eval040::Get::Response& obj)
{
  j.get_to(obj._Eval040);
}


inline void to_json(nlohmann::ordered_json& j, Eval040::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval040::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval040::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval041::Get::Response::Eval041::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Get::Response::Eval041::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Get::Response::Eval041::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Get::Response::Eval041::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Get::Response::Eval041::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Get::Response::Eval041::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Get::Response::Eval041::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Get::Response::Eval041::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Get::Response::Eval041 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Get::Response::Eval041& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Get::Response const& obj)
{
  j = obj._Eval041;
}

inline void from_json(const nlohmann::json& j, Eval041::Get::Response& obj)
{
  j.get_to(obj._Eval041);
}


inline void to_json(nlohmann::ordered_json& j, Eval041::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval041::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval041::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval042::Get::Response::Eval042::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Get::Response::Eval042::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Get::Response::Eval042::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Get::Response::Eval042::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Get::Response::Eval042::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Get::Response::Eval042::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Get::Response::Eval042::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Get::Response::Eval042::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Get::Response::Eval042 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Get::Response::Eval042& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Get::Response const& obj)
{
  j = obj._Eval042;
}

inline void from_json(const nlohmann::json& j, Eval042::Get::Response& obj)
{
  j.get_to(obj._Eval042);
}


inline void to_json(nlohmann::ordered_json& j, Eval042::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval042::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval042::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval043::Get::Response::Eval043::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Get::Response::Eval043::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Get::Response::Eval043::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Get::Response::Eval043::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Get::Response::Eval043::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Get::Response::Eval043::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Get::Response::Eval043::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Get::Response::Eval043::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Get::Response::Eval043 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Get::Response::Eval043& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Get::Response const& obj)
{
  j = obj._Eval043;
}

inline void from_json(const nlohmann::json& j, Eval043::Get::Response& obj)
{
  j.get_to(obj._Eval043);
}


inline void to_json(nlohmann::ordered_json& j, Eval043::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval043::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval043::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval044::Get::Response::Eval044::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Get::Response::Eval044::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Get::Response::Eval044::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Get::Response::Eval044::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Get::Response::Eval044::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Get::Response::Eval044::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Get::Response::Eval044::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Get::Response::Eval044::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Get::Response::Eval044 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Get::Response::Eval044& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Get::Response const& obj)
{
  j = obj._Eval044;
}

inline void from_json(const nlohmann::json& j, Eval044::Get::Response& obj)
{
  j.get_to(obj._Eval044);
}


inline void to_json(nlohmann::ordered_json& j, Eval044::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval044::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval044::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval045::Get::Response::Eval045::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Get::Response::Eval045::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Get::Response::Eval045::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Get::Response::Eval045::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Get::Response::Eval045::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Get::Response::Eval045::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Get::Response::Eval045::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Get::Response::Eval045::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Get::Response::Eval045 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Get::Response::Eval045& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Get::Response const& obj)
{
  j = obj._Eval045;
}

inline void from_json(const nlohmann::json& j, Eval045::Get::Response& obj)
{
  j.get_to(obj._Eval045);
}


inline void to_json(nlohmann::ordered_json& j, Eval045::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval045::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval045::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval046::Get::Response::Eval046::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Get::Response::Eval046::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Get::Response::Eval046::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Get::Response::Eval046::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Get::Response::Eval046::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Get::Response::Eval046::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Get::Response::Eval046::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Get::Response::Eval046::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Get::Response::Eval046 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Get::Response::Eval046& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Get::Response const& obj)
{
  j = obj._Eval046;
}

inline void from_json(const nlohmann::json& j, Eval046::Get::Response& obj)
{
  j.get_to(obj._Eval046);
}


inline void to_json(nlohmann::ordered_json& j, Eval046::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval046::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval046::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval047::Get::Response::Eval047::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Get::Response::Eval047::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Get::Response::Eval047::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Get::Response::Eval047::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Get::Response::Eval047::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Get::Response::Eval047::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Get::Response::Eval047::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Get::Response::Eval047::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Get::Response::Eval047 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Get::Response::Eval047& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Get::Response const& obj)
{
  j = obj._Eval047;
}

inline void from_json(const nlohmann::json& j, Eval047::Get::Response& obj)
{
  j.get_to(obj._Eval047);
}


inline void to_json(nlohmann::ordered_json& j, Eval047::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval047::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval047::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Eval048::Get::Response::Eval048::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Get::Response::Eval048::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Get::Response::Eval048::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Get::Response::Eval048::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Get::Response::Eval048::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Get::Response::Eval048::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Get::Response::Eval048::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Get::Response::Eval048::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Get::Response::Eval048 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Get::Response::Eval048& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Get::Response const& obj)
{
  j = obj._Eval048;
}

inline void from_json(const nlohmann::json& j, Eval048::Get::Response& obj)
{
  j.get_to(obj._Eval048);
}


inline void to_json(nlohmann::ordered_json& j, Eval048::Post::Request::EvaluationParamsMaskBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"InfringementThresholdFactor", obj._InfringementThresholdFactor.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Post::Request::EvaluationParamsMaskBasedItem& obj)
{
  j.at("InfringementThresholdFactor").get_to(obj._InfringementThresholdFactor);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Post::Request::EvaluationParamsSegmentationBasedItem const& obj)
{
  j = nlohmann::ordered_json{
      {"SampleParam1", obj._SampleParam1},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Post::Request::EvaluationParamsSegmentationBasedItem& obj)
{
  j.at("SampleParam1").get_to(obj._SampleParam1);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Post::Request::EvaluationParamsCommonItem const& obj)
{
  j = nlohmann::ordered_json{
      {"MinimumObjectSizeHorizontal", obj._MinimumObjectSizeHorizontal.value()},
      {"MinimumObjectSizeVertical", obj._MinimumObjectSizeVertical.value()},
      {"OcclusionHandling", obj._OcclusionHandling},
      {"TreatMissingDataAsInfringed", obj._TreatMissingDataAsInfringed},
      {"TimeForInfringedState", obj._TimeForInfringedState.value()},
      {"TimeForFreeState", obj._TimeForFreeState.value()},
      {"Reserved3", obj._Reserved3},
      {"Reserved4", obj._Reserved4},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Post::Request::EvaluationParamsCommonItem& obj)
{
  j.at("MinimumObjectSizeHorizontal").get_to(obj._MinimumObjectSizeHorizontal);
  j.at("MinimumObjectSizeVertical").get_to(obj._MinimumObjectSizeVertical);
  j.at("OcclusionHandling").get_to(obj._OcclusionHandling);
  j.at("TreatMissingDataAsInfringed").get_to(obj._TreatMissingDataAsInfringed);
  j.at("TimeForInfringedState").get_to(obj._TimeForInfringedState);
  j.at("TimeForFreeState").get_to(obj._TimeForFreeState);
  j.at("Reserved3").get_to(obj._Reserved3);
  j.at("Reserved4").get_to(obj._Reserved4);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Post::Request::EvaluationParamsExitSizeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"disableExitSize", obj._disableExitSize},
      {"exitSizeVertical", obj._exitSizeVertical.value()},
      {"exitSizeHorizontal", obj._exitSizeHorizontal.value()},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Post::Request::EvaluationParamsExitSizeItem& obj)
{
  j.at("disableExitSize").get_to(obj._disableExitSize);
  j.at("exitSizeVertical").get_to(obj._exitSizeVertical);
  j.at("exitSizeHorizontal").get_to(obj._exitSizeHorizontal);
}

inline void to_json(nlohmann::ordered_json& j, Eval048::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Source", obj._Source},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"EvaluationParamsMaskBased", obj._EvaluationParamsMaskBased},
      {"EvaluationParamsSegmentationBased", obj._EvaluationParamsSegmentationBased},
      {"EvaluationParamsCommon", obj._EvaluationParamsCommon},
      {"EvaluationParamsExitSize", obj._EvaluationParamsExitSize},
      {"VolumeList", obj._VolumeList},
  };
}

inline void from_json(const nlohmann::json& j, Eval048::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Source").get_to(obj._Source);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("EvaluationParamsMaskBased").get_to(obj._EvaluationParamsMaskBased);
  j.at("EvaluationParamsSegmentationBased").get_to(obj._EvaluationParamsSegmentationBased);
  j.at("EvaluationParamsCommon").get_to(obj._EvaluationParamsCommon);
  j.at("EvaluationParamsExitSize").get_to(obj._EvaluationParamsExitSize);
  j.at("VolumeList").get_to(obj._VolumeList);
}


inline void to_json(nlohmann::ordered_json& j, Volume001::Get::Response::Volume001::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume001::Get::Response::Volume001::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume001::Get::Response::Volume001::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume001::Get::Response::Volume001::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume001::Get::Response::Volume001 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume001::Get::Response::Volume001& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume001::Get::Response const& obj)
{
  j = obj._Volume001;
}

inline void from_json(const nlohmann::json& j, Volume001::Get::Response& obj)
{
  j.get_to(obj._Volume001);
}


inline void to_json(nlohmann::ordered_json& j, Volume001::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume001::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume001::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume001::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume001::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume001::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume002::Get::Response::Volume002::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume002::Get::Response::Volume002::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume002::Get::Response::Volume002::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume002::Get::Response::Volume002::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume002::Get::Response::Volume002 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume002::Get::Response::Volume002& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume002::Get::Response const& obj)
{
  j = obj._Volume002;
}

inline void from_json(const nlohmann::json& j, Volume002::Get::Response& obj)
{
  j.get_to(obj._Volume002);
}


inline void to_json(nlohmann::ordered_json& j, Volume002::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume002::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume002::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume002::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume002::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume002::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume003::Get::Response::Volume003::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume003::Get::Response::Volume003::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume003::Get::Response::Volume003::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume003::Get::Response::Volume003::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume003::Get::Response::Volume003 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume003::Get::Response::Volume003& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume003::Get::Response const& obj)
{
  j = obj._Volume003;
}

inline void from_json(const nlohmann::json& j, Volume003::Get::Response& obj)
{
  j.get_to(obj._Volume003);
}


inline void to_json(nlohmann::ordered_json& j, Volume003::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume003::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume003::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume003::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume003::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume003::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume004::Get::Response::Volume004::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume004::Get::Response::Volume004::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume004::Get::Response::Volume004::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume004::Get::Response::Volume004::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume004::Get::Response::Volume004 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume004::Get::Response::Volume004& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume004::Get::Response const& obj)
{
  j = obj._Volume004;
}

inline void from_json(const nlohmann::json& j, Volume004::Get::Response& obj)
{
  j.get_to(obj._Volume004);
}


inline void to_json(nlohmann::ordered_json& j, Volume004::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume004::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume004::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume004::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume004::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume004::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume005::Get::Response::Volume005::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume005::Get::Response::Volume005::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume005::Get::Response::Volume005::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume005::Get::Response::Volume005::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume005::Get::Response::Volume005 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume005::Get::Response::Volume005& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume005::Get::Response const& obj)
{
  j = obj._Volume005;
}

inline void from_json(const nlohmann::json& j, Volume005::Get::Response& obj)
{
  j.get_to(obj._Volume005);
}


inline void to_json(nlohmann::ordered_json& j, Volume005::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume005::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume005::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume005::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume005::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume005::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume006::Get::Response::Volume006::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume006::Get::Response::Volume006::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume006::Get::Response::Volume006::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume006::Get::Response::Volume006::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume006::Get::Response::Volume006 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume006::Get::Response::Volume006& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume006::Get::Response const& obj)
{
  j = obj._Volume006;
}

inline void from_json(const nlohmann::json& j, Volume006::Get::Response& obj)
{
  j.get_to(obj._Volume006);
}


inline void to_json(nlohmann::ordered_json& j, Volume006::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume006::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume006::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume006::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume006::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume006::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume007::Get::Response::Volume007::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume007::Get::Response::Volume007::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume007::Get::Response::Volume007::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume007::Get::Response::Volume007::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume007::Get::Response::Volume007 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume007::Get::Response::Volume007& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume007::Get::Response const& obj)
{
  j = obj._Volume007;
}

inline void from_json(const nlohmann::json& j, Volume007::Get::Response& obj)
{
  j.get_to(obj._Volume007);
}


inline void to_json(nlohmann::ordered_json& j, Volume007::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume007::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume007::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume007::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume007::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume007::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume008::Get::Response::Volume008::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume008::Get::Response::Volume008::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume008::Get::Response::Volume008::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume008::Get::Response::Volume008::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume008::Get::Response::Volume008 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume008::Get::Response::Volume008& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume008::Get::Response const& obj)
{
  j = obj._Volume008;
}

inline void from_json(const nlohmann::json& j, Volume008::Get::Response& obj)
{
  j.get_to(obj._Volume008);
}


inline void to_json(nlohmann::ordered_json& j, Volume008::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume008::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume008::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume008::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume008::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume008::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume009::Get::Response::Volume009::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume009::Get::Response::Volume009::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume009::Get::Response::Volume009::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume009::Get::Response::Volume009::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume009::Get::Response::Volume009 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume009::Get::Response::Volume009& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume009::Get::Response const& obj)
{
  j = obj._Volume009;
}

inline void from_json(const nlohmann::json& j, Volume009::Get::Response& obj)
{
  j.get_to(obj._Volume009);
}


inline void to_json(nlohmann::ordered_json& j, Volume009::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume009::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume009::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume009::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume009::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume009::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume010::Get::Response::Volume010::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume010::Get::Response::Volume010::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume010::Get::Response::Volume010::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume010::Get::Response::Volume010::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume010::Get::Response::Volume010 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume010::Get::Response::Volume010& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume010::Get::Response const& obj)
{
  j = obj._Volume010;
}

inline void from_json(const nlohmann::json& j, Volume010::Get::Response& obj)
{
  j.get_to(obj._Volume010);
}


inline void to_json(nlohmann::ordered_json& j, Volume010::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume010::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume010::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume010::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume010::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume010::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume011::Get::Response::Volume011::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume011::Get::Response::Volume011::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume011::Get::Response::Volume011::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume011::Get::Response::Volume011::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume011::Get::Response::Volume011 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume011::Get::Response::Volume011& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume011::Get::Response const& obj)
{
  j = obj._Volume011;
}

inline void from_json(const nlohmann::json& j, Volume011::Get::Response& obj)
{
  j.get_to(obj._Volume011);
}


inline void to_json(nlohmann::ordered_json& j, Volume011::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume011::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume011::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume011::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume011::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume011::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume012::Get::Response::Volume012::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume012::Get::Response::Volume012::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume012::Get::Response::Volume012::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume012::Get::Response::Volume012::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume012::Get::Response::Volume012 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume012::Get::Response::Volume012& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume012::Get::Response const& obj)
{
  j = obj._Volume012;
}

inline void from_json(const nlohmann::json& j, Volume012::Get::Response& obj)
{
  j.get_to(obj._Volume012);
}


inline void to_json(nlohmann::ordered_json& j, Volume012::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume012::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume012::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume012::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume012::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume012::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume013::Get::Response::Volume013::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume013::Get::Response::Volume013::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume013::Get::Response::Volume013::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume013::Get::Response::Volume013::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume013::Get::Response::Volume013 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume013::Get::Response::Volume013& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume013::Get::Response const& obj)
{
  j = obj._Volume013;
}

inline void from_json(const nlohmann::json& j, Volume013::Get::Response& obj)
{
  j.get_to(obj._Volume013);
}


inline void to_json(nlohmann::ordered_json& j, Volume013::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume013::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume013::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume013::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume013::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume013::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume014::Get::Response::Volume014::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume014::Get::Response::Volume014::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume014::Get::Response::Volume014::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume014::Get::Response::Volume014::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume014::Get::Response::Volume014 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume014::Get::Response::Volume014& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume014::Get::Response const& obj)
{
  j = obj._Volume014;
}

inline void from_json(const nlohmann::json& j, Volume014::Get::Response& obj)
{
  j.get_to(obj._Volume014);
}


inline void to_json(nlohmann::ordered_json& j, Volume014::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume014::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume014::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume014::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume014::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume014::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume015::Get::Response::Volume015::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume015::Get::Response::Volume015::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume015::Get::Response::Volume015::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume015::Get::Response::Volume015::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume015::Get::Response::Volume015 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume015::Get::Response::Volume015& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume015::Get::Response const& obj)
{
  j = obj._Volume015;
}

inline void from_json(const nlohmann::json& j, Volume015::Get::Response& obj)
{
  j.get_to(obj._Volume015);
}


inline void to_json(nlohmann::ordered_json& j, Volume015::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume015::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume015::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume015::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume015::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume015::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume016::Get::Response::Volume016::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume016::Get::Response::Volume016::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume016::Get::Response::Volume016::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume016::Get::Response::Volume016::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume016::Get::Response::Volume016 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume016::Get::Response::Volume016& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume016::Get::Response const& obj)
{
  j = obj._Volume016;
}

inline void from_json(const nlohmann::json& j, Volume016::Get::Response& obj)
{
  j.get_to(obj._Volume016);
}


inline void to_json(nlohmann::ordered_json& j, Volume016::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume016::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume016::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume016::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume016::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume016::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume017::Get::Response::Volume017::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume017::Get::Response::Volume017::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume017::Get::Response::Volume017::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume017::Get::Response::Volume017::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume017::Get::Response::Volume017 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume017::Get::Response::Volume017& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume017::Get::Response const& obj)
{
  j = obj._Volume017;
}

inline void from_json(const nlohmann::json& j, Volume017::Get::Response& obj)
{
  j.get_to(obj._Volume017);
}


inline void to_json(nlohmann::ordered_json& j, Volume017::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume017::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume017::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume017::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume017::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume017::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume018::Get::Response::Volume018::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume018::Get::Response::Volume018::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume018::Get::Response::Volume018::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume018::Get::Response::Volume018::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume018::Get::Response::Volume018 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume018::Get::Response::Volume018& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume018::Get::Response const& obj)
{
  j = obj._Volume018;
}

inline void from_json(const nlohmann::json& j, Volume018::Get::Response& obj)
{
  j.get_to(obj._Volume018);
}


inline void to_json(nlohmann::ordered_json& j, Volume018::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume018::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume018::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume018::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume018::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume018::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume019::Get::Response::Volume019::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume019::Get::Response::Volume019::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume019::Get::Response::Volume019::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume019::Get::Response::Volume019::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume019::Get::Response::Volume019 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume019::Get::Response::Volume019& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume019::Get::Response const& obj)
{
  j = obj._Volume019;
}

inline void from_json(const nlohmann::json& j, Volume019::Get::Response& obj)
{
  j.get_to(obj._Volume019);
}


inline void to_json(nlohmann::ordered_json& j, Volume019::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume019::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume019::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume019::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume019::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume019::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume020::Get::Response::Volume020::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume020::Get::Response::Volume020::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume020::Get::Response::Volume020::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume020::Get::Response::Volume020::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume020::Get::Response::Volume020 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume020::Get::Response::Volume020& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume020::Get::Response const& obj)
{
  j = obj._Volume020;
}

inline void from_json(const nlohmann::json& j, Volume020::Get::Response& obj)
{
  j.get_to(obj._Volume020);
}


inline void to_json(nlohmann::ordered_json& j, Volume020::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume020::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume020::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume020::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume020::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume020::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume021::Get::Response::Volume021::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume021::Get::Response::Volume021::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume021::Get::Response::Volume021::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume021::Get::Response::Volume021::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume021::Get::Response::Volume021 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume021::Get::Response::Volume021& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume021::Get::Response const& obj)
{
  j = obj._Volume021;
}

inline void from_json(const nlohmann::json& j, Volume021::Get::Response& obj)
{
  j.get_to(obj._Volume021);
}


inline void to_json(nlohmann::ordered_json& j, Volume021::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume021::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume021::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume021::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume021::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume021::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume022::Get::Response::Volume022::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume022::Get::Response::Volume022::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume022::Get::Response::Volume022::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume022::Get::Response::Volume022::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume022::Get::Response::Volume022 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume022::Get::Response::Volume022& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume022::Get::Response const& obj)
{
  j = obj._Volume022;
}

inline void from_json(const nlohmann::json& j, Volume022::Get::Response& obj)
{
  j.get_to(obj._Volume022);
}


inline void to_json(nlohmann::ordered_json& j, Volume022::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume022::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume022::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume022::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume022::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume022::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume023::Get::Response::Volume023::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume023::Get::Response::Volume023::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume023::Get::Response::Volume023::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume023::Get::Response::Volume023::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume023::Get::Response::Volume023 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume023::Get::Response::Volume023& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume023::Get::Response const& obj)
{
  j = obj._Volume023;
}

inline void from_json(const nlohmann::json& j, Volume023::Get::Response& obj)
{
  j.get_to(obj._Volume023);
}


inline void to_json(nlohmann::ordered_json& j, Volume023::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume023::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume023::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume023::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume023::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume023::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume024::Get::Response::Volume024::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume024::Get::Response::Volume024::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume024::Get::Response::Volume024::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume024::Get::Response::Volume024::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume024::Get::Response::Volume024 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume024::Get::Response::Volume024& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume024::Get::Response const& obj)
{
  j = obj._Volume024;
}

inline void from_json(const nlohmann::json& j, Volume024::Get::Response& obj)
{
  j.get_to(obj._Volume024);
}


inline void to_json(nlohmann::ordered_json& j, Volume024::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume024::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume024::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume024::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume024::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume024::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume025::Get::Response::Volume025::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume025::Get::Response::Volume025::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume025::Get::Response::Volume025::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume025::Get::Response::Volume025::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume025::Get::Response::Volume025 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume025::Get::Response::Volume025& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume025::Get::Response const& obj)
{
  j = obj._Volume025;
}

inline void from_json(const nlohmann::json& j, Volume025::Get::Response& obj)
{
  j.get_to(obj._Volume025);
}


inline void to_json(nlohmann::ordered_json& j, Volume025::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume025::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume025::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume025::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume025::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume025::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume026::Get::Response::Volume026::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume026::Get::Response::Volume026::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume026::Get::Response::Volume026::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume026::Get::Response::Volume026::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume026::Get::Response::Volume026 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume026::Get::Response::Volume026& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume026::Get::Response const& obj)
{
  j = obj._Volume026;
}

inline void from_json(const nlohmann::json& j, Volume026::Get::Response& obj)
{
  j.get_to(obj._Volume026);
}


inline void to_json(nlohmann::ordered_json& j, Volume026::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume026::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume026::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume026::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume026::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume026::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume027::Get::Response::Volume027::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume027::Get::Response::Volume027::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume027::Get::Response::Volume027::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume027::Get::Response::Volume027::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume027::Get::Response::Volume027 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume027::Get::Response::Volume027& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume027::Get::Response const& obj)
{
  j = obj._Volume027;
}

inline void from_json(const nlohmann::json& j, Volume027::Get::Response& obj)
{
  j.get_to(obj._Volume027);
}


inline void to_json(nlohmann::ordered_json& j, Volume027::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume027::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume027::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume027::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume027::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume027::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume028::Get::Response::Volume028::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume028::Get::Response::Volume028::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume028::Get::Response::Volume028::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume028::Get::Response::Volume028::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume028::Get::Response::Volume028 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume028::Get::Response::Volume028& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume028::Get::Response const& obj)
{
  j = obj._Volume028;
}

inline void from_json(const nlohmann::json& j, Volume028::Get::Response& obj)
{
  j.get_to(obj._Volume028);
}


inline void to_json(nlohmann::ordered_json& j, Volume028::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume028::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume028::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume028::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume028::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume028::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume029::Get::Response::Volume029::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume029::Get::Response::Volume029::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume029::Get::Response::Volume029::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume029::Get::Response::Volume029::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume029::Get::Response::Volume029 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume029::Get::Response::Volume029& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume029::Get::Response const& obj)
{
  j = obj._Volume029;
}

inline void from_json(const nlohmann::json& j, Volume029::Get::Response& obj)
{
  j.get_to(obj._Volume029);
}


inline void to_json(nlohmann::ordered_json& j, Volume029::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume029::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume029::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume029::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume029::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume029::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume030::Get::Response::Volume030::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume030::Get::Response::Volume030::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume030::Get::Response::Volume030::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume030::Get::Response::Volume030::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume030::Get::Response::Volume030 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume030::Get::Response::Volume030& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume030::Get::Response const& obj)
{
  j = obj._Volume030;
}

inline void from_json(const nlohmann::json& j, Volume030::Get::Response& obj)
{
  j.get_to(obj._Volume030);
}


inline void to_json(nlohmann::ordered_json& j, Volume030::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume030::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume030::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume030::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume030::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume030::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume031::Get::Response::Volume031::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume031::Get::Response::Volume031::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume031::Get::Response::Volume031::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume031::Get::Response::Volume031::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume031::Get::Response::Volume031 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume031::Get::Response::Volume031& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume031::Get::Response const& obj)
{
  j = obj._Volume031;
}

inline void from_json(const nlohmann::json& j, Volume031::Get::Response& obj)
{
  j.get_to(obj._Volume031);
}


inline void to_json(nlohmann::ordered_json& j, Volume031::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume031::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume031::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume031::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume031::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume031::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume032::Get::Response::Volume032::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume032::Get::Response::Volume032::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume032::Get::Response::Volume032::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume032::Get::Response::Volume032::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume032::Get::Response::Volume032 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume032::Get::Response::Volume032& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume032::Get::Response const& obj)
{
  j = obj._Volume032;
}

inline void from_json(const nlohmann::json& j, Volume032::Get::Response& obj)
{
  j.get_to(obj._Volume032);
}


inline void to_json(nlohmann::ordered_json& j, Volume032::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume032::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume032::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume032::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume032::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume032::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume033::Get::Response::Volume033::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume033::Get::Response::Volume033::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume033::Get::Response::Volume033::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume033::Get::Response::Volume033::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume033::Get::Response::Volume033 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume033::Get::Response::Volume033& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume033::Get::Response const& obj)
{
  j = obj._Volume033;
}

inline void from_json(const nlohmann::json& j, Volume033::Get::Response& obj)
{
  j.get_to(obj._Volume033);
}


inline void to_json(nlohmann::ordered_json& j, Volume033::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume033::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume033::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume033::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume033::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume033::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume034::Get::Response::Volume034::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume034::Get::Response::Volume034::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume034::Get::Response::Volume034::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume034::Get::Response::Volume034::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume034::Get::Response::Volume034 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume034::Get::Response::Volume034& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume034::Get::Response const& obj)
{
  j = obj._Volume034;
}

inline void from_json(const nlohmann::json& j, Volume034::Get::Response& obj)
{
  j.get_to(obj._Volume034);
}


inline void to_json(nlohmann::ordered_json& j, Volume034::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume034::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume034::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume034::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume034::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume034::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume035::Get::Response::Volume035::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume035::Get::Response::Volume035::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume035::Get::Response::Volume035::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume035::Get::Response::Volume035::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume035::Get::Response::Volume035 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume035::Get::Response::Volume035& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume035::Get::Response const& obj)
{
  j = obj._Volume035;
}

inline void from_json(const nlohmann::json& j, Volume035::Get::Response& obj)
{
  j.get_to(obj._Volume035);
}


inline void to_json(nlohmann::ordered_json& j, Volume035::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume035::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume035::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume035::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume035::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume035::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume036::Get::Response::Volume036::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume036::Get::Response::Volume036::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume036::Get::Response::Volume036::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume036::Get::Response::Volume036::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume036::Get::Response::Volume036 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume036::Get::Response::Volume036& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume036::Get::Response const& obj)
{
  j = obj._Volume036;
}

inline void from_json(const nlohmann::json& j, Volume036::Get::Response& obj)
{
  j.get_to(obj._Volume036);
}


inline void to_json(nlohmann::ordered_json& j, Volume036::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume036::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume036::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume036::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume036::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume036::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume037::Get::Response::Volume037::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume037::Get::Response::Volume037::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume037::Get::Response::Volume037::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume037::Get::Response::Volume037::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume037::Get::Response::Volume037 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume037::Get::Response::Volume037& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume037::Get::Response const& obj)
{
  j = obj._Volume037;
}

inline void from_json(const nlohmann::json& j, Volume037::Get::Response& obj)
{
  j.get_to(obj._Volume037);
}


inline void to_json(nlohmann::ordered_json& j, Volume037::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume037::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume037::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume037::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume037::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume037::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume038::Get::Response::Volume038::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume038::Get::Response::Volume038::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume038::Get::Response::Volume038::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume038::Get::Response::Volume038::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume038::Get::Response::Volume038 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume038::Get::Response::Volume038& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume038::Get::Response const& obj)
{
  j = obj._Volume038;
}

inline void from_json(const nlohmann::json& j, Volume038::Get::Response& obj)
{
  j.get_to(obj._Volume038);
}


inline void to_json(nlohmann::ordered_json& j, Volume038::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume038::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume038::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume038::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume038::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume038::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume039::Get::Response::Volume039::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume039::Get::Response::Volume039::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume039::Get::Response::Volume039::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume039::Get::Response::Volume039::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume039::Get::Response::Volume039 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume039::Get::Response::Volume039& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume039::Get::Response const& obj)
{
  j = obj._Volume039;
}

inline void from_json(const nlohmann::json& j, Volume039::Get::Response& obj)
{
  j.get_to(obj._Volume039);
}


inline void to_json(nlohmann::ordered_json& j, Volume039::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume039::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume039::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume039::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume039::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume039::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume040::Get::Response::Volume040::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume040::Get::Response::Volume040::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume040::Get::Response::Volume040::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume040::Get::Response::Volume040::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume040::Get::Response::Volume040 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume040::Get::Response::Volume040& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume040::Get::Response const& obj)
{
  j = obj._Volume040;
}

inline void from_json(const nlohmann::json& j, Volume040::Get::Response& obj)
{
  j.get_to(obj._Volume040);
}


inline void to_json(nlohmann::ordered_json& j, Volume040::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume040::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume040::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume040::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume040::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume040::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume041::Get::Response::Volume041::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume041::Get::Response::Volume041::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume041::Get::Response::Volume041::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume041::Get::Response::Volume041::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume041::Get::Response::Volume041 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume041::Get::Response::Volume041& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume041::Get::Response const& obj)
{
  j = obj._Volume041;
}

inline void from_json(const nlohmann::json& j, Volume041::Get::Response& obj)
{
  j.get_to(obj._Volume041);
}


inline void to_json(nlohmann::ordered_json& j, Volume041::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume041::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume041::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume041::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume041::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume041::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume042::Get::Response::Volume042::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume042::Get::Response::Volume042::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume042::Get::Response::Volume042::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume042::Get::Response::Volume042::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume042::Get::Response::Volume042 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume042::Get::Response::Volume042& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume042::Get::Response const& obj)
{
  j = obj._Volume042;
}

inline void from_json(const nlohmann::json& j, Volume042::Get::Response& obj)
{
  j.get_to(obj._Volume042);
}


inline void to_json(nlohmann::ordered_json& j, Volume042::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume042::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume042::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume042::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume042::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume042::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume043::Get::Response::Volume043::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume043::Get::Response::Volume043::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume043::Get::Response::Volume043::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume043::Get::Response::Volume043::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume043::Get::Response::Volume043 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume043::Get::Response::Volume043& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume043::Get::Response const& obj)
{
  j = obj._Volume043;
}

inline void from_json(const nlohmann::json& j, Volume043::Get::Response& obj)
{
  j.get_to(obj._Volume043);
}


inline void to_json(nlohmann::ordered_json& j, Volume043::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume043::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume043::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume043::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume043::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume043::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume044::Get::Response::Volume044::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume044::Get::Response::Volume044::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume044::Get::Response::Volume044::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume044::Get::Response::Volume044::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume044::Get::Response::Volume044 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume044::Get::Response::Volume044& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume044::Get::Response const& obj)
{
  j = obj._Volume044;
}

inline void from_json(const nlohmann::json& j, Volume044::Get::Response& obj)
{
  j.get_to(obj._Volume044);
}


inline void to_json(nlohmann::ordered_json& j, Volume044::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume044::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume044::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume044::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume044::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume044::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume045::Get::Response::Volume045::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume045::Get::Response::Volume045::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume045::Get::Response::Volume045::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume045::Get::Response::Volume045::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume045::Get::Response::Volume045 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume045::Get::Response::Volume045& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume045::Get::Response const& obj)
{
  j = obj._Volume045;
}

inline void from_json(const nlohmann::json& j, Volume045::Get::Response& obj)
{
  j.get_to(obj._Volume045);
}


inline void to_json(nlohmann::ordered_json& j, Volume045::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume045::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume045::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume045::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume045::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume045::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume046::Get::Response::Volume046::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume046::Get::Response::Volume046::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume046::Get::Response::Volume046::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume046::Get::Response::Volume046::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume046::Get::Response::Volume046 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume046::Get::Response::Volume046& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume046::Get::Response const& obj)
{
  j = obj._Volume046;
}

inline void from_json(const nlohmann::json& j, Volume046::Get::Response& obj)
{
  j.get_to(obj._Volume046);
}


inline void to_json(nlohmann::ordered_json& j, Volume046::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume046::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume046::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume046::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume046::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume046::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume047::Get::Response::Volume047::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume047::Get::Response::Volume047::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume047::Get::Response::Volume047::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume047::Get::Response::Volume047::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume047::Get::Response::Volume047 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume047::Get::Response::Volume047& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume047::Get::Response const& obj)
{
  j = obj._Volume047;
}

inline void from_json(const nlohmann::json& j, Volume047::Get::Response& obj)
{
  j.get_to(obj._Volume047);
}


inline void to_json(nlohmann::ordered_json& j, Volume047::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume047::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume047::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume047::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume047::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume047::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, Volume048::Get::Response::Volume048::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume048::Get::Response::Volume048::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume048::Get::Response::Volume048::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume048::Get::Response::Volume048::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume048::Get::Response::Volume048 const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume048::Get::Response::Volume048& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}

inline void to_json(nlohmann::ordered_json& j, Volume048::Get::Response const& obj)
{
  j = obj._Volume048;
}

inline void from_json(const nlohmann::json& j, Volume048::Get::Response& obj)
{
  j.get_to(obj._Volume048);
}


inline void to_json(nlohmann::ordered_json& j, Volume048::Post::Request::ExtrudedPolygonListItem::PointsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"x", obj._x},
      {"y", obj._y},
  };
}

inline void from_json(const nlohmann::json& j, Volume048::Post::Request::ExtrudedPolygonListItem::PointsItem& obj)
{
  j.at("x").get_to(obj._x);
  j.at("y").get_to(obj._y);
}

inline void to_json(nlohmann::ordered_json& j, Volume048::Post::Request::ExtrudedPolygonListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"LowerZLimit", obj._LowerZLimit.value()},
      {"UpperZLimit", obj._UpperZLimit.value()},
      {"Points", obj._Points},
  };
}

inline void from_json(const nlohmann::json& j, Volume048::Post::Request::ExtrudedPolygonListItem& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("LowerZLimit").get_to(obj._LowerZLimit);
  j.at("UpperZLimit").get_to(obj._UpperZLimit);
  j.at("Points").get_to(obj._Points);
}

inline void to_json(nlohmann::ordered_json& j, Volume048::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Name", obj._Name},
      {"ID", obj._ID},
      {"ExtrudedPolygonList", obj._ExtrudedPolygonList},
  };
}

inline void from_json(const nlohmann::json& j, Volume048::Post::Request& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Name").get_to(obj._Name);
  j.at("ID").get_to(obj._ID);
  j.at("ExtrudedPolygonList").get_to(obj._ExtrudedPolygonList);
}


inline void to_json(nlohmann::ordered_json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"State", obj._State},
  };
}

inline void from_json(const nlohmann::json& j, FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem& obj)
{
  j.at("State").get_to(obj._State);
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


inline void to_json(nlohmann::ordered_json& j, MaxVolumeAmount::Get::Response const& obj)
{
  j = obj._MaxVolumeAmount;
}

inline void from_json(const nlohmann::json& j, MaxVolumeAmount::Get::Response& obj)
{
  j.get_to(obj._MaxVolumeAmount);
}


inline void to_json(nlohmann::ordered_json& j, MaxEvaluationAmount::Get::Response const& obj)
{
  j = obj._MaxEvaluationAmount;
}

inline void from_json(const nlohmann::json& j, MaxEvaluationAmount::Get::Response& obj)
{
  j.get_to(obj._MaxEvaluationAmount);
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


inline void to_json(nlohmann::ordered_json& j, PolarProjectionParameters::Get::Response::PolarProjectionParametersItem const& obj)
{
  j = nlohmann::ordered_json{
      {"originAzimuth", obj._originAzimuth},
      {"originElevation", obj._originElevation},
      {"stepSizeAzimuth", obj._stepSizeAzimuth},
      {"stepSizeElevation", obj._stepSizeElevation},
      {"width", obj._width},
      {"height", obj._height},
  };
}

inline void from_json(const nlohmann::json& j, PolarProjectionParameters::Get::Response::PolarProjectionParametersItem& obj)
{
  j.at("originAzimuth").get_to(obj._originAzimuth);
  j.at("originElevation").get_to(obj._originElevation);
  j.at("stepSizeAzimuth").get_to(obj._stepSizeAzimuth);
  j.at("stepSizeElevation").get_to(obj._stepSizeElevation);
  j.at("width").get_to(obj._width);
  j.at("height").get_to(obj._height);
}

inline void to_json(nlohmann::ordered_json& j, PolarProjectionParameters::Get::Response const& obj)
{
  j = obj._PolarProjectionParameters;
}

inline void from_json(const nlohmann::json& j, PolarProjectionParameters::Get::Response& obj)
{
  j.get_to(obj._PolarProjectionParameters);
}


inline void to_json(nlohmann::ordered_json& j, PolarProjectionVectors::Get::Response::PolarProjectionVectorsItem const& obj)
{
  j = nlohmann::ordered_json{
      {"AzimuthAngles", obj._AzimuthAngles},
      {"ElevationAngles", obj._ElevationAngles},
  };
}

inline void from_json(const nlohmann::json& j, PolarProjectionVectors::Get::Response::PolarProjectionVectorsItem& obj)
{
  j.at("AzimuthAngles").get_to(obj._AzimuthAngles);
  j.at("ElevationAngles").get_to(obj._ElevationAngles);
}

inline void to_json(nlohmann::ordered_json& j, PolarProjectionVectors::Get::Response const& obj)
{
  j = obj._PolarProjectionVectors;
}

inline void from_json(const nlohmann::json& j, PolarProjectionVectors::Get::Response& obj)
{
  j.get_to(obj._PolarProjectionVectors);
}


inline void to_json(nlohmann::ordered_json& j, EvaluationGroupMapping::Get::Response::EvaluationGroupMappingItem::Activation const& obj)
{
  j = nlohmann::ordered_json{
      {"Type", obj._Type},
      {"Inputs", obj._Inputs},
      {"InitialActivationStateTelegram", obj._InitialActivationStateTelegram},
  };
}

inline void from_json(const nlohmann::json& j, EvaluationGroupMapping::Get::Response::EvaluationGroupMappingItem::Activation& obj)
{
  j.at("Type").get_to(obj._Type);
  j.at("Inputs").get_to(obj._Inputs);
  j.at("InitialActivationStateTelegram").get_to(obj._InitialActivationStateTelegram);
}

inline void to_json(nlohmann::ordered_json& j, EvaluationGroupMapping::Get::Response::EvaluationGroupMappingItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Name", obj._Name},
      {"Id", obj._Id.value()},
      {"Activation", obj._Activation},
      {"EvalIds", obj._EvalIds},
  };
}

inline void from_json(const nlohmann::json& j, EvaluationGroupMapping::Get::Response::EvaluationGroupMappingItem& obj)
{
  j.at("Name").get_to(obj._Name);
  j.at("Id").get_to(obj._Id);
  j.at("Activation").get_to(obj._Activation);
  j.at("EvalIds").get_to(obj._EvalIds);
}

inline void to_json(nlohmann::ordered_json& j, EvaluationGroupMapping::Get::Response const& obj)
{
  j = obj._EvaluationGroupMapping;
}

inline void from_json(const nlohmann::json& j, EvaluationGroupMapping::Get::Response& obj)
{
  j.get_to(obj._EvaluationGroupMapping);
}


inline void to_json(nlohmann::ordered_json& j, EvaluationGroupMapping::Post::Request::EvaluationGroupMappingItem::Activation const& obj)
{
  j = nlohmann::ordered_json{
      {"Type", obj._Type},
      {"Inputs", obj._Inputs},
      {"InitialActivationStateTelegram", obj._InitialActivationStateTelegram},
  };
}

inline void from_json(const nlohmann::json& j, EvaluationGroupMapping::Post::Request::EvaluationGroupMappingItem::Activation& obj)
{
  j.at("Type").get_to(obj._Type);
  j.at("Inputs").get_to(obj._Inputs);
  j.at("InitialActivationStateTelegram").get_to(obj._InitialActivationStateTelegram);
}

inline void to_json(nlohmann::ordered_json& j, EvaluationGroupMapping::Post::Request::EvaluationGroupMappingItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Name", obj._Name},
      {"Id", obj._Id.value()},
      {"Activation", obj._Activation},
      {"EvalIds", obj._EvalIds},
  };
}

inline void from_json(const nlohmann::json& j, EvaluationGroupMapping::Post::Request::EvaluationGroupMappingItem& obj)
{
  j.at("Name").get_to(obj._Name);
  j.at("Id").get_to(obj._Id);
  j.at("Activation").get_to(obj._Activation);
  j.at("EvalIds").get_to(obj._EvalIds);
}

inline void to_json(nlohmann::ordered_json& j, EvaluationGroupMapping::Post::Request const& obj)
{
  j = obj._EvaluationGroupMapping;
}

inline void from_json(const nlohmann::json& j, EvaluationGroupMapping::Post::Request& obj)
{
  j.get_to(obj._EvaluationGroupMapping);
}


inline void to_json(nlohmann::ordered_json& j, FieldEvaluationGroupState::Get::Response const& obj)
{
  j = obj._FieldEvaluationGroupState;
}

inline void from_json(const nlohmann::json& j, FieldEvaluationGroupState::Get::Response& obj)
{
  j.get_to(obj._FieldEvaluationGroupState);
}


inline void to_json(nlohmann::ordered_json& j, InputActivationSynchronizationTime::Get::Response const& obj)
{
  j = obj._InputActivationSynchronizationTime;
}

inline void from_json(const nlohmann::json& j, InputActivationSynchronizationTime::Get::Response& obj)
{
  j.get_to(obj._InputActivationSynchronizationTime);
}


inline void to_json(nlohmann::ordered_json& j, InputActivationSynchronizationTime::Post::Request const& obj)
{
  j = obj._InputActivationSynchronizationTime;
}

inline void from_json(const nlohmann::json& j, InputActivationSynchronizationTime::Post::Request& obj)
{
  j.get_to(obj._InputActivationSynchronizationTime);
}


inline void to_json(nlohmann::ordered_json& j, EvaluationConfigState::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ActiveBeamsLimit", obj._ActiveBeamsLimit},
      {"ActiveEvaluationsLimit", obj._ActiveEvaluationsLimit},
      {"NumberOfIntersectingBeams", obj._NumberOfIntersectingBeams},
      {"InputIsOutputErrorList", obj._InputIsOutputErrorList},
  };
}

inline void from_json(const nlohmann::json& j, EvaluationConfigState::Get::Response& obj)
{
  j.at("ActiveBeamsLimit").get_to(obj._ActiveBeamsLimit);
  j.at("ActiveEvaluationsLimit").get_to(obj._ActiveEvaluationsLimit);
  j.at("NumberOfIntersectingBeams").get_to(obj._NumberOfIntersectingBeams);
  j.at("InputIsOutputErrorList").get_to(obj._InputIsOutputErrorList);
}


inline void to_json(nlohmann::ordered_json& j, FieldEvaluationApplicationState::Get::Response const& obj)
{
  j = obj._FieldEvaluationApplicationState;
}

inline void from_json(const nlohmann::json& j, FieldEvaluationApplicationState::Get::Response& obj)
{
  j.get_to(obj._FieldEvaluationApplicationState);
}


inline void to_json(nlohmann::ordered_json& j, MaxActiveEvaluationsAmount::Get::Response const& obj)
{
  j = obj._MaxActiveEvaluationsAmount;
}

inline void from_json(const nlohmann::json& j, MaxActiveEvaluationsAmount::Get::Response& obj)
{
  j.get_to(obj._MaxActiveEvaluationsAmount);
}


inline void to_json(nlohmann::ordered_json& j, MaxActiveBeamsAmount::Get::Response const& obj)
{
  j = obj._MaxActiveBeamsAmount;
}

inline void from_json(const nlohmann::json& j, MaxActiveBeamsAmount::Get::Response& obj)
{
  j.get_to(obj._MaxActiveBeamsAmount);
}


inline void to_json(nlohmann::ordered_json& j, ObjectDetectionDiagnosis::Get::Response::ObjectDetectionDiagnosis::EvaluationDiagnosisListItem const& obj)
{
  j = nlohmann::ordered_json{
      {"Diagnosis", obj._Diagnosis},
  };
}

inline void from_json(const nlohmann::json& j, ObjectDetectionDiagnosis::Get::Response::ObjectDetectionDiagnosis::EvaluationDiagnosisListItem& obj)
{
  j.at("Diagnosis").get_to(obj._Diagnosis);
}

inline void to_json(nlohmann::ordered_json& j, ObjectDetectionDiagnosis::Get::Response::ObjectDetectionDiagnosis const& obj)
{
  j = nlohmann::ordered_json{
      {"Version", obj._Version},
      {"Timestamp", obj._Timestamp},
      {"EvaluationDiagnosisList", obj._EvaluationDiagnosisList},
  };
}

inline void from_json(const nlohmann::json& j, ObjectDetectionDiagnosis::Get::Response::ObjectDetectionDiagnosis& obj)
{
  j.at("Version").get_to(obj._Version);
  j.at("Timestamp").get_to(obj._Timestamp);
  j.at("EvaluationDiagnosisList").get_to(obj._EvaluationDiagnosisList);
}

inline void to_json(nlohmann::ordered_json& j, ObjectDetectionDiagnosis::Get::Response const& obj)
{
  j = obj._ObjectDetectionDiagnosis;
}

inline void from_json(const nlohmann::json& j, ObjectDetectionDiagnosis::Get::Response& obj)
{
  j.get_to(obj._ObjectDetectionDiagnosis);
}


inline void to_json(nlohmann::ordered_json& j, bIsObjectDetectionInstalled::Get::Response const& obj)
{
  j = obj._bIsObjectDetectionInstalled;
}

inline void from_json(const nlohmann::json& j, bIsObjectDetectionInstalled::Get::Response& obj)
{
  j.get_to(obj._bIsObjectDetectionInstalled);
}


inline void to_json(nlohmann::ordered_json& j, bIsObjectDetectionInstalled::Post::Request const& obj)
{
  j = obj._bIsObjectDetectionInstalled;
}

inline void from_json(const nlohmann::json& j, bIsObjectDetectionInstalled::Post::Request& obj)
{
  j.get_to(obj._bIsObjectDetectionInstalled);
}


inline void to_json(nlohmann::ordered_json& j, ActiveViewer::Get::Response const& obj)
{
  j = obj._ActiveViewer;
}

inline void from_json(const nlohmann::json& j, ActiveViewer::Get::Response& obj)
{
  j.get_to(obj._ActiveViewer);
}


inline void to_json(nlohmann::ordered_json& j, outputVisualizationContent::Get::Response::outputVisualizationContent const& obj)
{
  j = nlohmann::ordered_json{
      {"visualizeRssi", obj._visualizeRssi},
      {"visualizeProperties", obj._visualizeProperties},
      {"visualizeAmbientLight", obj._visualizeAmbientLight},
  };
}

inline void from_json(const nlohmann::json& j, outputVisualizationContent::Get::Response::outputVisualizationContent& obj)
{
  j.at("visualizeRssi").get_to(obj._visualizeRssi);
  j.at("visualizeProperties").get_to(obj._visualizeProperties);
  j.at("visualizeAmbientLight").get_to(obj._visualizeAmbientLight);
}

inline void to_json(nlohmann::ordered_json& j, outputVisualizationContent::Get::Response const& obj)
{
  j = obj._outputVisualizationContent;
}

inline void from_json(const nlohmann::json& j, outputVisualizationContent::Get::Response& obj)
{
  j.get_to(obj._outputVisualizationContent);
}


inline void to_json(nlohmann::ordered_json& j, SetActiveViewer::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"ActiveViewer", obj._ActiveViewer},
  };
}

inline void from_json(const nlohmann::json& j, SetActiveViewer::Post::Request& obj)
{
  j.at("ActiveViewer").get_to(obj._ActiveViewer);
}


inline void to_json(nlohmann::ordered_json& j, SetActiveViewer::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, SetActiveViewer::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


inline void to_json(nlohmann::ordered_json& j, setOutputVisualizationContent::Post::Request::outputVisualizationContent const& obj)
{
  j = nlohmann::ordered_json{
      {"visualizeRssi", obj._visualizeRssi},
      {"visualizeProperties", obj._visualizeProperties},
      {"visualizeAmbientLight", obj._visualizeAmbientLight},
  };
}

inline void from_json(const nlohmann::json& j, setOutputVisualizationContent::Post::Request::outputVisualizationContent& obj)
{
  j.at("visualizeRssi").get_to(obj._visualizeRssi);
  j.at("visualizeProperties").get_to(obj._visualizeProperties);
  j.at("visualizeAmbientLight").get_to(obj._visualizeAmbientLight);
}

inline void to_json(nlohmann::ordered_json& j, setOutputVisualizationContent::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"outputVisualizationContent", obj._outputVisualizationContent},
  };
}

inline void from_json(const nlohmann::json& j, setOutputVisualizationContent::Post::Request& obj)
{
  j.at("outputVisualizationContent").get_to(obj._outputVisualizationContent);
}


inline void to_json(nlohmann::ordered_json& j, setOutputVisualizationContent::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"ErrorCode", obj._ErrorCode},
  };
}

inline void from_json(const nlohmann::json& j, setOutputVisualizationContent::Post::Response& obj)
{
  j.at("ErrorCode").get_to(obj._ErrorCode);
}


inline void to_json(nlohmann::ordered_json& j, ScanConfig::Get::Response::ScanRange::aThetaAngleRangeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"udiThetaAngleRes", obj._udiThetaAngleRes.value()},
      {"diThetaStartAngle", obj._diThetaStartAngle.value()},
      {"diThetaStopAngle", obj._diThetaStopAngle.value()},
  };
}

inline void from_json(const nlohmann::json& j, ScanConfig::Get::Response::ScanRange::aThetaAngleRangeItem& obj)
{
  j.at("udiThetaAngleRes").get_to(obj._udiThetaAngleRes);
  j.at("diThetaStartAngle").get_to(obj._diThetaStartAngle);
  j.at("diThetaStopAngle").get_to(obj._diThetaStopAngle);
}

inline void to_json(nlohmann::ordered_json& j, ScanConfig::Get::Response::ScanRange::aPhiAngleRangeItem const& obj)
{
  j = nlohmann::ordered_json{
      {"udiPhiAngleRes", obj._udiPhiAngleRes.value()},
      {"diPhiStartAngle", obj._diPhiStartAngle.value()},
      {"diPhiStopAngle", obj._diPhiStopAngle.value()},
  };
}

inline void from_json(const nlohmann::json& j, ScanConfig::Get::Response::ScanRange::aPhiAngleRangeItem& obj)
{
  j.at("udiPhiAngleRes").get_to(obj._udiPhiAngleRes);
  j.at("diPhiStartAngle").get_to(obj._diPhiStartAngle);
  j.at("diPhiStopAngle").get_to(obj._diPhiStopAngle);
}

inline void to_json(nlohmann::ordered_json& j, ScanConfig::Get::Response::ScanRange const& obj)
{
  j = nlohmann::ordered_json{
      {"uiLength", obj._uiLength.value()},
      {"aThetaAngleRange", obj._aThetaAngleRange},
      {"aPhiAngleRange", obj._aPhiAngleRange},
  };
}

inline void from_json(const nlohmann::json& j, ScanConfig::Get::Response::ScanRange& obj)
{
  j.at("uiLength").get_to(obj._uiLength);
  j.at("aThetaAngleRange").get_to(obj._aThetaAngleRange);
  j.at("aPhiAngleRange").get_to(obj._aPhiAngleRange);
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


inline void to_json(nlohmann::ordered_json& j, PerformanceProfileNumber::Get::Response const& obj)
{
  j = obj._PerformanceProfileNumber;
}

inline void from_json(const nlohmann::json& j, PerformanceProfileNumber::Get::Response& obj)
{
  j.get_to(obj._PerformanceProfileNumber);
}


inline void to_json(nlohmann::ordered_json& j, PerformanceProfileNumber::Post::Request const& obj)
{
  j = obj._PerformanceProfileNumber;
}

inline void from_json(const nlohmann::json& j, PerformanceProfileNumber::Post::Request& obj)
{
  j.get_to(obj._PerformanceProfileNumber);
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


inline void to_json(nlohmann::ordered_json& j, horizontalFieldOfViewStartAngle::Get::Response const& obj)
{
  j = obj._horizontalFieldOfViewStartAngle.value();
}

inline void from_json(const nlohmann::json& j, horizontalFieldOfViewStartAngle::Get::Response& obj)
{
  j.get_to(obj._horizontalFieldOfViewStartAngle);
}


inline void to_json(nlohmann::ordered_json& j, horizontalFieldOfViewStartAngle::Post::Request const& obj)
{
  j = obj._horizontalFieldOfViewStartAngle.value();
}

inline void from_json(const nlohmann::json& j, horizontalFieldOfViewStartAngle::Post::Request& obj)
{
  j.get_to(obj._horizontalFieldOfViewStartAngle);
}


inline void to_json(nlohmann::ordered_json& j, bloomingFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"strength", obj._strength},
      {"enable", obj._enable},
  };
}

inline void from_json(const nlohmann::json& j, bloomingFilter::Get::Response& obj)
{
  j.at("strength").get_to(obj._strength);
  j.at("enable").get_to(obj._enable);
}


inline void to_json(nlohmann::ordered_json& j, bloomingFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"strength", obj._strength},
      {"enable", obj._enable},
  };
}

inline void from_json(const nlohmann::json& j, bloomingFilter::Post::Request& obj)
{
  j.at("strength").get_to(obj._strength);
  j.at("enable").get_to(obj._enable);
}


inline void to_json(nlohmann::ordered_json& j, particleFilter::Get::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"minNumberOfNeighbors", obj._minNumberOfNeighbors},
      {"distanceThreshold", obj._distanceThreshold.value()},
  };
}

inline void from_json(const nlohmann::json& j, particleFilter::Get::Response& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("minNumberOfNeighbors").get_to(obj._minNumberOfNeighbors);
  j.at("distanceThreshold").get_to(obj._distanceThreshold);
}


inline void to_json(nlohmann::ordered_json& j, particleFilter::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"enable", obj._enable},
      {"minNumberOfNeighbors", obj._minNumberOfNeighbors},
      {"distanceThreshold", obj._distanceThreshold.value()},
  };
}

inline void from_json(const nlohmann::json& j, particleFilter::Post::Request& obj)
{
  j.at("enable").get_to(obj._enable);
  j.at("minNumberOfNeighbors").get_to(obj._minNumberOfNeighbors);
  j.at("distanceThreshold").get_to(obj._distanceThreshold);
}


inline void to_json(nlohmann::ordered_json& j, ambientPixelCountVertical::Get::Response const& obj)
{
  j = obj._ambientPixelCountVertical;
}

inline void from_json(const nlohmann::json& j, ambientPixelCountVertical::Get::Response& obj)
{
  j.get_to(obj._ambientPixelCountVertical);
}


inline void to_json(nlohmann::ordered_json& j, ambientPixelCountVertical::Post::Request const& obj)
{
  j = obj._ambientPixelCountVertical;
}

inline void from_json(const nlohmann::json& j, ambientPixelCountVertical::Post::Request& obj)
{
  j.get_to(obj._ambientPixelCountVertical);
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


inline void to_json(nlohmann::ordered_json& j, CPULoad::Get::Response const& obj)
{
  j = obj._CPULoad;
}

inline void from_json(const nlohmann::json& j, CPULoad::Get::Response& obj)
{
  j.get_to(obj._CPULoad);
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


inline void to_json(nlohmann::ordered_json& j, CreateSessionToken::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"token", obj._token},
      {"timeToLive", obj._timeToLive},
  };
}

inline void from_json(const nlohmann::json& j, CreateSessionToken::Post::Response& obj)
{
  j.at("token").get_to(obj._token);
  j.at("timeToLive").get_to(obj._timeToLive);
}


inline void to_json(nlohmann::ordered_json& j, GetSessionTokenInfo::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"token", obj._token},
  };
}

inline void from_json(const nlohmann::json& j, GetSessionTokenInfo::Post::Request& obj)
{
  j.at("token").get_to(obj._token);
}


inline void to_json(nlohmann::ordered_json& j, GetSessionTokenInfo::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"status", obj._status},
      {"userlevel", obj._userlevel},
      {"timeToLive", obj._timeToLive},
  };
}

inline void from_json(const nlohmann::json& j, GetSessionTokenInfo::Post::Response& obj)
{
  j.at("status").get_to(obj._status);
  j.at("userlevel").get_to(obj._userlevel);
  j.at("timeToLive").get_to(obj._timeToLive);
}


inline void to_json(nlohmann::ordered_json& j, RenewSessionToken::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"token", obj._token},
  };
}

inline void from_json(const nlohmann::json& j, RenewSessionToken::Post::Request& obj)
{
  j.at("token").get_to(obj._token);
}


inline void to_json(nlohmann::ordered_json& j, RenewSessionToken::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"success", obj._success},
  };
}

inline void from_json(const nlohmann::json& j, RenewSessionToken::Post::Response& obj)
{
  j.at("success").get_to(obj._success);
}


inline void to_json(nlohmann::ordered_json& j, TerminateSession::Post::Request const& obj)
{
  j = nlohmann::ordered_json{
      {"token", obj._token},
  };
}

inline void from_json(const nlohmann::json& j, TerminateSession::Post::Request& obj)
{
  j.at("token").get_to(obj._token);
}


inline void to_json(nlohmann::ordered_json& j, TerminateSession::Post::Response const& obj)
{
  j = nlohmann::ordered_json{
      {"success", obj._success},
  };
}

inline void from_json(const nlohmann::json& j, TerminateSession::Post::Response& obj)
{
  j.at("success").get_to(obj._success);
}


} // namespace sick::srt::multiScan200
