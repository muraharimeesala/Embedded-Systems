#include<stdio.h>
int main(){
	int a,b;
	printf("Enter two values:\n");
	scanf("%d%d",&a,&b);
	int *p1=&a;
	int *p2=&b;
	printf("Before swapping the value:\nA=%d\nB=%d\n",*p1,*p2);
	int temp;
	temp=*p1;
	*p1=*p2;
	*p2=temp;
	printf("After swapping the value:\nA=%d\nB=%d\n",*p1,*p2);
}

