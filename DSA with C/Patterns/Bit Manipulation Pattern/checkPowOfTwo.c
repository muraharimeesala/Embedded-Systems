#include<stdio.h>
int main(){
	unsigned int num;
	printf("Enter number:");
	scanf("%d",&num);
	if(num>0 && (num&(num-1))==0){
		printf("%d is power of 2\n",num);
	}
	else{
		printf("%d is not power of 2\n",num);
	}
}
