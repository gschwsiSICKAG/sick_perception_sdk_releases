/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

#include <sick_perception_sdk/sensor_configuration/MultiScan100Configurator.hpp>

#include <sick_perception_sdk/common/IpV4Address.hpp>
#include <sick_perception_sdk/common/export.hpp>
#include <sick_perception_sdk/common/quantities/Distance.hpp>
#include <sick_perception_sdk/common/quantities/Duration.hpp>
#include <sick_perception_sdk/common/quantities/Temperature.hpp>
#include <sick_perception_sdk/sensor_configuration/HttpClient/IHttpClient.hpp>
#include <sick_perception_sdk/sensor_configuration/SensorConfigurator.hpp>
#include <sick_perception_sdk/sensor_configuration/api/FieldEvaluationContour.hpp>
#include <sick_perception_sdk/sensor_configuration/api/NumericRange.hpp>
#include <sick_perception_sdk/sensor_configuration/api/SensorPosition.hpp>
#include <sick_perception_sdk/sensor_configuration/api/SrtRest.hpp>
#include <sick_perception_sdk/sensor_configuration/api/UserLevel.hpp>
#include <sick_perception_sdk/sensor_configuration/api/multiScan100.g.hpp>

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

MultiScan100Configurator::MultiScan100Configurator(std::shared_ptr<IHttpClient> httpClient, UserLevel userLevel, std::string password)
  : SensorConfigurator(std::move(httpClient), userLevel, std::move(password))
  , angleRangeFilter(*this)
  , contaminationConfig(*this)
  , contaminationData(*this)
  , contaminationResult(*this)
  , cuboidFilter(*this)
  , sensorTemperature(*this)
  , deviceState(*this)
  , deviceType(*this)
  , distanceFilter(*this)
  , echoFilter(*this)
  , sensorIPAddress(*this)
  , sensorIPAddressingMode(*this)
  , sensorIPMask(*this)
  , sensorIPGateway(*this)
  , ethernetUpdate(*this)
  , fieldEvaluationGroupState(*this)
  , fieldEvaluationResult(*this)
  , firmwareVersion(*this)
  , fogFilter(*this)
  , fieldEvaluationContour(*this)
  , imuStreaming(*this)
  , intervalFilter(*this)
  , locationName(*this)
  , movingAverageFilter(*this)
  , orderNumber(*this)
  , particleFilter(*this)
  , sensorPosition(*this)
  , serialNumber(*this)
  , scanDataStreaming(*this)
  , systemTime(*this)
  , timeSynchronization(*this)
{ }

using C = MultiScan100Configurator;

// AngleRangeFilter
template <>
auto SDK_EXPORT C::GetAccess<C::AngleRangeFilterSettings>::get() const -> C::AngleRangeFilterSettings
{
  auto const payload = m_configurator.readVariable<srt::multiScan100::LFPangleRangeFilter>();
  return C::AngleRangeFilterSettings {
    sopasToAngle(payload._fThetaStart.value()), //
    sopasToAngle(payload._fThetaStop.value()),  //
    payload._uiBeamIncrement                    //
  };
}

