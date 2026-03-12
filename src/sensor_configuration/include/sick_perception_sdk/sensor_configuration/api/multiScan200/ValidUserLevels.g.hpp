/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ValidUserLevels.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ValidUserLevels.
*/
struct SDK_EXPORT ValidUserLevels
{

  constexpr static const char* variableName = "ValidUserLevels";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Enable state of all userlevels. Used for persistent storage, does not react on changes.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<bool, 8> ValidUserLevels)
    : _ValidUserLevels(ValidUserLevels)
  {}

  std::array<bool, 8> _ValidUserLevels;
};

}; // struct Get

/**
 * @brief Enable state of all userlevels. Used for persistent storage, does not react on changes.

 This function requires at least user level: Developer.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<bool, 8> ValidUserLevels)
    : _ValidUserLevels(ValidUserLevels)
  {}

  std::array<bool, 8> _ValidUserLevels;
};

}; // struct Post

}; // struct ValidUserLevels

} // namespace sick::srt::multiScan200
