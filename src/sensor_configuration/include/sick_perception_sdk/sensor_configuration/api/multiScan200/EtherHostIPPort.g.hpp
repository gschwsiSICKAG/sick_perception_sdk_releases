/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherHostIPPort.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherHostIPPort.
*/
struct SDK_EXPORT EtherHostIPPort
{

  constexpr static const char* variableName = "EtherHostIPPort";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Port for TCP/IP communication Aux.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int EtherHostIPPort)
    : _EtherHostIPPort(EtherHostIPPort)
  {}

  int _EtherHostIPPort;
};

}; // struct Get

}; // struct EtherHostIPPort

} // namespace sick::srt::multiScan200
