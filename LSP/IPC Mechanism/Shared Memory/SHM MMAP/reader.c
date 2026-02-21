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
        fd=shm_open(SHM_FILE,O_RDONLY,0666);       // Opemig existing shared memory
        if(fd==-1){
                perror("shm_open");
                exit(EXIT_FAILURE);
        }
	ptr=mmap(0,SIZE,PROT_READ,MAP_SHARED,fd,0);
	if(ptr==MAP_FAILED){
		perror("mmap");
		exit(EXIT_FAILURE);
	}
	printf("Reader read:\n%s",ptr);
	munmap(ptr,SIZE);
}
