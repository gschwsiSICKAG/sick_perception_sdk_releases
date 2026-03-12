/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherHostCoLaDialect.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherHostCoLaDialect.
*/
struct SDK_EXPORT EtherHostCoLaDialect
{

  constexpr static const char* variableName = "EtherHostCoLaDialect";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Selects if Ethernet Host is CoLaA or CoLaB.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class EtherHostCoLaDialect
  {
    TxColaAscii = 0,
    TxColaBinary = 1,
  };

  Response() = default;

  explicit Response(EtherHostCoLaDialect EtherHostCoLaDialect)
    : _EtherHostCoLaDialect(EtherHostCoLaDialect)
  {}

  EtherHostCoLaDialect _EtherHostCoLaDialect;
};

}; // struct Get

}; // struct EtherHostCoLaDialect

} // namespace sick::srt::multiScan200
