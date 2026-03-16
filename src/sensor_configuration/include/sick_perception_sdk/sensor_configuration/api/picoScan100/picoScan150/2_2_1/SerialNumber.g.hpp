/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SerialNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /SerialNumber.
*/
struct SDK_EXPORT SerialNumber
{

  constexpr static const char* variableName = "SerialNumber";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the serial number.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::string SerialNumber)
        : _SerialNumber(std::move(SerialNumber))
      {}

      std::string _SerialNumber;
    };

  }; // struct Get

}; // struct SerialNumber

} // namespace sick::picoScan150::v2_2_1::api::rest
