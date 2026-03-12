/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file SourceList.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /SourceList.
*/
struct SDK_EXPORT SourceList
{

  constexpr static const char* variableName = "SourceList";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief List of all available sources for IO port configuration.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  struct SDK_EXPORT SourceListItem
  {
    SourceListItem() = default;

    explicit SourceListItem(std::string Id, std::string Label, bool State, bool DefaultState)
      : _Id(std::move(Id)), _Label(std::move(Label)), _State(State), _DefaultState(DefaultState)
    {}

    std::string _Id;
    std::string _Label;
    bool _State;
    bool _DefaultState;
  };

  Response() = default;

  explicit Response(std::vector<SourceListItem> SourceList)
    : _SourceList(SourceList)
  {}

  std::vector<SourceListItem> _SourceList;
};

}; // struct Get

}; // struct SourceList

} // namespace sick::srt::multiScan200
