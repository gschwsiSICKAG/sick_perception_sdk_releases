/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file rosEndianness.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /rosEndianness.
*/
struct SDK_EXPORT rosEndianness
{

  constexpr static const char* variableName = "rosEndianness";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Endianness of the data output.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class rosEndianness
  {
    Littleendian = 1,
    Bigendian = 2,
  };

  Response() = default;

  explicit Response(rosEndianness rosEndianness)
    : _rosEndianness(rosEndianness)
  {}

  rosEndianness _rosEndianness;
};

}; // struct Get

/**
 * @brief Endianness of the data output.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class rosEndianness
  {
    Littleendian = 1,
    Bigendian = 2,
  };

  Request() = default;

  explicit Request(rosEndianness rosEndianness)
    : _rosEndianness(rosEndianness)
  {}

  rosEndianness _rosEndianness;
};

}; // struct Post

}; // struct rosEndianness

} // namespace sick::srt::multiScan200
