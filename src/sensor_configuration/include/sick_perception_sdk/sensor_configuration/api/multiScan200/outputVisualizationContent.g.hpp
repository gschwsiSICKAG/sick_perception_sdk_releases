/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

/**
 * @file outputVisualizationContent.g.hpp Sensor REST API payload definitions.
 * @warning This file was generated for device 'multiScan200' version '0.9.0-c.1+2407.172e2'.
 * Do not edit manually!
 */
#pragma once

#include <sick_perception_sdk/common/export.hpp>

namespace sick::srt::multiScan200 {

/**
 * @brief Payloads for endpoint /outputVisualizationContent.
*/
struct SDK_EXPORT outputVisualizationContent
{

  constexpr static const char* variableName = "outputVisualizationContent";
  constexpr static const bool isSopasMethod = false;

/**
 * @brief Describes which data of streaming application should be visualized.
*/
struct SDK_EXPORT Get
{
struct SDK_EXPORT Response
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

  Response() = default;

  explicit Response(outputVisualizationContent outputVisualizationContent)
    : _outputVisualizationContent(outputVisualizationContent)
  {}

  outputVisualizationContent _outputVisualizationContent;
};

}; // struct Get

}; // struct outputVisualizationContent

} // namespace sick::srt::multiScan200
