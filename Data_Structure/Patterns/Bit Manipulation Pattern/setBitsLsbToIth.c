#include<stdio.h>
void printBinary(unsigned int n){
	for(int i=31;i>=0;i--){
		printf("%d",(n>>i)&1);
		if(i%4==0){
			printf(" ");
		}
	}
	printf("\n");
}
int main(){
	unsigned int i;
	printf("Enter bit position:");
	scanf("%d",&i);
	unsigned int mask=(1<<(i+1))-1;
	printf("After SET bits:\n%u\n",mask);
	printBinary(mask);
}
