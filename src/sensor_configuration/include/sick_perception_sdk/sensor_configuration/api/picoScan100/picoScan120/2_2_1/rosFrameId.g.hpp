/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file rosFrameId.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan120' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::picoScan120::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /rosFrameId.
*/
struct SDK_EXPORT rosFrameId
{

  constexpr static const char* variableName = "rosFrameId";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the frame ID of the published topics.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::string rosFrameId)
        : _rosFrameId(std::move(rosFrameId))
      {}

      std::string _rosFrameId;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the frame ID of the published topics.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(std::string rosFrameId)
        : _rosFrameId(std::move(rosFrameId))
      {}

      std::string _rosFrameId;
    };

  }; // struct Post

}; // struct rosFrameId

} // namespace sick::picoScan120::v2_2_1::api::rest
