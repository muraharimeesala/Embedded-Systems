#include<stdio.h>
int main(){
	int arr[100],n,i,result;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Square of array elements:\n");
	for(i=0;i<n;i++){
		result=arr[i]*arr[i];
	printf("%d^2 = %d\n",arr[i],result);
	}
}

