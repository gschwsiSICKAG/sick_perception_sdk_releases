/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan100_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/drivers/MultiScan100.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/MultiScan100Configurator.hpp>

#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void printExceptionMessage(std::exception const& ex)
{
  std::cout << "Error: " << ex.what() << '\n';
}

void onNewScanData(sick::compact::scan_data::ScanData const& compactScanData)
{
  std::cout << "Received scan data with telegram counter: " << compactScanData.header.telegramCounter << '\n';
  for (auto& module : compactScanData.modules)
  {
    std::cout << "Segment counter: \t" << module.metaData.segmentIndex << '\n';
    std::cout << "Frame number: \t" << module.metaData.frameSequenceNumber << '\n';
  }
}

int main(int argc, char* argv[])
{
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);
  sick::MultiScan100Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

  try
  {
    std::cout << "Configuring scan data streaming...\n";
    configurator.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  sick::MultiScan100 driver(printExceptionMessage);
  driver.setOnNewScanData(onNewScanData, 2115);
  driver.run();

  std::this_thread::sleep_for(std::chrono::seconds(10));

  return 0;
}
