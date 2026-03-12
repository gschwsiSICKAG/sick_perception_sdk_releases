/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/sensor_configuration/MultiScan200Configurator.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Angle.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/common/quantities/Temperature.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/IHttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/SensorConfigurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>
#include <sick_perception_sdk/sensor_configuration/api/SensorPosition.hpp>
#include <sick_perception_sdk/sensor_configuration/api/SrtRest.hpp>
#include <sick_perception_sdk/sensor_configuration/api/UserLevel.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200.g.hpp>

#include <array>
#include <chrono>
#include <cstdint>
#include <memory>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers): magic numbers occur for many
// configuration parameters and result from generated code

namespace sick {

MultiScan200Configurator::MultiScan200Configurator(std::shared_ptr<IHttpClient> httpClient, UserLevel userLevel, std::string password)
  : SensorConfigurator(std::move(httpClient), userLevel, std::move(password))
  , ambientLightPixelCountVertical(*this)
  , bloomingFilter(*this)
  , contaminationConfig(*this)
  , contaminationData(*this)
  , contaminationResult(*this)
  , sensorTemperature(*this)
  , deviceState(*this)
  , deviceType(*this)
  , echoFilter(*this)
  , sensorIPAddress(*this)
  , sensorIPAddressingMode(*this)
  , sensorIPMask(*this)
  , sensorIPGateway(*this)
  , ethernetUpdate(*this)
  , firmwareVersion(*this)
  , horizontalAngleRangeFilter(*this)
  , horizontalFieldOfViewStartAngle(*this)
  , intervalFilter(*this)
  , locationName(*this)
  , orderNumber(*this)
  , performanceProfile(*this)
  , sensitivity(*this)
  , sensorPosition(*this)
  , serialNumber(*this)
  , streaming(*this)
  , systemTime(*this)
  , timeSynchronization(*this)
  , verticalAngleRangeFilter(*this)
{ }

using C = MultiScan200Configurator;

// AmbientLightPixelCountVertical
template <>
auto SDK_EXPORT C::GetAccess<C::AmbientLightPixelCountVertical>::get() const -> C::AmbientLightPixelCountVertical
{
  return static_cast<C::AmbientLightPixelCountVertical>(m_configurator.readVariable<srt::multiScan200::ambientPixelCountVertical>()._ambientPixelCountVertical);
}

template <>
void SDK_EXPORT C::SetAccess<C::AmbientLightPixelCountVertical>::set(C::AmbientLightPixelCountVertical value) const
{
  srt::multiScan200::ambientPixelCountVertical::Post::Request const request {
    static_cast<srt::multiScan200::ambientPixelCountVertical::Post::Request::ambientPixelCountVertical>(value)
  };
  m_configurator.writeVariable<srt::multiScan200::ambientPixelCountVertical>(request);
}

// BloomingFilter
template <>
auto SDK_EXPORT C::GetAccess<C::BloomingFilterSettings>::get() const -> C::BloomingFilterSettings
{
  auto const payload = m_configurator.readVariable<srt::multiScan200::bloomingFilter>();
  return C::BloomingFilterSettings {payload._enable, static_cast<C::BloomingFilterStrength>(payload._strength)};
}

template <>
void SDK_EXPORT C::EnableAccess<C::BloomingFilterStrength>::enable(C::BloomingFilterStrength value) const
{
  srt::multiScan200::bloomingFilter::Post::Request const request {static_cast<srt::multiScan200::bloomingFilter::Post::Request::strength>(value), true};
  m_configurator.writeVariable<srt::multiScan200::bloomingFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::BloomingFilterStrength>::disable() const
{
  srt::multiScan200::bloomingFilter::Post::Request const request {srt::multiScan200::bloomingFilter::Post::Request::strength::Low, false};
  m_configurator.writeVariable<srt::multiScan200::bloomingFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::BloomingFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan200::bloomingFilter>()._enable;
}

auto C::ContaminationConfigAccess::get() const -> ContaminationConfiguration
{
  ContaminationConfiguration config;
  config.strategy       = static_cast<uint8_t>(m_configurator.readVariable<srt::multiScan200::ContaminationConfig>()._eStrategy);
  config.responseTime   = m_configurator.readVariable<srt::multiScan200::ContaminationConfig>()._usiResponseTime.value();
  config.threshold      = static_cast<uint8_t>(m_configurator.readVariable<srt::multiScan200::ContaminationConfig>()._eThreshold);
  config.cover          = static_cast<uint8_t>(m_configurator.readVariable<srt::multiScan200::ContaminationConfig>()._eCover);
  config.customSectors  = m_configurator.readVariable<srt::multiScan200::ContaminationConfig>()._CustomSectors;
  config.bEnableWarning = m_configurator.readVariable<srt::multiScan200::ContaminationConfig>()._bEnableWarning;
  config.bEnableError   = m_configurator.readVariable<srt::multiScan200::ContaminationConfig>()._bEnableError;

  return config;
}

auto C::ContaminationConfigAccess::set(ContaminationConfiguration const& configuration) const
{
  srt::multiScan200::ContaminationConfig::Post::Request req;
  req._eStrategy       = static_cast<srt::multiScan200::ContaminationConfig::Post::Request::eStrategy>(configuration.strategy);
  req._usiResponseTime = configuration.responseTime;
  req._eThreshold      = static_cast<srt::multiScan200::ContaminationConfig::Post::Request::eThreshold>(configuration.threshold);
  req._eCover          = static_cast<srt::multiScan200::ContaminationConfig::Post::Request::eCover>(configuration.cover);
  req._CustomSectors   = configuration.customSectors;
  req._bEnableWarning  = configuration.bEnableWarning;
  req._bEnableError    = configuration.bEnableError;
  m_configurator.writeVariable<srt::multiScan200::ContaminationConfig>(req);
}

auto C::ContaminationDataAccess::get() const -> std::vector<int>
{
  return m_configurator.readVariable<srt::multiScan200::ContaminationData>()._ContaminationData;
}

auto C::ContaminationResultAccess::get() const -> std::array<bool, 2>
{
  std::array<bool, 2> const arr {
    m_configurator.readVariable<srt::multiScan200::ContaminationResult>()._bErrorActive,
    m_configurator.readVariable<srt::multiScan200::ContaminationResult>()._bWarningActive
  };
  return arr;
}

// CurrentTempDev
auto C::DeviceTemperatureAccess::get() const -> Temperature
{
  return Temperature::fromDegreesCelsius(m_configurator.readVariable<srt::multiScan200::CurrentTempDev>()._CurrentTempDev);
}

// DeviceState
template <>
auto SDK_EXPORT
C::GetAccess<srt::multiScan200::DeviceStatus::Get::Response::DeviceStatus>::get() const -> srt::multiScan200::DeviceStatus::Get::Response::DeviceStatus
{
  return m_configurator.readVariable<srt::multiScan200::DeviceStatus>()._DeviceStatus;
}

// DeviceType
auto C::DeviceTypeAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan200::DeviceType>()._DeviceType;
}

// EchoFilter
template <>
auto SDK_EXPORT C::GetAccess<C::EchoFilterSetting>::get() const -> C::EchoFilterSetting
{
  return static_cast<C::EchoFilterSetting>(m_configurator.readVariable<srt::multiScan200::FREchoFilter>()._FREchoFilter);
}

template <>
void SDK_EXPORT C::SetAccess<C::EchoFilterSetting>::set(C::EchoFilterSetting value) const
{
  srt::multiScan200::FREchoFilter::Post::Request const request {static_cast<srt::multiScan200::FREchoFilter::Post::Request::FREchoFilter>(value)};
  m_configurator.writeVariable<srt::multiScan200::FREchoFilter>(request);
}

// EtherIPAddress
auto C::IPAddressAccess::get() const -> IpV4Address
{
  auto const resArray = m_configurator.readVariable<srt::multiScan200::EtherIPAddress>()._EtherIPAddress;
  return IpV4Address(std::array<std::uint8_t, 4> {
    static_cast<std::uint8_t>(resArray[0]),
    static_cast<std::uint8_t>(resArray[1]),
    static_cast<std::uint8_t>(resArray[2]),
    static_cast<std::uint8_t>(resArray[3])
  });
}

void C::IPAddressAccess::set(IpV4Address const& ipAddress) const
{
  auto const bytes = ipAddress.bytes();
  srt::multiScan200::EtherIPAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::multiScan200::EtherIPAddress>(request);
}

// EtherAddressingMode
template <>
auto SDK_EXPORT C::GetAccess<C::IPAddressingMode>::get() const -> C::IPAddressingMode
{
  return static_cast<C::IPAddressingMode>(m_configurator.readVariable<srt::multiScan200::EtherAddressingMode>()._EtherAddressingMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::IPAddressingMode>::set(C::IPAddressingMode mode) const
{
  srt::multiScan200::EtherAddressingMode::Post::Request const request {
    static_cast<srt::multiScan200::EtherAddressingMode::Post::Request::EtherAddressingMode>(mode)
  };
  m_configurator.writeVariable<srt::multiScan200::EtherAddressingMode>(request);
}

// EtherIPMask
auto C::IPMaskAccess::get() const -> IpV4Address
{
  auto const mask = m_configurator.readVariable<srt::multiScan200::EtherIPMask>()._EtherIPMask;
  return IpV4Address(std::array<std::uint8_t, 4> {
    static_cast<std::uint8_t>(mask[0]),
    static_cast<std::uint8_t>(mask[1]),
    static_cast<std::uint8_t>(mask[2]),
    static_cast<std::uint8_t>(mask[3])
  });
}

void C::IPMaskAccess::set(IpV4Address const& ipMask) const
{
  auto const bytes = ipMask.bytes();
  srt::multiScan200::EtherIPMask::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::multiScan200::EtherIPMask>(request);
}

// EtherIPGateAddress
auto C::IPGatewayAccess::get() const -> IpV4Address
{
  auto const gateway = m_configurator.readVariable<srt::multiScan200::EtherIPGateAddress>()._EtherIPGateAddress;
  return IpV4Address(std::array<std::uint8_t, 4> {
    static_cast<std::uint8_t>(gateway[0]),
    static_cast<std::uint8_t>(gateway[1]),
    static_cast<std::uint8_t>(gateway[2]),
    static_cast<std::uint8_t>(gateway[3])
  });
}

void C::IPGatewayAccess::set(IpV4Address const& ipGateway) const
{
  auto const bytes = ipGateway.bytes();
  srt::multiScan200::EtherIPGateAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::multiScan200::EtherIPGateAddress>(request);
}

// EthernetUpdate
void C::EthernetUpdateAccess::apply() const
{
  m_configurator.post(srt::multiScan200::EthernetUpdate::methodName).execute();
}

// FirmwareVersion
auto C::FirmwareVersionAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan200::FirmwareVersion>()._FirmwareVersion;
}

// HorizontalAngleRangeFilter
template <>
auto SDK_EXPORT C::GetAccess<C::HorizontalAngleRangeFilterSettings>::get() const -> C::HorizontalAngleRangeFilterSettings
{
  auto const payload = m_configurator.readVariable<srt::multiScan200::horizontalAngleRangeFilter>();
  return C::HorizontalAngleRangeFilterSettings {
    sopasToAngle(payload._thetaStart.value()), //
    sopasToAngle(payload._thetaStop.value()),  //
    payload._thetaIndexIncrement               //
  };
}

template <>
void SDK_EXPORT C::EnableAccess<C::HorizontalAngleRangeFilterSettings>::enable(C::HorizontalAngleRangeFilterSettings settings) const
{
  srt::multiScan200::horizontalAngleRangeFilter::Post::Request const
    request {true, angleToSopas(settings.start), angleToSopas(settings.end), settings.indexIncrement};
  m_configurator.writeVariable<srt::multiScan200::horizontalAngleRangeFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::HorizontalAngleRangeFilterSettings>::disable() const
{
  srt::multiScan200::horizontalAngleRangeFilter::Post::Request const request {false, {}, {}, {}};
  m_configurator.writeVariable<srt::multiScan200::horizontalAngleRangeFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::HorizontalAngleRangeFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan200::horizontalAngleRangeFilter>()._enable;
}

// HorizontalFieldOfViewStartAngle
auto C::HorizontalFieldOfViewStartAngleAccess::get() const -> Angle
{
  return sopasToAngle(m_configurator.readVariable<srt::multiScan200::horizontalFieldOfViewStartAngle>()._horizontalFieldOfViewStartAngle.value());
}

void C::HorizontalFieldOfViewStartAngleAccess::set(Angle const& angle) const
{
  srt::multiScan200::horizontalFieldOfViewStartAngle::Post::Request const request {angleToSopas(angle)};
  m_configurator.writeVariable<srt::multiScan200::horizontalFieldOfViewStartAngle>(request);
}

// IntervalFilter
auto C::IntervalFilterAccess::get() const -> NumericRange<2, 50, 2>
{
  return m_configurator.readVariable<srt::multiScan200::LFPintervalFilter>()._uiReductionFactor;
}

void C::IntervalFilterAccess::enable(NumericRange<2, 50, 2> value) const
{
  srt::multiScan200::LFPintervalFilter::Post::Request const request {true, value};
  m_configurator.writeVariable<srt::multiScan200::LFPintervalFilter>(request);
}

void C::IntervalFilterAccess::disable() const
{
  srt::multiScan200::LFPintervalFilter::Post::Request const request {false, {}};
  m_configurator.writeVariable<srt::multiScan200::LFPintervalFilter>(request);
}

auto C::IntervalFilterAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan200::LFPintervalFilter>()._bEnable;
}

// LocationName
auto C::LocationNameAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan200::LocationName>()._LocationName;
}

void C::LocationNameAccess::set(std::string const& value) const
{
  srt::multiScan200::LocationName::Post::Request const request {value};
  m_configurator.writeVariable<srt::multiScan200::LocationName>(request);
}

// OrderNumber
auto C::OrderNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan200::OrderNumber>()._OrderNumber;
}

