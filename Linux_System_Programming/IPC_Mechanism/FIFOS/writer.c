#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
int main(){
	char *fifo="mypipe";
	int fd;
	if(mkfifo(fifo,0666)==-1){
		perror("mkfifo");
		exit(1);
	}
	if((fd=open(fifo,O_WRONLY))==-1){
		perror("open");
		exit(1);
	}
	char msg[1024];
	printf("Writer: Enter Message:\n");
	fgets(msg,sizeof(msg),stdin);
	if(write(fd,msg,strlen(msg))==-1){
		perror("write");
		exit(1);
	}
	printf("Writer: Sent Message:\n%s",msg);
	close(fd);
}
