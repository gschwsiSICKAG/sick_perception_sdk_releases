/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableColaScan.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /EnableColaScan.
*/
struct SDK_EXPORT EnableColaScan
{

  constexpr static const char* variableName = "EnableColaScan";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Enables/disables the device search by SICK tools. If disabled, finding the device via device search and changing the IP address via SICK tools is not possible.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool EnableColaScan)
        : _EnableColaScan(EnableColaScan)
      {}

      bool _EnableColaScan;
    };

  }; // struct Get

  /**
   * @brief Enables/disables the device search by SICK tools. If disabled, finding the device via device search and changing the IP address via SICK tools is not possible.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(bool EnableColaScan)
        : _EnableColaScan(EnableColaScan)
      {}

      bool _EnableColaScan;
    };

  }; // struct Post

}; // struct EnableColaScan

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
