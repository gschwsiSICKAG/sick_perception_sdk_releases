/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SetActiveViewer.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SetActiveViewer.
*/
struct SDK_EXPORT SetActiveViewer
{

  constexpr static const char* methodName = "SetActiveViewer";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief set the active viewer.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class ActiveViewer
  {
    Streaming = 0,
    ObjectDetection = 1,
    Disabled = 2,
  };

  Request() = default;

  explicit Request(ActiveViewer ActiveViewer)
    : _ActiveViewer(ActiveViewer)
  {}

  ActiveViewer _ActiveViewer;
};

struct SDK_EXPORT Response
{
  enum class ErrorCode
  {
    SopasErrNoErr = 0,
  };

  Response() = default;

  explicit Response(ErrorCode ErrorCode)
    : _ErrorCode(ErrorCode)
  {}

  ErrorCode _ErrorCode;
};

}; // struct Post

}; // struct SetActiveViewer

} // namespace sick::srt::multiScan200
