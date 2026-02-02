/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan200_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudCollector.hpp>
#include <sick_perception_sdk/drivers/MultiScan200.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/MultiScan200Configurator.hpp>

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace sick::literals;

void onNewPointCloud(sick::PointCloud const& pointCloud)
{
  std::cout << "Received point cloud data with timestamp: " << pointCloud.header.timestamp.microsecondsSinceEpoch() << " (" << pointCloud.numberOfPoints
            << " points)" << '\n';

  // Parse the raw point cloud data
  for (size_t i = 0; i < pointCloud.numberOfPoints; ++i)
  {
    std::uint8_t const* pointData = &pointCloud.data[i * pointCloud.pointStep];

    // Assuming the data is laid out as floats: x, y, z, range, azimuth, elevation, intensity, echo
    float const* floatData  = reinterpret_cast<float const*>(pointData);
    float const x           = floatData[0];
    float const y           = floatData[1];
    float const z           = floatData[2];
    float const range       = floatData[3];
    std::uint8_t const echo = pointData[pointCloud.pointStep - 1];

    std::cout << "Point " << i << ":\t" << "x=" << std::fixed << std::setprecision(3) << x << " m\t" << "y=" << y << " m\t" << "z=" << z << " m\t"
              << "range=" << range << " m\t" << "echo=" << static_cast<int>(echo) << '\n';
  }
}

void printExceptionMessage(std::exception const& ex)
{
  std::cout << "Error: " << ex.what() << '\n';
}

int main(int argc, char* argv[])
{
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  try
  {
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);
    sick::MultiScan200Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring scan data streaming...\n";
    configurator.streaming.set(sick::MultiScan200Configurator::StreamingMode::Compact);
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableSpherical = true;
  config.fields.enableIntensity = true;
  config.fields.enableEcho      = true;
  // only output data in this ROI
  config.filters.azimuth.min   = -1_deg;
  config.filters.azimuth.max   = 1_deg;
  config.filters.elevation.min = -1_deg;
  config.filters.elevation.max = 1_deg;

  sick::MultiScan200 driver(deviceAddress, printExceptionMessage);
  driver.setOnNewPointCloud(config, onNewPointCloud, 2115, std::chrono::milliseconds(10000), std::chrono::milliseconds(3000));
  driver.run();
  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}
