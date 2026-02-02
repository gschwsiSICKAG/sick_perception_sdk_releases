/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FirmwareVersion.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /FirmwareVersion.
*/
struct SDK_EXPORT FirmwareVersion
{

  constexpr static const char* variableName = "FirmwareVersion";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the current firmware version.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string FirmwareVersion)
    : _FirmwareVersion(std::move(FirmwareVersion))
  {}

  std::string _FirmwareVersion;
};

}; // struct Get

}; // struct FirmwareVersion

} // namespace sick::srt::picoScan100
