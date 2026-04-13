#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<mqueue.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>

#define SERVER_QUEUE "/server_queue"
#define CLIENT_QUEUE "/client_queue"
#define MAX_MSG_SIZE 1024

int main()
{
    mqd_t server_queue;
    mqd_t client_queue;
    struct mq_attr attr;
    char buffer[MAX_MSG_SIZE];
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_MSG_SIZE;
    attr.mq_curmsgs = 0;

    server_queue = mq_open(SERVER_QUEUE, O_CREAT | O_RDONLY, 0666, &attr);
    client_queue = mq_open(CLIENT_QUEUE, O_CREAT | O_WRONLY, 0666, &attr);
    if(server_queue == -1 || client_queue == -1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    while(1){
        if(mq_receive(server_queue, buffer, MAX_MSG_SIZE, NULL)==-1){
            perror("mq_receive");
            exit(EXIT_FAILURE);
        }
        printf("Client Message: %s\n",buffer);
        char reply[1024];
        printf("Enter reply: ");
        fgets(reply, sizeof(reply), stdin);
        if(mq_send(client_queue, reply, strlen(reply)+1, 0)==-1){
            perror("mq_send");
            exit(EXIT_FAILURE);
        }
    }
    mq_close(server_queue);
    mq_close(client_queue);
    mq_unlink(SERVER_QUEUE);
    return 0;
        
}
