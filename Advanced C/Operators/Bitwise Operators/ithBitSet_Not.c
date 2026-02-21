#include<stdio.h>
int check_set(int x,int i){
	if((x&(1<<i))!=0){
		printf("Ith bit is a Set.\n");
	}
	else{
		printf("Ith bit is not a Set.\n");
	}
}
int main(){
	int x,i;
	printf("Enter value:");
	scanf("%d",&x);
	printf("Enter bit to check:");
	scanf("%d",&i);
	check_set(x,i);
}
