#include "client.h"

Client::Client() {
    // Below code is same as for server.cpp
    int optval = 1; // How many options we will pass to reuseport
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(socket_, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof(optval));
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET; // AF_INET means standard iPv4 protocol
    address.sin_addr.s_addr = INADDR_ANY; // We can listen to any ip address
    address.sin_port = htons(1969);

    // Convert IP address from text to binary form
    inet_pton(AF_INET, "192.168.1.66", &address.sin_addr);

    // Connect socket to address of server
    ::connect(socket_, (struct sockaddr *)&address, addrlen);
}


void Client::send(const std::string &msg) {
    // Send message - with 0 flags, send is equivalent to write
    ::send(socket_, msg.c_str(), msg.size(), 0);
}
