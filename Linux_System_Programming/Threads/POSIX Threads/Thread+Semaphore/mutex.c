#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t sem;
int shared=0;

void *mutex(void *arg)
{
    sem_wait(&sem);
    shared++;
    printf("Thread %ld: %d\n",pthread_self(),shared);
    sleep(2);
    sem_post(&sem);
    return NULL;
}

int main(){
    pthread_t t1,t2;
    sem_init(&sem,0,1);
    pthread_create(&t1,NULL,mutex,NULL);
    pthread_create(&t2,NULL,mutex,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
