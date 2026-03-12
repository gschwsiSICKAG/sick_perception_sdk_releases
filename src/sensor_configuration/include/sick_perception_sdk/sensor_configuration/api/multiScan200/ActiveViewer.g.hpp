/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ActiveViewer.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ActiveViewer.
*/
struct SDK_EXPORT ActiveViewer
{

  constexpr static const char* variableName = "ActiveViewer";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Describes which is the currently active viewer in the UI where data should be sent to.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  enum class ActiveViewer
  {
    Streaming = 0,
    ObjectDetection = 1,
    Disabled = 2,
  };

  Response() = default;

  explicit Response(ActiveViewer ActiveViewer)
    : _ActiveViewer(ActiveViewer)
  {}

  ActiveViewer _ActiveViewer;
};

}; // struct Get

}; // struct ActiveViewer

} // namespace sick::srt::multiScan200
