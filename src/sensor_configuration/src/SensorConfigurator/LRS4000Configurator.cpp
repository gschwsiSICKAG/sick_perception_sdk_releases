/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/sensor_configuration/LRS4000Configurator.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/common/quantities/Temperature.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/IHttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/SensorConfigurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/FieldEvaluationContour.hpp>
#include <sick_perception_sdk/sensor_configuration/api/LRS4000.g.hpp>
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

LRS4000Configurator::LRS4000Configurator(std::shared_ptr<IHttpClient> httpClient, UserLevel userLevel, std::string const& password)
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

using C = LRS4000Configurator;

auto C::ContaminationConfigAccess::get() const -> ContaminationConfiguration
{
  ContaminationConfiguration config;
  config.strategy       = static_cast<uint8_t>(m_configurator.readVariable<srt::LRS4000::ContaminationConfig>()._eStrategy);
  config.responseTime   = m_configurator.readVariable<srt::LRS4000::ContaminationConfig>()._usiResponseTime.value();
  config.threshold      = static_cast<uint8_t>(m_configurator.readVariable<srt::LRS4000::ContaminationConfig>()._eThreshold);
  config.cover          = static_cast<uint8_t>(m_configurator.readVariable<srt::LRS4000::ContaminationConfig>()._eCover);
  config.customSectors  = m_configurator.readVariable<srt::LRS4000::ContaminationConfig>()._CustomSectors;
  config.bEnableWarning = m_configurator.readVariable<srt::LRS4000::ContaminationConfig>()._bEnableWarning;
  config.bEnableError   = m_configurator.readVariable<srt::LRS4000::ContaminationConfig>()._bEnableError;

  return config;
}

auto C::ContaminationConfigAccess::set(ContaminationConfiguration const& configuration) const
{
  srt::LRS4000::ContaminationConfig::Post::Request req;
  req._eStrategy       = static_cast<srt::LRS4000::ContaminationConfig::Post::Request::eStrategy>(configuration.strategy);
  req._usiResponseTime = configuration.responseTime;
  req._eThreshold      = static_cast<srt::LRS4000::ContaminationConfig::Post::Request::eThreshold>(configuration.threshold);
  req._eCover          = static_cast<srt::LRS4000::ContaminationConfig::Post::Request::eCover>(configuration.cover);
  req._CustomSectors   = configuration.customSectors;
  req._bEnableWarning  = configuration.bEnableWarning;
  req._bEnableError    = configuration.bEnableError;
  m_configurator.writeVariable<srt::LRS4000::ContaminationConfig>(req);
}

auto C::ContaminationDataAccess::get() const -> std::array<int, 12>
{
  return m_configurator.readVariable<srt::LRS4000::ContaminationData>()._ContaminationData;
}

auto C::ContaminationResultAccess::get() const -> std::array<bool, 2>
{
  std::array<bool, 2> const arr {
    m_configurator.readVariable<srt::LRS4000::ContaminationResult>()._errorActive,
    m_configurator.readVariable<srt::LRS4000::ContaminationResult>()._warningActive
  };
  return arr;
}

// CurrentTempDev
auto C::DeviceTemperatureAccess::get() const -> Temperature
{
  return Temperature::fromDegreesCelsius(m_configurator.readVariable<srt::LRS4000::CurrentTempDev>()._CurrentTempDev);
}

// DeviceState
template <>
auto SDK_EXPORT C::GetAccess<srt::LRS4000::DeviceStatus::Get::Response::DeviceStatus>::get() const -> srt::LRS4000::DeviceStatus::Get::Response::DeviceStatus
{
  return m_configurator.readVariable<srt::LRS4000::DeviceStatus>()._DeviceStatus;
}

// DeviceType
auto C::DeviceTypeAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::LRS4000::DeviceType>()._DeviceType;
}

// EchoFilter
template <>
auto SDK_EXPORT C::GetAccess<C::EchoFilterSetting>::get() const -> C::EchoFilterSetting
{
  return static_cast<C::EchoFilterSetting>(m_configurator.readVariable<srt::LRS4000::FREchoFilter>()._FREchoFilter);
}

template <>
void SDK_EXPORT C::SetAccess<C::EchoFilterSetting>::set(C::EchoFilterSetting value) const
{
  srt::LRS4000::FREchoFilter::Post::Request const request {static_cast<srt::LRS4000::FREchoFilter::Post::Request::FREchoFilter>(value)};
  m_configurator.writeVariable<srt::LRS4000::FREchoFilter>(request);
}

