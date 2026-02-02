/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#pragma once

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/common/quantities/Temperature.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/IHttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/SensorConfigurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/FieldEvaluationContour.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/UserLevel.hpp>
#include <sick_perception_sdk/sensor_configuration/api/json/LRS4000.g.hpp>

#include <chrono>
#include <cstdint>
#include <memory>
#include <string>

namespace sick {

/**
 * @brief Convenience functions for configuring LRS4000 sensors.
 *
 * This class provides access to common configuration parameters and methods with a consistent naming scheme.
 * Internally, all parameters are mapped to generated data objects in namespace sick::srt::LRS4000.
 *
 * See SensorConfigurator for a more detailed description of the design principles.
 */
class SDK_EXPORT LRS4000Configurator : public SensorConfigurator
{
public:
  enum class EchoFilterSetting
  {
    FirstEcho = 0,
    AllEchoes = 1,
    LastEcho  = 2,
  };

  enum class IPAddressingMode
  {
    StaticIP = 0,
    DHCP     = 1,
  };

  enum class StreamingMode
  {
    Disabled    = 0,
    Compact     = 2,
    LMDscandata = 3,
  };

  class SDK_EXPORT DeviceTemperatureAccess
  {
  public:
    explicit DeviceTemperatureAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> Temperature;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT DeviceTypeAccess
  {
  public:
    explicit DeviceTypeAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> std::string;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT IPAddressAccess
  {
  public:
    explicit IPAddressAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> IpV4Address;
    void set(IpV4Address const& ipAddress) const;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT IPMaskAccess
  {
  public:
    explicit IPMaskAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> IpV4Address;
    void set(IpV4Address const& ipMask) const;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT IPGatewayAccess
  {
  public:
    explicit IPGatewayAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> IpV4Address;
    void set(IpV4Address const& ipGateway) const;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT EthernetUpdateAccess
  {
  public:
    explicit EthernetUpdateAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    void apply() const;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT FirmwareVersionAccess
  {
  public:
    explicit FirmwareVersionAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> std::string;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT LocationNameAccess
  {
  public:
    explicit LocationNameAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> std::string;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT OrderNumberAccess
  {
  public:
    explicit OrderNumberAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> std::string;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT SerialNumberAccess
  {
  public:
    explicit SerialNumberAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> std::string;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT SystemTimeAccess
  {
  public:
    explicit SystemTimeAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> std::chrono::microseconds;

  private:
    SensorConfigurator const& m_configurator;
  };

  struct TimeSynchronizationAccess
  {
  public:
    explicit TimeSynchronizationAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    void disable() const;
    void enableNtp(
      IpV4Address const& ntpServerAddress,
      srt::LRS4000::TSCTCtimezone::Post::Request::TSCTCtimezone timeZone,
      std::chrono::duration<int> updateInterval
    ) const;
    void enablePtp() const;

  private:
    SensorConfigurator const& m_configurator;
  };

  //Field Evaluation
  class SDK_EXPORT FieldEvaluationGroupStateAccess
  {
  public:
    explicit FieldEvaluationGroupStateAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> std::array<int, 48>;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT FieldEvaluationResultAccess
  {
  public:
    explicit FieldEvaluationResultAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> srt::LRS4000::FieldEvaluationResult::Get::Response::FieldEvaluationResult;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT FieldEvaluationContourAccess
  {
  public:
    explicit FieldEvaluationContourAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    void set(int evaluationId, FieldEvaluationContour const& contour) const;
    auto get(int evaluationId) const -> std::vector<FieldEvaluationContour>;

  private:
    SensorConfigurator const& m_configurator;
  };

public:
  explicit LRS4000Configurator(std::shared_ptr<IHttpClient> httpClient, UserLevel userLevel, std::string const& password);
  ~LRS4000Configurator() = default;

  DeviceTemperatureAccess const sensorTemperature;

  GetAccess<srt::LRS4000::DeviceStatus::Get::Response::DeviceStatus> const deviceState;

  DeviceTypeAccess const deviceType;

  IPAddressAccess const sensorIPAddress;

  GetSetAccess<IPAddressingMode> const sensorIPAddressingMode;

  IPMaskAccess const sensorIPMask;

  IPGatewayAccess const sensorIPGateway;

  EthernetUpdateAccess const ethernetUpdate;

  GetSetAccess<EchoFilterSetting> const echoFilter;

  FirmwareVersionAccess const firmwareVersion;

  LocationNameAccess const locationName;

  OrderNumberAccess const orderNumber;

  SerialNumberAccess const serialNumber;

  GetSetAccess<StreamingMode> const streaming;

  // 2D Object Detection - Field Evaluation

  FieldEvaluationGroupStateAccess const fieldEvaluationGroupState;

  FieldEvaluationResultAccess const fieldEvaluationResult;

  FieldEvaluationContourAccess const fieldEvaluationContour;

  /**
   * @brief Access to the current system time of the sensor. The system time is represented as a duration since the
   * sensor's epoch (Unix epoch).
   */
  SystemTimeAccess const systemTime;

  TimeSynchronizationAccess const timeSynchronization;

  // Device methods
  void factoryReset() const;
  void findMe(Duration const& activateFor) const;
  void reboot() const;
  void startMeasurement() const;
  void persistParametersOnDevice() const;
};

} // namespace sick
