/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file StopTeachIn.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::LRS4000::v1_9_0_0R::api::rest {

/**
 * @brief Payloads for endpoint /StopTeachIn.
*/
struct SDK_EXPORT StopTeachIn
{

  constexpr static const char* methodName = "StopTeachIn";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Stops the teach in process.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
  }; // struct Post

}; // struct StopTeachIn

} // namespace sick::LRS4000::v1_9_0_0R::api::rest
