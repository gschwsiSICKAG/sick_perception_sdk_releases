/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LocationName.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /LocationName.
*/
struct SDK_EXPORT LocationName
{

  constexpr static const char* variableName = "LocationName";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the device name.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::string LocationName)
        : _LocationName(std::move(LocationName))
      {}

      std::string _LocationName;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the device name.

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      Request() = default;

      explicit Request(std::string LocationName)
        : _LocationName(std::move(LocationName))
      {}

      std::string _LocationName;
    };

  }; // struct Post

}; // struct LocationName

} // namespace sick::multiScan100::v2_4_1::api::rest