template <>
void SDK_EXPORT C::EnableAccess<C::AngleRangeFilterSettings>::enable(C::AngleRangeFilterSettings settings) const
{
  srt::multiScan100::LFPangleRangeFilter::Post::Request const
    request {true, angleToSopas(settings.startAzimuth), angleToSopas(settings.stopAzimuth), {}, {}, settings.azimuthIndexIncrement};
  m_configurator.writeVariable<srt::multiScan100::LFPangleRangeFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::AngleRangeFilterSettings>::disable() const
{
  srt::multiScan100::LFPangleRangeFilter::Post::Request const request {false, {}, {}, {}, {}, {}};
  m_configurator.writeVariable<srt::multiScan100::LFPangleRangeFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::AngleRangeFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::LFPangleRangeFilter>()._bEnable;
}

auto C::ContaminationConfigAccess::get() const -> ContaminationConfiguration
{
  ContaminationConfiguration config;
  config.strategy       = static_cast<uint8_t>(m_configurator.readVariable<srt::multiScan100::ContaminationConfig>()._eStrategy);
  config.responseTime   = m_configurator.readVariable<srt::multiScan100::ContaminationConfig>()._usiResponseTime.value();
  config.threshold      = static_cast<uint8_t>(m_configurator.readVariable<srt::multiScan100::ContaminationConfig>()._eThreshold);
  config.cover          = static_cast<uint8_t>(m_configurator.readVariable<srt::multiScan100::ContaminationConfig>()._eCover);
  config.customSectors  = m_configurator.readVariable<srt::multiScan100::ContaminationConfig>()._CustomSectors;
  config.bEnableWarning = m_configurator.readVariable<srt::multiScan100::ContaminationConfig>()._bEnableWarning;
  config.bEnableError   = m_configurator.readVariable<srt::multiScan100::ContaminationConfig>()._bEnableError;

  return config;
}

auto C::ContaminationConfigAccess::set(ContaminationConfiguration const& configuration) const
{
  srt::multiScan100::ContaminationConfig::Post::Request req;
  req._eStrategy       = static_cast<srt::multiScan100::ContaminationConfig::Post::Request::eStrategy>(configuration.strategy);
  req._usiResponseTime = configuration.responseTime;
  req._eThreshold      = static_cast<srt::multiScan100::ContaminationConfig::Post::Request::eThreshold>(configuration.threshold);
  req._eCover          = static_cast<srt::multiScan100::ContaminationConfig::Post::Request::eCover>(configuration.cover);
  req._CustomSectors   = configuration.customSectors;
  req._bEnableWarning  = configuration.bEnableWarning;
  req._bEnableError    = configuration.bEnableError;
  m_configurator.writeVariable<srt::multiScan100::ContaminationConfig>(req);
}

auto C::ContaminationDataAccess::get() const -> std::vector<int>
{
  return m_configurator.readVariable<srt::multiScan100::ContaminationData>()._ContaminationData;
}

auto C::ContaminationResultAccess::get() const -> std::array<bool, 2>
{
  std::array<bool, 2> const arr {
    m_configurator.readVariable<srt::multiScan100::ContaminationResult>()._bErrorActive,
    m_configurator.readVariable<srt::multiScan100::ContaminationResult>()._bWarningActive
  };
  return arr;
}

// CuboidFilter
template <>
auto SDK_EXPORT C::GetAccess<C::CuboidFilterSettings>::get() const -> C::CuboidFilterSettings
{
  auto const payload = m_configurator.readVariable<srt::multiScan100::LFPcubicareafilter>();
  return C::CuboidFilterSettings {
    {Distance::fromMillimeters(static_cast<float>(payload._lXMin.value())), Distance::fromMillimeters(static_cast<float>(payload._lXMax.value()))},
    {Distance::fromMillimeters(static_cast<float>(payload._lYMin.value())), Distance::fromMillimeters(static_cast<float>(payload._lYMax.value()))},
    {Distance::fromMillimeters(static_cast<float>(payload._lZMin.value())), Distance::fromMillimeters(static_cast<float>(payload._lZMax.value()))}
  };
}

template <>
void SDK_EXPORT C::EnableAccess<C::CuboidFilterSettings>::enable(C::CuboidFilterSettings settings) const
{
  srt::multiScan100::LFPcubicareafilter::Post::Request const request {
    true,
    static_cast<int>(settings.x.start.millimeters()),
    static_cast<int>(settings.x.stop.millimeters()),
    static_cast<int>(settings.y.start.millimeters()),
    static_cast<int>(settings.y.stop.millimeters()),
    static_cast<int>(settings.z.start.millimeters()),
    static_cast<int>(settings.z.stop.millimeters())
  };
  m_configurator.writeVariable<srt::multiScan100::LFPcubicareafilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::CuboidFilterSettings>::disable() const
{
  srt::multiScan100::LFPcubicareafilter::Post::Request const request {false, {}, {}, {}, {}, {}, {}};
  m_configurator.writeVariable<srt::multiScan100::LFPcubicareafilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::CuboidFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::LFPcubicareafilter>()._bEnable;
}

// CurrentTempDev
auto C::DeviceTemperatureAccess::get() const -> Temperature
{
  return Temperature::fromDegreesCelsius(m_configurator.readVariable<srt::multiScan100::CurrentTempDev>()._CurrentTempDev);
}

// DeviceState
template <>
auto SDK_EXPORT
C::GetAccess<srt::multiScan100::DeviceStatus::Get::Response::DeviceStatus>::get() const -> srt::multiScan100::DeviceStatus::Get::Response::DeviceStatus
{
  return m_configurator.readVariable<srt::multiScan100::DeviceStatus>()._DeviceStatus;
}

// DeviceType
auto C::DeviceTypeAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan100::DeviceType>()._DeviceType;
}

// DistanceFilter
template <>
auto SDK_EXPORT C::GetAccess<C::DistanceFilterSettings>::get() const -> C::DistanceFilterSettings
{
  auto const payload = m_configurator.readVariable<srt::multiScan100::LFPradialDistanceRangeFilter>();
  return C::DistanceFilterSettings {
    Distance::fromMillimeters(static_cast<float>(payload._ulDistMin.value())),
    Distance::fromMillimeters(static_cast<float>(payload._ulDistMax.value()))
  };
}

template <>
void SDK_EXPORT C::EnableAccess<C::DistanceFilterSettings>::enable(C::DistanceFilterSettings settings) const
{
  srt::multiScan100::LFPradialDistanceRangeFilter::Post::Request const request {
    true,
    static_cast<int>(settings.range.start.millimeters()),
    static_cast<int>(settings.range.stop.millimeters())
  };
  m_configurator.writeVariable<srt::multiScan100::LFPradialDistanceRangeFilter>(request);
}

template <>
void SDK_EXPORT C::DisableAccess<C::DistanceFilterSettings>::disable() const
{
  srt::multiScan100::LFPradialDistanceRangeFilter::Post::Request const request {false, {}, {}};
  m_configurator.writeVariable<srt::multiScan100::LFPradialDistanceRangeFilter>(request);
}

template <>
auto SDK_EXPORT C::IsEnabledAccess<C::DistanceFilterSettings>::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::LFPradialDistanceRangeFilter>()._bEnable;
}

