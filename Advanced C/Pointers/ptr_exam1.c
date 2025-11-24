#include<stdio.h>
int main(){
	int a=10;
	float b=13.2;
	char c='M';
	printf("Value is:%d Address of a is:%p\n",a,&a);
	printf("Value is:%.2f Address of b is:%p\n",b,&b);
	printf("character is:%c Adress of c is:%p\n",c,&c);
}
