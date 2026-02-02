/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/LRS4000_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConverter.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudToPCDConverter.hpp>
#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>
#include <sick_perception_sdk/compact_receiver/StreamExtractor.hpp>
#include <sick_perception_sdk/drivers/LRS4000.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/LRS4000Configurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/json/LRS4000.g.hpp>

#include <chrono>
#include <fstream>
#include <iostream>

using namespace std::chrono_literals;

void onNewPointCloud(sick::PointCloud const& pointCloud)
{
  std::cout << "Got point cloud with " << pointCloud.numberOfPoints << " points." << '\n';
}

void printExceptionMessage(std::exception const& ex)
{
  std::cout << "Error: " << ex.what() << '\n';
}

int main(int argc, char* argv[])
{
  using namespace sick::literals;

  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  try
  {
    auto httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);
    sick::LRS4000Configurator configurator(std::move(httpClient), sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring compact streaming with convenience function..." << '\n';
    configurator.streaming.set(sick::LRS4000Configurator::StreamingMode::Compact);
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;

  sick::LRS4000 driver(deviceAddress, printExceptionMessage);
  driver.setOnNewPointCloud(config, onNewPointCloud, 2115, std::chrono::milliseconds(3000), std::chrono::milliseconds(1000));
  driver.run();

  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}
