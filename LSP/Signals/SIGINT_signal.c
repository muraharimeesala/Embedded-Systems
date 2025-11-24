#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void my_handler(int signo){
	printf("Caught Signal '%d' Press Ctrl+Z to stop.\n",signo);
}
int main(){
	signal(2,my_handler);
	while(1){
		printf("Waiting...\n");
		sleep(1);
	}
}
