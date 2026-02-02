/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file compactSerializationContent.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.6.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /compactSerializationContent.
*/
struct SDK_EXPORT compactSerializationContent
{

  constexpr static const char* variableName = "compactSerializationContent";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the data output mode (e.g. Compact format) or disables scan data transmission.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
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
 * @brief Returns/sets the data output mode (e.g. Compact format) or disables scan data transmission.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
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

} // namespace sick::srt::multiScan200
