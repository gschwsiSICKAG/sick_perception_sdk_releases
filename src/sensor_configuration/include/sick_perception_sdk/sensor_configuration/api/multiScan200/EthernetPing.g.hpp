/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EthernetPing.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /EthernetPing.
*/
struct SDK_EXPORT EthernetPing
{

  constexpr static const char* methodName = "EthernetPing";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief tests the ethernet connection.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  enum class InterfaceNumber
  {
    TxEth1 = 0,
    TxEth2 = 1,
    TxEth3 = 2,
    TxEth4 = 3,
    TxEth5 = 4,
    TxEth6 = 5,
    TxEth7 = 6,
    TxEth8 = 7,
  };

  Request() = default;

  explicit Request(std::array<int, 4> IPAddress, int Timeout, InterfaceNumber InterfaceNumber)
    : _IPAddress(IPAddress), _Timeout(Timeout), _InterfaceNumber(InterfaceNumber)
  {}

  std::array<int, 4> _IPAddress;
  int _Timeout;
  InterfaceNumber _InterfaceNumber;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Success)
    : _Success(Success)
  {}

  bool _Success;
};

}; // struct Post

}; // struct EthernetPing

} // namespace sick::srt::multiScan200
