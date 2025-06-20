#include "net_utils.h"
#include <stdio.h>
#include <string.h>  // Для memcpy/memset

#ifdef _WIN32
static WSADATA wsaData;
#endif

int create_server_socket(int port) {
#ifdef _WIN32
    static int initialized = 0;
    if (!initialized) {
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            fprintf(stderr, "WSAStartup failed\n");
            return -1;
        }
        initialized = 1;
    }
#endif

    SOCKET sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        perror("socket");
        return -1;
    }

    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        close_socket(sockfd);
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close_socket(sockfd);
        return -1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        close_socket(sockfd);
        return -1;
    }

    return (int)sockfd;
}

int send_all(int sockfd, const void *buffer, size_t length) {
    const char *ptr = (const char*)buffer;
    size_t remaining = length;
    
    while (remaining > 0) {
        int sent = send(sockfd, ptr, (int)remaining, 0);
        if (sent <= 0) {
            return sent;
        }
        remaining -= sent;
        ptr += sent;
    }
    return (int)length;
}

int recv_all(int sockfd, void *buffer, size_t maxlen) {
    char *ptr = (char*)buffer;
    size_t total = 0;
    
    while (total < maxlen) {
        int recvd = recv(sockfd, ptr + total, (int)(maxlen - total), 0);
        if (recvd <= 0) {
            return (recvd == 0) ? (int)total : -1;
        }
        total += recvd;
    }
    return (int)total;
}