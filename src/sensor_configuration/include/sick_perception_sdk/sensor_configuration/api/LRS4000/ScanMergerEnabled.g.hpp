/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanMergerEnabled.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /ScanMergerEnabled.
*/
struct SDK_EXPORT ScanMergerEnabled
{

  constexpr static const char* methodName = "ScanMergerEnabled";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Enable/ disable the Scan Merger functionality.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool ScanMergerEnabled)
    : _ScanMergerEnabled(ScanMergerEnabled)
  {}

  bool _ScanMergerEnabled;
};

}; // struct Post

}; // struct ScanMergerEnabled

} // namespace sick::srt::LRS4000
