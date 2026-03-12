/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file TypeCode.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /TypeCode.
*/
struct SDK_EXPORT TypeCode
{

  constexpr static const char* variableName = "TypeCode";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief This variable's value matches the SICK type code as it is used in SAP (first 18 characters).
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string TypeCode)
    : _TypeCode(std::move(TypeCode))
  {}

  std::string _TypeCode;
};

}; // struct Get

/**
 * @brief This variable's value matches the SICK type code as it is used in SAP (first 18 characters).

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string TypeCode)
    : _TypeCode(std::move(TypeCode))
  {}

  std::string _TypeCode;
};

}; // struct Post

}; // struct TypeCode

} // namespace sick::srt::multiScan200
