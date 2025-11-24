#include<stdio.h>
/*
int main(){
	int num,i;
	printf("Enter elements of array:");
	scanf("%d",&num);
	int arr[num];
	for(i=0;i<num;i++){
		printf("Element-%d:",i);
		scanf("%d",&arr[i]);
	}
	int max=arr[0];
	for(int i=0;i<num;i++){
		if(arr[i]>max){
			max=arr[i];
		}
	}
	printf("The largest element of array is:%d",max);
}
*/
int main(){
	int num,i;
	printf("Enter elements of array:");
	scanf("%d",&num);
	int arr[num];
	for(i=0;i<num;i++){
		printf("Element-%d:",i);
		scanf("%d",&arr[i]);
	}
	int min=arr[0];
	for(int i=0;i<num;i++){
		if(arr[i]<min){
			min=arr[i];
		}
	}
	printf("The smallest element of array is:%d",min);
}
	
