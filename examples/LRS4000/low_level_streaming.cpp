/*
Copyright (c) 2026 SICK AG
SPDX-License-Identifier: MIT
*/

// For a description of this example, refer to: examples/LRS4000_learning_examples.md

#include "../examples_helper.hpp"
#include <sick_perception_sdk/compact_receiver/ScanDataParser.hpp>
#include <sick_perception_sdk/compact_receiver/StreamExtractor.hpp>
#include <sick_perception_sdk/compact_receiver/socket/TcpClientSocket.hpp>

#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
  auto const deviceAddress = sick::examples::getDeviceAddress(argc, argv);

  // Create a buffer to receive data. This will be reused for each receive call.
  std::vector<std::uint8_t> buffer(4'000'000);

  sick::TcpClientSocket socket {deviceAddress, 2115};
  socket.openConnection();

  sick::compact::StreamExtractor extractor;

  while (true)
  {
    // Receive new data from the socket
    auto const numberOfReceivedBytes = socket.receive(buffer);
    if (numberOfReceivedBytes == 0)
    {
      continue;
    }

    // Extract telegrams from the received data. The extractor will collect data if the buffer contains partial Compact telegrams.
    auto const telegrams =
      extractor.extractTelegrams(buffer.cbegin(), buffer.cbegin() + static_cast<std::vector<std::uint8_t>::difference_type>(numberOfReceivedBytes));
    if (telegrams.empty())
    {
      continue;
    }

    // Here we parse only the first telegram for demonstration purposes.
    try
    {
      auto const scanData = sick::compact::scan_data::Parser::validateAndParse(telegrams[0].cbegin(), telegrams[0].cend(), true);
      std::cout << "Received scan data with " << scanData.modules.size() << " modules." << '\n';
    }
    catch (std::exception const& e)
    {
      std::cerr << "Failed to parse scan data: " << e.what() << '\n';
    }
  }

  return 0;
}
