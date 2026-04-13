#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
sem_t sem;
void* worker(void* arg){
    printf("Worker waiting...\n");
    sem_wait(&sem);
    printf("Worker running\n");
    return NULL;
}
int main(){
    pthread_t t;
    sem_init(&sem, 0, 0);
    pthread_create(&t, NULL, worker, NULL);
    sleep(2);
    sem_post(&sem);   // unblock thread
    pthread_join(t, NULL);
    sem_destroy(&sem);
}

