#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<fcntl.h>
#include<mqueue.h>
#include<string.h>

#define QUEUE_NAME "/pc_queue"
#define SIZE 1024

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
mqd_t mqid;
int i = 1;

void *producer(void *arg)
{
    char msg[SIZE];

    while(1)
    {
        pthread_mutex_lock(&mutex);

        sprintf(msg,"%d",i);

        if(mq_send(mqid,msg,strlen(msg)+1,0) == -1)
        {
            perror("mq_send");
            exit(1);
        }

        printf("PRODUCER: Produced = %s\n",msg);

        i++;
        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    char msg[SIZE];

    while(1)
    {
        pthread_mutex_lock(&mutex);

        if(mq_receive(mqid,msg,SIZE,NULL) == -1)
        {
            perror("mq_receive");
            exit(1);
        }

        printf("CONSUMER: Consumed = %s\n",msg);

        pthread_mutex_unlock(&mutex);

        sleep(1);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t p,c;
    struct mq_attr attr;
    mq_unlink(QUEUE_NAME);
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = SIZE;
    attr.mq_curmsgs = 0;

    mqid = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0666, &attr);

    if(mqid == -1)
    {
        perror("mq_open");
        exit(1);
    }

    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);

    pthread_join(p,NULL);
    pthread_join(c,NULL);

    mq_close(mqid);
    mq_unlink(QUEUE_NAME);

    pthread_mutex_destroy(&mutex);

    return 0;
}
