/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/logging/LogLevel.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/DataLossMonitor.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudCollector.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudConverter.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/ScanData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/ScanDataParser.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_2_imu/ImuData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_2_imu/ImuParser.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_4_encoder/EncoderData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_4_encoder/EncoderParser.hpp>
#include <sick_perception_sdk/drivers/UdpPacketReceiver.hpp>

#include <functional>
#include <optional>
#include <string>
#include <utility>

namespace sick {

/**
 * @ingroup Drivers
 * 
 * See drivers.hpp for an overview.
 */
class SDK_EXPORT PicoScan100
{
public:
  static constexpr std::chrono::milliseconds kDefaultFirstDataTimeout = std::chrono::milliseconds(3000);
  static constexpr std::chrono::milliseconds kDefaultNewDataTimeout   = std::chrono::milliseconds(1000);

  class SDK_EXPORT EncoderReceiver
  {
  public:
    static constexpr std::uint16_t kDefaultPort = 7504;
    using DataCallback                          = std::function<void(compact::encoder::EncoderData)>;

    explicit EncoderReceiver(std::function<void(std::exception_ptr)> const& onError);
    void setup(
      std::uint16_t receiverPort                 = kDefaultPort,
      std::chrono::milliseconds firstDataTimeout = PicoScan100::kDefaultFirstDataTimeout,
      std::chrono::milliseconds newDataTimeout   = PicoScan100::kDefaultNewDataTimeout
    );
    void teardown();
    void setOnNewDataCallback(DataCallback callback);

  private:
    friend class PicoScan100;

    std::function<void(std::exception_ptr)> m_onError;
    std::optional<compact::UdpPacketReceiver<compact::encoder::Parser, compact::encoder::EncoderData>> m_stream;
    std::optional<DataCallback> m_onNewData;
  };

  class SDK_EXPORT ImuReceiver
  {
  public:
    static constexpr std::uint16_t kDefaultPort = 7503;
    using DataCallback                          = std::function<void(compact::imu::ImuData)>;

    explicit ImuReceiver(std::function<void(std::exception_ptr)> const& onError);
    void setup(
      std::uint16_t receiverPort                 = kDefaultPort,
      std::chrono::milliseconds firstDataTimeout = PicoScan100::kDefaultFirstDataTimeout,
      std::chrono::milliseconds newDataTimeout   = PicoScan100::kDefaultNewDataTimeout
    );
    void teardown();
    void setOnNewDataCallback(DataCallback callback);

  private:
    friend class PicoScan100;

    std::function<void(std::exception_ptr)> m_onError;
    std::optional<compact::UdpPacketReceiver<compact::imu::Parser, compact::imu::ImuData>> m_stream;
    std::optional<DataCallback> m_onNewData;
  };

  class SDK_EXPORT ScanDataReceiver
  {
  public:
    static constexpr std::uint16_t kDefaultPort = 2115;
    using DataLossCallback                      = std::function<void(compact::scan_data::DataLossMonitor::LossCounts const&)>;
    using PointCloudCallback                    = std::function<void(MultiEchoPointCloud const&)>;
    using ScanDataCallback                      = std::function<void(compact::scan_data::ScanData const&)>;

    explicit ScanDataReceiver(std::function<void(std::exception_ptr)> const& onError);
    void setup(
      std::uint16_t receiverPort                 = kDefaultPort,
      std::chrono::milliseconds firstDataTimeout = PicoScan100::kDefaultFirstDataTimeout,
      std::chrono::milliseconds newDataTimeout   = PicoScan100::kDefaultNewDataTimeout
    );
    void teardown();
    void setDataLossMonitor(compact::scan_data::DataLossMonitor monitor, DataLossCallback callback);
    void setOnNewFrameCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration = PointCloudConfiguration());
    void setOnNewSegmentCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration = PointCloudConfiguration());
    void setOnNewSegmentCallback(ScanDataCallback callback);

  private:
    friend class PicoScan100;

    std::function<void(std::exception_ptr)> m_onError;
    std::optional<compact::UdpPacketReceiver<compact::scan_data::Parser, compact::scan_data::ScanData>> m_stream;
    std::optional<std::pair<compact::scan_data::DataLossMonitor, DataLossCallback>> m_dataLoss;
    std::optional<ScanDataCallback> m_onNewSegmentScanData;
    std::optional<std::pair<compact::scan_data::PointCloudCollector, PointCloudCallback>> m_framePointCloud;
    std::optional<std::pair<compact::scan_data::PointCloudConverter, PointCloudCallback>> m_segmentPointCloud;
    std::optional<std::uint64_t> m_lastFrameSequenceNumber;
    bool m_firstFrameChangeDetected = false;

    void multiplexScanData(compact::scan_data::ScanData const& data);
  };

  /** @param onError Callback function that is called when an unhandled exception is thrown */
  explicit PicoScan100(std::function<void(std::exception_ptr)> const& onError = [](std::exception_ptr) -> void {});

  PicoScan100(PicoScan100 const&)                    = delete;
  auto operator=(PicoScan100 const&) -> PicoScan100& = delete;
  PicoScan100(PicoScan100&&)                         = delete;
  auto operator=(PicoScan100&&) -> PicoScan100&      = delete;

  ~PicoScan100();

  auto encoderReceiver() -> EncoderReceiver&
  {
    return m_encoderReceiver;
  }

  auto imuReceiver() -> ImuReceiver&
  {
    return m_imuReceiver;
  }

  auto scanDataReceiver() -> ScanDataReceiver&
  {
    return m_scanDataReceiver;
  }

  /**
   * @brief Listens for incoming data packets.
   *        Forwards the received packets to the onNewData callbacks.
   */
  void run();

  /**
   * @brief Stops receiving data. Call @ref run() to start receiving data again.
   */
  void stop();

private:
  EncoderReceiver m_encoderReceiver;
  ImuReceiver m_imuReceiver;
  ScanDataReceiver m_scanDataReceiver;
};

} // namespace sick
