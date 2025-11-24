#include<stdio.h>
int main(){
	int arr[100],n,i,second,smallest;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	second=smallest=9999;
	for(i=0;i<n;i++){
		if(arr[i]<smallest){
			second=smallest;
			smallest=arr[i];
		}
		else if(arr[i]<second && arr[i]!=smallest){
			second=arr[i];
		}
	}
	printf("Second largest elements:%d\n",second);
}

