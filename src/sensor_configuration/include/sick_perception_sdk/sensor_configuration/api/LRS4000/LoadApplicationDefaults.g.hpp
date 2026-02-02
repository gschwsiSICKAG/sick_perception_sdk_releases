/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LoadApplicationDefaults.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /LoadApplicationDefaults.
*/
struct SDK_EXPORT LoadApplicationDefaults
{

  constexpr static const char* methodName = "LoadApplicationDefaults";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Resets only the user parametrization of the fields, evaluation cases, and parameters under the section Application. Other parameters like interface settings, echo filter, etc. remain unchanged.This function requires the user level: Service.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct LoadApplicationDefaults

} // namespace sick::srt::LRS4000
