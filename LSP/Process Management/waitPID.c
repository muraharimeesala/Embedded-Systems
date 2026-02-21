#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("child process: PID:%d\n",getpid());
		sleep(2);
		printf("Child exiting\n");
		return 5;
	}
	else{
		int status;
		printf("Parent waiting for child\n");
		waitpid(pid,&status,0);
		printf("Parent exited with status: %d\n",WEXITSTATUS(status));
	}

		
}
