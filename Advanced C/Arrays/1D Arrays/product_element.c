#include<stdio.h>
int main(){
	int arr[100],n,i,product=1;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Product of all elements: ")
	for(i=0;i<n;i++){
		product=product*arr[i];
	}
	printf("%d\n",product);
}
