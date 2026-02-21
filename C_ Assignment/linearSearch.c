#include<stdio.h>
#include<stdlib.h>
int main(){
	int arr[100],n,i,found=0,value;
	printf("Enter a array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter value to search:");
	scanf("%d",&value);
	for(i=0;i<n;i++){
		if(arr[i]==value){
			found=1;
			break;
		}
	}
	printf("%d is found at %d index.\n",value,i);
}
