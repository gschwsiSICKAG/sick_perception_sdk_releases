/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file parameterbackup.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /parameterbackup.
*/
struct SDK_EXPORT parameterbackup
{

  constexpr static const char* variableName = "parameterbackup";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Reads/transfers the backup file (.json) from/to the device.
*/
struct SDK_EXPORT Get
{
}; // struct Get

}; // struct parameterbackup

} // namespace sick::srt::multiScan100
