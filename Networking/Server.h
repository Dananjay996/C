//
// Created by dananjay on 12/5/23.
//

#ifndef Server_h
#define Server_h

#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

typedef unsigned long u_long;

struct Server{
    int domain;
    int service;
    int protocol;
    u_long interface;
    int port;
    int backlog;

    struct sockaddr_in address;

    int socket;

    void (*launch)(struct Server *server);
};

/// @brief Function prototype for the server constructor defined in Server.c
struct Server serverConstructor(int domain, int service, int protocol, u_long interface, int port, int backlog, void (*launch)(struct Server *server));

#endif //SERVER_H
