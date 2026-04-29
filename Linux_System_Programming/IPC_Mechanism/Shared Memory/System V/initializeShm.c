// Write a C program that initializes a shared memory segment using shmget. 

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

int main() {
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0666);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }
    printf("Shared memory segment created with ID: %d\n", shmid);
    return 0;
}
