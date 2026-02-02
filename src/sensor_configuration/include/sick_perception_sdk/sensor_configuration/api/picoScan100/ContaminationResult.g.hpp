/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ContaminationResult.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /ContaminationResult.
*/
struct SDK_EXPORT ContaminationResult
{

  constexpr static const char* variableName = "ContaminationResult";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the contamination indication state of the device.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool bWarningActive, bool bErrorActive)
    : _bWarningActive(bWarningActive), _bErrorActive(bErrorActive)
  {}

  bool _bWarningActive;
  bool _bErrorActive;
};

}; // struct Get

}; // struct ContaminationResult

} // namespace sick::srt::picoScan100
