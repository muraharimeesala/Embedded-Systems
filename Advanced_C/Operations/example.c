#include<stdio.h>
int main(){
	int a;
	printf("Enter hexa decimal value:");
	scanf("%d",&a);
	a=a|0x04;
	printf("Value:%d\n",a);
	a|=0x01;
	printf("Value:%d\n",a);
}
