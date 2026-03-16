/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/LRS4000_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>

#if defined(USE_MULTISCAN100)
#  include <sick_perception_sdk/drivers/multiScan100/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/multiScan100/multiScan100.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/multiScan100/Configurator.hpp>
using ConfiguratorT = sick::multiScan100::v2_4_1::Configurator;
namespace srt       = sick::multiScan100::v2_4_1::api::rest;
#elif defined(USE_MULTISCAN200)
#  include <sick_perception_sdk/drivers/multiScan200/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/multiScan200/multiScan200.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/multiScan200/Configurator.hpp>
using ConfiguratorT = sick::multiScan200::v0_9_0::Configurator;
namespace srt       = sick::multiScan200::v0_9_0::api::rest;
#elif defined(USE_LRS4000)
#  include <sick_perception_sdk/drivers/LRS4000/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/LRS4000/Configurator.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/LRS4000/LRS4000.g.hpp>
using ConfiguratorT = sick::LRS4000::v1_9_0_0R::Configurator;
namespace srt       = sick::LRS4000::v1_9_0_0R::api::rest;
#else // Default to picoScan100
#  include <sick_perception_sdk/drivers/picoScan100/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/picoScan100/picoScan150.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/picoScan150/Configurator.hpp>
using ConfiguratorT = sick::picoScan150::v2_2_1::Configurator;
namespace srt       = sick::picoScan150::v2_2_1::api::rest;
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
