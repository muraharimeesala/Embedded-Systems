#include<stdio.h>
int swapp(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int a,b;
	printf("Enter two values:\n");
	scanf("%d%d",&a,&b);
	printf("Before swapping the value:\nA=%d\nB=%d\n",a,b);
	swapp(&a,&b);
	printf("After swapping the value:\nA=%d\nB=%d\n",a,b);
}

