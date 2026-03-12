/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GenWriteFile.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GenWriteFile.
*/
struct SDK_EXPORT GenWriteFile
{

  constexpr static const char* methodName = "GenWriteFile";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Write selected file.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int FileHandle, std::vector<int> Data, int SequenceNumber)
    : _FileHandle(FileHandle), _Data(Data), _SequenceNumber(SequenceNumber)
  {}

  int _FileHandle;
  std::vector<int> _Data;
  int _SequenceNumber;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int State)
    : _State(State)
  {}

  int _State;
};

}; // struct Post

}; // struct GenWriteFile

} // namespace sick::srt::multiScan200
