/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include "../examples_helper.hpp"
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudCollector.hpp>
#include <sick_perception_sdk/drivers/PicoScan100.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/PicoScan100Configurator.hpp>
#include <sick_perception_sdk/sensor_configuration/SensorConfigurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/picoScan100.g.hpp> // Include all generated payloads for picoScan100

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
  sick::IpV4Address const IpAddress    = "192.168.0.1";
  sick::IpV4Address const IpAddressNew = "192.168.0.2";
  sick::IpV4Address const IpMask       = "255.255.255.0";
  sick::IpV4Address const IpGateway    = "0.0.0.0";

  try
  {
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(IpAddress, 80);
    sick::PicoScan100Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Current IP Address: " << configurator.sensorIPAddress.get().toString() << '\n';

    // Write new IP configuration
    std::cout << "Configuring new IP settings...\n";
    configurator.sensorIPAddressingMode.set(sick::PicoScan100Configurator::IPAddressingMode::StaticIP);
    configurator.sensorIPAddress.set(IpAddressNew);
    configurator.sensorIPMask.set(IpMask);
    configurator.sensorIPGateway.set(IpGateway);

    // Read back and print the new configuration
    auto const modeResponse = configurator.sensorIPAddressingMode.get();
    std::cout << "New IP Configuration:\n";
    std::cout << "IP Mode: " << (modeResponse == sick::PicoScan100Configurator::IPAddressingMode::StaticIP ? "Static" : "DHCP") << '\n';
    std::cout << "IP Address: " << configurator.sensorIPAddress.get().toString() << '\n';
    std::cout << "IP Mask: " << configurator.sensorIPMask.get().toString() << '\n';
    std::cout << "IP Gateway: " << configurator.sensorIPGateway.get().toString() << '\n';

    // Apply the changes
    std::cout << "Applying IP configuration changes...\n";
    configurator.ethernetUpdate.apply();

    std::cout << "IP configuration updated. Waiting for sensor...\n";
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Connect with new IP address
    auto const httpClientNew = std::make_shared<sick::httplib_client::HttpClient>(IpAddressNew, 80);
    sick::PicoScan100Configurator configuratorNew(httpClientNew, sick::UserLevel::Service, "servicelevel");
    std::cout << "Connected to sensor at new IP: " << configuratorNew.sensorIPAddress.get().toString() << '\n';
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  return 0;
}
