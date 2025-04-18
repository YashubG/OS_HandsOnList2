/* Program Number: 34c
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to execute ls -l | wc using:
c. fcntl
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int p[2];
    pipe(p);

    if (fork() == 0)
    {             // Child process (wc)
        close(0); // Redirect stdin to pipe's read end
        fcntl(p[0], F_DUPFD, 0);
        close(p[0]);
        close(p[1]);
        execlp("wc", "wc", NULL);
    }
    else
    {             // Parent process (ls -l)
        close(1); // Redirect stdout to pipe's write end
        fcntl(p[1], F_DUPFD, 1);
        close(p[0]);
        close(p[1]);
        execlp("ls", "ls", "-l", NULL);
    }
}