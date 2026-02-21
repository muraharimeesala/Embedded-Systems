#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *printString(void *arg){
	char *str=(void*)arg;
	printf("ThreadFunc: Recevied string..\n");
	printf("ThreadFunc: Executing String..\n");
	sleep(2);
	printf("ThreadFunc: String is:%s\n",str);
	pthread_exit(NULL);
}
int main(){
	pthread_t tid;
	char str[100]="Hello World!!";
	printf("Main: Input string:\n");
	printf("Main: String is:%s\n",str);
	sleep(2);
	printf("Main: Creating a thread for printing string..\n");
	if(pthread_create(&tid,NULL,&printString,&str)==-1){
		perror("pthread_create");
		exit(1);
	}
	printf("Main: Thread created continuing main execution..\n");
	sleep(2);
	if(pthread_join(tid,NULL)==-1){
		perror("pthread_join");
		exit(1);
	}
	printf("Main: Printing string completed\n");
	printf("Main: Exiting program\n");
	return 0;
}
