#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/mman.h>
#define SIZE 4096
#define SHM_FILE "/myshm"
int main(){
	int fd;
	char *ptr;
	fd=shm_open(SHM_FILE,O_CREAT|O_RDWR,0666);       // Creating shared memory object
	if(fd==-1){
		perror("shm_open");
		exit(EXIT_FAILURE);
	}
	ftruncate(fd,SIZE);        // Set Memory size
	ptr=mmap(0,SIZE,PRO_READ|PRO_WRITE,MAP_SHARED,fd,0);        // Map It
	if(ptr==MAP_FAILED){
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("Enter data to share:\n");
	fgets(ptr,SIZE,stdin);
	printf("Writer Wrote:\n%s",ptr);
}
