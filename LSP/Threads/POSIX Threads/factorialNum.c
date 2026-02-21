#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *threadFunc(void *arg){
	int num=*(int*)arg;
	int fact=1;
	printf("ThreadFunc: Recived %d number\n",num);
	for(int i=1;i<=num;i++){
		fact=fact*i;
	}
	printf("ThreadFunc: finding factorial of %d number..\n",num);
	sleep(2);
	printf("ThreadFunc: Factorial of %d number=%d\n",num,fact);
	pthread_exit(NULL);
}
int main(){
	int num;
	printf("Enter number:");
	scanf("%d",&num);
	pthread_t tid;
	printf("Main: Input number=%d\n",num);
	printf("Main: Creating thread for finding factorial of number\n");
	if(pthread_create(&tid,NULL,&threadFunc,&num)==-1){
		perror("pthread_create");
		exit(1);
	}
	printf("Main: Thread created continuing main execution...\n");
	sleep(2);
	if(pthread_join(tid,NULL)==-1){
		perror("pthread_join");
		exit(1);
	}
	printf("Main: Thread execution successfully\n");
	printf("Main: Exiting program\n");
	return 0;
}
