#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	int n,i;
	pid_t pid;
	printf("Enter no of child process:");
	scanf("%d",&n);
	printf("Parent PID:%d\n",getppid());
	for(i=0;i<n;i++){
		pid=fork();
	if(pid<0){
		printf("fork failed.\n");
		exit(0);
	}
	else if(pid==0){
		printf("Child %d created. PID:%d | Parent PID:%d\n",i,getpid(),getppid());
		exit(0);
	}
	else{
		continue;
	}
	}
	sleep(10);
	printf("Parent Process PID:%d Finished creating %d child process.\n",getpid(),n);
}
