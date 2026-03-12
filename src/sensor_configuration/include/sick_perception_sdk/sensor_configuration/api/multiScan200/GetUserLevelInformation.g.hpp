/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file GetUserLevelInformation.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /GetUserLevelInformation.
*/
struct SDK_EXPORT GetUserLevelInformation
{

  constexpr static const char* methodName = "GetUserLevelInformation";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post GetUserLevelInformation.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT userLevelsItem
  {
    userLevelsItem() = default;

    explicit userLevelsItem(bool isDefeatable, bool isEnabled)
      : _isDefeatable(isDefeatable), _isEnabled(isEnabled)
    {}

    bool _isDefeatable;
    bool _isEnabled;
  };

  Response() = default;

  explicit Response(std::vector<userLevelsItem> userLevels)
    : _userLevels(userLevels)
  {}

  std::vector<userLevelsItem> _userLevels;
};

}; // struct Post

}; // struct GetUserLevelInformation

} // namespace sick::srt::multiScan200
