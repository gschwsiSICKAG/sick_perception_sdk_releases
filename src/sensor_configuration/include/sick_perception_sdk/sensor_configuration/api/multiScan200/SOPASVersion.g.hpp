/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SOPASVersion.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SOPASVersion.
*/
struct SDK_EXPORT SOPASVersion
{

  constexpr static const char* variableName = "SOPASVersion";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Version of SOPAS runtime (SOPAS DCD).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int Version, int Release, int Build)
    : _Version(Version), _Release(Release), _Build(Build)
  {}

  int _Version;
  int _Release;
  int _Build;
};

}; // struct Get

}; // struct SOPASVersion

} // namespace sick::srt::multiScan200
