/* Program Number: 41
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to create a message queue, and print
the key and message queue ID
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

int main()
{
    key_t key = ftok(".", 'a'); // Using current directory and a character 'a'
                                //  to create the unique key for message queue.
    if (key == -1)
    {
        perror("ftok");
        return 1;
    }

    // Create the message queue and get its ID
    int msgid = msgget(key, IPC_CREAT | 0666); // Create if it doesn't exist, with read/write permissions
    if (msgid == -1)
    {
        perror("msgget");
        return 1;
    }

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);
}