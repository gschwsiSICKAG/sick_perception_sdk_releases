/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LastParaDateTemp.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LastParaDateTemp.
*/
struct SDK_EXPORT LastParaDateTemp
{

  constexpr static const char* variableName = "LastParaDateTemp";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief is not defined unti the method SetLastUser has been executed.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string LastParaDateTemp)
    : _LastParaDateTemp(std::move(LastParaDateTemp))
  {}

  std::string _LastParaDateTemp;
};

}; // struct Get

}; // struct LastParaDateTemp

} // namespace sick::srt::multiScan200
