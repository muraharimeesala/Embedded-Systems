#include<stdio.h>
void printBinary(unsigned int num){
	for(int i=31;i>=0;i--){
		printf("%d",(num>>i)&1);
		if(i%4==0){
			printf(" ");
		}
	}
	printf("\n");
}
int main(){
	unsigned int num;
	//int pos;
	printf("Enter number:");
	scanf("%u",&num);
	//printf("Enter bit position:");
	//scanf("%d",&num);
	printf("Before:%u\n",num);
	printBinary(num);
	num=num&(num>>1);
	printf("After:%u\n",num);
	printBinary(num);
}
