#include "tcp_server.h"

int create_tcp_socket(int port) {
    int sock_fd;
    struct sockaddr_in serv_addr;

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);

#ifdef WINDOWS_DEFINITION
    // Windows下的代码
    memset(&serv_addr, 0, sizeof(serv_addr));
#endif
#ifdef LINUX_DEFINITION
    // Linux下的代码
    bzero(&serv_addr, sizeof(serv_addr));
#endif

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int on = 1;
#ifdef WINDOWS_DEFINITION
    // Windows下的代码
    setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on));
#endif
#ifdef LINUX_DEFINITION
    // Linux下的代码
    setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
#endif


    bind(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    listen(sock_fd, 1024);

    return sock_fd;
}