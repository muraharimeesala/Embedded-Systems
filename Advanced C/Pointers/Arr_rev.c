#include<stdio.h>
int arrRev(int *arr,int n){
	int *start=arr;
	int *end=arr+n-1;
	int temp;
	while(start<end){
		temp=*start;
		*start=*end;
		*end=temp;
	start++;
	end--;
	}
}
int main(){
	int arr[100],i,n;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	arrRev(arr,n);
	printf("Reverse of array:\n");
	for(i=0;i<n;i++){
        printf("%d ",arr[i]);
	}
}


