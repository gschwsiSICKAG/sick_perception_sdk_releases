/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/drivers/PicoScan100.hpp>

#include <sick_perception_sdk/common/logging/logging.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/DataLossMonitor.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudCollector.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/ScanData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_2_imu/ImuData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_4_encoder/EncoderData.hpp>

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <exception>
#include <functional>
#include <optional>
#include <string>
#include <utility>

namespace sick {

PicoScan100::PicoScan100(std::function<void(std::exception_ptr)> const& onError)
  : m_encoderReceiver(onError)
  , m_imuReceiver(onError)
  , m_scanDataReceiver(onError)
{ }

PicoScan100::~PicoScan100()
{
  stop();
}

void PicoScan100::run()
{
  if (m_encoderReceiver.m_stream.has_value())
  {
    m_encoderReceiver.m_stream->start();
  }
  if (m_imuReceiver.m_stream.has_value())
  {
    m_imuReceiver.m_stream->start();
  }
  if (m_scanDataReceiver.m_stream.has_value())
  {
    m_scanDataReceiver.m_stream->start();
  }
}

void PicoScan100::stop()
{
  if (m_encoderReceiver.m_stream.has_value())
  {
    m_encoderReceiver.m_stream->stop();
  }
  if (m_imuReceiver.m_stream.has_value())
  {
    m_imuReceiver.m_stream->stop();
  }
  if (m_scanDataReceiver.m_stream.has_value())
  {
    m_scanDataReceiver.m_stream->stop();
  }
}

// --------------------------------------------------------------
// EncoderReceiver
// --------------------------------------------------------------
PicoScan100::EncoderReceiver::EncoderReceiver(std::function<void(std::exception_ptr)> const& onError)
  : m_onError(onError)
  , m_stream(std::nullopt)
  , m_onNewData(std::nullopt)
{ }

void PicoScan100::EncoderReceiver::setup(std::uint16_t receiverPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
{
  if (m_stream)
  {
    return;
  }
  constexpr std::size_t receiveBufferSize = 65'507;
  m_stream.emplace(
    receiverPort,
    receiveBufferSize,
    [&](compact::encoder::EncoderData const& encoderData) -> void {
      if (m_onNewData)
      {
        (*m_onNewData)(encoderData);
      }
    },
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "picoScan100 encoder on port " + std::to_string(receiverPort)
  );
}

void PicoScan100::EncoderReceiver::teardown()
{
  m_stream = std::nullopt;
}

void PicoScan100::EncoderReceiver::setOnNewDataCallback(std::function<void(compact::encoder::EncoderData)> callback)
{
  m_onNewData = std::move(callback);
}

// --------------------------------------------------------------
// ImuReceiver
// --------------------------------------------------------------
PicoScan100::ImuReceiver::ImuReceiver(std::function<void(std::exception_ptr)> const& onError)
  : m_onError(onError)
  , m_stream(std::nullopt)
  , m_onNewData(std::nullopt)
{ }

void PicoScan100::ImuReceiver::setup(std::uint16_t receiverPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
{
  if (m_stream)
  {
    return;
  }
  constexpr std::size_t kReceiveBufferSize = 65'507;
  m_stream.emplace(
    receiverPort,
    kReceiveBufferSize,
    [&](compact::imu::ImuData const& imuData) -> void {
      if (m_onNewData)
      {
        (*m_onNewData)(imuData);
      }
    },
    m_onError,
    firstDataTimeout,
    newDataTimeout,
    "picoScan100 IMU on port " + std::to_string(receiverPort)
  );
}

void PicoScan100::ImuReceiver::teardown()
{
  m_stream = std::nullopt;
}

void PicoScan100::ImuReceiver::setOnNewDataCallback(PicoScan100::ImuReceiver::DataCallback callback)
{
  m_onNewData = std::move(callback);
}

// --------------------------------------------------------------
// ScanDataReceiver
// --------------------------------------------------------------
PicoScan100::ScanDataReceiver::ScanDataReceiver(std::function<void(std::exception_ptr)> const& onError)
  : m_onError(onError)
  , m_stream(std::nullopt)
  , m_dataLoss(std::nullopt)
  , m_onNewSegmentScanData(std::nullopt)
  , m_framePointCloud(std::nullopt)
  , m_segmentPointCloud(std::nullopt)
{ }

void PicoScan100::ScanDataReceiver::multiplexScanData(compact::scan_data::ScanData const& scanData)
{
  if (m_dataLoss)
  {
    try
    {
      auto& [monitor, callback] = *m_dataLoss;
      auto const lossCounts     = monitor.check(scanData);
      if ((lossCounts.numberOfLostFrames != 0) || (lossCounts.numberOfLostTelegrams != 0) || (lossCounts.numberOfLostSegments != 0))
      {
        callback(lossCounts);
      }
    }
    catch (std::exception_ptr exception)
    {
      m_onError(exception);
    }
  }
  if (m_onNewSegmentScanData)
  {
    (*m_onNewSegmentScanData)(scanData);
  }
  if (m_segmentPointCloud)
  {
    m_segmentPointCloud->second(m_segmentPointCloud->first.convert(scanData));
  }
  if (m_framePointCloud)
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

    auto& collector = m_framePointCloud->first;  // No structured bindings because captured in lambda below.
    auto& callback  = m_framePointCloud->second; // No structured bindings because captured in lambda below.

    auto collectScanData = [&]() -> void {
      LOG_FAST_LOOP_INFO("picoScan100") << "Collecting segment with number " << scanData.modules.front().metaData.segmentIndex << " from frame "
                                        << scanData.modules.front().metaData.frameSequenceNumber << ".";
      collector.collect(scanData);
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
      LOG_FAST_LOOP_INFO("picoScan100") << "Frame changed. Calling the frame callback with the frame point cloud.";
      callback(collector.getPointCloud());
      collector.reset();
    }

    collectScanData();
  }
}

void PicoScan100::ScanDataReceiver::setup(std::uint16_t receiverPort, std::chrono::milliseconds firstDataTimeout, std::chrono::milliseconds newDataTimeout)
{
  if (m_stream)
  {
    return;
  }

  constexpr std::size_t kReceiveBufferSize = 65'507;
  m_stream.emplace(
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

void PicoScan100::ScanDataReceiver::teardown()
{
  m_stream = std::nullopt;
}

void PicoScan100::ScanDataReceiver::setDataLossMonitor(compact::scan_data::DataLossMonitor monitor, DataLossCallback callback)
{
  m_dataLoss = std::make_pair(std::move(monitor), std::move(callback));
}

void PicoScan100::ScanDataReceiver::setOnNewFrameCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration)
{
  m_framePointCloud = std::make_pair(compact::scan_data::PointCloudCollector(pointCloudConfiguration), std::move(callback));
}

void PicoScan100::ScanDataReceiver::setOnNewSegmentCallback(ScanDataCallback callback)
{
  m_onNewSegmentScanData = std::move(callback);
}

void PicoScan100::ScanDataReceiver::setOnNewSegmentCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration)
{
  m_segmentPointCloud = std::make_pair(compact::scan_data::PointCloudConverter(pointCloudConfiguration), std::move(callback));
}

} // namespace sick
