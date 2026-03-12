/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file httpsStatus.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /httpsStatus.
*/
struct SDK_EXPORT httpsStatus
{

  constexpr static const char* variableName = "httpsStatus";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get httpsStatus.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT errorCode
  {
    errorCode() = default;

    explicit errorCode(std::string error)
      : _error(std::move(error))
    {}

    std::string _error;
  };

  Response() = default;

  explicit Response(bool enabled, errorCode errorCode)
    : _enabled(enabled), _errorCode(errorCode)
  {}

  bool _enabled;
  errorCode _errorCode;
};

}; // struct Get

}; // struct httpsStatus

} // namespace sick::srt::multiScan200
