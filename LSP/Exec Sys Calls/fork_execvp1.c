#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(){
pid_t pid;
if(pid<0){
printf("Fork failed\n");
}
else if(pid==0){
printf("Child: running 'ls l' using execvp()\n");
char *args[]={"ls","-l",NULL};
execvp("ls",args);
}
else{
wait(NULL);
printf("Parent: child finished execution\n");
}
}

