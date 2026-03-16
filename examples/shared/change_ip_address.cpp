/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/shared_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/SensorConfigurator.hpp>

#if defined(USE_MULTISCAN100)
#  include <sick_perception_sdk/drivers/multiScan100/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/multiScan100/multiScan100.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/multiScan100/Configurator.hpp>
using ConfiguratorT = sick::multiScan100::v2_4_1::Configurator;
#elif defined(USE_MULTISCAN200)
#  include <sick_perception_sdk/drivers/multiScan200/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/multiScan200/multiScan200.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/multiScan200/Configurator.hpp>
using ConfiguratorT = sick::multiScan200::v0_9_0::Configurator;
#elif defined(USE_LRS4000)
#  include <sick_perception_sdk/drivers/LRS4000/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/LRS4000/Configurator.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/LRS4000/LRS4000.g.hpp>
using ConfiguratorT = sick::LRS4000::v1_9_0_0R::Configurator;
#else // Default to picoScan100
#  include <sick_perception_sdk/drivers/picoScan100/Driver.hpp>
#  include <sick_perception_sdk/sensor_configuration/api/picoScan100/picoScan150.g.hpp>
#  include <sick_perception_sdk/sensor_configuration/picoScan150/Configurator.hpp>
using ConfiguratorT = sick::picoScan150::v2_2_1::Configurator;
#endif

#include <cstdint>
#include <iomanip>
#include <iostream>

using namespace sick::literals;
using namespace std::chrono_literals;

int main(int argc, char* argv[])
{
  sick::examples::printSdkVersion();
  sick::IpV4Address const IpAddress    = "192.168.0.1";
  sick::IpV4Address const IpAddressNew = "192.168.0.2";
  sick::IpV4Address const IpMask       = "255.255.255.0";
  sick::IpV4Address const IpGateway    = "0.0.0.0";

  try
  {
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(IpAddress, 80);

    // Change the default passwords during initial commissioning to secure your device.
    // Passwords can be updated via the web browser or API.
    // For production use, store passwords in a secure vault rather than in plain text.
    ConfiguratorT configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Current IP Address: " << configurator.sensorIPAddress.get().toString() << '\n';

    // Write new IP configuration
    std::cout << "Configuring new IP settings...\n";
    configurator.sensorIPAddressingMode.set(ConfiguratorT::IPAddressingMode::StaticIP);
    configurator.sensorIPAddress.set(IpAddressNew);
    configurator.sensorIPMask.set(IpMask);
    configurator.sensorIPGateway.set(IpGateway);

    // Read back and print the new configuration
    auto const modeResponse = configurator.sensorIPAddressingMode.get();
    std::cout << "New IP Configuration:\n";
    std::cout << "IP Mode: " << (modeResponse == ConfiguratorT::IPAddressingMode::StaticIP ? "Static" : "DHCP") << '\n';
    std::cout << "IP Address: " << configurator.sensorIPAddress.get().toString() << '\n';
    std::cout << "IP Mask: " << configurator.sensorIPMask.get().toString() << '\n';
    std::cout << "IP Gateway: " << configurator.sensorIPGateway.get().toString() << '\n';

    // Apply the changes
    std::cout << "Applying IP configuration changes...\n";
    configurator.ethernetUpdate.apply();

    std::cout << "IP configuration updated. Waiting for sensor...\n";
    std::this_thread::sleep_for(5s);

    // Connect with new IP address
    auto const httpClientNew = std::make_shared<sick::httplib_client::HttpClient>(IpAddressNew, 80);
    ConfiguratorT configuratorNew(httpClientNew, sick::UserLevel::Service, "servicelevel");
    std::cout << "Connected to sensor at new IP: " << configuratorNew.sensorIPAddress.get().toString() << '\n';
  }
  catch (std::exception const& exception)
  {
    std::cout << "Exception: " << exception.what() << '\n';
    return EXIT_FAILURE;
  }

  return 0;
}
