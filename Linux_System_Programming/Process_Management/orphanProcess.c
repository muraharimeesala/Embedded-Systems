#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid>0){
		printf("Parent exiting\n");
		return 0;
	}
	else{
		sleep(5);
		printf("Child running And New PID: %d\n",getppid());
	}
	return 0;
}
