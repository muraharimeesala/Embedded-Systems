#include<stdio.h>
int main(){
	int num,i;
	printf("Enter number of elements:");
	scanf("%d",&num);
	int arr[num];
	for(i=0;i<num;i++){
	printf("Element-%d:",i);
	scanf("%d",&arr[i]);
	}
        printf("The elements of array is:\n");
	for(i=0;i<num;i++){
	printf("%d\n",arr[i]);
	}
}


