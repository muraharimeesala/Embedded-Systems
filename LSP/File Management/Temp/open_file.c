#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	const char *filename="txt_file.txt";
        char buff[1024];
	int fd;
	ssize_t ret;
	fd=open(filename,O_RDONLY);
	if(fd<0){
		printf("Failed to open file.\n");
		exit(1);
		printf("Content of '%s' is:",filename);
	}
	while((ret=read(fd,buff,sizeof(buff)))>0){
		write(STDOUT_FILENO,buff,ret);
	}
	if(ret<0){
		printf("Failed to read the file.\n");
		close(fd);
		exit(1);
	}
	close(fd);
}
