#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main()
{
    int port = 8001;
    int serv_sock;
    int clnt_sock;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;

    char messsage[] = "Hello World@";

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
    {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(serv_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
    {
        error_handling("bind() error");
    }

    if (listen(serv_sock, 5) == -1)
    {
        error_handling("listen() error");
    }

    client_addr_size = sizeof(client_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*) &client_addr, &client_addr_size);
    if (clnt_sock == -1)
    {
        error_handling("accept error");
    }

    
    write(clnt_sock, messsage, sizeof(messsage));
    close(clnt_sock);
    close(serv_sock);
    return 0;
}

