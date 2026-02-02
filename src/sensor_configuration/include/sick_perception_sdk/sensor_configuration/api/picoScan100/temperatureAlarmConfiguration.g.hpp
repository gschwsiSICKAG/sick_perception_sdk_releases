/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file temperatureAlarmConfiguration.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /temperatureAlarmConfiguration.
*/
struct SDK_EXPORT temperatureAlarmConfiguration
{

  constexpr static const char* variableName = "temperatureAlarmConfiguration";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets temperature alarm thresholds.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int upperThreshold, int lowerThreshold)
    : _upperThreshold(upperThreshold), _lowerThreshold(lowerThreshold)
  {}

  int _upperThreshold;
  int _lowerThreshold;
};

}; // struct Get

}; // struct temperatureAlarmConfiguration

} // namespace sick::srt::picoScan100
