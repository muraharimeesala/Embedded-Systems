#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(){
    int shmid;
    char *shmaddr;
    key_t key;

    key = ftok("shmfile",65);
    if(key == -1){
        perror("ftok");
        return 1;
    }

    shmid = shmget(key,SHM_SIZE,0666|IPC_CREAT);
    if(shmid == -1){
        perror("shmget");
        return 1;
    }

    shmaddr = shmat(shmid,NULL,0);
    if(shmaddr == (char *) -1){
        perror("shmat");
        return 1;
    }
    printf("Data read from shared memory: %s\n",shmaddr);
    shmdt(shmaddr);
    return 0;
}
