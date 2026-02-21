#include<stdio.h>
int main(){
	int x,count=0;
	printf("Enter value:");
	scanf("%d",&x);
	for(int i=31;i>=0;i--){
		if(x&(1u<<i)){
			break;
		}
		count++;
	}
	printf("No of leading zeros:%d\n",count);
}

