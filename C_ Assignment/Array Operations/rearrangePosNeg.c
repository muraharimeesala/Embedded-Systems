#include<stdio.h>
int main(){
	int n,i,j,arr[100];
	int temp;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	i=0;
	for(j=0;j<n;j++){
		if(arr[j]<0){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
		}
	}
	printf("Updated array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}

