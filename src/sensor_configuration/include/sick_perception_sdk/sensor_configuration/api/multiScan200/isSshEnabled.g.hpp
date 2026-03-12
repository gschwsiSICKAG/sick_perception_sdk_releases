/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file isSshEnabled.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /isSshEnabled.
*/
struct SDK_EXPORT isSshEnabled
{

  constexpr static const char* variableName = "isSshEnabled";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Read SSH state.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool isSshEnabled)
    : _isSshEnabled(isSshEnabled)
  {}

  bool _isSshEnabled;
};

}; // struct Get

}; // struct isSshEnabled

} // namespace sick::srt::multiScan200
