/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file temperatureAlarmConfiguration.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

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

} // namespace sick::multiScan200::v0_9_0::api::rest
