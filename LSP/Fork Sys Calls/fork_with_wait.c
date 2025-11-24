#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
pid_t pid;
pid=fork();
if(pid<0){
printf("Fork failed\n");
}
else if(pid==0){
printf("Child Process\n");
sleep(4);
printf("Child: Finished work\n");
}
else{
int stat;
printf("Parent: waiting for child to finish\n");
wait(&stat);
printf("Parent: Child finished Status: %d\n",WEXITSTATUS(stat));
}
}
