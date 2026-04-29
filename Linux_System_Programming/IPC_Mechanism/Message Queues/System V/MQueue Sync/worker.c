#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define SIZE 1024

struct msgbuf{
    long mtype;
    char mtext[SIZE];
};

int main(){
    key_t key;
    int msgid;
    struct msgbuf msg;

    key = ftok("syncfile",65);
    if(key == -1){
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key,0666|IPC_CREAT);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }
    printf("Worker Waiting... ");

    msgrcv(msgid,&msg,sizeof(msg.mtext),1,0);
    printf("Worker Started: %s\n",msg.mtext);
    return 0;
}
