#include<stdio.h>
int main(){
	int n,i,j,arr[100];
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	i=0;
	j=n-1;
	while(i<j){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
	printf("Revered Array:\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
	}
}
