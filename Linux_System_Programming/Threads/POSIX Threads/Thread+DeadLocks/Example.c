#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t mutex1;
pthread_mutex_t mutex2;

void *thread1(void *arg)
{
    printf("THREAD 1: Trying to lock mutex1\n");
    pthread_mutex_lock(&mutex1);
    printf("THREAD 1: Locked mutex1\n");
    sleep(1);
    printf("THREAD 2: Trying to lock mutex2\n");
    pthread_mutex_lock(&mutex2);
    printf("THREAD 2: Locked mutex2\n");

    pthread_mutex_unlock(&mutex2);
    printf("THREAD 1: Unlocked mutex2\n");
    pthread_mutex_unlock(&mutex1);
    printf("THREAD 1: Unlocked mutex1\n");
    return NULL;

}

void *thread2(void *arg){
    printf("THREAD 2: Trying to lock mutex2\n");
    pthread_mutex_lock(&mutex2);
    printf("THREAD 2: Locked mutex2\n");
    sleep(1);
    printf("THREAD 1: Trying to lock mutex1\n");
    pthread_mutex_lock(&mutex1);
    printf("THREAD 1: Locked mutex1\n");

    pthread_mutex_unlock(&mutex1);
    printf("THREAD 2: Unlocked mutex1\n");
    pthread_mutex_unlock(&mutex2);
    printf("THREAD 2: Unlocked mutex2\n");
    return NULL;
}

int main(){
    pthread_t tid1, tid2;
    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    pthread_create(&tid1,NULL,thread1,NULL);
    pthread_create(&tid2,NULL,thread2,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}
