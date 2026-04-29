#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>
int main(){
	char buff[1024],Sent[1024],Rece[1024];
	int pToC[2],cToP[2];        //Parent to Child to Parent 
	pid_t pid;
	if(pipe(pToC) || pipe(cToP)==-1){
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if(pid>0){
		close(pToC[0]);
		close(cToP[1]);
		printf("Parent: Enter Message:\n");
		fgets(Sent,sizeof(Sent),stdin);
		if(write(pToC[1],Sent,strlen(Sent))==-1){
			perror("write");
			exit(1);
		}
		printf("Parent: Send Message:\n%s",Sent);
		if(read(cToP[0],buff,sizeof(buff))==-1){
			perror("read");
			exit(1);
		}
		printf("Parent: Received Message:\n%s",buff);
		wait(NULL);
		close(pToC[1]);
		close(cToP[0]);
	}
	else{
		close(pToC[1]);
		close(cToP[0]);
		if(read(pToC[0],buff,sizeof(buff))==-1){
			perror("read");
			exit(1);
		}
		printf("Child: Received Message:\n%s",buff);
		printf("Child: Enter Replay Message:\n");
		fgets(Rece,sizeof(Rece),stdin);
		if(write(cToP[1],Rece,strlen(Rece))==-1){
			perror("write");
			exit(1);
		}
		printf("Child: Sent Message:\n%s",Rece);
		close(pToC[0]);
		close(cToP[1]);
	}
	return 0;
}

