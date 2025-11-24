#include<stdio.h>
int main(){
	int n1,n2,a[100],b[100],merg[100];
	int i,j,temp;
	printf("Enter first array size:");
	scanf("%d",&n1);
	printf("Enter %d elements:\n",n1);
	for(i=0;i<n1;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter second array size:");
	scanf("%d",&n2);
	printf("Enter %d elements:\n",n2);
	for(i=0;i<n2;i++){
		scanf("%d",&b[i]);
	}
	for(i=0;i<n1;i++){
		merg[i]=a[i];
	}
	for(j=0;j<n2;j++){
		merg[i+j]=b[j];
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
	printf("After concatnenated and sorting the array ascending:\n");
	for(i=0;i<total;i++){
		printf("%d ",merg[i]);
	}
}
