#include<stdio.h>
int main(){
	int a,b;
	printf("Enter two numbers:");
	scanf("%d %d",&a,&b);
	printf("Before swapping:\n A=%d\n B=%d\n",a,b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("After swapping:\n A=%d\n B=%d\n",a,b);
}
