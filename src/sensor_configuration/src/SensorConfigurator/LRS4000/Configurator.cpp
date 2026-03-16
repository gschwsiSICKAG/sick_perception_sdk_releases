/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/sensor_configuration/LRS4000/Configurator.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/common/quantities/Temperature.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/IHttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/SensorConfigurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/FieldEvaluationContour.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000/LRS4000.g.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>
#include <sick_perception_sdk/sensor_configuration/api/UserLevel.hpp>

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
template <>
auto SensorConfigurator::getSystemTime<LRS4000::v1_9_0_0R::api::rest::DateTime>() const -> std::chrono::microseconds;
} // namespace sick

namespace sick::LRS4000::v1_9_0_0R {

Configurator::Configurator(std::shared_ptr<IHttpClient> httpClient, UserLevel userLevel, std::string const& password)
  : SensorConfigurator(std::move(httpClient), userLevel, password)
  , contaminationConfig(*this)
  , contaminationData(*this)
  , contaminationResult(*this)
  , deviceState(*this)
  , deviceType(*this)
  , echoFilter(*this)
  , sensorIPAddress(*this)
  , sensorIPAddressingMode(*this)
  , sensorIPMask(*this)
  , sensorIPGateway(*this)
  , ethernetUpdate(*this)
  , fieldEvaluationGroupState(*this)
  , fieldEvaluationResult(*this)
  , firmwareVersion(*this)
  , fieldEvaluationContour(*this)
  , locationName(*this)
  , orderNumber(*this)
  , serialNumber(*this)
  , sensorTemperature(*this)
  , streaming(*this)
  , systemTime(*this)
  , timeSynchronization(*this)
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

auto C::ContaminationDataAccess::get() const -> std::array<int, 12>
{
  return m_configurator.readVariable<api::rest::ContaminationData>()._ContaminationData;
}

auto C::ContaminationResultAccess::get() const -> std::array<bool, 2>
{
  std::array<bool, 2> const arr {
    m_configurator.readVariable<api::rest::ContaminationResult>()._errorActive,
    m_configurator.readVariable<api::rest::ContaminationResult>()._warningActive
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
  api::rest::EtherIPAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
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
  api::rest::EtherIPMask::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
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
  api::rest::EtherIPGateAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<api::rest::EtherIPGateAddress>(request);
}

// EthernetUpdate
void C::EthernetUpdateAccess::apply() const
{
  m_configurator.post(api::rest::EthernetUpdate::methodName).execute();
}

// Object Detection - Field Evaluation
auto C::FieldEvaluationContourAccess::get(int evaluationId) const -> std::vector<FieldEvaluationContour>
{
  api::rest::GetFieldEvaluationContour::Post::Request const request {evaluationId};

  auto const response =
    m_configurator.post(api::rest::GetFieldEvaluationContour::methodName)
      .withPlainRequestPayload(request)
      .execute()
      .withPlainResponsePayload<api::rest::GetFieldEvaluationContour::Post::Response>();

  std::vector<FieldEvaluationContour> ret;
  ret.reserve(response._Contour.size());
  for (auto const& contourItem : response._Contour)
  {
    FieldEvaluationContour contour;
    contour.points.reserve(contourItem._Points.size());
    contour.evaluationId = contourItem._EvaluationId;
    contour.lowerZLimit  = Distance::fromMillimeters(static_cast<float>(contourItem._LowerZLimit.value()));
    contour.upperZLimit  = Distance::fromMillimeters(static_cast<float>(contourItem._UpperZLimit.value()));
    for (auto const& point : contourItem._Points)
    {
      FieldEvaluationContour::Point const newPoint {
        Distance::fromMillimeters(static_cast<float>(point._x)),
        Distance::fromMillimeters(static_cast<float>(point._y))
      };
      contour.points.push_back(newPoint);
    }
    ret.push_back(contour);
  }

  return ret;
}

void C::FieldEvaluationContourAccess::set(int evaluationId, FieldEvaluationContour const& contour) const
{
  NumericRange<-100000, 100000, 0> const lowerZLimit(static_cast<int>(contour.lowerZLimit.millimeters()));
  NumericRange<-100000, 100000, 0> const upperZLimit(static_cast<int>(contour.upperZLimit.millimeters()));
  std::vector<api::rest::SetFieldEvaluationContour::Post::Request::PointsItem> points;
  points.reserve(contour.points.size());
  for (auto const& point : contour.points)
  {
    points.emplace_back(static_cast<int>(point.x.millimeters()), static_cast<int>(point.y.millimeters()));
  }
  api::rest::SetFieldEvaluationContour::Post::Request const request {evaluationId, points, lowerZLimit, upperZLimit};

  auto const response =
    m_configurator.post(api::rest::SetFieldEvaluationContour::methodName)
      .withPlainRequestPayload(request)
      .execute()
      .withPlainResponsePayload<api::rest::SetFieldEvaluationContour::Post::Response>();

  if (response._ErrorCode != api::rest::SetFieldEvaluationContour::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to set SetFieldEvaluationContour: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

auto C::FieldEvaluationGroupStateAccess::get() const -> std::array<int, 48>
{
  return m_configurator.readVariable<api::rest::FieldEvaluationGroupState>()._FieldEvaluationGroupState;
}

auto C::FieldEvaluationResultAccess::get() const -> api::rest::FieldEvaluationResult::Get::Response::FieldEvaluationResult
{
  return m_configurator.readVariable<api::rest::FieldEvaluationResult>()._FieldEvaluationResult;
}

// FirmwareVersion
auto C::FirmwareVersionAccess::get() const -> std::string
{
  return m_configurator.readVariable<api::rest::FirmwareVersion>()._FirmwareVersion;
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

// SerialNumber
auto C::SerialNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<api::rest::SerialNumber>()._SerialNumber;
}

// System Time
auto C::SystemTimeAccess::get() const -> std::chrono::microseconds
{
  return m_configurator.getSystemTime<api::rest::DateTime>();
}

auto C::SystemTimeAccess::set(std::chrono::microseconds timeSinceEpoch) const -> api::rest::mSetDateTime::Post::Response::ErrorCode
{
  return m_configurator.setSystemTime<api::rest::mSetDateTime>(timeSinceEpoch);
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
    api::rest::TSCTCupdatetime::Post::Request const request {static_cast<int>(std::chrono::seconds(updateInterval).count())};
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
  api::rest::FindMe::Post::Request const request {static_cast<int>(activateFor.seconds())};
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

void Configurator::persistParametersOnDevice() const
{
  post(api::rest::WriteEeprom::methodName).execute();
}

} // namespace sick::LRS4000::v1_9_0_0R

namespace sick {

using C       = LRS4000::v1_9_0_0R::Configurator;
namespace api = LRS4000::v1_9_0_0R::api;

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

// Streaming
template <>
auto SDK_EXPORT C::GetAccess<C::StreamingMode>::get() const -> C::StreamingMode
{
  return static_cast<C::StreamingMode>(m_configurator.readVariable<api::rest::ScanDataFormat>()._ScanDataFormat);
}

template <>
void SDK_EXPORT C::SetAccess<C::StreamingMode>::set(C::StreamingMode value) const
{
  api::rest::ScanDataFormat::Post::Request const request {static_cast<api::rest::ScanDataFormat::Post::Request::ScanDataFormat>(value)};
  m_configurator.writeVariable<api::rest::ScanDataFormat>(request);
}

// System Time
template <>
auto SDK_EXPORT SensorConfigurator::getSystemTime<api::rest::DateTime>() const -> std::chrono::microseconds
{
  auto const sickDatetime = readVariable<api::rest::DateTime>()._DateTime;

  std::tm timeStruct {};
  // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
  timeStruct.tm_year = sickDatetime._uiYear.value() - 1900;
  timeStruct.tm_mon  = sickDatetime._usiMonth.value() - 1;
  timeStruct.tm_mday = sickDatetime._usiDay.value();
  timeStruct.tm_hour = sickDatetime._usiHour.value();
  timeStruct.tm_min  = sickDatetime._usiMinute.value();
  timeStruct.tm_sec  = sickDatetime._usiSec.value();

#ifdef _WIN32
  time_t const secondsSinceEpoch = _mkgmtime(&timeStruct);
#else
  time_t const secondsSinceEpoch = timegm(&timeStruct);
#endif

  return std::chrono::seconds(static_cast<std::int64_t>(secondsSinceEpoch)) +
         std::chrono::microseconds(static_cast<std::int64_t>(sickDatetime._udiUSec.value()));
}

} // namespace sick

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
