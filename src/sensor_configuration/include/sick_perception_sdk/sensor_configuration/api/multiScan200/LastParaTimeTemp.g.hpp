/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LastParaTimeTemp.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LastParaTimeTemp.
*/
struct SDK_EXPORT LastParaTimeTemp
{

  constexpr static const char* variableName = "LastParaTimeTemp";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief is not defined unti the method SetLastUser has been executed.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string LastParaTimeTemp)
    : _LastParaTimeTemp(std::move(LastParaTimeTemp))
  {}

  std::string _LastParaTimeTemp;
};

}; // struct Get

}; // struct LastParaTimeTemp

} // namespace sick::srt::multiScan200
