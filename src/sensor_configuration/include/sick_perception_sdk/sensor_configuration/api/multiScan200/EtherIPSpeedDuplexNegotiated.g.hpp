/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPSpeedDuplexNegotiated.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherIPSpeedDuplexNegotiated.
*/
struct SDK_EXPORT EtherIPSpeedDuplexNegotiated
{

  constexpr static const char* variableName = "EtherIPSpeedDuplexNegotiated";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Speed and Duplex settings as negotiated when set to AUTO.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class EtherIPSpeedDuplexNegotiated
  {
    TxUnknownDuplexSpeed = 0,
    Tx10mbHalf = 1,
    Tx10mbFull = 2,
    Tx100mbHalf = 3,
    Tx100mbFull = 4,
    Tx1000mbHalf = 5,
    Tx1000mbFull = 6,
  };

  Response() = default;

  explicit Response(EtherIPSpeedDuplexNegotiated EtherIPSpeedDuplexNegotiated)
    : _EtherIPSpeedDuplexNegotiated(EtherIPSpeedDuplexNegotiated)
  {}

  EtherIPSpeedDuplexNegotiated _EtherIPSpeedDuplexNegotiated;
};

}; // struct Get

}; // struct EtherIPSpeedDuplexNegotiated

} // namespace sick::srt::multiScan200
