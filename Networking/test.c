#include "Server.h"
#include <stdio.h>
#include <string.h>

void launch(struct Server *server){
    char buffer[30000];
    printf("Waiting for a Connection!!!!\n");

    int addressLength = sizeof(server->address);
    int new_socket = accept(server->socket, (struct sockaddr*)&server->address, (socklen_t*)&addressLength);

    read(new_socket, buffer, 30000);
    printf("%s\n", buffer);

    char *message = "Hello from server!\n";
    write(new_socket, message, strlen(message));

    close(new_socket);

}

int main(){
    struct Server server = serverConstructor(AF_INET, SOCK_STREAM, 0, INADDR_ANY, 80, 10, launch);
    server.launch(&server);
    return 0;
}