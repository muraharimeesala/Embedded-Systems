#include<stdio.h>
#include<unistd.h>
//#include<stdlib.h>
//#include<sys/wait.h>
int main(){
int i;
for(i=0;i<4;i++){
fork();
printf("Hello\n");
}
}
