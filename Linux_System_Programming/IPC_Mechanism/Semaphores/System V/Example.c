#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    key_t key;
    int semid;
    key = ftok("example",65);
    if(key == -1){
        perror("ftok");
        exit(1);
    }
    semid = semget(key, 1, 0666 | IPC_CREAT);
    if(semid == -1){
        perror("semget");
        exit(1);
    }
    semctl(semid, 0, SETVAL, 1);

    printf("Process trying to enter critical section\n");
    struct sembuf wait_op = {0,-1,0};  
    struct sembuf signal_op = {0,1,0};
        semop(semid, &wait_op, 1);           // Entered Critical Section
        printf("Hello\n");
        sleep(1);
        semop(semid, &signal_op, 1);         // Exited Critical Section
    
    return 0;
}
