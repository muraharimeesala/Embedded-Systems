#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
int pid,stat;
int chpid1,chpid2;
chpid1=fork();
if(chpid1==0){
printf("First child process\n");
sleep(60);
exit(8);
}
chpid2=fork();
if(chpid2==0){
printf("Second child process\n");
sleep(30);
exit(4);
}
//pid=wait(&stat);
pid=waitpid(pid,&stat,0);
printf("%d",WEXITSTATUS(stat));
pid=wait(&stat);
//pid=waitpid(pid,&stat,0);
printf("%d",WEXITSTATUS(stat));
}
