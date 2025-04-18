/* Program Number: 37
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write two programs to enable communication
through FIFO using one-way communication.
This is the reader program
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("37_fifo", O_RDONLY);
    if (fd == -1)
        perror("open fifo");
    else
    {
        char buffer[21];
        int bytes_read = read(fd, buffer, 20);
        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0'; // Mark the end of the string, required for printing it using %s
            printf("Reader received: %s\n", buffer);
        }
        close(fd);
    }
}