#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
int count=0;
pthread_mutex_t lock;
void *thread_func(void *arg){
        char *msg=(char*)arg;
	for(int i=0;i<100000;i++){
		pthread_mutex_lock(&lock);
		count++;
		pthread_mutex_unlock(&lock);
	}
        printf("Thread ID:%lu---->%s",pthread_self(),msg);

}
int main(){
        int n,i;
        printf("Enter no of threads:");
        scanf("%d",&n);
        getchar();
        pthread_t tid[n];
	pthread_mutex_init(&lock,NULL);
        char msg[n][1024];
        for(i=0;i<n;i++){
                printf("Enter message for '%d' thread:\n",i+1);
                fgets(msg[i],sizeof(msg[i]),stdin);
        }
        for(i=0;i<n;i++){
                pthread_create(&tid[i],NULL,thread_func,msg[i]);
        }
        for(i=0;i<n;i++){
                pthread_join(tid[i],NULL);
        }
        printf("Final count:%d\n",count);
}

