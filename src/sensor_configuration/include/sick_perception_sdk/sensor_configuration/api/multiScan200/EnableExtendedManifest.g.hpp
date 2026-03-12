/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EnableExtendedManifest.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EnableExtendedManifest.
*/
struct SDK_EXPORT EnableExtendedManifest
{

  constexpr static const char* variableName = "EnableExtendedManifest";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Enables manifest with developer and production crowns - needs reboot to be become active.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool EnableExtendedManifest)
    : _EnableExtendedManifest(EnableExtendedManifest)
  {}

  bool _EnableExtendedManifest;
};

}; // struct Get

/**
 * @brief Enables manifest with developer and production crowns - needs reboot to be become active.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool EnableExtendedManifest)
    : _EnableExtendedManifest(EnableExtendedManifest)
  {}

  bool _EnableExtendedManifest;
};

}; // struct Post

}; // struct EnableExtendedManifest

} // namespace sick::srt::multiScan200
