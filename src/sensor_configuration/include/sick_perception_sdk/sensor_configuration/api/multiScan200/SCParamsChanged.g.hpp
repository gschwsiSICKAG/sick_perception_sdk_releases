/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SCParamsChanged.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SCParamsChanged.
*/
struct SDK_EXPORT SCParamsChanged
{

  constexpr static const char* variableName = "SCParamsChanged";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Flag is set if parameters may have been changed but are not saved permanently.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool SCParamsChanged)
    : _SCParamsChanged(SCParamsChanged)
  {}

  bool _SCParamsChanged;
};

}; // struct Get

}; // struct SCParamsChanged

} // namespace sick::srt::multiScan200
