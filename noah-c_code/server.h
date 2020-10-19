#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

void server_list();
void server_init();
int server_accept();
void server_terminate();
int server_store(char *filename);
int server_retrieve(char *filename);
void server_send(int client_socket, char *message);

