#include<stdio.h>
int main(){
	unsigned int num;
	int i;
	printf("Enter number:");
	scanf("%d",&num);
	printf("Enter position to set:");
	scanf("%d",&i);
	printf("Before SET:%u\n",num);
	num=num|(1<<i);
	printf("After SET:%u\n",num);
}

