#include<stdio.h>
int main(){
	int n,arr[100],i,maxSum,currSum;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d values:\n",n);
	for(i=0;i<n-1;i++){
		scanf("%d ",&arr[i]);
	}
	maxSum=arr[0]+arr[i+1];
	for(i=0;i<n-1;i++){
		currSum=arr[i]+arr[i+1];
		if(currSum>maxSum){
			maxSum=currSum;
		}
	}
	printf("Adjcent values highest sum:%d\n",maxSum);
}
