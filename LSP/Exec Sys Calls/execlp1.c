#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
pid_t pid = fork();
if (pid == 0) {
// Child process
printf("Child: executing ls command\n");
execlp("ls", "ls", "-l", NULL);
// If execlp returns, it must have failed
perror("execlp");
} 
else {
// Parent process
wait(NULL);
printf("Parent: child finished\n");
}
return 0;
}

