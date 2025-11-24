#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
int pid,i,stat;
for(i=0;i<3;i++){
pid=fork();
if(pid==0){
printf("Child process:%d with PID:%d exiting with code:%d\n",i,getpid(),i+10);
exit(i+10);
}
}
for(i=0;i<3;i++){
pid=wait(&stat);
int code=WEXITSTATUS(stat);
printf("Parent:Child with PID:%d exiting with code:%d\n",pid,code);
}
}
