/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file compactScanDataTelegramType.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /compactScanDataTelegramType.
*/
struct compactScanDataTelegramType
{

  constexpr static const char* variableName = "compactScanDataTelegramType";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Return/sets the compact telegram type for the primary scan data. Telegram type 1 is deprecated and will be removed in future versions.
   */
  struct Get
  {
    struct Response
    {
      enum class compactScanDataTelegramType
      {
        TelegramType1 = 1,
        TelegramType6 = 6,
      };

      Response() = default;

      explicit Response(compactScanDataTelegramType compactScanDataTelegramType)
        : _compactScanDataTelegramType(compactScanDataTelegramType)
      {}

      compactScanDataTelegramType _compactScanDataTelegramType;
    };

  }; // struct Get

  /**
   * @brief Return/sets the compact telegram type for the primary scan data. Telegram type 1 is deprecated and will be removed in future versions.

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      enum class compactScanDataTelegramType
      {
        TelegramType1 = 1,
        TelegramType6 = 6,
      };

      Request() = default;

      explicit Request(compactScanDataTelegramType compactScanDataTelegramType)
        : _compactScanDataTelegramType(compactScanDataTelegramType)
      {}

      compactScanDataTelegramType _compactScanDataTelegramType;
    };

  }; // struct Post

}; // struct compactScanDataTelegramType

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
