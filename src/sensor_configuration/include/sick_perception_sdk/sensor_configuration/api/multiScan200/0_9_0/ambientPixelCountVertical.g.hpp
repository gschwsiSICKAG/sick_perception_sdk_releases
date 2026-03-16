/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ambientPixelCountVertical.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /ambientPixelCountVertical.
*/
struct SDK_EXPORT ambientPixelCountVertical
{

  constexpr static const char* variableName = "ambientPixelCountVertical";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the vertical ambient pixel count.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      enum class ambientPixelCountVertical
      {
        Full = 0,
        Matching = 1,
      };

      Response() = default;

      explicit Response(ambientPixelCountVertical ambientPixelCountVertical)
        : _ambientPixelCountVertical(ambientPixelCountVertical)
      {}

      ambientPixelCountVertical _ambientPixelCountVertical;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the vertical ambient pixel count.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      enum class ambientPixelCountVertical
      {
        Full = 0,
        Matching = 1,
      };

      Request() = default;

      explicit Request(ambientPixelCountVertical ambientPixelCountVertical)
        : _ambientPixelCountVertical(ambientPixelCountVertical)
      {}

      ambientPixelCountVertical _ambientPixelCountVertical;
    };

  }; // struct Post

}; // struct ambientPixelCountVertical

} // namespace sick::multiScan200::v0_9_0::api::rest
