#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	char filename[100];
	char buff[1024];
	int fd;
	ssize_t ret;
	printf("Enter file name:");
	scanf("%s",filename);
	fd=open(filename,O_RDONLY,0664);
	if(fd<0){
		perror("open");
		exit(1);
	}
	if((ret=read(fd,buff,sizeof(buff)))==-1){
		perror("read");
		close(fd);
		exit(1);
	}
	buff[ret]='\0';
	close(fd);
	printf("Data readed successfully:\n%s",buff);

}
