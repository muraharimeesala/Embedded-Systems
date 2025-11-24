#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void My_Handler(int signo){
	printf("Received a signal %d (SIGINT),(Press the Ctrl+C)\n",signo);
}
int main(){
	struct sigaction sa;
	sa.sa_handler=SIG_IGN;
	sa.sa_flags=0;
	if(sigaction(SIGINT,&sa,NULL)==-1){
		printf("Sigaction\n");
		return 1;
	}
	printf("Current process ID:%d\n",getpid());
	printf("Press the Ctrl+Z to stop or kill the process manually.\n");
	while(1){
		printf("Running...\n");
		sleep(2);
	}
}
