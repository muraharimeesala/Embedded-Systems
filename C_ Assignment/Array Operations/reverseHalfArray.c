#include<stdio.h>
int main(){
	int arr[100],n,i,half;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d values:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	half=n/2;
	for(i=0;i<half/2;i++){
		int temp=arr[i];
		arr[i]=arr[half-1-i];
		arr[half-i-1]=temp;
	}
	printf("Updated Array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
