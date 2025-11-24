#include<stdio.h>
int printBinary(unsigned int n){
	int i;
	for(i=15;i>=0;i--){
		printf("%d\n",(n>>i)&1);
		if(i%4==0){
			printf(" ");
		}
	}
}
int main(){
	int num;
	printf("Enter a number:");
	scanf("%d",&num);
	printBinary(num);
}
