#include "packets.hpp"

// Constructor
Packets::Packets() : head(nullptr), tail(nullptr), packetCount(0) {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Destructor
Packets::~Packets() {
    Node* current = head;
    Node* next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}

// Function to add a packet to the list
void Packets::addPacket() {
    // Create a new packet
    Node* newNode = new Node;
    
    // Increment packet number
    ++packetCount;

    // Set packet ID
    newNode->id.packetNumber = packetCount;
    newNode->id.randomDigits = std::to_string(std::rand() % 1000);
    newNode->id.randomLetter = 'A' + std::rand() % 26;
    newNode->id.classificationDate = generateRandomDate();
    newNode->id.townCodes = getRandomTownCode();

    // Set GPS coordinates for longitude
    newNode->longitude.degrees = 40 + (rand() % 10);
    newNode->longitude.minutes = 28 + (rand() % 60);
    newNode->longitude.seconds = 30.0 + (rand() % 60);

    // Set GPS coordinates for latitude
    newNode->latitude.degrees = 28 + (rand() % 10);
    newNode->latitude.minutes = 20 + (rand() % 60);
    newNode->latitude.seconds = 45.0 + (rand() % 60);

    // Set client ID
    newNode->clientID = std::to_string(std::rand() % 10000000) + static_cast<char>('A' + std::rand() % 26);


    // Update links
    newNode->prev = tail;
    newNode->next = nullptr;

    if (tail != nullptr) {
        tail->next = newNode;
    } else {
        // The list is empty, set the head
        head = newNode;
    }

    // Update tail
    tail = newNode;
}

// Function to display all packets in the list
void Packets::displayPackets() {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Packet Number: " << current->id.packetNumber << "\n";
        std::cout << "Packet ID: " << current->id.packetNumber << "-" << current->id.randomDigits
                  << "-" << current->id.randomLetter << "-" << current->id.classificationDate
                  << "-" << current->id.townCodes << "\n";
        std::cout << "Longitude: " << current->longitude.degrees << "º "
                  << current->longitude.minutes << "' " << current->longitude.seconds << "\"\n";
        std::cout << "Latitude: " << current->latitude.degrees << "º "
                  << current->latitude.minutes << "' " << current->latitude.seconds << "\"\n";
        std::cout << "Client ID: " << current->clientID << "\n\n";

        current = current->next;
    }
}

// Helper function to generate a random date after 2020
std::string Packets::generateRandomDate() {
    const int startYear = 2021; // Change as needed
    const int endYear = 2023;   // Change as needed

    int year = startYear + std::rand() % (endYear - startYear + 1);
    int month = 1 + std::rand() % 12;
    int day = 1 + std::rand() % 31;

    return std::to_string(day) + "-" + std::to_string(month) + "-" + std::to_string(year);
}

// Helper function to select a town code at random
std::string Packets::getRandomTownCode() {
    const std::vector<std::string> townCodes = {"ADT", "PER", "ROD", "VDT", "CDV", "MOZ", "CDB", "ALD", "SAL"};
    int randomIndex = std::rand() % townCodes.size();
    return townCodes[randomIndex];
}
