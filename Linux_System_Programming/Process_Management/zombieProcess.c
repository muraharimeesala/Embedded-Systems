#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("Child Exiting..\n");
		exit(0);
	}
	else {
		printf("Parent Sleeping..\n");
		sleep(5);
	}
}
