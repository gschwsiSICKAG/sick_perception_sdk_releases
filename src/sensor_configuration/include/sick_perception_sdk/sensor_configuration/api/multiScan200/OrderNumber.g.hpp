/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OrderNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /OrderNumber.
*/
struct SDK_EXPORT OrderNumber
{

  constexpr static const char* variableName = "OrderNumber";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief This variable's value matches the SICK order number (million number) in SAP.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::string OrderNumber)
    : _OrderNumber(std::move(OrderNumber))
  {}

  std::string _OrderNumber;
};

}; // struct Get

/**
 * @brief This variable's value matches the SICK order number (million number) in SAP.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string OrderNumber)
    : _OrderNumber(std::move(OrderNumber))
  {}

  std::string _OrderNumber;
};

}; // struct Post

}; // struct OrderNumber

} // namespace sick::srt::multiScan200
