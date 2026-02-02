/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/logging/LogLevel.hpp>
#include <sick_perception_sdk/compact_receiver/AmbientLightData.hpp>
#include <sick_perception_sdk/compact_receiver/AmbientLightParser.hpp>
#include <sick_perception_sdk/compact_receiver/ImuData.hpp>
#include <sick_perception_sdk/compact_receiver/ImuParser.hpp>
#include <sick_perception_sdk/compact_receiver/PackageLossMonitor.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConverter.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>
#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>
#include <sick_perception_sdk/compact_receiver/TcpCompactStream.hpp>

#include <chrono>
#include <cstdint>
#include <functional>
#include <string>

namespace sick {

//! \brief This class listens for data packets of the multiScan200 in a non-blocking manner.
class SDK_EXPORT MultiScan200
{
public:
  //! @param deviceAddress The IP address of the MultiScan200 device to connect to
  //! @param onError Callback function that is called when an unhandled exception is thrown
  MultiScan200(IpV4Address deviceAddress, std::function<void(std::exception)> onError = [](std::exception) {});

  //! \param onNewScanData Callback function that is called when new scan data is received and parsed
  //! \param devicePort The port on the device to which to connect
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewScanData(
    std::function<void(compact::scan_data::ScanData)> onNewScanData,
    std::uint16_t devicePort                   = 2115,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \param pointCloudConfiguration The configuration for the point cloud
  //! \param onNewPointCloud Callback function that is called when a new point cloud is available
  //! \param devicePort The port on the device to which to connect
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewPointCloud(
    PointCloudConfiguration const& pointCloudConfiguration,
    std::function<void(PointCloud)> onNewPointCloud,
    std::uint16_t devicePort                   = 2115,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \param onNewAmbientLight Callback function that is called when new ambient light data is received and parsed
  //! \param devicePort The port on the device to which to connect
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewAmbientLightData(
    std::function<void(compact::ambient_light::AmbientLightData)> onNewAmbientLight,
    std::uint16_t devicePort                   = 2116,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \param onNewImu Callback function that is called when new IMU data is received and parsed
  //! \param devicePort The port on the device to which to connect
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewImuData(
    std::function<void(compact::imu::ImuData)> onNewImu,
    std::uint16_t devicePort                   = 2117,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  ~MultiScan200();

  //! \brief Connects to the TCP server and listens for incoming data packets.
  //!        Forwards the received packets to the onNewData callbacks.
  void run();

  void stop();

  //! \brief Set a PackageLossMonitor to detect losses of telegrams, frames or segments.
  //!        If the callback from PackageLossMonitor is needed, set it before calling this function.
  void setPackageLossMonitor(compact::scan_data::PackageLossMonitor monitor);

private:
  void enableScanDataStream(
    std::uint16_t devicePort,
    std::function<void(std::exception)> onError,
    std::chrono::milliseconds firstDataTimeout,
    std::chrono::milliseconds newDataTimeout
  );
  void multiplexScanData(compact::scan_data::ScanData const& scanData);

  std::function<void(std::exception const&)> m_onError;

  std::optional<compact::TCPCompactStream<compact::scan_data::Parser, compact::scan_data::ScanData>> m_scanDataStream;
  std::optional<std::function<void(compact::scan_data::ScanData)>> m_onNewScanData;

  compact::PointCloudConverter m_pointCloudConverter;
  std::optional<std::function<void(PointCloud)>> m_onNewPointCloud;

  std::optional<compact::TCPCompactStream<compact::ambient_light::Parser, compact::ambient_light::AmbientLightData>> m_ambientLightStream;
  std::optional<compact::TCPCompactStream<compact::imu::Parser, compact::imu::ImuData>> m_imuStream;

  IpV4Address m_deviceAddress;

  std::optional<compact::scan_data::PackageLossMonitor> m_packageLossMonitor;
};

} // namespace sick
