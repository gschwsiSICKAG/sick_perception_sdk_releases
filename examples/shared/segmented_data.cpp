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
using ConfiguratorT = sick::MultiScan100Configurator;
using DriverT       = sick::MultiScan100;
#else // Default to picoScan100
#  include <sick_perception_sdk/drivers/PicoScan100.hpp>
#  include <sick_perception_sdk/sensor_configuration/PicoScan100Configurator.hpp>
using ConfiguratorT = sick::PicoScan100Configurator;
using DriverT       = sick::PicoScan100;
#endif

#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

void onNewScanData(sick::compact::scan_data::ScanData const& compactScanData)
{
  std::cout << "Received scan data with telegram counter: " << compactScanData.telegramHeader.telegramCounter << '\n';
  for (auto const& module : compactScanData.modules)
  {
    std::cout << "Segment index: " << module.metaData.segmentIndex << '\n';
    std::cout << "Frame sequence number: " << module.metaData.frameSequenceNumber << '\n';
  }
}

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
    std::cout << "Configuring scan data streaming...\n";
    configurator.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address
  }
  catch (std::exception const& exception)
  {
    std::cout << "Exception: " << exception.what() << '\n';
    return EXIT_FAILURE;
  }

  DriverT driver(sick::examples::printExceptionMessage);
  driver.scanDataReceiver().setup();
  driver.scanDataReceiver().setOnNewSegmentCallback(onNewScanData);
  driver.run();

  std::this_thread::sleep_for(10s);

  return 0;
}
