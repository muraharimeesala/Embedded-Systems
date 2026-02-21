#include<stdio.h>
int calculate(int a,int b,int *sum,int *sub){
	*sum=a+b;
	*sub=a-b;
}
int main(){
	int a,b,sum,sub;
	printf("Enter two values:\n");
	scanf("%d%d",&a,&b);
	calculate(a,b,&sum,&sub);
	printf("Sum=%d\n",sum);
	printf("Sub=%d\n",sub);
}

