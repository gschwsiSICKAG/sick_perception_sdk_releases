/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AppConsoleOutput.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /AppConsoleOutput.
*/
struct SDK_EXPORT AppConsoleOutput
{

  constexpr static const char* variableName = "AppConsoleOutput";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief App Console output.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string AppConsoleOutput)
    : _AppConsoleOutput(std::move(AppConsoleOutput))
  {}

  std::string _AppConsoleOutput;
};

}; // struct Get

}; // struct AppConsoleOutput

} // namespace sick::srt::multiScan200
