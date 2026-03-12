/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetDiagnosisDumpPath.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /GetDiagnosisDumpPath.
*/
struct SDK_EXPORT GetDiagnosisDumpPath
{

  constexpr static const char* methodName = "GetDiagnosisDumpPath";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Returns the path, where the DiagnosisDump is stored.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string DiagDumpPath)
    : _DiagDumpPath(std::move(DiagDumpPath))
  {}

  std::string _DiagDumpPath;
};

}; // struct Post

}; // struct GetDiagnosisDumpPath

} // namespace sick::srt::multiScan200
