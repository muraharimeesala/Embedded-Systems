#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(){
	int fd,ret;
	char readbuf[100];
	fd = open("/dev/sample",O_RDONLY);
	if(fd < 0){
		printf("open error\n");
		return -1;
	}
	ret = read(fd,readbuf,sizeof(readbuf));
	if(ret < 0){
		printf("read error\n");
		return -1;
	}
	readbuf[ret] = '\0';
	printf("Message read from device: %s\n",readbuf);

	close(fd);
	return 0;
}

