#include<stdio.h>
int main(){
	int arr[5]={10,20,30,40,50};
	int i=0,j=5-1;
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
	printf("\n");
}

