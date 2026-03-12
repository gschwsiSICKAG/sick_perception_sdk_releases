/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetFileSize.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GetFileSize.
*/
struct SDK_EXPORT GetFileSize
{

  constexpr static const char* methodName = "GetFileSize";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief get file size.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int FileHandle)
    : _FileHandle(FileHandle)
  {}

  int _FileHandle;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int State, int FileSize)
    : _State(State), _FileSize(FileSize)
  {}

  int _State;
  int _FileSize;
};

}; // struct Post

}; // struct GetFileSize

} // namespace sick::srt::multiScan200
