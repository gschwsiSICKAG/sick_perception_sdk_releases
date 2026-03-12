/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SubDevicesExt.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SubDevicesExt.
*/
struct SDK_EXPORT SubDevicesExt
{

  constexpr static const char* variableName = "SubDevicesExt";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get SubDevicesExt.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT AddressesItem
  {
    struct SDK_EXPORT xProperties
    {
      enum class eProtocol
      {
        Eprotnotdefined = 0,
        Eprotcolaa = 1,
        Eprotcolab = 2,
        Eprotseriallink = 3,
      };

      xProperties() = default;

      explicit xProperties(bool bVisible, eProtocol eProtocol)
        : _bVisible(bVisible), _eProtocol(eProtocol)
      {}

      bool _bVisible;
      eProtocol _eProtocol;
    };

    AddressesItem() = default;

    explicit AddressesItem(int usiSubAddress, xProperties xProperties)
      : _usiSubAddress(usiSubAddress), _xProperties(xProperties)
    {}

    int _usiSubAddress;
    xProperties _xProperties;
  };

  Response() = default;

  explicit Response(std::vector<AddressesItem> Addresses, std::vector<int> reserved)
    : _Addresses(Addresses), _reserved(reserved)
  {}

  std::vector<AddressesItem> _Addresses;
  std::vector<int> _reserved;
};

}; // struct Get

}; // struct SubDevicesExt

} // namespace sick::srt::multiScan200
