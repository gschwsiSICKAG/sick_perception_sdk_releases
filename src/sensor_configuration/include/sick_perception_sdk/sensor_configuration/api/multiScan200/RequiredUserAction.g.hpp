/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file RequiredUserAction.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /RequiredUserAction.
*/
struct SDK_EXPORT RequiredUserAction
{

  constexpr static const char* variableName = "RequiredUserAction";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief A Hint what can be done if the DeviceStatus is not DS_NormalOperation.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT RequiredUserAction
  {
    RequiredUserAction() = default;

    explicit RequiredUserAction(bool ConfirmConfiguration, bool CheckConfiguration, bool CheckEnvironment, bool CheckApplicationInterfaces, bool CheckDevice, bool RunSetupProcedure, bool CheckFirmware, bool Wait, int Reserved)
      : _ConfirmConfiguration(ConfirmConfiguration), _CheckConfiguration(CheckConfiguration), _CheckEnvironment(CheckEnvironment), _CheckApplicationInterfaces(CheckApplicationInterfaces), _CheckDevice(CheckDevice), _RunSetupProcedure(RunSetupProcedure), _CheckFirmware(CheckFirmware), _Wait(Wait), _Reserved(Reserved)
    {}

    bool _ConfirmConfiguration;
    bool _CheckConfiguration;
    bool _CheckEnvironment;
    bool _CheckApplicationInterfaces;
    bool _CheckDevice;
    bool _RunSetupProcedure;
    bool _CheckFirmware;
    bool _Wait;
    int _Reserved;
  };

  Response() = default;

  explicit Response(RequiredUserAction RequiredUserAction)
    : _RequiredUserAction(RequiredUserAction)
  {}

  RequiredUserAction _RequiredUserAction;
};

}; // struct Get

}; // struct RequiredUserAction

} // namespace sick::srt::multiScan200
