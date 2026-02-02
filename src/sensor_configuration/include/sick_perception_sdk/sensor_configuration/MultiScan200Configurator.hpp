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
#include <sick_perception_sdk/sensor_configuration/api/UserLevel.hpp>
#include <sick_perception_sdk/sensor_configuration/api/json/multiScan200.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200.g.hpp>

#include <chrono>
#include <cstdint>
#include <memory>
#include <string>

namespace sick {

/**
 * @brief Convenience functions for configuring multiScan200 sensors.
 *
 * This class provides access to common configuration parameters and methods with a consistent naming scheme.
 * Internally, all parameters are mapped to generated data objects in namespace sick::srt::multiScan200.
 *
 * See SensorConfigurator for a more detailed description of the design principles.
 */
class SDK_EXPORT MultiScan200Configurator : public SensorConfigurator
{
public:
  enum class AmbientLightPixelCountVertical
  {
    Full     = 0,
    Matching = 1,
  };

  struct HorizontalAngleRangeFilterSettings
  {
    Angle start;
    Angle end;
    NumericRange<1, 50, 1> indexIncrement;
  };

  enum class BloomingFilterStrength
  {
    Low    = 0,
    Medium = 1,
    Strong = 2
  };

  struct BloomingFilterSettings
  {
    bool isEnabled;
    BloomingFilterStrength strength;
  };

  enum class EchoFilterSetting
  {
    FirstEcho               = 0,
    AllEchoes               = 1,
    StrongestEcho           = 3,
    AllEchoesStrongestFirst = 4
  };

  enum class IPAddressingMode
  {
    StaticIP = 0,
    DHCP     = 1,
  };

  enum class Sensitivity
  {
    OptimizedForRobustness   = 0,
    Standard                 = 1,
    OptimizedForLowRemission = 2,
  };

  enum class StreamingMode
  {
    Disabled   = 0,
    Compact    = 1,
    NativeROS2 = 2,
  };

  enum class PerformanceProfile
  {
    Allrounder          = 0,
    VerticalSharpness   = 11,
    HorizontalSharpness = 12,
    Sharpness2          = 13,
    MaxTemperature1     = 21,
    MaxTemperature2     = 22,
  };

