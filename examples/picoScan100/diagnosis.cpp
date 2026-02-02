/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/picoScan100_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/compact_receiver/PackageLossMonitor.hpp>
#include <sick_perception_sdk/drivers/PicoScan100.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/PicoScan100Configurator.hpp>

#include <chrono>
#include <iostream>
#include <thread>

using namespace sick::literals;
using namespace std::chrono_literals;
using MissedPackages = sick::compact::scan_data::PackageLossMonitor::MissedPackages;

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

void onPackageLoss(MissedPackages const& missedPackages)
{
  std::cout << "Package losses detected: Lost Telegrams=" << missedPackages.numberOfLostTelegrams << ", Lost Frames=" << missedPackages.numberOfLostFrames
            << ", Lost Segments=" << missedPackages.numberOfLostSegments << '\n';
}

void printExceptionMessage(std::exception const& ex)
{
  std::cout << "Error: " << ex.what() << '\n';
}

int main(int argc, char* argv[])
{
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  sick::Log::init(sick::LogLevel::Info);

  auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);
  sick::PicoScan100Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");
  try
  {
    std::cout << "Diagnosis for device at IP " << configurator.sensorIPAddress.get().toString() << '\n';
    std::cout << "You can find a diagnosis overview at: http://" + configurator.sensorIPAddress.get().toString() + "/#/diagnosis/overview" << '\n';
    std::cout << "DeviceType: \t" << configurator.deviceType.get() << '\n';
    std::cout << "DeviceState: \t" << static_cast<int>(configurator.deviceState.get()) << '\n';
    std::cout << "FirmwareVersion: \t" << configurator.firmwareVersion.get() << '\n';
    std::cout << "LocationName: \t" << configurator.locationName.get() << '\n';
    std::cout << "OrderNumber: \t" << configurator.orderNumber.get() << '\n';
    std::cout << "SerialNumber: \t" << configurator.serialNumber.get() << '\n';
    std::cout << "SystemTime: \t" << configurator.systemTime.get().count() << " us since epoch" << '\n';

    std::cout << "Blinking the device LEDs for identification...\n";
    configurator.findMe(5_s);

    std::cout << "Configuring scan data streaming...\n";
    configurator.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address
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

        auto contaminationData = configurator.contaminationData.get();
        std::cout << "ContaminationData [" << contaminationData.size() << " sectors]: ";
        for (size_t i = 0; i < contaminationData.size(); ++i)
        {
          std::cout << contaminationData[i];
          if (i < contaminationData.size() - 1)
          {
            std::cout << ", ";
          }
        }
        std::cout << '\n';
      }
      catch (std::exception const& e)
      {
        std::cout << "Polling error: " << e.what() << '\n';
      }
      std::this_thread::sleep_for(2s);
    }
  });

  //depends on the configured field of view
  constexpr std::uint64_t kExpectedNumberOfSegments = 10;

  std::uint8_t intervalFilterSetting = 1;
  if (configurator.intervalFilter.isEnabled())
  {
    intervalFilterSetting = configurator.intervalFilter.get().value();
  }

  sick::compact::scan_data::PackageLossMonitor packageLossMonitor {kExpectedNumberOfSegments, intervalFilterSetting};
  packageLossMonitor.setPackageLossCallback(onPackageLoss);

  sick::PicoScan100 driver(printExceptionMessage);
  driver.setPackageLossMonitor(packageLossMonitor);
  driver.setOnNewScanData(onNewScanData, 2115);
  driver.run();
  std::this_thread::sleep_for(60s);

  return 0;
}
