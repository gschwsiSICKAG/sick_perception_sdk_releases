/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ScanDataFormat.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan150' version '2.2.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::picoScan150::v2_2_1::api::rest {

/**
 * @brief Payloads for endpoint /ScanDataFormat.
*/
struct SDK_EXPORT ScanDataFormat
{

  constexpr static const char* variableName = "ScanDataFormat";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns/sets the scan data format (e.g. Compact format).
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      enum class ScanDataFormat
      {
        Msgpack = 1,
        Compact = 2,
        Lmdscandata = 3,
        Nativeros2 = 4,
      };

      Response() = default;

      explicit Response(ScanDataFormat ScanDataFormat)
        : _ScanDataFormat(ScanDataFormat)
      {}

      ScanDataFormat _ScanDataFormat;
    };

  }; // struct Get

  /**
   * @brief Returns/sets the scan data format (e.g. Compact format).

 This function requires at least user level: Authorized Client.
   */
  struct SDK_EXPORT Post
  {
    struct SDK_EXPORT Request
    {
      enum class ScanDataFormat
      {
        Msgpack = 1,
        Compact = 2,
        Lmdscandata = 3,
        Nativeros2 = 4,
      };

      Request() = default;

      explicit Request(ScanDataFormat ScanDataFormat)
        : _ScanDataFormat(ScanDataFormat)
      {}

      ScanDataFormat _ScanDataFormat;
    };

  }; // struct Post

}; // struct ScanDataFormat

} // namespace sick::picoScan150::v2_2_1::api::rest
