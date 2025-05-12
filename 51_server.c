/* Program Number: 51
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to communicate between two machines using sockets.

THIS IS THE SERVER PROGRAM
*/

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Hello from server!";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 1);
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Client says: %s\n", buffer);
    send(new_socket, message, strlen(message), 0);
    close(new_socket);
    close(server_fd);
}