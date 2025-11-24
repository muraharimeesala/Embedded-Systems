#include<stdio.h>
int main(){
	int n,i,temp;
	printf("size of array: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Element-%d:",i);
		scanf("%d",&arr[i]);
	}
	int half=n/2;
	int *start=arr;
	int *end=arr+half-1;
	while(start<end){
		temp=*start;
		*start=*end;
		*end=temp;
		start++;
		end--;
	}
	printf("After reverse the first half\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}

