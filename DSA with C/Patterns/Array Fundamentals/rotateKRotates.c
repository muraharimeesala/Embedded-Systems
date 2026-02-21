#include<stdio.h>
int main(){
	int arr[5]={10,20,30,40,50};
	int i,k,j;
	printf("Enter position to rotate:");
	scanf("%d",&k);
	i=0;
	j=k-1;
	while(i<j){
		int temp=arr[i];
		arr[i]=arr[j];
		arr[j]=temp;
		i++;
		j--;
	}
	for(i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
}
