/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file horizontalAngleRangeFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <cstdint>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /horizontalAngleRangeFilter.
*/
struct horizontalAngleRangeFilter
{

  constexpr static const char* variableName = "horizontalAngleRangeFilter";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the horizontal angle range filter settings.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(bool enable, NumericRange<std::int32_t, -1800000, 1800000, -900000> thetaStart, NumericRange<std::int32_t, -1800000, 1800000, 900000> thetaStop, NumericRange<std::uint16_t, 1, 50, 1> thetaIndexIncrement)
        : _enable(enable), _thetaStart(std::move(thetaStart)), _thetaStop(std::move(thetaStop)), _thetaIndexIncrement(std::move(thetaIndexIncrement))
      {}

      bool _enable;
      NumericRange<std::int32_t, -1800000, 1800000, -900000> _thetaStart;
      NumericRange<std::int32_t, -1800000, 1800000, 900000> _thetaStop;
      NumericRange<std::uint16_t, 1, 50, 1> _thetaIndexIncrement;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the horizontal angle range filter settings.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(bool enable, NumericRange<std::int32_t, -1800000, 1800000, -900000> thetaStart, NumericRange<std::int32_t, -1800000, 1800000, 900000> thetaStop, NumericRange<std::uint16_t, 1, 50, 1> thetaIndexIncrement)
        : _enable(enable), _thetaStart(std::move(thetaStart)), _thetaStop(std::move(thetaStop)), _thetaIndexIncrement(std::move(thetaIndexIncrement))
      {}

      bool _enable;
      NumericRange<std::int32_t, -1800000, 1800000, -900000> _thetaStart;
      NumericRange<std::int32_t, -1800000, 1800000, 900000> _thetaStop;
      NumericRange<std::uint16_t, 1, 50, 1> _thetaIndexIncrement;
    };

  }; // struct Post

}; // struct horizontalAngleRangeFilter

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
