#include<stdio.h>
#include<semaphore.h>
int main(){
	sem_t sem;
	if(sem_init(&sem,0,1)!=0){
		printf("sem_init failed.\n");
	}
	printf("semaphore initialized.\n");
	sem_destroy(&sem);
	printf("semaphore destroyed.\n");
}

