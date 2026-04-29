#include<stdio.h>
#include<sys/stat.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/mman.h>
#include<fcntl.h>

#define SHM_NAME "/shm"
#define SIZE 1024

int main(){
    char *shm;
    int shmfd;

    shmfd=shm_open(SHM_NAME, O_RDONLY, 0666);
    if(shmfd==-1){
        perror("shm_open");
        return 1;
    }
    shm=mmap(NULL,SIZE,PROT_READ,MAP_SHARED,shmfd,0);
    if(shm==MAP_FAILED){
        perror("mmap");
        return 1;
    }
    
    printf("Message:%s",shm);
    
    munmap(shm,SIZE);
    close(shmfd);
    shm_unlink(SHM_NAME);
    
    return 0;
}
