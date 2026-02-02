/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/LRS4000_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/LRS4000Configurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/OpHours.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/json/LRS4000.g.hpp>

#include <chrono>
#include <fstream>
#include <iostream>

using namespace std::chrono_literals;

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

    std::cout << "Reading objects with convenience function...\n";
    std::cout << "DeviceType: \t" << configurator.deviceType.get() << '\n';
    std::cout << "FirmwareVersion: \t" << configurator.firmwareVersion.get() << '\n';
    std::cout << "LocationName: \t" << configurator.locationName.get() << '\n';
    std::cout << "OrderNumber: \t" << configurator.orderNumber.get() << '\n';
    std::cout << "SerialNumber: \t" << configurator.serialNumber.get() << '\n';
    std::cout << "IpAddress: \t" << configurator.sensorIPAddress.get().toString() << '\n';

    std::cout << "Reading object without convenience function...\n";
    std::cout << "OpHours: \t" << configurator.readVariable<sick::srt::LRS4000::OpHours>()._OpHours << '\n';

    std::cout << "Setting echo filter with convenience function...\n";
    configurator.echoFilter.set(sick::LRS4000Configurator::EchoFilterSetting::LastEcho);

    std::cout << "Configuring compact streaming with convenience function..." << '\n';
    configurator.streaming.set(sick::LRS4000Configurator::StreamingMode::Compact);
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  return 0;
}
