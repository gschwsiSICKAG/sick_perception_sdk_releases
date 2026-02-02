/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan200_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/MultiScan200Configurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/OpHours.g.hpp>

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
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);
    sick::MultiScan200Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Reading objects with convenience function...\n";
    std::cout << "DeviceType: \t" << configurator.deviceType.get() << '\n';
    std::cout << "FirmwareVersion: \t" << configurator.firmwareVersion.get() << '\n';
    std::cout << "LocationName: \t" << configurator.locationName.get() << '\n';
    std::cout << "OrderNumber: \t" << configurator.orderNumber.get() << '\n';
    std::cout << "SensorPosition: \t" << configurator.sensorPosition.get().toString() << '\n';
    std::cout << "SerialNumber: \t" << configurator.serialNumber.get() << '\n';
    std::cout << "SystemTime: \t" << configurator.systemTime.get().count() << " us since epoch" << '\n';
    std::cout << "IpAddress: \t" << configurator.sensorIPAddress.get().toString() << '\n';

    std::cout << "Reading object without convenience function...\n";
    std::cout << "OpHours: \t" << configurator.readVariable<sick::srt::multiScan200::OpHours>()._OpHours << '\n';

    std::cout << "Setting echo filter with convenience function...\n";
    configurator.echoFilter.set(sick::MultiScan200Configurator::EchoFilterSetting::StrongestEcho);

    std::cout << "Enabling horizontal angle range filter...\n";
    configurator.horizontalAngleRangeFilter.enable({-120_deg, 120_deg, 1});

    std::cout << "Configuring compact streaming with convenience function..." << '\n';
    configurator.streaming.set(sick::MultiScan200Configurator::StreamingMode::Compact);
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  return 0;
}
