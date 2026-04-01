/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/sensor_configuration/multiScan200/MultiScan200Configurator.hpp>

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
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ContaminationConfig.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ContaminationData.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ContaminationResult.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/CurrentTempDev.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DeviceStatus.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/DeviceType.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherAddressingMode.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPAddress.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPGateAddress.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EtherIPMask.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/EthernetUpdate.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/FREchoFilter.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/FindMe.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/FirmwareVersion.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LFPintervalFilter.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LSPdatetime.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LSPsetdatetime.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LoadFactoryDefaults.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/LocationName.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/OrderNumber.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/PerformanceProfileNumber.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/RebootDevice.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SensitivityMode.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SensorPosition.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/SerialNumber.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCRole.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCTCSrvAddr.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCTCtimezone.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/TSCTCupdatetime.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/WriteEeprom.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/ambientPixelCountVertical.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/bloomingFilter.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/dataOutputMode.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/horizontalAngleRangeFilter.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/horizontalFieldOfViewCenterAngle.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/mStartMeasure.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/mStopMeasure.nlohmann_json.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan200/0_9_0_2C/verticalAngleRangeFilter.nlohmann_json.g.hpp>

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

namespace sick::multiScan200::v0_9_0_2C {

Configurator::Configurator(std::shared_ptr<IHttpClient> httpClient, UserLevel userLevel, std::string password)
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
  , horizontalFieldOfViewCenterAngle(*this)
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

using C = Configurator;

auto C::ContaminationConfigAccess::get() const -> ContaminationConfiguration
{
  ContaminationConfiguration config;
  config.strategy       = static_cast<uint8_t>(m_configurator.readVariable<api::rest::ContaminationConfig>()._eStrategy);
  config.responseTime   = m_configurator.readVariable<api::rest::ContaminationConfig>()._usiResponseTime.value();
  config.threshold      = static_cast<uint8_t>(m_configurator.readVariable<api::rest::ContaminationConfig>()._eThreshold);
  config.cover          = static_cast<uint8_t>(m_configurator.readVariable<api::rest::ContaminationConfig>()._eCover);
  config.customSectors  = m_configurator.readVariable<api::rest::ContaminationConfig>()._CustomSectors;
  config.bEnableWarning = m_configurator.readVariable<api::rest::ContaminationConfig>()._bEnableWarning;
  config.bEnableError   = m_configurator.readVariable<api::rest::ContaminationConfig>()._bEnableError;

  return config;
}

auto C::ContaminationConfigAccess::set(ContaminationConfiguration const& configuration) const
{
  api::rest::ContaminationConfig::Post::Request req;
  req._eStrategy       = static_cast<api::rest::ContaminationConfig::Post::Request::eStrategy>(configuration.strategy);
  req._usiResponseTime = configuration.responseTime;
  req._eThreshold      = static_cast<api::rest::ContaminationConfig::Post::Request::eThreshold>(configuration.threshold);
  req._eCover          = static_cast<api::rest::ContaminationConfig::Post::Request::eCover>(configuration.cover);
  req._CustomSectors   = configuration.customSectors;
  req._bEnableWarning  = configuration.bEnableWarning;
  req._bEnableError    = configuration.bEnableError;
  m_configurator.writeVariable<api::rest::ContaminationConfig>(req);
}

auto C::ContaminationDataAccess::get() const -> std::vector<int>
{
  return m_configurator.readVariable<api::rest::ContaminationData>()._ContaminationData;
}

auto C::ContaminationResultAccess::get() const -> std::array<bool, 2>
{
  std::array<bool, 2> const arr {
    m_configurator.readVariable<api::rest::ContaminationResult>()._bErrorActive,
    m_configurator.readVariable<api::rest::ContaminationResult>()._bWarningActive
  };
  return arr;
}

// CurrentTempDev
auto C::DeviceTemperatureAccess::get() const -> Temperature
{
  return Temperature::fromDegreesCelsius(m_configurator.readVariable<api::rest::CurrentTempDev>()._CurrentTempDev);
}

// DeviceType
auto C::DeviceTypeAccess::get() const -> std::string
{
  return m_configurator.readVariable<api::rest::DeviceType>()._DeviceType;
}

// EtherIPAddress
auto C::IPAddressAccess::get() const -> IpV4Address
{
  auto const resArray = m_configurator.readVariable<api::rest::EtherIPAddress>()._EtherIPAddress;
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
  api::rest::EtherIPAddress::Post::Request const request {std::array<std::uint8_t, 4> {
    static_cast<std::uint8_t>(bytes[0]),
    static_cast<std::uint8_t>(bytes[1]),
    static_cast<std::uint8_t>(bytes[2]),
    static_cast<std::uint8_t>(bytes[3])
  }};
  m_configurator.writeVariable<api::rest::EtherIPAddress>(request);
}

// EtherIPMask
auto C::IPMaskAccess::get() const -> IpV4Address
{
  auto const mask = m_configurator.readVariable<api::rest::EtherIPMask>()._EtherIPMask;
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
  api::rest::EtherIPMask::Post::Request const request {std::array<std::uint8_t, 4> {
    static_cast<std::uint8_t>(bytes[0]),
    static_cast<std::uint8_t>(bytes[1]),
    static_cast<std::uint8_t>(bytes[2]),
    static_cast<std::uint8_t>(bytes[3])
  }};
  m_configurator.writeVariable<api::rest::EtherIPMask>(request);
}

// EtherIPGateAddress
auto C::IPGatewayAccess::get() const -> IpV4Address
{
  auto const gateway = m_configurator.readVariable<api::rest::EtherIPGateAddress>()._EtherIPGateAddress;
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
  api::rest::EtherIPGateAddress::Post::Request const request {std::array<std::uint8_t, 4> {
    static_cast<std::uint8_t>(bytes[0]),
    static_cast<std::uint8_t>(bytes[1]),
    static_cast<std::uint8_t>(bytes[2]),
    static_cast<std::uint8_t>(bytes[3])
  }};
  m_configurator.writeVariable<api::rest::EtherIPGateAddress>(request);
}

// EthernetUpdate
void C::EthernetUpdateAccess::apply() const
{
  m_configurator.post(api::rest::EthernetUpdate::methodName).execute();
}

// FirmwareVersion
auto C::FirmwareVersionAccess::get() const -> std::string
{
  return m_configurator.readVariable<api::rest::FirmwareVersion>()._FirmwareVersion;
}

// HorizontalFieldOfViewCenterAngleAccess
auto C::HorizontalFieldOfViewCenterAngleAccess::get() const -> Angle
{
  return sopasToAngle(m_configurator.readVariable<api::rest::horizontalFieldOfViewCenterAngle>()._horizontalFieldOfViewCenterAngle.value());
}

void C::HorizontalFieldOfViewCenterAngleAccess::set(Angle const& angle) const
{
  api::rest::horizontalFieldOfViewCenterAngle::Post::Request const request {angleToSopas(angle)};
  m_configurator.writeVariable<api::rest::horizontalFieldOfViewCenterAngle>(request);
}

// IntervalFilter
auto C::IntervalFilterAccess::get() const -> NumericRange<std::int32_t, 2, 50, 2>
{
  return m_configurator.readVariable<api::rest::LFPintervalFilter>()._uiReductionFactor;
}

void C::IntervalFilterAccess::enable(NumericRange<std::int32_t, 2, 50, 2> value) const
{
  api::rest::LFPintervalFilter::Post::Request const request {true, value};
  m_configurator.writeVariable<api::rest::LFPintervalFilter>(request);
}

void C::IntervalFilterAccess::disable() const
{
  api::rest::LFPintervalFilter::Post::Request const request {false, {}};
  m_configurator.writeVariable<api::rest::LFPintervalFilter>(request);
}

auto C::IntervalFilterAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<api::rest::LFPintervalFilter>()._bEnable;
}

