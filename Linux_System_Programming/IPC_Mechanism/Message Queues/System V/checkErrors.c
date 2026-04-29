// Write a C program to create a message queue using the msgget system call. Ensure that the program checks for errors during the creation process.

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int key = 1234;
    int msgid = msgget(key, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    printf("Message queue created with ID: %d\n", msgid);
    return 0;
}
