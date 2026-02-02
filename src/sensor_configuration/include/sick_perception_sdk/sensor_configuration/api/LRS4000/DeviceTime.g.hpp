/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceTime.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /DeviceTime.
*/
struct SDK_EXPORT DeviceTime
{

  constexpr static const char* variableName = "DeviceTime";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the current time of the internal clock (ms). The timer is 32 bit counter with a resolution of 1 ms.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int DeviceTime)
    : _DeviceTime(DeviceTime)
  {}

  int _DeviceTime;
};

}; // struct Get

}; // struct DeviceTime

} // namespace sick::srt::LRS4000
