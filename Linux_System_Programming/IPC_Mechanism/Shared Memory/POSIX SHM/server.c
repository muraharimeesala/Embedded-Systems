#include<stdio.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

#define SHM_SIZE 1024
#define S2C_NAME "/s2c"
#define C2S_NAME "/c2s"

int main(){
    int fd1,fd2;
    char *s2c,*c2s;
    fd1 = shm_open(S2C_NAME, O_CREAT | O_RDWR, 0666);
    fd2 = shm_open(C2S_NAME, O_CREAT | O_RDWR, 0666);
    if(fd1 == -1 || fd2 == -1){
        perror("shm_open");
        exit(1);
    }
    ftruncate(fd1, SHM_SIZE);
    ftruncate(fd2, SHM_SIZE);
    if(fd1 == -1 || fd2 == -1){
        perror("ftruncate");
        exit(1);
    }
    s2c = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd1, 0);
    c2s = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
    if(s2c == MAP_FAILED || c2s == MAP_FAILED){
        perror("mmap");
        exit(1);
    }
    while(1)
    {
        printf("CLIENT: %s", c2s);

        printf("SERVER: ");
        fgets(s2c, SHM_SIZE, stdin);

        sleep(2);
    }
    munmap(c2s, SHM_SIZE);
    close(fd1);
    close(fd2);
}

