#include "net_utils.h"
#include <stdio.h>
#define PORT 8080

int main() {
    int server_fd = create_server_socket(PORT);
    if (server_fd < 0) return 1;

    printf("Server listening on port %d...\n", PORT);
    
    while (1) {
        SOCKET client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == INVALID_SOCKET) {
            perror("accept");
            break;
        }
        
        printf("Client connected\n");
        char buf[1024];
        int n;
        
        while ((n = recv_all(client_fd, buf, sizeof(buf))) > 0) {
            send_all(client_fd, buf, n);
        }
        
        close_socket(client_fd);
        printf("Client disconnected\n");
    }
    
    close_socket(server_fd);
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}