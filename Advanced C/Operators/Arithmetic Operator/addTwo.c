#include<stdio.h>
int main(){
	int num,sum=0;
	printf("Enter a number:");
	scanf("%d",&num);
	int i=0;
	while(i<num){
		++i;
		sum+=i;
	}
	printf("Sum=%d\n",num);
}
