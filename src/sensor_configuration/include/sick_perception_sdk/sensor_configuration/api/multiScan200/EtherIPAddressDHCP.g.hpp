/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPAddressDHCP.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherIPAddressDHCP.
*/
struct SDK_EXPORT EtherIPAddressDHCP
{

  constexpr static const char* variableName = "EtherIPAddressDHCP";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the assigned DHCP IP address.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 4> EtherIPAddressDHCP)
    : _EtherIPAddressDHCP(EtherIPAddressDHCP)
  {}

  std::array<int, 4> _EtherIPAddressDHCP;
};

}; // struct Get

}; // struct EtherIPAddressDHCP

} // namespace sick::srt::multiScan200
