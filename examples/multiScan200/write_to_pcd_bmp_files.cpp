/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/multiScan200_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/common/BitmapEncoder.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudToPCDConverter.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>
#include <sick_perception_sdk/drivers/multiScan200/Driver.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/httplib_client/HttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/multiScan200/Configurator.hpp>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <utility>

using namespace std::chrono_literals;

auto getAmbientLightValueRange(sick::compact::multiscan200::MultiScan200Data const& data) -> std::pair<std::uint16_t, std::uint16_t>
{
  std::uint16_t minValue = std::numeric_limits<std::uint16_t>::max();
  std::uint16_t maxValue = std::numeric_limits<std::uint16_t>::lowest();

  for (auto const& column : data.ambientLightData)
  {
    for (auto const& value : column)
    {
      if (value < minValue)
      {
        minValue = value;
      }
      if (value > maxValue)
      {
        maxValue = value;
      }
    }
  }
  return {minValue, maxValue};
}

void writeAmbientLightToBitmap(sick::compact::multiscan200::MultiScan200Data const& data, std::string const& filename)
{
  auto ambientLightData = data.ambientLightData;
  std::reverse(ambientLightData.begin(), ambientLightData.end());
  auto const minMaxValue = getAmbientLightValueRange(data);
  auto const bitmap      = sick::encodeGrayscaleBmp<std::uint16_t>(ambientLightData, minMaxValue);
  std::ofstream file(filename, std::ios_base::binary);
  file.write(reinterpret_cast<char const*>(bitmap.data()), bitmap.size());
  file.close();
}

void writePointCloudToPCDFile(sick::MultiEchoPointCloud const& pointCloud, std::string const& filename)
{
  // open in binary mode to prevent the compiler from converting \n to \r\n on windows
  std::ofstream file(filename, std::ios_base::binary);
  sick::PointCloudToPCDConverter::convertToPCDASCII(pointCloud, file);
  std::cout << "Wrote point cloud with " << pointCloud.numberOfPoints() << " points to " << filename << "\n";
  file.close();
}

int main(int argc, char* argv[])
{
  sick::examples::printSdkVersion();
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);
  auto const basePath      = std::filesystem::current_path() / "multiScan200_files";

  try
  {
    auto const httpClient = std::make_shared<sick::httplib_client::HttpClient>(deviceAddress, 80);

    // Change the default passwords during initial commissioning to secure your device.
    // Passwords can be updated via the web browser or API.
    // For production use, store passwords in a secure vault rather than in plain text.
    sick::multiScan200::v0_9_0::Configurator configurator(httpClient, sick::UserLevel::Service, "servicelevel");

    std::cout << "Configuring compact streaming...\n";
    configurator.streaming.set(sick::multiScan200::v0_9_0::Configurator::StreamingMode::Compact);

    // Create multiScan200_files directory if it doesn't exist
    std::filesystem::create_directories(basePath);
  }
  catch (std::exception const& exception)
  {
    std::cout << "Exception: " << exception.what() << '\n';
    return EXIT_FAILURE;
  }

  sick::PointCloudConfiguration config;
  config.fields.enableIntensity  = true;
  config.fields.enableSpherical  = true;
  config.fields.enableRing       = true;
  config.fields.enableLayer      = true;
  config.fields.enableTimeOffset = true;
  config.fields.enableEcho       = true;

  sick::multiScan200::Driver driver(deviceAddress, sick::examples::printExceptionMessage);
  driver.scanDataReceiver().setup();
  driver.scanDataReceiver().setOnNewFrameCallback(
    [basePath](sick::MultiEchoPointCloud const& framePointCloud) {
      auto const filename = basePath / ("multiScan200_" + std::to_string(framePointCloud.timestamp().microsecondsSinceEpoch()) + ".pcd");
      writePointCloudToPCDFile(framePointCloud, filename.string());
    },
    config
  );
  driver.scanDataReceiver().setOnNewFrameCallback([basePath](sick::compact::multiscan200::MultiScan200Data const& data) {
    auto const filename = basePath / ("ambient_light_" + std::to_string(data.telegramHeader.transmitTimestamp.microsecondsSinceEpoch()) + ".bmp");
    writeAmbientLightToBitmap(data, filename.string());
  });
  driver.run();

  std::this_thread::sleep_for(10s);
  return 0;
}
