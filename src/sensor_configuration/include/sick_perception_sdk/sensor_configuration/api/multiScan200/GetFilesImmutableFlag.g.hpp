/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetFilesImmutableFlag.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GetFilesImmutableFlag.
*/
struct SDK_EXPORT GetFilesImmutableFlag
{

  constexpr static const char* methodName = "GetFilesImmutableFlag";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Get the state if all relevant files are immutable.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Immutable)
    : _Immutable(Immutable)
  {}

  bool _Immutable;
};

}; // struct Post

}; // struct GetFilesImmutableFlag

} // namespace sick::srt::multiScan200
