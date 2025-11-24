#include<stdio.h>
int modify(int a){
	a=a+10;
	printf("Inside funcation:%d\n",a);
}
int main(){
	int a;
	printf("Enter a value:");
	scanf("%d",&a);
	printf("Before modifying the value:%d\n",a);
	modify(a);
	printf("After modifying the value:%d\n",a);
}


