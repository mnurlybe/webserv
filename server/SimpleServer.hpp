#ifndef SIMPLESERVER_HPP
#define SIMPLESERVER_HPP

#include "../socket/SimpleSocket.hpp"
#include <sys/epoll.h>

#define BACKLOG 10
#define BUFFER_SIZE 30000
#define NUM_OF_EVENTS 30 

class SimpleServer {
    private:
        SimpleSocket *ListeningSocket;
        char buffer[BUFFER_SIZE];
        int new_socket;

        int epoll_fd;
        struct epoll_event event;

    public:
        SimpleServer(const char *input_node, const char *input_service);
        void launch_simple();
        void launch_extended();
        // SimpleSocket *get_serv_socket(); -> not sure if this is needed
};

#endif