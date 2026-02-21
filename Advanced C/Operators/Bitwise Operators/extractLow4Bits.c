#include<stdio.h>
void printBinary(int x){
	int i;
	for(i=31;i>=0;i--){
		printf("%d",(x>>i)&1);
		if(i%4==0){
			printf(" ");
		}
	}
	printf("\n");
}
int main(){
	int x;
	printf("Enter value:");
	scanf("%d",&x);
	int low=x&0x0F;
	printf("Binary of %d\n:",x);
	printBinary(x);
	printf("Lowest Bits:%d\n",low);

}
