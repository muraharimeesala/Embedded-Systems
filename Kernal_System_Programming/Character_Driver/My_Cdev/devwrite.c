#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

int main(){
	char wrbuff[512];
	int ret=0;
	int fd=open("/dev/mychrmod",O_RDWR);
	if(fd < 0){
		printf("Error opening device\n");
		return -1;
	}
	printf("Enter the string to write to device\n");
	scanf("%s",wrbuff);
	ret = write(fd,wrbuff,strlen(wrbuff));
	if(ret < 0){
		printf("Error writing to device\n");
		return -1;
	}
	close(fd);
	return 0;
}
