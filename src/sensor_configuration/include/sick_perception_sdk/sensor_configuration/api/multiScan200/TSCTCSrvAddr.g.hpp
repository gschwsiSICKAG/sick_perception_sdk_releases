/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCTCSrvAddr.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /TSCTCSrvAddr.
*/
struct SDK_EXPORT TSCTCSrvAddr
{

  constexpr static const char* variableName = "TSCTCSrvAddr";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Server address of the time server.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::vector<int> TSCTCSrvAddr)
    : _TSCTCSrvAddr(TSCTCSrvAddr)
  {}

  std::vector<int> _TSCTCSrvAddr;
};

}; // struct Get

/**
 * @brief Server address of the time server.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::vector<int> TSCTCSrvAddr)
    : _TSCTCSrvAddr(TSCTCSrvAddr)
  {}

  std::vector<int> _TSCTCSrvAddr;
};

}; // struct Post

}; // struct TSCTCSrvAddr

} // namespace sick::srt::multiScan200
