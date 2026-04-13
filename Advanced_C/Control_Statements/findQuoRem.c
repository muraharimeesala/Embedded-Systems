#include <stdio.h>
#include <stdlib.h>

int main(){
	int a,b;
	printf("Enter two numbers\n");
	scanf("%d %d",&a,&b);
	if(b){
		int quotient = a/b;
		int remainder = a%b;
		printf("Quotient = %d\n",quotient);
		printf("Remainder  = %d\n",remainder);
	}
	else{
		printf("Division by zero\n");
	}
	
}
