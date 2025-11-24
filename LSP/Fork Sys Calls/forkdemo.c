#include<stdio.h>
#include<sys/types.h>
int main(){
int pid;
pid=fork();
if(0==pid){
int i=0;
for(i=0;i<5;++i){
printf("This is child process\n");
sleep(1);
}
}
else{
int i=0;
for(i=0;i<5;++i){
printf("This is parent process\n");
sleep(1);
}
}
}

