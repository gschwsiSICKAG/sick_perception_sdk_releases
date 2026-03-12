/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SwitchChangeDefaultPasswordDialogState.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SwitchChangeDefaultPasswordDialogState.
*/
struct SDK_EXPORT SwitchChangeDefaultPasswordDialogState
{

  constexpr static const char* methodName = "SwitchChangeDefaultPasswordDialogState";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Post SwitchChangeDefaultPasswordDialogState.

 This function requires at least user level: Maintenance.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(std::string userLevel, bool enableChangePasswordDialog)
    : _userLevel(std::move(userLevel)), _enableChangePasswordDialog(enableChangePasswordDialog)
  {}

  std::string _userLevel;
  bool _enableChangePasswordDialog;
};

struct SDK_EXPORT Response
{
  enum class result
  {
    ChangePwDialogStateChanged = 0,
    IllegalStateChangeRequested = 1,
    StorageOfNewStateFailed = 2,
    AccessDenied = 3,
  };

  Response() = default;

  explicit Response(result result)
    : _result(result)
  {}

  result _result;
};

}; // struct Post

}; // struct SwitchChangeDefaultPasswordDialogState

} // namespace sick::srt::multiScan200
