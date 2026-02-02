/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file UpdateState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /UpdateState.
*/
struct SDK_EXPORT UpdateState
{

  constexpr static const char* variableName = "UpdateState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the state of the update process.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class UpdateState
  {
    Initial = 0,
    Started = 1,
    Finished = 2,
    Error = 3,
  };

  Response() = default;

  explicit Response(UpdateState UpdateState)
    : _UpdateState(UpdateState)
  {}

  UpdateState _UpdateState;
};

}; // struct Get

}; // struct UpdateState

} // namespace sick::srt::multiScan200
