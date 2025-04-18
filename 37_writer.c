/* Program Number: 37
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Write two programs to enable communication
through FIFO using one-way communication.
This is the writer program
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    // First create the fifo file using mkfifo:
    if (mkfifo("37_fifo", 0666) == -1)
        perror("mkfifo");
    else
    {
        int fd = open("37_fifo", O_WRONLY);
        if (fd == -1)
            perror("open fifo");
        else
        {
            write(fd, "Hello World!", 12);
            close(fd);
        }
    }
}