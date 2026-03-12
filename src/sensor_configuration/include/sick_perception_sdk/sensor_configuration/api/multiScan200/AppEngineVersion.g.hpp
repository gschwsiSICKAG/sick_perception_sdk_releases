/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file AppEngineVersion.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /AppEngineVersion.
*/
struct SDK_EXPORT AppEngineVersion
{

  constexpr static const char* variableName = "AppEngineVersion";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief AppEngine version.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string AppEngineVersion)
    : _AppEngineVersion(std::move(AppEngineVersion))
  {}

  std::string _AppEngineVersion;
};

}; // struct Get

/**
 * @brief AppEngine version.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string AppEngineVersion)
    : _AppEngineVersion(std::move(AppEngineVersion))
  {}

  std::string _AppEngineVersion;
};

}; // struct Post

}; // struct AppEngineVersion

} // namespace sick::srt::multiScan200
