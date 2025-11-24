#include<stdio.h>
void printBinary(unsigned int x){
	for(int i=31;i>=0;i--){
		if(x&(1u<<i)){
			printf("1");
		}
		else{
			printf("0");
		}
		if(i%8==0){
			printf(" ");
		}
	}
	printf("\n");
}
int main(){
	unsigned int x;
	printf("Enter value:");
	scanf("%d",&x);
	x=~0u;
	printf("After ON the bits:\n");
	printBinary(x);
	x=0;
	printf("After OFF the bits:\n");
	printBinary(x);
}
