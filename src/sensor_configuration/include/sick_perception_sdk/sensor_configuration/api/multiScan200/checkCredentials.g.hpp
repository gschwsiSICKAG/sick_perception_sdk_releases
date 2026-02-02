/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file checkCredentials.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /checkCredentials.
*/
struct SDK_EXPORT checkCredentials
{

  constexpr static const char* methodName = "checkCredentials";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Returns authentication success. For more details see https://github.com/SICKAG/sick_scan_rest_client.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct checkCredentials

} // namespace sick::srt::multiScan200
