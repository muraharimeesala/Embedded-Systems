#include<stdio.h>
int main(){
	int arr[100],n,sum=0,i,result;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Sum of average of array: ");
	for(i=0;i<n;i++){
		sum=sum+arr[i];
	}
	result=sum/2;
	printf("%d\n",result);
}
