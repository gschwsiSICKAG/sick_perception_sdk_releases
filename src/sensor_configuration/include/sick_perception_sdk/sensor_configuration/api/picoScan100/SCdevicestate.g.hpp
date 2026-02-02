/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SCdevicestate.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /SCdevicestate.
*/
struct SDK_EXPORT SCdevicestate
{

  constexpr static const char* variableName = "SCdevicestate";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the device state (busy, ready, or ready).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class SCdevicestate
  {
    Busy = 0,
    Ready = 1,
    Error = 2,
  };

  Response() = default;

  explicit Response(SCdevicestate SCdevicestate)
    : _SCdevicestate(SCdevicestate)
  {}

  SCdevicestate _SCdevicestate;
};

}; // struct Get

}; // struct SCdevicestate

} // namespace sick::srt::picoScan100
