#include<stdio.h>
#include<pthread.h>
#include<string.h>
void *threadFun(int *arg){
	char *ptr;
	ptr=(char*)arg;
	printf("%s\n",ptr);
	return strlen(ptr);
}
int main(){
	pthread_t ti;
	pthread_create(&ti,NULL,threadFun,"Hello World!!");
	int ret;
	pthread_join(ti,&ret);
	printf("Thread 1 exit:%d\n",*(int*)ret);
}
