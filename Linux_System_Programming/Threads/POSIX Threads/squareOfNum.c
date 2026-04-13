#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *threadFunc(void *arg){
	int num=*(int*)arg;
	int square=num*num;
	printf("ThreadFunc: SQUARE CALCULATING THREAD\n");
	printf("ThreadFunc: Received %d number\n",num);
	printf("ThreadFunc: Caclulating square of %d number....\n",num);
	sleep(2);
	printf("ThreadFunc: Square of %d number: %d*%d=%d\n",num,num,num,square);
	return NULL;
}
int main(){
	pthread_t tid;
	int num;
	printf("Enter number:");
	scanf("%d",&num);
	printf("Main: Input number=%d\n",num);
	printf("Main: Creating thread for calculating square of number..\n");
	sleep(2);
	if(pthread_create(&tid,NULL,threadFunc,&num)==-1){
		perror("pthread_create");
		exit(1);
	}
	printf("Main: Thread created continue program execution..\n");
	if(pthread_join(tid,NULL)==-1){
		perror("pthread_join");
		exit(1);
	}
	printf("Main: Thread execution completed\n");
	printf("Main: Exiting program\n");
	return 0;
}
