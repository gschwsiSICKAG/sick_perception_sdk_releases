/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file OrderNumber.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0.2C'.
 * Do not edit manually!
 */
#pragma once

#include <string>

namespace sick::multiScan200::v0_9_0_2C::api::rest {

/**
 * @brief Payloads for endpoint /OrderNumber.
*/
struct OrderNumber
{

  constexpr static const char* variableName = "OrderNumber";
  constexpr static const bool isSopasMethod = false;

  /**
   * @brief Returns the order number (SICK part number).
   */
  struct Get
  {
    struct Response
    {
      Response() = default;

      explicit Response(std::string OrderNumber)
        : _OrderNumber(std::move(OrderNumber))
      {}

      std::string _OrderNumber;
    };

  }; // struct Get

}; // struct OrderNumber

} // namespace sick::multiScan200::v0_9_0_2C::api::rest
