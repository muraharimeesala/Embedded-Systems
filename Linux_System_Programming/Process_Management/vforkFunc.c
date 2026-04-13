#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
	pid_t pid;
	pid=vfork();
	if(pid==0)
	{
		printf("Child Process:%d\n",getpid());
		_exit(0);
	}
	else
	{
		printf("Parent Process:%d\n",getpid());
	}
	return 0;
}
