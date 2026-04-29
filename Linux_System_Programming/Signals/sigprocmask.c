#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void my_handler(int signo){
	printf("Im inside the handler.\n");
	sleep(5);
}
int main(){
	sigset_t msk;                        // Mask for signals
	signal(SIGINT,my_handler);           //Registering the handler
	sigemptyset(&msk);                  //Clearing the mask
	sigaddset(&msk,SIGINT);            //Adding Signal to the mask
	sigprocmask(SIG_BLOCK,&msk,NULL);   //Blocking Signal
	printf("Signal is blocked for 10 seconds, Try pressing ctrl+c....\n");
	sleep(5);
	printf("Unblocking SIGINT now ,Press ctrl+c again.\n");
	sigprocmask(SIG_UNBLOCK,&msk,NULL);
	while(1){
		sleep(2);
	}
}
