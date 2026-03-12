/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file rosNamespace.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /rosNamespace.
*/
struct SDK_EXPORT rosNamespace
{

  constexpr static const char* variableName = "rosNamespace";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Namespace which is prepended to all topics.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string rosNamespace)
    : _rosNamespace(std::move(rosNamespace))
  {}

  std::string _rosNamespace;
};

}; // struct Get

/**
 * @brief Namespace which is prepended to all topics.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string rosNamespace)
    : _rosNamespace(std::move(rosNamespace))
  {}

  std::string _rosNamespace;
};

}; // struct Post

}; // struct rosNamespace

} // namespace sick::srt::multiScan200
