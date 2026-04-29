#include<stdio.h>
int main(){
	int num,n;
	printf("Enter a number:");
	scanf("%d",&num);
	printf("Enter bit position to SET(0 to 31):");
	scanf("%d",&n);
	num=num|(1<<n-1);
	printf("After Setting the bit %u: %u\n",n,num);
}
