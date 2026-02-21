#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	char filename[100];
	char buff[1024];
	int fd;
	printf("Enter file namei:");
	scanf("%s",filename);
	fd=open(filename,O_APPEND|O_WRONLY,0664);
	if(fd<0){
		perror("open");
		exit(1);	
	}
	printf("Enter data to append:\n");
	getchar();
	fgets(buff,sizeof(buff),stdin);
	if(write(fd,buff,strlen(buff))==-1){
		perror("write");
		close(fd);
		exit(1);
	}
	close(fd);
	printf("Data appending successfully\n");
}
