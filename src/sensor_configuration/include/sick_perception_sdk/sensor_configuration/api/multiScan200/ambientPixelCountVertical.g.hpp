/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ambientPixelCountVertical.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ambientPixelCountVertical.
*/
struct SDK_EXPORT ambientPixelCountVertical
{

  constexpr static const char* variableName = "ambientPixelCountVertical";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Vertical resolution of the ambient light image. FULL: Maximal number of vertical pixels. MATCHING: numberOfPixel.
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
 * @brief Vertical resolution of the ambient light image. FULL: Maximal number of vertical pixels. MATCHING: numberOfPixel.

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

} // namespace sick::srt::multiScan200
