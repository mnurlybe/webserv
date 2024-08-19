#ifndef SIMPLESOCKET_HPP
#define SIMPLESOCKET_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>

class SimpleSocket
{
    private:
        int socket_fd;
        struct sockaddr_in address;
        int connection;

    public:
        SimpleSocket(int domain, int socket_type, int protocol, int port, u_long interface);

        // member functions
        void start_listening(int backlog);
        //getters
        struct sockaddr_in get_address();
        int get_socket();
        int get_connection();
        
};

/**
 * 1. Create a socket; -> SimpleSocket Class
 * 2. Bind a socket to network; -> SimpleSocket Class
 * 3. Listening socket;
 * 
 * a. Add exceptions to a SimpleSocket Class;
 */

#endif