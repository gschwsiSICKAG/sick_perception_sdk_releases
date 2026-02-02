/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ActualEncPosition1Enable.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /ActualEncPosition1Enable.
*/
struct SDK_EXPORT ActualEncPosition1Enable
{

  constexpr static const char* methodName = "ActualEncPosition1Enable";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Enables/disables the use of the 1st reference signal (port 3).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool ActualEncPosition1Enable)
    : _ActualEncPosition1Enable(ActualEncPosition1Enable)
  {}

  bool _ActualEncPosition1Enable;
};

}; // struct Post

}; // struct ActualEncPosition1Enable

} // namespace sick::srt::picoScan100
