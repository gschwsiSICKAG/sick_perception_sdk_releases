/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file horizontalFieldOfViewCenterAngle.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <cstdint>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /horizontalFieldOfViewCenterAngle.
*/
struct horizontalFieldOfViewCenterAngle
{

  constexpr static const char* variableName = "horizontalFieldOfViewCenterAngle";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the horizontal field of view center angle.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(NumericRange<std::int32_t, -1790000, 1800000, 0> horizontalFieldOfViewCenterAngle)
        : _horizontalFieldOfViewCenterAngle(std::move(horizontalFieldOfViewCenterAngle))
      {}

      NumericRange<std::int32_t, -1790000, 1800000, 0> _horizontalFieldOfViewCenterAngle;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the horizontal field of view center angle.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(NumericRange<std::int32_t, -1790000, 1800000, 0> horizontalFieldOfViewCenterAngle)
        : _horizontalFieldOfViewCenterAngle(std::move(horizontalFieldOfViewCenterAngle))
      {}

      NumericRange<std::int32_t, -1790000, 1800000, 0> _horizontalFieldOfViewCenterAngle;
    };

  }; // struct Post

}; // struct horizontalFieldOfViewCenterAngle

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
