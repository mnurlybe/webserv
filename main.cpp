#include "server/SimpleServer.hpp"

int main()
{
    SimpleServer myServer(NULL, "8080");
    myServer.launch_extended();
    return 0;
}