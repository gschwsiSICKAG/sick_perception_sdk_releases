/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file temperatureAlarmConfiguration.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

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

  /**
   * @brief Returns/sets temperature alarm thresholds.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(int upperThreshold, int lowerThreshold)
        : _upperThreshold(upperThreshold), _lowerThreshold(lowerThreshold)
      {}

      int _upperThreshold;
      int _lowerThreshold;
    };

  }; // struct Post

}; // struct temperatureAlarmConfiguration

} // namespace sick::picoScan150::v2_2_1::api::rest