// EchoFilter
template <>
auto SDK_EXPORT C::GetAccess<C::EchoFilterSetting>::get() const -> C::EchoFilterSetting
{
  return static_cast<C::EchoFilterSetting>(m_configurator.readVariable<srt::multiScan100::FREchoFilter>()._FREchoFilter);
}

template <>
void SDK_EXPORT C::SetAccess<C::EchoFilterSetting>::set(C::EchoFilterSetting value) const
{
  srt::multiScan100::FREchoFilter::Post::Request const request {static_cast<srt::multiScan100::FREchoFilter::Post::Request::FREchoFilter>(value)};
  m_configurator.writeVariable<srt::multiScan100::FREchoFilter>(request);
}

// EtherIPAddress
auto C::IPAddressAccess::get() const -> IpV4Address
{
  auto const resArray = m_configurator.readVariable<srt::multiScan100::EtherIPAddress>()._EtherIPAddress;
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
  srt::multiScan100::EtherIPAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::multiScan100::EtherIPAddress>(request);
}

// EtherAddressingMode
template <>
auto SDK_EXPORT C::GetAccess<C::IPAddressingMode>::get() const -> C::IPAddressingMode
{
  return static_cast<C::IPAddressingMode>(m_configurator.readVariable<srt::multiScan100::EtherAddressingMode>()._EtherAddressingMode);
}

template <>
void SDK_EXPORT C::SetAccess<C::IPAddressingMode>::set(C::IPAddressingMode mode) const
{
  srt::multiScan100::EtherAddressingMode::Post::Request const request {
    static_cast<srt::multiScan100::EtherAddressingMode::Post::Request::EtherAddressingMode>(mode)
  };
  m_configurator.writeVariable<srt::multiScan100::EtherAddressingMode>(request);
}

// EtherIPMask
auto C::IPMaskAccess::get() const -> IpV4Address
{
  auto const mask = m_configurator.readVariable<srt::multiScan100::EtherIPMask>()._EtherIPMask;
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
  srt::multiScan100::EtherIPMask::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::multiScan100::EtherIPMask>(request);
}

// EtherIPGateAddress
auto C::IPGatewayAccess::get() const -> IpV4Address
{
  auto const gateway = m_configurator.readVariable<srt::multiScan100::EtherIPGateAddress>()._EtherIPGateAddress;
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
  srt::multiScan100::EtherIPGateAddress::Post::Request const request {
    std::array<int, 4> {static_cast<int>(bytes[0]), static_cast<int>(bytes[1]), static_cast<int>(bytes[2]), static_cast<int>(bytes[3])}
  };
  m_configurator.writeVariable<srt::multiScan100::EtherIPGateAddress>(request);
}

// EthernetUpdate
void C::EthernetUpdateAccess::apply() const
{
  m_configurator.post(srt::multiScan100::EthernetUpdate::methodName).execute();
}

