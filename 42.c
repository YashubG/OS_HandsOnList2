/* Program Number: 42
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to print information about a
message queue using msqid_ds and ipc_perm structures:
a. Access permission
b. UID, GID
c. Time of last message sent and received
d. Time of last change in the message queue
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>
#include <unistd.h>
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
    int msg_id = msgget(key, IPC_CREAT | 0777); // Create if it doesn't exist, with read/write permissions
    if (msg_id == -1)
    {
        perror("msgget");
        return 1;
    }

    struct msqid_ds msq_stat; // Structure of record for one message inside the kernel.
    struct tm *timeinfo;      // ISO C 'broken-down time' structure.
    // Get the status of the message queue and put it in msq_stat
    if (msgctl(msg_id, IPC_STAT, &msq_stat) == -1)
    {
        perror("msgctl (IPC_STAT)");
        return 1;
    }

    // a. Access Permission
    printf("Access Permission: 0%o\n", msq_stat.msg_perm.mode & 0777);

    // b. UID, GID
    printf("Owner UID: %d\n", msq_stat.msg_perm.uid);
    printf("Owner GID: %d\n", msq_stat.msg_perm.gid);

    // c. Time of last message sent and received
    // Send time
    if (msq_stat.msg_stime == 0)
        printf("Last Message Sent Time: Never\n");
    else
    {
        timeinfo = localtime(&msq_stat.msg_stime);               // Convert this time to local time
        printf("Last Message Sent Time: %s", asctime(timeinfo)); // Convert the local time to human readable format and print.
    }
    // Receive time
    if (msq_stat.msg_rtime == 0)
        printf("Last Message Received Time: Never\n");
    else
    {
        timeinfo = localtime(&msq_stat.msg_rtime);                   // Convert this time to local time
        printf("Last Message Received Time: %s", asctime(timeinfo)); // Convert the local time to human readable format and print.
    }

    // d. Time of last change in the message queue
    timeinfo = localtime(&msq_stat.msg_ctime);         // Convert this time to local time
    printf("Last Change Time: %s", asctime(timeinfo)); // Convert the local time to human readable format and print.
}