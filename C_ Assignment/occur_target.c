//given a sorted array and a target value  write a program to find no of times occurrences of the target value

#include<stdio.h>
int firstOccurr(int arr[],int n,int target){
	int low=0,high=n-1,result=-1;
	while(low<=high){
	int mid=(low+high)/2;
	if(arr[mid]==target){
		result=mid;
		high=mid-1;
	}
	else if(arr[mid]>target){
			high=mid-1;
	}
	else
	low=mid+1;
	}
	return result;
}
int lastOccurr(int arr[],int n,int target){	
	int low=0,high=n-1,result=-1;
	while(low<=high){
	int mid=(low+high)/2;
	if(arr[mid]==target){
		result=mid;
		low=mid+1;
	}
	else if(arr[mid]>target){
			high=mid-1;
	}
	else
	low=mid+1;
	}
	return result;
}
int main(){
	int n,arr[100],target,i;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter a targeted value:");
	scanf("%d",&target);
	int first=firstOccurr(arr,n,target);
	int last=lastOccurr(arr,n,target);
	if(first==-1){
		printf("%d value not found in the array.\n",target);
	}
	else{
		printf("%d value occurs %d times in the array.\n",target,last-first+1);
	}
}
