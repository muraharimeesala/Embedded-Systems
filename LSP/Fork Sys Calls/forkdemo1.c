#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
int num;
pid_t pid;
printf("Enter a number:");
scanf("%d",&num);
pid=fork();
if(pid<0){
printf("Fork failed\n");
}
else if(pid==0){
if(num%2==0){
printf("parent process:\n%d is Even\n",num);
}else{
printf("parent process:\n%d is  not Even\n",num);
}
if(num%2!=0){
printf("child process:\n%d is Odd\n",num);
}
else{
printf("child process:\n+++%d is not Odd\n",num);
}
}
}
