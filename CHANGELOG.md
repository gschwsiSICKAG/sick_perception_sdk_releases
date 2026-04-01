# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.5.0] - 2026-04-01

### Added

- Support for multiScan200.
- Added support for UDP multicast.
- More examples.

## Breaking Changes

- Full refactoring of the point cloud API.
- Support for device families and multiple versions of a device. This breaks sensor configuration API.
- Driver callbacks are renamed for consistency.
- Package loss handling is now called "data loss" and API was changed.
- Library compact_receiver was renamed to compact_format.
- Socket wrappers were moved to common.
- Thread handling was moved to drivers.

## [0.4.0] - 2026-02-13

First release of the sick_perception_sdk package. This release includes the following features:

- Initial implementation of the SDK components for interacting with SICK sensors.
- Basic documentation and examples for using the sick_perception_sdk.
- Support for the SICK LiDAR sensors: picoScan100, multiScan100, and LRS4000.
