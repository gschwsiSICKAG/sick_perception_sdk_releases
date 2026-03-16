/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file compactTelegramType6Content.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /compactTelegramType6Content.
*/
struct SDK_EXPORT compactTelegramType6Content
{

  constexpr static const char* variableName = "compactTelegramType6Content";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Return/sets the optional channels in the compact telegram type 6.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(bool includeRssi, bool includeProperties, bool includeAmbientLight, bool reserved)
        : _includeRssi(includeRssi), _includeProperties(includeProperties), _includeAmbientLight(includeAmbientLight), _reserved(reserved)
      {}

      bool _includeRssi;
      bool _includeProperties;
      bool _includeAmbientLight;
      bool _reserved;
    };

  }; // struct Get

  /**
   * @brief Return/sets the optional channels in the compact telegram type 6.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(bool includeRssi, bool includeProperties, bool includeAmbientLight, bool reserved)
        : _includeRssi(includeRssi), _includeProperties(includeProperties), _includeAmbientLight(includeAmbientLight), _reserved(reserved)
      {}

      bool _includeRssi;
      bool _includeProperties;
      bool _includeAmbientLight;
      bool _reserved;
    };

  }; // struct Post

}; // struct compactTelegramType6Content

} // namespace sick::multiScan200::v0_9_0::api::rest
