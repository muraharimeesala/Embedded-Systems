#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>

#define SHM_SIZE 1024

int main()
{
    int shmid;
    char *shmaddr;
    key_t key;

    key = ftok("shmfile",65);
    if(key == -1){
        perror("ftok");
        exit(1);
    }

    shmid = shmget(key,SHM_SIZE,0666|IPC_CREAT);
    if(shmid == -1){
        perror("shmget");
        exit(1);
    }

    shmaddr = shmat(shmid,NULL,0);
    if(shmaddr == (char *)-1){
        perror("shmat");
        exit(1);
    }
    while(1){
        printf("SERVER: ");
        fgets(shmaddr,SHM_SIZE,stdin);
        sleep(5);

        printf("CLIENT: %s\n",shmaddr);

        shmdt(shmaddr);
    }

    return 0;
}
