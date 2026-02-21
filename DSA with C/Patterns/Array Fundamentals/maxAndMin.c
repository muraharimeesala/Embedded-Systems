#include<stdio.h>
int main(){
	int arr[5]={10,20,30,40,50};
	int max,min,i;
	min=max=arr[0];
	for(i=0;i<5;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		else if(arr[i]<min){
			min=arr[i];
		}
	}
	printf("Maximum element:%d\n",max);
	printf("Minumum element:%d\n",min);
}
