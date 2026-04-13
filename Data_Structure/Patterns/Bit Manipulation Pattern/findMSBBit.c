#include<stdio.h>
int main(){
	unsigned int num;
	printf("Enter number:");
	scanf("%u",&num);
	int pos=0;
	while(num){
		pos++;
		num=num>>1;
	}
	printf("MSB:%d\n",pos);
}
