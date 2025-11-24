#include<stdio.h>
#include<stdlib.h>
int main(){
	int x,count=0;
	printf("Enter value:");
	scanf("%d",&x);
	if(x==0){
		printf("Infinite trailing zeros.\n");
		exit(1);
	}
	while((x&1)==0){
		count++;
		x>>=1;
	}
	printf("No of trailing zeros:%d\n",count);
}

