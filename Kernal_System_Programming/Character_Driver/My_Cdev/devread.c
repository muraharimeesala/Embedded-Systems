#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(){
	char rdbuf[512]={0};
	int ret=0;
	int fd;
	fd = open("/dev/mychrmod", O_RDONLY);
	if(fd < 0){
		perror("failed to open device file");
		return -1;	
	}
	ret = read(fd, rdbuf, sizeof(rdbuf));
	if(ret < 0){
		perror("failed to read from device file");
		return -1;
	}
	rdbuf[ret] = '\0';
	printf("read from device file: %s\n", rdbuf);
	close(fd);

}
