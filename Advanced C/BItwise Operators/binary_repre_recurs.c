#include<stdio.h>
void printBinary(unsigned int n, int pos){
	if(pos==0)
		return;
	printBinary(n>>1,pos-1);
	printf("%d",n&1);
	if(pos%4==0){
		printf(" ");
	}
}
int main(){
	unsigned int  num;
	int pos;
	int bitCount=0;
	printf("Enter a number:");
	scanf("%d",&num);
	printf("Enter a position:");
	scanf("%d",&pos);
	printf("Binary Representaion:\n");
	printBinary(num,pos);
}
