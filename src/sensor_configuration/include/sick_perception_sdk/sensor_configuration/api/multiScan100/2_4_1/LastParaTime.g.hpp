/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LastParaTime.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::multiScan100::v2_4_1::api::rest {

/**
 * @brief Payloads for endpoint /LastParaTime.
*/
struct SDK_EXPORT LastParaTime
{

  constexpr static const char* variableName = "LastParaTime";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the last time (e.g. 13:24) when a permanent parameter save was executed.
   */
  struct SDK_EXPORT Get
  {
    struct SDK_EXPORT Response
    {
      Response() = default;

      explicit Response(std::string LastParaTime)
        : _LastParaTime(std::move(LastParaTime))
      {}

      std::string _LastParaTime;
    };

  }; // struct Get

}; // struct LastParaTime

} // namespace sick::multiScan100::v2_4_1::api::rest
