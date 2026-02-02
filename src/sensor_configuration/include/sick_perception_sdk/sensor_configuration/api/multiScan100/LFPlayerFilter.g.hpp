/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LFPlayerFilter.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /LFPlayerFilter.
*/
struct SDK_EXPORT LFPlayerFilter
{

  constexpr static const char* variableName = "LFPlayerFilter";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Filter complete layers in the output data.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool bEnable, std::vector<bool> aLayers)
    : _bEnable(bEnable), _aLayers(aLayers)
  {}

  bool _bEnable;
  std::vector<bool> _aLayers;
};

}; // struct Get

/**
 * @brief Filter complete layers in the output data.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool bEnable, std::vector<bool> aLayers)
    : _bEnable(bEnable), _aLayers(aLayers)
  {}

  bool _bEnable;
  std::vector<bool> _aLayers;
};

}; // struct Post

}; // struct LFPlayerFilter

} // namespace sick::srt::multiScan100
