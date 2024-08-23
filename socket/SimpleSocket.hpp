#ifndef SIMPLESOCKET_HPP
#define SIMPLESOCKET_HPP

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <string.h>

class SimpleSocket
{
    private:
        int socket_fd;
        struct sockaddr_in address;
        int connection;
        int listening;

    public:
        SimpleSocket(int domain, int socket_type, int protocol, int port, u_long interface, int backlog);

        //getters
        struct sockaddr_in get_address();
        int get_socket();
        int get_connection();
        
};

/**
 * 1. Create a socket; -> SimpleSocket Class -> done
 * 2. Bind a socket to network; -> SimpleSocket Class -> done
 * 3. Listening socket; -> done
 * 
 * a. Add exceptions to a SimpleSocket Class;
 */

#endif