#include <stdio.h>

int main(){
	int num,rem,j=1,dec=0,d;
	printf("Enter a binary number: ");
	scanf("%d",&num);
	int unsave=num;
	while(num>0){
		rem=num%10;
		d=rem*j;
		dec+=d;
		j*=2;
		num/=10;
	}
	printf("The binary number: %d Decimal number: %d\n",unsave,dec);
	return 0;
}
