#include<stdio.h>
int main(){
	int a,b;
	printf("Enter A and B Values:\n");
	scanf("%d %d",&a,&b);
	printf("Bitwise AND:%d\n",a&b);
	printf("Bitwise OR:%d\n",a|b);
	printf("Bitwise XOR:%d\n",a^b);
	printf("Bitwise NOT of a:%d\n",~a);
	printf("Bitwise NOT of b:%d\n",~b);
	printf("Left Shift of a:%d\n",a<<1);
	printf("Right Shift of a:%d\n",a>>1);
}
