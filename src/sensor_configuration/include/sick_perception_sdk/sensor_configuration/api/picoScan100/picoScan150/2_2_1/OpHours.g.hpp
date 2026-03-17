/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OpHours.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once


namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /OpHours.
*/
struct OpHours
{

  constexpr static const char* variableName = "OpHours";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the total number of operating hours during the lifetime of the device. The resolution is a 1/10 hour.
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(int OpHours)
        : _OpHours(OpHours)
      {}

      int _OpHours;
    };

  }; // struct Get

}; // struct OpHours

} // namespace sick::picoScan150::v2_2_1::api::rest
