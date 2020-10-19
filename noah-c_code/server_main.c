#include "server.h"

int main (int argc, char** argv)
{
    server_init();

    int client_socket;
    while (1)
    {
        client_socket = server_accept();

        char *success_message = "Successfully connected to server.";
        server_send(client_socket, success_message);
    }
}