#include<stdio.h>
#include<string.h>
int main(){
	int base,num,i,result=1;
	printf("Enter base:");
	scanf("%d",&base);
	printf("Enter a integer:");
	scanf("%d",&num);
	for(int i=0;i<num;i++){
		result=result*base;
	}
	printf("Power of integer is:");
	printf("%d^%d is %d\n",base,num,result);
}
