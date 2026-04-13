#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/stat.h>
#include<fcntl.h>

sem_t sem;

void *func(void *arg){
    sem_wait(&sem);
    printf("Enterd Critical Section\n");
    sleep(1);
    sem_post(&sem);
    return NULL;
}

int main(){
    pthread_t t1,t2;
    sem_init(&sem,0,1);
    pthread_create(&t1,NULL,func,NULL);
    pthread_create(&t2,NULL,func,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
