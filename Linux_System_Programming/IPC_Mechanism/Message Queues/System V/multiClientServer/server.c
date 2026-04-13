#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 1024

struct msgbuf{
    long mtype;
    int client_id;
    char mtext[SIZE];
};

int main(){
    int msgid;
    struct msgbuf msg;
    key_t key;

    key = ftok("multiclient",65);
    if(key == -1){
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key,0666|IPC_CREAT);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }

    while(1){
        msgrcv(msgid,&msg,sizeof(msg)-sizeof(long),1,0);
        printf("Message from client %d: %s\n",msg.client_id,msg.mtext);
    }
}

    
