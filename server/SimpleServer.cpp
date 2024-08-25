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

    struct epoll_event event;
    int ls_fd = ListeningSocket->get_socket();
    // define which events to monitor
    event.events = EPOLLIN;
    event.data.fd = ls_fd;

    // Store the listening socket file descriptor
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, ls_fd, &event);
    // ***add epoll_ctl() error management

    struct epoll_event occurred_events[NUM_OF_EVENTS];
    while (true)
    {
        int num_of_occurred_events = epoll_wait(epoll_fd, occurred_events, NUM_OF_EVENTS, -1);
        std::cout << num_of_occurred_events << "NUM OF OCCURED EVENTS" << std::endl;
        // ***add epoll_wait() error management
        for (int i = 0; i < num_of_occurred_events; ++i)
        {
            if (occurred_events[i].data.fd == ls_fd)
            {
                struct addrinfo address = ListeningSocket->get_address();
                int addrlen = sizeof(address);

                // accept a new connection by creating a new socket
                new_socket = accept(ListeningSocket->get_socket(), 
                            (struct sockaddr *)&address, (socklen_t *)&addrlen);
                if (new_socket != -1)
                    std::cout << new_socket << "NEW CLIENT ESTABLISHED" << std::endl;
                // ***add new_socket == -1 error management
                event.events = EPOLLIN;
                event.data.fd = new_socket;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_socket, &event);
            } 
            else 
            {
                int valread = recv(occurred_events[i].data.fd, buffer, BUFFER_SIZE, 0);
                if(valread < 0)
                    std::cout << "No bytes are read." << std::endl;
                
                std::cout << buffer << std::endl;

                const char *hello = "Hello from the server";
                send(occurred_events[i].data.fd, hello, strlen(hello), 0);
            }
        }

    }

    close(ListeningSocket->get_socket());
    close(epoll_fd);
}



