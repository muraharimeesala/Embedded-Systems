#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
void signal_handler(int sig){
	printf("Caught signal %d(SIGINT) cleaning up...\n",sig);
	exit(0);
}
int main(){
	signal(SIGINT,signal_handler);
	while(1){
		printf("Running... press ctrl+c to stop\n");
		sleep(2);
	}
}
