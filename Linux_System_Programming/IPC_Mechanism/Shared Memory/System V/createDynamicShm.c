// Write a program that dynamically creates shared memory segments based on user input

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZE 1024
int main() {
    key_t key;
    int shmid;
    char *shmaddr;

    key = ftok("shmfile", 'a');
    if(key == -1) {
        perror("ftok");
        return 1;
    }
    printf("Key: %d\n", key);

    shmid = shmget(key, SIZE, IPC_CREAT | 0666);
    if(shmid == -1) {
        perror("shmget");
        return 1;
    }

    printf("Shared Memory ID: %d\n", shmid);

    shmaddr = shmat(shmid, NULL, 0);
    if(shmaddr == (char *)-1) {
        perror("shmat");
        return 1;
    }

    printf("Shared Memory Address: %p\n", shmaddr);
    printf("Enter message to store in shared memory: ");
    fgets(shmaddr, SIZE, stdin);

    printf("Message stored in shared memory: %s", shmaddr);

    shmdt(shmaddr);
   // shmctl(shmid, IPC_RMID, NULL);
  // printf("Shared memory segment deleted.\n");
    return 0;
}
