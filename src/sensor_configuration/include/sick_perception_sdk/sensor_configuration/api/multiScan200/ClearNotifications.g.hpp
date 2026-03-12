/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ClearNotifications.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ClearNotifications.
*/
struct SDK_EXPORT ClearNotifications
{

  constexpr static const char* methodName = "ClearNotifications";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief This function clears all active entries of the notification memory.

 This function requires at least user level: SICK Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool bSuccess)
    : _bSuccess(bSuccess)
  {}

  bool _bSuccess;
};

}; // struct Post

}; // struct ClearNotifications

} // namespace sick::srt::multiScan200