// EtherIPAddress
auto C::IPAddressAccess::get() const -> IpV4Address
{
  auto const resArray = m_configurator.readVariable<srt::LRS4000::EtherIPAddress>()._EtherIPAddress;
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
  srt::LRS4000::EtherIPAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::LRS4000::EtherIPAddress>(request);
}

// EtherAddressingMode
template <>
auto SDK_EXPORT C::GetAccess<C::IPAddressingMode>::get() const -> C::IPAddressingMode
{
  return static_cast<C::IPAddressingMode>(m_configurator.readVariable<srt::LRS4000::EtherAddressingMode>()._EtherAddressingMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::IPAddressingMode>::set(C::IPAddressingMode mode) const
{
  srt::LRS4000::EtherAddressingMode::Post::Request const request {static_cast<srt::LRS4000::EtherAddressingMode::Post::Request::EtherAddressingMode>(mode)};
  m_configurator.writeVariable<srt::LRS4000::EtherAddressingMode>(request);
}

// EtherIPMask
auto C::IPMaskAccess::get() const -> IpV4Address
{
  auto const mask = m_configurator.readVariable<srt::LRS4000::EtherIPMask>()._EtherIPMask;
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
  srt::LRS4000::EtherIPMask::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::LRS4000::EtherIPMask>(request);
}

// EtherIPGateAddress
auto C::IPGatewayAccess::get() const -> IpV4Address
{
  auto const gateway = m_configurator.readVariable<srt::LRS4000::EtherIPGateAddress>()._EtherIPGateAddress;
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
  srt::LRS4000::EtherIPGateAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::LRS4000::EtherIPGateAddress>(request);
}

// EthernetUpdate
void C::EthernetUpdateAccess::apply() const
{
  m_configurator.post(srt::LRS4000::EthernetUpdate::methodName).execute();
}

// Object Detection - Field Evaluation
auto C::FieldEvaluationContourAccess::get(int evaluationId) const -> std::vector<FieldEvaluationContour>
{
  srt::LRS4000::GetFieldEvaluationContour::Post::Request const request {evaluationId};

  auto const response =
    m_configurator.post(srt::LRS4000::GetFieldEvaluationContour::methodName)
      .withPlainRequestPayload(request)
      .execute()
      .withPlainResponsePayload<srt::LRS4000::GetFieldEvaluationContour::Post::Response>();

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
  std::vector<srt::LRS4000::SetFieldEvaluationContour::Post::Request::PointsItem> points;
  points.reserve(contour.points.size());
  for (auto const& point : contour.points)
  {
    points.emplace_back(static_cast<int>(point.x.millimeters()), static_cast<int>(point.y.millimeters()));
  }
  srt::LRS4000::SetFieldEvaluationContour::Post::Request const request {evaluationId, points, lowerZLimit, upperZLimit};

  auto const response =
    m_configurator.post(srt::LRS4000::SetFieldEvaluationContour::methodName)
      .withPlainRequestPayload(request)
      .execute()
      .withPlainResponsePayload<srt::LRS4000::SetFieldEvaluationContour::Post::Response>();

  if (response._ErrorCode != srt::LRS4000::SetFieldEvaluationContour::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to set SetFieldEvaluationContour: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

auto C::FieldEvaluationGroupStateAccess::get() const -> std::array<int, 48>
{
  return m_configurator.readVariable<srt::LRS4000::FieldEvaluationGroupState>()._FieldEvaluationGroupState;
}

auto C::FieldEvaluationResultAccess::get() const -> srt::LRS4000::FieldEvaluationResult::Get::Response::FieldEvaluationResult
{
  return m_configurator.readVariable<srt::LRS4000::FieldEvaluationResult>()._FieldEvaluationResult;
}

// FirmwareVersion
auto C::FirmwareVersionAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::LRS4000::FirmwareVersion>()._FirmwareVersion;
}

// LocationName
auto C::LocationNameAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::LRS4000::LocationName>()._LocationName;
}

void C::LocationNameAccess::set(std::string const& value) const
{
  srt::LRS4000::LocationName::Post::Request const request {value};
  m_configurator.writeVariable<srt::LRS4000::LocationName>(request);
}

// OrderNumber
auto C::OrderNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::LRS4000::OrderNumber>()._OrderNumber;
}

// SerialNumber
auto C::SerialNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::LRS4000::SerialNumber>()._SerialNumber;
}

