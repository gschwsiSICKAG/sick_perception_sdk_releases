/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableLongRangeMode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /EnableLongRangeMode.
*/
struct SDK_EXPORT EnableLongRangeMode
{

  constexpr static const char* variableName = "EnableLongRangeMode";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Enables/disables the maximum scanning range depending on the scan configuration.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool EnableLongRangeMode)
        : _EnableLongRangeMode(EnableLongRangeMode)
      {}

      bool _EnableLongRangeMode;
    };

  }; // struct Get

  /**
   * @brief Enables/disables the maximum scanning range depending on the scan configuration.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(bool EnableLongRangeMode)
        : _EnableLongRangeMode(EnableLongRangeMode)
      {}

      bool _EnableLongRangeMode;
    };

  }; // struct Post

}; // struct EnableLongRangeMode

} // namespace sick::picoScan150::v2_2_1::api::rest
