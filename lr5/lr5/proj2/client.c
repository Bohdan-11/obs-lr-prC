#include "net_utils.h"
#include <stdio.h>
#include <string.h>

#define SERVER_ADDR "127.0.0.1"
#define PORT 8080

int main() {
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed\n");
        return 1;
    }
#endif

    int sock = create_client_socket(SERVER_ADDR, PORT);
    if (sock < 0) {
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    printf("Connected to server %s:%d\n", SERVER_ADDR, PORT);
    
    char msg[256];
    printf("Enter message: ");
    if (!fgets(msg, sizeof(msg), stdin)) {
        close_socket(sock);
#ifdef _WIN32
        WSACleanup();
#endif
        return 0;
    }

    size_t len = strlen(msg);
    if (send_all(sock, msg, len) != len) {
        perror("send_all failed");
    }

    char reply[256] = {0};
    size_t received = recv_all(sock, reply, sizeof(reply)-1);
    
    if (received > 0) {
        printf("Server replied: %.*s\n", (int)received, reply);
    } else if (received == 0) {
        printf("Connection closed by server\n");
    } else {
        perror("recv_all failed");
    }

    close_socket(sock);
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}