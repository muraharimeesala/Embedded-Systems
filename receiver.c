#include <stdio.h>
#include <stdlib.h>
#include <mqueue.h>
#include <string.h>

int main() {
    mqd_t mq;
    char message[100];
    struct mq_attr attr;

    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    mq = mq_open("/myqueue", O_RDONLY | O_CREAT, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }
    if (mq_receive(mq, message, sizeof(message), NULL) == -1) {
        perror("mq_receive");
        exit(1);
    }
    printf("Received message: %s", message);
    if (mq_close(mq) == -1) {
        perror("mq_close");
        exit(1);
    }
    if (mq_unlink("/myqueue") == -1) {
        perror("mq_unlink");
        exit(1);
    }
    return 0;
}
