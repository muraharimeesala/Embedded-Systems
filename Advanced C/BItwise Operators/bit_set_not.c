#include<stdio.h>
int main(){
	int num,n;
	printf("Enter a number:");
	scanf("%d",&num);
	printf("Enter bit position to check(0 to31):");
	scanf("%d",&n);
	if(num&(1<<n)){
		printf("Bit %u is SET(1).\n",n);
	}
	else{
		printf("Bit %u is CLEAR(0).\n",n);
	}
}
