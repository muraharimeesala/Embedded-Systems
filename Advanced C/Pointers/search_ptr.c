#include<stdio.h>
int main(){
	int arr[100],n,i,key,found=0;
	printf("Enter array size:");
	scanf("%d",&n);
	int *ptr=arr;
	printf("Enter %d elemenst:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter element to search:");
	scanf("%d",&key);
	for(i=0;i<n;i++){
		if(*(ptr+i)==key){
			printf("%d element is found at index %d\n",key,i);
			found=1;
			break;
		}
	}
	if(!found){
		printf("%d element is not found in the array.\n",key);
	}
}
