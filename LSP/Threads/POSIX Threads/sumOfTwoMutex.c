#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
pthread_mutex_t sumMutex=PTHREAD_MUTEX_INITIALIZER;
int a,b,sum=0,i;
void *threadFunc(void *arg){
	int threadID=*(int*)arg;
	pthread_mutex_lock(&sumMutex);
	printf("ThreadFunc: Thread %d Received\n",threadID);
	printf("ThreadFunc: Thread %d addition is started...\n",threadID);
	sleep(2);
	sum=a+b;
	sleep(2);
	printf("ThreadFunc: Thread %d Calculation compelted\n",threadID);
	sleep(2);
	printf("ThreadFunc: %d Thread Sum: %d+%d=%d\n",threadID,a,b,sum);
	pthread_mutex_unlock(&sumMutex);
	return NULL;
}
int main(){
	int n;
	printf("Enter two values:\n");
	scanf("%d %d",&a,&b);
	printf("Enter no of threads:");
	scanf("%d",&n);
	pthread_t tid[n];
	int threadID[n];
	printf("Main: Input values:%d,%d\n",a,b);
	printf("Main: Creating %d threads to perform addition operation...\n",n);
	for(int i=0;i<n;i++){
		threadID[i]=i+1;
		if(pthread_create(&tid[i],NULL,threadFunc,&threadID[i])==-1){
			perror("pthread_create");
			exit(1);
		}
	}
	printf("Main: %d Threads created continue with execution..\n",n);
	for(int i=0;i<n;i++){
		if(pthread_join(tid[i],NULL)==-1){
			perror("pthread_join");
			exit(1);
		}

	}
	if(pthread_mutex_destroy(&sumMutex)==-1){
		perror("pthread_mutex_destroy");
		exit(1);
	}
	printf("Main: Threads execution completed\n");
	printf("Main: Exiting program\n");
	return 0;
}
