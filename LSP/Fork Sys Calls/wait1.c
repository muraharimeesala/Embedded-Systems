#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
int stat,id;
id=fork();
if(id==0){
printf("Child process");
exit(5);
}
id=wait(&stat);
printf("%d",WEXITSTATUS(stat));
}

