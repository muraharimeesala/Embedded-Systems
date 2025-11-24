#include<stdio.h>
#include<pthread.h>
#include<string.h>
void *threadfun(void *arg){
	char *ptr;
	ptr=(char*)arg;
	printf("%s\n",ptr);
	return (void*)(long)strlen(ptr);
}
int main(){
	pthread_t t1;
	void *ret;
	pthread_create(&t1,NULL,threadfun,"Hello");
	pthread_join(t1,&ret);
	printf("Thread 1 exit code:%ld\n",(long)ret);
}
