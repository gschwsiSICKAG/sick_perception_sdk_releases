/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherAuxEnabled.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EtherAuxEnabled.
*/
struct SDK_EXPORT EtherAuxEnabled
{

  constexpr static const char* variableName = "EtherAuxEnabled";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Enables/disables the legacy interface CoLa A/B. If enabled CoLa A uses port 2111 and CoLa B uses 2112.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool EtherAuxEnabled)
    : _EtherAuxEnabled(EtherAuxEnabled)
  {}

  bool _EtherAuxEnabled;
};

}; // struct Get

/**
 * @brief Enables/disables the legacy interface CoLa A/B. If enabled CoLa A uses port 2111 and CoLa B uses 2112.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool EtherAuxEnabled)
    : _EtherAuxEnabled(EtherAuxEnabled)
  {}

  bool _EtherAuxEnabled;
};

}; // struct Post

}; // struct EtherAuxEnabled

} // namespace sick::srt::multiScan200
