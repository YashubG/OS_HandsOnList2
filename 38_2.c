/* Program Number: 38
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Two programs to establish communication
through FIFO using two-way communication.
This is program 2
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    printf("Please create the fifo file if it does not exist already\nby entering the following into the terminal :\n\"mkfifo 38_fifo2\"\n");

    int fd1 = open("38_fifo1", O_RDONLY);
    int fd2 = open("38_fifo2", O_WRONLY);
    if (fd1 == -1 || fd2 == -1)
        perror("open fifo");
    else
    {
        write(fd2, "Hello from process 2!", 21);
        char buffer[25];
        int bytes_read = read(fd1, buffer, 24);
        if (bytes_read > 0)
        {
            buffer[bytes_read] = '\0'; // Mark the end of the string, required for printing it using %s
            printf("Process 2 received: %s\n", buffer);
        }
        close(fd1);
        close(fd2);
    }
}
