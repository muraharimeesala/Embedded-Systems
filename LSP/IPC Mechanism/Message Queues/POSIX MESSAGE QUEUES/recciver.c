#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <unistd.h>
#define MQ_NAME "/msgqueue"
int main() {
    mqd_t fd;
    unsigned int prio;
    struct mq_attr attr;
    fd = mq_open(MQ_NAME, O_RDONLY);
    if (fd == (mqd_t)-1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    // Get queue attributes
    mq_getattr(fd, &attr);
    char buff[attr.mq_msgsize + 1];
    ssize_t ret = mq_receive(fd, buff, attr.mq_msgsize, &prio);
    if (ret == -1) {
        perror("mq_receive");
        exit(EXIT_FAILURE);
    }
    buff[ret] = '\0';   // NULL TERMINATE BEFORE PRINTING
    printf("Received Message: %s (prio %u)\n", buff, prio);
    mq_close(fd);
    mq_unlink(MQ_NAME);
}

