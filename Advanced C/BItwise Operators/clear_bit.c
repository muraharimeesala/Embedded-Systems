#include<stdio.h>
int main(){
	int num,n;
	printf("Enter a number:");
	scanf("%d",&num);
	printf("Enter bit position to CLEAR(0 to 31):");
	scanf("%d",&n);
	num=num&~(1<<n);
	printf("After clreaing the bit %u:%u\n",n,num);
}
