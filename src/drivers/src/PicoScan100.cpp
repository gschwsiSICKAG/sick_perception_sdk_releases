/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/drivers/PicoScan100.hpp>

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_receiver/EncoderData.hpp>
#include <sick_perception_sdk/compact_receiver/ImuData.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloud.hpp>
#include <sick_perception_sdk/compact_receiver/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_receiver/ScanData.hpp>

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <functional>
#include <string>
#include <utility>

namespace sick {

PicoScan100::PicoScan100(std::function<void(std::exception)> onError)
  : m_lastFrameSequenceNumber(0)
  , m_onError(std::move(onError))
{ }

PicoScan100::~PicoScan100()
{
  stop();
}

void PicoScan100::multiplexScanData(compact::scan_data::ScanData const& scanData)
{
  if (m_onNewScanData)
  {
    if (m_packageLossMonitor)
    {
      m_packageLossMonitor->check(scanData);
    }
    (*m_onNewScanData)(scanData);
  }
  if (m_onNewPointCloud)
  {
    (*m_onNewPointCloud)(m_pointCloudConverter.convert(scanData));
  }
  if (m_onNewFullFrame)
  {
    if (scanData.modules.empty())
    {
      LOG_WARNING("picoScan100") << "Received segment with no modules. Cannot deduce the frame number.";
      return;
    }

    if (!m_lastFrameSequenceNumber)
    {
      m_lastFrameSequenceNumber = scanData.modules.front().metaData.frameSequenceNumber;
      return;
    }

    auto collectScanData = [&]() -> void {
      LOG_FAST_LOOP_INFO("picoScan100") << "Collecting segment with number " << scanData.modules.front().metaData.segmentIndex << " from frame "
                                        << scanData.modules.front().metaData.frameSequenceNumber << ".";
      m_pointCloudCollector.collect(scanData);
    };

    bool const frameChanged   = (*m_lastFrameSequenceNumber != scanData.modules.front().metaData.frameSequenceNumber);
    m_lastFrameSequenceNumber = scanData.modules.front().metaData.frameSequenceNumber;

    if (!m_firstFrameChangeDetected && frameChanged)
    {
      m_firstFrameChangeDetected = true;
      LOG_INFO("picoScan100") << "First frame change detected. Starting to collect segments.";
      collectScanData();
      return;
    }

    if (frameChanged)
    {
      LOG_FAST_LOOP_INFO("picoScan100") << "Frame changed. Calling the m_onNewFullFrame callback with the full frame point cloud.";
      (*m_onNewFullFrame)(m_pointCloudCollector.getPointCloud());
      m_pointCloudCollector.reset();
    }

    collectScanData();
  }
}

void PicoScan100::enableScanDataStream(std::uint16_t receiverPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
{
  if (m_scanDataStream)
  {
    return;
  }

  constexpr std::size_t kReceiveBufferSize = 65'507;
  m_scanDataStream.emplace(
    receiverPort,
    kReceiveBufferSize,
    [&](compact::scan_data::ScanData const& scanData) -> void {
      multiplexScanData(scanData);
    },
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "picoScan100 scan data on port " + std::to_string(receiverPort)
  );
}

void PicoScan100::setOnNewScanData(
  std::function<void(compact::scan_data::ScanData)> onNewScanData,
  std::uint16_t receiverPort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  m_onNewScanData = std::move(onNewScanData);
  enableScanDataStream(receiverPort, firstDataTimeout, newDataTimeout);
}

void PicoScan100::setOnNewPointCloud(
  PointCloudConfiguration pointCloudConfiguration,
  std::function<void(PointCloud)> onNewPointCloud,
  std::uint16_t receiverPort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  m_pointCloudConverter = compact::PointCloudConverter(std::move(pointCloudConfiguration));
  m_onNewPointCloud     = std::move(onNewPointCloud);
  enableScanDataStream(receiverPort, firstDataTimeout, newDataTimeout);
}

void PicoScan100::setOnNewFullFrame(
  PointCloudConfiguration pointCloudConfiguration,
  std::function<void(PointCloud)> onNewFullFrame,
  std::uint16_t receiverPort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  m_pointCloudCollector = compact::PointCloudCollector(std::move(pointCloudConfiguration));
  m_onNewFullFrame      = std::move(onNewFullFrame);
  enableScanDataStream(receiverPort, firstDataTimeout, newDataTimeout);
}

void PicoScan100::setOnNewImuData(
  std::function<void(compact::imu::ImuData)> onNewImu,
  std::uint16_t receiverPort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  constexpr std::size_t kReceiveBufferSize = 65'507;
  m_imuStream.emplace(
    receiverPort,
    kReceiveBufferSize,
    std::move(onNewImu),
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "picoScan100 IMU on port " + std::to_string(receiverPort)
  );
}

void PicoScan100::setOnNewEncoderData(
  std::function<void(compact::encoder::EncoderData)> onNewEncoder,
  std::uint16_t receiverPort,
  std::chrono::milliseconds firstDataTimeout,
  std::chrono::milliseconds newDataTimeout
)
{
  constexpr std::size_t receiveBufferSize = 65'507;
  m_encoderStream.emplace(
    receiverPort,
    receiveBufferSize,
    std::move(onNewEncoder),
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "picoScan100 encoder on port " + std::to_string(receiverPort)
  );
}

void PicoScan100::run()
{
  if (m_scanDataStream)
  {
    m_scanDataStream->start();
  }
  if (m_imuStream)
  {
    m_imuStream->start();
  }
  if (m_encoderStream)
  {
    m_encoderStream->start();
  }
}

void PicoScan100::stop()
{
  if (m_scanDataStream)
  {
    m_scanDataStream->stop();
  }
  if (m_imuStream)
  {
    m_imuStream->stop();
  }
  if (m_encoderStream)
  {
    m_encoderStream->stop();
  }
}

void PicoScan100::setPackageLossMonitor(compact::scan_data::PackageLossMonitor monitor)
{
  m_packageLossMonitor = std::move(monitor);
}

} // namespace sick
