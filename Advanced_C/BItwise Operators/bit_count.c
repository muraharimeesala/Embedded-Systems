#include<stdio.h>
int countSetbits(unsigned int n){
	int count=0;
	while(n){
		n=n&(n-1);
		count++;
	}
	return count;
}
int main(){
	int num,ret;
	printf("Enter a number:");
	scanf("%d",&num);
	ret=countSetbits(num);
	printf("No of set bits is:%d\n",ret);
}
