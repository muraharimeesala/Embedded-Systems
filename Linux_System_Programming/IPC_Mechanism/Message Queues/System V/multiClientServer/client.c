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

    struct msgbuf msg;
    int msgid;
    key_t key;
    key = ftok("multiclient", 65);
    if(key == -1){
        perror("ftok");
        exit(1);
    }
    msgid = msgget(key, 0666 | IPC_CREAT);
    if(msgid == -1){
        perror("msgget");
        exit(1);
    }

    msg.mtype = 1;
    msg.client_id = getpid();
    while(1){
        printf("Enter the message: ");
        fgets(msg.mtext, SIZE, stdin);
        sleep(2);

        if(msgsnd(msgid,&msg,sizeof(msg)-sizeof(long), 0) == -1){
            perror("msgsnd");
            exit(1);
        }
        printf("Message sent\n");
    }
    return 0;
}
