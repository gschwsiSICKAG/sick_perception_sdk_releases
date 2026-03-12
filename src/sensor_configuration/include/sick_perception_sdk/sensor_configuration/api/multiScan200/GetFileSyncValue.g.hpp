/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetFileSyncValue.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GetFileSyncValue.
*/
struct SDK_EXPORT GetFileSyncValue
{

  constexpr static const char* methodName = "GetFileSyncValue";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief get Sync Value for file.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string Name)
    : _Name(std::move(Name))
  {}

  std::string _Name;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int HashValue)
    : _HashValue(HashValue)
  {}

  int _HashValue;
};

}; // struct Post

}; // struct GetFileSyncValue

} // namespace sick::srt::multiScan200
