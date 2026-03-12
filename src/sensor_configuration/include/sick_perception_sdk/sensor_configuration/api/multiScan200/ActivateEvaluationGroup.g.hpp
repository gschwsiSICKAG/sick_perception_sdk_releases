/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ActivateEvaluationGroup.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /ActivateEvaluationGroup.
*/
struct SDK_EXPORT ActivateEvaluationGroup
{

  constexpr static const char* methodName = "ActivateEvaluationGroup";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief (De)activate an evaluation group.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  struct SDK_EXPORT ListItem
  {
    ListItem() = default;

    explicit ListItem(NumericRange<1, 48, 1> GroupId, bool Activate)
      : _GroupId(std::move(GroupId)), _Activate(Activate)
    {}

    NumericRange<1, 48, 1> _GroupId;
    bool _Activate;
  };

  Request() = default;

  explicit Request(std::vector<ListItem> List)
    : _List(List)
  {}

  std::vector<ListItem> _List;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(std::vector<bool> Success)
    : _Success(Success)
  {}

  std::vector<bool> _Success;
};

}; // struct Post

}; // struct ActivateEvaluationGroup

} // namespace sick::srt::multiScan200
