/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/shared_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>

#if defined(USE_MULTISCAN100)
#  include <sick_perception_sdk/drivers/MultiScan100.hpp>
#  include <sick_perception_sdk/sensor_configuration/MultiScan100Configurator.hpp>
using ConfiguratorT         = sick::MultiScan100Configurator;
using SetContourRequest     = sick::srt::multiScan100::SetFieldEvaluationContour::Post::Request;
using GetContourRequest     = sick::srt::multiScan100::GetFieldEvaluationContour::Post::Response;
using FieldEvaluationResult = sick::srt::multiScan100::FieldEvaluationResult::Get::Response::FieldEvaluationResult;
using EvaluationState       = sick::srt::multiScan100::FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem::State;
#elif defined(USE_LRS4000)
#  include <sick_perception_sdk/drivers/LRS4000.hpp>
#  include <sick_perception_sdk/sensor_configuration/LRS4000Configurator.hpp>
using ConfiguratorT         = sick::LRS4000Configurator;
using SetContourRequest     = sick::srt::LRS4000::SetFieldEvaluationContour::Post::Request;
using GetContourRequest     = sick::srt::LRS4000::GetFieldEvaluationContour::Post::Response;
using FieldEvaluationResult = sick::srt::LRS4000::FieldEvaluationResult::Get::Response::FieldEvaluationResult;
using EvaluationState       = sick::srt::LRS4000::FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem::State;
#else // Default to picoScan100
#  include <sick_perception_sdk/drivers/PicoScan100.hpp>
#  include <sick_perception_sdk/sensor_configuration/PicoScan100Configurator.hpp>
using ConfiguratorT         = sick::PicoScan100Configurator;
using SetContourRequest     = sick::srt::picoScan100::SetFieldEvaluationContour::Post::Request;
using GetContourRequest     = sick::srt::picoScan100::GetFieldEvaluationContour::Post::Response;
using FieldEvaluationResult = sick::srt::picoScan100::FieldEvaluationResult::Get::Response::FieldEvaluationResult;
using EvaluationState       = sick::srt::picoScan100::FieldEvaluationResult::Get::Response::FieldEvaluationResult::EvaluationResultListItem::State;
#endif

#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

constexpr int GroupActivationStateInactive = 0;
constexpr int NumberOfEvaluationGroups     = 48;

void printFieldEvaluationContours(std::vector<sick::FieldEvaluationContour> const& fieldContours)
{
  for (auto const& contour : fieldContours)
  {
    std::cout << "Contour for Evaluation ID " << contour.evaluationId << '\n';
    std::cout << "Points: \n";
    for (auto const& point : contour.points)
    {
      std::cout << "- [" << point.x << ", " << point.y << "]\n";
    }
    std::cout << "Lower z limit: " << contour.lowerZLimit << '\n';
    std::cout << "Upper z limit: " << contour.upperZLimit << '\n';
  }
}

void printEvaluationGroupStates(ConfiguratorT& configurator)
{
  std::cout << "Getting group states from device.\n";
  std::array<int, NumberOfEvaluationGroups> groupStates = configurator.fieldEvaluationGroupState.get();
  for (size_t i = 0; i < groupStates.size(); ++i)
  {
    if (groupStates[i] != GroupActivationStateInactive) //only show active Fields
    {
      std::cout << "Group ID: " << i + 1 << ", State: " << groupStates[i] << '\n';
    }
  }
}

void printEvaluationFieldsStates(std::vector<int>& evaluationIDs, ConfiguratorT& configurator)
{
  std::cout << "Getting states of fields.\n";
  FieldEvaluationResult result = configurator.fieldEvaluationResult.get();
  std::cout << "Timestamp: " << result._Timestamp << '\n';
  for (size_t i = 0; i < result._EvaluationResultList.size(); i++)
  {
    if (result._EvaluationResultList.at(i)._State != EvaluationState::NotConfigured)
    {
      std::cout << "ID: " << i + 1 << " State: " << static_cast<int>(result._EvaluationResultList.at(i)._State) << '\n';
      evaluationIDs.push_back(static_cast<int>(i + 1));
    }
  }
}

void scaleEvaluationContours(std::vector<int>& evaluationIDs, ConfiguratorT& configurator)
{
  if (evaluationIDs.size() == 0)
  {
    std::cout << "No fields to change. Make sure that there is at least one field configured in the sensor.\n";
    return;
  }

  std::cout << "\nReading and changing field contours: \n\n";

  for (auto const& evaluationID : evaluationIDs)
  {
    auto fieldContours = configurator.fieldEvaluationContour.get(evaluationID);
    printFieldEvaluationContours(fieldContours);

    // Change field contour points
    for (auto& contour : fieldContours)
    {
      std::cout << "Changing contour for field/evaluation Id: " << contour.evaluationId << '\n';

      for (auto& point : contour.points)
      {
        point.x = point.x / 2;
        point.y = point.y / 2;
      }

      configurator.fieldEvaluationContour.set(contour.evaluationId, contour);
    }
  }
}

/*
*  ! Expected Device Configuration: At least one field must already be stored in Object Detection. !
*/

int main(int argc, char* argv[])
{
  sick::examples::printSdkVersion();
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);

  // Change the default passwords during initial commissioning to secure your device.
  // Passwords can be updated via the web browser or API.
  // For production use, store passwords in a secure vault rather than in plain text.
  ConfiguratorT configurator(httpClient, sick::UserLevel::Service, "servicelevel");

  try
  {
    std::vector<int> evaluationIDs;

    printEvaluationGroupStates(configurator);
    printEvaluationFieldsStates(evaluationIDs, configurator);
    scaleEvaluationContours(evaluationIDs, configurator);
  }
  catch (std::exception const& exception)
  {
    std::cout << "Exception: " << exception.what() << '\n';
    return EXIT_FAILURE;
  }
}
