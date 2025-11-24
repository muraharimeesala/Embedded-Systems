#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void my_handler(int signo){
	printf("First caught Ctrl+C,Now default action\n");
	signal(SIGINT,SIG_DFL);
}
int main(){
	signal(SIGINT,my_handler);
	while(1){
		printf("Running...\n");
		sleep(1);
	}
}
