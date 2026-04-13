#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char *argv[]){
	int fd1,fd2;
	char buff[1024];
	size_t ret;
	if(argc!=3){
		printf("Usage:%s <src><dest>\n",argv[0]);
		exit(1);
	}
	fd1=open(argv[1],O_RDONLY);
	if(fd1<0){
		perror("open");
		exit(1);
	}
	fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0664);
	if(fd2<0){
		perror("open");
		exit(1);
	}
	while((ret=read(fd1,buff,sizeof(buff)))>0){
		write(fd2,buff,ret);
	}
	close(fd1);
	close(fd2);
	printf("Coping is sucessfully.\n");
}
