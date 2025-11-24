//Write a C program to copy the contents of one file to another?

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
	const char *source="source_file.txt";
	const char *dest="dest_file.txt";
	int src_fd,dest_fd;
	char buff[1024];
	ssize_t ret;
	 // Open source file for reading
	src_fd=open(source,O_RDONLY);
	if(src_fd<0){
		printf("Failed to open file.\n");
		exit(1);
	}
	// Open destination file for writing (create if doesn't exist, truncate if exists)
	dest_fd=open(dest,O_WRONLY|O_CREAT|O_TRUNC,0644);
	if(dest_fd<0){
		printf("Failed to open file.\n");
		close(src_fd);
		exit(1);
	}
	// Read from source and write to destination
	while((ret=read(src_fd,buff,sizeof(buff)))>0){
			if(write(dest_fd,buff,ret)<0){
			printf("Failed to write to destination.\n");
			close(src_fd);
			close(dest_fd);
			exit(1);
		}
	}
	if(ret<0){
		printf("Failed to reading from source file.\n");
		exit(1);
	}
	close(src_fd);
	close(dest_fd);
	printf("Contents of '%s' are copied to '%s' file.\n",source,dest);
}
			

	
