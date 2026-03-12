/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceType.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /DeviceType.
*/
struct SDK_EXPORT DeviceType
{

  constexpr static const char* variableName = "DeviceType";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief DeviceType.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string DeviceType)
    : _DeviceType(std::move(DeviceType))
  {}

  std::string _DeviceType;
};

}; // struct Get

/**
 * @brief DeviceType.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string DeviceType)
    : _DeviceType(std::move(DeviceType))
  {}

  std::string _DeviceType;
};

}; // struct Post

}; // struct DeviceType

} // namespace sick::srt::multiScan200
