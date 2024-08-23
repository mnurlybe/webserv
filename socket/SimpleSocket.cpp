#include "SimpleSocket.hpp"

// default Constructor
SimpleSocket::SimpleSocket(int domain, int socket_type, int protocol, int port, u_long interface, int backlog)
{
    // define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    // get socket file descriptor
    socket_fd = socket(domain, socket_type, protocol);
    // #add exception
    if (socket_fd < 0)
        std::cout << "Error: socket()" << std::endl;
    else
        std::cout << "Socket is created." << std::endl;
    // establish connection to a network
    connection = bind(socket_fd, (struct sockaddr *)&address, sizeof(address));
    // #add exception
    if (connection < 0)
        std::cout << "Error: bind()" << std::endl;
    else
        std::cout << "Socket is connected to a network." << std::endl;

    listening = listen(get_socket(), backlog) < 0;
    if (listening < 0)
        std::cout << "Error: listen()" << std::endl;
    else
        std::cout << "Socket started listening." << std::endl;
}

// getters
struct sockaddr_in SimpleSocket::get_address() {
    return address;
}

int SimpleSocket::get_socket() {
    return socket_fd;
}

int SimpleSocket::get_connection() {
    return connection;
}