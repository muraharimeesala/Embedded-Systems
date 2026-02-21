#include<stdio.h>
int main(){
	int num,i;
	printf("Enter number:");
	scanf("%d",&num);
	printf("Enter bit position:(0 to 31):");
	scanf("%d",&i);
	if(num&(1<<i)){
		printf("%d bit is SET(1)\n",i);
	}
	else{
		printf("%d bit is CLEAR(0)\n",i);
	}
}

