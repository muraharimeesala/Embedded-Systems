#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
void *threadFun(void *arg){
	char *ptr;
	ptr=(char*)arg;
	printf("%s",ptr);
	int *len=malloc(sizeof(int));
	*len=strlen(ptr);
	return len;
}
int main(){
	pthread_t ti;
	pthread_create(&ti,NULL,threadFun,"Hello World!!");
	void *ret;
	pthread_join(ti,&ret);
	printf("Thread 1 exit code:%d\n",*(int*)ret);
}
