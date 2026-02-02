/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan100_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudCollector.hpp>
#include <sick_perception_sdk/drivers/MultiScan100.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/MultiScan100Configurator.hpp>

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace sick::literals;

void onNewImuData(sick::compact::imu::ImuData const& compactImu)
{
  std::cout << "Received IMU data with timestamp: \t" << compactImu.imuSensorTimestampMicroseconds << " us" << '\n';
}

void onNewFullFrame(sick::PointCloud const& pointCloud)
{
  std::cout << "Received point cloud data with timestamp: \t" << pointCloud.header.timestamp.microsecondsSinceEpoch() << " (" << pointCloud.numberOfPoints
            << " points)" << '\n';
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
    sick::MultiScan100Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring scan data streaming...\n";
    configurator.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address

    std::cout << "Configuring IMU data streaming...\n";
    configurator.enableImuStreaming("192.168.0.100", 7503); // Enter your computer's IP address
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;

  sick::MultiScan100 driver(printExceptionMessage);
  driver.setOnNewFullFrame(config, onNewFullFrame, 2115, std::chrono::milliseconds(10000), std::chrono::milliseconds(3000));
  driver.setOnNewImuData(onNewImuData, 7503);
  driver.run();

  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}
