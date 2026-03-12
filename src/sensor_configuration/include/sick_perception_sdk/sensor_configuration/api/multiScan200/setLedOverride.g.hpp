/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file setLedOverride.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /setLedOverride.
*/
struct SDK_EXPORT setLedOverride
{

  constexpr static const char* methodName = "setLedOverride";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Activate or deactivate the override mode for LEDs.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool enable)
    : _enable(enable)
  {}

  bool _enable;
};

}; // struct Post

}; // struct setLedOverride

} // namespace sick::srt::multiScan200
