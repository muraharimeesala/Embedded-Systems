#include<stdio.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

#define SHM_NAME "/shm"
#define SIZE 1024

int main(){
    char *shm;
    int shmfd;

    shmfd=shm_open(SHM_NAME, O_CREAT|O_RDWR, 0666);    // open or create
    if(shmfd==-1){
        perror("shm_open");
        return 1;
    }
    ftruncate(shmfd, SIZE);        // resize

    shm=mmap(NULL,SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,shmfd,0);    // map
    if(shm==MAP_FAILED){
        perror("mmap");
        return 1;
    }
    printf("Enter Message:");
    fgets(shm,SIZE,stdin);

    munmap(shm,SIZE);           // unmap
    close(shmfd);
    return 0;
}


