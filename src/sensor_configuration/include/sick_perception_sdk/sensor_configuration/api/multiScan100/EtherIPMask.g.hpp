/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EtherIPMask.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /EtherIPMask.
*/
struct SDK_EXPORT EtherIPMask
{

  constexpr static const char* variableName = "EtherIPMask";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns/sets the subnet mask.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 4> EtherIPMask)
    : _EtherIPMask(EtherIPMask)
  {}

  std::array<int, 4> _EtherIPMask;
};

}; // struct Get

/**
 * @brief Returns/sets the subnet mask.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<int, 4> EtherIPMask)
    : _EtherIPMask(EtherIPMask)
  {}

  std::array<int, 4> _EtherIPMask;
};

}; // struct Post

}; // struct EtherIPMask

} // namespace sick::srt::multiScan100
