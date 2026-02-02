/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableDetectionHistory.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /EnableDetectionHistory.
*/
struct SDK_EXPORT EnableDetectionHistory
{

  constexpr static const char* methodName = "EnableDetectionHistory";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Enables/disables the detection history.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool EnableDetectionHistory)
    : _EnableDetectionHistory(EnableDetectionHistory)
  {}

  bool _EnableDetectionHistory;
};

}; // struct Post

}; // struct EnableDetectionHistory

} // namespace sick::srt::picoScan100
