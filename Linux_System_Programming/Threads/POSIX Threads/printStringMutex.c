#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_mutex_t printMutex=PTHREAD_MUTEX_INITIALIZER;
char msg[100];
void *threadFunc(void *arg){
	int thread_id=*(int*)arg;
	pthread_mutex_lock(&printMutex);
	printf("ThreadFunc: Thread %d: %s",thread_id,msg);
	sleep(1);
	printf("ThreadFunc: Thread %d synchronization output completed\n",thread_id);
	pthread_mutex_unlock(&printMutex);
	return NULL;
}
int main(){
	int n;
	printf("Enter no of threads:");
	scanf("%d",&n);
	getchar();
	printf("Enter message for print:\n");
	fgets(msg,sizeof(msg),stdin);
	pthread_t id[n];
	int threads[n];
	printf("Main: Creating thread to print output....\n");
	for(int i=0;i<n;i++){
		threads[i]=i+1;
		if(pthread_create(&id[i],NULL,threadFunc,&threads[i])==-1){
			perror("pthread_create");
			exit(1);
		}
	}
	for(int i=0;i<n;i++){
		if(pthread_join(id[i],NULL)==-1){
			perror("pthread_join");
			exit(1);
		}
	}
	printf("Main: Destroying Mutex...\n");
	pthread_mutex_destroy(&printMutex);
	printf("Main: All threads completed successfully\n");
	return 0;
}

