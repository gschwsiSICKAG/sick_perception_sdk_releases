/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file bIsObjectDetectionInstalled.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /bIsObjectDetectionInstalled.
*/
struct SDK_EXPORT bIsObjectDetectionInstalled
{

  constexpr static const char* variableName = "bIsObjectDetectionInstalled";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get bIsObjectDetectionInstalled.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool bIsObjectDetectionInstalled)
    : _bIsObjectDetectionInstalled(bIsObjectDetectionInstalled)
  {}

  bool _bIsObjectDetectionInstalled;
};

}; // struct Get

/**
 * @brief Post bIsObjectDetectionInstalled.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool bIsObjectDetectionInstalled)
    : _bIsObjectDetectionInstalled(bIsObjectDetectionInstalled)
  {}

  bool _bIsObjectDetectionInstalled;
};

}; // struct Post

}; // struct bIsObjectDetectionInstalled

} // namespace sick::srt::multiScan200
