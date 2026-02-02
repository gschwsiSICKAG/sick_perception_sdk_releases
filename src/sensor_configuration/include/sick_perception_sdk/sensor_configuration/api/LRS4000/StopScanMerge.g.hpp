/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file StopScanMerge.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /StopScanMerge.
*/
struct SDK_EXPORT StopScanMerge
{

  constexpr static const char* methodName = "StopScanMerge";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Stop the recording of a running scan merge.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct StopScanMerge

} // namespace sick::srt::LRS4000
