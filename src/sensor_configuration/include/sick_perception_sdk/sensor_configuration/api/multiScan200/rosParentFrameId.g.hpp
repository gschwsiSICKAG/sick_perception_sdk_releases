/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file rosParentFrameId.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /rosParentFrameId.
*/
struct SDK_EXPORT rosParentFrameId
{

  constexpr static const char* variableName = "rosParentFrameId";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief ROS parent frame to use for data output.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string rosParentFrameId)
    : _rosParentFrameId(std::move(rosParentFrameId))
  {}

  std::string _rosParentFrameId;
};

}; // struct Get

/**
 * @brief ROS parent frame to use for data output.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string rosParentFrameId)
    : _rosParentFrameId(std::move(rosParentFrameId))
  {}

  std::string _rosParentFrameId;
};

}; // struct Post

}; // struct rosParentFrameId

} // namespace sick::srt::multiScan200
