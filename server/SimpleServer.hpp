#ifndef SIMPLESERVER_HPP
#define SIMPLESERVER_HPP

#include "../socket/SimpleSocket.hpp"
#include <unistd.h>

#define BACKLOG 10
#define BUFFER_SIZE 30000

class SimpleServer {
    private:
        SimpleSocket *ListeningSocket;
        char buffer[BUFFER_SIZE];
        int new_socket;

    public:
        SimpleServer(const char *input_node, const char *input_service);
        void launch();
        // SimpleSocket *get_serv_socket(); -> not sure if this is needed
};

#endif