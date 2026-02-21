#include<stdio.h>
int main(){
	int arr[100],n,i,j,temp;
	printf("Enter a array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("After asecnding the array:\n");
	for(i=0;i<n;i++){
		printf("%d\n",arr[i]);
	}
}
