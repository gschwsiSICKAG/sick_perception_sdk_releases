/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LastUsername.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LastUsername.
*/
struct SDK_EXPORT LastUsername
{

  constexpr static const char* variableName = "LastUsername";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Last user executed store permanent.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string LastUsername)
    : _LastUsername(std::move(LastUsername))
  {}

  std::string _LastUsername;
};

}; // struct Get

/**
 * @brief Last user executed store permanent.

 This function requires at least user level: SICK Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string LastUsername)
    : _LastUsername(std::move(LastUsername))
  {}

  std::string _LastUsername;
};

}; // struct Post

}; // struct LastUsername

} // namespace sick::srt::multiScan200
