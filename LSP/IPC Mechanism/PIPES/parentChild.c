#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main(){
	char buff[1024];
	int fd[2];
	pid_t pid;
	pipe(fd);    //Create PIPE
	printf("Enter data:\n");
	fgets(buff,sizeof(buff),stdin);
	if(pipe(fd)<0){
		perror("pipe");
		exit(1);
	}
	pid=fork();
	if(pid>0){             //Parent
		close(fd[0]);  //Close read end
		if(write(fd[1],buff,strlen(buff))==-1){
			perror("write");
			exit(1);
		}
		close(fd[1]);
	}
	else{                      //Child
		close(fd[1]);     //Close write end
		if(read(fd[0],buff,sizeof(buff))==-1){
			perror("read");
			exit(1);
		}
		printf("Child: Received Data:\n%s",buff);
		close(fd[0]);
	}
	return 0;
}

