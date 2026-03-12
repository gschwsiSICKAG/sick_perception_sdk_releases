/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OrderNumberCompat.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /OrderNumberCompat.
*/
struct SDK_EXPORT OrderNumberCompat
{

  constexpr static const char* variableName = "OrderNumberCompat";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Order number.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string OrderNumberCompat)
    : _OrderNumberCompat(std::move(OrderNumberCompat))
  {}

  std::string _OrderNumberCompat;
};

}; // struct Get

/**
 * @brief Order number.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string OrderNumberCompat)
    : _OrderNumberCompat(std::move(OrderNumberCompat))
  {}

  std::string _OrderNumberCompat;
};

}; // struct Post

}; // struct OrderNumberCompat

} // namespace sick::srt::multiScan200
