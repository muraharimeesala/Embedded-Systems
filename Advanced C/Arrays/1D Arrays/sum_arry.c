#include<stdio.h>
int main(){
	int num,i;
	printf("Enter elements of array:");
	scanf("%d",&num);
	int arr[num];
	for(int i=0;i<num;i++){
		printf("Element-%d:",i);
		scanf("%d",&arr[i]);
	}
	int sum=0;
	printf("The sum of array elements:\n");
	for(int i=0;i<num;i++){
		sum=sum+arr[i];
	}
	printf("%d\n",sum);
}
