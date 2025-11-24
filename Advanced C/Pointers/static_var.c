#include<stdio.h>
int *getNumber(){
	static int n=42;
	return &n;
}
int main(){
	int *ptr;
	ptr=getNumber();
	printf("Value is:%d\n",*ptr);
	printf("Address is:%p\n",ptr);
}
