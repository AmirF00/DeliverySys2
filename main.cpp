#include "packets.hpp"

int main() {
    // Create instances of the Packets class
    Packets packets;
    Packets packetVIP;

    // Add some packets to the original list
    for (int i = 0; i < 10; ++i) {
        packets.addPacket();
    }

    // Display original packets
    std::cout << "Original packets:\n";
    packets.displayPackets();

    // Move a packet with packet number 3 to the VIP list
    packets.movePacketToVIPList(3, packetVIP);

    // Display packets after moving to VIP list
    std::cout << "\nPackets after moving to VIP list:\n";
    packets.displayPackets();

    // Display VIP packets
    std::cout << "\nVIP packets:\n";
    packetVIP.displayPackets();

    return 0;
}
