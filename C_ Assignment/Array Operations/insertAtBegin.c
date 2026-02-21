#include<stdio.h>
int main(){
	int arr[100],n,i,value;
	printf("Enter no elements:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter value ot insert at begin:");
	scanf("%d",&value);
	for(i=n;i>0;i--){
		arr[i]=arr[i-1];
	}
	arr[0]=value;
	n++;
	printf("After inserting the value at begining:");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
