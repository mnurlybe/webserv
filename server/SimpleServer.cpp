#include "SimpleServer.hpp"

SimpleServer::SimpleServer(){
    ListeningSocket = new SimpleSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);
}

SimpleSocket *SimpleServer::get_serv_socket(){
    return ListeningSocket;
}

void SimpleServer::launch()
{
    while (true)
    {
        std::cout << "----WAITING-----" << std::endl;
        struct sockaddr_in address = get_serv_socket()->get_address();
        int addrlen = sizeof(address);
        // accept a new connection by creating a new socket
        new_socket = accept(get_serv_socket()->get_socket(), 
                    (struct sockaddr *)&address, (socklen_t *)&addrlen);
        
        int valread = read(new_socket, buffer, 30000);
        if(valread < 0)
            std::cout << "No bytes are read." << std::endl;
        
        std::cout << buffer << std::endl;

        const char *hello = "Hello from the server";
        write(new_socket, hello, strlen(hello));
        close(new_socket);
        std::cout << "----DONE-----" << std::endl;
    }

}