// LocationName
auto C::LocationNameAccess::get() const -> std::string
{
  return m_configurator.readVariable<api::rest::LocationName>()._LocationName;
}

void C::LocationNameAccess::set(std::string const& value) const
{
  api::rest::LocationName::Post::Request const request {value};
  m_configurator.writeVariable<api::rest::LocationName>(request);
}

// OrderNumber
auto C::OrderNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<api::rest::OrderNumber>()._OrderNumber;
}

// SensorPosition
auto C::SensorPositionAccess::get() const -> SensorPosition
{
  return m_configurator.getSensorPosition<api::rest::SensorPosition>();
}

void C::SensorPositionAccess::set(SensorPosition const& value) const
{
  m_configurator.setSensorPosition<api::rest::SensorPosition>(value);
}

// SerialNumber
auto C::SerialNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<api::rest::SerialNumber>()._SerialNumber;
}

// SystemTime
auto C::SystemTimeAccess::get() const -> std::chrono::microseconds
{
  return m_configurator.getSystemTime<api::rest::LSPdatetime>();
}

auto C::SystemTimeAccess::set(std::chrono::microseconds timeSinceEpoch) const -> api::rest::LSPsetdatetime::Post::Response::ErrorCode
{
  return m_configurator.setSystemTime<api::rest::LSPsetdatetime>(timeSinceEpoch);
}

