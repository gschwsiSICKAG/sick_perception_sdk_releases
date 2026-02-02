/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file RebootDevice.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /RebootDevice.
*/
struct SDK_EXPORT RebootDevice
{

  constexpr static const char* methodName = "RebootDevice";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Reboots the device. All parameters are saved. This function requires the user level: Service.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct RebootDevice

} // namespace sick::srt::multiScan100
