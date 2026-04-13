#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

sem_t mutex;
sem_t wrt;

int data=0;
int readcount=0;

void *reader(void *arg){
    int id=*((int*)arg);

    sem_wait(&mutex);
    readcount++;

    if(readcount==1)
        sem_wait(&wrt);

    sem_post(&mutex);

    printf("READER: %d reading data: %d\n",id,data);
    sleep(1);

    sem_wait(&mutex);
    readcount--;

    if(readcount==0)
        sem_post(&wrt);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg){
    int id=*((int*)arg);

    sem_wait(&wrt);

    data++;
    printf("WRITER: %d writing data: %d\n",id,data);

    sleep(1);

    sem_post(&wrt);

    return NULL;
}

int main(){
    pthread_t r[3],w[3];
    int rid[3],wid[3];
    int i;

    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);

    /* create readers first */
    for(i=0;i<3;i++){
        rid[i]=i;
        pthread_create(&r[i],NULL,reader,&rid[i]);
    }

    /* then writers */
    for(i=0;i<3;i++){
        wid[i]=i;
        pthread_create(&w[i],NULL,writer,&wid[i]);
    }

    for(i=0;i<3;i++){
        pthread_join(r[i],NULL);
        pthread_join(w[i],NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

