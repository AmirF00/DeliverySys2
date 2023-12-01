#include "packets.hpp"

int main() {
    // Create an instance of the Packets class
    Packets packets;

    // Add some packets to the list
    for (int i = 0; i < 10; ++i) {
        packets.addPacket();
    }

    // Display the packets
    std::cout << "Displaying packets:\n";
    packets.displayPackets();

    // Display the packets in reverse order
    std::cout << "\nDisplaying packets in reverse order:\n";
    packets.displayReversePackets();

    // Insert a packet at position 5
    packets.insertPacketAtPosition(5);

    // Display the packets after insertion
    std::cout << "\nDisplaying packets after insertion:\n";
    packets.displayPackets();

    // Delete a packet at position 2
    packets.deletePacketAtPosition(2);

    // Display the packets after deletion
    std::cout << "\nDisplaying packets after deletion:\n";
    packets.displayPackets();

    // Search for a packet by packet number
    int packetNumberToSearch = 7;
    Packets::Node* foundPacket = packets.searchPacketByNumber(packetNumberToSearch);
    if (foundPacket != nullptr) {
        std::cout << "\nPacket with packet number " << packetNumberToSearch << " found:\n";
        std::cout << "Packet ID: " << foundPacket->id.packetNumber << "\n";
        std::cout << "Longitude: " << foundPacket->longitude.degrees << "º "
                  << foundPacket->longitude.minutes << "' " << foundPacket->longitude.seconds << "\"\n";
        std::cout << "Latitude: " << foundPacket->latitude.degrees << "º "
                  << foundPacket->latitude.minutes << "' " << foundPacket->latitude.seconds << "\"\n";
    } else {
        std::cout << "\nPacket with packet number " << packetNumberToSearch << " not found.\n";
    }

    // Peek at the front packet
    Packets::Node* frontPacket = packets.peekFront();
    if (frontPacket != nullptr) {
        std::cout << "\nPeek at the front packet:\n";
        std::cout << "Packet ID: " << frontPacket->id.packetNumber << "\n";
    } else {
        std::cout << "\nThe list is empty.\n";
    }

    // Peek at the end packet
    Packets::Node* endPacket = packets.peekEnd();
    if (endPacket != nullptr) {
        std::cout << "\nPeek at the end packet:\n";
        std::cout << "Packet ID: " << endPacket->id.packetNumber << "\n";
    } else {
        std::cout << "\nThe list is empty.\n";
    }

    return 0;
}
