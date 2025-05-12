/* Program Number: 52
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to create a concurrent server:
a. Use fork
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/wait.h> // For waitpid()

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket)
{
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Hello from server (forked)!";
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Child process %d received: %s\n", getpid(), buffer);
    send(client_socket, message, strlen(message), 0);
    close(client_socket);
    exit(0); // Important: Child process should exit
}

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);
    printf("Server (PID %d) listening on port %d...\n", getpid(), PORT);

    while (1)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (fork() == 0)
        {                     // Child process
            close(server_fd); // Child doesn't need the listening socket
            handle_client(new_socket);
        }
        else                   // Parent process
            close(new_socket); // Parent doesn't need the client socket
    }
}