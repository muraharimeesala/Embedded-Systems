#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	char buff[1024];
	int pid;
	while(1){
		printf("My Shell> ");
		fflush(stdout);
		if(fgets(buff,1024,stdin)==NULL){
			exit(0);
		}
		buff[strcspn(buff,"\n")]='0';

		if(strcmp(buff,"exit")==0){
			printf("Exiting...\n");
			exit(0);
		}
		if(strcmp(buff,"Viven")==0){
			printf("Welcome to my shell\n");
			continue;
		}
		pid = fork();
		if(pid < 0){
			printf("Error in forking\n");
			exit(0);
		}
		if(pid == 0) {
    			char *args[] = {buff, NULL};
			perror("execvp failed");   // VERY IMPORTANT
    		
		}
		else{
			waitpid(pid,NULL,0);
		}


	}
}





