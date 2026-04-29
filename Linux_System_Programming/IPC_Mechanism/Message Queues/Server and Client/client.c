#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>
struct msgBuff{
	long mtype;
	int clientID;
	char mtext[100];
};
int main(){
	key_t key;
	int msgID;
	struct msgBuff msg;
	struct msgBuff reply;
	if((key=ftok("progFile",65))==-1){
		perror("ftok");
		exit(1);
	}
	if((msgID=msgget(key,0666|IPC_CREAT))==-1){
		perror("msgget");
		exit(1);
	}
	msg.mtype=1;
	msg.clientID=getpid();
	printf("Enter message:\n");
	fgets(msg.mtext,sizeof(msg.mtext),stdin);
	if((msgsnd(msgID,&msg,sizeof(msg)-sizeof(long),0))==-1){
		perror("msgsnd");
		exit(1);
	}
	printf("Waiting for server response....\n");
	if((msgrcv(msgID,&reply,sizeof(reply)-sizeof(long),msg.clientID,0))==-1){
		perror("msgrcv");
		exit(1);
	}
	printf("Server reply:\n%s",reply.mtext);
	return 0;
}
