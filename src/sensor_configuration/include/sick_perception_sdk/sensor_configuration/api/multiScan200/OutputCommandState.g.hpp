/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OutputCommandState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /OutputCommandState.
*/
struct SDK_EXPORT OutputCommandState
{

  constexpr static const char* variableName = "OutputCommandState";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get OutputCommandState.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<bool, 8> OutputCommandState)
    : _OutputCommandState(OutputCommandState)
  {}

  std::array<bool, 8> _OutputCommandState;
};

}; // struct Get

}; // struct OutputCommandState

} // namespace sick::srt::multiScan200
