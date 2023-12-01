#ifndef PACKETS_HPP
#define PACKETS_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

struct PacketID {
    int packetNumber;
    std::string randomDigits;
    char randomLetter;
    std::string classificationDate;
    std::string townCodes;
};

struct GPSCoordinates {
    int degrees;
    int minutes;
    double seconds;
};

class Packets {
private:
    struct Node {
        PacketID id;
        GPSCoordinates longitude;
        GPSCoordinates latitude;
        std::string clientID;
        Node* prev;
        Node* next;
    };

    Node* head;
    Node* tail;
    int packetCount;

public:
    // Constructor
    Packets();

    // Destructor
    ~Packets();

    // Function to add a packet to the list
    void addPacket();

    // Function to display all packets in the list
    void displayPackets();

    // Function to display all packets in reverse order
    void displayReversePackets();

private:
    // Helper function to generate a random date after 2020
    std::string generateRandomDate();

    // Helper function to select a town code at random
    std::string getRandomTownCode();
};

#endif // PACKETS_HPP
