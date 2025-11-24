#include<stdio.h>
int main(){
	int x,count=0;
	printf("Enter value:");
	scanf("%d",&x);
	while(x){
		x=x&(x-1);         //removes last set bit
	        count++; 
	}
	printf("Count of set bits:%d",count);
}

