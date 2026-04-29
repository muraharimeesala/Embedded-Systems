#include<stdio.h>
#include<semaphore.h>
sem_t sem;
int main(){
	sem_init(&sem,0,1);
	sem_wait(&sem);
	printf("Your in ctitical sections.\n");
	sem_post(&sem);
	printf("Your exited ctritical section.\n");
	sem_destroy(&sem);
}

