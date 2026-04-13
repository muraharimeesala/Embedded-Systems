#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<pthread.h>

#define SIZE 1024
pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
struct msgbuf{
    long mtype;
    char mtext[SIZE];
};
int i=1;
int msgid;
void *Producer(void *arg){
    struct msgbuf msg;

    while(1){
        pthread_mutex_lock(&mutex);
        msg.mtype = 1;
        sprintf(msg.mtext," %d\n",i);
        if(msgsnd(msgid,&msg,sizeof(msg.mtext),0) == -1){
            perror("msgsnd");
            exit(1);
        }
        printf("PRODUSER: Produced = %s\n",msg.mtext);
        pthread_mutex_unlock(&mutex);
        i++;
        sleep(1);
    }
    pthread_exit(NULL);
}

void *Consumer(void *arg){
    struct msgbuf msg;
    while(1){

        pthread_mutex_lock(&mutex);
        if(msgrcv(msgid,&msg,sizeof(msg.mtext),1,0) == -1){
            perror("msgrcv");
            exit(1);
        }
        printf("CONSUMER: Consumed = %s\n",msg.mtext);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    pthread_exit(NULL);
        }
int main(){
    key_t key;
    pthread_t p,c;
    struct msgbuf msg;

    key = ftok("producer_consumer", 65);
    if(key == -1){
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }

    pthread_create(&p,NULL,Producer,NULL);
    pthread_create(&c,NULL,Consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}
    
