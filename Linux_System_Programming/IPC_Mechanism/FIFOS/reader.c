#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main(){
	char *fifo="mypipe";
	int fd;
	char msg[1024];
	if(open(fifo,O_RDONLY)==-1){
		perror("open");
		exit(1);
	}
	if(read(fd,msg,sizeof(msg))==-1){
		perror("read");
		exit(1);
	}
	printf("Reader: Received Message:\n%s",msg);
	close(fd);
}
