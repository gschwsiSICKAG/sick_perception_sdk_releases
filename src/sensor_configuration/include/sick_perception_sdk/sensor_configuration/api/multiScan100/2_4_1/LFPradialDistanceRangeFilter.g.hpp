/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LFPradialDistanceRangeFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /LFPradialDistanceRangeFilter.
*/
struct SDK_EXPORT LFPradialDistanceRangeFilter
{

  constexpr static const char* variableName = "LFPradialDistanceRangeFilter";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the scanning range filter settings. Restriction of the distance measurements to a specified distance range. Measurement distances outside of the specified distance are assigned the distance and RSSI value 0.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool bEnable, NumericRange<0, 200000, 0> ulDistMin, NumericRange<0, 200000, 20000> ulDistMax)
        : _bEnable(bEnable), _ulDistMin(std::move(ulDistMin)), _ulDistMax(std::move(ulDistMax))
      {}

      bool _bEnable;
      NumericRange<0, 200000, 0> _ulDistMin;
      NumericRange<0, 200000, 20000> _ulDistMax;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the scanning range filter settings. Restriction of the distance measurements to a specified distance range. Measurement distances outside of the specified distance are assigned the distance and RSSI value 0.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(bool bEnable, NumericRange<0, 200000, 0> ulDistMin, NumericRange<0, 200000, 20000> ulDistMax)
        : _bEnable(bEnable), _ulDistMin(std::move(ulDistMin)), _ulDistMax(std::move(ulDistMax))
      {}

      bool _bEnable;
      NumericRange<0, 200000, 0> _ulDistMin;
      NumericRange<0, 200000, 20000> _ulDistMax;
    };

  }; // struct Post

}; // struct LFPradialDistanceRangeFilter

} // namespace sick::multiScan100::v2_4_1::api::rest
