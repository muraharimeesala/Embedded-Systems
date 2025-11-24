#include<stdio.h>
int main(){
	char arr[100];
	int n,i;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d characters:\n",n);
	for(i=0;i<n;i++){
		scanf(" %c",&arr[i]);
	}
	printf("Ascii values of array:\n");
	for(i=0;i<n;i++){
		printf("'%c'-->%d\n",arr[i],arr[i]);
	}
}
