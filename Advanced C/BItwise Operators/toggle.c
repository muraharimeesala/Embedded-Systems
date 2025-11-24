#include<stdio.h>
int main(){
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	int n;
	printf("Enter position to toggle (0 to 31):");
	scanf("%d",&n);
	num=num^(1<<n);
	printf("After toggling the bit %u: %u\n",n,num);
}
