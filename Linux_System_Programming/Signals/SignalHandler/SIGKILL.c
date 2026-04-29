#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void My_Handler(int signo){
	printf("Current Process ID:%d\n",getpid());
	kill(getpid(),SIGKILL);
}
int main(){
	struct sigaction sa;
	sa.sa_handler=My_Handler;
	sa.sa_flags=0;
	sigemptyset(&sa.sa_mask);
	if(sigaction(SIGINT,&sa,NULL)==-1){
		printf("Sigaction\n");
		return 1;
	}
	printf("Press the Ctrl+C kill the process by SIGKILL.\n");
	while(1){
		printf("Running...\n");
		sleep(2);
	}
}
