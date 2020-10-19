/*
 *  IGNORE THIS CODE
 */

#include "client.h"

//making the socket information available to every function in this scope.
int client_socket;

void client_init()
{
    // this creates the server socket.
    client_socket = socket(PF_INET, SOCK_STREAM, 0);
}

int client_connect(int client_socket)
{
    //this will create the address for the socket.
    struct sockaddr_in server_address;
    server_address.sin_family = PF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    if (connection_status == -1)
    {
        printf("There was an error in connecting to the remote socket. /n/n");
    }
}

int client_retrieve(char *filename)
{
    char server_response[256];
    recv(client_socket, &server_response, sizeof(server_response), 0);

    printf("Server sent data: %s\n", server_response);

    close(client_socket);

    return 0;
}