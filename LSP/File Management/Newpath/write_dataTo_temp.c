#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
int main(){
	char template[]="/temp/tempfileXXXXXX";
	int fd;
	fd=mkstemp(template);
	if(fd=-1){
		printf("mkstemp is failed.\n");
		exit(1);
	}
	printf("Temporary file is created successfully.\n");
	const char *data="This is temporary data\n";
	ssize_t ret=write(fd,data,sizeof(data));
	if(ret=-1){
		printf("Failed to write.\n");
		exit(1);
		close(fd);
	}
	printf("Data written to temporary file successfully\n");
	close(fd);
	unlink(template);
	printf("Temporary data deleted.\n");
}
