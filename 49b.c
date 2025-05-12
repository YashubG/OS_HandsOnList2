/* Program Number: 49
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to implement a semaphore to
protect any critical section:
b. Protect shared memory from concurrent write access
c. Protect multiple pseudo resources (maybe two) using a counting semaphore
d. Remove the created semaphore
*/
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex; // Binary semaphore

void *thread_function(void *arg)
{
    (void)arg;

    sem_wait(&mutex); // Acquire semaphore (enter critical section)
    printf("Thread %lu: Inside critical section\n", pthread_self());
    sleep(1);
    printf("Thread %lu: Exiting critical section\n", pthread_self());
    sem_post(&mutex); // Release semaphore (exit critical section)

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;

    sem_init(&mutex, 0, 1); // Initialize as a binary semaphore (initial value 1)

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    sem_destroy(&mutex); // Clean up the semaphore
}