/* Program Number: 31
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Simple program to create a pipe, write
to the pipe, read from the pipe, and display the content on the monitor.
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int p[2];
    char msg[] = "Hello World!";
    char buf[100];

    pipe(p);                       // Declare p as a pipe
    write(p[1], msg, strlen(msg)); // Write to the pipe
    read(p[0], buf, sizeof(buf));  // Read from the pipe
    printf("%s\n", buf);           // Print the read content on the terminal
    close(p[0]);                   // Close the ends of the pipe
    close(p[1]);
}