/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file PortToPinMapping.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /PortToPinMapping.
*/
struct SDK_EXPORT PortToPinMapping
{

  constexpr static const char* variableName = "PortToPinMapping";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Contains list of pin numbers on the plug.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::vector<int> PortToPinMapping)
    : _PortToPinMapping(PortToPinMapping)
  {}

  std::vector<int> _PortToPinMapping;
};

}; // struct Get

}; // struct PortToPinMapping

} // namespace sick::srt::multiScan200
