# webserv
webserv project 42 School

I. Create a small version of a webserv:
  1. Socket Class
  2. Server Class
  3. Only 1 port handling (1 server).
  4. Multiple client connection.
  5. epoll() function implementation.
  6. Server just prints the message (no method handling for now).


Later:
  1. Configuration file format.
  2. Configuration file parsing.
  3. Handling multiple ports and servers.
  4. HTTP methods handling.
  5. Understand how folder structure should look like.
  6. Understand html files.
  7. Understand CGI.


Don't forget:
  1. To check that all the FDs have been properly closed when exiting the program.
  2. Add exceptions to the Classes.
  3. Handle partial send();
  4. Handle empty recv();
  5. Agree on the error management (exit, exceptions, error messages, etc.)
  6. Handling epoll events (Q: is it defined in HTTP protocol?):
          EPOLLIN: There is data to read.
          EPOLLOUT: The file descriptor is writable.
          EPOLLERR: An error occurred.
          EPOLLHUP: The file descriptor has been hung up.
          EPOLLRDHUP: Peer side of the connection closed (only for stream sockets).
          EPOLLET: Edge-triggered behavior (if set).
