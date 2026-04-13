#include<stdio.h>
int main(){
	int arr[100];
	int i,n,max,min;
	int *ptr;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	ptr=arr;
	max=min=*ptr;
	for(i=0;i<n;i++){
		ptr=arr+i;
		if(*ptr>max){
			max=*ptr;

		}
		if(*ptr<min){
			min=*ptr;
		}
	}
	printf("Maximum element is:%d\n",max);
	printf("Minimum element is:%d\n",min);
}
			