// TimeSynchronization
void C::TimeSynchronizationAccess::disable() const
{
  api::rest::TSCRole::Post::Request const request {api::rest::TSCRole::Post::Request::TSCRole::TxNone};
  m_configurator.writeVariable<api::rest::TSCRole>(request);
}

void C::TimeSynchronizationAccess::enableNtp(
  IpV4Address const& ntpServerAddress,
  api::rest::TSCTCtimezone::Post::Request::TSCTCtimezone timeZone,
  std::chrono::duration<int> updateInterval
) const
{
  {
    api::rest::TSCRole::Post::Request const request {api::rest::TSCRole::Post::Request::TSCRole::TxClient};
    m_configurator.writeVariable<api::rest::TSCRole>(request);
  }
  {
    api::rest::TSCTCSrvAddr::Post::Request const request {{ntpServerAddress.bytes().begin(), ntpServerAddress.bytes().end()}};
    m_configurator.writeVariable<api::rest::TSCTCSrvAddr>(request);
  }
  {
    api::rest::TSCTCtimezone::Post::Request const request {timeZone};
    m_configurator.writeVariable<api::rest::TSCTCtimezone>(request);
  }
  {
    api::rest::TSCTCupdatetime::Post::Request const request {static_cast<std::uint32_t>(std::chrono::seconds(updateInterval).count())};
    m_configurator.writeVariable<api::rest::TSCTCupdatetime>(request);
  }
}

void C::TimeSynchronizationAccess::enablePtp() const
{
  api::rest::TSCRole::Post::Request const request {api::rest::TSCRole::Post::Request::TSCRole::TxPtpSlave};
  m_configurator.writeVariable<api::rest::TSCRole>(request);
}

// Sensor methods
void Configurator::factoryReset() const
{
  post(api::rest::LoadFactoryDefaults::methodName).execute();
}

void Configurator::findMe(Duration const& activateFor) const
{
  api::rest::FindMe::Post::Request const request {static_cast<std::uint16_t>(activateFor.seconds())};
  post(api::rest::FindMe::methodName) //
    .withPlainRequestPayload(request) //
    .execute();
}

void Configurator::reboot() const
{
  post(api::rest::RebootDevice::methodName).execute();
}

