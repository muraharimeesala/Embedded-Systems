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

    key = ftok("chatfile",65);

    msgid = msgget(key,0666|IPC_CREAT);

    while(1)
    {
        if(msgrcv(msgid,&message,sizeof(message.mtext),1,0)==-1)
        {
            perror("msgrcv");
            exit(1);
        }

        printf("CLIENT: %s",message.mtext);

        printf("SERVER: ");
        fgets(message.mtext,SIZE,stdin);

        message.mtype = 2;

        msgsnd(msgid,&message,sizeof(message.mtext),0);
    }

    return 0;
}
