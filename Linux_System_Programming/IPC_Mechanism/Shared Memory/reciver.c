#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main(){
        char *str;
        key_t key;
        int shmid;
        key=ftok("shmfile",65);
        shmid=shmget(key,4096,0666);
        if(shmid==-1){
                perror("shmget");
                exit(EXIT_FAILURE);
        }       
	str=shmat(shmid,NULL,0);
	if(str==(char*)-1){
                perror("shmat");
                exit(EXIT_FAILURE);
        }
        printf("Data read from shared memory:\n%s\n",str);
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
}

