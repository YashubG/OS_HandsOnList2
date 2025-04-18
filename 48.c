/* Program Number: 48
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to create a semaphore
and initialize its value:
a. Create a binary semaphore
b. Create a counting semaphore
*/

#include <stdio.h>
#include <semaphore.h>

int main()
{
    // a. Create a binary semaphore
    sem_t myBinarySemaphore; // Create a semaphor

    // Function prototype of sem_init:
    //  int sem_init(sem_t *__sem, int __pshared, unsigned int __value)
    sem_init(&myBinarySemaphore, 0, 1); // Initialise the semaphore
                                        // 0 means this semaphore is not shared
                                        // 1 means the MAX values is 1, i.e., this is a binary semaphore

    printf("Binary semaphore created and initialized.\n");

    // b. Create a counting semaphore
    sem_t myCountingSemaphore;

    sem_init(&myCountingSemaphore, 0, 5); // Initialisation
                                          // 0 means this semaphore is not shared
                                          // 1 means the MAX values is 5.

    printf("Counting semaphore created and initialized with value 5.\n");

    // Ideally, we should also have destroyed the semaphores after using then.
}