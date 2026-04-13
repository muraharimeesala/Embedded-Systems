#include<stdio.h>
#include<pthread.h>
#include<string.h>
void *threadFun(void *arg){
	int n,i;
	char msg[n][1024];
	for(i=0;i<n;i++){
		printf("Enter Message of %d thread:\n",n);
		fgets(msg[i],sizeof(msg[i]),stdin);
	}
}
int main(){
    int n,i;
    printf("Enter no of thread:");
    scanf("%d",&n);
    getchar();
    pthread_t tid[n];
    char msg[n][1024];
    for(i=0;i<n;i++){
        pthread_create(&tid[i],NULL,threadFun,msg[i]);
    }
    for(i=0;i<n;i++){
        pthread_join(tid[i],NULL);
    }
    printf("Main Thread Existing.\n");
}	
