#include<stdio.h>
int main(){
	int arr[100],n,i,k,j,temp;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter positions to left rotation:");
	scanf("%d",&k);
	k=k%n;
	for(j=0;j<k;j++){
		temp=arr[n-1];
		for(i=n-1;i>0;i--)
		arr[i]=arr[i-1];
		arr[0]=temp;
	}
	printf("After left rotation of %d positions:",k);
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}

