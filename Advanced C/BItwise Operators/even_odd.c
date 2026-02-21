#include<stdio.h>
int main(){
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	if(num&1){
		printf("%d is Odd number.\n",num);
	}
	else{
		printf("%d is Even number.\n",num);
	}
}
