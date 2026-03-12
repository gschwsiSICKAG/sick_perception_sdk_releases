/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file Manufacturer.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /Manufacturer.
*/
struct SDK_EXPORT Manufacturer
{

  constexpr static const char* variableName = "Manufacturer";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Manufacturer.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string Manufacturer)
    : _Manufacturer(std::move(Manufacturer))
  {}

  std::string _Manufacturer;
};

}; // struct Get

/**
 * @brief Manufacturer.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string Manufacturer)
    : _Manufacturer(std::move(Manufacturer))
  {}

  std::string _Manufacturer;
};

}; // struct Post

}; // struct Manufacturer

} // namespace sick::srt::multiScan200
