#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#define SIZE 4096
#define SH_FILE "/example"
int main(){
	char *ptr;
	int fd;
	fd=shm_open(SH_FILE,O_CREAT|O_RDWR,0666);
	if(fd<0){
		perror("shm_open");
		exit(EXIT_FAILURE);
	}
	ftruncate(fd,SIZE);
	ptr=mmap(0,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
	if(ptr==MAP_FAILED){
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("Enter data:\n");
	fgets(ptr,SIZE,stdin);
	printf("Writer Wrote data:\n%s",ptr);
	munmap(ptr,SIZE);
	close(fd);
	shm_unlink(SH_FILE);
}

