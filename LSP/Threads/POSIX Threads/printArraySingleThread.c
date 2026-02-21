#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define MAX 100
int arr[MAX];
int n;
void *threadFunc(void *arg){
	for(int i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
	return NULL;
}
int main(){
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	pthread_t t1;
	pthread_create(&t1,NULL,&threadFunc,NULL);
	pthread_join(t1,NULL);
}
