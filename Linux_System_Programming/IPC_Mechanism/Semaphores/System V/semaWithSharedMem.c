// Write a program that combines semaphores and shared memory for synchronization between processes.

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <unistd.h>

union semun { int val; };

int main()
{
    key_t key = ftok("file",65);
    if(key == -1)
    {
        perror("ftok");
        exit(1);
    }

    int shmid = shmget(key,1024,0666|IPC_CREAT);
    if(shmid == -1)
    {
        perror("shmget");
        exit(1);
    }
    char *data = shmat(shmid,NULL,0);
    if(data == (char*)-1)
    {
        perror("shmat");
        exit(1);
    }
    int semid = semget(key,1,0666|IPC_CREAT);
    if(semid == -1)
    {
        perror("semget");
        exit(1);
    }

    union semun arg;
    arg.val = 1;
    semctl(semid,0,SETVAL,arg);

    struct sembuf wait = {0,-1,0};
    struct sembuf signal = {0,1,0};

    if(fork()==0)
    {
        semop(semid,&wait,1);
        printf("Enter Message:");
        fgets(data,1024,stdin);
        semop(semid,&signal,1);
    }
    else
    {
        sleep(1);
        semop(semid,&wait,1);
        printf("Parent read: %s\n",data);
        semop(semid,&signal,1);
    }
}
