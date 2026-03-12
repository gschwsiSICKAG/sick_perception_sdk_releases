/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file HasEthernet.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /HasEthernet.
*/
struct SDK_EXPORT HasEthernet
{

  constexpr static const char* variableName = "HasEthernet";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief True if device type has got an ethernet interface.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool HasEthernet)
    : _HasEthernet(HasEthernet)
  {}

  bool _HasEthernet;
};

}; // struct Get

}; // struct HasEthernet

} // namespace sick::srt::multiScan200
