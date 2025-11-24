#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
char *args[] = {"./hello", NULL};
pid_t pid = fork();
if(pid == 0){
execv("./hello", args);
perror("execv"); // only runs if exec fails
}
else {
wait(NULL);
printf("Parent: hello finished\n");
}
return 0;
}

