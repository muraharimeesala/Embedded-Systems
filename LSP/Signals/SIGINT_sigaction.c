#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void my_handler(int signo){
	printf("Received a signal:%d\n",signo);
}
int main(){
	struct sigaction sa;
	sa.sa_handler=my_handler;
	sa.sa_flags=0;
	sigemptyset(&sa.sa_mask);
	sigaction(2,&sa,NULL);
	while(1){
		printf("Running...\n");
		sleep(1);
	}
}
