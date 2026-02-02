/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OrderNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'picoScan100' version '2.2.0'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::picoScan100 {

/**
 * @brief Payloads for endpoint /OrderNumber.
*/
struct SDK_EXPORT OrderNumber
{

  constexpr static const char* variableName = "OrderNumber";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Returns the order number (SICK part number).
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

}; // struct OrderNumber

} // namespace sick::srt::picoScan100
