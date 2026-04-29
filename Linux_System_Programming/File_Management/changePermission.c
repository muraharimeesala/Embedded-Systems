// Implement a C program to change the permissions of a file to read-only? 
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char file[100];
    printf("Enter the file name: ");
    scanf("%s", file);
    int fd = open(file, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    int result = chmod(file, S_IREAD);
    if (result == -1) {
        perror("chmod");
        return 1;
    }
    close(fd);
    return 0;
}
