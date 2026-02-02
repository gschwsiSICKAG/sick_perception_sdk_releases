/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan100_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/drivers/MultiScan100.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/MultiScan100Configurator.hpp>

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex output_mutex;

void onNewFullFrame1(sick::PointCloud const& pointCloud)
{
  std::lock_guard<std::mutex> lock(output_mutex);
  std::cout << "Received full frame from device 1." << '\n';
}

void onNewFullFrame2(sick::PointCloud const& pointCloud)
{
  std::lock_guard<std::mutex> lock(output_mutex);
  std::cout << "Received full frame from device 2." << '\n';
}

void printExceptionMessage(std::uint16_t port, std::exception const& ex)
{
  std::lock_guard<std::mutex> lock(output_mutex);
  std::cout << "Error on port: " << port << ": " << ex.what() << '\n';
}

int main(int argc, char* argv[])
{
  auto const deviceAddresses = sick::examples::getTwoDeviceAddresses(argc, argv);

  auto const httpClient1 = std::make_shared<sick::httplib_client::HttpClient>(deviceAddresses.first, 80);
  auto const httpClient2 = std::make_shared<sick::httplib_client::HttpClient>(deviceAddresses.second, 80);
  sick::MultiScan100Configurator configurator1(httpClient1, sick::UserLevel::Service, "servicelevel");
  sick::MultiScan100Configurator configurator2(httpClient2, sick::UserLevel::Service, "servicelevel");

  try
  {
    std::cout << "Device 1 IP: " << configurator1.sensorIPAddress.get().toString() << '\n';
    std::cout << "Device 2 IP: " << configurator2.sensorIPAddress.get().toString() << '\n';

    std::cout << "Configuring scan data streaming...\n";
    configurator1.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address
    configurator2.enableScanDataStreaming("192.168.0.100", 2116); // Enter your computer's IP address
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  sick::MultiScan100 driver1([&](std::exception const& ex) {
    printExceptionMessage(2115, ex);
  });
  sick::MultiScan100 driver2([&](std::exception const& ex) {
    printExceptionMessage(2116, ex);
  });

  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;

  driver1.setOnNewFullFrame(config, onNewFullFrame1, 2115);
  driver1.run();

  driver2.setOnNewFullFrame(config, onNewFullFrame2, 2116);
  driver2.run();

  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}
