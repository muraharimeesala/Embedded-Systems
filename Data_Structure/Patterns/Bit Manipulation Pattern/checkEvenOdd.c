#include<stdio.h>
int main(){
	signed int num;
	printf("Enter number:");
	scanf("%u",&num);
	if((num&1)==0){
		printf("Even\n");
	}
	else{
		printf("Odd\n");
	}
}
