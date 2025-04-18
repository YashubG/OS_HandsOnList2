/* Program Number: 34a
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to execute ls -l | wc using:
a. dup
*/

#include <stdio.h>
#include <unistd.h>

int main()
{
    int p[2];
    pipe(p);

    if (fork() == 0)
    {             // Child process (wc)
        close(0); // Redirect stdin to pipe's read end
        dup(p[0]);
        close(p[0]);
        close(p[1]);
        execlp("wc", "wc", NULL);
    }
    else
    {             // Parent process (ls -l)
        close(1); // Redirect stdout to pipe's write end
        dup(p[1]);
        close(p[0]);
        close(p[1]);
        execlp("ls", "ls", "-l", NULL);
    }
}