// FieldEvaluationContour
auto C::FieldEvaluationContourAccess::get(int evaluationId) const -> std::vector<FieldEvaluationContour>
{
  srt::multiScan100::GetFieldEvaluationContour::Post::Request const request {evaluationId};

  auto const response =
    m_configurator.post(srt::multiScan100::GetFieldEvaluationContour::methodName)
      .withPlainRequestPayload(request)
      .execute()
      .withPlainResponsePayload<srt::multiScan100::GetFieldEvaluationContour::Post::Response>();

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
  std::vector<srt::multiScan100::SetFieldEvaluationContour::Post::Request::PointsItem> points;
  points.reserve(contour.points.size());
  for (auto const& point : contour.points)
  {
    points.emplace_back(static_cast<int>(point.x.millimeters()), static_cast<int>(point.y.millimeters()));
  }
  srt::multiScan100::SetFieldEvaluationContour::Post::Request const request {evaluationId, points, lowerZLimit, upperZLimit};

  auto const response =
    m_configurator.post(srt::multiScan100::SetFieldEvaluationContour::methodName)
      .withPlainRequestPayload(request)
      .execute()
      .withPlainResponsePayload<srt::multiScan100::SetFieldEvaluationContour::Post::Response>();

  if (response._ErrorCode != srt::multiScan100::SetFieldEvaluationContour::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to set SetFieldEvaluationContour: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

auto C::FieldEvaluationGroupStateAccess::get() const -> std::array<int, 48>
{
  return m_configurator.readVariable<srt::multiScan100::FieldEvaluationGroupState>()._FieldEvaluationGroupState;
}

auto C::FieldEvaluationResultAccess::get() const -> srt::multiScan100::FieldEvaluationResult::Get::Response::FieldEvaluationResult
{
  return m_configurator.readVariable<srt::multiScan100::FieldEvaluationResult>()._FieldEvaluationResult;
}

// FirmwareVersion
auto C::FirmwareVersionAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan100::FirmwareVersion>()._FirmwareVersion;
}

// FogFilter
void C::FogFilterAccess::enable() const
{
  srt::multiScan100::MCSenseLevel::Post::Request const request {1};
  m_configurator.writeVariable<srt::multiScan100::MCSenseLevel>(request);
}

void C::FogFilterAccess::disable() const
{
  srt::multiScan100::MCSenseLevel::Post::Request const request {0};
  m_configurator.writeVariable<srt::multiScan100::MCSenseLevel>(request);
}

auto C::FogFilterAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::MCSenseLevel>()._MCSenseLevel.value() != 0;
}

// ImuStreaming
void C::ImuStreamingAccess::configureCompact(IpV4Address const& destinationAddress, std::uint16_t destinationPort) const
{
  srt::multiScan100::ImuDataEthSettings::Post::Request const request {
    srt::multiScan100::ImuDataEthSettings::Post::Request::Protocol::Udp,
    {destinationAddress.bytes().begin(), destinationAddress.bytes().end()},
    destinationPort
  };
  m_configurator.writeVariable<srt::multiScan100::ImuDataEthSettings>(request);
}

void C::ImuStreamingAccess::enable() const
{
  srt::multiScan100::ImuDataEnable::Post::Request const request {true};
  m_configurator.writeVariable<srt::multiScan100::ImuDataEnable>(request);
}

void C::ImuStreamingAccess::disable() const
{
  srt::multiScan100::ImuDataEnable::Post::Request const request {false};
  m_configurator.writeVariable<srt::multiScan100::ImuDataEnable>(request);
}

auto C::ImuStreamingAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::ImuDataEnable>()._ImuDataEnable;
}

// IntervalFilter
auto C::IntervalFilterAccess::get() const -> NumericRange<2, 50, 2>
{
  return m_configurator.readVariable<srt::multiScan100::LFPintervalFilter>()._uiReductionFactor;
}

void C::IntervalFilterAccess::enable(NumericRange<2, 50, 2> value) const
{
  srt::multiScan100::LFPintervalFilter::Post::Request const request {true, value};
  m_configurator.writeVariable<srt::multiScan100::LFPintervalFilter>(request);
}

void C::IntervalFilterAccess::disable() const
{
  srt::multiScan100::LFPintervalFilter::Post::Request const request {false, {}};
  m_configurator.writeVariable<srt::multiScan100::LFPintervalFilter>(request);
}

auto C::IntervalFilterAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::LFPintervalFilter>()._bEnable;
}

