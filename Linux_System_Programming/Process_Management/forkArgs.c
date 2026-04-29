#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("child process\n");
		printf("Arguments passed: %s\n",argv[1]);

	}
	else{
		printf("parent process\n");
	}
	return 0;
}
