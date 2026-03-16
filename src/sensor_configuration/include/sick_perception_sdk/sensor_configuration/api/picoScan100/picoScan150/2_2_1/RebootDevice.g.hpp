/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file RebootDevice.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /RebootDevice.
*/
struct SDK_EXPORT RebootDevice
{

  constexpr static const char* methodName = "RebootDevice";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Reboots the device. All parameters are saved.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
  }; // struct Post

}; // struct RebootDevice

} // namespace sick::picoScan150::v2_2_1::api::rest