// LocationName
auto C::LocationNameAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan100::LocationName>()._LocationName;
}

// MovingAverageFilter
auto C::MovingAverageFilterAccess::get() const -> NumericRange<2, 4, 3>
{
  return m_configurator.readVariable<srt::multiScan100::LFPmovingAveragingFilter>()._uiAveragingDepth;
}

void C::MovingAverageFilterAccess::enable(NumericRange<2, 4, 3> value) const
{
  srt::multiScan100::LFPmovingAveragingFilter::Post::Request const request {true, value};
  m_configurator.writeVariable<srt::multiScan100::LFPmovingAveragingFilter>(request);
}

void C::MovingAverageFilterAccess::disable() const
{
  srt::multiScan100::LFPmovingAveragingFilter::Post::Request const request {false, {}};
  m_configurator.writeVariable<srt::multiScan100::LFPmovingAveragingFilter>(request);
}

auto C::MovingAverageFilterAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::LFPmovingAveragingFilter>()._bEnable;
}

// OrderNumber
auto C::OrderNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan100::OrderNumber>()._OrderNumber;
}

// ParticleFilter
auto C::ParticleFilterAccess::threshold() const -> Distance
{
  return Distance::fromMillimeters(static_cast<float>(m_configurator.readVariable<srt::multiScan100::LFPparticle>()._uiThreshold.value()));
}

void C::ParticleFilterAccess::enable(Distance const& threshold) const
{
  srt::multiScan100::LFPparticle::Post::Request const request {true, static_cast<int>(threshold.millimeters())};
  m_configurator.writeVariable<srt::multiScan100::LFPparticle>(request);
}

void C::ParticleFilterAccess::disable() const
{
  srt::multiScan100::LFPparticle::Post::Request const request {false, {}};
  m_configurator.writeVariable<srt::multiScan100::LFPparticle>(request);
}

auto C::ParticleFilterAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::LFPparticle>()._bEnable;
}

// SensorPosition
auto C::SensorPositionAccess::get() const -> SensorPosition
{
  return m_configurator.getSensorPosition<srt::multiScan100::SensorPosition>();
}

void C::SensorPositionAccess::set(SensorPosition const& value) const
{
  m_configurator.setSensorPosition<srt::multiScan100::SensorPosition>(value);
}

// SerialNumber
auto C::SerialNumberAccess::get() const -> std::string
{
  return m_configurator.readVariable<srt::multiScan100::SerialNumber>()._SerialNumber;
}

// ScanDataStreaming
void C::ScanDataStreamingAccess::configureCompact(IpV4Address const& destinationAddress, std::uint16_t destinationPort) const
{
  srt::multiScan100::ScanDataEthSettings::Post::Request const request {
    srt::multiScan100::ScanDataEthSettings::Post::Request::Protocol::Udp,
    {destinationAddress.bytes().begin(), destinationAddress.bytes().end()},
    destinationPort
  };
  m_configurator.writeVariable<srt::multiScan100::ScanDataEthSettings>(request);
}

void C::ScanDataStreamingAccess::enable() const
{
  srt::multiScan100::ScanDataEnable::Post::Request const request {true};
  m_configurator.writeVariable<srt::multiScan100::ScanDataEnable>(request);
}

void C::ScanDataStreamingAccess::disable() const
{
  srt::multiScan100::ScanDataEnable::Post::Request const request {false};
  m_configurator.writeVariable<srt::multiScan100::ScanDataEnable>(request);
}

auto C::ScanDataStreamingAccess::getMode() const -> StreamingMode
{
  return static_cast<StreamingMode>(m_configurator.readVariable<srt::multiScan100::ScanDataFormat>()._ScanDataFormat);
}

auto C::ScanDataStreamingAccess::isEnabled() const -> bool
{
  return m_configurator.readVariable<srt::multiScan100::ScanDataEnable>()._ScanDataEnable;
}

void C::ScanDataStreamingAccess::setMode(StreamingMode mode) const
{
  srt::multiScan100::ScanDataFormat::Post::Request const request {static_cast<srt::multiScan100::ScanDataFormat::Post::Request::ScanDataFormat>(mode)};
  m_configurator.writeVariable<srt::multiScan100::ScanDataFormat>(request);
}

// SystemTime
auto C::SystemTimeAccess::get() const -> std::chrono::microseconds
{
  return m_configurator.getSystemTime<srt::multiScan100::LSPdatetime>();
}

