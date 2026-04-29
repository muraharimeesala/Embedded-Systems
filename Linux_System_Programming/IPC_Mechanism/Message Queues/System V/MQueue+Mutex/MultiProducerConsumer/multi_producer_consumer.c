#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<pthread.h>
#include<string.h>

#define SIZE 1024
pthread_mutex_t mutex;
int counter=0;
int msgid;

struct msgbuf{
    long mtype;
    char mtext[SIZE];
};

void *producer(void *arg){
    struct msgbuf msg;
    int id=*(int*)arg;

    while(1){
        pthread_mutex_lock(&mutex);
        int value=counter++;
        msg.mtype=1;
        sprintf(msg.mtext,"%d",value);
        if(msgsnd(msgid,&msg,strlen(msg.mtext)+1,0)==-1){
            perror("msgsnd");
            exit(1);
        }
        printf("PRODUCER [%d]: Produced = %s\n",id,msg.mtext);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg){
    struct msgbuf msg;
    int id=*(int*)arg;

    while(1){

        if(msgrcv(msgid,&msg,sizeof(msg.mtext),1,0)==-1){
            perror("msgrcv");
            exit(1);
        }
        printf("CONSUMER [%d]: Consumed = %s\n",id,msg.mtext);

        sleep(1);
    }
    pthread_exit(NULL);
}

int main(){
    int p,c,i;
    printf("Enter no of producers:");
    scanf("%d",&p);
    printf("Enter no of consumers:");
    scanf("%d",&c);
    pthread_mutex_init(&mutex,NULL);

    pthread_t prod[p],cons[c];
    int pid[p],cid[c];
    key_t key;

    key=ftok("multiproducersconsumers",65);
    if(key==-1){
        perror("ftok");
        exit(1);
    }

    msgid=msgget(key,0666|IPC_CREAT);
    if(msgid==-1){
        perror("msgid");
        exit(1);
    }
    for(i=0;i<p;i++){
        pid[i]=i+1;
        pthread_create(&prod[i],NULL,producer,&pid[i]);
    }
    for(i=0;i<c;i++){
        cid[i]=i+1;
        pthread_create(&cons[i],NULL,consumer,&cid[i]);
    }
    for(i=0;i<p;i++)
        pthread_join(prod[i],NULL);

    for(i=0;i<c;i++)
        pthread_join(cons[i],NULL);

    msgctl(msgid,IPC_RMID,NULL);

    pthread_mutex_destroy(&mutex);
}

