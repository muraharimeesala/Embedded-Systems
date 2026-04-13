#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
void *threadFunc(void *arg){
	time_t currTime,newTime;
	struct tm *time_info;
	char dateBuff[100];
	char timeBuff[100];
	time(&currTime);
	time_info=localtime(&currTime);
	printf("ThreadFunc: Date and Time thread started..\n");
	strftime(dateBuff,sizeof(dateBuff),"%A,%B %d,%Y",time_info);
	strftime(timeBuff,sizeof(timeBuff),"%H:%M:%S",time_info);
	printf("ThreadFunc: Current date:%s\n",dateBuff);
	printf("ThreadFunc: Current time:%s\n",timeBuff);
	sleep(1);
	time(&newTime);
	double elasped=difftime(newTime,currTime);
	printf("ThreadFunc: After %.0f seconds:\n",elasped);
	time_info=localtime(&newTime);
	strftime(timeBuff,sizeof(timeBuff),"%H:%M:%S",time_info);
	printf("ThreadFunc: Updated time:%s\n",timeBuff);
}
int main(){
	pthread_t tid;
	time_t mainTime;
	struct tm *main_time_info;
	char mainTimeBuff[100];
	time(&mainTime);
	main_time_info=localtime(&mainTime);
	strftime(mainTimeBuff,sizeof(mainTimeBuff),"%H:%M:%S",main_time_info);
	printf("Main: Program started at %s\n",mainTimeBuff);
	printf("Main: Create thread to display time..\n");
	if(pthread_create(&tid,NULL,threadFunc,NULL)==-1){
		perror("pthread_create");
		exit(1);
	}
	printf("Main: Thread created continue program execution..\n");
	if(pthread_join(tid,NULL)==-1){
		perror("pthread_join");
		exit(1);
	}
	printf("Main: Thread date and time execution completed\n");
	printf("Main: Exiting program\n");

}
