#include<stdio.h>
int main(){
	int x;
	printf("Enter value:");
	scanf("%d",&x);
	printf("Binary:\n");
	for(int i=31;i>=0;i--){
		if(x&(1<<i)){
			printf("1");
		}
		else{
			printf("0");
		}
	}
	printf("\n");
}
