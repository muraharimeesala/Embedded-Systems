#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<string.h>
#include<unistd.h>

#define SIZE 1024

struct msgbuf{
    long mtype;
    char mtext[SIZE];
};

int main()
{
    key_t key;
    int msgid,semid;
    struct msgbuf message;

    key = ftok("semafile",65);

    msgid = msgget(key,0666|IPC_CREAT);

    semid = semget(key,1,0666|IPC_CREAT);

    struct sembuf wait_op={0,-1,0};
    struct sembuf signal_op={0,1,0};

    while(1)
    {
        semop(semid,&wait_op,1);

        printf("CLIENT: ");
        fgets(message.mtext,SIZE,stdin);

        message.mtype = 1;

        msgsnd(msgid,&message,sizeof(message.mtext),0);

        if(msgrcv(msgid,&message,sizeof(message.mtext),2,0)==-1){
            perror("msgrcv");
            exit(1);
        }

        printf("SERVER: %s",message.mtext);

        semop(semid,&signal_op,1);
    }

    return 0;
}
