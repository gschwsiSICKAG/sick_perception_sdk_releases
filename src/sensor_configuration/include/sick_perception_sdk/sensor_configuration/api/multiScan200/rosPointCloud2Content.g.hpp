/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file rosPointCloud2Content.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /rosPointCloud2Content.
*/
struct SDK_EXPORT rosPointCloud2Content
{

  constexpr static const char* variableName = "rosPointCloud2Content";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Set the optional channels of PointCloud2 topics (rt/cloud).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool includeRssi, bool includeProperties, bool includeTimeOffset, bool includeRing)
    : _includeRssi(includeRssi), _includeProperties(includeProperties), _includeTimeOffset(includeTimeOffset), _includeRing(includeRing)
  {}

  bool _includeRssi;
  bool _includeProperties;
  bool _includeTimeOffset;
  bool _includeRing;
};

}; // struct Get

/**
 * @brief Set the optional channels of PointCloud2 topics (rt/cloud).

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool includeRssi, bool includeProperties, bool includeTimeOffset, bool includeRing)
    : _includeRssi(includeRssi), _includeProperties(includeProperties), _includeTimeOffset(includeTimeOffset), _includeRing(includeRing)
  {}

  bool _includeRssi;
  bool _includeProperties;
  bool _includeTimeOffset;
  bool _includeRing;
};

}; // struct Post

}; // struct rosPointCloud2Content

} // namespace sick::srt::multiScan200
