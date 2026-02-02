/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableInertialMeasurementUnit.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /EnableInertialMeasurementUnit.
*/
struct SDK_EXPORT EnableInertialMeasurementUnit
{

  constexpr static const char* methodName = "EnableInertialMeasurementUnit";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Enables/Disables IMU data streaming output on CoLa A/B protocol.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool EnableInertialMeasurementUnit)
    : _EnableInertialMeasurementUnit(EnableInertialMeasurementUnit)
  {}

  bool _EnableInertialMeasurementUnit;
};

}; // struct Post

}; // struct EnableInertialMeasurementUnit

} // namespace sick::srt::LRS4000
