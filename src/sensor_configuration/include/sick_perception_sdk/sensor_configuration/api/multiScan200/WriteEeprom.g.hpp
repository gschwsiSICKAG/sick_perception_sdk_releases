/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file WriteEeprom.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /WriteEeprom.
*/
struct SDK_EXPORT WriteEeprom
{

  constexpr static const char* methodName = "WriteEeprom";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Method writes all permanent parameters from the SOPAS mirror to the ParamEEprom.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Success)
    : _Success(Success)
  {}

  bool _Success;
};

}; // struct Post

}; // struct WriteEeprom

} // namespace sick::srt::multiScan200
