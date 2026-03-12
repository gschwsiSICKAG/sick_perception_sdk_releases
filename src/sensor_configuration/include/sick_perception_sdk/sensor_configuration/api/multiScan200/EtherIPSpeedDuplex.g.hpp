/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPSpeedDuplex.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherIPSpeedDuplex.
*/
struct SDK_EXPORT EtherIPSpeedDuplex
{

  constexpr static const char* variableName = "EtherIPSpeedDuplex";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Speed and Duplex settings.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class EtherIPSpeedDuplex
  {
    TxAuto = 0,
  };

  Response() = default;

  explicit Response(EtherIPSpeedDuplex EtherIPSpeedDuplex)
    : _EtherIPSpeedDuplex(EtherIPSpeedDuplex)
  {}

  EtherIPSpeedDuplex _EtherIPSpeedDuplex;
};

}; // struct Get

/**
 * @brief Speed and Duplex settings.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class EtherIPSpeedDuplex
  {
    TxAuto = 0,
  };

  Request() = default;

  explicit Request(EtherIPSpeedDuplex EtherIPSpeedDuplex)
    : _EtherIPSpeedDuplex(EtherIPSpeedDuplex)
  {}

  EtherIPSpeedDuplex _EtherIPSpeedDuplex;
};

}; // struct Post

}; // struct EtherIPSpeedDuplex

} // namespace sick::srt::multiScan200
