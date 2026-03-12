/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once
#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/logging/LogLevel.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/MultiEchoPointCloud.hpp>
#include <sick_perception_sdk/compact_format/PointCloud/PointCloudConfiguration.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/DataLossMonitor.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/PointCloudConverter.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/ScanData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_1_scan_data/ScanDataParser.hpp>
#include <sick_perception_sdk/drivers/TcpPacketReceiver.hpp>

#include <chrono>
#include <cstdint>
#include <functional>
#include <string>
#include <utility>

namespace sick {

/**
 * @ingroup Drivers
 * 
 * See drivers.hpp for an overview.
 */
class SDK_EXPORT LRS4000
{
public:
  static constexpr std::chrono::milliseconds kDefaultFirstDataTimeout = std::chrono::milliseconds(3000);
  static constexpr std::chrono::milliseconds kDefaultNewDataTimeout   = std::chrono::milliseconds(1000);

  class SDK_EXPORT ScanDataReceiver
  {
  public:
    static constexpr std::uint16_t kDefaultPort = 2115;
    using DataLossCallback                      = std::function<void(compact::scan_data::DataLossMonitor::LossCounts const&)>;
    using PointCloudCallback                    = std::function<void(MultiEchoPointCloud const&)>;
    using ScanDataCallback                      = std::function<void(compact::scan_data::ScanData const&)>;

    explicit ScanDataReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError);
    void setup(
      std::uint16_t sensorPort                   = kDefaultPort,
      std::chrono::milliseconds firstDataTimeout = LRS4000::kDefaultFirstDataTimeout,
      std::chrono::milliseconds newDataTimeout   = LRS4000::kDefaultNewDataTimeout
    );
    void teardown();
    void setDataLossMonitor(compact::scan_data::DataLossMonitor monitor, DataLossCallback callback);
    void setOnNewFrameCallback(ScanDataCallback callback);
    void setOnNewFrameCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration = PointCloudConfiguration());

  private:
    friend class LRS4000;

    IpV4Address m_deviceAddress;
    std::function<void(std::exception_ptr)> m_onError;
    std::optional<compact::TcpPacketReceiver<compact::scan_data::Parser, compact::scan_data::ScanData>> m_stream;
    std::optional<std::pair<compact::scan_data::DataLossMonitor, DataLossCallback>> m_dataLoss;
    std::optional<ScanDataCallback> m_onNewData;
    std::optional<std::pair<compact::scan_data::PointCloudConverter, PointCloudCallback>> m_pointCloud;

    void multiplexScanData(compact::scan_data::ScanData const& scanData);
  };

  /**
   * @param deviceAddress The IP address of the LRS4000 device to connect to
   * @param onError Callback function that is called when an unhandled exception is thrown
   */
  explicit LRS4000(IpV4Address deviceAddress, std::function<void(std::exception_ptr)> const& onError = [](std::exception_ptr) -> void {});

  LRS4000(LRS4000 const&)                    = delete;
  auto operator=(LRS4000 const&) -> LRS4000& = delete;
  LRS4000(LRS4000&&)                         = delete;
  auto operator=(LRS4000&&) -> LRS4000&      = delete;

  ~LRS4000();

  auto scanDataReceiver() -> ScanDataReceiver&
  {
    return m_scanDataReceiver;
  }

  /**
   * @brief Connects to the TCP server and listens for incoming data packets.
   *        Forwards the received packets to the onNewData callbacks.
   */
  void run();

  /**
   * @brief Stops receiving data. Call @ref run() to start receiving data again.
   */
  void stop();

private:
  ScanDataReceiver m_scanDataReceiver;
};

} // namespace sick
