#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t s1,s2;
int i;
void *t1(void *arg){
	for(i=1;i<10;i++){
		sem_wait(&s1);
		printf("Thread A\n");
		sem_post(&s2);
	}
	return NULL;
}
void *t2(void *arg){
        for(i=1;i<10;i++){
                sem_wait(&s2);
                printf("Thread B\n");
                sem_post(&s1);
        }
        return NULL;
}
int main(){
	pthread_t a,b;
	sem_init(&s1,0,1);
	sem_init(&s2,0,0);
	pthread_create(&a,NULL,t1,NULL);
	pthread_create(&b,NULL,t2,NULL);
	pthread_join(a,NULL);
	pthread_join(b,NULL);
	sem_destroy(&s1);
	sem_destroy(&s2);
}
