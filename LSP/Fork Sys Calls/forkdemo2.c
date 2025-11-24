#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
pid_t pid;
pid=fork();
if(pid<0){
printf("Fork failed\n");
}
else if(pid==0){
// Child process (pid = 0 returned to child)
printf("Child Process:\n");
printf("Child PID =%d\n",getpid());              // Child Process ID
printf("Parent PID =%d\n",getppid());            // Parent Process ID
}
else{
// Parent process (pid = child’s PID returned to parent)
printf("Parent Process:\n");
printf("Parent PID =%d\n",getpid());             //Parent Process ID
printf("Child PID =%d\n",pid);             //Child PID
}
}
