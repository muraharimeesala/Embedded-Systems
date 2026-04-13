<<<<<<< HEAD:LSP/Threads/POSIX Threads/sumOfTwoMutex.c
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
=======
//.Write a C program to create a thread that performs addition of two numbers with mutex locks? 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;   // global mutex
int shared = 0;

void* thread_func(void* arg) {
    int num1 = 10;
    int num2 = 20;
    printf("Thread: Trying to lock...\n");
    pthread_mutex_lock(&lock);      // Acquire lock
    printf("Thread: Locked\n");
    shared = num1 + num2;
    printf("Thread: shared = %d\n", shared);
    sleep(5);   // Hold lock for demonstration
    printf("Thread: Unlocking...\n");
    pthread_mutex_unlock(&lock);    // Release lock
    return NULL;
}

int main() {
    pthread_t t1;
    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("pthread_mutex_init");
        exit(EXIT_FAILURE);
    }
    printf("Main: Creating threads...\n");
    pthread_create(&t1, NULL, thread_func, NULL);
    pthread_join(t1, NULL);
    printf("Main: Final value of shared = %d\n", shared);
    // Destroy mutex
    pthread_mutex_destroy(&lock);
    return 0;
>>>>>>> bac719f (Add embedded systems programs):Linux System Programming/Threads/POSIX Threads/sumOfTwoMutex.c
}
