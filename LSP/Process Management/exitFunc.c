#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid==0){
		printf("Child process\n");
		exit(0);
		printf("Child finished\n");
	}
	else{
		printf("Parent process\n");
	}
	return 0;
}

