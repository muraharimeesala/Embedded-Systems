// Implement a program that uses pipes for communication between a parent and child process. Show how data can be passed between processes using pipes.

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if(pid == 0){
        close(fd[0]);
        char message[] = "Hello, parent!";
        write(fd[1], message, sizeof(message));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        char buffer[100];
        read(fd[0], buffer, sizeof(buffer));
        printf("Message from child: %s\n", buffer);
        close(fd[0]);
        wait(NULL);
    }
    return 0;
}
