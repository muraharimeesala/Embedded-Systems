#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#define MAX 10
sem_t sem_even;
sem_t sem_odd;
int num=1;
void *printEven(void *arg){
	while(num<=MAX){
		sem_wait(&sem_even);         // wait for even number
		if(num<=MAX){
			printf("Child Thread(Even):%d\n",num);
			num++;
		}
		sem_post(&sem_odd);
	}
	return NULL;
}
int main(){
	pthread_t child;
	sem_init(&sem_odd,0,1);
	sem_init(&sem_even,0,0);
	pthread_create(&child,NULL,&printEven,NULL);
	while(num<=MAX){
                sem_wait(&sem_odd);         // wait for even number
		if(num<=MAX){
			printf("Parent Thread(Odd):%d\n",num);
			num++;
		}
		sem_post(&sem_even);
	}
	pthread_join(child,NULL);
	sem_destroy(&sem_odd);
	sem_destroy(&sem_even);
}

