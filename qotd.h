#ifndef QOTD_CLIENT_QOTD_H
#define QOTD_CLIENT_QOTD_H

#include <WinSock2.h>

const int MAX_SERVER_NAME = 128;
const int MAX_HOST_SIZE = 32;
const int MAX_SERVICE_SIZE = 32;
const int MAX_HOSTNAME = 1024;
const int MAX_PORT = 128;
const int MAX_RECV_BUF = 2048;
const int MAX_SEND_BUF = 2048;
const int WAIT_TIME = 15;
const char qotd_QUERY[] = "Name?";

struct ServerStruct {
    char name[MAX_SERVER_NAME];
    char host[MAX_HOST_SIZE];
    char port[MAX_SERVICE_SIZE];
};

int wait(SOCKET, int, int);

SOCKET passivesock(char *, char *);

SOCKET connectsock(char *, char *, char *);

char *timestamp();

char *getMyIPAddress();

int UDP_recv(SOCKET, char *, int, char *, char *);

int UDP_send(SOCKET, char *, int, char *, char *);

char *getBroadcastAddress();

#endif //QOTD_CLIENT_QOTD_H
