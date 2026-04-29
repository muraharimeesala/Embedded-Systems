#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main() {
    pid_t child = fork();

    if (child == 0) {
        // Child process
        sleep(3);  // Sleep for 3 seconds
        printf("Child process exiting...\n");
        exit(42);  // Exit with status 42
    } else {
        // Parent process
        int status;
        printf("Parent waiting for child...\n");
        pid_t pid = waitpid(child, &status, 0);  // Wait until child exits

        if (pid == -1) {
            perror("waitpid failed");
            return 1;
        }

        if (WIFEXITED(status)) {
            printf("Child %d exited with status %d\n", pid, WEXITSTATUS(status));
        } else {
            printf("Child terminated abnormally\n");
        }
    }

    return 0;
}

