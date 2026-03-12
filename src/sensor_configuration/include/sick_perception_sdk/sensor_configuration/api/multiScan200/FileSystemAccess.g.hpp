/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FileSystemAccess.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /FileSystemAccess.
*/
struct SDK_EXPORT FileSystemAccess
{

  constexpr static const char* methodName = "FileSystemAccess";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief EDP2 File system accessor.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string URL, std::string Buffer, int BufferCRC)
    : _URL(std::move(URL)), _Buffer(std::move(Buffer)), _BufferCRC(BufferCRC)
  {}

  std::string _URL;
  std::string _Buffer;
  int _BufferCRC;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string URL, std::string Buffer, int BufferCRC)
    : _URL(std::move(URL)), _Buffer(std::move(Buffer)), _BufferCRC(BufferCRC)
  {}

  std::string _URL;
  std::string _Buffer;
  int _BufferCRC;
};

}; // struct Post

}; // struct FileSystemAccess

} // namespace sick::srt::multiScan200
