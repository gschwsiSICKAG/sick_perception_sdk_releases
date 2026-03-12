/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LastParaDate.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LastParaDate.
*/
struct SDK_EXPORT LastParaDate
{

  constexpr static const char* variableName = "LastParaDate";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Last date when store permanent was executed.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string LastParaDate)
    : _LastParaDate(std::move(LastParaDate))
  {}

  std::string _LastParaDate;
};

}; // struct Get

/**
 * @brief Last date when store permanent was executed.

 This function requires at least user level: SICK Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string LastParaDate)
    : _LastParaDate(std::move(LastParaDate))
  {}

  std::string _LastParaDate;
};

}; // struct Post

}; // struct LastParaDate

} // namespace sick::srt::multiScan200
