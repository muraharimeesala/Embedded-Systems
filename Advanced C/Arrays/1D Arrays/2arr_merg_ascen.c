#include<stdio.h>
int main(){
	int arr1[100],arr2[100],merg[100];
	int i,j,n1,n2,temp;
	printf("Enter first array size:");
	scanf("%d",&n1);
	printf("Enter %d elements:\n",n1);
	for(i=0;i<n1;i++){
		scanf("%d",&arr1[i]);
	}
	printf("Enter second array size:");
	scanf("%d",&n2);
	printf("Enter %d elements:\n",n1);
	for(i=0;i<n2;i++){
		scanf("%d",&arr2[i]);
	}
	for(i=0;i<n1;i++){
		merg[i]=arr1[i];
	}
	for(j=0;j<n2;j++){
		merg[i+j]=arr2[j];
	}
	int total=n1+n2;
	for(i=0;i<total-1;i++){
		for(j=0;j<total-i-1;j++){
			if(merg[j]>merg[j+1]){
				temp=merg[j];
				merg[j]=merg[j+1];
				merg[j+1]=temp;
			}
		}
	}
	printf("After concatenated and sorting the array ascending:\n");
	for(i=0;i<total;i++){
		printf("%d ",merg[i]);
	}
}

