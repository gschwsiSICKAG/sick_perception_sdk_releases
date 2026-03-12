/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherAuxIPPort.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherAuxIPPort.
*/
struct SDK_EXPORT EtherAuxIPPort
{

  constexpr static const char* variableName = "EtherAuxIPPort";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Port for TCP/IP communication Aux.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int EtherAuxIPPort)
    : _EtherAuxIPPort(EtherAuxIPPort)
  {}

  int _EtherAuxIPPort;
};

}; // struct Get

}; // struct EtherAuxIPPort

} // namespace sick::srt::multiScan200
