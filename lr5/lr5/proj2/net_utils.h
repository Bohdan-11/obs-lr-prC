#ifndef NET_UTILS_H
#define NET_UTILS_H

#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #include <stddef.h>  // Добавлено для size_t
    #define close_socket closesocket
#else
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #include <stddef.h>  // Для size_t
    #define close_socket close
#endif

int create_server_socket(int port);
int create_client_socket(const char *host, int port);
int send_all(int sockfd, const void *buffer, size_t length);
int recv_all(int sockfd, void *buffer, size_t maxlen);

#endif