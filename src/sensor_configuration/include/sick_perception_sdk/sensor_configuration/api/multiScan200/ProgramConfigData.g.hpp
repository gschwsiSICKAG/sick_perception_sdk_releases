/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file ProgramConfigData.g.hpp Sensor REST API payload definitions.
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
 * @brief Payloads for endpoint /ProgramConfigData.
*/
struct SDK_EXPORT ProgramConfigData
{

  constexpr static const char* methodName = "ProgramConfigData";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Method transfers the relevant data of the program header.

 This function requires at least user level: Service.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(int Handle, int Device, std::string Identifier, std::string Data)
    : _Handle(Handle), _Device(Device), _Identifier(std::move(Identifier)), _Data(std::move(Data))
  {}

  int _Handle;
  int _Device;
  std::string _Identifier;
  std::string _Data;
};

struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(int Result)
    : _Result(Result)
  {}

  int _Result;
};

}; // struct Post

}; // struct ProgramConfigData

} // namespace sick::srt::multiScan200
