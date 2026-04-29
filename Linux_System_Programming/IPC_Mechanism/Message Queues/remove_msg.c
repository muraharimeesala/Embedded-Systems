#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
int main(){
	key_t key;
	int msgid;
	char choice;
	key=ftok("filemsg",65);
	if(key==-1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	msgid=msgget(key,0666);
	if(msgid==-1){
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	printf("Message ID:%d\n",msgid);
	printf("Are sure want to delete message queue(y/n):");
	scanf("%c",&choice);
	if(choice=='Y'|| choice=='y'){
		if(msgctl(msgid,IPC_RMID,NULL)==-1){
			perror("msgctl");
			exit(EXIT_FAILURE);
		}
		printf("Message queue successfully deleted.\n");
	}
	else{
		printf("Deletion Failed.\n");
	}
}
