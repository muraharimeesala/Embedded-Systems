#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
void *thread_func(void *arg){
        char *msg=(char*)arg;
	printf("Thread Received Message:\n%s",msg);
        return NULL;
}
int main(){
        int n,i;
        printf("Enter no of threads:");
        scanf("%d",&n);
        getchar();
        pthread_t tid[n];
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
        printf("Main thread existing.\n");
}

