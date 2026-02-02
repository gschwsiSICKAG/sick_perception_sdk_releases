/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/picoScan100_learning_examples.md

#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>
#include <sick_perception_sdk/compact_receiver/socket/UdpListeningSocket.hpp>

#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
  // Create a buffer to receive data. This will be reused for each receive call.
  std::vector<std::uint8_t> buffer(65'535);
  sick::UdpListeningSocket socket {2115}; // Listen on port 2115 for UDP packets (format Compact)

  while (true)
  {
    // Receive new data from the socket
    auto numberOfReceivedBytes = socket.receive(buffer);
    if (numberOfReceivedBytes == 0)
    {
      continue;
    }

    try
    {
      // The UDP packets of picoScan always contain one complete Compact telegram so we parse each packet into `ScanData`.
      auto const scanData = sick::compact::scan_data::Parser::validateAndParse(
        buffer.cbegin(),
        buffer.cbegin() + static_cast<std::vector<std::uint8_t>::difference_type>(numberOfReceivedBytes),
        true
      );
      std::cout << "Received scan data with " << scanData.modules.size() << " modules." << '\n';
    }
    catch (std::exception const& e)
    {
      std::cerr << "Failed to parse scan data: " << e.what() << '\n';
    }
  }

  return 0;
}
