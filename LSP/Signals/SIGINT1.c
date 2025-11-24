#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void my_handler(int signo){
	printf("My handler is:%d\n",signo);
}
int main(){
	struct sigaction act;
	act.sa_handler=my_handler;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	sigaction(SIGINT,&act,NULL);
	while(1){
		sleep(2);
	}
}
