/* Program Number: 47
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to create shared memory and
perform the following operations:
a. Write some data to the shared memory
b. Attach with O_RDONLY and check whether you are able to overwrite
c. Detach the shared memory
d. Remove the shared memory
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>

int main()
{
    // a. Create shared memory
    int shmid = shmget(ftok(".", 'a'), 1024, IPC_CREAT | 0666);
    // and attach it for writing
    char *shm_ptr = (char *)shmat(shmid, NULL, 0); // 0 means attach for both reading and writing
    strcpy(shm_ptr, "Hello World!");
    printf("Data written to the shared memory: %s\n", shm_ptr);
    // Detach after writing for part b
    shmdt(shm_ptr);

    // b. Attach read-only
    shm_ptr = (char *)shmat(shmid, NULL, SHM_RDONLY);
    printf("Read-only attached and read: %s\n", shm_ptr);
    // Attempt to overwrite
    // strcpy(shm_ptr, "Trying to overwrite!"); // Uncommenting leads to "Segmentation fault (core dumped)"

    // c. Detach read-only
    shmdt(shm_ptr);

    // d. Remove shared memory
    shmctl(shmid, IPC_RMID, NULL);
    printf("Shared memory removed.\n");
}