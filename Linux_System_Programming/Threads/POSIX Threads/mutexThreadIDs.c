#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_mutex_t printMutex=PTHREAD_MUTEX_INITIALIZER;
void *threadFunc(void *arg){
	int threadID=*(int*)arg;
	pthread_mutex_lock(&printMutex);
	sleep(2);
	printf("ThreadFunc: Thread %d Received Thread ID:%lu\n",threadID,pthread_self());
	sleep(2);
	pthread_mutex_unlock(&printMutex);
	return NULL;
}
int main(){
	int n,i;
	printf("Enter no of threads:");
	scanf("%d",&n);
	pthread_t tid[n];
	int threadID[n];
	printf("Main: Creating %d hreads for printing Thread IDs...\n",n);
	for(i=0;i<n;i++){
		threadID[i]=i+1;
		if(pthread_create(&tid[i],NULL,threadFunc,&threadID[i])==-1){
			perror("pthread_create");
			exit(1);
		}
	}
	sleep(2);
	printf("Main: Threads created continuing program execution..\n");
	for(i=0;i<n;i++){
		if(pthread_join(tid[i],NULL)==-1){
			perror("pthread_join");
			exit(1);
		}
	}
	if(pthread_mutex_destroy(&printMutex)==-1){
		perror("pthread_mutex_destroy");
		exit(1);
	}
	printf("Main: Thread execution completed\n");
	printf("Main: exiting program\n");
}
