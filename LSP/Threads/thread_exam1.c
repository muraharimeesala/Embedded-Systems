#include<stdio.h>
#include<pthread.h>
#include<string.h>
int glob=0;
pthread_mutex_t lock;
void *threadfun1(void *arg);
void *threadfun2(void *arg);
int main(){
int loop=2000;
pthread_t t1,t2;
void *ret;
pthread_mutex_init(&lock, NULL);
pthread_create(&t1,NULL,threadfun1,&loop);
pthread_create(&t2,NULL,threadfun2,&loop);
pthread_join(t1,&ret);
pthread_join(t2,&ret);
printf("final value of global:%d\n",glob);
pthread_mutex_destroy(&lock);
}
void *threadfun1(void *arg){
int loop,i;
loop=*(int*)arg;
for(i=0;i<loop;i++){
pthread_mutex_lock(&lock);
glob++;
pthread_mutex_unlock(&lock);
}
printf("Thread 1:%d\n",glob);
}
void *threadfun2(void *arg){
int loop,i;
loop=*(int*)arg;
for(i=0;i<loop;i++){
pthread_mutex_lock(&lock);
glob++;
pthread_mutex_unlock(&lock);
}
printf("Thread 2:%d\n",glob);
}

