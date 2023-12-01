#include "packets.hpp"

int main() {
    // Create an instance of the Packets class
    Packets packets;

    // Add some packets to the list
    for (int i = 0; i < 10; ++i) {
        packets.addPacket();
    }

    // Display the packets
    packets.displayPackets();

    return 0;
}
