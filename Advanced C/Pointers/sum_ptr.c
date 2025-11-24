#include<stdio.h>
int main(){
	int arr[100],n,i,sum=0;
	int *ptr=arr;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d element:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		sum+=*(ptr+i);
	}
	printf("Sum=%d\n",sum);
}
