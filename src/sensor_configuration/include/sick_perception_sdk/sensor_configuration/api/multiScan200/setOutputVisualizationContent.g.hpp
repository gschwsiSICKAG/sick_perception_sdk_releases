/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file setOutputVisualizationContent.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 *
 * @note This class represents the payload of a SOPAS method. Do not use in `write_variable()`!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /setOutputVisualizationContent.
*/
struct SDK_EXPORT setOutputVisualizationContent
{

  constexpr static const char* methodName = "setOutputVisualizationContent";
  constexpr static const bool isSopasMethod = true;

/**
 * @brief Set the visualization content for the streaming application.
*/
struct SDK_EXPORT Post
{
struct SDK_EXPORT Request
{
  struct SDK_EXPORT outputVisualizationContent
  {
    outputVisualizationContent() = default;

    explicit outputVisualizationContent(bool visualizeRssi, bool visualizeProperties, bool visualizeAmbientLight)
      : _visualizeRssi(visualizeRssi), _visualizeProperties(visualizeProperties), _visualizeAmbientLight(visualizeAmbientLight)
    {}

    bool _visualizeRssi;
    bool _visualizeProperties;
    bool _visualizeAmbientLight;
  };

  Request() = default;

  explicit Request(outputVisualizationContent outputVisualizationContent)
    : _outputVisualizationContent(outputVisualizationContent)
  {}

  outputVisualizationContent _outputVisualizationContent;
};

struct SDK_EXPORT Response
{
  enum class ErrorCode
  {
    SopasErrNoErr = 0,
  };

  Response() = default;

  explicit Response(ErrorCode ErrorCode)
    : _ErrorCode(ErrorCode)
  {}

  ErrorCode _ErrorCode;
};

}; // struct Post

}; // struct setOutputVisualizationContent

} // namespace sick::srt::multiScan200
