/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file NextMaintenance.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /NextMaintenance.
*/
struct SDK_EXPORT NextMaintenance
{

  constexpr static const char* variableName = "NextMaintenance";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Date of Next maintenance.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string NextMaintenance)
    : _NextMaintenance(std::move(NextMaintenance))
  {}

  std::string _NextMaintenance;
};

}; // struct Get

/**
 * @brief Date of Next maintenance.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string NextMaintenance)
    : _NextMaintenance(std::move(NextMaintenance))
  {}

  std::string _NextMaintenance;
};

}; // struct Post

}; // struct NextMaintenance

} // namespace sick::srt::multiScan200
