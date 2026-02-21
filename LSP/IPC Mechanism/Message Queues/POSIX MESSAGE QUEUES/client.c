#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <mqueue.h>
#define SERVER_QUEUE "/server_queue"
#define CLIENT_QUEUE "/client_queue"
int main() {
    ssize_t bytes;
    mqd_t server_qid, client_qid;
    server_qid = mq_open(SERVER_QUEUE, O_WRONLY);
    if (server_qid == -1) {
        perror("mq_open server");
        exit(EXIT_FAILURE);
    }
    client_qid = mq_open(CLIENT_QUEUE, O_RDONLY);
    if (client_qid == -1) {
        perror("mq_open client");
        exit(EXIT_FAILURE);
    }
    char buff[1024];
    while (1) {
        printf("Client: Enter message:\n");
        fgets(buff, sizeof(buff), stdin);
        // Send to server
        mq_send(server_qid, buff, strlen(buff), 0);
        // Receive reply
	printf("Client waiting...\n");
        bytes = mq_receive(client_qid, buff, sizeof(buff), NULL);
        if (bytes == -1) {
            perror("mq_receive");
            exit(EXIT_FAILURE);
        }
        buff[bytes] = '\0';
        printf("Client received: %s", buff);
    }
    mq_close(server_qid);
    mq_close(client_qid);
    return 0;
}

