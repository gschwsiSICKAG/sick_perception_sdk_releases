/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/common/version.hpp>
#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>
#include <sick_perception_sdk/drivers/PicoScan100.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/PicoScan100Configurator.hpp>

#include <iostream>

int main(int argc, char* argv[])
{
  std::cout << "SICK Perception SDK Version: " << sick::version() << std::endl;

  // Test compilation of library compact_receiver
  sick::compact::scan_data::Parser parser;

  // Test compilation of library drivers
  sick::PicoScan100 driver;

  // Test compilation of library sensor_configuration
  auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>("127.0.0.1", 80);
  sick::PicoScan100Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

  return 0;
}