  struct VerticalAngleRangeFilterSettings
  {
    Angle outerStart;
    Angle outerEnd;
    NumericRange<1, 50, 2> outerIndexIncrement;
    Angle innerStart;
    Angle innerEnd;
    NumericRange<1, 50, 1> innerIndexIncrement;
  };

public:
  struct BloomingFilterAccess
    : public GetAccess<BloomingFilterSettings>
    , public EnableAccess<BloomingFilterStrength>
    , public DisableAccess<BloomingFilterStrength>
    , public IsEnabledAccess<BloomingFilterSettings>
  {
    explicit BloomingFilterAccess(SensorConfigurator const& configurator)
      : GetAccess<BloomingFilterSettings>(configurator)
      , EnableAccess<BloomingFilterStrength>(configurator)
      , DisableAccess<BloomingFilterStrength>(configurator)
      , IsEnabledAccess<BloomingFilterSettings>(configurator)
    { }
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

  class HorizontalAngleRangeFilterAccess
    : public GetAccess<HorizontalAngleRangeFilterSettings>
    , public EnableAccess<HorizontalAngleRangeFilterSettings>
    , public DisableAccess<HorizontalAngleRangeFilterSettings>
    , public IsEnabledAccess<HorizontalAngleRangeFilterSettings>
  {
  public:
    explicit HorizontalAngleRangeFilterAccess(SensorConfigurator const& configurator)
      : GetAccess<HorizontalAngleRangeFilterSettings>(configurator)
      , EnableAccess<HorizontalAngleRangeFilterSettings>(configurator)
      , DisableAccess<HorizontalAngleRangeFilterSettings>(configurator)
      , IsEnabledAccess<HorizontalAngleRangeFilterSettings>(configurator)
    { }
  };

  class SDK_EXPORT IntervalFilterAccess
  {
  public:
    explicit IntervalFilterAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> NumericRange<2, 50, 2>;
    auto enable(NumericRange<2, 50, 2> value) const -> void;
    auto disable() const -> void;
    auto isEnabled() const -> bool;

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

  class VerticalAngleRangeFilterAccess
    : public GetAccess<VerticalAngleRangeFilterSettings>
    , public EnableAccess<VerticalAngleRangeFilterSettings>
    , public DisableAccess<VerticalAngleRangeFilterSettings>
    , public IsEnabledAccess<VerticalAngleRangeFilterSettings>
  {
  public:
    explicit VerticalAngleRangeFilterAccess(SensorConfigurator const& configurator)
      : GetAccess<VerticalAngleRangeFilterSettings>(configurator)
      , EnableAccess<VerticalAngleRangeFilterSettings>(configurator)
      , DisableAccess<VerticalAngleRangeFilterSettings>(configurator)
      , IsEnabledAccess<VerticalAngleRangeFilterSettings>(configurator)
    { }
  };

  class SDK_EXPORT HorizontalFieldOfViewStartAngleAccess
  {
  public:
    explicit HorizontalFieldOfViewStartAngleAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> Angle;
    void set(Angle const& angle) const;

  private:
    SensorConfigurator const& m_configurator;
  };

  class SDK_EXPORT SensorPositionAccess
  {
  public:
    explicit SensorPositionAccess(SensorConfigurator const& configurator)
      : m_configurator(configurator)
    { }

    auto get() const -> SensorPosition;
    void set(SensorPosition const& value) const;

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
    auto set(std::chrono::microseconds timeSinceEpoch) const -> srt::multiScan200::LSPsetdatetime::Post::Response::ErrorCode;

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
      srt::multiScan200::TSCTCtimezone::Post::Request::TSCTCtimezone timeZone,
      std::chrono::duration<int> updateInterval
    ) const;
    void enablePtp() const;

  private:
    SensorConfigurator const& m_configurator;
  };

public:
  explicit MultiScan200Configurator(std::shared_ptr<IHttpClient> httpClient, UserLevel userLevel, std::string password);
  ~MultiScan200Configurator() = default;

  GetSetAccess<AmbientLightPixelCountVertical> const ambientLightPixelCountVertical;

  BloomingFilterAccess const bloomingFilter;

  DeviceTemperatureAccess const sensorTemperature;

  GetAccess<srt::multiScan200::DeviceStatus::Get::Response::DeviceStatus> const deviceState;

  DeviceTypeAccess const deviceType;

  IPAddressAccess const sensorIPAddress;

  GetSetAccess<IPAddressingMode> const sensorIPAddressingMode;

  IPMaskAccess const sensorIPMask;

  IPGatewayAccess const sensorIPGateway;

  EthernetUpdateAccess const ethernetUpdate;

  GetSetAccess<EchoFilterSetting> const echoFilter;

  FirmwareVersionAccess const firmwareVersion;

  HorizontalAngleRangeFilterAccess const horizontalAngleRangeFilter;

  HorizontalFieldOfViewStartAngleAccess const horizontalFieldOfViewStartAngle;

  IntervalFilterAccess const intervalFilter;

  LocationNameAccess const locationName;

  OrderNumberAccess const orderNumber;

  GetSetAccess<PerformanceProfile> const performanceProfile;

  GetSetAccess<Sensitivity> const sensitivity;

  SensorPositionAccess const sensorPosition;

  SerialNumberAccess const serialNumber;

  GetSetAccess<StreamingMode> const streaming;

  /**
   * @brief Access to the current system time of the sensor. The system time is represented as a duration since the
   * sensor's epoch (Unix epoch).
   */
  SystemTimeAccess const systemTime;

  TimeSynchronizationAccess const timeSynchronization;

  VerticalAngleRangeFilterAccess const verticalAngleRangeFilter;

  // Device methods
  void factoryReset() const;
  void findMe(Duration const& activateFor) const;
  void reboot() const;
  void startMeasurement() const;
  void stopMeasurement() const;
  void persistParametersOnDevice() const;
};

} // namespace sick