// Streaming
template <>
auto SDK_EXPORT C::GetAccess<C::StreamingMode>::get() const -> C::StreamingMode
{
  return static_cast<C::StreamingMode>(m_configurator.readVariable<srt::LRS4000::ScanDataFormat>()._ScanDataFormat);
}

template <>
void SDK_EXPORT C::SetAccess<C::StreamingMode>::set(C::StreamingMode value) const
{
  srt::LRS4000::ScanDataFormat::Post::Request const request {static_cast<srt::LRS4000::ScanDataFormat::Post::Request::ScanDataFormat>(value)};
  m_configurator.writeVariable<srt::LRS4000::ScanDataFormat>(request);
}

// System Time
template <>
auto SensorConfigurator::getSystemTime<srt::LRS4000::DateTime>() const -> std::chrono::microseconds
{
  auto const sickDatetime = readVariable<srt::LRS4000::DateTime>()._DateTime;

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

auto C::SystemTimeAccess::get() const -> std::chrono::microseconds
{
  return m_configurator.getSystemTime<srt::LRS4000::DateTime>();
}

auto C::SystemTimeAccess::set(std::chrono::microseconds timeSinceEpoch) const -> srt::LRS4000::mSetDateTime::Post::Response::ErrorCode
{
  return m_configurator.setSystemTime<srt::LRS4000::mSetDateTime>(timeSinceEpoch);
}

// TimeSynchronization
void C::TimeSynchronizationAccess::disable() const
{
  srt::LRS4000::TSCRole::Post::Request const request {srt::LRS4000::TSCRole::Post::Request::TSCRole::TxNone};
  m_configurator.writeVariable<srt::LRS4000::TSCRole>(request);
}

void C::TimeSynchronizationAccess::enableNtp(
  IpV4Address const& ntpServerAddress,
  srt::LRS4000::TSCTCtimezone::Post::Request::TSCTCtimezone timeZone,
  std::chrono::duration<int> updateInterval
) const
{
  {
    srt::LRS4000::TSCRole::Post::Request const request {srt::LRS4000::TSCRole::Post::Request::TSCRole::TxClient};
    m_configurator.writeVariable<srt::LRS4000::TSCRole>(request);
  }
  {
    srt::LRS4000::TSCTCSrvAddr::Post::Request const request {{ntpServerAddress.bytes().begin(), ntpServerAddress.bytes().end()}};
    m_configurator.writeVariable<srt::LRS4000::TSCTCSrvAddr>(request);
  }
  {
    srt::LRS4000::TSCTCtimezone::Post::Request const request {timeZone};
    m_configurator.writeVariable<srt::LRS4000::TSCTCtimezone>(request);
  }
  {
    srt::LRS4000::TSCTCupdatetime::Post::Request const request {static_cast<int>(std::chrono::seconds(updateInterval).count())};
    m_configurator.writeVariable<srt::LRS4000::TSCTCupdatetime>(request);
  }
}

void C::TimeSynchronizationAccess::enablePtp() const
{
  srt::LRS4000::TSCRole::Post::Request const request {srt::LRS4000::TSCRole::Post::Request::TSCRole::TxPtpSlave};
  m_configurator.writeVariable<srt::LRS4000::TSCRole>(request);
}

// Sensor methods
void LRS4000Configurator::factoryReset() const
{
  post(srt::LRS4000::LoadFactoryDefaults::methodName).execute();
}

void LRS4000Configurator::findMe(Duration const& activateFor) const
{
  srt::LRS4000::FindMe::Post::Request const request {static_cast<int>(activateFor.seconds())};
  post(srt::LRS4000::FindMe::methodName) //
    .withPlainRequestPayload(request)    //
    .execute();
}

void LRS4000Configurator::reboot() const
{
  post(srt::LRS4000::RebootDevice::methodName).execute();
}

void LRS4000Configurator::startMeasurement() const
{
  auto const response =
    post(srt::LRS4000::mStartMeasure::methodName) //
      .execute()                                  //
      .withPlainResponsePayload<srt::LRS4000::mStartMeasure::Post::Response>();
  if (response._ErrorCode != srt::LRS4000::mStartMeasure::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to start measurement: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

void LRS4000Configurator::persistParametersOnDevice() const
{
  post(srt::LRS4000::WriteEeprom::methodName).execute();
}

} // namespace sick

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
