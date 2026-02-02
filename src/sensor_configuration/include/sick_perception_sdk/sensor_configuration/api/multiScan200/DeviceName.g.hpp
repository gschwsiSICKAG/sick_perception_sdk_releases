/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceName.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DeviceName.
*/
struct SDK_EXPORT DeviceName
{

  constexpr static const char* variableName = "DeviceName";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the device name given by SICK.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string DeviceName)
    : _DeviceName(std::move(DeviceName))
  {}

  std::string _DeviceName;
};

}; // struct Get

}; // struct DeviceName

} // namespace sick::srt::multiScan200
