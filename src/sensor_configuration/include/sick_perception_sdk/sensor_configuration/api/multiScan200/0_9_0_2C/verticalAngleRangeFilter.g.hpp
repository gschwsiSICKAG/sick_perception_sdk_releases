/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file verticalAngleRangeFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <cstdint>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /verticalAngleRangeFilter.
*/
struct verticalAngleRangeFilter
{

  constexpr static const char* variableName = "verticalAngleRangeFilter";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the vertical angle range filter settings.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(bool enable, NumericRange<std::int32_t, -900000, 900000, -250000> outerRoiStartAngle, NumericRange<std::int32_t, -900000, 900000, 250000> outerRoiStopAngle, NumericRange<std::int32_t, -900000, 900000, -100000> innerRoiStartAngle, NumericRange<std::int32_t, -900000, 900000, 100000> innerRoiStopAngle, NumericRange<std::uint16_t, 1, 50, 2> outerRoiIndexIncrement, NumericRange<std::uint16_t, 1, 50, 1> innerRoiIndexIncrement)
        : _enable(enable), _outerRoiStartAngle(std::move(outerRoiStartAngle)), _outerRoiStopAngle(std::move(outerRoiStopAngle)), _innerRoiStartAngle(std::move(innerRoiStartAngle)), _innerRoiStopAngle(std::move(innerRoiStopAngle)), _outerRoiIndexIncrement(std::move(outerRoiIndexIncrement)), _innerRoiIndexIncrement(std::move(innerRoiIndexIncrement))
      {}

      bool _enable;
      NumericRange<std::int32_t, -900000, 900000, -250000> _outerRoiStartAngle;
      NumericRange<std::int32_t, -900000, 900000, 250000> _outerRoiStopAngle;
      NumericRange<std::int32_t, -900000, 900000, -100000> _innerRoiStartAngle;
      NumericRange<std::int32_t, -900000, 900000, 100000> _innerRoiStopAngle;
      NumericRange<std::uint16_t, 1, 50, 2> _outerRoiIndexIncrement;
      NumericRange<std::uint16_t, 1, 50, 1> _innerRoiIndexIncrement;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the vertical angle range filter settings.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(bool enable, NumericRange<std::int32_t, -900000, 900000, -250000> outerRoiStartAngle, NumericRange<std::int32_t, -900000, 900000, 250000> outerRoiStopAngle, NumericRange<std::int32_t, -900000, 900000, -100000> innerRoiStartAngle, NumericRange<std::int32_t, -900000, 900000, 100000> innerRoiStopAngle, NumericRange<std::uint16_t, 1, 50, 2> outerRoiIndexIncrement, NumericRange<std::uint16_t, 1, 50, 1> innerRoiIndexIncrement)
        : _enable(enable), _outerRoiStartAngle(std::move(outerRoiStartAngle)), _outerRoiStopAngle(std::move(outerRoiStopAngle)), _innerRoiStartAngle(std::move(innerRoiStartAngle)), _innerRoiStopAngle(std::move(innerRoiStopAngle)), _outerRoiIndexIncrement(std::move(outerRoiIndexIncrement)), _innerRoiIndexIncrement(std::move(innerRoiIndexIncrement))
      {}

      bool _enable;
      NumericRange<std::int32_t, -900000, 900000, -250000> _outerRoiStartAngle;
      NumericRange<std::int32_t, -900000, 900000, 250000> _outerRoiStopAngle;
      NumericRange<std::int32_t, -900000, 900000, -100000> _innerRoiStartAngle;
      NumericRange<std::int32_t, -900000, 900000, 100000> _innerRoiStopAngle;
      NumericRange<std::uint16_t, 1, 50, 2> _outerRoiIndexIncrement;
      NumericRange<std::uint16_t, 1, 50, 1> _innerRoiIndexIncrement;
    };

  }; // struct Post

}; // struct verticalAngleRangeFilter

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
