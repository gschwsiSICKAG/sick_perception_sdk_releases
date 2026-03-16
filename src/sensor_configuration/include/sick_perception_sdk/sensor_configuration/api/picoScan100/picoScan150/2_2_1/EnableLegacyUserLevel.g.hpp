/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableLegacyUserLevel.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /EnableLegacyUserLevel.
*/
struct SDK_EXPORT EnableLegacyUserLevel
{

  constexpr static const char* methodName = "EnableLegacyUserLevel";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Activates / deactivates a specific user level for the CoLa A/B interface.

 This function requires at least user level: Service.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(NumericRange<0, 7, 0> userLevel, bool isEnabled)
        : _userLevel(std::move(userLevel)), _isEnabled(isEnabled)
      {}

      NumericRange<0, 7, 0> _userLevel;
      bool _isEnabled;
    };

    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool result)
        : _result(result)
      {}

      bool _result;
    };

  }; // struct Post

}; // struct EnableLegacyUserLevel

} // namespace sick::picoScan150::v2_2_1::api::rest
