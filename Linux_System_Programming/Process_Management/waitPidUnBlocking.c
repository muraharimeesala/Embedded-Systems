#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t child = fork();

    if (child == 0) {
        // Child sleeps for 5 seconds
        sleep(5);
        printf("Child exiting...\n");
        exit(42);
    } else {
        // Parent polls for child
        int status;
        printf("Parent checking child status...\n");

        // First check — child hasn't exited yet
        pid_t pid = waitpid(child, &status, WNOHANG);
        if (pid == 0) {
            printf("Child not ready yet.\n");
        } else if (pid == -1) {
            perror("waitpid failed");
        } else {
            printf("Child %d exited with status %d\n", pid, WEXITSTATUS(status));
        }

        // Wait for child to exit (non-blocking check)
        while (1) {
            pid_t p = waitpid(child, &status, WNOHANG);
            if (p == 0) {
                printf("Still waiting...\n");
                sleep(1);
            } else if (p == -1) {
                perror("waitpid");
                break;
            } else {
                printf("Child %d exited with status %d\n", p, WEXITSTATUS(status));
                break;
            }
        }
    }

    return 0;
}

