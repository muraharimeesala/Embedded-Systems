#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#define SIZE 4096
#define SH_FILE "/example"
int main() {
    char *ptr;
    int fd;
    fd = shm_open(SH_FILE, O_RDONLY, 0666);
    if (fd < 0) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);
    if (ptr == MAP_FAILED) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    printf("Reader read the data:\n%s\n", ptr);
    munmap(ptr, SIZE);
    close(fd);
}

