// van.hpp

#ifndef VAN_HPP
#define VAN_HPP

#include "packets.hpp"

class Van {
private:
    static const int MAX_CAPACITY = 86;

    struct Node {
        Packets::Node* data;
        Node* next;
    };

    Node* top; // For regular packets
    Node* vipTop; // For VIP packets

public:
    Van();  // Constructor
    ~Van(); // Destructor

    void loadPacket(Packets::Node* packet);
    void unloadPackets();
    void loadPacketVIP(Packets::Node* packet);
    void unloadVIP();

    bool isFullyLoaded() const;
    bool isVIPFullyLoaded() const;
    bool isEmpty() const;
    bool isVIPEmpty() const;

    // Getters and setters
    Node* getTop() const;
    void setTop(Node* newTop);

    Node* getVIPTop() const;
    void setVIPTop(Node* newTop);

    // Helper function to get the size of the stack
    int size() const;
    int VIPSize() const;
};

#endif // VAN_HPP
