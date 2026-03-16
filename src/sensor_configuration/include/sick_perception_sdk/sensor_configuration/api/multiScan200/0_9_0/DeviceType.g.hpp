/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceType.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /DeviceType.
*/
struct SDK_EXPORT DeviceType
{

  constexpr static const char* variableName = "DeviceType";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the device type.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::string DeviceType)
        : _DeviceType(std::move(DeviceType))
      {}

      std::string _DeviceType;
    };

  }; // struct Get

}; // struct DeviceType

} // namespace sick::multiScan200::v0_9_0::api::rest
