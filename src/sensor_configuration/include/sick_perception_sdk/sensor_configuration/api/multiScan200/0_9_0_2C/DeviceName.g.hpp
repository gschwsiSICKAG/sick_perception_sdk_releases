/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DeviceName.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <string>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /DeviceName.
*/
struct DeviceName
{

  constexpr static const char* variableName = "DeviceName";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the device name given by SICK.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::string DeviceName)
        : _DeviceName(std::move(DeviceName))
      {}

      std::string _DeviceName;
    };

  }; // struct Get

}; // struct DeviceName

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
