/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file StatusDownload.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /StatusDownload.
*/
struct SDK_EXPORT StatusDownload
{

  constexpr static const char* methodName = "StatusDownload";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Method informs the progress of the download process.

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

  explicit Response(int Status)
    : _Status(Status)
  {}

  int _Status;
};

}; // struct Post

}; // struct StatusDownload

} // namespace sick::srt::multiScan200
