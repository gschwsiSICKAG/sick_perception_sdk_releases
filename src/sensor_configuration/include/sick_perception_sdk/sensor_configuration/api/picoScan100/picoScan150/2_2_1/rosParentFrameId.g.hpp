/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file rosParentFrameId.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /rosParentFrameId.
*/
struct SDK_EXPORT rosParentFrameId
{

  constexpr static const char* variableName = "rosParentFrameId";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the parent frame ID of the published topics.
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
   * @brief Returns/sets the parent frame ID of the published topics.

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

} // namespace sick::picoScan150::v2_2_1::api::rest
