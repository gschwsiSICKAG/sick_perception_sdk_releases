/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SerialNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SerialNumber.
*/
struct SDK_EXPORT SerialNumber
{

  constexpr static const char* variableName = "SerialNumber";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief serial number of device.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string SerialNumber)
    : _SerialNumber(std::move(SerialNumber))
  {}

  std::string _SerialNumber;
};

}; // struct Get

/**
 * @brief serial number of device.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string SerialNumber)
    : _SerialNumber(std::move(SerialNumber))
  {}

  std::string _SerialNumber;
};

}; // struct Post

}; // struct SerialNumber

} // namespace sick::srt::multiScan200
