/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan100_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudCollector.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudToPCDConverter.hpp>
#include <sick_perception_sdk/drivers/MultiScan100.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/MultiScan100Configurator.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>

void writePointCloudToPCDFile(sick::PointCloud const& pointCloud, std::string const& filename)
{
  // open in binary mode to prevent the compiler from converting \n to \r\n on windows
  std::ofstream file(filename, std::ios_base::binary);
  if (!file.is_open())
  {
    std::cout << "Could not open file " << filename << " for writing.\n";
    return;
  }
  sick::PointCloudToPCDConverter::convertToPCDASCII(pointCloud, file);
  std::cout << "Wrote point cloud with " << pointCloud.numberOfPoints << " points to " << filename << "\n";
  file.close();
}

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
    sick::MultiScan100Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring scan data streaming...\n";
    configurator.enableScanDataStreaming("192.168.0.100", 2115); // Enter your computer's IP address

    // Create pcd_files directory if it doesn't exist
    std::filesystem::create_directories(std::filesystem::current_path() / "pcd_files");
  }
  catch (std::exception const& e)
  {
    std::cout << "Exception: " << e.what() << '\n';
  }

  sick::PointCloudConfiguration config;
  config.fields.enableCartesian = true;
  config.fields.enableIntensity = true;

  sick::MultiScan100 driver(printExceptionMessage);
  driver.setOnNewFullFrame(
    config,
    [&](sick::PointCloud const& fullFrame) {
      auto filename =
        std::filesystem::current_path() / "pcd_files" / ("multiScan100_" + std::to_string(fullFrame.header.timestamp.microsecondsSinceEpoch()) + ".pcd");
      writePointCloudToPCDFile(fullFrame, filename.string());
    },
    2115
  );
  driver.run();

  std::this_thread::sleep_for(std::chrono::seconds(10));
  return 0;
}
