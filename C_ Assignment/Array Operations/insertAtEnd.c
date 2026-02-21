#include<stdio.h>
int main(){
	int arr[100],n,i,value;
	printf("Enter no elements:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter value to insert at end:");
	scanf("%d",&value);
	arr[n]=value;
	n++;
	printf("After inserting the element at ending:\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}
