#include<stdio.h>
int main(){
	unsigned int num;
	int i;
	printf("Enter number:");
	scanf("%d",&num);
	printf("Enter bit position:");
	scanf("%d",&i);
	int bit=(num>>i)&1;
	printf("Bit at position:%d=%d\n",i,bit);
}
