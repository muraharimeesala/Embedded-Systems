// Implement a program that uses pipes for communication between a parent and child process. Show how data can be passed between processes using pipes.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        close(pipefd[0]);
        char message[] = "Hello, parent!";
        write(pipefd[1], message, sizeof(message));
        close(pipefd[1]);
        return 0;
    } else {
        // Parent process
        close(pipefd[1]);
        char buffer[100];
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Message from child: %s\n", buffer);
        close(pipefd[0]);
        wait(NULL);
        return 0;
    }
}
