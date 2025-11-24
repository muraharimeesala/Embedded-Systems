#include<stdio.h>
#include<pthread.h>
void *threadFun(void *arg){
	printf("Hello from Thread!! arg=%d\n",*(int*)arg);
	return NULL;
}
int main(){
	pthread_t tid;
	int val=10;
	pthread_create(&tid,NULL,threadFun,&val);
	pthread_join(tid,NULL);
}

