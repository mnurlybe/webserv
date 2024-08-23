#ifndef SIMPLESERVER_HPP
#define SIMPLESERVER_HPP

#include "../socket/SimpleSocket.hpp"
#include <unistd.h>

class SimpleServer {
    private:
        SimpleSocket *ListeningSocket;
        char buffer[30000];
        int new_socket;

    public:
        SimpleServer();
        SimpleSocket *get_serv_socket();
        void launch();
};


#endif