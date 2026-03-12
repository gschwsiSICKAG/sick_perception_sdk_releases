/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceIdent.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DeviceIdent.
*/
struct SDK_EXPORT DeviceIdent
{

  constexpr static const char* variableName = "DeviceIdent";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Unique Identification of device.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string Name, std::string Version)
    : _Name(std::move(Name)), _Version(std::move(Version))
  {}

  std::string _Name;
  std::string _Version;
};

}; // struct Get

}; // struct DeviceIdent

} // namespace sick::srt::multiScan200
