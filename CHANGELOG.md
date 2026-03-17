# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [0.5.0] - 2026-0x-xx

### Breaking Changes

- Moved `Socket` and `Compact*Stream` classes to `drivers` library.
- Renamed library `compact_receiver` to `compact_format`.
- `PointCloud` was renamed to `MultiEchoPointCloud` and extends the two row and column dimensions by a third echo dimension.
- Harmonized the API of the `drivers` library.
- `PackageLossMonitor` was renamed to `DataLossMonitor` and its API changed.
- Driver classes are renamed to `Driver` in the device specific namespace. This is analogous to the naming of the `Parser` classes for the Compact formats.

### Added

- Support for multiScan200 configuration and compact data format parsing (telegram types 3 and 6).
- Benchmarks for `ByteView` and compact parsers.
- Sensor family and sensor variants handling.

### Changed

- Set minimum required CMake version to 3.22 (from 3.24).

### Fixed

- Fixed bugs where the `DataLossMonitor`s did not count lost data correctly.

## [0.4.0] - 2026-02-11

### First version for testing

- Modern C++17 SDK for SICK LiDAR sensors (multiScan100, picoScan100, LRS4000 families)
- Receive scan data, IMU data, and encoder data in SICK Compact format over UDP or TCP
- Sensor configuration via REST API
- Support for Linux and Windows
- Dependency management via Conan 2
- Multiple examples for fast prototyping
