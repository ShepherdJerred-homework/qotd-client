// qotdUDPClient
// Jerred Shepherd
#include "qotd.h"
#include <iostream>
#include <WinSock2.h>
using namespace std;

#pragma comment (lib,"ws232.lib");

void run() {
    WORD wVersionRequired = 0x0101;
    WSADATA wsaData;
    int err = WSAStartup(wVersionRequired, &wsaData);
    if (err) {
        cout << "Unable to initialize Windows Socket library" << endl;
        return;
    }
    SOCKET s;
    s = connectsock("", "", "UDP");
    if (s != INVALID_SOCKET) {
        char serverName[MAX_HOSTNAME];
        cout << "QOTD server? ";
        cin >> serverName;

        char command[MAX_SEND_BUF];
        cout << "Command to send? ";
        cin.ignore();
        cin.getline(command, MAX_SEND_BUF - 1);
        int commandLength = strlen(command);

        if (commandLength > 0 && _stricmp(command, "quit") != 0) {
            int numBytesSent = UDP_send(s, command, commandLength + 1, serverName, "qotd");

            if (_stricmp(command, "sendQOTD") == 0) {
                cout << endl << "Quote of the day: " << endl;

                int waitStatus = wait(s, 10, 0);
                if (waitStatus == 1) {
                    char remoteName[MAX_HOSTNAME];
                    char remotePort[MAX_PORT];
                    char recvBuf[MAX_RECV_BUF];
                    int numBytesRecvd = UDP_recv(s, recvBuf, MAX_RECV_BUF - 1, remoteName, remotePort);
                    while (numBytesRecvd > 0) {
                        recvBuf[numBytesRecvd] = '\0';
                        cout << recvBuf;
                        waitStatus = wait(s, 1, 0);
                        if (waitStatus == 1) {
                            int numBytesRecvd = UDP_recv(s, recvBuf, MAX_RECV_BUF, remoteName, remotePort);

                        } else {
                            numBytesRecvd = 0;
                        }
                    }
                }
                cout << endl;
            }
        }

        closesocket(s);
    }
}
