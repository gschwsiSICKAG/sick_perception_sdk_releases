/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file compactSerializationContent.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
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
 * @brief Defines which data channels are serialized in the compact tcp output.
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
 * @brief Defines which data channels are serialized in the compact tcp output.

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
