/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OpHours.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /OpHours.
*/
struct SDK_EXPORT OpHours
{

  constexpr static const char* variableName = "OpHours";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the total number of operating hours during the lifetime of the device. The resolution is 1/10 hour.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int OpHours)
    : _OpHours(OpHours)
  {}

  int _OpHours;
};

}; // struct Get

}; // struct OpHours

} // namespace sick::srt::multiScan200
