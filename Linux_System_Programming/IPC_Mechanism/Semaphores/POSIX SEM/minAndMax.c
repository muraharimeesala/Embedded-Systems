#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 10
int arr[SIZE];
int Min,Max;
void* findMin(void* arg){
    Min=arr[0];
    for(int i=1;i<SIZE;i++){
	    if(arr[i]<Min){
		    Min=arr[i];
	    }
    }
    return NULL;
}
void* findMax(void* arg){
    Max=arr[0];
    for(int i=1;i<SIZE;i++){
            if(arr[i]>Max){
                    Max=arr[i];
            }
    }
    return NULL;
}
int main(){
	pthread_t t1,t2;
	printf("Enter %d Values:\n",SIZE);
	for(int i=0;i<SIZE;i++){
		scanf("%d",&arr[i]);
	}
	pthread_create(&t1,NULL,findMin,NULL);
	pthread_create(&t2,NULL,findMax,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Minimum Value:%d\n",Min);
	printf("Maximum Value:%d\n",Max);
}
