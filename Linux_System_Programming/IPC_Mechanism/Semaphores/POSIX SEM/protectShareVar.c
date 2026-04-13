#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int shared=0;
sem_t sem;
void *increment(void *arg){
	sem_wait(&sem);
	shared++;
	printf("Shared:%d\n",shared);
	sem_post(&sem);
}
int main(){
	pthread_t t1,t2;
	sem_init(&sem,0,1);
	pthread_create(&t1,NULL,increment,NULL);
	pthread_create(&t2,NULL,increment,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	sem_destroy(&sem);
}
