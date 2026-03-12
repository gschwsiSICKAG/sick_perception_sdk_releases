/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TSCTCupdatetime.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /TSCTCupdatetime.
*/
struct SDK_EXPORT TSCTCupdatetime
{

  constexpr static const char* variableName = "TSCTCupdatetime";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Update time for the time client.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(NumericRange<1, 3600, 600> TSCTCupdatetime)
    : _TSCTCupdatetime(std::move(TSCTCupdatetime))
  {}

  NumericRange<1, 3600, 600> _TSCTCupdatetime;
};

}; // struct Get

/**
 * @brief Update time for the time client.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(NumericRange<1, 3600, 600> TSCTCupdatetime)
    : _TSCTCupdatetime(std::move(TSCTCupdatetime))
  {}

  NumericRange<1, 3600, 600> _TSCTCupdatetime;
};

}; // struct Post

}; // struct TSCTCupdatetime

} // namespace sick::srt::multiScan200
