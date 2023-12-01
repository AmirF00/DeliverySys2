#include "packets.hpp"

int main() {
    // Create an instance of the Packets class
    Packets packets;

    // Add some packets to the list
    for (int i = 0; i < 4700; ++i) {
        packets.addPacket();
    }

    // Display the packets
    std::cout << "Displaying packets:\n";
    packets.displayPackets();

    // Display the packets in reverse order
    //std::cout << "\nDisplaying packets in reverse order:\n";
    //packets.displayReversePackets();

    return 0;
}
