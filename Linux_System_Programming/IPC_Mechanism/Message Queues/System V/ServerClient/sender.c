#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

#define SIZE 1024

struct msgbuf
{
    long mtype;
    char mtext[SIZE];
};

int main()
{
    key_t key;
    int msgid;
    struct msgbuf message;

    key = ftok("file",65);

    msgid = msgget(key,0666|IPC_CREAT);

    while(1)
    {
        printf("SENDER : ");
        fgets(message.mtext,SIZE,stdin);
        if(msgsnd(msgid,&message,sizeof(message.mtext),0)==-1)
        {
            perror("msgsnd");
            exit(1);
        }
    }

    return 0;
}
