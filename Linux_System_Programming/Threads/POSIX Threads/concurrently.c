#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *threadFunc(void *arg){
	int thread_id=*(int*)arg;
	printf("ThreadFunc: Thread %d starting...\n",thread_id);
	sleep(2);
	printf("ThreadFunc: Thread %d will print 1-10 numbers\n",thread_id);
	for(int i=1;i<=10;i++){
		printf("ThreadFunc: Thread %d: Number %d\n",thread_id,i);
	}
	printf("ThreadFunc: Thread %d All numbers are printed..\n",thread_id);
	printf("ThreadFunc: Thread %d is completed\n",thread_id);
	pthread_exit(NULL);
}
int main(){
	pthread_t tid[2];
	int thread_id[2]={1,2};
	printf("Main: Concurrent number printing..\n");
	printf("Main: Starting two numbers..\n");
	printf("Main: Creating threads for printing concurrent numbers..\n");
	for(int i=0;i<2;i++){
		if(pthread_create(&tid[i],NULL,&threadFunc,&thread_id[i])==-1){
			perror("pthread_create");
			exit(1);
		}

	}
	printf("Main: Thread Created for printing concorrent numbers...\n");
	sleep(2);
	printf("Main: Waiting for thread to complete..\n");
	for(int i=0;i<2;i++){
		if(pthread_join(tid[i],NULL)==-1){
			perror("pthread_join");
			exit(1);
		}
	}
	printf("Main: Both the thread completed successfully\n");
	printf("Main: Exiting program\n");
	return 0;
}
