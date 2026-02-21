#include<stdio.h>
int main(){
	int arr[100],n,i,second,largest;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	second=largest=-9999;
	for(i=0;i<n;i++){
		if(arr[i]>largest){
			second=largest;
			largest=arr[i];
		}
		else if(arr[i]>second && arr[i]!=largest){
			second=arr[i];
		}
	}
	printf("Second largest elements:%d\n",second);
}

