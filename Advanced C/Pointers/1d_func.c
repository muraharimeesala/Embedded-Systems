#include<stdio.h>
int printfArr(int arr[],int n){
	int i;
	printf("Printing 1D array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
int main(){
	int arr[100],n,i;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printfArr(arr,n);
}

