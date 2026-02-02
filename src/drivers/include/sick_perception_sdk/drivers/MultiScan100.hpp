/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/logging/LogLevel.hpp>
#include <sick_perception_sdk/compact_receiver/EncoderData.hpp>
#include <sick_perception_sdk/compact_receiver/EncoderParser.hpp>
#include <sick_perception_sdk/compact_receiver/ImuData.hpp>
#include <sick_perception_sdk/compact_receiver/ImuParser.hpp>
#include <sick_perception_sdk/compact_receiver/PackageLossMonitor.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudCollector.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConverter.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>
#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>
#include <sick_perception_sdk/compact_receiver/UdpCompactStream.hpp>

#include <functional>
#include <optional>
#include <string>

namespace sick {

//! \brief This class listens for data packets of the multiScan100 in a non-blocking manner.
class SDK_EXPORT MultiScan100
{
public:
  //! @param onError Callback function that is called when an unhandled exception is thrown
  MultiScan100(std::function<void(std::exception)> onError = [](std::exception) {});

  ~MultiScan100();

  //! \param onNewScanData Callback function that is called when new scan data is received and parsed
  //! \param receiverPort The port on which to listen for incoming UDP packets. Listens on all interfaces.
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewScanData(
    std::function<void(compact::scan_data::ScanData)> onNewScanData,
    std::uint16_t receiverPort                 = 2115,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \param pointCloudConfiguration The configuration for the point cloud
  //! \param onNewPointCloud Callback function that is called when a new point cloud is available
  //! \param receiverPort The port on which to listen for incoming UDP packets. Listens on all interfaces.
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewPointCloud(
    PointCloudConfiguration pointCloudConfiguration,
    std::function<void(PointCloud)> onNewPointCloud,
    std::uint16_t receiverPort                 = 2115,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \param pointCloudConfiguration The configuration for the point cloud
  //! \param onNewFullFrame Callback function that is called when a new full frame point cloud is available
  //! \param receiverPort The port on which to listen for incoming UDP packets. Listens on all interfaces.
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewFullFrame(
    PointCloudConfiguration pointCloudConfiguration,
    std::function<void(PointCloud)> onNewFullFrame,
    std::uint16_t receiverPort                 = 2115,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \param onNewImu Callback function that is called when new IMU data is received and parsed
  //! \param receiverPort The port on which to listen for incoming UDP packets. Listens on all interfaces.
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewImuData(
    std::function<void(compact::imu::ImuData)> onNewImu,
    std::uint16_t receiverPort                 = 2117,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \param onNewEncoder Callback function that is called when new encoder data is received and parsed
  //! \param receiverPort The port on which to listen for incoming UDP packets. Listens on all interfaces.
  //! \param firstDataTimeout If more time has passed than specified since the stream was started without receiving
  //! any data, an exception is raised. A value of 0 means no timeout.
  //! \param newDataTimeout If more time has passed than specified without receiving any data after the first data was
  //! received, an exception is raised. A value of 0 means no timeout.
  void setOnNewEncoderData(
    std::function<void(compact::encoder::EncoderData)> onNewEncoder,
    std::uint16_t receiverPort                 = 2118,
    std::chrono::milliseconds firstDataTimeout = std::chrono::milliseconds(3000),
    std::chrono::milliseconds newDataTimeout   = std::chrono::milliseconds(1000)
  );

  //! \brief Listens for incoming data packets.
  //!        Forwards the received packets to the onNewData callbacks.
  void run();

  void stop();

  //! \brief Set a PackageLossMonitor to detect losses of telegrams, frames or segments.
  //!        If the callback from PackageLossMonitor is needed, set it before calling this function.
  void setPackageLossMonitor(compact::scan_data::PackageLossMonitor monitor);

private:
  void enableScanDataStream(std::uint16_t receiverPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout);
  void multiplexScanData(compact::scan_data::ScanData const& scanData);
  std::optional<compact::UdpCompactStream<compact::scan_data::Parser, compact::scan_data::ScanData>> m_scanDataStream;
  std::optional<compact::UdpCompactStream<compact::imu::Parser, compact::imu::ImuData>> m_imuStream;
  std::optional<compact::UdpCompactStream<compact::encoder::Parser, compact::encoder::EncoderData>> m_encoderStream;

  std::function<void(std::exception const&)> m_onError;

  std::optional<std::function<void(compact::scan_data::ScanData)>> m_onNewScanData;

  compact::PointCloudConverter m_pointCloudConverter;
  std::optional<std::function<void(PointCloud)>> m_onNewPointCloud;

  std::optional<std::uint64_t> m_lastFrameSequenceNumber;
  bool m_firstFrameChangeDetected = false;
  compact::PointCloudCollector m_pointCloudCollector;
  std::optional<std::function<void(PointCloud)>> m_onNewFullFrame;
  std::optional<compact::scan_data::PackageLossMonitor> m_packageLossMonitor;
};

} // namespace sick
