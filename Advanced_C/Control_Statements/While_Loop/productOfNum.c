#include <stdio.h>

int main(){
	int num,rem,prod=1;
	int sum=0;
	printf("Enter a number: ");
	scanf("%d",&num);
	while(num>0){
		rem=num%10;
		prod*=rem;
		sum+=rem;
		num/=10;
		
	}
	printf("Product of digits of %d is %d\n",num,prod);
	printf("Sum of product is = %d\n",sum);
	return 0;
}
