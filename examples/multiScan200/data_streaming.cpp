/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan200_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/compact_receiver/AmbientLightParser.hpp>
#include <sick_perception_sdk/compact_receiver/ImuParser.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConverter.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudToPCDConverter.hpp>
#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>
#include <sick_perception_sdk/compact_receiver/StreamExtractor.hpp>
#include <sick_perception_sdk/drivers/MultiScan200.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/MultiScan200Configurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/json/multiScan200.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/EtherMACAddress.g.hpp>

#include <chrono>
#include <fstream>
#include <iostream>

using namespace std::chrono_literals;

void onNewAmbientLightData(sick::compact::ambient_light::AmbientLightData const& compactAmbientLight)
{
  std::cout << "Ambient Light Sensor Timestamp: " << compactAmbientLight.payload.metaData.startTimestamp << " us" << '\n';
}

void onNewImuData(sick::compact::imu::ImuData const& compactImu)
{
  std::cout << "IMU Sensor Timestamp: " << compactImu.imuSensorTimestampMicroseconds << " us" << '\n';
}

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
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);
    sick::MultiScan200Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring compact streaming..." << '\n';
    configurator.streaming.set(sick::MultiScan200Configurator::StreamingMode::Compact);
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;

  sick::MultiScan200 driver(deviceAddress, printExceptionMessage);
  driver.setOnNewPointCloud(config, onNewPointCloud, 2115, std::chrono::milliseconds(3000), std::chrono::milliseconds(1000));
  driver.setOnNewAmbientLightData(onNewAmbientLightData, 2116, std::chrono::milliseconds(3000), std::chrono::milliseconds(1000));
  driver.setOnNewImuData(onNewImuData, 2117, std::chrono::milliseconds(3000), std::chrono::milliseconds(1000));
  driver.run();

  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}
