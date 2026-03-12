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
#include <sick_perception_sdk/compact_format/telegram_type_2_imu/ImuData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_2_imu/ImuParser.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_3_ambient_light/AmbientLightData.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_3_ambient_light/AmbientLightParser.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/DataLossMonitor.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Data.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/MultiScan200Parser.hpp>
#include <sick_perception_sdk/compact_format/telegram_type_6_multiScan200/PointCloudConverter.hpp>
#include <sick_perception_sdk/drivers/TcpPacketReceiver.hpp>

#include <chrono>
#include <cstdint>
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
class SDK_EXPORT MultiScan200
{
public:
  static constexpr std::chrono::milliseconds kDefaultFirstDataTimeout = std::chrono::milliseconds(3000);
  static constexpr std::chrono::milliseconds kDefaultNewDataTimeout   = std::chrono::milliseconds(1000);

  class SDK_EXPORT AmbientLightReceiver
  {
  public:
    static constexpr std::uint16_t kDefaultPort = 2116;
    using DataCallback                          = std::function<void(compact::ambient_light::AmbientLightData)>;

    explicit AmbientLightReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError);
    void setup(
      std::uint16_t sensorPort                   = kDefaultPort,
      std::chrono::milliseconds firstDataTimeout = MultiScan200::kDefaultFirstDataTimeout,
      std::chrono::milliseconds newDataTimeout   = MultiScan200::kDefaultNewDataTimeout
    );
    void teardown();
    void setOnNewDataCallback(DataCallback callback);

  private:
    friend class MultiScan200;

    IpV4Address m_deviceAddress;
    std::function<void(std::exception_ptr)> m_onError;
    std::optional<compact::TcpPacketReceiver<compact::ambient_light::Parser, compact::ambient_light::AmbientLightData>> m_stream;
    std::optional<DataCallback> m_onNewData;
  };

  class SDK_EXPORT ImuReceiver
  {
  public:
    static constexpr std::uint16_t kDefaultPort = 2117;
    using DataCallback                          = std::function<void(compact::imu::ImuData)>;

    explicit ImuReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError);
    void setup(
      std::uint16_t sensorPort                   = kDefaultPort,
      std::chrono::milliseconds firstDataTimeout = MultiScan200::kDefaultFirstDataTimeout,
      std::chrono::milliseconds newDataTimeout   = MultiScan200::kDefaultNewDataTimeout
    );
    void teardown();
    void setOnNewDataCallback(DataCallback callback);

  private:
    friend class MultiScan200;

    IpV4Address m_deviceAddress;
    std::function<void(std::exception_ptr)> m_onError;
    std::optional<compact::TcpPacketReceiver<compact::imu::Parser, compact::imu::ImuData>> m_stream;
    std::optional<DataCallback> m_onNewData;
  };

  class SDK_EXPORT ScanDataReceiver
  {
  public:
    static constexpr std::uint16_t kDefaultPort = 2115;
    using DataLossCallback                      = std::function<void(compact::multiscan200::DataLossMonitor::LossCounts const&)>;
    using PointCloudCallback                    = std::function<void(MultiEchoPointCloud const&)>;
    using ScanDataCallback                      = std::function<void(compact::multiscan200::MultiScan200Data const&)>;

    explicit ScanDataReceiver(IpV4Address const& deviceAddress, std::function<void(std::exception_ptr)> const& onError);
    void setup(
      std::uint16_t sensorPort                   = kDefaultPort,
      std::chrono::milliseconds firstDataTimeout = MultiScan200::kDefaultFirstDataTimeout,
      std::chrono::milliseconds newDataTimeout   = MultiScan200::kDefaultNewDataTimeout
    );
    void teardown();
    void setDataLossMonitor(compact::multiscan200::DataLossMonitor monitor, DataLossCallback callback);
    void setOnNewFrameCallback(ScanDataCallback callback);
    void setOnNewFrameCallback(PointCloudCallback callback, PointCloudConfiguration const& pointCloudConfiguration = PointCloudConfiguration());

  private:
    friend class MultiScan200;

    IpV4Address m_deviceAddress;
    std::function<void(std::exception_ptr)> m_onError;
    std::optional<compact::TcpPacketReceiver<compact::multiscan200::Parser, compact::multiscan200::MultiScan200Data>> m_stream;
    std::optional<std::pair<compact::multiscan200::DataLossMonitor, DataLossCallback>> m_dataLoss;
    std::optional<ScanDataCallback> m_onNewData;
    std::optional<std::pair<compact::multiscan200::PointCloudConverter, PointCloudCallback>> m_pointCloud;

    void multiplexScanData(compact::multiscan200::MultiScan200Data const& data);
  };

  /**
   * @param deviceAddress The IP address of the MultiScan200 device to connect to
   * @param onError Callback function that is called when an unhandled exception is thrown
   */
  explicit MultiScan200(IpV4Address deviceAddress, std::function<void(std::exception_ptr)> const& onError = [](std::exception_ptr) -> void {});

  MultiScan200(MultiScan200 const&)                    = delete;
  auto operator=(MultiScan200 const&) -> MultiScan200& = delete;
  MultiScan200(MultiScan200&&)                         = delete;
  auto operator=(MultiScan200&&) -> MultiScan200&      = delete;

  ~MultiScan200();

  auto ambientLightReceiver() -> AmbientLightReceiver&
  {
    return m_ambientLightReceiver;
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
   * @brief Connects to the TCP server and listens for incoming data packets.
   *        Forwards the received packets to the onNewData callbacks.
   */
  void run();

  /**
   * @brief Stops receiving data. Call @ref run() to start receiving data again.
   */
  void stop();

private:
  AmbientLightReceiver m_ambientLightReceiver;
  ImuReceiver m_imuReceiver;
  ScanDataReceiver m_scanDataReceiver;
};

} // namespace sick
