/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file temperatureAlarmStatus.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /temperatureAlarmStatus.
*/
struct SDK_EXPORT temperatureAlarmStatus
{

  constexpr static const char* variableName = "temperatureAlarmStatus";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the current device temperature alarm status. If true, the configured temperature alarm is active.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool temperatureAlarmStatus)
    : _temperatureAlarmStatus(temperatureAlarmStatus)
  {}

  bool _temperatureAlarmStatus;
};

}; // struct Get

}; // struct temperatureAlarmStatus

} // namespace sick::srt::multiScan100
