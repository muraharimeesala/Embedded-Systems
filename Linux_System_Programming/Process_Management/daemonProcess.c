#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid>0){
		exit(1);
	}
	if(pid==0){
		exit(1);
	}
	setsid();
	chdir("/");
	close(0);
	close(1);
	close(2);
	while(1){
		sleep(20);
	}
	return 0;
}
