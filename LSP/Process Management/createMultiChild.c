#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	for(int i=0;i<5;i++){
		pid=fork();
		if(pid==0){
			printf("Child [%d]=%d\n",i,getpid());
			exit(0);
		}
	}
	for(int i=0;i<5;i++){
		wait(NULL);
	}
	return 0;
}
