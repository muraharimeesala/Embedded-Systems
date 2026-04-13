#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main(){
int stat,opt,id;
while(1){
printf("Enter option(0 to exit):");
scanf("%d",&opt);
if(!opt)
exit(0);
id=fork();
if(id==0){
execl("/bin/ls","ls","-l",(char*)0);
exit(5);
}
wait(&stat);
}
}
