#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
volatile sig_atomic_t sigint_count=0;
void sigint_handler(int signo){
	const char *msg1="Caught SIGINT (press again to exit)\n";
	const char *msg2="Caught SIGINT -again exiting.\n";
	sigint_count++;
	if(sigint_count==1){
		write(STDOUT_FILENO,msg1,strlen(msg1));
	}
	else{
		write(STDOUT_FILENO,msg2,strlen(msg2));
		exit(0);
	}
}
int main(){
	struct sigaction sa;
	sa.sa_handler=sigint_handler;
	sa.sa_flags=0;
	sigemptyset(&sa.sa_mask);
	if(sigaction(SIGINT,&sa,NULL)==-1){
		perror("sigction");
		exit(0);
	}
	printf("PID %d Running.. press Ctrl+C to send SIGINT.\n",getpid());
	for(;;){
		pause();
	}
}

