/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LoadApplicationDefaults.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /LoadApplicationDefaults.
*/
struct SDK_EXPORT LoadApplicationDefaults
{

  constexpr static const char* methodName = "LoadApplicationDefaults";
  constexpr static const bool isSopasMethod = true;

  /**
   * @brief Resets only the user parameterization of the fields, evaluation cases, and parameters under the section "Application". Other parameters like interface settings, echo filter, etc. remain unchanged.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
  }; // struct Post

}; // struct LoadApplicationDefaults

} // namespace sick::multiScan200::v0_9_0::api::rest
