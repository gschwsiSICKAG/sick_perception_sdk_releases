/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetFilesImmutableFlag.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SetFilesImmutableFlag.
*/
struct SDK_EXPORT SetFilesImmutableFlag
{

  constexpr static const char* methodName = "SetFilesImmutableFlag";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief This method will set/clear the immutable flag on all explicitly protected files. The list of files is device defined and cannot be changed by any SOPAS method.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool Immutable)
    : _Immutable(Immutable)
  {}

  bool _Immutable;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Success)
    : _Success(Success)
  {}

  bool _Success;
};

}; // struct Post

}; // struct SetFilesImmutableFlag

} // namespace sick::srt::multiScan200
