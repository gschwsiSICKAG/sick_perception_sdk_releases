/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LoadFactoryDefaults.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /LoadFactoryDefaults.
*/
struct SDK_EXPORT LoadFactoryDefaults
{

  constexpr static const char* methodName = "LoadFactoryDefaults";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Resets all parameters to default.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct LoadFactoryDefaults

} // namespace sick::srt::picoScan100
