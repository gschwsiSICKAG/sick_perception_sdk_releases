/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceStatus.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DeviceStatus.
*/
struct SDK_EXPORT DeviceStatus
{

  constexpr static const char* variableName = "DeviceStatus";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the device state (9 possible states).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class DeviceStatus
  {
    DsUnknownstate = 0,
    DsStartup = 1,
    DsServicemode = 2,
    DsNormaloperation = 3,
    DsSuspendedoperation = 4,
    DsServicerecommended = 5,
    DsServicerequired = 6,
    DsRecoverableerror = 7,
    DsFatalerror = 8,
  };

  Response() = default;

  explicit Response(DeviceStatus DeviceStatus)
    : _DeviceStatus(DeviceStatus)
  {}

  DeviceStatus _DeviceStatus;
};

}; // struct Get

}; // struct DeviceStatus

} // namespace sick::srt::multiScan200
