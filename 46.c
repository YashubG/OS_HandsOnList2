/* Program Number: 46
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to remove the message queue.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main()
{
    key_t key = ftok(".", 'a'); // Generate the same key as used to create the queue
    int msgid = msgget(key, 0); // Get the message queue ID

    // Function defintion for msgctl:
    //  int msgctl(int __msqid, int __cmd, struct msqid_ds *__buf)
    if (msgctl(msgid, IPC_RMID, NULL) == -1) // IPC_RMID->translates to->Remove identifier.
        perror("msgctl - IPC_RMID");
    else
        printf("Message queue removed successfully.\n");
}