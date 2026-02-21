#include<stdio.h>
int main(){
	int arr[100],n,i,key,high,low,mid,result=-1;
	printf("Enter a array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter value to search:");
	scanf("%d",&key);
	low=0;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==key){
			result=mid;    // store index
			low=mid+1;    //Move to left side to find last occurrence
		}
		else if(arr[mid]>key){
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	if(result!=-1){
		printf("Last occurrence of %d is found at %d index.\n",key,result);
	}
	else{
		printf("%d is not found in the array.\n",key);
	}
}
