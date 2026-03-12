/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LocationName.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LocationName.
*/
struct SDK_EXPORT LocationName
{

  constexpr static const char* variableName = "LocationName";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Location of Device (set by user).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string LocationName)
    : _LocationName(std::move(LocationName))
  {}

  std::string _LocationName;
};

}; // struct Get

/**
 * @brief Location of Device (set by user).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string LocationName)
    : _LocationName(std::move(LocationName))
  {}

  std::string _LocationName;
};

}; // struct Post

}; // struct LocationName

} // namespace sick::srt::multiScan200
