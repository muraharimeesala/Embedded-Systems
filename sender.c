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
    mq = mq_open("/myqueue", O_WRONLY | O_CREAT, 0644, &attr);
    if (mq == -1) {
        perror("mq_open");
        exit(1);
    }
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    if (mq_send(mq, message, strlen(message), 0) == -1) {
        perror("mq_send");
        exit(1);
    }
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
