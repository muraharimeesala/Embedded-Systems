#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf{
    long mtype;
    char mtext[100];
};

int main(){

    struct msgbuf msg;
    int msgid;
    key_t key;
    key = ftok("file",65);
    msgid = msgget(key,0666|IPC_CREAT);
    if(msgid==-1){
        perror("msgget");
        exit(1);
    }
    if(msgrcv(msgid,&msg,sizeof(msg.mtext),1,0)==-1){
        perror("msgrcv");
        exit(1);
    }
    printf("Message : %s\n",msg.mtext);
    msgctl(msgid,IPC_RMID,NULL);
    return 0;
}
