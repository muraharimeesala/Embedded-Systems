// Design a program where multiple processes are forked and synchronization is achieved using semaphores.

#include<stdio.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/sem.h>
#include<stdlib.h>

int main()
{
    key_t key;
    int semid;
    key = ftok("multifork",65);
    if(key == -1)
    {
        perror("ftok");
        exit(1);
    }

    semid = semget(key,1,0666 | IPC_CREAT);
    if(semid == -1)
    {
        perror("semget");
        exit(1);
    }
    printf("Semaphore ID = %d\n",semid);
    semctl(semid,0,SETVAL,1);
    struct sembuf wait={0,-1,0};
    struct sembuf signal={0,1,0};

    for(int i=0;i<2;i++){
        if(fork()==0){
            semop(semid,&wait,1);
            printf("Semaphore Enterd Critical Section With Process ID = %d\n",getpid());
            sleep(2);
            printf("Semaphore Exited Critical Section With Process ID = %d\n",getpid());
            semop(semid,&signal,1);
            exit(0);
        }
    }
    sleep(10);
    return 0;
}
