#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<stdlib.h>

#define SIZE 1024

struct msgbuf{
    long mtype;
    char mtext[SIZE];
};

int main(){

    struct msgbuf msg;
    int msgid;
    key_t key;
    key = ftok("mqueuesched",65);
    if(key == -1){
        perror("ftok");
        exit(1);
    }

    msgid = msgget(key,0666|IPC_CREAT);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }

    msg.mtype = 3;
    printf("Enter the message: ");
    fgets(msg.mtext,SIZE,stdin);

    if(msgsnd(msgid,&msg,sizeof(msg.mtext),0) == -1){
        perror("msgsnd");
        exit(1);
    }
    msg.mtype = 2;
    printf("Enter the message: ");
    fgets(msg.mtext,SIZE,stdin);
    if(msgsnd(msgid,&msg,sizeof(msg.mtext),0) == -1){
        perror("msgsnd");
        exit(1);
    }
    msg.mtype = 1;
    printf("Enter the message: ");
    fgets(msg.mtext,SIZE,stdin);
    if(msgsnd(msgid,&msg,sizeof(msg.mtext),0) == -1){
        perror("msgsnd");
        exit(1);
    }
    return 0;
}

