#include "SimpleServer.hpp"

SimpleServer::SimpleServer(const char *input_node, const char *input_service) {
    ListeningSocket = new SimpleSocket(input_node, input_service);
}

// SimpleSocket *SimpleServer::get_serv_socket() {
//     return ListeningSocket;
// }

void SimpleServer::launch()
{
    while (true)
    {
        std::cout << "----WAITING-----" << std::endl;


        struct addrinfo address = ListeningSocket->get_address();
        int addrlen = sizeof(address);

        // accept a new connection by creating a new socket
        new_socket = accept(ListeningSocket->get_socket(), 
                    (struct sockaddr *)&address, (socklen_t *)&addrlen);
        
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        if(valread < 0)
            std::cout << "No bytes are read." << std::endl;
        
        std::cout << buffer << std::endl;

        const char *hello = "Hello from the server";
        write(new_socket, hello, strlen(hello));

        close(new_socket);

        std::cout << "----DONE-----" << std::endl;
    }
}

