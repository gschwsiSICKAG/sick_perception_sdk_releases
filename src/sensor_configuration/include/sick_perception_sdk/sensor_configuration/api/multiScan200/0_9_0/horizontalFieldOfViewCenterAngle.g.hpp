/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file horizontalFieldOfViewCenterAngle.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /horizontalFieldOfViewCenterAngle.
*/
struct SDK_EXPORT horizontalFieldOfViewCenterAngle
{

  constexpr static const char* variableName = "horizontalFieldOfViewCenterAngle";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the horizontal field of view center angle.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(NumericRange<-1790000, 1800000, 0> horizontalFieldOfViewCenterAngle)
        : _horizontalFieldOfViewCenterAngle(std::move(horizontalFieldOfViewCenterAngle))
      {}

      NumericRange<-1790000, 1800000, 0> _horizontalFieldOfViewCenterAngle;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the horizontal field of view center angle.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(NumericRange<-1790000, 1800000, 0> horizontalFieldOfViewCenterAngle)
        : _horizontalFieldOfViewCenterAngle(std::move(horizontalFieldOfViewCenterAngle))
      {}

      NumericRange<-1790000, 1800000, 0> _horizontalFieldOfViewCenterAngle;
    };

  }; // struct Post

}; // struct horizontalFieldOfViewCenterAngle

} // namespace sick::multiScan200::v0_9_0::api::rest
