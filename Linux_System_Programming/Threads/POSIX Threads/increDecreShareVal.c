#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
pthread_mutex_t increMutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t decreMutex=PTHREAD_MUTEX_INITIALIZER;
int shared=0;
void *increThread(void *arg){
	int incre=*(int*)arg;
	for(int i=0;i<5;i++){
		pthread_mutex_lock(&increMutex);
		printf("IncreThread: Increment %d Thread started\n",incre);
		int before=shared;
		shared++;
		int after=shared;
		printf("IncreThread: Porgram is completed\n");
		sleep(2);
		printf("IncreThread: Final Output [%d]=%d->%d\n",shared,before,after);
		pthread_mutex_unlock(&increMutex);
	}
}
void *decreThread(void *arg){
	int decre=*(int*)arg;
	for(int i=0;i<5;i++){
		pthread_mutex_lock(&decreMutex);
		printf("DecreThread: Decrement %d Thread started\n",decre);
		int before=shared;
		shared--;
		int after=shared;
		printf("DecreThread: Porgram is completed\n");
		sleep(2);
		printf("DecreThread: Final Output [%d]=%d->%d\n",shared,before,after);
		pthread_mutex_unlock(&decreMutex);
	}
}
int main(){
	pthread_t incTid,decTid;
	int incre,decre;
	printf("Main: Increment Decrement Operations\n");
	printf("Main: Creating %d thread...\n",incre);
	pthread_create(&incTid,NULL,increThread,&shared);
	printf("Main: Thread %d is created continue program\n",incre);
	printf("Main: Creating %d thread...\n",decre);
	pthread_create(&decTid,NULL,decreThread,&shared);
	printf("Main: Thread %d is created continue program\n",decre);
	pthread_join(incTid,NULL);
	pthread_join(decTid,NULL);
	pthread_mutex_destroy(&increMutex);
	pthread_mutex_destroy(&decreMutex);

}



