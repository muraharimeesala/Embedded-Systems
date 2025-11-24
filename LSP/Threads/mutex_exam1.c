#include<stdio.h>
#include<pthread.h>
int counter=0;
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void *increment(void *arg){
	for(int i=0;i<100000;i++){
		pthread_mutex_lock(&lock);
		counter++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
int main(){
	pthread_t t1,t2;
	if(pthread_create(&t1,NULL,increment,NULL)){
			printf("pthread_create");
			return 1;
	}
	if(pthread_create(&t2,NULL,increment,NULL)){
		printf("pthread_create");
		return 1;
	}
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_mutex_destroy(&lock);
	printf("Final counter is:%d\n",counter);
}
