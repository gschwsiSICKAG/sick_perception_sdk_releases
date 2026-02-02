/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/LRS4000_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/drivers/LRS4000.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/LRS4000Configurator.hpp>

#include <iostream>

using namespace sick::literals;

std::uint8_t newScanCounter = 0;

void onNewScanData(sick::compact::scan_data::ScanData const& compactScanData)
{
  newScanCounter++;
  if (newScanCounter == 100)
  {
    std::cout << "Received scan data with telegram counter: " << compactScanData.header.telegramCounter << '\n';
    newScanCounter = 0;
  }
}

void printExceptionMessage(std::exception const& ex)
{
  std::cout << "Error: " << ex.what() << '\n';
}

int main(int argc, char* argv[])
{
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  sick::Log::init(sick::LogLevel::Info);

  auto httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);
  sick::LRS4000Configurator configurator(std::move(httpClient), sick::UserLevel::Service, "servicelevel");
  try
  {
    std::cout << "Diagnosis for device at " << configurator.sensorIPAddress.get().toString() << '\n';
    std::cout << "You can find a diagnosis overview at: http://" + configurator.sensorIPAddress.get().toString() + "/#/diagnosis/overview" << '\n';
    std::cout << "DeviceType: \t" << configurator.deviceType.get() << '\n';
    std::cout << "DeviceState: \t" << static_cast<int>(configurator.deviceState.get()) << '\n';
    std::cout << "FirmwareVersion: \t" << configurator.firmwareVersion.get() << '\n';
    std::cout << "LocationName: \t" << configurator.locationName.get() << '\n';
    std::cout << "OrderNumber: \t" << configurator.orderNumber.get() << '\n';
    std::cout << "SerialNumber: \t" << configurator.serialNumber.get() << '\n';

    std::cout << "Blinking the device LEDs for identification...\n";
    configurator.findMe(5_s);

    std::cout << "Configuring compact streaming..." << '\n';
    configurator.streaming.set(sick::LRS4000Configurator::StreamingMode::Compact);
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  // gets continuously DeviceState and Temperature
  std::thread deviceHealthThread([&configurator]() {
    while (true)
    {
      try
      {
        std::cout << "DeviceState: " << static_cast<int>(configurator.deviceState.get()) << '\n';
        std::cout << "Temperature: " << configurator.sensorTemperature.get() << '\n';
      }
      catch (std::exception const& e)
      {
        std::cout << "Polling error: " << e.what() << '\n';
      }
      std::this_thread::sleep_for(std::chrono::seconds(2));
    }
  });

  sick::LRS4000 driver(deviceAddress, printExceptionMessage);
  driver.setOnNewScanData(onNewScanData, 2115, std::chrono::milliseconds(3000), std::chrono::milliseconds(1000));
  driver.run();
  std::this_thread::sleep_for(std::chrono::seconds(60));
  deviceHealthThread.join();

  return 0;
}
