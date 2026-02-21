#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void my_handler(int signo){
	printf("Received a signal %d(SIGINT) You pressed Ctrl+c\n",signo);
}
int main(){
	struct sigaction sa;
	sa.sa_handler=my_handler;          // Set handler
	sa.sa_flags=0;                     // Default flags
	// Register the signal handler
	if(sigaction(SIGINT,&sa,NULL)==-1){
		printf("Sigaction.\n");
		return 1;
	}
	printf("Press the ctrl+c for trigger SIGINT (press the ctrl+z to stop)\n");
	// Infinite loop to keep program running
	while(1){
		printf("Running\n");
		sleep(2);
	}
}

