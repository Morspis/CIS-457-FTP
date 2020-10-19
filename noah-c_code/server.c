#include "server.h"

#define MAX_QUEUE 3

//making the socket information available to every function in this scope.
int server_socket;

void server_init()
{
    // this creates the server socket.
    server_socket = socket(PF_INET, SOCK_STREAM, 0);

    //this will create the address for the socket.
    struct sockaddr_in server_address;
    server_address.sin_family = PF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
    listen(server_socket, MAX_QUEUE);
}

int server_retrieve(char *filename)
{
    //get a file sent by the client.
}

int server_store(char *filename)
{
    //send a file requested by the client.
}

void server_list()
{
    //list all files in the current directory.
}

void server_terminate()
{
    close(server_socket);
}

int server_accept()
{
    return accept(server_socket, NULL, NULL);
}

void server_send(int client_socket, char *message)
{
    send(client_socket, (void *) message, sizeof(message), 0);
}

char * server_receive()
{
    char *message;
    recv(server_socket, &message[0], sizeof(message), 0);
    return message;
}