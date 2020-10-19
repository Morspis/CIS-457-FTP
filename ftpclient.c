#include <strings.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int getUserInput(char *buffer){
    memset(buffer, 0, (int)sizeof(buffer));

    printf("> ");

    if (fgets(buffer, 1024, stdin) == NULL){
        return -1;
    }
    return 1;
}

int getCommand(char *command){
    int value, check = -1;
    char copy[1024];
    while (check < 0){
        char *str;
        
        if (getUserInput(command) < 0){
            printf("Invalid commmand.\n");
            bzero(command, (int)sizeof(command));
            continue;
        }

        strcpy(copy, command);

        char delimit[] = " \t\r\n\v\f";
        str = strtok(copy, delimit);
        if ((strcmp(str, "list") == 0) || (strcmp(str, "retrieve") == 0) || (strcmp(str, "store") == 0) || (strcmp(str, "quit") == 0)){
            check = 1;

            if (strcmp(str, "list") == 0){
                value = 1;
            }
            else if (strcmp(str, "retrieve") == 0){
                value = 2;
            }
            else if (strcmp(str, "store") == 0){
                value = 3;
            }
            else if (strcmp(str, "quit") == 0){
                value = 4;
            }
        }
        else{
            printf("Incorrect Command Entered.\n");
            bzero(command, strlen(command));
            bzero(copy, sizeof(copy));
            continue;
        }
    }
    return value;
}

int doStore(){
    printf("Store");
    return 0;
}

int doRetrieve(){
    printf("Retrieve");
    return 0;
}

int doList(){
    printf("List");
    return 0;
}

int main(int argc, char **argv){

    int code;
    char command[1024], ip[50];

    if (argc != 3){
        printf("Invalid Number of Arguments...\n");
        exit(-1);
    }

    printf("IP: %s\n", argv[1]);
    printf("Port: %s\n", argv[2]);
   
    while (1){
        bzero(command, strlen(command));

        code = getCommand(command);

        if (code == 4){
            char quit[1024];
            sprintf(quit, "QUIT");
            break;
        }

        printf("command: %s\n", command);

        if (code == 1){
            doList();
        }
        else if (code == 2){
            doRetrieve();
        }
        else if (code == 3){
            doStore();
        }
    }

    return 1;
}