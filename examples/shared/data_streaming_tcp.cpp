/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/shared_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>

#if defined(USE_LRS4000)
#  include <sick_perception_sdk/drivers/LRS4000/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/LRS4000/Configurator.hpp>
using ConfiguratorT = sick::LRS4000::v1_9_0_0R::Configurator;
using DriverT       = sick::LRS4000::Driver;
#else // Defaults to multiScan200
#  include <sick_perception_sdk/drivers/multiScan200/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/multiScan200/Configurator.hpp>
using ConfiguratorT = sick::multiScan200::v0_9_0::Configurator;
using DriverT       = sick::multiScan200::Driver;
#endif

#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

#if defined(USE_MULTISCAN200)
void onNewAmbientLightData(sick::compact::ambient_light::AmbientLightData const& compactAmbientLight)
{
  std::cout << "Received ambient light data with timestamp: " << compactAmbientLight.payload.metaData.startTimestamp << " us\n";
}

void onNewImuData(sick::compact::imu::ImuData const& compactImu)
{
  std::cout << "Received IMU data with timestamp: \t" << compactImu.sensorTimestamp << " us\n";
}
#endif

void onNewPointCloud(sick::MultiEchoPointCloud const& pointCloud)
{
  std::cout << "Got point cloud with " << pointCloud.numberOfPoints() << " points.\n";
}

int main(int argc, char* argv[])
{
  sick::examples::printSdkVersion();
  using namespace sick::literals;

  sick::examples::printSdkVersion();
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  try
  {
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);

    // Change the default passwords during initial commissioning to secure your device.
    // Passwords can be updated via the web browser or API.
    // For production use, store passwords in a secure vault rather than in plain text.
    ConfiguratorT configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring compact streaming...\n";
    configurator.streaming.set(ConfiguratorT::StreamingMode::Compact);
  }
  catch (std::exception const& exception)
  {
    std::cout << "Exception: " << exception.what() << '\n';
    return EXIT_FAILURE;
  }

  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;

  DriverT driver(deviceAddress, sick::examples::printExceptionMessage);
  driver.scanDataReceiver().setup();
  driver.scanDataReceiver().setOnNewFrameCallback(onNewPointCloud, config);
#if defined(USE_MULTISCAN200)
  driver.ambientLightReceiver().setup();
  driver.ambientLightReceiver().setOnNewDataCallback(onNewAmbientLightData);
  driver.imuReceiver().setup();
  driver.imuReceiver().setOnNewDataCallback(onNewImuData);
#endif
  driver.run();

  std::this_thread::sleep_for(10s);
  return 0;
}
