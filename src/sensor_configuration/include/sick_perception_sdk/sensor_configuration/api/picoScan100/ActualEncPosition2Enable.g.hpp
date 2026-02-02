/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ActualEncPosition2Enable.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /ActualEncPosition2Enable.
*/
struct SDK_EXPORT ActualEncPosition2Enable
{

  constexpr static const char* methodName = "ActualEncPosition2Enable";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Enables/disables the use of the 2nd reference signal (port 4).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool ActualEncPosition2Enable)
    : _ActualEncPosition2Enable(ActualEncPosition2Enable)
  {}

  bool _ActualEncPosition2Enable;
};

}; // struct Post

}; // struct ActualEncPosition2Enable

} // namespace sick::srt::picoScan100
