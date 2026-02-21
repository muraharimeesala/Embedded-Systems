#include<stdio.h>
int main(){
	int arr[100];
	int n,i;
	printf("Enter array size:");
	scanf("%d",&n);
	int *p1=arr;
	int (*p2)[n]=&arr;
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Pointer to integer(p1):\n\n");
	for(i=0;i<n;i++){
		printf("p1[%d]=%d Address=%p\n",i,p1[i],&p1[i]);
	}
	printf("Pointer to entire array(p2):\n\n");
	for(i=0;i<n;i++){
		printf("p2[%d]=%d Address=%p\n",i,*(p2)[i],&(*p2)[i]);
	}
}
	
