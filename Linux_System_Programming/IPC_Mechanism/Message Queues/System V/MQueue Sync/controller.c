#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define SIZE 1024

struct msgbuf{
    long mtype;
    char mtext[SIZE];
};

int main(){
    int msgid;
    struct msgbuf msg;
    key_t key;

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
    msg.mtype=1;

    strcpy(msg.mtext,"START PROCESS");
    for(int i=0;i<3;i++){
        msgsnd(msgid,&msg,sizeof(msg.mtext),0);
    }
    printf("Controller sent signal to workers\n");
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}
