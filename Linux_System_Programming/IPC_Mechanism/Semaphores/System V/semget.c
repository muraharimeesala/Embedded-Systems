// Write a C program that uses semget to create a new semaphore set

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    key_t key = ftok("semfile", 65);
    if(key == -1) {
        perror("ftok");
        exit(1);
    }
    int semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        exit(1);
    }
    printf("Semaphore set created with ID: %d\n", semid);
    return 0;
}
