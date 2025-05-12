/* Program Number: 49
Student Name: Yashub Goel; Register Number: IMT2023117
Date: 12-04-2025
Description: Program to implement a semaphore to
protect any critical section:
c. Protect multiple pseudo resources (maybe two) using a counting semaphore
d. Remove the created semaphore
*/

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t resources; // Counting semaphore for two resources

void *use_resource(void *arg)
{
    int thread_id = *(int *)arg;
    sem_wait(&resources);
    printf("Thread %d: Acquired resource\n", thread_id);
    sleep(1); // Simulate use of some resource
    printf("Thread %d: Released resource\n", thread_id);
    sem_post(&resources);
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2, thread3, thread4, thread5;
    int id1 = 1, id2 = 2, id3 = 3, id4 = 4, id5 = 5;

    sem_init(&resources, 0, 2); // Two available resources

    pthread_create(&thread1, NULL, use_resource, &id1);
    pthread_create(&thread2, NULL, use_resource, &id2);
    pthread_create(&thread3, NULL, use_resource, &id3);
    pthread_create(&thread4, NULL, use_resource, &id4);
    pthread_create(&thread5, NULL, use_resource, &id5);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);

    sem_destroy(&resources);
}