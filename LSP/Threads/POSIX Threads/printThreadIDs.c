#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void *threadFunc(void *arg){
	 int thread_id=*(int*)arg;
	 printf("=====GET THREAD INFO=====\n");
	 printf("ThreadFunc: Thread %d Received:",thread_id);
	 printf("ThreadFunc: Thread ID:%lu\n",pthread_self());
	 pthread_exit(NULL);
}
int main(){
	pthread_t ti[2];
	int thread_id[2];
	printf("Main: Creating two threads...\n");
	for(int i=0;i<2;i++){
		thread_id[i]=i+1;
		if(pthread_create(&ti[i],NULL,threadFunc,&thread_id[i])==-1){
			perror("pthread_error");
			exit(1);
		}
	}
	printf("Main: Two threads are created continuing main execution\n");
	for(int i=0;i<2;i++){
		if(pthread_join(ti[i],NULL)==-1){
			perror("pthread_join");
			exit(1);
		}
	}
	printf("Main: Execution completed\n");
	printf("Main: Exiting program..\n");
	return 0;
}
