#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("Child PID is %d\n",getpid());
	}
	else{
		printf("Parent PID is %d\n",getpid());
		wait(NULL);
		printf("Child PID is %d\n",pid);
	}
	return 0;
	
}
