#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 5

int buffer[SIZE];
int in = 0;
int out = 0;

sem_t mutex;
sem_t empty;
sem_t full;

void *producer(void *arg)
{

    while(1)
    {
        sem_wait(&empty);         // Check if buffer has empty slots
        sem_wait(&mutex);        // Lock the buffer one thread can access it
        buffer[in] = rand();
        printf("Produced %d at position : %d\n",buffer[in],in);
        sleep(2);
        in = (in+1)%SIZE;         // Move to next position
        sem_post(&mutex);        // Unlock the buffer
        sem_post(&full);        // Increase Full Count  (One new item available for consumer)
    }
    return NULL;
}

void *consumer(void *arg)
{
    while(1)
    {
        sem_wait(&full);          // Check if items exist
        sem_wait(&mutex);        // Lock the buffer one thread can access it
        printf("Consumed %d at position : %d\n",buffer[out],out);
        sleep(2);
        out = (out+1)%SIZE;
        sem_post(&mutex);        // Unlock the buffer
        sem_post(&empty);        // Increase Empty Count  (One new slot available for producer)
    }
    return NULL;
}

int main()
{
    sem_init(&mutex,0,1);
    sem_init(&empty,0,SIZE);
    sem_init(&full,0,0);
    pthread_t producerThread;
    pthread_t consumerThread;
    pthread_create(&producerThread,NULL,producer,NULL);
    pthread_create(&consumerThread,NULL,consumer,NULL);
    pthread_join(producerThread,NULL);
    pthread_join(consumerThread,NULL);
    return 0;
}
