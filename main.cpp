#include "server/SimpleServer.hpp"

int main()
{
    SimpleServer myServer(NULL, "8080");
    myServer.launch();
    return 0;
}