# picoScan100 Learning Examples

- [Configuration](#configuration)
- [Data streaming](#data-streaming)
- [Data streaming ROI](#data-streaming-roi)
- [Low-level streaming](#low-level-streaming)
- [Diagnosis](#diagnosis)
- [Multiple devices](#multiple-devices)
- [Object detection](#object-detection)
- [Segmented data](#segmented-data)
- [Write to PCD file](#write-to-pcd-file)
- [Change IP address](#change-ip-address)
- [Run examples](#run-examples)

## Configuration

This example [picoScan100/configuration.cpp](picoScan100/configuration.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Reads and prints the following information from the connected device: device type, firmware version, location name, order number, serial number, system time, and device IP address
- Reads operational hours from the device
- Sets echo filter to LastEcho
- Configures angle range filter (start: -90°, stop: 90°, beam increment: 1)
- Enables measurement data streaming (UDP) to IP address `192.168.0.100`, port `2115`
- Expected device configuration: Factory defaults, licenses for used functions available

## Data streaming

This example [picoScan100/data_streaming.cpp](picoScan100/data_streaming.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Enables measurement data streaming (UDP) to IP address `192.168.0.100`, port `2115`
- Enables IMU data streaming (UDP) to IP address `192.168.0.100`, port `7503`
- Enables encoder data streaming (UDP) to IP address `192.168.0.100`, port `7504`
- Receives and prints metadata for full frame point cloud data, IMU data, and encoder data
- Expected device configuration: Factory defaults, licenses for used functions available

## Data streaming ROI

This example [picoScan100/data_streaming_roi.cpp](picoScan100/data_streaming_roi.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Enables measurement data streaming (UDP) to IP address `192.168.0.100`, port `2115`
- Configures region of interest (ROI) filters for azimuth (-1° to 1°) and elevation (-1° to 1°)
- Receives and prints all points within the defined ROI
- Expected device configuration: Factory defaults, licenses for used functions available

## Low-level streaming

This example [picoScan100/low_level_streaming.cpp](picoScan100/low_level_streaming.cpp)

- Listens for UDP packets on port `2115` (format Compact)
- Receives raw data from the socket using a reusable buffer
- Parses and validates Compact telegrams from the received data
- Prints the number of modules in each received scan data frame
- Demonstrates low-level handling of UDP streaming data without using high-level device configuration APIs
- Expected device configuration: Device streaming Compact data on UDP port 2115

## Diagnosis

This example [picoScan100/diagnosis.cpp](picoScan100/diagnosis.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Reads and prints device information: device type, device state, firmware version, location name, order number, serial number, and system time
- Calls find-me function; the device LEDs blink for 5 seconds
- Starts measurement
- Enables measurement data streaming (UDP) to IP address `192.168.0.100`, port `2115`
- Continuously monitors and prints device state, temperature, and contamination data every 5 seconds
- Monitors and reports lost data (telegrams, frames, and segments)
- Prints link to diagnosis overview: [http://192.168.0.1/#/diagnosis/overview](http://192.168.0.1/#/diagnosis/overview)
- Expected device configuration: Factory defaults, licenses for used functions available

## Multiple devices

This example [picoScan100/multiple_devices.cpp](picoScan100/multiple_devices.cpp)

- Establishes connections to both devices (192.168.0.1, 192.168.0.2)
- Reads and prints the IP addresses from both connected devices
- Sets the measurement data output format to _Compact_
- Enables measurement data streaming (UDP) to IP address `192.168.0.100`, ports `2115` and `2116`
- Prints metadata for full frame point cloud data from both devices
- Expected device configuration: Factory defaults, licenses for used functions available

## Object detection

This example [picoScan100/object_detection.cpp](picoScan100/object_detection.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Reads and prints evaluation group states for all active fields
- Reads and prints evaluation field states and results
- Reads field evaluation contours (field points and z-limits)
- Scales all x-y coordinates of field contours by a factor of 0.5
- Writes the modified field contours back to the device
- Expected device configuration: At least one field stored in object detection, object detection license available

## Segmented data

This example [picoScan100/segmented_data.cpp](picoScan100/segmented_data.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Reads and prints the following information from the connected device: product name, part number, serial number, firmware version, system time, and device IP address
- Sets the measurement data output format to _Compact_
- Enables measurement data streaming (UDP) to IP address `192.168.0.100`, port `2115`
- Prints metadata for segmented measurement data
- Expected device configuration: Factory defaults, licenses for used functions available

## Write to PCD file

This example [picoScan100/write_to_pcd_file.cpp](picoScan100/write_to_pcd_file.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Reads and prints the following information from the connected device: product name, part number, serial number, firmware version, system time, and device IP address
- Sets the measurement data output format to _Compact_
- Enables measurement data streaming (UDP) to IP address `192.168.0.100`, port `2115`
- Creates a new PCD file with the latest frame every second
- Expected device configuration: Factory defaults, licenses for used functions available

## Change IP address

This example [picoScan100/change_ip_address.cpp](picoScan100/change_ip_address.cpp)

- Establishes a connection to the device using the initial IP address (192.168.0.1)
- Reads and prints the current IP address configuration
- Configures new static IP settings (IP address: 192.168.0.2, subnet mask: 255.255.255.0, gateway: 0.0.0.0)
- Applies the IP configuration changes and waits for the sensor
- Reconnects to the device using the new IP address (192.168.0.2)
- Expected device configuration: Factory defaults

## Run examples

Depending on the selected example and the operating system, you can start the executable as follows:  

- **Linux:** `./examples/picoScan100/picoScan100_<example name>_example`
- **Windows:** `"C:\examples\picoScan100\picoScan100_<example name>_example.exe"`
