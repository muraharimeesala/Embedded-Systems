#include<stdio.h>
#include<pthread.h>
#include<string.h>
void *threadFun(void *arg){
	char *msg=(char*)arg;          // Convert void* to char*
	pthread_t tid=pthread_self();          // Get current thread ID
	printf("Thread ID:%lu - Messages:%s\n",(unsigned long)tid,msg);
	return NULL;
}
int main(){
	int n,i;
	printf("Enter no of threads:");
	scanf("%d",&n);
	getchar();
	pthread_t t[n];
	char messages[n][100];           // Store messages for each thread
	for(i=0;i<n;i++){
	printf("Enter message for %d thread:",i+1);
	fgets(messages[i],sizeof(messages[i]),stdin);
	messages[i][strcspn(messages[i],"\n")]='\0';
	}
	for(i=0;i<n;i++){
		pthread_create(&t[i],NULL,threadFun,(void*)messages[i]);
	}
	// Wait for all threads to finish
	for(i=0;i<n;i++){
		pthread_join(t[i],NULL);
	}
	printf("Main thread ID:%lu\n",(unsigned long)pthread_self());
	printf("All threads are finished.\n");
}
