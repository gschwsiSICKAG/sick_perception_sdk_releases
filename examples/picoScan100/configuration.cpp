/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/picoScan100_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/PicoScan100Configurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/picoScan100/OpHours.g.hpp>

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace sick::literals;

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
    sick::PicoScan100Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Reading objects with convenience function...\n";
    std::cout << "DeviceType: \t" << configurator.deviceType.get() << '\n';
    std::cout << "FirmwareVersion: \t" << configurator.firmwareVersion.get() << '\n';
    std::cout << "LocationName: \t" << configurator.locationName.get() << '\n';
    std::cout << "OrderNumber: \t" << configurator.orderNumber.get() << '\n';
    std::cout << "SerialNumber: \t" << configurator.serialNumber.get() << '\n';
    std::cout << "SystemTime: \t" << configurator.systemTime.get().count() << " us since epoch" << '\n';
    std::cout << "IpAddress: \t" << configurator.sensorIPAddress.get().toString() << '\n';

    std::cout << "Reading object without convenience function...\n";
    std::cout << "OpHours: \t" << configurator.readVariable<sick::srt::picoScan100::OpHours>()._OpHours << '\n';

    std::cout << "Setting echo filter with convenience function...\n";
    configurator.echoFilter.set(sick::PicoScan100Configurator::EchoFilterSetting::LastEcho);

    std::cout << "Setting angle range filter...\n";
    configurator.angleRangeFilter.enable({-90_deg, 90_deg, 1}); // start angle, stop angle, beam increment

    std::cout << "Configuring scan data streaming...\n";
    configurator.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  return 0;
}
