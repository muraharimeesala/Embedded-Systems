#include<stdio.h>
int main(){
	int arr[100],n,i,sum=0,expectedSum,missing;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n-1);
	for(i=0;i<n-1;i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}
	expectedSum=n*(n+2)/2;
	missing=expectedSum-sum;
	printf("The missing value is: %d",missing);
}


