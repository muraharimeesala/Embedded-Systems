#include<stdio.h>
int main(){
	int a,b;
	printf("Enter A and B values:");
	scanf("%d %d",&a,&b);
	printf("Before Swap:\nA=%d B=%d\n",a,b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After Swap:\nA=%d B=%d",a,b);
}
