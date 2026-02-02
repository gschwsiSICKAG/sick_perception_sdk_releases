/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file EthernetUpdate.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan100' version '2.4.1'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan100 {

/**
 * @brief Payloads for endpoint /EthernetUpdate.
*/
struct SDK_EXPORT EthernetUpdate
{

  constexpr static const char* methodName = "EthernetUpdate";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Applies the ethernet settings. This needs to be executed to actually change the ethernet settings.

 This function requires at least user level: Authorized Client.
*/
struct SDK_EXPORT Post
{
}; // struct Post

}; // struct EthernetUpdate

} // namespace sick::srt::multiScan100
