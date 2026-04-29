#include<stdio.h>
#include<mqueue.h>
#include<sys/stat.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define SERVER_QUEUE "/server_queue"
#define SIZE 1024

struct message{
    char client_queue[50];
    char text[SIZE];
};
int main(){
    mqd_t server_q,client_q;
    struct mq_attr attr;
    struct message msg;
    attr.mq_flags=0;
    attr.mq_maxmsg=10;
    attr.mq_msgsize=sizeof(msg);
    attr.mq_curmsgs=0;

    server_q=mq_open(SERVER_QUEUE,O_CREAT|O_RDONLY,0666,&attr);
    if(server_q==-1){
        perror("mq_open");
        exit(1);
    }
    client_q = mq_open(msg.client_queue, O_WRONLY);
    if(client_q == -1){
        perror("mq_open client");
        exit(1);
    }

    while(1){
        if(mq_receive(server_q,(char*)&msg,sizeof(msg),NULL)==-1){
            perror("mq_receive");
            exit(1);
        }
        printf("Message From Client [%s]: %s",msg.client_queue,msg.text);

        char reply[SIZE];
        printf("Enter Server Response:");
        fgets(reply,SIZE,stdin);

        if(mq_send(client_q,reply,strlen(reply)+1,0)==-1){
            perror("mq_send");
            exit(1);
        }
    }
    mq_close(server_q);
    //mq_close(client_q);
    mq_unlink(SERVER_QUEUE);
}
