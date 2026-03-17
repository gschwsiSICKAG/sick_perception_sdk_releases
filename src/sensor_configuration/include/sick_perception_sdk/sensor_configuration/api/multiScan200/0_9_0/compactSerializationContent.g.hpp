/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file compactSerializationContent.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0'.
 * Do not edit manually!
 */
#pragma once


namespace sick::multiScan200::v0_9_0::api::rest {

/**
 * @brief Payloads for endpoint /compactSerializationContent.
*/
struct compactSerializationContent
{

  constexpr static const char* variableName = "compactSerializationContent";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Return/sets the optional channels in the compact telegram type 1 (deprecated).
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(bool serializeRssis, bool serializeProperties)
        : _serializeRssis(serializeRssis), _serializeProperties(serializeProperties)
      {}

      bool _serializeRssis;
      bool _serializeProperties;
    };

  }; // struct Get

  /**
   * @brief Return/sets the optional channels in the compact telegram type 1 (deprecated).

 This function requires at least user level: Authorized Client.
   */
  struct Post
  {
    struct Request
    {
      Request() = default;

      explicit Request(bool serializeRssis, bool serializeProperties)
        : _serializeRssis(serializeRssis), _serializeProperties(serializeProperties)
      {}

      bool _serializeRssis;
      bool _serializeProperties;
    };

  }; // struct Post

}; // struct compactSerializationContent

} // namespace sick::multiScan200::v0_9_0::api::rest