auto C::SystemTimeAccess::set(std::chrono::microseconds timeSinceEpoch) const -> srt::multiScan100::LSPsetdatetime::Post::Response::ErrorCode
{
  return m_configurator.setSystemTime<srt::multiScan100::LSPsetdatetime>(timeSinceEpoch);
}

// TimeSynchronization
void C::TimeSynchronizationAccess::disable() const
{
  srt::multiScan100::TSCRole::Post::Request const request {srt::multiScan100::TSCRole::Post::Request::TSCRole::TxNone};
  m_configurator.writeVariable<srt::multiScan100::TSCRole>(request);
}

void C::TimeSynchronizationAccess::enableNtp(
  IpV4Address const& ntpServerAddress,
  srt::multiScan100::TSCTCtimezone::Post::Request::TSCTCtimezone timeZone,
  std::chrono::duration<int> updateInterval
) const
{
  {
    srt::multiScan100::TSCRole::Post::Request const request {srt::multiScan100::TSCRole::Post::Request::TSCRole::TxClient};
    m_configurator.writeVariable<srt::multiScan100::TSCRole>(request);
  }
  {
    srt::multiScan100::TSCTCSrvAddr::Post::Request const request {{ntpServerAddress.bytes().begin(), ntpServerAddress.bytes().end()}};
    m_configurator.writeVariable<srt::multiScan100::TSCTCSrvAddr>(request);
  }
  {
    srt::multiScan100::TSCTCtimezone::Post::Request const request {timeZone};
    m_configurator.writeVariable<srt::multiScan100::TSCTCtimezone>(request);
  }
  {
    srt::multiScan100::TSCTCupdatetime::Post::Request const request {static_cast<int>(std::chrono::seconds(updateInterval).count())};
    m_configurator.writeVariable<srt::multiScan100::TSCTCupdatetime>(request);
  }
}

void C::TimeSynchronizationAccess::enablePtp() const
{
  srt::multiScan100::TSCRole::Post::Request const request {srt::multiScan100::TSCRole::Post::Request::TSCRole::TxPtpSlave};
  m_configurator.writeVariable<srt::multiScan100::TSCRole>(request);
}

void MultiScan100Configurator::enableImuStreaming(IpV4Address const& destinationAddress, std::uint16_t destinationPort) const
{
  imuStreaming.configureCompact(destinationAddress, destinationPort);
  imuStreaming.enable();
}

void MultiScan100Configurator::enableScanDataStreaming(IpV4Address const& destinationAddress, std::uint16_t destinationPort) const
{
  scanDataStreaming.configureCompact(destinationAddress, destinationPort);
  scanDataStreaming.setMode(StreamingMode::Compact);
  scanDataStreaming.enable();
}

// Sensor methods
void MultiScan100Configurator::factoryReset() const
{
  post(srt::multiScan100::LoadFactoryDefaults::methodName).execute();
}

void MultiScan100Configurator::findMe(Duration const& activateFor) const
{
  srt::multiScan100::FindMe::Post::Request const request {static_cast<int>(activateFor.seconds())};
  post(srt::multiScan100::FindMe::methodName)
    .                                //
    withPlainRequestPayload(request) //
    .execute();
}

void MultiScan100Configurator::reboot() const
{
  post(srt::multiScan100::RebootDevice::methodName).execute();
}

void MultiScan100Configurator::startMeasurement() const
{
  auto const response =
    post(srt::multiScan100::mStartMeasure::methodName) //
      .execute()                                       //
      .withPlainResponsePayload<srt::multiScan100::mStartMeasure::Post::Response>();
  if (response._ErrorCode != srt::multiScan100::mStartMeasure::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to start measurement: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

void MultiScan100Configurator::stopMeasurement() const
{
  auto const response =
    post(srt::multiScan100::mStopMeasure::methodName) //
      .execute()                                      //
      .withPlainResponsePayload<srt::multiScan100::mStopMeasure::Post::Response>();
  if (response._ErrorCode != srt::multiScan100::mStopMeasure::Post::Response::ErrorCode::SopasErrNoErr)
  {
    throw std::runtime_error("Failed to stop measurement: " + std::to_string(static_cast<int>(response._ErrorCode)));
  }
}

void MultiScan100Configurator::persistParametersOnDevice() const
{
  post(srt::multiScan100::WriteEeprom::methodName).execute();
}

} // namespace sick

// NOLINTEND(cppcoreguidelines-avoid-magic-numbers, readability-magic-numbers)
