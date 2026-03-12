/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>

#include <string>

namespace sick {

auto PointCloudConfiguration::Fields::toString() const -> std::string
{
  std::string result;
  result += "  enableCartesian: " + std::string(enableCartesian ? "true" : "false") + "\n";
  result += "  enableSpherical: " + std::string(enableSpherical ? "true" : "false") + "\n";
  result += "  enableIntensity: " + std::string(enableIntensity ? "true" : "false") + "\n";
  result += "  enableTimeOffset: " + std::string(enableTimeOffset ? "true" : "false") + "\n";
  result += "  enableRing: " + std::string(enableRing ? "true" : "false") + "\n";
  result += "  enableLayer: " + std::string(enableLayer ? "true" : "false") + "\n";
  result += "  enableEcho: " + std::string(enableEcho ? "true" : "false") + "\n";
  result += "  enableIsReflector: " + std::string(enableIsReflector ? "true" : "false") + "\n";
  result += "  enableHasBlooming: " + std::string(enableHasBlooming ? "true" : "false") + "\n";
  return result;
}

auto PointCloudConfiguration::Filters::toString() const -> std::string
{
  std::string result;
  result += "  selectedEchos: ";
  if (selectedEchos)
  {
    result += "{";
    for (auto const& echo : *selectedEchos)
    {
      result += std::to_string(echo) + ", ";
    }
    if (!selectedEchos->empty())
    {
      result.pop_back();
      result.pop_back();
    }
    result += "}\n";
  }
  else
  {
    result += "all\n";
  }

  result += "  selectedLayers: ";
  if (selectedLayers)
  {
    result += "{";
    for (auto const& layer : *selectedLayers)
    {
      result += std::to_string(layer) + ", ";
    }
    if (!selectedLayers->empty())
    {
      result.pop_back();
      result.pop_back();
    }
    result += "}\n";
  }
  else
  {
    result += "all\n";
  }

  result += "  elevation: " + elevation.toString() + "\n";
  result += "  azimuth: " + azimuth.toString() + "\n";
  result += "  range: " + range.toString() + "\n";
  result += "  intensity: " + intensity.toString() + "\n";
  result += "  requiredReflectorFlag: ";
  if (requiredReflectorFlag)
  {
    result += (*requiredReflectorFlag ? "true" : "false");
  }
  else
  {
    result += "any";
  }
  result += "\n";

  result += "  requiredBloomingFlag: ";
  if (requiredBloomingFlag)
  {
    result += (*requiredBloomingFlag ? "true" : "false");
  }
  else
  {
    result += "any";
  }
  result += "\n";

  return result;
}

auto PointCloudConfiguration::toString() const -> std::string
{
  std::string result = "Fields:\n";
  result += fields.toString();
  result += "distanceScalingFactor: " + std::to_string(distanceScalingFactor) + "\n";
  result += "Filters:\n";
  result += filters.toString();
  return result;
}

} // namespace sick
