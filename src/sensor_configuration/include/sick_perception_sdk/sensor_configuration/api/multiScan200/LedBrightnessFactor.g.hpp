/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file LedBrightnessFactor.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /LedBrightnessFactor.
*/
struct SDK_EXPORT LedBrightnessFactor
{

  constexpr static const char* variableName = "LedBrightnessFactor";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Get LedBrightnessFactor.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
{
  Response() = default;

  explicit Response(float Red, float Green, float Blue)
    : _Red(Red), _Green(Green), _Blue(Blue)
  {}

  float _Red;
  float _Green;
  float _Blue;
};

}; // struct Get

/**
 * @brief Post LedBrightnessFactor.

 This function requires at least user level: Production.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  Request() = default;

  explicit Request(float Red, float Green, float Blue)
    : _Red(Red), _Green(Green), _Blue(Blue)
  {}

  float _Red;
  float _Green;
  float _Blue;
};

}; // struct Post

}; // struct LedBrightnessFactor

} // namespace sick::srt::multiScan200
