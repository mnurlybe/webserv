#include "SimpleSocket.hpp"

// default Constructor
SimpleSocket::SimpleSocket(int domain, int socket_type, int protocol, int port, u_long interface)
{
    // define address structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    // get socket file descriptor
    socket_fd = socket(domain, socket_type, protocol);
    // #add exception
    // establish connection to a network
    connection = bind(socket_fd, (struct sockaddr *)&address, sizeof(address));
    // #add exception
}

//member functions
void SimpleSocket::start_listening(int backlog)
{
    listen(get_socket(), backlog);
    // #add exception
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