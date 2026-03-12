/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AppDebugEnvironment.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /AppDebugEnvironment.
*/
struct SDK_EXPORT AppDebugEnvironment
{

  constexpr static const char* variableName = "AppDebugEnvironment";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief App debugging environment.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string AppDebugEnvironment)
    : _AppDebugEnvironment(std::move(AppDebugEnvironment))
  {}

  std::string _AppDebugEnvironment;
};

}; // struct Get

}; // struct AppDebugEnvironment

} // namespace sick::srt::multiScan200
