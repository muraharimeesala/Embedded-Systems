#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
int main(){
	int msgid;
	key_t key;
	key=ftok("example",65);
	if(key==-1){
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	msgid=msgget(key,IPC_CREAT|0666);
	if(msgid==-1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Message queue is created successfully.\n");
	printf("Message ID:%d\n",msgid);
}
