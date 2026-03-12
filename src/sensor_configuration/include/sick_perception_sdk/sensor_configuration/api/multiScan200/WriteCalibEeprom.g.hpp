/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file WriteCalibEeprom.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /WriteCalibEeprom.
*/
struct SDK_EXPORT WriteCalibEeprom
{

  constexpr static const char* methodName = "WriteCalibEeprom";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Method writes all calibration parameters from the SOPAS mirror to the CalibEEprom.

 This function requires at least user level: Production.
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

}; // struct WriteCalibEeprom

} // namespace sick::srt::multiScan200