// PerformanceProfile
template <>
auto SDK_EXPORT C::GetAccess<C::PerformanceProfile>::get() const -> C::PerformanceProfile
{
  return static_cast<C::PerformanceProfile>(m_configurator.readVariable<srt::multiScan200::PerformanceProfileNumber>()._PerformanceProfileNumber);
}

template <>
void SDK_EXPORT C::SetAccess<C::PerformanceProfile>::set(C::PerformanceProfile value) const
{
  srt::multiScan200::PerformanceProfileNumber::Post::Request const request {
    static_cast<srt::multiScan200::PerformanceProfileNumber::Post::Request::PerformanceProfileNumber>(value)
  };
  m_configurator.writeVariable<srt::multiScan200::PerformanceProfileNumber>(request);
}

// Sensitivity
template <>
auto SDK_EXPORT C::GetAccess<C::Sensitivity>::get() const -> C::Sensitivity
{
  return static_cast<C::Sensitivity>(m_configurator.readVariable<srt::multiScan200::SensitivityMode>()._SensitivityMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::Sensitivity>::set(C::Sensitivity value) const
{
  srt::multiScan200::SensitivityMode::Post::Request const request {static_cast<srt::multiScan200::SensitivityMode::Post::Request::SensitivityMode>(value)};
  m_configurator.writeVariable<srt::multiScan200::SensitivityMode>(request);
}

// SensorPosition
auto C::SensorPositionAccess::get() const -> SensorPosition
{
  return m_configurator.getSensorPosition<srt::multiScan200::SensorPosition>();
}

void C::SensorPositionAccess::set(SensorPosition const& value) const
{
  m_configurator.setSensorPosition<srt::multiScan200::SensorPosition>(value);
}

// SerialNumber
auto C::SerialNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan200::SerialNumber>()._SerialNumber;
}

// Streaming
template <>
auto SDK_EXPORT C::GetAccess<C::StreamingMode>::get() const -> C::StreamingMode
{
  return static_cast<C::StreamingMode>(m_configurator.readVariable<srt::multiScan200::dataOutputMode>()._dataOutputMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::StreamingMode>::set(C::StreamingMode value) const
{
  srt::multiScan200::dataOutputMode::Post::Request const request {static_cast<srt::multiScan200::dataOutputMode::Post::Request::dataOutputMode>(value)};
  m_configurator.writeVariable<srt::multiScan200::dataOutputMode>(request);
}

// SystemTime
auto C::SystemTimeAccess::get() const -> std::chrono::microseconds
{
  return m_configurator.getSystemTime<srt::multiScan200::LSPdatetime>();
}

auto C::SystemTimeAccess::set(std::chrono::microseconds timeSinceEpoch) const -> srt::multiScan200::LSPsetdatetime::Post::Response::ErrorCode
{
  return m_configurator.setSystemTime<srt::multiScan200::LSPsetdatetime>(timeSinceEpoch);
}

// TimeSynchronization
void C::TimeSynchronizationAccess::disable() const
{
  srt::multiScan200::TSCRole::Post::Request const request {srt::multiScan200::TSCRole::Post::Request::TSCRole::TxNone};
  m_configurator.writeVariable<srt::multiScan200::TSCRole>(request);
}

void C::TimeSynchronizationAccess::enableNtp(
  IpV4Address const& ntpServerAddress,
  srt::multiScan200::TSCTCtimezone::Post::Request::TSCTCtimezone timeZone,
  std::chrono::duration<int> updateInterval
) const
{
  {
    srt::multiScan200::TSCRole::Post::Request const request {srt::multiScan200::TSCRole::Post::Request::TSCRole::TxClient};
    m_configurator.writeVariable<srt::multiScan200::TSCRole>(request);
  }
  {
    srt::multiScan200::TSCTCSrvAddr::Post::Request const request {{ntpServerAddress.bytes().begin(), ntpServerAddress.bytes().end()}};
    m_configurator.writeVariable<srt::multiScan200::TSCTCSrvAddr>(request);
  }
  {
    srt::multiScan200::TSCTCtimezone::Post::Request const request {timeZone};
    m_configurator.writeVariable<srt::multiScan200::TSCTCtimezone>(request);
  }
  {
    srt::multiScan200::TSCTCupdatetime::Post::Request const request {static_cast<int>(std::chrono::seconds(updateInterval).count())};
    m_configurator.writeVariable<srt::multiScan200::TSCTCupdatetime>(request);
  }
}

void C::TimeSynchronizationAccess::enablePtp() const
{
  srt::multiScan200::TSCRole::Post::Request const request {srt::multiScan200::TSCRole::Post::Request::TSCRole::TxPtpSlave};
  m_configurator.writeVariable<srt::multiScan200::TSCRole>(request);
}

// VerticalAngleRangeFilter
template <>
auto SDK_EXPORT C::GetAccess<C::VerticalAngleRangeFilterSettings>::get() const -> C::VerticalAngleRangeFilterSettings
{
  auto const payload = m_configurator.readVariable<srt::multiScan200::verticalAngleRangeFilter>();
  return C::VerticalAngleRangeFilterSettings {
    sopasToAngle(payload._outerRoiStartAngle.value()), //
    sopasToAngle(payload._outerRoiStopAngle.value()),  //
    payload._outerRoiIndexIncrement,                   //
    sopasToAngle(payload._innerRoiStartAngle.value()), //
    sopasToAngle(payload._innerRoiStopAngle.value()),  //
    payload._innerRoiIndexIncrement                    //
  };
}

template <>
void SDK_EXPORT C::EnableAccess<C::VerticalAngleRangeFilterSettings>::enable(C::VerticalAngleRangeFilterSettings settings) const
{
  srt::multiScan200::verticalAngleRangeFilter::Post::Request const request {
    true,
    angleToSopas(settings.outerStart),
    angleToSopas(settings.outerEnd),
    angleToSopas(settings.innerStart),
    angleToSopas(settings.innerEnd),
    settings.outerIndexIncrement,
    settings.innerIndexIncrement
  };
  m_configurator.writeVariable<srt::multiScan200::verticalAngleRangeFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::VerticalAngleRangeFilterSettings>::disable() const
{
  srt::multiScan200::verticalAngleRangeFilter::Post::Request const request {false, {}, {}, {}, {}, {}, {}};
  m_configurator.writeVariable<srt::multiScan200::verticalAngleRangeFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::VerticalAngleRangeFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan200::verticalAngleRangeFilter>()._enable;
}

// Sensor methods
void MultiScan200Configurator::factoryReset() const
{
  post(srt::multiScan200::LoadFactoryDefaults::methodName).execute();
}

void MultiScan200Configurator::findMe(Duration const& activateFor) const
{
  srt::multiScan200::FindMe::Post::Request const request {static_cast<int>(activateFor.seconds())};
  post(srt::multiScan200::FindMe::methodName) //
    .withPlainRequestPayload(request)         //
    .execute();
}

void MultiScan200Configurator::reboot() const
{
  post(srt::multiScan200::RebootDevice::methodName).execute();
}

void MultiScan200Configurator::startMeasurement() const
{
  auto const response =
    post(srt::multiScan200::mStartMeasure::methodName) //
      .execute()                                       //
      .withPlainResponsePayload<srt::multiScan200::mStartMeasure::Post::Response>();
  if (response._ErrorCode != srt::multiScan200::mStartMeasure::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to start measurement: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

void MultiScan200Configurator::stopMeasurement() const
{
  auto const response =
    post(srt::multiScan200::mStopMeasure::methodName) //
      .execute()                                      //
      .withPlainResponsePayload<srt::multiScan200::mStopMeasure::Post::Response>();
  if (response._ErrorCode != srt::multiScan200::mStopMeasure::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to stop measurement: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

void MultiScan200Configurator::persistParametersOnDevice() const
{
  post(srt::multiScan200::WriteEeprom::methodName).execute();
}

} // namespace sick

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
