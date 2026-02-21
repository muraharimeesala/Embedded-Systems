#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#define MQ_NAME "/msgqueue"
int main() {
    mqd_t fd;
    struct mq_attr attr;
    // Set queue attributes
    attr.mq_flags = 0;         // 0 or O_NONBLOCK
    attr.mq_maxmsg = 10;      // Max no of messages allowed
    attr.mq_msgsize = 1024;   // IMPORTANT: same as receiver
    attr.mq_curmsgs = 0;      // Current no of massages (read only)
    fd = mq_open(MQ_NAME, O_CREAT | O_WRONLY, 0666, &attr);
    if (fd == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    char buff[1024];
    printf("Enter Message:\n");
    fgets(buff, sizeof(buff), stdin);
    if (mq_send(fd, buff, strlen(buff) + 1, 10) == -1) {
        perror("mq_send");
        exit(EXIT_FAILURE);
    }
    printf("Message Sent\n");
    mq_close(fd);
}

