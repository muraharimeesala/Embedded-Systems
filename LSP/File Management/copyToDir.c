#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
int main(){
	char src[256],dirDest[256],destPath[256];
	int src_fd,dest_fd;
	char buff[1024];
	ssize_t ret;
	struct stat sa;
	printf("Enter a source file:");
	scanf("%s",src);
	printf("Enter  destination file:");
	scanf("%s",dirDest);
	if((stat(src,&sa)!=0) || (S_ISREG(sa.st_mode)!=0)){
		printf("Source file is not exit.\n");
		exit(1);
	}
	if((stat(dirDest,&sa)!=0) || (S_ISDIR(sa.st_mode)!=0)){
		printf("Destination directory not exit.\n");
		exit(1);
	}
	char *filename=strrchr(src,'/');
	if(filename){
	filename++;
	}
	else{
		filename=src;
	}
	printf(destPath,"%s/%s",dirDest,filename);
	src_fd=open(src,O_RDONLY);
	if(src_fd<0){
		printf("Failed to open\n");
		exit(1);
	}
	dest_fd=open(dirDest,O_RDONLY|O_WRONLY|O_TRUNC,0664);
	if(dest_fd<0){
		printf("Failed to open.\n");
		exit(1);
	}
	while((ret=read(src_fd,buff,sizeof(buff)))>0){
		write(dest_fd,buff,ret);
	}
	printf("'%s'is copied to '%s' successfully.\n",src,dirDest);
	close(src_fd);
	close(dest_fd);
}
		



