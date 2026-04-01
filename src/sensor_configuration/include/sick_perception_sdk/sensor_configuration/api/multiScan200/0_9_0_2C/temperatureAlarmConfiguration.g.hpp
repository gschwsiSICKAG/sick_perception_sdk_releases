/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file temperatureAlarmConfiguration.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <cstdint>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /temperatureAlarmConfiguration.
*/
struct temperatureAlarmConfiguration
{

  constexpr static const char* variableName = "temperatureAlarmConfiguration";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets temperature alarm thresholds.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::int8_t upperThreshold, std::int8_t lowerThreshold)
        : _upperThreshold(upperThreshold), _lowerThreshold(lowerThreshold)
      {}

      std::int8_t _upperThreshold;
      std::int8_t _lowerThreshold;
    };

  }; // struct Get

}; // struct temperatureAlarmConfiguration

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
