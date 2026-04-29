#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(void){
    int fd;
    char filename[100];
    char buffer[1024];
    printf("Enter file name: ");
    scanf("%99s", filename);
    fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    printf("Enter text to write into file:\n");
    getchar();              // clear newline left by scanf
    fgets(buffer, sizeof(buffer), stdin);
    if (write(fd, buffer, strlen(buffer)) == -1) {
        perror("write");
        close(fd);
        exit(1);
    }
    close(fd);
    printf("Data written successfully.\n");
    return 0;
}

