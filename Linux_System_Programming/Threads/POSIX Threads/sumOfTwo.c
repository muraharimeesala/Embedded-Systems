#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *sumOfTwo(void *arg){
	int *number=(int*)arg;
	int a=number[0];
	int b=number[1];
	int res=a+b;
	printf("Sum Calculator: Received two numbers:\n");
	printf("Sum Calculator: Number 1:%d\n",a);
	printf("Sum Calculator: Number 2:%d\n",b);
	sleep(2);
	printf("Sum Calculator: Calculating sum..\n");
	sleep(2);
	printf("Sum Calculator: %d + %d = %d\n",a,b,res);
	pthread_exit(NULL);
}
int main(){
	pthread_t tid;
	int number[2]={24,35};
	printf("Main: Input values:\n");
	printf("Main: Number 1:%d\n",number[0]);
	printf("Main: number 2:%d\n",number[1]);
	sleep(2);
	printf("Main: Creating a thread to calculate sum..\n");
	if(pthread_create(&tid,NULL,&sumOfTwo,&number)==-1){
		perror("pthread_create");
		exit(1);
	}
	printf("Main: Thread created continuing main execution..\n");
	sleep(2);
	if(pthread_join(tid,NULL)==-1){
		perror("pthread_join");
		exit(1);
	}
	printf("Main: Sum calculation completed\n");
	printf("Main: Exiting program\n");
	return 0;
}
