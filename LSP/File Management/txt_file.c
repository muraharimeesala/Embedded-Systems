#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	const char *filename="file_txt.txt";
	const char *text="Hello World!!";
	int fd;
	fd=open("file_txt.txt",O_WRONLY|O_CREAT,0644);
	if(fd<0){
		printf("Failed to open file.\n");
		exit(1);
	}
	if(write(fd,text,sizeof("Hello World!!")-1)==-1){
		printf("Failed to write file.\n");
		close(fd);
		exit(1);
	}
	close(fd);
	printf("File '%s' is created successfully with content '%s'\n",filename,text);
}
