#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0){
		exit(1);
		//sleep(5);
		printf("child process: PPID=%d\n",getppid());
	}
	else{
		printf("parent exit\n");
	}
	return 0;
}
