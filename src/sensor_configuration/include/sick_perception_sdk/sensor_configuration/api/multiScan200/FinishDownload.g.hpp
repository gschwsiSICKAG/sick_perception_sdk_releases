/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file FinishDownload.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /FinishDownload.
*/
struct SDK_EXPORT FinishDownload
{

  constexpr static const char* methodName = "FinishDownload";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Finishes the download process.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int Handle, int Device)
    : _Handle(Handle), _Device(Device)
  {}

  int _Handle;
  int _Device;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int Result)
    : _Result(Result)
  {}

  int _Result;
};

}; // struct Post

}; // struct FinishDownload

} // namespace sick::srt::multiScan200
