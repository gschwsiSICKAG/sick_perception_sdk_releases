/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file temperatureAlarmStatus.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /temperatureAlarmStatus.
*/
struct SDK_EXPORT temperatureAlarmStatus
{

  constexpr static const char* variableName = "temperatureAlarmStatus";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Current device temperature alarm status. If true, the configured temperature alarm is active.
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

} // namespace sick::srt::multiScan200
