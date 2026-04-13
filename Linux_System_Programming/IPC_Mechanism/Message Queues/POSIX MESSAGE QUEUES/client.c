#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<mqueue.h>
#include<sys/stat.h>

#define SERVER_QUEUE "/server_queue"
#define CLIENT_QUEUE "/client_queue"
#define MAX_MSG_SIZE 1024

int main(){
    mqd_t server_queue, client_queue;
    char buffer[MAX_MSG_SIZE];
    char msg[MAX_MSG_SIZE];
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    server_queue = mq_open(SERVER_QUEUE, O_CREAT | O_WRONLY);
    client_queue = mq_open(CLIENT_QUEUE, O_RDONLY,0644,&attr);
    if(server_queue == -1 || client_queue == -1){
        perror("mq_open failed");
        exit(EXIT_FAILURE);
    }
    while(1){
        printf("Enter message: ");
        fgets(msg, sizeof(msg), stdin);

        if(mq_send(server_queue, msg, strlen(msg)+1, 0)==-1){
            perror("mq_send failed");
            exit(EXIT_FAILURE);
        }

        if(mq_receive(client_queue, buffer, MAX_MSG_SIZE, NULL)==-1){
            perror("mq_receive failed");
            exit(EXIT_FAILURE);
        }
        printf("Server Message: %s\n", buffer);
    }
    mq_close(server_queue);
    mq_close(client_queue);
    mq_unlink(SERVER_QUEUE);
    mq_unlink(CLIENT_QUEUE);
    return 0;
}

