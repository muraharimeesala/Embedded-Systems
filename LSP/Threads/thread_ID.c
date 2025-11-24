#include<stdio.h>
#include<pthread.h>
#include<string.h>
void *threadFun(void *arg){
	int id=*(int*)arg;          // Get thread number
	pthread_t tid=pthread_self();          // Get current thread ID
	printf("Thread %d: Thread ID:%lu\n",id,(unsigned long)tid);
	return NULL;
}
int main(){
	int n,i;
	printf("Enter no of threads:");
	scanf("%d",&n);
	pthread_t t[n];
	int ids[n];                 // IDs for each thread
	for(i=0;i<n;i++){
		ids[i]=i+1;
		if(pthread_create(&t[i],NULL,threadFun,&ids[i])!=0){
			printf("Failed to crete thread.\n");
		}
	}
	// Wait for all threads to finish
	for(i=0;i<n;i++){
		pthread_join(t[i],NULL);
	}
	printf("Main thread ID:%lu\n",(unsigned long)pthread_self());
	printf("All threads are finished.\n");
}
