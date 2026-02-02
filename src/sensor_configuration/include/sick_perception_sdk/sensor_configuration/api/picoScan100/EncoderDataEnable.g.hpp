/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EncoderDataEnable.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /EncoderDataEnable.
*/
struct SDK_EXPORT EncoderDataEnable
{

  constexpr static const char* variableName = "EncoderDataEnable";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Enables/disables the encoder data streaming. The encoder data itself is sent via a UDP-based SICK-specific format.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool EncoderDataEnable)
    : _EncoderDataEnable(EncoderDataEnable)
  {}

  bool _EncoderDataEnable;
};

}; // struct Get

/**
 * @brief Enables/disables the encoder data streaming. The encoder data itself is sent via a UDP-based SICK-specific format.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool EncoderDataEnable)
    : _EncoderDataEnable(EncoderDataEnable)
  {}

  bool _EncoderDataEnable;
};

}; // struct Post

}; // struct EncoderDataEnable

} // namespace sick::srt::picoScan100
