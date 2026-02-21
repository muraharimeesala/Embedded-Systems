#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/sem.h>
void wait_semaphore(int semid){
	struct sembuf s={0,-1,0};
	semop(semid,&s,1);
}
void signal_semaphore(int semid){
	struct sembuf s={0,+1,0};
	semop(semid,&s,1);
}
int main(){
	key_t key;
	int semid;
	key=ftok("file",65);
	if(key==-1){
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	semid=semget(key,1,IPC_CREAT|0666);
	if(semid==-1){
		perror("semget");
		exit(EXIT_FAILURE);
	}
	semctl(semid,0,SETVAL,1);
	printf("SERVER: Waiting to enter critical section.\n");
	wait_semaphore(semid);
	printf("SERVER: Inside critical section.\n");
	sleep(2);
	signal_semaphore(semid);
	printf("SERVER: Exited critical section.\n");
}
