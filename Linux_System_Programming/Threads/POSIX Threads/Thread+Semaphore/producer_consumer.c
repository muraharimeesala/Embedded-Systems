#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define SIZE 10

sem_t sem;
sem_t empty;
sem_t full;

int buff[SIZE];
int in=0,out=0;

void *producer(void *arg){
    int i;
    while(1){
        sem_wait(&sem);
        sem_wait(&empty);
        for(i=1;i<=100;i++){
            buff[in]=i;
            printf("PRODUCER: Produced %d at position: %d\n",buff[in],in);
            sleep(1);
            in=(in+1)%SIZE;
            sem_post(&sem);
            sem_post(&full);
        }
    }
    return NULL;
}

void *consumer(void *arg){
    int i;
    while(1){
        sem_wait(&full);
        sem_wait(&sem);
        for(i=1;i<=100;i++){
            i=buff[out];
            printf("CONSUMER: Consumed %d at position: %d\n",buff[out],out);
            sleep(1);
            out=(out+1)%SIZE;
            sem_post(&sem);
            sem_post(&empty);
        }
    }
    return NULL;
}

int main(){
    pthread_t t1,t2;

    sem_init(&sem,0,1);
    sem_init(&empty,0,SIZE);
    sem_init(&full,0,0);

    pthread_create(&t1,NULL,producer,NULL);
    pthread_create(&t2,NULL,consumer,NULL);

    pthread_join(t1,NULL);
    pthread_join(t2,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&sem);
    return 0;
}
