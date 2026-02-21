#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define MAX 100
int n;
int arr[MAX];
void *threadFunc(void *arg){
	int index=*(int*)arg;
	printf("Thread :%ld-> arr[%d]=%d\n",pthread_self(),index,arr[index]);
	return NULL;
}
int main(){
	printf("Enter size of array:");
	scanf("%d",&n);
	pthread_t t[n];
	int index[n];
	printf("Enter %d elements:\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		index[i]=i;
		pthread_create(&t[i],NULL,&threadFunc,&index[i]);
	}
	for(int i=0;i<n;i++){
		pthread_join(t[i],NULL);
	}
}
