#include<stdio.h>
int main(){
        int arr[100],n,i,value;
        printf("Enter no elements:");
        scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
	for(i=0;i<n;i++){
		arr[i]=arr[i+1];
	}
	n--;
	printf("Updated array:\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
	printf("\n");
}
