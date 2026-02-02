/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file DoDiagnosisDump.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'LRS4000' version '1.9.0.0R'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <string>

namespace sick::srt::LRS4000 {

/**
 * @brief Payloads for endpoint /DoDiagnosisDump.
*/
struct SDK_EXPORT DoDiagnosisDump
{

  constexpr static const char* methodName = "DoDiagnosisDump";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Creates a diagnostic file (zip file) for further analysis.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(bool DoRunlevelLoop, std::string Output)
    : _DoRunlevelLoop(DoRunlevelLoop), _Output(std::move(Output))
  {}

  bool _DoRunlevelLoop;
  std::string _Output;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(bool Successfull)
    : _Successfull(Successfull)
  {}

  bool _Successfull;
};

}; // struct Post

}; // struct DoDiagnosisDump

} // namespace sick::srt::LRS4000
