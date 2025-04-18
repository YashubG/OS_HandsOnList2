/* Program Number: 39
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to wait for data to be written into a FIFO
within 10 seconds, utilizing the select system call with the FIFO.
*/

#include <sys/stat.h>
#include <stdio.h>
#include <sys/select.h>
#include <sys/time.h> // For struct timeval (timeout)
#include <unistd.h>
#include <fcntl.h>

int main()
{
    printf("Please create the fifo file if it does not exist already\nby entering the following into the terminal :\n\"mkfifo 39_fifo\"\n");

    // NOTE:
    //  By default, open() on a FIFO for reading blocks until a writer connects.
    //  O_NONBLOCK prevents this initial blocking.  This allows select() to work correctly.
    int fd = open("39_fifo", O_RDONLY | O_NONBLOCK);
    if (fd == -1)
        perror("open fifo");
    else
    {
        printf("Fifo file opened successfully!\n");

        // USE THE SELECT SYSCALL TO WAIT FOR DATA IN FIFO:
        //  Create the file descriptor sets
        fd_set read_fd_set;

        // Initialize the file descriptor set to be empty
        FD_ZERO(&read_fd_set);

        // Add the file descriptors to the set
        FD_SET(fd, &read_fd_set); // Add fifo file's fd to the read set

        // Set the timeout
        // If not used, the select syscall will wait indefinitely
        // We use struct timeval for this:
        // It takes two values: time in seconds and in microseconds
        struct timeval timeout = {10, 0}; // Wait for 10 seconds and 0 microseconds

        // Call the select syscall, FINALLY!!
        // The function definition of the select syscall is as follows:
        //  int select(int __nfds,                         --> 1 + Highest numbered fd in the three sets
        //   fd_set *__restrict__ __readfds,               --> Set 1: pointer to fd_set structure of read fds
        //    fd_set *__restrict__ __writefds,             --> Set 2: pointer to fd_set structure of write fds
        //     fd_set *__restrict__ __exceptfds,           --> Set 3: pointer to fd_set structure of exception fds
        //      struct timeval *__restrict__ __timeout)    --> Pointer to our struct timeval specifying the maximum wait time
        int no_of_ready_fds = select(fd + 1, &read_fd_set, NULL, NULL, &timeout); // Note: this is a blocking syscall

        // Check the return value of select:
        //  >0: means one or more fds in the sets became ready. We can iterate over the sets to check which ones are ready
        //  =0: means timeout occured before any fd in the three sets became ready.
        //  -1: Error occured
        if (no_of_ready_fds > 0)
        {
            // We can use the FD_ISSET() macro for checking which fds became ready
            if (FD_ISSET(fd, &read_fd_set))
            {
                printf("FIFO file is ready to be read.\n");
                char buffer[256];
                ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
                if (bytes_read > 0)
                    printf("Received text: %s", buffer);
            }
        }
        else if (no_of_ready_fds == 0)
            printf("Timeout occurred. Nothing to read.\n");
        else
            printf("Error occured.\n");
    }
}