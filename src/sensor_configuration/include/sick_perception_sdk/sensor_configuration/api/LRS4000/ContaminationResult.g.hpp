/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ContaminationResult.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

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

  explicit Response(bool warningActive, bool errorActive)
    : _warningActive(warningActive), _errorActive(errorActive)
  {}

  bool _warningActive;
  bool _errorActive;
};

}; // struct Get

}; // struct ContaminationResult

} // namespace sick::srt::LRS4000
