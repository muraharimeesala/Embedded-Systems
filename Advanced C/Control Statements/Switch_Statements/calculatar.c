#include<stdio.h>
int main(){
	char operation;
	int a,b,result;
	printf("Enter opearation(+,-,*,/):");
	scanf("%c",&operation);
	printf("Enter two values:\n");
	scanf("%d%d",&a,&b);
	switch(operation){
		case '+':
			result=a+b;
			printf("Sum is:%d",result);
			break;
		case '-':
			result=a+b;
			printf("Sub is:%d",result);
			break;
		case '*':
			result=a*b;
			printf("Mul is:%d",result);
			break;
		case '/':
			result=a/b;
			printf("Div is:%d",result);
			break;
		default:
			printf("Enter invalid operation\n");
	}
}
