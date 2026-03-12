/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file CopySensorOrientationFromImu.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /CopySensorOrientationFromImu.
*/
struct SDK_EXPORT CopySensorOrientationFromImu
{

  constexpr static const char* methodName = "CopySensorOrientationFromImu";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Copy roll and pitch angles from IMU data to sensor orientation.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct CopySensorOrientationFromImu

} // namespace sick::srt::multiScan200
