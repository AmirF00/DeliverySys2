#include "packets.hpp"
#include "van.hpp"
#include <thread>
#include <vector>

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

    // Simulate multi-threaded delivery with multiple vans
    const int numVans = 3; // You can adjust the number of vans as needed
    std::vector<std::thread> vanThreads;

    for (int i = 0; i < numVans; ++i) {
        Van van;
        vanThreads.emplace_back([&]() {
            // Load packets into the van
            for (int j = 0; j < 5; ++j) { // Load 5 packets into each van
                van.loadPacket(packets.peekFront());
                packets.deletePacketAtPosition(1);
            }

            // Display the packets loaded into the van
            std::cout << "Van " << i + 1 << " packets:\n";
            van.unloadPackets();
        });
    }

    // Wait for all van threads to finish
    for (auto& thread : vanThreads) {
        thread.join();
    }

    return 0;
}
