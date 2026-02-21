#include<stdio.h>
int main(){
	int a,b,temp;
	printf("Enter A and B values:");
	scanf("%d %d",&a,&b);
	temp=a;
	a=b;
	b=temp;
	printf("A=%d B=%d",a,b);
}
