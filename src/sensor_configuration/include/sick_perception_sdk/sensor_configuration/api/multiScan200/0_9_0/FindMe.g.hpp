/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FindMe.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /FindMe.
*/
struct SDK_EXPORT FindMe
{

  constexpr static const char* methodName = "FindMe";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Sets the device LEDs into blinking mode for better identification.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(int uiDuration)
        : _uiDuration(uiDuration)
      {}

      int _uiDuration;
    };

  }; // struct Post

}; // struct FindMe

} // namespace sick::multiScan200::v0_9_0::api::rest
