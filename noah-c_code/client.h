/*
 *  IGNORE THIS CODE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int client_list();
int client_store(char *filename);
void client_init();
int client_connect();
int client_retrieve(char *filename);
int client_terminate();