#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void my_handler(int signo,siginfo_t *info,void *context){
	printf("Received sig no:%d SIGINT from PID:%d UID:%d\n",signo,info->si_pid,info->si_uid);
}
int main(){
	struct sigaction sa;
	sa.sa_sigaction=my_handler;
	sa.sa_flags=SA_SIGINFO;
	
	if(sigaction(SIGINT,&sa,NULL)==-1){
		printf("Sigaction.\n");
		return 1;
	}
	printf("Press ctrl+c to trigger SIGINT (Advcanced handler)\n");
	while(1){
		printf("Waiting...\n");
		sleep(2);
	}
}
