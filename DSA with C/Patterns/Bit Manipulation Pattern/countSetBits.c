#include<stdio.h>
int main(){
	unsigned int num;
	int count=0;
	printf("Enter number:");
	scanf("%u",&num);
	while(num){
		num=(num&(num-1));
		count++;
	}
	printf("Count no bits:%d\n",count);
}

