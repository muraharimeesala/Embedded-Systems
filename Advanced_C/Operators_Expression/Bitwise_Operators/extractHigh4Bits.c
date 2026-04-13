#include<stdio.h>
void printBinary(int x){
	int i;
	printf("Binary value of %d:\n",x);
	for(i=31;i>=0;i--){
		printf("%d",(x>>i)&1);
		if(i%4==0){
			printf(" ");
		}
	}
	printf("\n");
}
int main(){
	unsigned char x;
	printf("Enter value:");
	scanf("%hhu",&x);
	unsigned char high=(x>>4)&0x0F;
	printBinary(x);
	printf("Highest 4 bits(Binary):\n");
	for(int i=31;i>=0;i--){
	    printf("%d",(high>>i)&1);
	    if(i%4==0){
	        printf(" ");
	    }
	}
	printf("\n");
	
	printf("highest Bits (Decimal):%d\n",high);

}
