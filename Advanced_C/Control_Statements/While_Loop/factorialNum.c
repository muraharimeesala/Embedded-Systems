#include <stdio.h>

int main(){
	int num,fact=1;
	printf("Enter a number: ");
	scanf("%d",&num);
	int n=num;
	if(num<0){
		printf("Enter a positive number");
		return 0;
	}
	else{
		while(num>1){
			fact*=num;
			num--;
		}
		printf("factorial of %d is %d",n,fact);
		return 0;
	}
}
