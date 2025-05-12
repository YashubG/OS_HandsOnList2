/* Program Number: 52
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to create a concurrent server:
b. Use pthread_create
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct
{
    int client_socket;
} thread_args_t;

void *handle_client_thread(void *arg)
{
    int client_socket = ((thread_args_t *)arg)->client_socket;
    char buffer[BUFFER_SIZE] = {0};
    const char *message = "Hello from server (threaded)!";
    read(client_socket, buffer, BUFFER_SIZE);
    printf("Thread %lu received: %s\n", pthread_self(), buffer);
    send(client_socket, message, strlen(message), 0);
    close(client_socket);
    free(arg); // Free the allocated argument structure
    pthread_exit(NULL);
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
        pthread_t thread_id;
        thread_args_t *args = malloc(sizeof(thread_args_t));
        args->client_socket = new_socket;

        if (pthread_create(&thread_id, NULL, handle_client_thread, (void *)args) < 0)
        {
            perror("Could not create thread");
            free(args); // Clean up if thread creation fails (minimal error handling)
            close(new_socket);
            continue;
        }
        // The main thread continues to listen for new connections
    }
}