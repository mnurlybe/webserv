#include "SimpleServer.hpp"

SimpleServer::SimpleServer(const char *input_node, const char *input_service) {
    ListeningSocket = new SimpleSocket(input_node, input_service);
}

// SimpleSocket *SimpleServer::get_serv_socket() {
//     return ListeningSocket;
// }

void SimpleServer::launch_simple()
{
    while (true)
    {
        std::cout << "----WAITING-----" << std::endl;


        struct addrinfo address = ListeningSocket->get_address();
        int addrlen = sizeof(address);

        // accept a new connection by creating a new socket
        new_socket = accept(ListeningSocket->get_socket(), 
                    (struct sockaddr *)&address, (socklen_t *)&addrlen);
        
        int valread = recv(new_socket, buffer, BUFFER_SIZE, 0);
        if(valread < 0)
            std::cout << "No bytes are read." << std::endl;
        
        std::cout << buffer << std::endl;

        const char *hello = "Hello from the server";
        send(new_socket, hello, strlen(hello), 0);

        close(new_socket);
        close(Listening)

        std::cout << "----DONE-----" << std::endl;
    }
}

void SimpleServer::launch_extended()
{
    epoll_fd = epoll_create(2);
    if (epoll_fd < 0) {
        std::cerr << "Error: epoll_create()" << std::endl;
        exit(1);
    }

    // define which events to monitor
    event.events = EPOLLIN;
    // Store the listening socket file descriptor
    event.data.fd = ListeningSocket->get_socket();

    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, ListeningSocket->get_socket(), &event);
    // ***add epoll_ctl() error management

    while (true)
    {
        int wait_event = epoll_wait(epoll_fd, event, NUM_OF_EVENTS, -1);
        // ***add epoll_wait() error management

    }


    close(epoll_fd);
}



