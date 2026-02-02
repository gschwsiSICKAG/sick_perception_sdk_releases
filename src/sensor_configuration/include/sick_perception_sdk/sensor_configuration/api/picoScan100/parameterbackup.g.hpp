/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file parameterbackup.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /parameterbackup.
*/
struct SDK_EXPORT parameterbackup
{

  constexpr static const char* variableName = "parameterbackup";
  constexpr static const bool isSopasMethod = false;

}; // struct parameterbackup

} // namespace sick::srt::picoScan100
