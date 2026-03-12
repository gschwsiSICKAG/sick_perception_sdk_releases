/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SystemDump.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SystemDump.
*/
struct SDK_EXPORT SystemDump
{

  constexpr static const char* methodName = "SystemDump";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Dumps system information on the console. The output is device dependent.

 This function requires at least user level: SICK Service.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct SystemDump

} // namespace sick::srt::multiScan200
