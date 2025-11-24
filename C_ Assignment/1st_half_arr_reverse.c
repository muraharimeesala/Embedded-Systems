#include<stdio.h>
int main(){
	int n,arr[100],temp,i;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int half=n/2;
	for(i=0;i<half/2;i++){
		temp=arr[i];
		arr[i]=arr[half-1-i];
		arr[half-1-i]=temp;
	}
	printf("After revesring the half array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
