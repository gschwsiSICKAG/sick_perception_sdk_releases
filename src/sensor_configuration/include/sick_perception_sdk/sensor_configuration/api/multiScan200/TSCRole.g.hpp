/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCRole.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /TSCRole.
*/
struct SDK_EXPORT TSCRole
{

  constexpr static const char* variableName = "TSCRole";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Select the role (none or client).
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
  };

  Response() = default;

  explicit Response(TSCRole TSCRole)
    : _TSCRole(TSCRole)
  {}

  TSCRole _TSCRole;
};

}; // struct Get

/**
 * @brief Select the role (none or client).

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
  };

  Request() = default;

  explicit Request(TSCRole TSCRole)
    : _TSCRole(TSCRole)
  {}

  TSCRole _TSCRole;
};

}; // struct Post

}; // struct TSCRole

} // namespace sick::srt::multiScan200
