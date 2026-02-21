#include<stdio.h>
int main(){
	int arr[100],n,i,j,minIndx,temp;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	// find min element index
	for(i=0;i<n;i++){
		minIndx=i;
		for(j=i+1;j<n;j++){
			if(arr[j]>arr[minIndx]){
				minIndx=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[minIndx];
		arr[minIndx]=temp;
	}
	printf("After descending array:\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}