void Configurator::startMeasurement() const
{
  auto const response =
    post(api::rest::mStartMeasure::methodName) //
      .execute()                               //
      .withPlainResponsePayload<api::rest::mStartMeasure::Post::Response>();
  if (response._ErrorCode != api::rest::mStartMeasure::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to start measurement: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

void Configurator::stopMeasurement() const
{
  auto const response =
    post(api::rest::mStopMeasure::methodName) //
      .execute()                              //
      .withPlainResponsePayload<api::rest::mStopMeasure::Post::Response>();
  if (response._ErrorCode != api::rest::mStopMeasure::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to stop measurement: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

void Configurator::persistParametersOnDevice() const
{
  post(api::rest::WriteEeprom::methodName).execute();
}

} // namespace sick::multiScan200::v0_9_0_2C

namespace sick {

using C       = multiScan200::v0_9_0_2C::Configurator;
namespace api = multiScan200::v0_9_0_2C::api;

// AmbientLightPixelCountVertical
template <>
auto SDK_EXPORT C::GetAccess<C::AmbientLightPixelCountVertical>::get() const -> C::AmbientLightPixelCountVertical
{
  return static_cast<C::AmbientLightPixelCountVertical>(m_configurator.readVariable<api::rest::ambientPixelCountVertical>()._ambientPixelCountVertical);
}

template <>
void SDK_EXPORT C::SetAccess<C::AmbientLightPixelCountVertical>::set(C::AmbientLightPixelCountVertical value) const
{
  api::rest::ambientPixelCountVertical::Post::Request const request {
    static_cast<api::rest::ambientPixelCountVertical::Post::Request::ambientPixelCountVertical>(value)
  };
  m_configurator.writeVariable<api::rest::ambientPixelCountVertical>(request);
}

// BloomingFilter
template <>
auto SDK_EXPORT C::GetAccess<C::BloomingFilterSettings>::get() const -> C::BloomingFilterSettings
{
  auto const payload = m_configurator.readVariable<api::rest::bloomingFilter>();
  return C::BloomingFilterSettings {payload._enable, static_cast<C::BloomingFilterStrength>(payload._strength)};
}

template <>
void SDK_EXPORT C::EnableAccess<C::BloomingFilterStrength>::enable(C::BloomingFilterStrength value) const
{
  api::rest::bloomingFilter::Post::Request const request {static_cast<api::rest::bloomingFilter::Post::Request::strength>(value), true};
  m_configurator.writeVariable<api::rest::bloomingFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::BloomingFilterStrength>::disable() const
{
  api::rest::bloomingFilter::Post::Request const request {api::rest::bloomingFilter::Post::Request::strength::Low, false};
  m_configurator.writeVariable<api::rest::bloomingFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::BloomingFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<api::rest::bloomingFilter>()._enable;
}

// DeviceState
template <>
auto SDK_EXPORT C::GetAccess<api::rest::DeviceStatus::Get::Response::DeviceStatus>::get() const -> api::rest::DeviceStatus::Get::Response::DeviceStatus
{
  return m_configurator.readVariable<api::rest::DeviceStatus>()._DeviceStatus;
}

// EchoFilter
template <>
auto SDK_EXPORT C::GetAccess<C::EchoFilterSetting>::get() const -> C::EchoFilterSetting
{
  return static_cast<C::EchoFilterSetting>(m_configurator.readVariable<api::rest::FREchoFilter>()._FREchoFilter);
}

template <>
void SDK_EXPORT C::SetAccess<C::EchoFilterSetting>::set(C::EchoFilterSetting value) const
{
  api::rest::FREchoFilter::Post::Request const request {static_cast<api::rest::FREchoFilter::Post::Request::FREchoFilter>(value)};
  m_configurator.writeVariable<api::rest::FREchoFilter>(request);
}

// EtherAddressingMode
template <>
auto SDK_EXPORT C::GetAccess<C::IPAddressingMode>::get() const -> C::IPAddressingMode
{
  return static_cast<C::IPAddressingMode>(m_configurator.readVariable<api::rest::EtherAddressingMode>()._EtherAddressingMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::IPAddressingMode>::set(C::IPAddressingMode mode) const
{
  api::rest::EtherAddressingMode::Post::Request const request {static_cast<api::rest::EtherAddressingMode::Post::Request::EtherAddressingMode>(mode)};
  m_configurator.writeVariable<api::rest::EtherAddressingMode>(request);
}

// HorizontalAngleRangeFilter
template <>
auto SDK_EXPORT C::GetAccess<C::HorizontalAngleRangeFilterSettings>::get() const -> C::HorizontalAngleRangeFilterSettings
{
  auto const payload = m_configurator.readVariable<api::rest::horizontalAngleRangeFilter>();
  return C::HorizontalAngleRangeFilterSettings {
    sopasToAngle(payload._thetaStart.value()), //
    sopasToAngle(payload._thetaStop.value()),  //
    payload._thetaIndexIncrement               //
  };
}

template <>
void SDK_EXPORT C::EnableAccess<C::HorizontalAngleRangeFilterSettings>::enable(C::HorizontalAngleRangeFilterSettings settings) const
{
  api::rest::horizontalAngleRangeFilter::Post::Request const request {true, angleToSopas(settings.start), angleToSopas(settings.end), settings.indexIncrement};
  m_configurator.writeVariable<api::rest::horizontalAngleRangeFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::HorizontalAngleRangeFilterSettings>::disable() const
{
  api::rest::horizontalAngleRangeFilter::Post::Request const request {false, {}, {}, {}};
  m_configurator.writeVariable<api::rest::horizontalAngleRangeFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::HorizontalAngleRangeFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<api::rest::horizontalAngleRangeFilter>()._enable;
}

// PerformanceProfile
template <>
auto SDK_EXPORT C::GetAccess<C::PerformanceProfile>::get() const -> C::PerformanceProfile
{
  return static_cast<C::PerformanceProfile>(m_configurator.readVariable<api::rest::PerformanceProfileNumber>()._PerformanceProfileNumber);
}

template <>
void SDK_EXPORT C::SetAccess<C::PerformanceProfile>::set(C::PerformanceProfile value) const
{
  api::rest::PerformanceProfileNumber::Post::Request const request {
    static_cast<api::rest::PerformanceProfileNumber::Post::Request::PerformanceProfileNumber>(value)
  };
  m_configurator.writeVariable<api::rest::PerformanceProfileNumber>(request);
}

// Sensitivity
template <>
auto SDK_EXPORT C::GetAccess<C::Sensitivity>::get() const -> C::Sensitivity
{
  return static_cast<C::Sensitivity>(m_configurator.readVariable<api::rest::SensitivityMode>()._SensitivityMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::Sensitivity>::set(C::Sensitivity value) const
{
  api::rest::SensitivityMode::Post::Request const request {static_cast<api::rest::SensitivityMode::Post::Request::SensitivityMode>(value)};
  m_configurator.writeVariable<api::rest::SensitivityMode>(request);
}

// Streaming
template <>
auto SDK_EXPORT C::GetAccess<C::StreamingMode>::get() const -> C::StreamingMode
{
  return static_cast<C::StreamingMode>(m_configurator.readVariable<api::rest::dataOutputMode>()._dataOutputMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::StreamingMode>::set(C::StreamingMode value) const
{
  api::rest::dataOutputMode::Post::Request const request {static_cast<api::rest::dataOutputMode::Post::Request::dataOutputMode>(value)};
  m_configurator.writeVariable<api::rest::dataOutputMode>(request);
}

// VerticalAngleRangeFilter
template <>
auto SDK_EXPORT C::GetAccess<C::VerticalAngleRangeFilterSettings>::get() const -> C::VerticalAngleRangeFilterSettings
{
  auto const payload = m_configurator.readVariable<api::rest::verticalAngleRangeFilter>();
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
  api::rest::verticalAngleRangeFilter::Post::Request const request {
    true,
    angleToSopas(settings.outerStart),
    angleToSopas(settings.outerEnd),
    angleToSopas(settings.innerStart),
    angleToSopas(settings.innerEnd),
    settings.outerIndexIncrement,
    settings.innerIndexIncrement
  };
  m_configurator.writeVariable<api::rest::verticalAngleRangeFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::VerticalAngleRangeFilterSettings>::disable() const
{
  api::rest::verticalAngleRangeFilter::Post::Request const request {false, {}, {}, {}, {}, {}, {}};
  m_configurator.writeVariable<api::rest::verticalAngleRangeFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::VerticalAngleRangeFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<api::rest::verticalAngleRangeFilter>()._enable;
}

} // namespace sick

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
