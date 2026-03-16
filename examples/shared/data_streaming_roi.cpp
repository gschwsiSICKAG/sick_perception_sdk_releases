/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/shared_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>

#if defined(USE_MULTISCAN100)
#  include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudCollector.hpp>
#  include <sick_perception_sdk/drivers/multiScan100/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/multiScan100/Configurator.hpp>
using ConfiguratorT = sick::multiScan100::v2_4_1::Configurator;
using DriverT       = sick::multiScan100::Driver;
#elif defined(USE_MULTISCAN200)
#  include <sick_perception_sdk/drivers/multiScan200/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/multiScan200/Configurator.hpp>
using ConfiguratorT = sick::multiScan200::v0_9_0::Configurator;
using DriverT       = sick::multiScan200::Driver;
#elif defined(USE_LRS4000)
#  include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudCollector.hpp>
#  include <sick_perception_sdk/drivers/LRS4000/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/LRS4000/Configurator.hpp>
using ConfiguratorT = sick::LRS4000::v1_9_0_0R::Configurator;
using DriverT       = sick::LRS4000::Driver;
#else // Default to picoScan100
#  include <sick_perception_sdk/drivers/picoScan100/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/picoScan150/Configurator.hpp>
using ConfiguratorT = sick::picoScan150::v2_2_1::Configurator;
using DriverT       = sick::picoScan100::Driver;
#endif

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace sick::literals;
using namespace std::chrono_literals;

void onNewPointCloudData(sick::MultiEchoPointCloud const& pointCloud)
{
  using FieldType = sick::MultiEchoPointCloud::PointField::FieldType;
  std::cout << "Received point cloud data with timestamp: " << pointCloud.timestamp() << " (" << pointCloud.numberOfPoints() << " points)\n";

  for (size_t i = 0; i < pointCloud.numberOfPoints(); ++i)
  {
    auto const x     = pointCloud.getFieldValue<float>(FieldType::X, i);
    auto const y     = pointCloud.getFieldValue<float>(FieldType::Y, i);
    auto const z     = pointCloud.getFieldValue<float>(FieldType::Z, i);
    auto const range = pointCloud.getFieldValue<float>(FieldType::Range, i);
    auto const echo  = pointCloud.getFieldValue<std::int8_t>(FieldType::Echo, i);

    std::cout << "Point " << i << ":\t" << "x=" << std::fixed << std::setprecision(3) << x << " m\t" << "y=" << y << " m\t" << "z=" << z << " m\t"
              << "range=" << range << " m\t" << "echo=" << static_cast<int>(echo) << '\n';
  }
}

int main(int argc, char* argv[])
{
  sick::examples::printSdkVersion();
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  try
  {
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);

    // Change the default passwords during initial commissioning to secure your device.
    // Passwords can be updated via the web browser or API.
    // For production use, store passwords in a secure vault rather than in plain text.
    ConfiguratorT configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring scan data streaming...\n";
#if defined(USE_LRS4000) || defined(USE_MULTISCAN200)
    configurator.streaming.set(ConfiguratorT::StreamingMode::Compact);
#else
    configurator.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address
#endif
  }
  catch (std::exception const& exception)
  {
    std::cout << "Exception: " << exception.what() << '\n';
    return EXIT_FAILURE;
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

#if defined(USE_LRS4000) || defined(USE_MULTISCAN200)
  DriverT driver(deviceAddress, sick::examples::printExceptionMessage);
#else
  DriverT driver(sick::examples::printExceptionMessage);
#endif
  driver.scanDataReceiver().setup(2115, 10s, 3s);
  driver.scanDataReceiver().setOnNewFrameCallback(onNewPointCloudData, config);
  driver.run();
  std::this_thread::sleep_for(10s);
  return 0;
}
