#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mqueue.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#define SERVER_QUEUE "/server_queue"
#define CLIENT_QUEUE "/client_queue"
int main() {
    mqd_t server_qid, client_qid;
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_msgsize = 1024;   // FIXED
    attr.mq_maxmsg = 10;
    attr.mq_curmsgs = 0;
    server_qid = mq_open(SERVER_QUEUE, O_CREAT | O_RDONLY, 0666, &attr);
    if (server_qid == -1) {
        perror("mq_open server");
        exit(EXIT_FAILURE);
    }
    client_qid = mq_open(CLIENT_QUEUE, O_CREAT | O_WRONLY, 0666, &attr);
    if (client_qid == -1) {
        perror("mq_open client");
        exit(EXIT_FAILURE);
    }
    char buff[1024];
    ssize_t bytes;
    while (1) {
        printf("Server waiting...\n");
        bytes = mq_receive(server_qid, buff, attr.mq_msgsize, NULL);
        if (bytes == -1) {
            perror("mq_receive");
            exit(EXIT_FAILURE);
        }
        buff[bytes] = '\0';   // terminate string
        printf("Server received: %s", buff);
        // Convert to uppercase
        for (int i = 0; buff[i]; i++)
            buff[i] = toupper(buff[i]);
	printf("Server: Enter message:\n");
	fgets(buff,sizeof(buff),stdin);
        mq_send(client_qid, buff, strlen(buff), 0);
        printf("Server sent: %s", buff);
    }
    mq_close(server_qid);
    mq_close(client_qid);
    mq_unlink(SERVER_QUEUE);
    mq_unlink(CLIENT_QUEUE);
    return 0;
}

