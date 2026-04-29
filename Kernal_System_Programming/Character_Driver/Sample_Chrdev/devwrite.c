#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
	char writebuf[100];
	int fd;
	int ret;
	fd = open("/dev/sample",O_WRONLY);
	if(fd < 0){
		printf("open error\n");
		return -1;
	}
	
	printf("Enter message to write to device\n");
	fgets(writebuf,sizeof(writebuf),stdin);

	ret = write(fd,writebuf,strlen(writebuf));
	if(ret < 0 ){
		printf("write error\n");
		return -1;
	}
	printf("Message written to device\n");
	close(fd);
	return 0;
}
