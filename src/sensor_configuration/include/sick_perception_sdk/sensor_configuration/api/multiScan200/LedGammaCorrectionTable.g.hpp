/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LedGammaCorrectionTable.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LedGammaCorrectionTable.
*/
struct SDK_EXPORT LedGammaCorrectionTable
{

  constexpr static const char* variableName = "LedGammaCorrectionTable";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get LedGammaCorrectionTable.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::array<int, 256> LedGammaCorrectionTable)
    : _LedGammaCorrectionTable(LedGammaCorrectionTable)
  {}

  std::array<int, 256> _LedGammaCorrectionTable;
};

}; // struct Get

/**
 * @brief Post LedGammaCorrectionTable.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::array<int, 256> LedGammaCorrectionTable)
    : _LedGammaCorrectionTable(LedGammaCorrectionTable)
  {}

  std::array<int, 256> _LedGammaCorrectionTable;
};

}; // struct Post

}; // struct LedGammaCorrectionTable

} // namespace sick::srt::multiScan200
