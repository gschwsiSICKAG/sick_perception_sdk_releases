/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetSSHEnabled.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SetSSHEnabled.
*/
struct SDK_EXPORT SetSSHEnabled
{

  constexpr static const char* methodName = "SetSSHEnabled";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Enable / Disable ssh access via ethernet. sshd will not be started after reboot.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool Enable)
    : _Enable(Enable)
  {}

  bool _Enable;
};

}; // struct Post

}; // struct SetSSHEnabled

} // namespace sick::srt::multiScan200
