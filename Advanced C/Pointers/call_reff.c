#include<stdio.h>
int modify(int *a){
	*a=*a+10;
	printf("Inside the function:%d\n",*a);
}
int main(){
	int a;
	printf("Enter value:");
	scanf("%d",&a);
	printf("Before modifying the value:%d\n",a);
	modify(&a);
	printf("After modifying the value:%d\n",a);
}

