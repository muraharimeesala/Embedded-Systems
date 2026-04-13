#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<mqueue.h>

#define SERVER "/server_queue"
#define SIZE 1024

struct message{
    char client_queue[50];
    char text[SIZE];
};

int main(){
    mqd_t server_q,client_q;
    struct mq_attr attr;
    struct message msg;
    char reply[SIZE];
    
    sprintf(msg.client_queue,"/client_%d",getpid());
    
    attr.mq_flags=0;
    attr.mq_maxmsg=10;
    attr.mq_msgsize=sizeof(msg);
    attr.mq_curmsgs=0;

    client_q=mq_open(msg.client_queue,O_CREAT|O_RDONLY,0666,&attr);
    server_q=mq_open(SERVER,O_WRONLY);
    if(client_q==-1 || server_q==-1){
        perror("mq_open");
        exit(1);
    }
    while(1){
        printf("Enter Message: ");
        fgets(msg.text,SIZE,stdin);

        mq_send(server_q,(char*)&msg,sizeof(msg),0);

        mq_receive(client_q,reply,SIZE,0);
        printf("Server Reply: %s\n",reply);
    }

    mq_close(server_q);
    mq_close(client_q);
    mq_unlink(msg.client_queue);
}




