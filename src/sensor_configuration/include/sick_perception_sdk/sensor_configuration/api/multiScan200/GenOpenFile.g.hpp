/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GenOpenFile.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /GenOpenFile.
*/
struct SDK_EXPORT GenOpenFile
{

  constexpr static const char* methodName = "GenOpenFile";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Open selected file.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string Name, std::string Mode)
    : _Name(std::move(Name)), _Mode(std::move(Mode))
  {}

  std::string _Name;
  std::string _Mode;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int State, int FileHandle)
    : _State(State), _FileHandle(FileHandle)
  {}

  int _State;
  int _FileHandle;
};

}; // struct Post

}; // struct GenOpenFile

} // namespace sick::srt::multiScan200
