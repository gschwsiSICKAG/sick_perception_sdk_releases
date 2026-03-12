/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/LRS4000_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>

#if defined(USE_MULTISCAN100)
#  include <sick_perception_sdk/drivers/MultiScan100.hpp>
#  include <sick_perception_sdk/sensor_configuration/MultiScan100Configurator.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/multiScan100.g.hpp>
using ConfiguratorT = sick::MultiScan100Configurator;
namespace srt       = sick::srt::multiScan100;
#elif defined(USE_MULTISCAN200)
#  include <sick_perception_sdk/drivers/MultiScan200.hpp>
#  include <sick_perception_sdk/sensor_configuration/MultiScan200Configurator.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/multiScan200.g.hpp>
using ConfiguratorT = sick::MultiScan200Configurator;
namespace srt       = sick::srt::multiScan200;
#elif defined(USE_LRS4000)
#  include <sick_perception_sdk/drivers/LRS4000.hpp>
#  include <sick_perception_sdk/sensor_configuration/LRS4000Configurator.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/LRS4000.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/LRS4000/OpHours.g.hpp>
using ConfiguratorT = sick::LRS4000Configurator;
namespace srt       = sick::srt::LRS4000;
#else // Default to picoScan100
#  include <sick_perception_sdk/drivers/PicoScan100.hpp>
#  include <sick_perception_sdk/sensor_configuration/PicoScan100Configurator.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/picoScan100.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/picoScan100/LFPintervalFilter.g.hpp>
using ConfiguratorT = sick::PicoScan100Configurator;
namespace srt       = sick::srt::picoScan100;
#endif

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace sick::literals;

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

    std::cout << "Reading objects with convenience function...\n";
    std::cout << "DeviceType:      " << configurator.deviceType.get() << '\n';
    std::cout << "FirmwareVersion: " << configurator.firmwareVersion.get() << '\n';
    std::cout << "LocationName:    " << configurator.locationName.get() << '\n';
    std::cout << "OrderNumber:     " << configurator.orderNumber.get() << '\n';
    std::cout << "SerialNumber:    " << configurator.serialNumber.get() << '\n';
    std::cout << "SystemTime:      " << configurator.systemTime.get().count() << " us since epoch\n";
    std::cout << "IpAddress:       " << configurator.sensorIPAddress.get().toString() << '\n';

    std::cout << "Reading object without convenience function...\n";
    std::cout << "OpHours:         " << configurator.readVariable<srt::OpHours>()._OpHours << '\n';

    std::cout << "Setting echo filter with convenience function...\n";
    configurator.echoFilter.set(ConfiguratorT::EchoFilterSetting::LastEcho);

    std::cout << "Setting echo filter without convenience function...\n";
    srt::FREchoFilter::Post::Request settings;
    settings._FREchoFilter = srt::FREchoFilter::Post::Request::FREchoFilter::FirstEcho;
    configurator.writeVariable<srt::FREchoFilter>(settings);

    std::cout << "Configuring compact streaming...\n";
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

  return 0;
}
