#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
void *threadFunc(void *arg){
	int num=*(int*)arg;
	int isPrime=1;
	printf("ThreadFunc: Received number:%d\n",num);
	if(num<=1){
		isPrime=0;
	}
	else{
		for(int i=2;i*i<=num;i++){
			if(num%i==0){
				isPrime=0;
				break;
			}
		}
	}
	if(isPrime){
		printf("%d is a prime number\n",num);
	}
	else{
		printf("%d is NOT a prime number\n",num);
	}
	return NULL;
}
int main(){
	int num;
	printf("Enter number:");
	scanf("%d",&num);
	pthread_t tid;
	if(pthread_create(&tid,NULL,threadFunc,&num)==-1){
		perror("pthread_create");
		exit(1);
	}
	if(pthread_join(tid,NULL)==-1){
		perror("pthread_join");
		exit(1);
	}
	return 0;

}
