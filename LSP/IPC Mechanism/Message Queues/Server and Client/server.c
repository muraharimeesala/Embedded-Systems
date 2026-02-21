#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/msg.h>
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
	printf("Server Started......\n");
	while(1){
		if(msgrcv(msgID,&msg,sizeof(msg)-sizeof(long),1,0)==-1){
			perror("msgrcv");
			exit(1);
		}
		printf("Received from client:%d: %s\n",msg.clientID,msg.mtext);
		reply.mtype=msg.clientID;
		printf("Enter Message:");
		fgets(reply.mtext,sizeof(reply.mtext),stdin);
		if(msgsnd(msgID,&reply,sizeof(reply)-sizeof(long),0)==-1){
			perror("msgsnd");
			exit(1);
		}
	}
	return 0;
}
