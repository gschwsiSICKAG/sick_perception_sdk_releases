/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCRole.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /TSCRole.
*/
struct SDK_EXPORT TSCRole
{

  constexpr static const char* variableName = "TSCRole";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the time synchronization role (none = 0 , NTP = 1 or PTP = 3).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class TSCRole
  {
    TxNone = 0,
    TxClient = 1,
    TxPtpSlave = 3,
    TxPtpMaster = 4,
  };

  Response() = default;

  explicit Response(TSCRole TSCRole)
    : _TSCRole(TSCRole)
  {}

  TSCRole _TSCRole;
};

}; // struct Get

/**
 * @brief Returns/sets the time synchronization role (none = 0 , NTP = 1 or PTP = 3).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class TSCRole
  {
    TxNone = 0,
    TxClient = 1,
    TxPtpSlave = 3,
    TxPtpMaster = 4,
  };

  Request() = default;

  explicit Request(TSCRole TSCRole)
    : _TSCRole(TSCRole)
  {}

  TSCRole _TSCRole;
};

}; // struct Post

}; // struct TSCRole

} // namespace sick::srt::LRS4000
