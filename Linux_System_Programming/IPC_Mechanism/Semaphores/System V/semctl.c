// Enhance the program to initialize the values of the semaphores(binary semaphore) in the set using semctl.

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
    int val;

};
int main() {
    key_t key = ftok("semfile",65);
    if(key == -1){
        perror("ftok");
        return 1;
    }

    int semid = semget(key,1,IPC_CREAT|0666);
    if(semid == -1){
        perror("semget");
        return 1;
    }

    union semun arg;
    arg.val = 5;
    semctl(semid,0,SETVAL,arg);
    int value=semctl(semid,0,GETVAL,NULL);
    if(value == -1){
        perror("semctl");   
        return 1;
    }
    printf("Semaphore value set to: %d\n",value);
    
    semctl(semid,0,IPC_RMID,NULL);
    printf("Semaphore deleted.\n");
    return 0;
}
