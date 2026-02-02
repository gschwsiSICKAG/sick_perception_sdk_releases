# multiScan200 Examples

- [Configuration](#configuration)
- [Data Streaming](#data-streaming)
- [Data streaming ROI](#data-streaming-roi)
- [Low-level streaming](#low-level-streaming)
- [Diagnosis](#diagnosis)
- [Write to PCD file](#write-to-pcd-file)
- [Change IP address](#change-ip-address)
- [Run examples](#run-examples)

## Configuration

This example [multiScan200/configuration.cpp](multiScan200/configuration.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Reads and prints the following information from the connected device: device type, firmware version, location name, order number, sensor position, serial number, system time, and device IP address
- Reads operational hours from the device
- Sets echo filter to StrongestEcho
- Configures horizontal angle range filter (start: -120°, stop: 120°, beam increment: 1)
- Configures streaming mode to Compact format
- Expected device configuration: Factory defaults, licenses for used functions available

## Data Streaming

This example [multiScan200/data_streaming.cpp](multiScan200/data_streaming.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Configures streaming mode to Compact format
- Receives and prints point cloud data with Cartesian coordinates and intensity
- Receives and prints ambient light sensor data
- Receives and prints IMU data
- Data is streamed over TCP on ports `2115` (point cloud), `2116` (ambient light), and `2117` (IMU)
- Expected device configuration: Factory defaults, licenses for used functions available

## Data streaming ROI

This example [multiScan200/data_streaming_roi.cpp](multiScan200/data_streaming_roi.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Enables measurement data streaming (TCP) to IP address `192.168.0.100`, port `2115`
- Configures region of interest (ROI) filters for azimuth (-1° to 1°) and elevation (-1° to 1°)
- Receives and prints all points within the defined ROI
- Expected device configuration: Factory defaults, licenses for used functions available

## Low-level streaming

This example [multiScan200/low_level_streaming.cpp](multiScan200/low_level_streaming.cpp)

- Establishes a TCP connection to the device using the specified IP address or the default IP address (192.168.0.1 if no IP is specified) on port `2115`
- Receives raw data from the socket using a reusable buffer
- Extracts Compact telegrams from the received data stream using StreamExtractor
- Parses and validates the scan data telegrams
- Prints the number of modules in each received scan data frame
- Demonstrates low-level handling of TCP streaming data without using high-level device configuration APIs
- Expected device configuration: Device streaming Compact data on TCP port 2115

## Diagnosis

This example [multiScan200/diagnosis.cpp](multiScan200/diagnosis.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Reads and prints device information: device type, device state, firmware version, location name, order number, sensor position, and serial number
- Calls find-me function; the device LEDs blink for 5 seconds
- Configures streaming mode to Compact format
- Continuously monitors and prints device state and temperature every 5 seconds
- Receives and counts scan data telegrams
- Prints link to diagnosis overview: [http://192.168.0.1/#/diagnosis/overview](http://192.168.0.1/#/diagnosis/overview)
- Expected device configuration: Factory defaults, licenses for used functions available

## Write to PCD file

This example [multiScan200/write_to_pcd_file.cpp](multiScan200/write_to_pcd_file.cpp)

- Establishes a connection to the device using the specified IP address (CMD interface) or the default IP address (192.168.0.1 if no IP is specified)
- Configures streaming mode to Compact format
- Creates a new PCD file with the latest point cloud every time a new frame is received
- PCD files are written to a `pcd_files` directory in the current working directory
- Expected device configuration: Factory defaults, licenses for used functions available

## Change IP address

This example [multiScan200/change_ip_address.cpp](multiScan200/change_ip_address.cpp)

- Establishes a connection to the device using the initial IP address (192.168.0.1)
- Reads and prints the current IP address configuration
- Configures new static IP settings (IP address: 192.168.0.2, subnet mask: 255.255.255.0, gateway: 0.0.0.0)
- Applies the IP configuration changes and waits for the sensor
- Reconnects to the device using the new IP address (192.168.0.2)
- Expected device configuration: Factory defaults

## Run examples

Depending on the selected example and the operating system, you can start the executable as follows:  

- **Linux:** `./examples/multiScan200/multiScan200_<example name>_example`
- **Windows:** `"C:\examples\multiScan200\multiScan200_<example name>_example.exe"`
